#!/bin/bash

# 定义一个函数check_user( )，注意括号里面没有空格
check_user() 
{
	# 若函数的第一个参数$1为“quit”，则立即结束脚本
	if [ $1 = "quit" ]	
	then
		exit
	fi
	count=`who | grep $1 | wc -l`
	if [ $count -eq 0 ]
	then
		# 用户未登录
		return 0	
	else
		# 用户已登录
		return 1
	fi
}

while true
do
	echo -n "请输入一个用户名:"
	read USER
	check_user $USER # 调用check_user，并传递参数$USER

	# 判断check_user的返回值$?是否为1
	if [ $? -eq 1 ]	 
	then
		echo -e "用户[$USER]已登录\n"
	else
		echo -e "用户[$USER]未登录\n"
	fi
done
