'resetconveyora:
'    OP(VR(621),OFF) 'start conveyorA
'    WAIT UNTIL IN(VR(626))=OFF
'loop0:
 '   ticks=1000
'    wait until in(vr(626))=ON or ticks<0 or conveyora=2
'    if conveyora=2 then goto resetconveyora
'    if ticks>0 then goto loop1
    OP(VR(620),OFF) 'start conveyorA
    conveyora=0
stopconveyora:
    WAIT UNTIL conveyora=0
    OP(VR(620),OFF) 'start conveyorA
    'loop indtil 627 off i mere end 100ms
loop1:
    TICKS=100
    WAIT UNTIL IN(VR(627))=ON OR TICKS<0
    IF TICKS>0 THEN GOTO loop1
    'loop indtil 627 on i mere end 100ms
loop2:
    TICKS=100
    WAIT UNTIL IN(VR(627))=OFF OR firstbox=1 OR TICKS<0
    IF TICKS>0 AND firstbox=0 THEN GOTO loop2
    IF firstbox=1 THEN firstbox=0
    OP(VR(620),ON) 'stop conveyorA
    conveyora=1
    GOTO stopconveyora
STOP

