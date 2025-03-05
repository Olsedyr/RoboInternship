'*******************************************************************************
'* ENABLE COMMUNICATION WITH MPN
'*******************************************************************************
ETHERNET(2,0,7,1)
ETHERNET(2,0,9,1)
'VR   0 - 9 are used by zmpnscope task
'VR  10 - 99 reserved for path execution
'VR  11 - UNITS AXIS(axis_a)
'VR  12 - UNITS AXIS(axis_b)
'VR  13 - UNITS AXIS(axis_c)
'VR  14 - UNITS AXIS(axis_d)
'VR  15 - UNITS AXIS(axis_e)
'VR  16 - UNITS AXIS(axis_f)
'VR  17 - UNITS AXIS(axis_vt)
'VR  20 - hpoint 0
'VR  21 - hpoint 1
'VR  22 - hpoint 2
'VR  23 - hpoint 3
'VR  24 - hpoint 4
'VR  25 - hpoint 5
'VR  26 - hpoint 6
'VR  27 - hpoint 7
'VR  28 - hpoint 8
'VR  29 - hpoint 9
'VR  30 - address of first keypoint axis a
'VR  31 - address of first keypoint axis b
'VR  32 - address of first keypoint axis c
'VR  33 - address of first keypoint axis d
'VR  34 - address of first keypoint axis e
'VR  35 - address of first keypoint axis f
'VR  36 - address of first keypoint axis vt
'VR  40 - expand start address axis a
'VR  41 - expand start address axis b
'VR  42 - expand start address axis c
'VR  43 - expand start address axis d
'VR  44 - expand start address axis e
'VR  45 - expand start address axis f
'VR  46 - expand start address axis vt
'VR  50 - expand end address axis a
'VR  51 - expand end address axis b
'VR  52 - expand end address axis c
'VR  53 - expand end address axis d
'VR  54 - expand end address axis e
'VR  55 - expand end address axis f
'VR  56 - expand end address axis vt
'VR  60 - savepath
'VR  70 - used by zforce
'VR  80 - 93 hspack
'VR 300 - 302 path performens
'VR 600 - 699 global names for input and output
'VR 700 - 799 globals stat
'VR 800 - 899 globals
'VR 900 - 949 reserved for tablespate pointers
'VR 950 - 1023 globals
'**************************************************
'* constant's                                     *
'**************************************************
'!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
'if you disable axis B or C you MUST unplug power cable
'because the breakes are released when WDOG is set ON
'!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
CONSTANT "axis_a_enabled",1
CONSTANT "axis_b_enabled",1
CONSTANT "axis_c_enabled",1
CONSTANT "axis_d_enabled",1
CONSTANT "axis_e_enabled",1
CONSTANT "axis_f_enabled",0
CONSTANT "axis_t",0
CONSTANT "axis_a",1
CONSTANT "axis_b",2
CONSTANT "axis_c",3
CONSTANT "axis_d",4
CONSTANT "axis_e",5
CONSTANT "axis_f",6
CONSTANT "axis_vt",10
'**************************************************
'* constant's - TABLE SPACE POINTERS              *
'**************************************************
CONSTANT "paxis_t",0
CONSTANT "paxis_a",paxis_t+29
CONSTANT "paxis_b",paxis_a+29
CONSTANT "paxis_c",paxis_b+29
CONSTANT "paxis_d",paxis_c+29
CONSTANT "paxis_e",paxis_d+29
CONSTANT "paxis_f",paxis_e+29
CONSTANT "pscoperetur",paxis_f+29
CONSTANT "pscopeparam",pscoperetur+1
CONSTANT "pscopecommand",pscopeparam+20
CONSTANT "pscopetype",pscopecommand+1
CONSTANT "pscopelength",pscopetype+1
CONSTANT "pscopenumofsam",pscopelength+1
CONSTANT "pscopeascale",pscopenumofsam+1
CONSTANT "pscopebscale",pscopeascale+1
CONSTANT "pscopecscale",pscopebscale+1
CONSTANT "pscopedscale",pscopecscale+1
CONSTANT "pscopeescale",pscopedscale+1
CONSTANT "pscopefscale",pscopeescale+1
CONSTANT "pscopebuffer",pscopefscale+1
CONSTANT "pctlretur",pscopebuffer+20
CONSTANT "pctlcommand",pctlretur+11
CONSTANT "pmpnretur",pctlcommand+1
CONSTANT "pmpncommand",pmpnretur+11
CONSTANT "pmpnbasicerror",pmpncommand+1
CONSTANT "pmpnlinenumber",pmpnbasicerror+1
CONSTANT "pmpncancel",pmpnlinenumber+1
CONSTANT "pmpnrunning",pmpncancel+1
CONSTANT "pmpnstate",pmpnrunning+1
CONSTANT "pmpnspeedfactor",pmpnstate+1
CONSTANT "pmpntrio",pmpnspeedfactor+1
CONSTANT "pmpnlift",pmpntrio+50
CONSTANT "pmpnlast",pmpnlift+50
CONSTANT "uploadgroup",5000
CONSTANT "psavetab",65600 'to 65799
CONSTANT "psavedata",66000 'to 99999
CONSTANT "pexpand",100000 'to 199999
CONSTANT "pscopedata",200000 'to 249999
'**************************************************
'* VR 600 - 699 global for input and output       *
'**************************************************
'**************************************************
'* VR 700 - 749 globals stat                      *
'**************************************************
'**************************************************
'* VR 800 - 899 globals                           *
'* use is depending on workcellid                 *
'* HAC = slot 1, SAC = slot 2                     *
'**************************************************
'SLM asic asignment axis A
'VR(811)=2 'slot
'VR(821)=1 'asic
'SLM asic asignment axis B
'VR(812)=1 'slot
'VR(822)=0 'asic
'SLM asic asignment axis C
'VR(813)=2 'slot
'VR(823)=0 'asic
'SLM asic asignment axis D
'VR(814)=1 'slot
'VR(824)=1 'asic
'SLM asic asignment axis E
'VR(815)=1 'slot
'VR(825)=2 'asic
'**************************************************
'* VR 1000 - 1023                                 *
'**************************************************
GLOBAL "mpnhome_t",1013
GLOBAL "mpnhome_a",1014
GLOBAL "mpnhome_b",1015
GLOBAL "mpnhome_c",1016
GLOBAL "mpnhome_d",1017
GLOBAL "mpnhome_e",1018
GLOBAL "mpnhome_f",1019
'workcelltype: 0=alm, 1=lille robot, 2=ruslandsrobot
GLOBAL "workcelltype",1020
GLOBAL "debug",1021
GLOBAL "workcellid",1022
GLOBAL "runningoffline",1023
'**************************************************
'* LOCALS                                         *
'**************************************************
'GLOBAL "savenextpathidx",936:savenextpathidx=-1
oldspeedfactor=-1
maxspeed=0
mpnspeed=0
pathtype=-1
abspos=0
backup_val=778
debug = VR(1000)
inresetaxis=0 'show correct axis in error_routine (current_axis/dl_axis)
ON BASICERROR GOTO error_routine
'**************************************************
'* reset to default values                        *
'**************************************************
FOR i = 0 TO 15
  VR(600+i)=i
NEXT i

bvtest=0
kasseskaffet=0
boxunaligned=0

TABLE(pmpnstate,0) 'IDLE
'workcellid=401
TABLE(pmpnlift,0) 'disable=0 enable=1 will be set from pc

fe_limit_axis_a=10.0 'mm
fe_limit_axis_b=5.0 'deg
fe_limit_axis_c=5.0 'deg
fe_limit_axis_d=5.0 'deg
fe_limit_axis_e=5.0 'deg
fe_limit_axis_f=5.0 'mm

GOSUB inittablevalues
GOSUB set_units_and_defaults


IF debug>0 THEN
testloop:
'WAIT UNTIL IN(1)=ON
'WAIT UNTIL IN(1)=OFF
'TICKS=5000
'WAIT UNTIL TICKS<0
TRON
IF runningoffline=0 THEN GOSUB mpnstartup
'GOSUB set_units_and_defaults
GOSUB resetaxis
WDOG=ON
TRON
homeloop:
GOSUB set_mpn_home_all
IF slm_is_ok=0 THEN
  IF runningoffline=0 THEN GOSUB set_defpos
ENDIF
TRON
'GOSUB defpos_home_d
GOTO testloop
ENDIF


'RUN "ZMPNSCOPE",13
RUN "ZCTLCOMMAND",1
mainloop:
    TABLE(pmpnstate,3) 'wating for mpncommand
    IF TABLE(pmpncommand)>1 THEN
        TABLE(pmpncancel,0)
        TABLE(pmpnretur,0)
'*******************************************************************************
'*      2 - mpnstartup
'*******************************************************************************
        IF TABLE(pmpncommand)=2 THEN
            IF runningoffline=0 THEN
                TABLE(pmpnstate,40) 'mpnstartup
                GOSUB mpnstartup
            ENDIF
            TABLE(pmpncommand,1)
            GOTO mainloop
        ENDIF
'*******************************************************************************
'*      3 - set_units_and_defaults
'*******************************************************************************
        IF TABLE(pmpncommand)=3 THEN
            TABLE(pmpnstate,50)
            GOSUB set_units_and_defaults
            TABLE(pmpncommand,1)
            GOTO mainloop
        ENDIF
'*******************************************************************************
'*      4 - set_defpos
'*******************************************************************************
        IF TABLE(pmpncommand)=4 THEN
            TABLE(pmpnstate,60) 'set_defpos
            IF runningoffline=0 THEN GOSUB set_defpos
            TABLE(pmpncommand,1)
            GOTO mainloop
        ENDIF
'*******************************************************************************
'*      5 - resetaxis
'*******************************************************************************
        IF TABLE(pmpncommand)=5 THEN
            TABLE(pmpnstate,70) 'reset axis
            IF runningoffline=0 THEN
                GOSUB resetaxis
                WDOG=ON
            ENDIF
            TABLE(pmpncommand,1)

            GOTO mainloop
        ENDIF
'*******************************************************************************
'*      6 - movehome and return new mpnhome
'*******************************************************************************
        IF TABLE(pmpncommand)=6 THEN
            GOSUB movehome
            TABLE(pmpnretur,VR(1013+TABLE(pmpnretur+1)))
            TABLE(pmpncommand,1)
            GOTO mainloop
        ENDIF
'*******************************************************************************
'*      7 - PATHEXECUTER
'*******************************************************************************
        IF TABLE(pmpncommand)=7 THEN
