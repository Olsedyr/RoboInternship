#!/bin/bash
make clean &> /dev/null
((make | tee buildout.log) 3>&1 1>&2 2>&3 | tee builderr.log) &> buildall.log
