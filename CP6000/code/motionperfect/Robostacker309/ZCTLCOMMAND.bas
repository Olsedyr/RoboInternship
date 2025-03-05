blink = OFF
TICKS=0
ON BASICERROR GOTO error_routine
mainloop:
    IF TABLE(pctlcommand)>1 THEN
zctlcommand:
    TABLE(pctlretur,0)
    'WDOG
    IF TABLE(pctlcommand)=2 THEN
      IF runningoffline=1 THEN
        TABLE(pctlretur,1)
      ELSE
        TABLE(pctlretur,WDOG)
      ENDIF
      TABLE(pctlcommand,1)
      GOTO mainloop
    ENDIF
    'set_outport
    IF TABLE(pctlcommand)=5 THEN
      vrnumber=600+TABLE(pctlretur+1)
      TABLE(pctlretur,OP(VR(vrnumber),TABLE(pctlretur+2)))
      TABLE(pctlcommand,1)
      GOTO mainloop
    ENDIF
    'get_in
    IF TABLE(pctlcommand)=6 THEN
      TABLE(pctlretur,IN OR OP)
      TABLE(pctlcommand,1)
      GOTO mainloop
    ENDIF
    'get_erroraxis
    IF TABLE(pctlcommand)=7 THEN
      TABLE(pctlretur,ERROR_AXIS)
      TABLE(pctlcommand,1)
      GOTO mainloop
    ENDIF
    'moveallabs
    IF TABLE(pctlcommand)=8 THEN
      a=TABLE(pctlretur+1)
      b=TABLE(pctlretur+2)
      c=TABLE(pctlretur+3)
      d=TABLE(pctlretur+4)
      e=TABLE(pctlretur+5)
      BASE(axis_a,axis_b,axis_c,axis_d,axis_e)
      MOVEABS(a,b,c,d,e)
      TABLE(pctlcommand,1)
      GOTO mainloop
    ENDIF
    'move one axis
    IF TABLE(pctlcommand)=9 THEN
      MOVE(TABLE(pctlretur+2)) AXIS(TABLE(pctlretur+1))
      TABLE(pctlcommand,1)
      GOTO mainloop
    ENDIF
    'moveabs one axis
    IF TABLE(pctlcommand)=10 THEN
      MOVEABS(TABLE(pctlretur+2)) AXIS(TABLE(pctlretur+1))
      TABLE(pctlcommand,1)
      GOTO mainloop
    ENDIF
    'movemodify one axis
    IF TABLE(pctlcommand)=11 THEN
      MOVEMODIFY(TABLE(pctlretur+2)) AXIS(TABLE(pctlretur+1))
      TABLE(pctlcommand,1)
      GOTO mainloop
    ENDIF
    'version
    IF TABLE(pctlcommand)=12 THEN
'VERSION=2 PID from host
'VERSION=3 kasseLift axis_f
      TABLE(pctlretur,3)
      TABLE(pctlcommand,1)
      GOTO mainloop
    ENDIF
    'endmove
    IF TABLE(pctlcommand)=13 THEN
      TABLE(pctlretur,ENDMOVE AXIS(TABLE(pctlretur+1)))
      TABLE(pctlcommand,1)
      GOTO mainloop
    ENDIF
    'AXISVALUES
    IF TABLE(pctlcommand)=14 THEN
'caglulate address where axisvalues are stored
'first parameter to axisrefresh command is axis number
'second parameter is block number
'third parameter is read or write
zaxisvalues:
      idx = paxis_t + TABLE(pctlretur+1) * 29
      dl_axis = TABLE(pctlretur+1)
      IF TABLE(pctlretur+2) = 1 THEN
        GOSUB getreadonly
      ELSE
        IF TABLE(pctlretur+2) = 0 THEN
          IF TABLE(pctlretur+3) = 0 THEN
            GOSUB getreadwrite
          ELSE
            GOSUB setreadwrite
          ENDIF
        ELSE
