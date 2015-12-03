#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
 * 定义函数：har * fgets(char * s, int size, FILE * stream);
 * 函数说明：fgets()用来从参数stream 所指的文件内读入字符并存到参数s
 * 所指的内存空间, 直到出现换行字符、读到文件尾或是已读了size-1 个字符为止
 * , 最后会加上NULL 作为字符串结束.
 *puts(str)  输出字符串
 *putchar(c) 输出字符
 */
main()
{
	char inputs[1000];
	char buffer[100];
	while(1)
	{
		puts("Enter some text : ");
		fgets(buffer,100,stdin);
		strcat(inputs,buffer);
		if(strncmp(buffer,"end",3)==0)
		{
			break;
		}
	}
	printf("Your input is: \n%s",inputs);
}
