IF workcellid=302 THEN
testloop302:
  TICKS=500
  WAIT UNTIL IN(VR(603))=OFF OR TICKS<0
  IF TICKS < 0 AND IN(VR(626))=ON THEN
    beltfull=1
    OP(VR(624),OFF)
  ELSE
    beltfull=0
  ENDIF
  GOTO testloop302
ENDIF

IF workcellid =303 THEN
testloop303:
  TICKS=500
  WAIT UNTIL IN(VR(628))=OFF OR TICKS<0
  IF TICKS < 0 THEN
    conveyorb=1
'    OP(VR(621),ON) 'send fotocell simulation to PLC
  ELSE
    conveyorb=0
  ENDIF
  GOTO testloop303
ENDIF
STOP

