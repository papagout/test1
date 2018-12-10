#include "manager.h"

int count_teacher;

bool is_right_manager (char* str1,char* str2)
{
	for(int i=0; i < manager_num ;i++)
	{
		if( !strcmp( str1, mana[i].id) && !mana[i].del )
		{	
			if( !strcmp( str2,mana[i].password ) )
			{
				return true;	
			}
			return false;
		}
	}
	return false;
}

void manager_show_time(char* str1)    
{
	for(int i=0; i < manager_num ;i++)
	{
		if( !strcmp( str1,mana[i].id ) )
		{	
			mana[i].lock ++ ;
			if( mana[i].lock <=3)
			{
				printf("%d次错误密码！！ \n", mana[i].lock ) ;
			}
			sleep(1);
			return ;	
		}
	}
	printf("账号输入有错误，请重新输入\n");
	sleep(1);
	return ;
}

bool is_time_manager_right(char* str1) 
{
	for(int i=0; i < manager_num ;i++)
	{
		if(!strcmp(str1,mana[i].id))
		{	
			if( mana[i].lock  >= 3)
				return true;
			else
			{
				return false;
			}
		}
	}
	return false;
}

//判断ID是否相等
bool isteaidequal(char* id,int n)
{
	for(int i = 0;i < n;i++)
	{
		if(0 == strcmp(teacher[i].id,id))
		{
			return true;
		}
	}
	return false;
}


//ID输入及判定
bool in_teaid(char* id,int idlen,int n,bool isid)
{
	printf("请输入ID：");
	get_str_del(id,idlen,1);
	while(!(6 == strlen(id) && isid?!isteaidequal(id,n):isteaidequal(id,n)))
	{
		printf("ID错误！回车继续输入！任意键退出！\n");
		if('\n' == getch())
		{
			id[5] = '\0';
			CLEAR_UP_LINE(1);
			CLEAR_UP_LINE(1);
			printf("请输入ID：");
			get_str_del(id,idlen,1);
		}
		else
		{
			return false;
		}
	}
	return true;	
}

//判断姓名是否相等
bool isteanameequal(char* name,int n)
{
	for(int i = 0;i < n;i++)
	{
		if(0 == strcmp(teacher[i].name,name))
		{
			return true;
		}
	}
	return false;
}

/*//姓名输入及判定
void in_teaname(char* name,int n,bool isname)
{
	printf("请输入姓名：");
	get_str_del(name,20,1);
	if(isname)
	{
		while(!isnamelenequal(name))
		{
			printf("请输入姓名：");
			get_str_del(name,20,1);
		}
	}
	else
	{
		while(!isnamelenequal(name)||!isteanameequal(name,n))
		{
			printf("请输入姓名：");
			get_str_del(name,20,1);
		}
	}
}*/

//判断教师是否为空
bool isnotea()
{
	if(0 == strcmp(teacher[0].id,"\0"))
	{
		return true;
	}
	return false;
}

//
void show_tea()
{
	printf("\n----在职教师----\n");
	for(int i = 0;i < count_teacher;i++)
	{
		if(0 != strcmp(teacher[i].id,"\0") && !teacher[i].del)
		{
			printf("ID:%s 姓名:%s\n",teacher[i].id,teacher[i].name);
		}
	}
}

//获取已有教师数量
int get_counttea()
{
	for(int i = 0;i < SUMTEA;i++)
	{
		if(!islenequal(teacher[i].id, 6))
		{
			return i;
		}
	}
}

//选择管理员功能
void chose_manager(char* manaid)
{
	if(NULL == manaid)return;
	count_teacher = get_counttea();
	first_change_manapass(manaid);
	while(1)
	{
		show_chose_manager(manaid);
		switch(getch())
		{
			case one	: add_teacher();			break;
			case two	: del_teacher();			break;
			case three	: change_teacher();			break;
			case four   : reset_teacher();			break;
			case five	: ulock_teacher();			break;
			case six    : find_teacher();			break;
			case seven	: on_job();					break;
			case eight	: leave_job();			    break;
			case nine	: change_manapass(manaid);	break;
			case zero	: return;
			default:break;
		}
	}
}

