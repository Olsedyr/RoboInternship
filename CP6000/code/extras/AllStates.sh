#/bin/sh
echo -en "STATE WorkCell ?\nALLSTATES\nEND\n"| nc 127.0.0.1 1299
