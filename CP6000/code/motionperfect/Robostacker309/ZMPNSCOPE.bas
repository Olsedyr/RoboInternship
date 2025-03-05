GOTO print_scope
'mpnscope<>(1,2,3,4,5,6) -> do nothing
'mpnscope=1 -> programmed do nothing
'mpnscope=2 -> init scopedata
'mpnscope=3 -> wait for trigger
'mpnscope=4 -> sample scopedata
'mpnscope=5 -> force stop sampling
'mpnscope=6 -> set save next line of scopedata
'mpnscope=7 -> next line of scopedata saved
init:
TABLE(pscopecommand,1)
TABLE(pscopetype,1)
TABLE(pscopenumofsam,0)
TABLE(pscopelength,13)
IF runningoffline=0 THEN
  IF ATYPE AXIS(axis_a)<>11 THEN GOTO init
  IF ATYPE AXIS(axis_b)<>11 THEN GOTO init
  IF ATYPE AXIS(axis_c)<>11 THEN GOTO init
  IF ATYPE AXIS(axis_d)<>11 THEN GOTO init
  IF ATYPE AXIS(axis_e)<>11 THEN GOTO init
  IF axis_f_enabled=1 AND ATYPE AXIS(axis_f)<>11 THEN GOTO init
ENDIF

IF runningoffline=0 THEN
  TABLE(pscopeascale,DLINK(5,axis_a,7))
  TABLE(pscopebscale,DLINK(5,axis_b,7))
  TABLE(pscopecscale,DLINK(5,axis_c,7))
  TABLE(pscopedscale,DLINK(5,axis_d,7))
  TABLE(pscopeescale,DLINK(5,axis_e,7))
  IF axis_f_enabled=1 THEN TABLE(pscopefscale,DLINK(5,axis_f,7))
ELSE
  TABLE(pscopeascale,1001)
  TABLE(pscopebscale,1002)
  TABLE(pscopecscale,1003)
  TABLE(pscopedscale,1004)
  TABLE(pscopeescale,1005)
  TABLE(pscopefscale,1006)
ENDIF
  ON BASICERROR GOTO start

start:
  IF runningoffline=0 THEN
    WAIT UNTIL WDOG=ON
  ELSE
  ENDIF
  IF TABLE(pscopecommand)=1 THEN GOTO start
  IF TABLE(pscopecommand)=2 THEN
    GOTO init_mpnscope
  ENDIF
  IF TABLE(pscopecommand)=3 THEN
    WAIT UNTIL WDOG=OFF OR TABLE(pscopecommand)<>3
  ENDIF
  IF TABLE(pscopecommand)=4 THEN
    WAIT UNTIL MTYPE AXIS(axis_t)>0 'or reset
    IF runningoffline=0 THEN GOTO dompnscope
    IF runningoffline=1 THEN GOTO dompnscopempos
  ENDIF
  IF TABLE(pscopecommand)=5 THEN
    TICKS=10
    WAIT UNTIL TICKS<0
    TABLE(pscopecommand,6)
  ENDIF
  IF TABLE(pscopecommand)=6 THEN GOTO savescopedata
  GOTO start
  STOP

init_mpnscope:
  VR(0)=pscopedata 'sidx=pscopedata
  VR(1)=pscopebuffer 'copyto=pscopebuffer
  VR(2)=pscopedata 'copyfrom=pscopedata
  VR(3)=0 'scnt=0
  TABLE(pscopenumofsam,0) 'zero samples
  maxsamples=50000/TABLE(pscopelength)
  sampleinterval=1000000/maxsamples
  'how many samples fit into scopebuffer
  saminbuf=INT(20/TABLE(pscopelength))
  oldtp=-99999
  'enable auto cyclic data exchange over channel 3
  IF runningoffline=0 THEN
    DLINK(1,2,1,11,248) 'A
    DLINK(1,1,0,11,248) 'B
    DLINK(1,2,0,11,248) 'C
    DLINK(1,1,1,11,248) 'D
    DLINK(1,1,2,11,248) 'E
    IF axis_f_enabled=1 THEN DLINK(1,2,2,11,248) 'F
    'DLINK(6,dl_axis,59,14579) 'set T3 = Revolutions
    'DLINK(6,dl_axis,59,14342) 'set T3 = Speed
    DLINK(6,1,59,14520) 'set T3 = Current Demand axis A
    DLINK(6,2,59,14520) 'set T3 = Current Demand axis B
    DLINK(6,3,59,14520) 'set T3 = Current Demand axis C
    DLINK(6,4,59,14520) 'set T3 = Current Demand axis D
    DLINK(6,5,59,14520) 'set T3 = Current Demand axis E
    IF axis_f_enabled=1 THEN DLINK(6,6,59,14520) 'set T3
  ENDIF
  TABLE(pscopecommand,3)
  GOTO start

