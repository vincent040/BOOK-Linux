////////////////////////////////////////////////////
//
//  Copyright(C), 广州粤嵌通信科技股份有限公司
//
//  作者: Vincent Lin (林世霖)  微信公众号：秘籍酷
//
//  技术微店: http://weidian.com/?userid=260920190
//  技术交流: 260492823（QQ群）
//
//  文件: GPLE2.0/ch02/2.4/color
//  描述: 模仿涂色监测程序功能示例
//
////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>

// 监测涂色是否均匀
void detect(void *arg)
{
	char **p = (char **)arg;

	int side   = atoi(p[0]);
	int bottom = atoi(p[1]);

	printf("边框宽度是%d\n", side);
	printf("底部大小是%d\n", bottom);
	printf("监测涂色均匀，合格！\n");
}