'pathexecuter:
          GOSUB mpnpath
          TABLE(pmpncommand,1)
          GOTO mainloop
        ENDIF
'*******************************************************************************
'*      8 - set_mpn_home_all (+ test if power to slm has been lost)
'*******************************************************************************
        IF TABLE(pmpncommand)=8 THEN
            TABLE(pmpnstate,80) 'set_mpn_home_all
            IF runningoffline=0 THEN
                GOSUB set_mpn_home_all
            ENDIF

            TABLE(pmpncommand,1)
            GOTO mainloop
        ENDIF
'*******************************************************************************
'*      9 - set_mpn_auto_home
'*******************************************************************************
        IF TABLE(pmpncommand)=9 THEN
            TABLE(pmpnstate,90) 'set_mpn_auto_home
            IF runningoffline=0 THEN
              GOSUB set_defpos
              'GOSUB set_mpn_auto_home
            ENDIF
            TABLE(pmpncommand,1)
            GOTO mainloop
        ENDIF
    ENDIF
    GOTO mainloop
STOP

inittablevalues:
TABLE(pscoperetur,0)
TABLE(pscopecommand,1)
TABLE(pctlretur,0)
TABLE(pctlcommand,1)
TABLE(pmpnretur,0)
TABLE(pmpncommand,1)
TABLE(pmpnspeedfactor,0.5)
TABLE(pmpnbasicerror,0)
TABLE(pmpnlinenumber,0)
TABLE(pmpncancel,0)
TABLE(pmpnrunning,5)
RETURN

mpnstartup:
'Start DLink Section
'****************************************
'*** B B B B B B B B B B B B B B B B  ***
'****************************************
IF axis_b_enabled = 1 THEN
  motor_default=FALSE
  dl_slot=VR(812):dl_asic=VR(822):dl_axis=2
  current_scaling=200.0000:filter=1000.0000
  IF debug = 1 THEN
    TRON
  ENDIF
  IF workcelltype=1 THEN
    drive_current=9.5000
    '4 deg - 29kgcm 180
    kp=0.027709:ki=2.932726:kd=0.003271
  ELSE
    IF workcelltype=2 THEN
      drive_current=15.0000
      '2 deg - 0.015kgm^2 200
      'kp=0.023386:ki=2.088949:kd=0.006495
       kp=0.027709:ki=2.932726:kd=0.003271
    ELSE
      drive_current=15.0000
      '4 deg - 29kgcm 180
      kp=0.027709:ki=2.932726:kd=0.003271
      '2 deg - 200kgcm 180
      'kp=0.019603:ki=1.467906:kd=0.009243
    ENDIF
  ENDIF
  GOSUB init_dlink_axis
  'kp=0.019603:ki=1.467906:kd=0.009243
  'GOSUB set_motor_pid
ENDIF
'****************************************
'*** D D D D D D D D D D D D D D D D  ***
'****************************************
IF axis_d_enabled = 1 THEN
  motor_default=FALSE
  dl_slot=VR(814):dl_asic=VR(824):dl_axis=4
  current_scaling=200.0000:filter=1000.0000
  IF debug = 1 THEN
    TRON
  ENDIF
  IF workcelltype=1 THEN
    drive_current=2.5000
    kp=0.018725:ki=2.25:kd=0.002081
    'set motor parameters
  ELSE
    drive_current=2.5000
    kp=0.018725:ki=2.25:kd=0.002081
    'set motor parameters
  ENDIF
  GOSUB init_dlink_axis
ENDIF
'****************************************
'*** E E E E E E E E E E E E E E E E  ***
'****************************************
IF axis_e_enabled = 1 THEN
  motor_default=FALSE
  dl_slot=VR(815):dl_asic=VR(825):dl_axis=5
  'kp=0.027709:ki=2.932726:kd=0.003271
  'current_scaling=100.0000:filter=1000.0000
  current_scaling=200.0000:filter=1000.0000
  IF debug = 1 THEN
    TRON
  ENDIF
  IF workcelltype=1 THEN
    drive_current=2.5000
    kp=0.022933:ki=2.25:kd=0.002548
  ELSE
    drive_current=2.5000
    kp=0.022933:ki=2.25:kd=0.002548
  ENDIF
  GOSUB init_dlink_axis
ENDIF
'****************************************
'*** C C C C C C C C C C C C C C C C  ***
'****************************************
IF axis_c_enabled = 1 THEN
  motor_default=FALSE
  dl_slot=VR(813):dl_asic=VR(823):dl_axis=3
  current_scaling=200.0000:filter=1000.0000
  IF debug = 1 THEN
    TRON
  ENDIF
  IF workcelltype=1 THEN
    drive_current=2.5000
    kp=0.027709:ki=2.932726:kd=0.003
  ELSE
    drive_current=9.5000
    kp=0.027709:ki=2.932726:kd=0.003
  ENDIF
  GOSUB init_dlink_axis
ENDIF
'****************************************
'*** A A A A A A A A A A A A A A A A  ***
'****************************************
IF axis_a_enabled = 1 THEN
  motor_default=FALSE
  dl_slot=VR(811):dl_asic=VR(821):dl_axis=1
  current_scaling=200.0000:filter=1000.0000
  IF debug = 1 THEN
    TRON
  ENDIF
  IF workcelltype=1 THEN
    drive_current=9.5000
    kp=0.016556:ki=1.04703:kd=0.009163
  ELSE
    drive_current=9.5000
    kp=0.016556:ki=1.04703:kd=0.009163
  ENDIF
  GOSUB init_dlink_axis
ENDIF
'****************************************
'*** F F F F F F F F F F F F F F F F  ***
'****************************************
IF axis_f_enabled = 1 THEN
  motor_default=FALSE
  dl_slot=VR(816):dl_asic=VR(826):dl_axis=6
  current_scaling=200.0000:filter=1000.0000
  IF debug = 1 THEN
    TRON
  ENDIF
  IF workcelltype=1 THEN
    drive_current=2.5000
    kp=0.022933:ki=2.25:kd=0.002548
  ELSE
    drive_current=2.5000
    kp=0.022933:ki=2.25:kd=0.002548
  ENDIF
  GOSUB init_dlink_axis
ENDIF
RETURN
'slut mpnstartup

'************************************************************
'Initialisation Subroutine for SLM Technology Daughter boards
 dl_version = 2.0
'For use with System Software 1.52 and above
'Trio Motion Technology - 23-Jul-2003
'(based on dl_version 1.8 - Control Techniques - 28 Sept 2001)
'************************************************************
init_dlink_axis:
start_attempt = 0
dlink_status = 0
TABLE(pmpnstate,40+dl_axis) 'init axis X, 41 = A, 42 = B etc.
retry:
' PRINT "initialising Axis ";dl_axis [0]
 ' check if first initialisation attempt for this axis
 IF ATYPE AXIS(dl_axis)<>11 THEN
  ' check that the SLM module is detected
  IF DLINK(2,dl_slot,dl_asic)=0 THEN
   dlink_status=2
   GOTO error_handling
  ENDIF
  WA(5)

  ' check that the drive is detected
  IF DLINK(3,dl_slot,dl_asic)=0 THEN
   dlink_status=3
   GOTO error_handling
  ENDIF
  ' initialise the axis
  DLINK(4,dl_slot,dl_asic,dl_axis)
'  PRINT "axis:";dl_axis[0];" assigned"
 ENDIF
 WA(10)
 ' reset the amplifier in case of trip
 tries = 0
 reset_x:
  IF MOTION_ERROR THEN DATUM(0)
  sum=0
  FOR check=1 TO 10
   DLINK(7,dl_axis,252)
   sum=sum+DLINK(7,dl_axis,251)
  NEXT check
  IF sum<>-10 THEN
    tries = tries+1
    IF tries > 5 THEN
'      PRINT "unable to reset drive axis ", dl_axis
TRON
        RETURN
'      STOP
    ELSE
      WA(10)
      GOTO reset_x
    ENDIF
  ENDIF

  DLINK(10,dl_axis,22)' Dummy read encoder eprom

'*******************************************************
' ADDED BY THN 02.11.2003
  'skip initialization if 24V backup maintained
  IF debug = 1 THEN
    TRON
  ENDIF
  host_flag = DLINK(5,dl_axis,62)
  IF host_flag = backup_val THEN
    GOTO enable_axis
  ENDIF
'********************************************************
 ' Perform Checksums to make sure that the data is valid
 ' Calculate the checksum for the motor object
 instances = DLINK(10,dl_axis,21)
 IF instances > 27 THEN
   dlink_status=5
   GOTO error_handling
 ENDIF
 calcheck = 0
 FOR object = 21 TO (20 + instances)
   calcheck = calcheck + DLINK(10,dl_axis,object)
   IF calcheck > 65535 THEN calcheck = calcheck - 65536
 NEXT object
 IF DLINK(10,dl_axis,20) <> calcheck THEN
   dlink_status=5
   GOTO error_handling
 ENDIF
 ' Check that the encoder data version is correct
 ' Motor Object
 IF DLINK(10,dl_axis,22) < 3 OR DLINK(10,dl_axis,22) > 99 THEN
   dlink_status = 4
   GOTO error_handling
 ENDIF
 'Calculate the checksum for the Encoder Object
 calcheck = 0
 FOR object = 0 TO 18
   calcheck = calcheck + DLINK(10,dl_axis,object)
   IF calcheck > 65535 THEN calcheck = calcheck - 65536
 NEXT object
 IF DLINK(10,dl_axis,19) <> calcheck THEN
   dlink_status=6
   GOTO error_handling
 ENDIF
 'Calculate the checksum for the performance object
 IF motor_default = TRUE THEN
   instances = DLINK(10,dl_axis,51)
   IF instances > 40 THEN
     dlink_status=7
     GOTO error_handling
   ENDIF
   calcheck = 0
   FOR object = 51 TO (50 + instances)
     calcheck = calcheck + DLINK(10,dl_axis,object)
       IF calcheck > 65535 THEN calcheck = calcheck - 65536
     NEXT object
     IF DLINK(10,dl_axis,50) <> calcheck THEN
       dlink_status=7
       GOTO error_handling

     ENDIF
     objver = DLINK(10,dl_axis,52)
     IF (objver < 1) OR (objver > 100) THEN
       dlink_status=8
       GOTO error_handling
     ENDIF
 ENDIF


 ' Check for CT-Coder Failure
 DLINK(6,dl_axis,28,0)
 IF DLINK(5,dl_axis,28) <> 0 THEN
    dlink_status=10
    GOTO error_handling
 ENDIF

 ' Detect High Speed Motors
 IF DLINK(10,dl_axis,37) > 3700 THEN
    ss = 2
    DLINK(6,dl_axis,39,1)
 ELSE
    ss = 1
 ENDIF

 ' if using default values then read them
 IF motor_default THEN
  kp=DLINK(10,dl_axis,53)/10000
  ki=DLINK(10,dl_axis,54)/1000
  kd=DLINK(10,dl_axis,55)/10000
 ENDIF

