////////////////////////////////////////////////////
//
//  Copyright(C), 广州粤嵌通信科技股份有限公司
//
//  作者: Vincent Lin (林世霖)  微信公众号：秘籍酷
//
//  技术微店: http://weidian.com/?userid=260920190
//  技术交流: 260492823（QQ群）
//
//  文件: GPLE2.0/ch02/2.2/strong_ls/main.c
//  描述: 使用stat()来实现命令 ls -l 的功能：
//        1，显示文件的类型、权限、所有者、名字等基本信息
//        2，不同类型文件用不同的颜色
//        3，设备文件显示设备号，普通文件显示大小
//
////////////////////////////////////////////////////

#include "myls.h"

int main(int argc, char **argv)
{
	umask(0);
	struct stat s;
	char *path;

	if(argc == 1)
	{
		path = ".";
		Stat(path, &s);
	}
	else if(argc == 2)
	{
		path = argv[1];
		Stat(path, &s);
	}
	else
		err_quit("too many arguments.\n");


	if((s.st_mode & S_IFMT) == S_IFDIR)
	{
		DIR *dp;
		struct dirent *ep;

		dp = Opendir(path);

		chdir(path);
		while((ep=readdir(dp)) != NULL)
		{
			if(ep->d_name[0] == '.')
				continue;

			lstat(ep->d_name, &s);

			printf("%s%3d %7s %7s%8s %.16s ",
				mode(&s), hln(&s), user(&s), group(&s),
				size_dev(&s), mtime(&s));

			print_color_name(&s, ep->d_name);
		}

		Closedir(dp);
	}

	else
	{
		printf("%s%3d %7s %7s%8s %.16s ", mode(&s), hln(&s),
			user(&s), group(&s), size_dev(&s), mtime(&s));

		print_color_name(&s, path);
	}
		
	exit(0);
}
