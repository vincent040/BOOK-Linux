////////////////////////////////////////////////////
//
//  Copyright(C), 广州粤嵌通信科技股份有限公司
//
//  作者: Vincent Lin (林世霖)  微信公众号：秘籍酷
//
//  技术微店: http://weidian.com/?userid=260920190
//  技术交流: 260492823（QQ群）
//
//  文件: GPLE2.0/ch02/2.4/facade.c
//  描述: 模仿外观监测程序功能示例
//
////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

// 外观是否破损
void detect(void *arg)
{
	char **p = (char **)arg;

	int length = atoi(p[0]);
	int width  = atoi(p[1]);
	int height = atoi(p[2]);

	printf("长度：%d\n", length);
	printf("宽度：%d\n", width);
	printf("高度：%d\n", height);

	printf("监测外观无破损，合格！\n");
}