dompnscope:
  'we could also sample only part of path if given a start and stop time
  'on axis_t
  TICKS=0
  tp=MPOS AXIS(axis_t) 'could be param 18
  af=DLINK(0,2,1,8) 'A
  bf=DLINK(0,1,0,8) 'B
  cf=DLINK(0,2,0,8) 'C
  df=DLINK(0,1,1,8) 'D
  ef=DLINK(0,1,2,8) 'E
  ff=0
  apo=FE AXIS(axis_a)
  bpo=FE AXIS(axis_b)
  cpo=FE AXIS(axis_c)
  dpo=FE AXIS(axis_d)
  epo=FE AXIS(axis_e)
  fpo=FE AXIS(axis_f)
  ff=0
  IF tp-oldtp>sampleinterval THEN
    IF VR(0) < 250000-TABLE(pscopelength) THEN
      TABLE(VR(0),tp,af,bf,cf,df,ef,ff,apo,bpo,cpo,dpo,epo,fpo)
      VR(0)=VR(0)+TABLE(pscopelength)
      VR(3)=VR(3)+1
      TABLE(pscopenumofsam,VR(3)) 'numofsamples
    ENDIF
    oldtp=tp
  ENDIF
  IF MTYPE AXIS(axis_t)>0 THEN
    GOTO dompnscope
  ENDIF
  IF TABLE(pscopecommand)=4 THEN TABLE(pscopecommand,6)
  GOTO start

dompnscopempos:
  'we could also sample only part of path if given a start and stop time
  'on axis_t
  TICKS=0
  tp=MPOS AXIS(axis_t) 'could be param 18
  apo=MPOS AXIS(axis_a)
  bpo=MPOS AXIS(axis_b)
  cpo=MPOS AXIS(axis_c)
  dpo=MPOS AXIS(axis_d)
  epo=MPOS AXIS(axis_e)
  fpo=MPOS AXIS(axis_f)
'  ae=FE AXIS(axis_a)
'  be=FE AXIS(axis_b)
'  ce=FE AXIS(axis_c)
'  de=FE AXIS(axis_d)
'  ee=FE AXIS(axis_e)
'  fee=FE AXIS(axis_f)
  IF runningoffline=0 THEN
    af=DLINK(0,2,1,8) 'A
    bf=DLINK(0,1,0,8) 'B
    cf=DLINK(0,2,0,8) 'C
    df=DLINK(0,1,1,8) 'D
    ef=DLINK(0,1,2,8) 'E
    'ff=DLINK(0,2,2,8) 'F
    ff=0
  ELSE
    af=DPOS AXIS(axis_a)
    bf=DPOS AXIS(axis_b)
    cf=DPOS AXIS(axis_c)
    df=DPOS AXIS(axis_d)
    ef=DPOS AXIS(axis_e)
    ff=DPOS AXIS(axis_f)
  ENDIF
'    TABLE(pscopebuffer,tp)
'    TABLE(pscopebuffer+1,af)
'    TABLE(pscopebuffer+2,bf)
'    TABLE(pscopebuffer+3,cf)
'    TABLE(pscopebuffer+4,df)
'    TABLE(pscopebuffer+5,ef)
'    TABLE(pscopebuffer+6,ff)
  IF tp-oldtp>sampleinterval THEN
    IF VR(0) < 250000-TABLE(pscopelength) THEN
      TABLE(VR(0),tp,apo,bpo,cpo,dpo,epo,fpo,af,bf,cf,df,ef,ff)
      VR(0)=VR(0)+TABLE(pscopelength)
      VR(3)=VR(3)+1
      TABLE(pscopenumofsam,VR(3)) 'numofsamples
    ENDIF
    oldtp=tp