' PRINT "calculate the parameters"
 ts=125/1000000
 digit_limit=524272
 a=(((kp/ki)+kd)*4*ss)/ts
 b=ki*32768*ts/kp
 c=ki*64*ss
 d=(kp*ss)/ts
 e=d*65535/(d+ki)
 f=digit_limit/((ki+(kp/ts))*ss)

 ' store the parameters
 DLINK(6,dl_axis,1,a)
 DLINK(6,dl_axis,2,b)
 DLINK(6,dl_axis,3,c)
 DLINK(6,dl_axis,4,d)
 DLINK(6,dl_axis,5,e)
 DLINK(6,dl_axis,6,f)

 ' p7: store the current scaling

 ' read motor current
 motor_current=DLINK(10,dl_axis,30)/10

 IF motor_current < 2.6 AND drive_current > 6.5 THEN
   dlink_status = 11
   GOTO error_handling
 ENDIF
 'THN 10.11.2004 motor has no power
 IF motor_current >= 2.6 AND drive_current <= 6.5 THEN
   dlink_status = 11
   GOTO error_handling
 ENDIF

 ' Read the recommended scaling
 IF motor_default = TRUE THEN current_scaling = DLINK(10,dl_axis,56)

 ' calculate current scale in SLM units proportional to drive current
 current_scale = (65536 * motor_current/drive_current)*(current_scaling/200)

 ' Check within range and download parameter
 IF current_scale > 65535 THEN current_scale = 65535
 DLINK(6,dl_axis,7,current_scale)

 ' p8: poles
 poles=DLINK(10,dl_axis,31)
 DLINK(6,dl_axis,8,poles/2)

 ' p9
 p9=65535-(current_scale*0.25/16)
 DLINK(6,dl_axis,9,p9)

 ' p10
 p10=65535-(current_scale*0.25)
 DLINK(6,dl_axis,10,p10)

 ' p11: absolute speed maximum trip threashold

 DLINK(6,dl_axis,11,32700)

 ' p12: MultiAx Read Address
 DLINK(6,dl_axis,12,32768)

 ' p13: speed loop filter cut off frequency
 IF motor_default THEN
   filter=DLINK(10,dl_axis,57)
 ENDIF
 DLINK(6,dl_axis,13,2*PI*filter*ts*65535)

 ' p14: phase advance
 DLINK(6,dl_axis,14,60000)

 ' p15: flux alignment position
 flux=DLINK(10,dl_axis,29)
 DLINK(6,dl_axis,15,flux)

 ' set I2t parameters

 ' p29: winding time constant
 IF VERSION > 1.49 THEN
  p29=(DLINK(10,dl_axis,32)*100)/16
  p36=(((32*motor_current*129)/(drive_current*100))^2)/4
 ELSE
  p29=(DLINK(10,dl_axis,32)*100)/8
  p36=(((32*motor_current*129)/(drive_current*100))^2)
 ENDIF
 DLINK(6,dl_axis,29,p29)
 DLINK(6,dl_axis,36,p36)
 ' p37: hysteresis
 p37 = p36 - ((p36*10)/100)
 DLINK(6,dl_axis,37,p37)

 ' p35: I2t backoff level (65535=peak current,32768=nom current
 DLINK(6,dl_axis,35,32768)

 ' set ctcoder parameters
 DLINK(6,dl_axis,20,DLINK(10,dl_axis,0))
 DLINK(6,dl_axis,22,DLINK(10,dl_axis,1))
 DLINK(6,dl_axis,21,DLINK(10,dl_axis,2))
 DLINK(6,dl_axis,23,DLINK(10,dl_axis,3))
 DLINK(6,dl_axis,16,DLINK(10,dl_axis,4))
 DLINK(6,dl_axis,18,DLINK(10,dl_axis,5))
 DLINK(6,dl_axis,17,DLINK(10,dl_axis,6))
 DLINK(6,dl_axis,19,DLINK(10,dl_axis,7))

 ' update the pid
 DLINK(7,dl_axis,247)

 ' update the number of poles and current scale
 DLINK(7,dl_axis,245)
 DLINK(7,dl_axis,246)




enable_axis:
 ' enable the axis
 DLINK(7,dl_axis,253)

 RETURN

' Error Handling Routein
 error_handling:
'    PRINT "Started Error Handling..."
   ' Each axis has a chance to retry the initialisation twice
   IF start_attempt < 2 THEN
'     PRINT "Retry to configure axis "; dl_axis
     start_attempt = start_attempt + 1
     GOTO retry
   ENDIF

'   PRINT "error initialising Axis number "; dl_axis[0]
'   PRINT "slot=";dl_slot[0];" asic=";dl_asic[0]

   IF dlink_status = 2 THEN
'     PRINT "DL.ER - No slm module detected"
   ENDIF

   IF dlink_status = 3 THEN
'     PRINT "DL.ER - No Drive Detected"
   ENDIF

   IF dlink_status = 4 THEN
'     PRINT "Motor Object ", DLINK(10,dl_axis,22)
'     PRINT "incompatible with initialisation routine version ", dl_version
   ENDIF

   IF dlink_status = 5 THEN
'     PRINT "SL.ER 2 - Motor Data Checksum Incorrect"
   ENDIF

   IF dlink_status = 6 THEN
'     PRINT "SL.ER 1 - Encoder Data Checksum Incorrect"
   ENDIF

   IF dlink_status = 7 THEN
'     PRINT "SL.ER 4 - Motor Default gains not available"
   ENDIF

   IF dlink_status = 8 THEN
'     PRINT "SL.ER 64 - Wrong version of performance object loaded"
   ENDIF

   IF dlink_status = 9 THEN
'     PRINT "SL.ER 8 - CT-Coder Failed"
   ENDIF

   IF dlink_status = 10 THEN
'     PRINT "Ctc - CT-Coder Failed"
   ENDIF

   IF dlink_status = 11 THEN
'     PRINT "Dr.Si - Motor / Drive Current Mismatch is too large"
   ENDIF

   TABLE(pmpnstate,7000+(dlink_status*10)+dl_axis)
   TICKS=5000
   WAIT UNTIL TICKS<=0
RETURN
end_of_dlink:

set_motor_pid:
 ' Detect High Speed Motors
 IF DLINK(10,dl_axis,37) > 3700 THEN
    ss = 2
    DLINK(6,dl_axis,39,1)
 ELSE
    ss = 1
 ENDIF
' PRINT "calculate the parameters"
 ts=125/1000000
 digit_limit=524272
 a=(((kp/ki)+kd)*4*ss)/ts
 b=ki*32768*ts/kp
 c=ki*64*ss
 d=(kp*ss)/ts
 e=d*65535/(d+ki)
 f=digit_limit/((ki+(kp/ts))*ss)
 ' store the parameters
 DLINK(6,dl_axis,1,a)
 DLINK(6,dl_axis,2,b)
 DLINK(6,dl_axis,3,c)
 DLINK(6,dl_axis,4,d)
 DLINK(6,dl_axis,5,e)
 DLINK(6,dl_axis,6,f)
 DLINK(6,dl_axis,13,2*PI*filter*ts*65535)
RETURN


'Stop DLink Section
set_units_and_defaults:
DATUM(0)
'**************************************************
'* AXIS  A                                        *
'**************************************************
TABLE(pmpnstate,51)
BASE(axis_a)
UNITS=(65536*5)/(50*PI) 'tandhjul dele-diameter 50mm 5:1 gearing
P_GAIN=0.1
I_GAIN=0.0
D_GAIN=0.15
'D_GAIN=0.0
OV_GAIN=0.0
VFF_GAIN=8.0
AFF_GAIN=0.0
SRAMP=5.0
SPEED=40 ' Saet hastighed
ACCEL=40 ' Saet acceleration
DECEL=400 ' Saet deceleration
CREEP=0.5
JOGSPEED=1.0
FE_LIMIT=10
DAC=0.0
REP_DIST=999999.0
FWD_IN=-1
REV_IN=-1
DATUM_IN=4
FHOLD_IN=-1
FS_LIMIT=9999.0
RS_LIMIT=-9999.0
'**************************************************
'* AXIS  B                                        *
'**************************************************
TABLE(pmpnstate,52)
BASE(axis_b)
IF workcelltype=1 THEN
  UNITS=65536*105/360
  P_GAIN=0.10
  I_GAIN=0.0
  D_GAIN=0.15
ELSE
  IF workcelltype=2 THEN
    UNITS=65536*191/360 '
    P_GAIN=0.20
    I_GAIN=0.0
    D_GAIN=0.15
  ELSE
    UNITS=65536*101/360 '
    P_GAIN=0.10
    I_GAIN=0.0
    D_GAIN=0.15
  ENDIF
ENDIF
VFF_GAIN=8.0
AFF_GAIN=0.0
SRAMP = 5.0
SPEED=4 ' Saet hastighed
ACCEL=8 ' Saet acceleration
DECEL=8 ' Saet deceleration
CREEP=0.1
JOGSPEED=1.0
FE_LIMIT=5
DAC=0.0
REP_DIST=999999.0
FWD_IN=-1
REV_IN=-1
DATUM_IN=5
FHOLD_IN=-1
FS_LIMIT=128.0
RS_LIMIT=-128.0
'**************************************************
'* AXIS  C                                        *
'**************************************************
TABLE(pmpnstate,53)
BASE(axis_c)
IF workcelltype=1 THEN
  UNITS=65536*105/360
  P_GAIN=0.12
  I_GAIN=0.0
  D_GAIN=0.15
ELSE
  IF workcelltype=2 THEN
    UNITS=65536*169/360 '
    P_GAIN=0.12
    I_GAIN=0.0
    D_GAIN=0.15
  ELSE
    UNITS=65536*105/360 '
    P_GAIN=0.12
    I_GAIN=0.0
    D_GAIN=0.15
  ENDIF
