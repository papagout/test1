#ifndef TOOLS_H
#define TOOLS_H

#include <getch.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "iofunction.h"
#include "ctrlcur.h"

char* get_str_del(char* str,size_t size,int mode);

char* in_str(char* id,int start,int idlen,int x,int y);

char* in__password(char* pass,int passlen,int x,int y);

void rand_key_exit(void);

bool islenequal(char* id,int idlen);

bool isnamelenequal(char* name);

#endif //TOOLS_H
