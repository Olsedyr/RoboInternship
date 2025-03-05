'700 1472
'701 1420
'702 42
'703 11
'704 0
'705 4
'706 2524
'707 12971 > 5 sec
'708 13945
'709 331
'710 -2491
'711 49780
'732 63903

TICKS=0
first=1
timerticks=60000
oldtime=TICKS
loop:
  IF ztimerticks=1 THEN
    timerticks=60000
    ztimerticks=0
    first=1
  ENDIF
  IF timerticks<0 THEN
    IF first=1 THEN
      OP(VR(615),OFF) 'STOP VACUUM MOTOR
      OP(VR(616),OFF) 'SUG
      OP(VR(619),OFF) 'BLOW INJECTOR
      OP(VR(620),ON)
      OP(VR(624),OFF) 'STOP BELT
      first=0
    ENDIF
  ELSE
    first=1
  ENDIF
  newtime=TICKS
  dif=newtime-oldtime
  IF dif > 0 THEN dif=0
  timerticks=timerticks+dif
  IF TABLE(pmpnrunning)=2 THEN
    timerunning=timerunning-dif*0.001
  ENDIF
  totaltime=totaltime-dif*0.001
  oldtime=newtime
  GOTO loop
  STOP

smallsetinactive:
  RETURN

'