ENDIF
OV_GAIN=0.0
VFF_GAIN=8.0
AFF_GAIN=0.0
SRAMP = 5.0
SPEED=4 ' Saet hastighed
ACCEL=8 ' Saet acceleration
DECEL=8 ' Saet deceleration
CREEP=0.1
JOGSPEED=1.0
FE_LIMIT=5
DAC=0.0
REP_DIST=999999.0
FWD_IN=-1
REV_IN=-1
DATUM_IN=6
FHOLD_IN=-1
FS_LIMIT=160.0
RS_LIMIT=-160.0
'**************************************************
'* AXIS  D                                  *
'**************************************************
TABLE(pmpnstate,54)
BASE(axis_d)
'UNITS=65536*4*5/360
'UNITS=65536*60/360
IF workcelltype=1 THEN
  UNITS=65536*100/360
  P_GAIN=0.15
  I_GAIN=0.0
  D_GAIN=0.20
ELSE
  IF workcelltype=2 THEN
    UNITS=65536*135/360 '
    P_GAIN=0.3
    I_GAIN=0.0
    D_GAIN=0.20
  ELSE
    UNITS=65536*100/360 '
    P_GAIN=0.15
    I_GAIN=0.0
    D_GAIN=0.20
  ENDIF
ENDIF
OV_GAIN=0.0
VFF_GAIN=8.0
AFF_GAIN=0.0
SRAMP = 5.0
SPEED=4 ' Saet hastighed
ACCEL=8 ' Saet acceleration
DECEL=8 ' Saet deceleration
CREEP=0.1
JOGSPEED=1.0
FE_LIMIT=5
DAC=0.0
REP_DIST=999999.0
FWD_IN=-1
REV_IN=-1
'*HStomat
DATUM_IN=7
FHOLD_IN=-1
FS_LIMIT=999999.0
RS_LIMIT=-999999.0
'**************************************************
'* AXIS  E                                  *
'**************************************************
TABLE(pmpnstate,55)
BASE(axis_e)
'UNITS=65536*5/360
'UNITS=65536*60/360
IF workcelltype=1 THEN
  UNITS=65536*50/360 '
  P_GAIN=0.20
  I_GAIN=0.0
  D_GAIN=0.25
ELSE
  IF workcelltype=2 THEN
    UNITS=65536*135/360 '
    P_GAIN=0.40
    I_GAIN=0.0
    D_GAIN=0.25
  ELSE
    UNITS=65536*50/360 '
    P_GAIN=0.20
    I_GAIN=0.0
    D_GAIN=0.25
  ENDIF
ENDIF
OV_GAIN=0.0
VFF_GAIN=8.0
AFF_GAIN=0.0
SRAMP = 5.0
SPEED=4 ' Saet hastighed
ACCEL=8 ' Saet acceleration
DECEL=8 ' Saet deceleration
CREEP=0.1
JOGSPEED=1.0
FE_LIMIT=5
DAC=0.0
REP_DIST=999999.0
FWD_IN=-1
REV_IN=-1
'*HStomat
DATUM_IN=8
FHOLD_IN=-1
FS_LIMIT=999999.0
RS_LIMIT=-999999.0

'**************************************************
'* AXIS  F                                  *
'**************************************************
TABLE(pmpnstate,56)
BASE(axis_f)
UNITS=(65536*10)/(50*PI) 'tandhjul dele-diameter 50mm 7:1 gearing
P_GAIN=0.20
I_GAIN=0.0
D_GAIN=0.25
OV_GAIN=0.0
VFF_GAIN=8.0
AFF_GAIN=0.0
SRAMP = 5.0
SPEED=4 ' Saet hastighed
ACCEL=8 ' Saet acceleration
DECEL=8 ' Saet deceleration
CREEP=0.1
JOGSPEED=1.0
FE_LIMIT=5
DAC=0.0
REP_DIST=999999.0
FWD_IN=-1
REV_IN=-1
'*HStomat
DATUM_IN=-1
FHOLD_IN=-1
FS_LIMIT=999999.0
RS_LIMIT=-999999.0
'**************************************************
'* AXIS  T                                        *
'**************************************************
TABLE(pmpnstate,57)
BASE(axis_t)
UNITS=1
P_GAIN=0.0
I_GAIN=0.0
D_GAIN=0.0
OV_GAIN=0.0
VFF_GAIN=0.0
AFF_GAIN=0.0
SRAMP = 0.0
SPEED=30000 ' Saet hastighed
ACCEL=100000000 ' Saet acceleration
DECEL=100000000 ' Saet deceleration
CREEP=100
JOGSPEED=1000
FE_LIMIT=1
DAC=0.0
REP_OPTION=1
REP_DIST=99999999
FWD_IN=-1
REV_IN=-1
DATUM_IN=-1
FHOLD_IN=-1
FS_LIMIT=99999999
RS_LIMIT=-99999999
'**************************************************
'* AXIS  VT                                       *
'**************************************************
TABLE(pmpnstate,58)
BASE(axis_vt)
UNITS=1
P_GAIN=0.0
I_GAIN=0.0
D_GAIN=0.0
OV_GAIN=0.0
VFF_GAIN=0.0
AFF_GAIN=0.0
SRAMP = 0.0
SPEED=30000 ' Saet hastighed
ACCEL=100000000 ' Saet acceleration
DECEL=100000000 ' Saet deceleration
CREEP=100
JOGSPEED=1000
FE_LIMIT=1
DAC=0.0
REP_OPTION=1
REP_DIST=99999999
FWD_IN=-1
REV_IN=-1
DATUM_IN=-1
FHOLD_IN=-1
FS_LIMIT=99999999
RS_LIMIT=-99999999
RETURN

resetaxis:
inresetaxis=1
WDOG=OFF
WA(100)
IF axis_a_enabled = 1 THEN
  current_axis=axis_a
  GOSUB reset_drive
ENDIF
IF axis_b_enabled = 1 THEN
  current_axis=axis_b
  GOSUB reset_drive
ENDIF
IF axis_c_enabled = 1 THEN
  current_axis=axis_c
  GOSUB reset_drive
ENDIF
IF axis_d_enabled = 1 THEN
  current_axis=axis_d
  GOSUB reset_drive
ENDIF
IF axis_e_enabled = 1 THEN
  current_axis=axis_e
  GOSUB reset_drive
ENDIF
IF axis_f_enabled = 1 THEN
  current_axis=axis_f
  GOSUB reset_drive
ENDIF
DATUM(0)

WA(100)
IF axis_a_enabled = 1 THEN SERVO AXIS(axis_a)=ON
IF axis_b_enabled = 1 THEN SERVO AXIS(axis_b)=ON
IF axis_c_enabled = 1 THEN SERVO AXIS(axis_c)=ON
IF axis_d_enabled = 1 THEN SERVO AXIS(axis_d)=ON
IF axis_e_enabled = 1 THEN SERVO AXIS(axis_e)=ON
IF axis_f_enabled = 1 THEN SERVO AXIS(axis_f)=ON
'WDOG=ON
inresetaxis=0
RETURN

'**************************************************
'********** T E S T   F U N C T I O N S ***********
'**************************************************
' reset the amplifier in case of trip
reset_drive:
TABLE(pmpnstate,70+current_axis) 'reset axis num
tries = 0
reset_xx:
BASE(current_axis)
'PRINT "*******************************************"
'PRINT "*** R E S E T   A X I S ";current_axis[0];"  ****************"
'PRINT "*******************************************"
  IF MOTION_ERROR THEN DATUM(0)
  sum=0
  FOR check=1 TO 10
   sum=sum+DLINK(7,current_axis,251)
  NEXT check
  IF sum<>-10 THEN
    tries = tries+1
    IF tries > 5 THEN
'      PRINT "unable to reset drive axis ", current_axis
      STOP
    ELSE
      WA(10)
      GOTO reset_xx
    ENDIF
  ENDIF
 ' enable the axis
  DLINK(7,current_axis,253)
RETURN
'**************************************************
set_mpn_home_all:
TABLE(pmpnretur,0)
slm_is_ok = 1
GOSUB test_if_slm_is_ok
IF axis_a_enabled = 1 THEN GOSUB quick_datum_a
IF axis_b_enabled = 1 THEN GOSUB quick_datum_b
IF axis_c_enabled = 1 THEN GOSUB quick_datum_c
IF axis_d_enabled = 1 THEN GOSUB quick_datum_d
IF axis_e_enabled = 1 THEN GOSUB quick_datum_e
IF axis_f_enabled = 1 THEN GOSUB quick_datum_f
IF slm_is_ok=0 THEN
  TABLE(pmpnretur,1) 'tell master to show calib screen
  BASE(axis_b)
  FS_LIMIT=999.0
  RS_LIMIT=-999.0
  BASE(axis_c)
  FS_LIMIT=999.0
  RS_LIMIT=-999.0
ELSE
  IF axis_a_enabled = 1 THEN GOSUB set_mpnhome_a
  IF axis_b_enabled = 1 THEN GOSUB set_mpnhome_b
  IF axis_c_enabled = 1 THEN GOSUB set_mpnhome_c
  IF axis_d_enabled = 1 THEN GOSUB set_mpnhome_d
  IF axis_e_enabled = 1 THEN GOSUB set_mpnhome_e
  IF axis_f_enabled = 1 THEN GOSUB set_mpnhome_f
ENDIF
RETURN

get_abspos:
'  PRINT "******************************"
  pos = DLINK(5,dl_axis,74)
  flux = DLINK(5,dl_axis,75)
  zero = DLINK(5,dl_axis,76)
  rev = DLINK(5,dl_axis,90)
'  PRINT "AXIS ";dl_axis;" pos=";pos;" zero=";zero;" rev=";rev;" flux=";flux
  IF rev > 32767 THEN
'    PRINT "AXIS ";dl_axis;" rev>32767 rev=";rev
    rev = rev - 65536
'    PRINT "AXIS ";dl_axis;" rev=rev-65536 rev=";rev
  ENDIF
  abspos=rev*65536+pos-zero
'  PRINT "AXIS ";dl_axis;" abspos=";abspos
RETURN

'mpnhome positions are absolute SLM positions
set_mpnhome_a:
  BASE(axis_a)
  WAIT IDLE
  WA(50)
  OFFPOS = -mpnhome_a/UNITS
  WAIT UNTIL OFFPOS=0
RETURN
set_mpnhome_b:
  BASE(axis_b)
  WAIT IDLE
  WA(50)
  OFFPOS = -mpnhome_b/UNITS
  WAIT UNTIL OFFPOS=0
