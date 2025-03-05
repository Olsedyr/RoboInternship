#!/bin/sh
# Script to see last X dhcp assigned addresses by 192.168.0.100
# 
# "lastdhcpconnect.sh" gives last address assigned
# "lastdhcpconnect.sh X" gives last X addresses assigned
#
if [ -z "$1" ] ; then
    ssh root@192.168.0.100 grep DHCPACK /var/log/messages|tail -1
else
    if [ "$1" == "--help" ] ; then
        echo ""
        echo "Usage:"
        echo ""
        echo "sh lastdhcpconnect.sh [X]"
        echo ""
        echo "    Shows last X dhcp assigned addresses by 192.168.0.100"
        echo ""
    else
        ssh root@192.168.0.100 grep DHCPACK /var/log/messages|tail -"$1"
    fi
fi
