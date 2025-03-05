#/bin/sh
if [ $1 ]; then
		echo -en "ALLVALS $1 ?\nEND\n"| nc 127.0.0.1 1299
else
		echo "Usage: $0 <STM-Name>"
fi