RETURN
set_mpnhome_c:
  BASE(axis_c)
  WAIT IDLE
  WA(50)
  OFFPOS = -mpnhome_c/UNITS
  WAIT UNTIL OFFPOS=0
RETURN
set_mpnhome_d:
  BASE(axis_d)
  WAIT IDLE
  WA(50)
  OFFPOS = -mpnhome_d/UNITS
  WAIT UNTIL OFFPOS=0
RETURN
set_mpnhome_e:
  BASE(axis_e)
  WAIT IDLE
  WA(50)
  OFFPOS = -mpnhome_e/UNITS
  WAIT UNTIL OFFPOS=0
RETURN
set_mpnhome_f:
  BASE(axis_f)
  WAIT IDLE
  WA(50)
  OFFPOS = -mpnhome_f/UNITS
  WAIT UNTIL OFFPOS=0
RETURN

quick_datum_a:
  TABLE(pmpnstate,81)
  BASE(axis_a)
  DATUM(2)
  WAIT IDLE
  WA(50)
  dl_axis = axis_a
  GOSUB get_abspos
  DEFPOS(abspos/UNITS)
  WAIT UNTIL OFFPOS=0
  WA(50)
RETURN
quick_datum_b:
  TABLE(pmpnstate,82)
  BASE(axis_b)
  IF workcelltype = 2 THEN
    DATUM(1)
  ELSE
    DATUM(2)
  ENDIF
  WAIT IDLE
  WA(50)
  dl_axis = axis_b
  GOSUB get_abspos
  DEFPOS(abspos/UNITS)
  WAIT UNTIL OFFPOS=0
  WA(50)
RETURN
quick_datum_c:
  TABLE(pmpnstate,83)
  BASE(axis_c)
  DATUM(1)
  WAIT IDLE
  WA(50)
  dl_axis = axis_c
  GOSUB get_abspos
  DEFPOS(abspos/UNITS)
  WAIT UNTIL OFFPOS=0
  WA(50)
RETURN
quick_datum_d:
  TABLE(pmpnstate,84)
  BASE(axis_d)
  DATUM(1)
  WAIT IDLE
  WA(50)
  dl_axis = axis_d
  GOSUB get_abspos
  DEFPOS(abspos/UNITS)
  WAIT UNTIL OFFPOS=0
  WA(50)
RETURN
quick_datum_e:
  TABLE(pmpnstate,85)
  BASE(axis_e)
  DATUM(2)
  WAIT IDLE
  WA(50)
  dl_axis = axis_e
  GOSUB get_abspos
  DEFPOS(abspos/UNITS)
  WAIT UNTIL OFFPOS=0
  WA(50)
RETURN
quick_datum_f:
  TABLE(pmpnstate,86)
  BASE(axis_f)
  DATUM(1)
  WAIT IDLE
  WA(50)
  dl_axis = axis_f
  GOSUB get_abspos
  DEFPOS(abspos/UNITS)
  WAIT UNTIL OFFPOS=0
  WA(50)
RETURN


set_defpos:
IF axis_a_enabled = 1 THEN GOSUB defpos_home_a
IF axis_b_enabled = 1 THEN GOSUB defpos_home_b
IF axis_c_enabled = 1 THEN GOSUB defpos_home_c
IF axis_d_enabled = 1 THEN GOSUB defpos_home_d
IF axis_e_enabled = 1 THEN GOSUB defpos_home_e
IF axis_f_enabled = 1 THEN GOSUB defpos_home_f
BASE(axis_t)
DEFPOS(0)
WAIT UNTIL OFFPOS=0' Ensures DEFPOS is complete before next line
RETURN

movehome:
  IF TABLE(pmpnretur+1) = 0 THEN
    BASE(axis_t)
    DEFPOS(0)
    WAIT UNTIL OFFPOS=0' Ensures DEFPOS is complete before next line
    mpnhome_t=0
  ENDIF
  IF TABLE(pmpnretur+1) = 1 THEN GOSUB defpos_home_a
  IF TABLE(pmpnretur+1) = 2 THEN GOSUB defpos_home_b
  IF TABLE(pmpnretur+1) = 3 THEN GOSUB defpos_home_c
  IF TABLE(pmpnretur+1) = 4 THEN GOSUB defpos_home_d
  IF TABLE(pmpnretur+1) = 5 THEN GOSUB defpos_home_e
  IF TABLE(pmpnretur+1) = 6 THEN GOSUB defpos_home_f
RETURN

defpos_home_a:
  BASE(axis_a)
'  DATUM(4)
  DATUM(2)
  WAIT IDLE
  WA(50)
  dl_axis = axis_a
  GOSUB get_abspos
  mpnhome_a = abspos
  DEFPOS(0)
  WAIT UNTIL OFFPOS=0
  WA(50)
  DLINK(6,axis_a,62,backup_val) 'set host flag for backup
RETURN

defpos_home_b:
  BASE(axis_b)
  IF workcelltype = 2 THEN
    DATUM(3)
  ELSE
    DATUM(4)
  ENDIF
  WAIT IDLE
  WA(50)
  dl_axis = axis_b
  GOSUB get_abspos
  mpnhome_b = abspos
  DEFPOS(0)
  WAIT UNTIL OFFPOS=0
  WA(50)
  DLINK(6,axis_b,62,backup_val) 'set host flag for backup
RETURN
defpos_home_c:
  BASE(axis_c)
  DATUM(3)
'  DATUM(1)
  WAIT IDLE
  WA(50)
  dl_axis = axis_c
  GOSUB get_abspos
  mpnhome_c = abspos '+ offset fra homesensor til lodret
  DEFPOS(0) 'OFFPOS=-DPOS
  WAIT UNTIL OFFPOS=0
  WA(50)
  DLINK(6,axis_c,62,backup_val) 'set host flag for backup
RETURN
defpos_home_d:
  BASE(axis_d)
'  DATUM(3)
  DATUM(1)
  WAIT IDLE
  WA(50)
  dl_axis = axis_d
  GOSUB get_abspos
  mpnhome_d = abspos
  DEFPOS(0)
  WAIT UNTIL OFFPOS=0
  WA(50)
  DLINK(6,axis_d,62,backup_val) 'set host flag for backup
RETURN
defpos_home_e:
  BASE(axis_e)
'  DATUM(1)
  DATUM(1)
  WAIT IDLE
  WA(50)
  dl_axis = axis_e
  GOSUB get_abspos
  mpnhome_e = abspos
  DEFPOS(0) 'OFFPOS=-DPOS
  WAIT UNTIL OFFPOS=0
  WA(50)
  DLINK(6,axis_e,62,backup_val) 'set host flag for backup
RETURN
defpos_home_f:
  BASE(axis_f)
'  DATUM(1)
  DATUM(1)
  WAIT IDLE
  WA(50)
  dl_axis = axis_f
  GOSUB get_abspos
  mpnhome_f = abspos
  DEFPOS(0) 'OFFPOS=-DPOS
  WAIT UNTIL OFFPOS=0
  WA(50)
  DLINK(6,axis_f,62,backup_val) 'set host flag for backup
RETURN

test_if_slm_is_ok:
IF axis_a_enabled = 1 THEN
  host_flag = DLINK(5,axis_a,62)
  IF host_flag <> backup_val THEN
    slm_is_ok = 0
    RETURN
  ENDIF
ENDIF
IF axis_b_enabled = 1 THEN
  host_flag = DLINK(5,axis_b,62)
  IF host_flag <> backup_val THEN
    slm_is_ok = 0
    RETURN
  ENDIF
ENDIF
IF axis_c_enabled = 1 THEN
  host_flag = DLINK(5,axis_c,62)
  IF host_flag <> backup_val THEN
    slm_is_ok = 0
    RETURN
  ENDIF
ENDIF
IF axis_d_enabled = 1 THEN
  host_flag = DLINK(5,axis_d,62)
  IF host_flag <> backup_val THEN
    slm_is_ok = 0
    RETURN
  ENDIF
ENDIF
IF axis_e_enabled = 1 THEN
  host_flag = DLINK(5,axis_e,62)
  IF host_flag <> backup_val THEN
    slm_is_ok = 0
    RETURN
  ENDIF
ENDIF
IF axis_f_enabled = 1 THEN
  host_flag = DLINK(5,axis_f,62)
  IF host_flag <> backup_val THEN
    slm_is_ok = 0
    RETURN
  ENDIF
ENDIF
RETURN


'**************************************************
'* EXPANDPATHDATA
'**************************************************
expandpathdata:
TICKS=0
VR(9) = TABLE(VR(8))'read numofaxis
maxspeed=TABLE(VR(8)+1) 'maxSpeed in ms is part of pathdata
VR(6) = TABLE(VR(8)+4)'numofsamples 'all axis have same numberofsamples
VR(5) = TABLE(VR(8)+5) 'numofhpoints
'TODO if VR(5)=0
FOR i=0 TO VR(5)-1
  VR(20+i) = TABLE(VR(8)+6+i) 'hpoint 0
NEXT i
GOSUB calgspeed 'update mpnspeed

VR(30) = VR(8)+6+VR(5) 'address of first keypoint axis a
VR(31) = VR(30)+VR(6) '-"- b
VR(32) = VR(31)+VR(6) '-"- c
VR(33) = VR(32)+VR(6) '-"- d
VR(34) = VR(33)+VR(6) '-"- e
VR(35) = VR(34)+VR(6) '-"- f
VR(36) = VR(35)+VR(6) '-"- t

'calg number of points to use between keypoints
VR(37)=INT(100000/((VR(6)+1)*7))

'expand address
VR(40) = pexpand 'expand address
VR(41) = VR(40) + (VR(6) + 1) * VR(37) + 1
VR(42) = VR(41) + (VR(6) + 1) * VR(37) + 1
VR(43) = VR(42) + (VR(6) + 1) * VR(37) + 1
VR(44) = VR(43) + (VR(6) + 1) * VR(37) + 1
VR(45) = VR(44) + (VR(6) + 1) * VR(37) + 1
VR(46) = VR(45) + (VR(6) + 1) * VR(37) + 1
'expand
B_SPLINE(1,VR(30),VR(6),VR(40),VR(37))
B_SPLINE(1,VR(31),VR(6),VR(41),VR(37))
B_SPLINE(1,VR(32),VR(6),VR(42),VR(37))
B_SPLINE(1,VR(33),VR(6),VR(43),VR(37))
B_SPLINE(1,VR(34),VR(6),VR(44),VR(37))
B_SPLINE(1,VR(35),VR(6),VR(45),VR(37))
B_SPLINE(1,VR(36),VR(6),VR(46),VR(37))
VR(300)=-TICKS
RETURN

