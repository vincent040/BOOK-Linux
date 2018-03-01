////////////////////////////////////////////////////
//
//  Copyright(C), 广州粤嵌通信科技股份有限公司
//
//  作者: Vincent Lin (林世霖)  微信公众号：秘籍酷
//
//  技术微店: http://weidian.com/?userid=260920190
//  技术交流: 260492823（QQ群）
//
//  文件: GPLE2.0/ch02/2.2/dev_no.c
//  描述: 利用函数stat()获取文件信息，并判断文件是否是设备节
//        点文件，如果是则打印其设备号。
//
////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		printf("Usage: %s <filename>\n", argv[0]);
		exit(1);
	}


	struct stat info;
	stat(argv[1], &info);


	if(S_ISCHR(info.st_mode) ||
	   S_ISBLK(info.st_mode))
	{
		printf("regular file: %d, %d\n",
			major(info.st_rdev),
			minor(info.st_rdev));
	}


	else
		printf("device: %d, %d\n",
			major(info.st_dev),
			minor(info.st_dev));

	printf("%d\n", info.st_blksize);

	return 0;
}
