#include "jiemian.h"

//测试界面
void show_chose_test()
{
	system("clear");
	printf("----test----\n");
	printf("1.管理员\n");
	printf("2.超级管理员\n");
	printf("请输入指令：\n");
}

//登陆界面
void load()
{
	system("clear");
	printf("|^^^欢迎使用学生管理系统^^^|\n");
	printf("|                          |\n");
	printf("|   帐号:                  |\n");
	printf("|                          |\n");
	printf("|   密码:                  |\n");
	printf("|                          |\n");
	printf("|__________________________|\n");
}

//超级管理员功能选择界面
void show_chose_sumanager()
{
	system("clear");
	printf("----超级管理员----\n");
	printf("1.添加管理员\n");
	printf("2.删除管理员\n");
	printf("3.重置管理员密码\n");
	printf("4.解锁管理员帐号\n");
	printf("5.显示所有管理员\n");
	printf("0.退出\n");
	printf("请输入指令：\n");
}

//管理员选择界面
void show_chose_manager(char* id)
{
	if(NULL == id)return;
	system("clear");
	printf("----管理员%s----\n",id);
	printf("1.添加教师\n");
	printf("2.删除教师\n");
	printf("3.修改教师基本信息\n");
	printf("4.重置教师密码\n");
	printf("5.解锁教师帐号\n");
	printf("6.查询教师基本信息\n");
	printf("7.显示所有在职教师\n");
	printf("8.显示所有离职教师\n");
	printf("9.修改登陆密码\n");
	printf("0.退出\n");
	printf("请输入指令：\n");
}
