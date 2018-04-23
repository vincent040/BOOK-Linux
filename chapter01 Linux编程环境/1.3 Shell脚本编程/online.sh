#!/bin/bash

check_user() # 定义一个函数check_user()，注意括号里面没有空格
{
	user=`who | awk '{print $1}' | uniq`

}


while [ 1 ]
do
	echo -n "input a user name:"
	read name

	if [ $name = "quit" ]
	then
		break
	fi

	n=0
	for u in $user
	do
		
		if [ $name = $u ]
		then
			echo "$name is online"
			n=1
			break
		fi
	done

	if [ $n -eq 0 ]
	then
		echo "$name is NOT online"
	fi
done
