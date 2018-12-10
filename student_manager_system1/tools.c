#include "tools.h"

//限制输入,上限删除
char* get_str_del(char* str,size_t size,int mode)
{
	if(NULL == str) return str;
	
	clear_stdin();
	for(int i=0;i<size;i++)
	{
		str[i] =getch();
		if('\n' == str[i])
		{
			if(0 == i)
			{
				i--;
				continue;
			}
			printf("\n");
			break;
		}
		else if(127 == str[i])
		{
			if(0 == i)
			{
				i--;
				continue;
			}
			printf("\b \b");
			i-=2;
			continue;
		}
		else
		{
			if(1 == mode)
			{
				printf("%c",str[i]);
			}
			else if(2 == mode)
			{
				printf("*");
			}
		}
		if(i == size-1)
		{
			printf("\b \b");
			i--;
		}
	}
	if(size-1 == strlen(str))
	{
		if('\n' == str[size-2])
				str[size-2] = '\0';
		else
			clear_stdin();
	}
	else
		str[strlen(str)-1] = '\0';
}

//指定位置字符串输入
char* in_str(char* id,int mode,int idlen,int x,int y)
{
	MOVETO(x,y);
	get_str_del(id,idlen,mode);
	return id;
}

//任意键退出
void rand_key_exit()
{
	printf("按任意键退出！\n");
	getch();
}

//判断ID长度
bool islenequal(char* id,int idlen)
{
	if(idlen == strlen(id))
	{
		return true;
	}
	return false;
}

//判断姓名长度
bool isnamelenequal(char* name)
{
	if(strlen(name) > 0)
	{
		return true;
	}
	return false;
}
