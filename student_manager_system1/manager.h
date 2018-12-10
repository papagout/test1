#ifndef MANAGER_H
#define MANAGER_H
#include "teacher.h"
#include <stdio.h>
#include <stdbool.h>
#include <getch.h>
#include "supermanager.h"
#include "jiemian.h"
#include "tools.h"

#define LENTID 7
#define LENTPASSWORD 7
#define SUMTEA 200
#define TAYEAR 2018 //暂时用
#define TEA "教师"
#define DEFAULTTPASS "000000"	//教师默认密码
#define manager_num 200
/*
typedef struct Teacher
{
	char id[7];
	char password[7];
	char name[20];
	char sex;
	//年龄(现在年数-出生年数)
	int birthyear;
	//工龄(现在年数-入职年数)
	int inyear;
	int lock;
	int del;
}Teacher;
*/

bool is_time_manager_right(char* user_id);  //输入次数少于３次

bool is_right_manager (char* user_id,char* user_password );

void manager_show_time(char* user_id);


void chose_manager(char*);

void add_teacher(void);

void del_teacher(void);

void change_teacher(void);

void reset_teacher(void);

void ulock_teacher(void);

void find_teacher(void);

void on_job(void);

void leave_job(void);

void change_manapass(char* );

void first_change_manapass(char* id);

#endif //MANAGER_H
