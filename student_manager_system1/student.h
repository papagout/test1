#ifndef STUDENT_H
#define STUDENT_H
#define student_num 10

#include <unistd.h>
#include <stdlib.h>
#include <getch.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct Student
{
	//学生信息包括：学号、密码、姓名、性别、年龄、语文、数学、英语、平均、总分、排名 
	char student_id[20];
	char student_password[20];
	char student_name[20];
	char student_sex;
	int student_age;
	float student_chinese;
	int student_chinese_seqencing;//chinese排名
	float student_math;
	int student_math_seqencing;//math排名
	float student_english;
	int student_english_seqencing;//english排名
	float student_sum;
	int student_sum_seqencing;//排名
	int student_enter_time;
	int enter_time;

}Student;


bool is_right_student ( char* ,char* );
bool is_time_student_right(char* );  
bool is_inschool_student(char* str1);

void student_system(char* );
void init_show(void );
void student_show_time(char* );
void change_password(char* str);
void first_change_password(char* str ,int* num );

//void student_clear_stdin(void);
void student_enter_password(char* user_id,char* user_password);

#endif //STUDENT
