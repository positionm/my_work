#include "stdlib.h"
#include "string.h"
#include "stdio.h"
#include "stdarg.h"

typedef int INT8U;
void log_out_lilei(const char *str_in, ...)
{
    	int len = strlen(str_in);
	char * str0="echo `data`";
	char * str1=">>lilei.log";
	int len0 = strlen(str0);
	int len1 = strlen(str1);
	
	va_list args;
	
	
   	char * buffer0 = (char*) malloc(len+len0+len1+1);
	char * buffer1 = (char*) malloc(len+len0+len1+100);
	char * str = buffer0;
	char * str_z = buffer1;
	va_start(args,str_in);
	memset(str,0,len+len0+len1+1);
	memset(str_z,0,len+len0+len1+100);

	memcpy(str,str0,len0);
   	memcpy(str+len0,str_in,len);
	memcpy(str+len0+len,str1,len1+1);
	
   	vsnprintf(str_z,len+len0+len1+100,str,args);
    	system(str_z);
	va_end(args);
    	free(str_z);
	free(str);
}
int main()
{
	int a=2;
	log_out_lilei("%d",a);
	return 0;
}
