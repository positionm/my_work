#include "stdio.h"
#include "stdarg.h"
#include "unistd.h"
#include "fcntl.h"
#include "string.h"
#include "stdlib.h"
#include "sys/types.h"
#include "time.h"

#define FILE_NAME "lilei.log"
#define DEFARG(name, defval) ((#name[0])? (name+0) : (defval))
#define log_out_lilei(length,str_in1,str_in,...) log_out(DEFARG(length,0),DEFARG(str_in1,""),str_in,__VA_ARGS__)

void log_out(int length, char *str_in,...)
{
	int len=0;
	if(length == 0)
	{
		len = strlen(str_in)+201;
	}
	else
	{
		len = length+1;//"\0"占一个字节
	}
	char * buf = (char*) malloc(len);//动态生成缓存区记得要释放
	memset(buf,0,len);
	va_list args;//动态参数列表变量
	va_start(args,str_in);
	vsnprintf(buf,len,str_in,args);
	va_end(args);
	
	time_t ptime;
	time(&ptime);
	
	int fd = open(FILE_NAME,O_RDWR|O_CREAT,S_IRUSR|S_IWUSR|S_IXUSR);
	if (fd != -1)
	{
		lseek(fd,0,SEEK_END);//从文件末尾开始写
		write(fd,ctime(&ptime),strlen(ctime(&ptime))-1);
		write(fd," ",1);
		if(length == 0)
		write(fd,buf,strlen(buf));
		else
		{
			int num = 0;
			while(num<length)
			{
				write(fd,buf+num,1);
				write(fd," ",1);
				num++;
			}
		}
		write(fd,"\r\n",2);
		close(fd);
		free(buf);
	}
	else
	{
		free(buf);
	}
	
}

int main()
{
//    FILE *fd;
	int b = 2;
	char a[10]={'0','1','2','3'};
    int fd = open("lilei2.log",O_RDWR|O_CREAT,S_IRUSR|S_IWUSR|S_IXUSR);
    char *msg = "lilei";
    write(fd,msg,strlen(msg));
    close(fd);
	log_out(0,"chengz");
	log_out(0,"jifoojo");
	log_out(0,"a = %04d b= %04d",b,b);
	log_out(3,a);
    return 0;
}