'  TABLE(sidx,tp,apo,bpo,cpo,dpo,epo,fpo,ae,be,ce,de,ee,fee,af,bf,cf,df,ef,ff)
'  ELSE
'    IF(af>32767) THEN af=af-65535
'    af=(af/ascale)*100.0
  ENDIF
  IF TABLE(pscopecommand)=4 THEN
'    IF WDOG=ON AND sidx < 250000-16 THEN
      IF MTYPE AXIS(axis_t)>0 THEN
        GOTO dompnscopempos
      ENDIF
'    ENDIF
  ENDIF
  IF TABLE(pscopecommand)=4 THEN TABLE(pscopecommand,6)
  GOTO start

savescopedata:
  'fill buffer
  VR(1)=pscopebuffer
  FOR i = 1 TO saminbuf*TABLE(pscopelength)
      TABLE(VR(1),TABLE(VR(2)))
      VR(1)=VR(1)+1
      VR(2)=VR(2)+1
  NEXT i
  IF VR(2)>=pscopedata+TABLE(pscopenumofsam)*TABLE(pscopelength) THEN
    TABLE(pscopecommand,8)
  ELSE
    TABLE(pscopecommand,7)
  ENDIF
  GOTO start


print_scope:
  ON BASICERROR GOTO print_scope
  PRINT "A scale = ";DLINK(5,1,7)
  PRINT "B scale = ";DLINK(5,2,7)
  PRINT "C scale = ";DLINK(5,3,7)
  PRINT "D scale = ";DLINK(5,4,7)
  PRINT "E scale = ";DLINK(5,5,7)
loopwdog:
  WAIT UNTIL TICKS < -1000
  IF WDOG=OFF THEN
    GOTO loopwdog
  ENDIF
  DLINK(1,2,1,11,248) 'A
  DLINK(1,1,0,11,248) 'B
  DLINK(1,2,0,11,248) 'C
  DLINK(1,1,1,11,248) 'D
  DLINK(1,1,2,11,248) 'E
  'DLINK(6,dl_axis,59,14579) 'set T3 = Revolutions
  'DLINK(6,dl_axis,59,14342) 'set T3 = Speed
  DLINK(6,1,59,14520) 'set T3 = Current Demand axis A
  DLINK(6,2,59,14520) 'set T3 = Current Demand axis B
  DLINK(6,3,59,14520) 'set T3 = Current Demand axis C
  DLINK(6,4,59,14520) 'set T3 = Current Demand axis D
  DLINK(6,5,59,14520) 'set T3 = Current Demand axis E
loopprint:
  TICKS = 0
  WAIT UNTIL TICKS < -100
  af=DLINK(0,2,1,8) 'A
  bf=DLINK(0,1,0,8) 'B
  cf=DLINK(0,2,0,8) 'C
  df=DLINK(0,1,1,8) 'D
  ef=DLINK(0,1,2,8) 'E
  PRINT "A=";af[5,0];" B=";bf[5,0];" C=";cf[5,0];" D=";df[5,0];" E=";ef[5,0]
'  dl_axis=1
'  GOSUB print_axis_status
'  dl_axis=2
'  GOSUB print_axis_status
'  dl_axis=3
'  GOSUB print_axis_status
'  dl_axis=4
'  GOSUB print_axis_status
'  dl_axis=5
'  GOSUB print_axis_status
  IF WDOG=OFF THEN
    GOTO loopwdog
  ENDIF
  GOTO loopprint

'set kp,ki,kd,dl_axis,filter
set_motor_pid:
' PRINT "calculate the parameters"
 ts=125/1000000
 digit_limit=524272
 a=(((kp/ki)+kd)*4)/ts
 b=ki*32768*ts/kp
 c=ki*64
 d=(kp)/ts
 e=d*65535/(d+ki)
 f=digit_limit/(ki+(kp/ts))
 ' store the parameters
 DLINK(6,dl_axis,1,a)
 DLINK(6,dl_axis,2,b)
 DLINK(6,dl_axis,3,c)
 DLINK(6,dl_axis,4,d)
 DLINK(6,dl_axis,5,e)
 DLINK(6,dl_axis,6,f)
 DLINK(6,dl_axis,13,2*PI*filter*ts*65535)
RETURN

'set dl_axis before calling
RETURN

