#!/bin/bash

check_user() # 定义一个函数check_user( )，注意括号里面没有空格
{
	if [ $1 = "quit" ]	# 若函数的第一个参数$1为“quit”，则立即结束脚本
	then
		exit
	fi
	count=`who | grep $1 | wc -l`
	if [ $count -eq 0 ]
	then
		return 0	# 判断用户$1是否在线，是则返回1，否则返回0
	else
		return 1
	fi
}

while true
do
	echo -n "input a user name:"
	read USER
	check_user $USER # 调用check_user，并传递参数$USER
	if [ $? -eq 1 ]	 # 判断check_user的返回值$?是否为1
	then
		echo "[$USER] online."
	else
		echo "[$USER] offline."
	fi
done
