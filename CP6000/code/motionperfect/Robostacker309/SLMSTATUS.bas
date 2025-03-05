loopwdog:
 PRINT "****************************************"
 PRINT "* STATUS                               *"
 PRINT "****************************************"
 dl_axis=2
 GOSUB print_axis_status
 dl_axis=4
 GOSUB print_axis_status
 dl_axis=5
 GOSUB print_axis_status
 dl_axis=1
 GOSUB print_axis_status
 dl_axis=3
 GOSUB print_axis_status
 TICKS=0
 WAIT UNTIL TICKS < -1000
 GOTO loopwdog

print_axis_status:
'DLINK(6,dl_axis,12,32768)
'DLINK(7,dl_axis,244)
VR(800)=DLINK(5,dl_axis,67)
VR(800)=DLINK(8,dl_axis,32768)
'DLINK(6,dl_axis,12,53248)
'DLINK(7,dl_axis,244)
VR(801)=DLINK(5,dl_axis,67)
VR(801)=DLINK(8,dl_axis,53248)
'DLINK(7,dl_axis,244)
VR(802)=DLINK(5,dl_axis,67)
VR(802)=DLINK(8,dl_axis,57344)
 PRINT "****************************************"
PRINT "STATUS axis=";dl_axis;" ";VR(800)[5,0]
PRINT "FAULT  axis=";dl_axis;" ";VR(801)[5,0]
PRINT "LINK ERROR COUNTER axis=";dl_axis;" ";VR(802)[5,0]
IF READ_BIT(0,800) THEN
  PRINT "STATUS axis=";dl_axis;" Axis enabled"
ENDIF
IF READ_BIT(1,800) THEN
  PRINT "STATUS axis=";dl_axis;" Axis healthy AND can be enabled via comms"
ENDIF
IF READ_BIT(2,800) THEN
  PRINT "STATUS axis=";dl_axis;" Axis I2t"
ENDIF
IF READ_BIT(3,800) THEN
  PRINT "STATUS axis=";dl_axis;" High current selected(link fitted pin 6/7)"
ENDIF
IF READ_BIT(4,800) THEN
  PRINT "STATUS axis=";dl_axis;" Drive in test mode"
ENDIF
IF READ_BIT(5,800) THEN
  PRINT "STATUS axis=";dl_axis;" Fan fail"
ENDIF
IF READ_BIT(6,800) THEN
  PRINT "STATUS axis=";dl_axis;" Braking I2t warning"
ENDIF
IF READ_BIT(7,800) THEN
  PRINT "STATUS axis=";dl_axis;" Braking I2t trip"
ENDIF
IF READ_BIT(12,800) THEN
  PRINT "STATUS axis=";dl_axis;" Encoder error warning"
ENDIF
IF READ_BIT(13,800) THEN
  PRINT "STATUS axis=";dl_axis;" Motor I2t warning"
ENDIF

IF READ_BIT(0,801) THEN
  PRINT "FAULT STATUS axis=";dl_axis;" Heatsink over-temp, thermistor - Drive"
ENDIF
IF READ_BIT(1,801) THEN
  PRINT "FAULT STATUS axis=";dl_axis;" Faulty/disconnected, thermistor - Drive"
ENDIF
IF READ_BIT(2,801) THEN
  PRINT "FAULT STATUS axis=";dl_axis;" Axis Link error"
ENDIF
IF READ_BIT(3,801) THEN
  PRINT "FAULT STATUS axis=";dl_axis;" Under-voltage trip - Drive"
ENDIF
IF READ_BIT(4,801) THEN
  PRINT "FAULT STATUS axis=";dl_axis;" Supply Phase fault/missing - Drive"
ENDIF
IF READ_BIT(5,801) THEN
  PRINT "FAULT STATUS axis=";dl_axis;" Over voltage trip - Drive"
ENDIF
IF READ_BIT(6,801) THEN
  PRINT "FAULT STATUS axis=";dl_axis;" vce trip on power dump IGBT - Drive"
ENDIF
IF READ_BIT(7,801) THEN
  PRINT "FAULT STATUS axis=";dl_axis;" Control volts fault(+5V,+-15V) - Drive"
ENDIF
IF READ_BIT(8,801) THEN
  PRINT "FAULT STATUS axis=";dl_axis;" Axis(not motor) I2t warning - Axis"
ENDIF
IF READ_BIT(9,801) THEN
  PRINT "FAULT STATUS axis=";dl_axis;" Axis(not motor) I2t trip - Drive"
ENDIF
IF READ_BIT(10,801) THEN
  PRINT "FAULT STATUS axis=";dl_axis;" Axis over current - Drive"
ENDIF
IF READ_BIT(11,801) THEN
  PRINT "FAULT STATUS axis=";dl_axis;" Axis Offset correction limit - Drive"
ENDIF
RETURN

