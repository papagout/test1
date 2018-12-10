#include "myfile.h"
#include "teacher.h"

//#define student_num 2000

extern Teacher teacher[teacher_num];
extern Student student_person[student_num];

void gettxt_base_information_student(void)
{
	FILE* frp = fopen("base_student.txt","r");

	if(NULL == frp)
	{
		perror("fopen");
		return;
	}
	char name[20],id[20],sex[20],age[20],password[20],is_first[20],lock[20];
	fscanf(frp,"%s %s %s %s %s %s %s",name,id,password,sex,age,is_first,lock);

	for(int i=0; i < student_num ;i++)
	{
		fscanf(frp,"%s %s %s %c %d %d %d",student_person[i].student_name, student_person[i].student_id, student_person[i].student_password, &student_person[i].student_sex, &student_person[i].student_age ,&student_person[i].enter_time , &student_person[i].student_enter_time);
	}
}
void gettxt_more_base_information_student(char *fname,int num)
{
	int temp=0;
	FILE* frp = fopen(fname,"r");

	if(NULL == frp)
	{
		perror("fopen");
		return;
	}
	for(int i=0;'\0'!=student_person[i].student_name[0];i++)
	{
		temp++;
	}//查找最后一位学生所在的位置，获得其数值

	for(int i=temp; i < temp+num ;i++)
	{
		fscanf(frp,"%s %s %s %c %d %d %d",student_person[i].student_name, student_person[i].student_id, student_person[i].student_password, &student_person[i].student_sex, &student_person[i].student_age ,&student_person[i].enter_time , &student_person[i].student_enter_time);
	}
}

void gettxt_grade_information_student(void)
{
	FILE* frp = fopen("grade_student.txt","r");
	if(NULL == frp)
	{
		perror("fopen");
		return ;
	}
	char chinese[20],math[20],english[20];
	fscanf(frp,"%s %s %s",chinese,math,english);

	for(int i=0; i<student_num ;i++)
	{
		fscanf(frp,"%f %f %f",&student_person[i].student_chinese, &student_person[i].student_math, &student_person[i].student_english);
	}
}
void gettxt_more_grade_information_student(char *fname,int num)
{
	int temp=0;
	FILE* frp = fopen(fname,"r");
	if(NULL == frp)
	{
		perror("fopen");
		return ;
	}
	for(int i=0;'\0'!=student_person[i].student_name[0];i++)
	{
		temp++;
	}//查找最后一位成绩所在的位置，获得其数值

	for(int i=temp; i<temp+num ;i++)
	{
		fscanf(frp,"%f %f %f",&student_person[i].student_chinese, &student_person[i].student_math, &student_person[i].student_english);
	}
}


void puttxt_base_information_student(void)
{
	FILE* fwp = fopen("base_student.txt","w");

	fprintf(fwp,"%s %s %s %s %s %s %s\n","姓名","学号","密码", "性别","年龄","is_first(0:isfirst)","lock");

	for(int i=0; i<student_num ;i++)
	{
		if(student_person[i].student_sex != 0)
			fprintf(fwp,"%s %s %s %c %2d %d\n",student_person[i].student_name, student_person[i].student_id,student_person[i].student_password,
										student_person[i].student_sex, student_person[i].student_age, student_person[i].enter_time ,student_person[i].student_enter_time);
	}
}

void puttxt_grade_information_student(void)
{
	FILE* fwp = fopen("grade_student_end.txt","w");

	fprintf(fwp,"%s %s %s %s %s %s %s %s %s %s\n","姓名","学号","语文","排名","数学","排名","英语","排名","总分","排名");

	for(int i=0; i<student_num ;i++)
	{
		if( student_person[i].student_sex != 0)
			fprintf(fwp,"%s %s %3g %d %3g %3d %3g %3d %3g %3d\n",student_person[i].student_name,  student_person[i].student_id,
														  student_person[i].student_chinese,  student_person[i].student_chinese_seqencing,
														  student_person[i].student_math,  student_person[i].student_math_seqencing,
														  student_person[i].student_english,  student_person[i].student_english_seqencing,
														  student_person[i].student_sum,  student_person[i].student_sum_seqencing   );
	}
}

void gettxt_base_information_teacher(void)
{
	FILE* frp = fopen("base_teacher.txt","r");

	if(NULL == frp)
	{
		perror("fopen");
		return;
	}
	char name[20],id[20], password[20], sex[20],age[20],work_time[20],is_first[20], lock[20] ,del[20];
	fscanf(frp,"%s %s %s %s %s %s %s %s %s",name,id,password,sex,age,work_time,is_first,lock, del);

	for(int i=0; i < teacher_num ;i++)
	{
		fscanf(frp,"%s %s %s %hhd %d %d %d %d %d",teacher[i].name, teacher[i].id, teacher[i].password,
		&teacher[i].sex, &teacher[i].birthyear , &teacher[i].inyear, &teacher[i].firstload, &teacher[i].lock, &teacher[i].del);
	}
}

void puttxt_base_information_teacher(void)
{
	FILE* fwp = fopen("base_teacher.txt","w");

	fprintf(fwp,"%s %s %s %s %s %s %s %s %s\n","姓名","工号","密码", "性别","年龄","工龄","is_first(0:isfirst)","lock","del");

	for(int i=0; i<teacher_num ;i++)
	{
		if(teacher[i].name[0] != 0)
			fprintf(fwp,"%s %s %s %hhd %d %d %d %d %d \n",
			teacher[i].name, teacher[i].id, teacher[i].password,
			teacher[i].sex, teacher[i].birthyear , teacher[i].inyear,
			teacher[i].firstload ,teacher[i].lock, teacher[i].del);
	}
}


void gettxt_base_information_manager(void)
{
	FILE* frp = fopen("base_manager.txt","r");

	if(NULL == frp)
	{
		perror("fopen");
		return;
	}
	char id[20], password[20], first_load[20], lock[20] ,del[20];
	fscanf(frp,"%s %s %s %s %s",id,password,first_load,lock, del);

	for(int i=0; i < SUMMANA ;i++)
	{
		fscanf(frp,"%s %s %d %d %d",mana[i].id, mana[i].password, &mana[i].lock, &mana[i].del, &mana[i].firstload);
	}
}


void puttxt_base_information_manager(void)
{
	FILE* fwp = fopen("base_manager.txt","w");

	fprintf(fwp,"%s \t%s \t%s \t%s \t%s\n","工号","密码","lock","del","firstload");

	for(int i=0; i<SUMMANA ;i++)
	{
		if(mana[i].id[0] != 0)
			fprintf(fwp,"%s %s %d %d %d\n",
			mana[i].id, mana[i].password,
			mana[i].lock, mana[i].del ,mana[i].firstload);
	}
}
