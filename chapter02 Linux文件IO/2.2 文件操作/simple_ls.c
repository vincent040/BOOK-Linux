////////////////////////////////////////////////////
//
//  Copyright(C), 广州粤嵌通信科技股份有限公司
//
//  作者: Vincent Lin (林世霖)  微信公众号：秘籍酷
//
//  技术微店: http://weidian.com/?userid=260920190
//  技术交流: 260492823（QQ群）
//
//  文件: GPLE2.0/ch02/2.2/simple_ls.c
//  描述: 使用函数stat()实现简单ls功能，显示文件的类
//        型、权限和名字
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

void print_type(struct stat *pinfo)
{

	switch(pinfo->st_mode & S_IFMT)
	{
	case S_IFREG: printf("-"); break;
	case S_IFDIR: printf("d"); break;
	case S_IFLNK: printf("l"); break;
	case S_IFCHR: printf("c"); break;
	case S_IFBLK: printf("b"); break;
	case S_IFIFO: printf("p"); break;
	case S_IFSOCK: printf("s"); break;
	}
}

void print_perm(struct stat *pinfo)
{
	char rwx[] = {'r', 'w', 'x'};

	int i;
	for(i=0; i<9; i++)
	{

		printf("%c", pinfo->st_mode & (0400>>i) ?
			     rwx[i%3] : '-');
	}
}

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		printf("Usage: %s <path>\n", argv[0]);
		exit(1);
	}


	struct stat info;
	stat(argv[1], &info);


	if(S_ISDIR(info.st_mode))
	{
		DIR *dp = opendir(argv[1]);
		struct dirent *ep;
		chdir(argv[1]);


		while(1)
		{
			ep = readdir(dp);
			if(ep == NULL)
				break;

			stat(ep->d_name, &info);
			print_type(&info);
			print_perm(&info);

			printf("\t%s\n", ep->d_name);
		}
	}

	else
	{
			print_type(&info);
			print_perm(&info);

			printf("\t%s\n", argv[1]);
	}

	return 0;
}