'used when host controls the PID values
          IF TABLE(pctlretur+2) = 2 THEN
            IF TABLE(pctlretur+3) = 0 THEN
              GOSUB getreadonly2
            ELSE
              GOSUB setreadwrite2
            ENDIF
          ENDIF
        ENDIF
      ENDIF
      TABLE(pctlcommand,1)
      GOTO mainloop
    ENDIF
    'set speedfactor
    IF TABLE(pctlcommand)=15 THEN
      IF TABLE(pctlretur+1) >= 0.0 AND TABLE(pctlretur+1) <= 1.0 THEN
        TABLE(pmpnspeedfactor,TABLE(pctlretur+1))
      ENDIF
      TABLE(pctlcommand,1)
      GOTO mainloop
    ENDIF
    'get speedfactor
    IF TABLE(pctlcommand)=16 THEN
      TABLE(pctlretur,TABLE(pmpnspeedfactor))
      TABLE(pctlcommand,1)
      GOTO mainloop
    ENDIF
    'GET VR
    IF TABLE(pctlcommand)=17 THEN
      TABLE(pctlretur,VR(TABLE(pctlretur+1)))
      TABLE(pctlcommand,1)
      GOTO mainloop
    ENDIF
    'SET VR
    IF TABLE(pctlcommand)=18 THEN
      TABLE(pctlretur,VR(TABLE(pctlretur+1)))
      VR(TABLE(pctlretur+1))=TABLE(pctlretur+2)
      TABLE(pctlcommand,1)
      GOTO mainloop
    ENDIF
    'mtype
    IF TABLE(pctlcommand)=20 THEN
      TABLE(pctlretur,MTYPE AXIS(TABLE(pctlretur+1)))
      TABLE(pctlcommand,1)
      GOTO mainloop
    ENDIF
    ENDIF 'if ctlcommand>1
'put code that has to run when ctl is idle here
zauto:
    'pmpntrio trio.c summary
    IF runningoffline=1 THEN
      TABLE(pmpntrio,1)
    ELSE
'watchdog
      TABLE(pmpntrio,WDOG)
    ENDIF
'robot emergency
    TABLE(pmpntrio+1,IN(VR(601)))
'robotstate
    TABLE(pmpntrio+2,TABLE(pmpnstate))
'
    TABLE(pmpntrio+3,MTYPE AXIS(0))
'
    TABLE(pmpntrio+4,MTYPE AXIS(6))
'
    TABLE(pmpntrio+5,MPOS AXIS(0))
    TABLE(pmpntrio+6,MPOS AXIS(1))
    TABLE(pmpntrio+7,MPOS AXIS(2))
    TABLE(pmpntrio+8,MPOS AXIS(3))
    TABLE(pmpntrio+9,MPOS AXIS(4))
    TABLE(pmpntrio+10,MPOS AXIS(5))
    TABLE(pmpntrio+11,MPOS AXIS(6))
    TABLE(pmpntrio+12,FE AXIS(0))
    TABLE(pmpntrio+13,FE AXIS(1))
    TABLE(pmpntrio+14,FE AXIS(2))
    TABLE(pmpntrio+15,FE AXIS(3))
    TABLE(pmpntrio+16,FE AXIS(4))
    TABLE(pmpntrio+17,FE AXIS(5))
    TABLE(pmpntrio+18,FE AXIS(6))

    'kasseLift
    IF workcellid = 401 AND axis_f_enabled = 1 THEN
      IF TABLE(pmpnlift) = 1 THEN
        BASE(axis_f)
        SPEED = TABLE(pmpnlift+1)
        ACCEL = TABLE(pmpnlift+2)
        DECEL = TABLE(pmpnlift+3)
        MOVEMODIFY(TABLE(pmpnlift+4))
      ELSE
        BASE(axis_f)
        CANCEL(1)
        CANCEL(0)
      ENDIF
    ENDIF

    IF TICKS<-500 THEN
        IF blink=OFF THEN
            blink=ON
        ELSE
            blink=OFF
        ENDIF
        TICKS=0
    ENDIF
    'test for emergency
    IF WDOG=OFF THEN
      OP(VR(612),OFF) 'green
      OP(VR(613),OFF) 'yellow
      OP(VR(614),ON) 'red
    ELSE
      IF TABLE(pmpnrunning)=0 THEN
          OP(VR(612),OFF) 'green
          OP(VR(613),ON) 'yellow
          OP(VR(614),OFF) 'red
      ENDIF
      'STARTING
      IF TABLE(pmpnrunning)=1 THEN
          OP(VR(612),blink) 'green
          OP(VR(613),ON) 'yellow
          OP(VR(614),OFF) 'red
      ENDIF
      'RUNNING
      IF TABLE(pmpnrunning)=2 THEN
          OP(VR(612),ON) 'green
          OP(VR(613),OFF) 'yellow
          OP(VR(614),OFF) 'red
      ENDIF
      'STOPPING
      IF TABLE(pmpnrunning)=3 THEN
          OP(VR(612),blink) 'green
          OP(VR(613),ON) 'yellow
          OP(VR(614),OFF) 'red
      ENDIF
      'PAUSED
      IF TABLE(pmpnrunning)=4 THEN
          OP(VR(612),blink) 'green
          OP(VR(613),blink) 'yellow
          OP(VR(614),OFF) 'red
      ENDIF
      'WDOGOFF
      IF TABLE(pmpnrunning)=5 THEN
          OP(VR(612),OFF) 'green
          OP(VR(613),OFF) 'yellow
          OP(VR(614),ON) 'red
      ENDIF
      'ERROR
      IF TABLE(pmpnrunning)=6 THEN
          OP(VR(612),OFF) 'green
          OP(VR(613),OFF) 'yellow
          OP(VR(614),blink) 'red
      ENDIF
    ENDIF
    GOTO mainloop
