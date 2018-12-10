#ifndef IOFUNCTION
#define IOFUNCTION
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
extern float student_avg_english;
extern float student_avg_math;
extern float student_avg_chinese;
char* get_str(char* str,size_t size);
void clear_stdin(void);
bool teacher_is_student(char *str,char *str1);
bool is_id_exist(char *id);
bool is_name_exist(char *name);
bool is_is_id_exist(char *id);
bool is_is_name_exist(char *name);
void init_password(char *str);
void teacher_change_self_password(char *id);
int id_found(char *str);
int name_found(char *str);
int found_teacher_user_id(char *user_id);
void change_self_password(char *str);//修改密码,传入密码所在位置
void calc_chinese_avg(void);
void calc_math_avg(void);
void calc_english_avg(void);
#endif//IOFUNCTION