//添加教师
void add_teacher()
{
		char id[LENTID] = {},name[20] = {},year[5] = {};
		char sex = 0;
		if(count_teacher < SUMTEA)
		{
			//输入ID
			if(!in_teaid(id,LENTID,count_teacher,true))return;
			strcpy(teacher[count_teacher].id,id);
			strcpy(teacher[count_teacher].password,DEFAULTTPASS);
			//输入姓名
			printf("请输入姓名：");
			get_str_del(name,20,1);
			strcpy(teacher[count_teacher].name,name);
			//输入性别
			printf("\n");
			do
			{
				CLEAR_UP_LINE(1);
				printf("请输入%s性别(1.男2.女)：",TEA);
				clear_stdin();
				scanf("%c",&sex);
				teacher[count_teacher].sex = sex;
			}while(!('1'==sex || '2'==sex));
			//年龄
			printf("\n");
			do
			{
				CLEAR_UP_LINE(1);
				printf("请输入%s出生年数:",TEA);
				get_str_del(year,5,1);
				teacher[count_teacher].birthyear = atoi(year);
			}while(atoi(year)>2018);
			//工龄
			printf("\n");
			do
			{
				CLEAR_UP_LINE(1);
				printf("请输入%s入职年数:",TEA);
				get_str_del(year,5,1);
				teacher[count_teacher].inyear = atoi(year);
			}while(atoi(year)>2018);
			count_teacher++;
		}
		else
		{
			printf("%s已满！\n",TEA);
		}
		rand_key_exit();
}

//是否全部删除
int is_alldel()
{
	for(int i = 0;i < count_teacher;i++)
	{
		if(0 == teacher[i].del)
		{
			return i;	
		}
	}
	return i;
}
//删除教师
void del_teacher()
{
		if(isnotea())
		{	
			printf("没有添加%s\n",TEA);
			rand_key_exit();
			return;
		}
		if(is_alldel() == count_teacher)
		{
			printf("%s已被全删除！\n",TEA);
			rand_key_exit();
			return;
		}
		show_tea();
		char id[LENTID] = {};
		if(!in_teaid(id,LENTID,count_teacher,false))return;
		for(int i = 0;i < count_teacher;i++)
		{
			if(0 == strcmp(teacher[i].id,id))
			{
				if(1 == teacher[i].del)
				{
					printf("%s已删除！\n",TEA);
					break;
				}
				teacher[i].del = 1;
				printf("%s%s删除成功!\n",TEA,id);
				break;
			}
		}
		rand_key_exit();
}

//分部修改
void change_tea(Teacher* tea)
{
	char name[20] = {};
	printf("ID:%s 姓名:%s 性别:%s 年龄:%d 工龄:%d\n",
			tea->id,tea->name,1 == tea->sex ? "男" : "女",
			TAYEAR-tea->birthyear,TAYEAR-tea->inyear);
	printf("是否修改姓名(1.确定):\n");
	if(one == getch())
	{
		printf("请输入姓名:\n");
		get_str_del(name,20,1);
		strcpy(tea->name,name);
	}

	printf("是否修改性别(1.确定):\n");
	if(one == getch())
	{
		printf("请输入性别(1.男2.女):");
		scanf("%c",&tea->sex);
	}

	printf("是否修改出生年数(1.确定):\n");
	if(one == getch())
	{
		printf("请输入出生年数:");
		scanf("%d",&tea->birthyear);
	}

	printf("是否修改入职年数(1.确定):\n");
	if(one == getch())
	{
		printf("请输入入职年数:");
		scanf("%d",&tea->inyear);
	}
	printf("按任意键返回！");
	getch();
}

//修改教师基本信息
void change_teacher()
{
		if(isnotea())
		{	
			printf("没有添加%s\n",TEA);
			rand_key_exit();
			return;
		}
		if(is_alldel() == count_teacher)
		{
			printf("%s已被全删除！\n",TEA);
			rand_key_exit();
			return;
		}
		show_tea();
		char id[LENTID] = {},name[20] = {};
		printf("1.根据ID修改。\n");
		printf("2.根据姓名修改。\n");
		if(one == getch())
		{
			in_teaid(id,LENTID,count_teacher,false);
			for(int i = 0;i < count_teacher;i++)
			{
				if(0 == strcmp(teacher[i].id,id))
				{	
					if(1 == teacher[i].del)
					{
						printf("%s已删除！\n",TEA);
						break;
					}
					change_tea(&teacher[i]);
				}
			}
		}
		else if(two == getch())
		{
			get_str_del(name,20,1);
			for(int i = 0;i < count_teacher;i++)
			{
				if(0 == strcmp(teacher[i].name,name))
				{
					if(1 == teacher[i].del)
					{
						printf("%s已删除！\n",TEA);
						break;
					}
					change_tea(&teacher[i]);
				}
			}
			printf("姓名错误！");
		}
		rand_key_exit();
}

