###########################
#
# 计算指定目录下的文件总数
#
###########################
#!/bin/sh

if [ $# -ne 1 ]
then
	echo "你需要指定一个目录"
	exit
fi

if [ ! -e $1 ] || [ ! -d $1 ]
then
	echo "你指定的目录不存在"
	exit
else
	files=`ls $1`
fi

count=0
for f in $files
do
	count=$(($count+1))
done

echo "文件总数：$count"
