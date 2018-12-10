#ifndef SUPERMANAGER_H
#define SUPERMANAGER_H

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <getch.h>
//#include "manager.h"
#include "jiemian.h"
#include "tools.h"

#define LENMID 11					//管理员ID长度
#define LENMPASSWORD 11				//管理员密码长度
#define SUMMANA 5					//管理员数量
#define DEFAULTMPASS "000000" 		//管理员默认密码
#define MANA "管理员"				//“管理员”
#define SUID "xxxx" 				//超级管理员ID
#define SUPASS "test" 				//超级管理员密码

typedef struct Manager
{
	char id[11];
	char password[11];
	int lock;
	int del;
	int firstload;
}Manager;

Manager mana[5];

int count_mana;

void chose_sumanager(void);

void add_manager(void);

void del_manager(void);

void reset_manager(void);

void ulock_manager(void);

void show_manager(void);

#endif //SUPERMANAGER_H
