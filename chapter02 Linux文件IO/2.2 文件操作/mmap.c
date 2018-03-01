////////////////////////////////////////////////////
//
//  Copyright(C), 广州粤嵌通信科技股份有限公司
//
//  作者: Vincent Lin (林世霖)  微信公众号：秘籍酷
//
//  技术微店: http://weidian.com/?userid=260920190
//  技术交流: 260492823（QQ群）
//
//  文件: GPLE2.0/ch02/2.2/mmap.c
//  描述: 演示了函数mmap的基本用法
//
////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		printf("Usage: %s <filename>\n", argv[0]);
		exit(1);
	}


	int fd = open(argv[1], O_RDONLY);


	char *p = mmap(NULL, 1024, PROT_READ,
				MAP_PRIVATE, fd, 0);


	printf("%s\n", p);
	
	
	return 0;
}