//重置教师密码
void reset_teacher()
{	
		if(isnotea())
		{	
			printf("没有添加%s\n",TEA);
			rand_key_exit();
			return;
		}
		if(is_alldel() == count_teacher)
		{
			printf("%s已被全删除！\n",TEA);
			rand_key_exit();
			return;
		}
		show_tea();
		char id[LENTID] = {};
		printf("默认密码为(%s)",DEFAULTMPASS);
		if(!in_teaid(id,LENTID,count_teacher,false))return;
		for(int i = 0;i < count_teacher;i++)
		{
			if(0 == strcmp(teacher[i].id,id))
			{
				if(1 == teacher[i].del)
				{
					printf("%s已删除！\n",TEA);
					break;
				}
				strcpy(teacher[i].password,"000000");
				teacher[i].firstload = 0;
				printf("%s%s密码重置成功!\n",TEA,id);
				break;
			}
		}
		rand_key_exit();
}

//解锁教师帐号
void ulock_teacher()
{
		if(isnotea())
		{	
			printf("没有添加%s\n",TEA);
			rand_key_exit();
			return;
		}
		if(is_alldel() == count_teacher)
		{
			printf("%s已被全删除！\n",TEA);
			return;
		}
		show_tea();
		char id[LENTID] = {};
		if(!in_teaid(id,LENTID,count_teacher,false))return;
		for(int i = 0;i < count_teacher;i++)
		{
			if(0 == strcmp(teacher[i].id,id))
			{
				if(1 == teacher[i].del)
				{
					printf("%s已删除！\n",TEA);
					break;
				}
				teacher[i].lock = 0;
				printf("%s%s解锁成功!\n",TEA,id);
				break;
			}
		}
		rand_key_exit();
}

//查询教师基本信息
void find_teacher()
{
		if(isnotea())
		{	
			printf("没有添加%s\n",TEA);
			rand_key_exit();
			return;
		}
		show_tea();
		char name[20] = {};
		printf("请输入要查询的教师姓名或关键字:\n");
		get_str_del(name,20,1);
		printf("\n-----查询结果-----\n");
		for(int i = 0;i < count_teacher;i++)
		{
			if(NULL != strstr(teacher[i].name,name))
			{
				printf("ID:%s 姓名:%s 性别:%s 年龄:%d 工龄:%d\n",
					teacher[i].id,teacher[i].name,'1' == teacher[i].sex?"男":"女",
					TAYEAR-teacher[i].birthyear,TAYEAR-teacher[i].inyear);
			}
		}
		rand_key_exit();
}

//显示在职教师
void on_job()
{	
		if(isnotea())
		{	
			printf("没有添加%s\n",TEA);
			rand_key_exit();
			return;
		}
		printf("\n----在职教师----\n");
		for(int i = 0;i < count_teacher;i++)
		{
			if(0 != strcmp(teacher[i].id,"\0") && !teacher[i].del)
			{
				printf("ID:%s 姓名:%s 性别:%s 年龄:%d 工龄:%d\n",
					teacher[i].id,teacher[i].name,'1' == teacher[i].sex?"男":"女",
					TAYEAR-teacher[i].birthyear,TAYEAR-teacher[i].inyear);
			}
		}
		rand_key_exit();
}

//显示离职教师
void leave_job()
{	
		if(isnotea())
		{	
			printf("没有添加%s\n",TEA);
			rand_key_exit();
			return;
		}
		printf("\n----离职教师----\n");
		for(int i = 0;i < count_teacher;i++)
		{
			if(0 != strcmp(teacher[i].id,"\0") && teacher[i].del)
			{
				printf("ID:%s 姓名:%s 性别:%s 年龄:%d 工龄:%d\n",
					teacher[i].id,teacher[i].name,'1' == teacher[i].sex?"男":"女",
					TAYEAR-teacher[i].birthyear,TAYEAR-teacher[i].inyear);
			}
		}
		rand_key_exit();
}

//修改密码
void change_manapass(char* id)
{	
		if(NULL == id)return;
		for(int i = 0;i < 5;i++)
		{printf("默认密码为(%s)",DEFAULTMPASS);
			if(0 == strcmp(mana[i].id,id))
			{
				char password[11] = {};
				printf("请输入修改后的密码:\n");
				get_str_del(password,11,1);
				strcpy(mana[i].password,password);
				break;
			}	
		}
		rand_key_exit();
}

//第一次修改密码
void first_change_manapass(char* id)
{
	if(NULL == id)return;
	for(int i = 0;i < 5;i++)
	{
		if(0 == strcmp(mana[i].id,id))
		{
			if(0 != mana[i].firstload)
			{
				return;
			}
			char password[11] = {};
			MOVETO(10,0);
			printf("请输入修改后的密码:\n");
			get_str_del(password,11,1);
			strcpy(mana[i].password,password);
			mana[i].firstload = 1;
			break;
		}	
	}
	printf("按任意键继续！");
	clear_stdin();
	getch();
}

