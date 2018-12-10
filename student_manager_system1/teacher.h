#ifndef TEACHER_H
#define TEACHER_H
#include <stdio.h>
#include <getch.h>
#include <unistd.h>
#include <stdbool.h>
#include "student.h"
#define teacher_num 200

typedef struct Teacher
{
	char id[20];
	char password[20];
	char name[20];
	char sex;
	int birthyear;
	int inyear;
	int lock;
	int del;
	int firstload;
}Teacher;

extern Teacher teacher[teacher_num];
extern Student student_person[student_num];
 
void test_teacher1(char *user_id);
void test_teacher2(char *user_id);
void teacher_choice_function_two(void);
void teacher_choice_function_three(void);
void exit_teacher(void);
void change_self_password(char *str);
void chinese_seqencing(void);
void math_seqencing(void);
void english_seqencing(void);
void sum_seqencing(void);
void student_chinese_seqencing_show(void);
void student_math_seqencing_show(void);
void student_english_seqencing_show(void);
void student_sum_seqencing_show(void);
int  teacher_choice_function_one(char *user_id);


bool is_time_teacher_right(char* user_id);  //输入次数少于３次
void teacher_show_time(char* user_id);
bool is_right_teacher(char* user_id,char* user_password );
bool is_inschool_teacher(char* user_id);
			
#endif//TEACHER_H