STOP
getreadonly:
BASE(dl_axis)
TABLE(idx+22,MTYPE )
TABLE(idx+23,NTYPE )
TABLE(idx+24,MPOS )
TABLE(idx+25,DPOS)
TABLE(idx+26,FE)
TABLE(idx+27,AXISSTATUS)
TABLE(idx+28,VP_SPEED)
RETURN

getreadwrite:
BASE(dl_axis)
TABLE(idx,ATYPE )
TABLE(idx+1,P_GAIN )
TABLE(idx+2,I_GAIN )
TABLE(idx+3,D_GAIN )
TABLE(idx+4,OV_GAIN)
TABLE(idx+5,VFF_GAIN )
TABLE(idx+6,UNITS )
TABLE(idx+7,SPEED )
TABLE(idx+8,ACCEL )
TABLE(idx+9,DECEL )
TABLE(idx+10,CREEP )
TABLE(idx+11,JOGSPEED )
TABLE(idx+12,FE_LIMIT )
TABLE(idx+13,DAC )
TABLE(idx+14,SERVO )
TABLE(idx+15,REP_DIST )
TABLE(idx+16,FWD_IN )
TABLE(idx+17,REV_IN )
TABLE(idx+18,DATUM_IN )
TABLE(idx+19,FHOLD_IN )
TABLE(idx+20,FS_LIMIT )
TABLE(idx+21,RS_LIMIT )
RETURN

setreadwrite:
BASE(dl_axis)
P_GAIN = TABLE(idx+1)
I_GAIN = TABLE(idx+2)
D_GAIN = TABLE(idx+3)
OV_GAIN = TABLE(idx+4 )
VFF_GAIN = TABLE(idx+5 )
UNITS = TABLE(idx+6 )
SPEED = TABLE(idx+7 )
ACCEL = TABLE(idx+8 )
DECEL = TABLE(idx+9 )
CREEP = TABLE(idx+10 )
JOGSPEED = TABLE(idx+11 )
FE_LIMIT = TABLE(idx+12 )
DAC = TABLE(idx+13 )
SERVO = TABLE(idx+14 )
REP_DIST = TABLE(idx+15)
FWD_IN = TABLE(idx+16 )
REV_IN = TABLE(idx+17 )
DATUM_IN = TABLE(idx+18 )
FHOLD_IN = TABLE(idx+19 )
FS_LIMIT= TABLE(idx+20 )
RS_LIMIT= TABLE(idx+21 )
RETURN

getreadonly2:
BASE(dl_axis)
TABLE(idx,ATYPE )
TABLE(idx+13,DAC )
TABLE(idx+14,SERVO )
TABLE(idx+15,REP_DIST )
TABLE(idx+16,FWD_IN )
TABLE(idx+17,REV_IN )
TABLE(idx+18,DATUM_IN )
TABLE(idx+19,FHOLD_IN )
TABLE(idx+20,FS_LIMIT )
TABLE(idx+21,RS_LIMIT )
TABLE(idx+22,MTYPE )
TABLE(idx+23,NTYPE )
TABLE(idx+24,MPOS )
TABLE(idx+25,DPOS)
TABLE(idx+26,FE)
TABLE(idx+27,AXISSTATUS)
TABLE(idx+28,VP_SPEED)
RETURN

setreadwrite2:
BASE(dl_axis)
P_GAIN = TABLE(idx+1)
I_GAIN = TABLE(idx+2)
D_GAIN = TABLE(idx+3)
OV_GAIN = TABLE(idx+4 )
VFF_GAIN = TABLE(idx+5 )
UNITS = TABLE(idx+6 )
SPEED = TABLE(idx+7 )
ACCEL = TABLE(idx+8 )
DECEL = TABLE(idx+9 )
CREEP = TABLE(idx+10 )
JOGSPEED = TABLE(idx+11 )
FE_LIMIT = TABLE(idx+12 )
RETURN

error_routine:
 TABLE(pmpnbasicerror,RUN_ERROR)
 TABLE(pmpnlinenumber,ERROR_LINE)
 WAIT UNTIL TABLE(pmpncancel)=1
 TABLE(pctlcommand,1)
 WAIT UNTIL 1=2
 GOTO mainloop
 WAIT UNTIL 1=2
 STOP


