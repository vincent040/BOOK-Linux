////////////////////////////////////////////////////
//
//  Copyright(C), 广州粤嵌通信科技股份有限公司
//
//  作者: Vincent Lin (林世霖)  微信公众号：秘籍酷
//
//  技术微店: http://weidian.com/?userid=260920190
//  技术交流: 260492823（QQ群）
//
//  文件: GPLE2.0/ch02/2.4/main.c
//  描述: 动态库参数化主程序示例
//
////////////////////////////////////////////////////

#include <stdio.h>
#include <dlfcn.h>

int main(int argc, char **argv)
{
	void *handle = dlopen(argv[1], RTLD_NOW);
	void (*detect)(void*) = dlsym(handle, "detect");

	char *arg[argc-2];

	for(int i=0; i<argc-2; i++)
	{
		arg[i] = argv[i+2];
	}

	detect((void *)arg);

	return 0;
}
