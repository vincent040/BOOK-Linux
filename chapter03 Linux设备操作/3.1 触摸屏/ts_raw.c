////////////////////////////////////////////////////
//
//  Copyright(C), 广州粤嵌通信科技股份有限公司
//
//  作者: Vincent Lin (林世霖)  微信公众号：秘籍酷
//
//  技术微店: http://weidian.com/?userid=260920190
//  技术交流: 260492823（QQ群）
//
//  文件: GPLE2.0/ch03/3.1/ts_raw.c
//  描述: 演示了使用函数read()直接读取触摸屏数据的例子
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
#include <linux/input.h>

int main(int argc, char **argv)
{
	// 打开触摸屏设备
	int ts = open("/dev/input/event0", O_RDONLY);

	// 定义输入信息结构体
	struct input_event buf;
	bzero(&buf, sizeof(buf));

	while(1)
	{
		// 读取触摸屏数据
		read(ts, &buf, sizeof(buf));

		// 1，读取到触摸屏被按下或被松开事件
		if(buf.type == EV_KEY && buf.code == BTN_TOUCH)
		{
			if(buf.value > 0) // 按下了触摸屏
			{
				printf("开始.\n");
			}

			if(buf.value == 0) // 松开了触摸屏
			{
				printf("结束.\n");
				break;
			}
		}

		// 2，读取到触摸屏X轴坐标值事件
		if(buf.type == EV_ABS && buf.code == ABS_X)
		{
			printf("x: %d\n", buf.value);
		}

		// 3，读取到触摸屏Y轴坐标值事件
		if(buf.type == EV_ABS && buf.code == ABS_Y)
		{
			printf("y: %d\n", buf.value);
		}
	}

	return 0;
}
