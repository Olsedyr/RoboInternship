#!/bin/sh
# Script for making phone-home connection to MPN controlcenter :)
# Date: 14.12.2005
# Author: Mads Lundstroem <mil@mpnrobotics.com>


# global settings (for init script!)

GW=192.168.0.1
NAMESERVER=194.239.134.83
NAMESERVER=193.162.153.164

# local settings


#wait 30 seconds at bootup
sleep 30

KEY="/.ssh/id_rsa.db"

PORT=1300
cd /mnt/
fn=`cat mntdatabase.txt|grep -v ini`/system/`cat mntdatabase.txt|grep ini`
if [ -f "$fn" ] ; then
    PORT=1`cat $fn|awk 'BEGIN {FS = "="}/plant/{print $2}'`
fi


MPNHOST="mpnrobotics.dyndns.org"

CONNECTPERIOD=3600

while `true`; do
    echo "Using host $MPNHOST, port $PORT. Connection-period is $CONNECTPERIOD s..."
    dbclient -i $KEY -p1022 -R $PORT:localhost:22 root@$MPNHOST sleep $CONNECTPERIOD
    sleep 1
done