movetofirsta:
  BASE(axis_a)
  MOVEABS(a)
  IF runningoffline=0 THEN
movetoloop1:
    IF MTYPE AXIS(axis_a)<>0 AND TABLE(pmpncancel)=0 THEN
           GOTO movetoloop1
    ENDIF
'todo if mpncancel=2
    IF TABLE(pmpncancel)=1 THEN
      rv=1
      ACCEL AXIS(axis_a)=SPEED AXIS(axis_a)*4
      DECEL AXIS(axis_a)=SPEED AXIS(axis_a)*4
      SPEED AXIS(axis_a)=0
      WAIT UNTIL VP_SPEED AXIS(axis_a)=0
      GOSUB cancelmove
      RETURN
    ENDIF
  ENDIF
RETURN


movetofirstabcde:
  BASE(axis_a,axis_b,axis_c,axis_d,axis_e)
  MOVEABS(a,b,c,d,e)
  IF runningoffline=0 THEN
movetoloop2:
    IF MTYPE AXIS(axis_a)<>0 AND TABLE(pmpncancel)=0 THEN
            GOTO movetoloop2
    ENDIF
'todo if mpncancel=2
    IF TABLE(pmpncancel)=1 THEN
      rv=1
      ACCEL AXIS(axis_a)=SPEED AXIS(axis_a)*4
      DECEL AXIS(axis_a)=SPEED AXIS(axis_a)*4
      SPEED AXIS(axis_a)=0
      WAIT UNTIL VP_SPEED AXIS(axis_a)=0
      GOSUB cancelmove
    ENDIF
  ENDIF
RETURN
'**************************************************
'* movetofirstpoint
'**************************************************
movetofirstpoint:
  IF ABS(TABLE(VR(40))-DPOS AXIS(axis_a))>0.001 THEN
    GOTO domoveabs
  ENDIF
  IF ABS(TABLE(VR(41))-DPOS AXIS(axis_b))>0.001 THEN
    GOTO domoveabs
  ENDIF
  IF ABS(TABLE(VR(42))-DPOS AXIS(axis_c))>0.001 THEN
    GOTO domoveabs
  ENDIF
  IF ABS(TABLE(VR(43))-DPOS AXIS(axis_d))>0.001 THEN
    GOTO domoveabs
  ENDIF
  IF ABS(TABLE(VR(44))-DPOS AXIS(axis_e))>0.001 THEN
    GOTO domoveabs
  ENDIF
'  IF ABS(TABLE(VR(45))-DPOS AXIS(axis_f))>0.001 THEN
'    GOTO domoveabs
'  ENDIF
  RETURN
domoveabs:
  TICKS=0
'move to first point
  WAIT IDLE AXIS(axis_a)
  fe_limit_axis_a = FE_LIMIT AXIS(axis_a)
  FE_LIMIT AXIS(axis_a)=10.0
  WAIT IDLE AXIS(axis_b)
  fe_limit_axis_b = FE_LIMIT AXIS(axis_b)
  FE_LIMIT AXIS(axis_b)=0.5
  WAIT IDLE AXIS(axis_c)
  fe_limit_axis_c = FE_LIMIT AXIS(axis_c)
  FE_LIMIT AXIS(axis_c)=0.5
  WAIT IDLE AXIS(axis_d)
  fe_limit_axis_d = FE_LIMIT AXIS(axis_e)
  FE_LIMIT AXIS(axis_d)=0.5
  WAIT IDLE AXIS(axis_e)
  fe_limit_axis_e = FE_LIMIT AXIS(axis_e)
  FE_LIMIT AXIS(axis_e)=0.5
'  WAIT IDLE AXIS(axis_f)
'  fe_limit_axis_f = FE_LIMIT AXIS(axis_f)
'  FE_LIMIT AXIS(axis_f)=1.0
  a=TABLE(VR(40))
  b=TABLE(VR(41))
  c=TABLE(VR(42))
  d=TABLE(VR(43))
  e=TABLE(VR(44))
  f=TABLE(VR(45))
  IF workcellid>=305 THEN
    a=MPOS AXIS(axis_a)
  ENDIF
  rv=0
  GOSUB movetofirsta
  IF rv=0 THEN
    WAIT IDLE AXIS(axis_a)
    GOSUB movetofirstabcde
    IF rv=0 THEN
      WAIT IDLE AXIS(axis_a)
      IF workcellid>=305 THEN
        a=TABLE(VR(40))
        GOSUB movetofirsta
        IF rv=0 THEN
          WAIT IDLE AXIS(axis_a)
        ENDIF
      ENDIF
    ENDIF
  ENDIF
  FE_LIMIT AXIS(axis_a)=fe_limit_axis_a
  FE_LIMIT AXIS(axis_b)=fe_limit_axis_b
  FE_LIMIT AXIS(axis_c)=fe_limit_axis_c
  FE_LIMIT AXIS(axis_d)=fe_limit_axis_d
  FE_LIMIT AXIS(axis_e)=fe_limit_axis_e
'  FE_LIMIT AXIS(axis_f)=fe_limit_axis_f
  IF rv=0 THEN
    BASE(axis_vt)
    DEFPOS(0)
    WAIT UNTIL OFFPOS=0' Ensures DEFPOS is complete before next line
    WAIT IDLE AXIS(axis_vt)
    BASE(axis_t)
    DEFPOS(0)
    WAIT UNTIL OFFPOS=0' Ensures DEFPOS is complete before next line
    WAIT IDLE AXIS(axis_t)
  ENDIF
  VR(301)=-TICKS
RETURN

'**************************************************
'* RUNCAMBOX
'**************************************************
runcambox:
GOSUB movetofirstpoint
IF rv=1 THEN RETURN
TICKS=0
'units
VR(11) =UNITS AXIS(axis_a)
VR(12) =UNITS AXIS(axis_b)
VR(13) =UNITS AXIS(axis_c)
VR(14) =UNITS AXIS(axis_d)
VR(15) =UNITS AXIS(axis_e)
VR(16) =UNITS AXIS(axis_f)
VR(17) =UNITS AXIS(axis_t)
'end address
VR(50) = pexpand + (VR(6) + 1) * VR(37)
VR(51) = VR(50) + (VR(6) + 1) * VR(37) + 1
VR(52) = VR(51) + (VR(6) + 1) * VR(37) + 1
VR(53) = VR(52) + (VR(6) + 1) * VR(37) + 1
VR(54) = VR(53) + (VR(6) + 1) * VR(37) + 1
VR(55) = VR(54) + (VR(6) + 1) * VR(37) + 1
VR(56) = VR(55) + (VR(6) + 1) * VR(37) + 1
'LINK cambox a,b,c,d,e,f to t
CAMBOX(VR(40),VR(50),VR(11),1000000,axis_t,2,0) AXIS(axis_a)
CAMBOX(VR(41),VR(51),VR(12),1000000,axis_t,2,0) AXIS(axis_b)
CAMBOX(VR(42),VR(52),VR(13),1000000,axis_t,2,0) AXIS(axis_c)
CAMBOX(VR(43),VR(53),VR(14),1000000,axis_t,2,0) AXIS(axis_d)
CAMBOX(VR(44),VR(54),VR(15),1000000,axis_t,2,0) AXIS(axis_e)
'CAMBOX(VR(45),VR(55),VR(16),1000000,axis_t,2,0) AXIS(axis_f)

'LINK cambox a,b,c,d,e to vt
'LINK vt to t
'CAMBOX(VR(40),VR(50),VR(11),1000000,axis_vt,2,0) AXIS(axis_a)
'CAMBOX(VR(41),VR(51),VR(12),1000000,axis_vt,2,0) AXIS(axis_b)
'CAMBOX(VR(42),VR(52),VR(13),1000000,axis_vt,2,0) AXIS(axis_c)
'CAMBOX(VR(43),VR(53),VR(14),1000000,axis_vt,2,0) AXIS(axis_d)
'CAMBOX(VR(44),VR(54),VR(15),1000000,axis_vt,2,0) AXIS(axis_e)
'CAMBOX(VR(45),VR(55),VR(16),1000000,axis_vt,2,0) AXIS(axis_f)
'CAMBOX(VR(46),VR(56),VR(17),1000000,axis_t,2,0) AXIS(axis_vt)
BASE(axis_t)
DEFPOS(0)
WAIT UNTIL OFFPOS=0' Ensures DEFPOS is complete before next line
WAIT IDLE AXIS(axis_t)
'OK
SPEED AXIS(axis_t)=mpnspeed
ACCEL AXIS(axis_t)=100000000 ' Saet acceleration
DECEL AXIS(axis_t)=100000000 ' Saet deceleration
MOVE(1000000) AXIS(axis_t)
RETURN
'**************************************************
'* MPNPATH
'**************************************************
mpnpath:
  '***************************************************************************
  '* DETERMIN PATH TYPE
  '***************************************************************************
  VR(7) = TABLE(pmpnretur+1)
  VR(8) = TABLE(VR(7)) 'read address of pathdata
  pathtype = TABLE(VR(8)+2)
  rv=0
  TABLE(pmpnretur+1,0)
'***************************************************************************
'* robostacker SECTION
'***************************************************************************
  IF pathtype=10 THEN
    GOSUB path10
  ENDIF
  IF pathtype=11 THEN
    GOSUB path11
  ENDIF
  IF pathtype=12 THEN
    GOSUB path12
  ENDIF
  IF pathtype=13 THEN
    GOSUB path13
  ENDIF
  IF pathtype=14 THEN
    GOSUB path14
  ENDIF
  IF pathtype=16 THEN
    GOSUB path16
  ENDIF
  IF pathtype=20 THEN
    GOSUB path20
  ENDIF
  IF pathtype=21 THEN
    GOSUB path21
  ENDIF
  IF pathtype=22 THEN
    GOSUB path22
  ENDIF
  IF pathtype=23 THEN
    GOSUB path23
  ENDIF
  IF pathtype=24 THEN
    GOSUB path24
  ENDIF
  IF pathtype=25 THEN
    GOSUB path25
  ENDIF
  IF pathtype=43 THEN
    GOSUB path43
  ENDIF
  IF pathtype=44 THEN
    GOSUB path44
  ENDIF
RETURN
'**************************************************
'* PATH10
'**************************************************
path10:
  rv=0
  TABLE(pmpnstate,30007) 'expand path
  GOSUB expandpathdata
  TABLE(pmpnstate,30002) 'finding start position
  GOSUB runcambox
  IF rv>0 THEN
    TABLE(pmpnretur,10) 'error durung start
    RETURN
  ENDIF
