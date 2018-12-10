#ifndef MYFILE_H
#define MYFILE_H
#include "student.h"
#include "supermanager.h"

extern Student student_person[student_num];

void gettxt_base_information_student(void);
void gettxt_more_base_information_student(char *fname,int num);
void gettxt_grade_information_student(void);
void gettxt_more_grade_information_student(char *fname,int num);
void gettxt_base_information_teacher(void);

void puttxt_base_information_student(void);
void puttxt_grade_information_student(void);
void puttxt_base_information_teacher(void);



void gettxt_base_information_manager(void);
void puttxt_base_information_manager(void);


#endif //endMYFILE_H 
