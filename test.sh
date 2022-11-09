#!/bin/bash
echo "Number of charsets (1 set = 10 chars):"
read charsets
echo "Server PID:"
read -p "" s_pid
echo ""
charnum=$(expr $charsets \* 10)
while [[ charsets -gt 0 ]]
    do
    message_mid="${message_mid}----------"
    charsets=$(expr $charsets - 1)
    done
message="|${message_mid}|"
while :
    do
t1=$(date +%s)
./client $s_pid $message
t2=$(date +%s)
t_sec=$(expr $t2 - $t1)
c_sec=$(expr $charnum / $t_sec)
echo ""
echo "______________________"
echo "  time in sec: `echo $t_sec`"
echo "chars per sec: `echo $c_sec`"
echo ""
echo "go again?"
echo "______________________"
read
done