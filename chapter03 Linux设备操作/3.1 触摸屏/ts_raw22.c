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
				printf("开始读取手指坐标...\n");
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
