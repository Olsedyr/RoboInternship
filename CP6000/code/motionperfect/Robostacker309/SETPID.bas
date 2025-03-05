'set kp,ki,kd,dl_axis,filter
dl_axis=2
kp=
ki=
kd=
filter=

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

