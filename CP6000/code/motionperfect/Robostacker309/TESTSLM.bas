
dl_axis=1
PRINT "*************************************"
PRINT "* AXIS  A                           *"
PRINT "*************************************"
GOSUB dd
dl_axis=2
PRINT "*************************************"
PRINT "* AXIS  B                           *"
PRINT "*************************************"
GOSUB dd
dl_axis=3
PRINT "*************************************"
PRINT "* AXIS  C                           *"
PRINT "*************************************"
GOSUB dd
dl_axis=4
PRINT "*************************************"
PRINT "* AXIS  D                           *"
PRINT "*************************************"
GOSUB dd
dl_axis=5
PRINT "*************************************"
PRINT "* AXIS  E                           *"
PRINT "*************************************"
GOSUB dd

STOP
dd:
dl_slot=VR(810+dl_axis)
dl_asic=VR(820+dl_axis)
 IF ATYPE AXIS(dl_axis)<>11 THEN
  IF DLINK(2,dl_slot,dl_asic)=0 THEN
   PRINT "SLM slot=";dl_slot;" asic=";dl_asic;" NOT detected !!!!!"
  ELSE
   PRINT "SLM slot=";dl_slot;" asic=";dl_asic;" detected !!!!!"
  ENDIF
  WA(5)
  ' check that the drive is detected
  IF DLINK(3,dl_slot,dl_asic)=0 THEN
   PRINT "DRIVE slot=";dl_slot;" asic=";dl_asic;" NOT detected !!!!!"
  ELSE
   PRINT "DRIVE slot=";dl_slot;" asic=";dl_asic;" detected !!!!!"
  ENDIF
  ' initialise the axis
  DLINK(4,dl_slot,dl_asic,dl_axis)
  PRINT "axis ";dl_axis;" assigned to ";dl_slot;",";dl_asic
 ENDIF
 PRINT "axis ";dl_axis;" assigned"
 WA(10)
 ' reset the amplifier in case of trip
 IF MOTION_ERROR THEN DATUM(0)
 sum=0
 FOR check=1 TO 10
  DLINK(7,dl_axis,252)
  sum=sum+DLINK(7,dl_axis,251)
 NEXT check
 IF sum<>-10 THEN
   PRINT "unable to reset drive axis ";dl_axis;" ";dl_slot;",";dl_asic
 ELSE
   PRINT "drive axis ";dl_axis;" ";dl_slot;",";dl_asic;" is OK"
 ENDIF
 RETURN
STOP