path10loop:
'crash sensor test
  IF IN(VR(602))=OFF AND VR(296)=1 THEN
     ACCEL AXIS(axis_t)=mpnspeed*4
     DECEL AXIS(axis_t)=mpnspeed*4
     SPEED AXIS(axis_t)=0
     WAIT UNTIL VP_SPEED AXIS(axis_t)=0
     RAPIDSTOP
     RAPIDSTOP
     TABLE(pmpnretur,34) 'crash
     RETURN
  ENDIF
'stop and cancel movement
  IF TABLE(pmpncancel)=1 THEN
     ACCEL AXIS(axis_t)=mpnspeed*4
     DECEL AXIS(axis_t)=mpnspeed*4
     SPEED AXIS(axis_t)=0
     WAIT UNTIL VP_SPEED AXIS(axis_t)=0
     RAPIDSTOP
     RAPIDSTOP
     TABLE(pmpnretur,11) 'mpncancel recieved from host
    RETURN
  ENDIF
 'pause and wait for continue movement
  IF TABLE(pmpncancel)=2 THEN
     ACCEL AXIS(axis_t)=mpnspeed*4
     DECEL AXIS(axis_t)=mpnspeed*4
     SPEED AXIS(axis_t)=0
     WAIT UNTIL VP_SPEED AXIS(axis_t)=0
     TABLE(pmpnstate,30011) 'paused
  ENDIF
 'continue movement
  IF TABLE(pmpncancel)=3 THEN
     ACCEL AXIS(axis_t)=mpnspeed*4
     DECEL AXIS(axis_t)=mpnspeed*4
     SPEED AXIS(axis_t)=mpnspeed
     WAIT UNTIL VP_SPEED AXIS(axis_t) = mpnspeed
     TABLE(pmpnstate,30012) 'continue
     TABLE(pmpncancel,0)
  ENDIF
  IF TABLE(pmpncancel)=0 THEN
    TABLE(pmpnstate,30009) 'running path
  ENDIF
'testing for dropped boxes etc here
' todo MTYPE
  IF MPOS AXIS(axis_t)>=990000 THEN
     TABLE(pmpnstate,30010) 'normal end
     TABLE(pmpnretur,0) 'mpncancel
     WAIT IDLE AXIS(axis_t)
     RETURN
  ENDIF
  GOTO path10loop
RETURN
'**************************************************
'* PATH16
'**************************************************
path16:
  TICKS=0
  rv=0
  ktest=0
  OP(VR(610),OFF)
  OP(VR(611),OFF)
  OP(VR(609),ON)
  TABLE(pmpnstate,30002)
  GOSUB expandpathdata
  GOSUB runcambox
  IF rv>0 THEN RETURN
  waitposition=990000:GOSUB zwaituntilposition
  IF rv>0 THEN RETURN
  OP(VR(610),OFF)
  OP(VR(611),OFF)
  OP(VR(609),ON)
  WAIT IDLE AXIS(axis_t)
  VR(302)=-TICKS
RETURN
'**************************************************
'* PATH20 pick from pallet a
'**************************************************
path20:
  TICKS=0
  rv=0
  ktest=0
  TABLE(pmpnstate,30003)
  OP(VR(610),OFF)
  OP(VR(611),OFF)
  GOSUB expandpathdata
  GOSUB runcambox
  IF rv>0 THEN RETURN
  waitposition=990000:GOSUB zwaituntilposition
  IF rv>0 THEN RETURN
  OP(VR(610),ON)
 OP(VR(611),ON)
  WAIT IDLE AXIS(axis_t)
  VR(302)=-TICKS
RETURN
'**************************************************
'* PATH21 move from pallet a to conveyor a
'**************************************************
path21:
  OP(VR(610),ON)
 OP(VR(611),ON)
  TICKS=0
  rv=0
  ktest=0
  TABLE(pmpnstate,30004)
  GOSUB expandpathdata
  GOSUB runcambox
  IF rv>0 THEN RETURN
  IF VR(298)=1 THEN
    IF IN(VR(603))=ON THEN
      ktest=1
    ENDIF
  ELSE
    IF VR(298)=2 THEN
    ELSE
      IF VR(298)=3 THEN
        IF VR(299)=1 AND (IN(VR(600))=ON OR IN(VR(604))=ON) THEN
          ktest=1
        ENDIF
        IF VR(299)=2 AND IN(VR(604))=ON THEN
          ktest=1
        ENDIF
      ELSE
        ktest=1
      ENDIF
    ENDIF
  ENDIF
  waitposition=VR(20)+VR(250):GOSUB zwaituntilposition
  IF rv>0 THEN RETURN
  IF ktest=1 AND VR(299)=1 AND (IN(VR(600))=OFF OR IN(VR(604))=OFF) THEN
    'release box, continue path and tell master to show continue screen
    OP(VR(610),OFF)
    OP(VR(611),OFF)
    TABLE(pmpnretur,31)
  ENDIF
  IF ktest=1 AND VR(299)=2 AND IN(VR(604))=OFF THEN
    'release box, continue path and tell master to show continue screen
    OP(VR(610),OFF)
    OP(VR(611),OFF)
    TABLE(pmpnretur,31)
  ENDIF
  TABLE(pmpnstate,30005)
  waitposition=VR(252):GOSUB zwaituntilposition
  IF rv>0 THEN RETURN
  IF ktest=1 AND VR(299)=1 AND (IN(VR(600))=OFF OR IN(VR(604))=OFF) THEN
    'release box, continue path and tell master to show continue screen
    OP(VR(610),OFF)
    OP(VR(611),OFF)
    TABLE(pmpnretur,31)
  ENDIF
  IF ktest=1 AND VR(299)=2 AND IN(VR(604))=OFF THEN
    'release box, continue path and tell master to show continue screen
    OP(VR(610),OFF)
    OP(VR(611),OFF)
    TABLE(pmpnretur,31)
  ENDIF

IF VR(297)=1 THEN
'**************************************************
'* waituntilposition waits for a position on the time axis
'**************************************************
  waitposition=VR(21)
p21waituntilposition:
  rv=0
p21loopwup1:
  IF TABLE(pmpncancel)=1 THEN
     rv=1
     GOSUB cancelmove
     RETURN
  ENDIF
  IF IN(VR(602))=OFF AND VR(296)=1 THEN
     rv=1
     GOSUB cancelmove
     TABLE(pmpnretur,8)
     RETURN
  ENDIF
  IF IN(VR(607))=OFF THEN
    'dobbelt kasse stop NU
    'release box, stop path and tell master to show continue screen
    rv=1
    GOSUB newcancelmove
    TABLE(pmpnretur,34)
    OP(VR(610),OFF)
    OP(VR(611),OFF)
    RETURN
  ENDIF
  IF MPOS AXIS(axis_t)<waitposition THEN
     GOTO p21loopwup1
  ENDIF
ENDIF

  waitposition=990000:GOSUB zwaituntilposition
  IF rv>0 THEN RETURN
  OP(VR(610),OFF)
  OP(VR(611),OFF)
  WAIT IDLE AXIS(axis_t)
RETURN
'**************************************************
'* PATH22 return from conveyor a to home
'**************************************************
path22:
  OP(VR(610),OFF)
  OP(VR(611),OFF)
  TICKS=0
  rv=0
  ktest=0
  TABLE(pmpnstate,30006)
  GOSUB expandpathdata
  GOSUB runcambox
  IF rv>0 THEN RETURN
  waitposition=990000:GOSUB zwaituntilposition
  IF rv>0 THEN RETURN
  OP(VR(610),OFF)
  OP(VR(611),OFF)
  WAIT IDLE AXIS(axis_t)
RETURN
'**************************************************
'* PATH23 pick from conveyor b
'**************************************************
path23:
  OP(VR(610),OFF)
  OP(VR(611),OFF)
  TICKS=0
  rv=0
  TABLE(pmpnstate,30003)
  OP(VR(610),OFF)
  OP(VR(611),OFF)
  GOSUB expandpathdata
  GOSUB runcambox
  IF rv>0 THEN RETURN
  waitposition=990000:GOSUB zwaituntilposition
  IF rv>0 THEN RETURN
  OP(VR(610),ON)
  OP(VR(611),ON)
  WAIT IDLE AXIS(axis_t)
RETURN
'**************************************************
'* PATH24 move from conveyor b to pallet b
'**************************************************
path24:
  OP(VR(610),ON)
  OP(VR(611),ON)
  TICKS=0
  rv=0
  ktest=0
  TABLE(pmpnstate,30004)
  GOSUB expandpathdata
  GOSUB runcambox
  IF rv>0 THEN RETURN
  IF VR(298)=1 OR VR(298)=3 THEN
    'allways test if we drop a box
    ktest=1
  ENDIF
  waitposition=VR(20)+VR(251):GOSUB zwaituntilposition
  IF rv>0 THEN RETURN
  IF ktest=1 AND VR(299)=1 AND (IN(VR(600))=OFF OR IN(VR(604))=OFF) THEN
    'release box, stop path and tell master to show continue screen
    rv=1
    GOSUB newcancelmove
    TABLE(pmpnretur,32)
    OP(VR(610),OFF)
    OP(VR(611),OFF)
    RETURN
  ENDIF
  IF ktest=1 AND VR(299)=2 AND IN(VR(604))=OFF THEN
    'release box, stop path and tell master to show continue screen
    rv=1
    GOSUB newcancelmove
    TABLE(pmpnretur,32)
    OP(VR(610),OFF)
    OP(VR(611),OFF)
    RETURN
  ENDIF
  TABLE(pmpnstate,30005)
  waitposition=VR(252):GOSUB zwaituntilposition
  IF rv>0 THEN RETURN
  IF ktest=1 AND VR(299)=1 AND (IN(VR(600))=OFF OR IN(VR(604))=OFF) THEN
    'release box, stop path and tell master to show continue screen
    rv=1
    GOSUB newcancelmove
    TABLE(pmpnretur,32)
    OP(VR(610),OFF)
    OP(VR(611),OFF)
    RETURN
  ENDIF
  IF ktest=1 AND VR(299)=2 AND IN(VR(604))=OFF THEN
    'release box, stop path and tell master to show continue screen
    rv=1
    GOSUB newcancelmove
    TABLE(pmpnretur,32)
    OP(VR(610),OFF)
    OP(VR(611),OFF)
    RETURN
  ENDIF
  TABLE(pmpnstate,30005)
  boxunaligned=0
  waitposition=990000:GOSUB zwaituntilposition
  IF rv>0 THEN RETURN
  'verify that box is aligned
  IF (VR(298)=1 OR VR(298)=3) AND (IN(VR(603))=ON OR boxunaligned=1) THEN
    'release box, continue path and tell master to show continue screen
    TABLE(pmpnretur+1,333)
  ENDIF
  'lift sensor cylinders
 OP(VR(611),OFF)
 TICKS=300
 WAIT UNTIL TICKS<=0
 OP(VR(610),OFF)
 WAIT IDLE AXIS(axis_t)
