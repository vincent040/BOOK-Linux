///////////////////////////////////////////////////
//
//  Copyright(C), 广州粤嵌通信科技股份有限公司
//
//  作者: Vincent Lin (林世霖)  微信公众号：秘籍酷
//
//  技术微店: http://weidian.com/?userid=260920190
//  技术交流: 260492823（QQ群）
//
//  文件: GPLE2.0/ch02/2.2/fopen_fclose.c
//  描述: 演示了fopen()和fclose()的基本用法
//
////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
	FILE *fp = fopen("a.txt", "r+");


	if(fp == NULL)
	{
		perror("fopen()");
		exit(1);
	}

	
	if(fclose(fp) == EOF)
	{
		perror("fclose()");
		exit(1);
	}

	return 0;
}
