////////////////////////////////////////////////////
//
//  Copyright(C), 广州粤嵌通信科技股份有限公司
//
//  作者: Vincent Lin (林世霖)  微信公众号：秘籍酷
//
//  技术微店: http://weidian.com/?userid=260920190
//  技术交流: 260492823（QQ群）
//
//  文件: GPLE2.0/ch02/2.2/open_close.c
//  描述: 演示了函数open()和close()的基本用法
//
////////////////////////////////////////////////////

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int main(void)
{
	int fd = open("a.txt", O_CREAT|O_TRUNC|O_WRONLY, 0644);
	printf("fd: %d\n", fd);

	close(fd);
	return 0;
}