RETURN
'**************************************************
'* PATH25 home from pallet b
'**************************************************
path25:
 OP(VR(610),OFF)
 OP(VR(611),OFF)
  TICKS=0
  rv=0
  ktest=0
  TABLE(pmpnstate,30006)
  OP(VR(611),OFF)
  GOSUB expandpathdata
  GOSUB runcambox
  IF rv>0 THEN RETURN
  waitposition=VR(20):GOSUB zwaituntilposition
  IF rv>0 THEN RETURN
  'lift sensor cylinders
  OP(VR(610),OFF)
  waitposition=990000:GOSUB zwaituntilposition
  IF rv>0 THEN RETURN
 OP(VR(610),OFF)
 OP(VR(611),OFF)
  WAIT IDLE AXIS(axis_t)
RETURN
'*************************************************
'* PATH43 conveyorB home
'*************************************************
path43:
 OP(VR(610),OFF)
 OP(VR(611),OFF)
  TICKS=0
  rv=0
  ktest=0
  TABLE(pmpnstate,30006)
  GOSUB expandpathdata
 WAIT UNTIL -TICKS>=1000.0
  GOSUB runcambox
  IF rv>0 THEN RETURN
  waitposition=990000:GOSUB zwaituntilposition
  IF rv>0 THEN RETURN
 OP(VR(610),OFF)
 OP(VR(611),OFF)
  WAIT IDLE AXIS(axis_t)
RETURN
'*************************************************
'* PATH44 palletB conveyorB
'*************************************************
path44:
 OP(VR(610),OFF)
 OP(VR(611),OFF)
  TICKS=0
  rv=0
  ktest=0
  TABLE(pmpnstate,30003)
  OP(VR(611),OFF)
  GOSUB expandpathdata
  GOSUB runcambox
  IF rv>0 THEN RETURN
  waitposition=VR(20):GOSUB zwaituntilposition
  IF rv>0 THEN RETURN
  'lift sensor cylinders
  OP(VR(610),OFF)
  waitposition=990000:GOSUB zwaituntilposition
  IF rv>0 THEN RETURN
  OP(VR(610),ON)
  OP(VR(611),ON)
  WAIT IDLE AXIS(axis_t)
RETURN
'**************************************************
'* PATH11 nyhuus home
'**************************************************
path11:
 OP(VR(610),OFF) 'lift flap
 OP(VR(611),OFF) 'close trap
 OP(VR(609),ON) 'close trap
  TICKS=0
  rv=0
  ktest=0
  TABLE(pmpnstate,20101)
  OP(VR(611),OFF)
  GOSUB expandpathdata
  GOSUB runcambox
  IF rv>0 THEN RETURN
  TABLE(pmpnstate,20102)
  waitposition=990000:GOSUB zwaituntilposition
  IF rv>0 THEN RETURN
  WAIT IDLE AXIS(axis_t)
RETURN
'**************************************************
'* PATH12 toConveyor
'**************************************************
path12:
  OP(VR(610),OFF)
  OP(VR(611),OFF)
  OP(VR(609),ON) 'close trap
  rv = 0
  TABLE(pmpnstate,20201)
  IF IN(VR(602))=ON OR IN(VR(603))=ON THEN
    TABLE(pmpnstate,20103)
    rv = 1
    GOSUB cancelmove
    RETURN
  ENDIF
  GOSUB expandpathdata
  GOSUB runcambox
  IF rv > 0 THEN RETURN
  TABLE(pmpnstate,20202)
  waitposition = 990000: GOSUB zwaituntilposition
  IF rv > 0 THEN RETURN
  WAIT IDLE AXIS(axis_t)
RETURN
'**************************************************
'* PATH13 conveyor to pallet
'**************************************************
path13:
  OP(VR(610),ON)
  OP(VR(611),OFF)
  OP(VR(609),ON)
  rv = 0
  TABLE(pmpnstate,20201)
  IF IN(VR(602))=ON OR IN(VR(603))=ON THEN
    TABLE(pmpnstate,20103)
    rv = 1
    GOSUB cancelmove
    RETURN
  ENDIF
  GOSUB expandpathdata
  GOSUB runcambox
  IF rv > 0 THEN RETURN
  TABLE(pmpnstate,20202)
  waitposition = 990000: GOSUB zwaituntilposition
  IF rv > 0 THEN RETURN
  OP(VR(610),ON)
  OP(VR(611),ON)
  OP(VR(609),OFF)
  WAIT IDLE AXIS(axis_t)
RETURN
'**************************************************
'* PATH14 away from pallet
'**************************************************
path14:
  rv = 0
  TABLE(pmpnstate,20201)
  IF IN(VR(602))=ON OR IN(VR(603))=ON THEN
    TABLE(pmpnstate,20103)
    rv = 1
    GOSUB cancelmove
    RETURN
  ENDIF
  GOSUB expandpathdata
  GOSUB runcambox
  IF rv > 0 THEN RETURN
  TABLE(pmpnstate,20202)
  waitposition = 200000: GOSUB zwaituntilposition
  IF rv > 0 THEN RETURN
  OP(VR(610),OFF)
  OP(VR(611),OFF)
  OP(VR(609),ON)
  waitposition = 990000: GOSUB zwaituntilposition
  IF rv > 0 THEN RETURN
  WAIT IDLE AXIS(axis_t)
RETURN
'***************************************************************************
'* END robostacker SECTION
'***************************************************************************
'*******************************************************************************
'*
'* generel SUB's - can be used by all workcells
'*
'*******************************************************************************
speedup:
  IF oldspeedfactor<>TABLE(pmpnspeedfactor) THEN
    GOSUB calgspeed
    oldspeedfactor=TABLE(pmpnspeedfactor)
  ENDIF
  ACCEL AXIS(axis_t)=mpnspeed*2
  DECEL AXIS(axis_t)=mpnspeed*2
  SPEED AXIS(axis_t)=mpnspeed
  RETURN

zspeedup:
  IF oldspeedfactor<>TABLE(pmpnspeedfactor) THEN
    GOSUB calgspeed
    oldspeedfactor=TABLE(pmpnspeedfactor)
  ENDIF
  ACCEL AXIS(axis_t)=mpnspeed*5
  DECEL AXIS(axis_t)=mpnspeed*5
  SPEED AXIS(axis_t)=mpnspeed
  RETURN

slowspeedup:
  IF oldspeedfactor<>TABLE(pmpnspeedfactor) THEN
    GOSUB calgspeed
    oldspeedfactor=TABLE(pmpnspeedfactor)
    ACCEL AXIS(axis_t)=mpnspeed*0.5
    DECEL AXIS(axis_t)=mpnspeed
    SPEED AXIS(axis_t)=mpnspeed
    speedchange=0
  ENDIF
  RETURN

quickstop:
  ACCEL AXIS(axis_t)=mpnspeed*2
  DECEL AXIS(axis_t)=mpnspeed*2
  SPEED AXIS(axis_t)=0
  WAIT UNTIL VP_SPEED AXIS(axis_t)=0
  RETURN

zstop:
  ACCEL AXIS(axis_t)=mpnspeed*5
  DECEL AXIS(axis_t)=mpnspeed*5
  SPEED AXIS(axis_t)=0
  WAIT UNTIL VP_SPEED AXIS(axis_t)=0
  RETURN
'**************************************************
'* zwaituntilposition waits for a position on the time axis
'**************************************************
zwaituntilposition:
  rv=0
zloopwup1:
  IF TABLE(pmpncancel)=1 THEN
     rv=1
     GOSUB cancelmove
     RETURN
  ENDIF
  IF IN(VR(602))=OFF AND VR(296)=1 THEN
     rv=1
     GOSUB cancelmove
     TABLE(pmpnretur,8)
     RETURN
  ENDIF
  IF IN(VR(603))=ON THEN
    boxunaligned=1
  ENDIF
  IF MPOS AXIS(axis_t)>=waitposition THEN
     RETURN
  ENDIF
  GOTO zloopwup1
'**************************************************
'* generel SUB'S that performs rapidstop
'**************************************************
newcancelmove:
  ACCEL AXIS(axis_t)=mpnspeed*4
  DECEL AXIS(axis_t)=mpnspeed*4
  SPEED AXIS(axis_t)=0
  WAIT UNTIL VP_SPEED AXIS(axis_t)=0
  RAPIDSTOP
  RAPIDSTOP
  RETURN

cancelmove:
  ACCEL AXIS(axis_t)=mpnspeed*8
  DECEL AXIS(axis_t)=mpnspeed*8
  SPEED AXIS(axis_t)=0
  WAIT UNTIL VP_SPEED AXIS(axis_t)=0
  RAPIDSTOP
  RAPIDSTOP
  TABLE(pmpncancel,0)
  TABLE(pmpnretur,6)
  RETURN

'**************************************************
'* generel SUB'S that regulate speed
'**************************************************
calgspeed:
  tempspeed=maxspeed 'convert to sec
  IF tempspeed > 0 THEN
    mpnspeed=INT(TABLE(pmpnspeedfactor)*1000000/tempspeed)*1000
' mpnspeed=mpnspeed*1.05
  ELSE
    mpnspeed=0
  ENDIF
  RETURN

error_routine:
  TABLE(pmpnbasicerror,RUN_ERROR)
  TABLE(pmpnlinenumber,ERROR_LINE)
  WDOG=OFF
  IF inresetaxis = 0 THEN
    TABLE(pmpnstate,7000+(dlink_status*10)+dl_axis)
  ELSE
    TABLE(pmpnstate,7000+current_axis)
  ENDIF
  WAIT UNTIL TABLE(pmpncancel)=1
  TABLE(pmpncancel,0)
  TABLE(pmpnbasicerror,0)
  TABLE(pmpnlinenumber,0)
  TABLE(pmpncommand,1)
  TABLE(pmpnretur,7)
  inresetaxis=0
  GOTO mainloop
  STOP

