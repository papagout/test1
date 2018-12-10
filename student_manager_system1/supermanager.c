#include "supermanager.h"

//判断ID是否相等
bool isidequal(char* id,int n)
{
	for(int i = 0;i < n;i++)
	{
		if(0 == strcmp(mana[i].id,id))
		{
			return true;
		}
	}
	return false;
}

//ID输入及判定
bool in_id(char* id,int idlen,int n,bool isid)
{
	printf("请输入ID：");
	get_str_del(id,idlen,1);
	while(!(10 == strlen(id) && isid?!isidequal(id,n):isidequal(id,n)))
	{
		printf("ID错误！回车继续输入！任意键退出！\n");
		if('\n' == getch())
		{
			//strcpy(id,"\0\0\0\0\0\0\0\0\0\0");
			//memset(id,'\0',sizeof(id));
			id[9] = '\0';
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

//判断管理员是否为空
bool isnomana()
{
	if(0 == strcmp(mana[0].id,"\0"))
	{
		return true;
	}
	return false;
}

//
void show_mana()
{
	printf("---管理员---\n");
	for(int i = 0;i < count_mana;i++)
	{
		if(0 != strcmp(mana[i].id,"\0") && !mana[i].del)
		{
			printf("%sID:%s\n",MANA,mana[i].id);
		}
	}
}

//获取已有管理员数量
int get_countmana()
{
	for(int i = 0;i < SUMMANA;i++)
	{
		if(!islenequal(mana[i].id,10))
		{
			return i;
		}
	}
}

//选择超级管理员功能
void chose_sumanager()
{
	count_mana = get_countmana();
	while(1)
	{
		show_chose_sumanager();
		switch(getch())
		{
			case one	:add_manager();		break;
			case two	:del_manager();		break;
			case three	:reset_manager();	break;
			case four	:ulock_manager();	break;
			case five	:show_manager();	break;
			case zero	:return;
			default:break;
		}
	}
}

//添加管理员
void add_manager()
{
		char id[LENMID] = {},password[LENMPASSWORD] = {};
		if(count_mana < SUMMANA)
		{
			if(!in_id(id,LENMID,count_mana,true))return;
			strcpy(mana[count_mana].id,id);
			printf("%s%s添加成功！\n",MANA,id);
			strcpy(mana[count_mana].password,DEFAULTMPASS);
			count_mana++;
		}
		else
		{
			printf("%s已满！\n",MANA);
		}
		rand_key_exit();
}

//是否全部删除
int is_allmdel()
{
	for(int i = 0;i < count_mana;i++)
	{
		if(0 == mana[i].del)
		{
			return i;	
		}
	}
	return i;
}

//删除管理员
void del_manager()
{	
		if(isnomana())
		{	
			printf("没有添加%s\n",MANA);
			rand_key_exit();
			return;
		}
		if(is_allmdel() == count_mana)
		{
			printf("%s已被全删除！\n",MANA);
			rand_key_exit();
			return;
		}
		show_mana();
		char id[LENMPASSWORD] = {};
		if(!in_id(id,LENMID,count_mana,false))return;
		for(int i = 0;i < count_mana;i++)
		{
			if(0 == strcmp(mana[i].id,id))
			{
				if(1 == mana[i].del)
				{
					printf("%s已删除！\n",MANA);
					break;
				}
				mana[i].del = 1;
				printf("%s%s删除成功!\n",MANA,id);
				break;
			}
		}
		rand_key_exit();
}

//重置管理员密码
void reset_manager()
{	
		if(isnomana())
		{	
			printf("没有添加%s\n",MANA);
			rand_key_exit();
			return;
		}
		if(is_allmdel() == count_mana)
		{
			printf("%s已被全删除！\n",MANA);
			rand_key_exit();
			return;
		}
		show_mana();
		char id[LENMID] = {};
		printf("默认密码为(%s)\n",DEFAULTMPASS);
		if(!in_id(id,LENMID,count_mana,false))return;
		for(int i = 0;i < count_mana;i++)
		{
			if(0 == strcmp(mana[i].id,id))
			{
				if(1 == mana[i].del)
				{
					printf("%s已删除！\n",MANA);
					break;
				}
				strcpy(mana[i].password,DEFAULTMPASS);
				mana[i].firstload = 0;
				printf("%s%s密码重置成功!\n",MANA,id);
				break;
			}
		}
		rand_key_exit();
}

//解锁管理员帐号
void ulock_manager()
{
		if(isnomana())
		{	
			printf("没有添加%s\n",MANA);
			rand_key_exit();
			return;
		}
		if(is_allmdel() == count_mana)
		{
			printf("%s已被全删除！\n",MANA);
			rand_key_exit();
			return;
		}
		show_mana();
		char id[LENMID] = {};
		if(!in_id(id,LENMID,count_mana,false))return;
		for(int i = 0;i < count_mana;i++)
		{
			if(0 == strcmp(mana[i].id,id))
			{
				if(1 == mana[i].del)
				{
					printf("%s已删除！\n",MANA);
					break;
				}
				mana[i].lock = 0;
				printf("%s%s解锁成功!\n",MANA,id);
				break;
			}
		}
		rand_key_exit();
}

//显示所有管理员
void show_manager()
{	
		if(isnomana())
		{	
			printf("没有添加%s\n",MANA);
			rand_key_exit();
			return;
		}
		if(is_allmdel() == count_mana)
		{
			printf("%s已被全删除！\n",MANA);
			rand_key_exit();
			return;
		}
		show_mana();
		rand_key_exit();
}
