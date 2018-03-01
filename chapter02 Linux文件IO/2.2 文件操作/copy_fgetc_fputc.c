////////////////////////////////////////////////////
//
//  Copyright(C), 广州粤嵌通信科技股份有限公司
//
//  作者: Vincent Lin (林世霖)  微信公众号：秘籍酷
//
//  技术微店: http://weidian.com/?userid=260920190
//  技术交流: 260492823（QQ群）
//
//  文件: GPLE2.0/ch02/2.2/copy_fgetc_fputc.c
//  描述: 使用文件读写接口fgetc()和fputc()
//        实现对文件的复制操作。
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

int main(int argc, char **argv)
{
	if(argc != 3)
	{
		printf("Usage: %s <src> <dst>\n", argv[0]);
		exit(1);
	}


	FILE *fp_src = fopen(argv[1], "r");
	FILE *fp_dst = fopen(argv[2], "w");


	if(fp_src == NULL || fp_dst == NULL)
	{
		perror("fopen()");
		exit(1);
	}

	int c, total = 0;
	while(1)
	{
		c = fgetc(fp_src);

		if(c == EOF && feof(fp_src))
		{
			printf("copy completed, "
				"%d bytes have been copied.\n", total);
			break;
		}
		else if(ferror(fp_src))
		{
			perror("fgetc()");
			break;
		}

		fputc(c, fp_dst);
		total++;
	}


	fclose(fp_src);
	fclose(fp_dst);

	return 0;
}
