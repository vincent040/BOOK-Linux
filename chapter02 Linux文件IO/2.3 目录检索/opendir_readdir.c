////////////////////////////////////////////////////
//
//  Copyright(C), 广州粤嵌通信科技股份有限公司
//
//  作者: Vincent Lin (林世霖)  微信公众号：秘籍酷
//
//  技术微店: http://weidian.com/?userid=260920190
//  技术交流: 260492823（QQ群）
//
//  文件: GPLE2.0/ch02/2.3/opendir_readdir.c
//  描述: 演示了目录操作基本API的使用细节
//
////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <strings.h>
#include <errno.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <dirent.h>

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		printf("Usage: %s <dir>\n", argv[0]);
		exit(1);
	}

	DIR *dp = opendir(argv[1]);

	struct dirent *ep = NULL;
	while(1)
	{
		ep = readdir(dp);
		if(ep == NULL)
			break;

		printf("%s\n", ep->d_name);
	}
	

	return 0;
}
