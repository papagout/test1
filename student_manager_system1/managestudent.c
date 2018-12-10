#include "managestudent.h"
//#include "managestudent2.h"
#include  "teacher.h"
#include  "iofunction.h"
#include  "tools.h"
#include  "myfile.h"
void add_student(void)//添加学生
{
	system("clear");
	int num=0,temp=0;
	char id[20]={};
	for(int i=0;'\0'!=student_person[i].student_name[0];i++)
	{
		temp++;
	}//查找最后一位学生所在的位置，获得其数值
        printf("请输入学生学号:\n");
		get_str(id,19);
		while(is_id_exist(id) || 0 == strlen(id))
		{
			printf("学号已存在或输入的学号为空，请重新输入\n");
			get_str(id,19);
		}
		strcpy(student_person[temp].student_id,id);
	    printf("请输入学生姓名:\n");
		get_str(student_person[temp].student_name,20);
		printf("请输入学生性别(1男2女):\n");
		clear_stdin();
		scanf("%c",&student_person[temp].student_sex);
        printf("请输入学生年龄:\n");
        clear_stdin();
		scanf("%d",&student_person[temp].student_age);      
        clear_stdin();
        init_password(student_person[temp].student_password);
    	chinese_seqencing();
  		math_seqencing();
		english_seqencing();
		sum_seqencing();
		calc_chinese_avg();
		calc_math_avg();
		calc_english_avg();
	    printf("添加成功");
		rand_key_exit();
}
void more_add_student(void)
{
	char fname[20]={};
	int num=0;
	printf("请输入想要导入的文件:");
	get_str(fname,19);
	printf("请输入要导入的人数:");
	clear_stdin();
	scanf("%d",&num);
	gettxt_more_base_information_student(fname,num);
}
void more_add_score(void)
{
	char fname[20]={};
	int num=0;
	printf("请输入想要导入的文件:");
	get_str(fname,19);
	printf("请输入要导入的人数:");
	clear_stdin();
	scanf("%d",&num);
	gettxt_more_grade_information_student(fname,num);
}
void del_student(void)
{
	system("clear");
	char id[20]={};
	int num=0;
	printf("请输入要删除的学生学号:");
	get_str(id,19);
	if(!is_is_id_exist(id))
	{
		return;
	}
	for(int i=0;student_person[i].student_id[0];i++)
	{
		if(teacher_is_student(id,student_person[i].student_id))
		{
			student_person[i].student_sex= '1' == student_person[i].student_sex ? '3':'4';
			student_person[i].student_chinese = 0;
			student_person[i].student_math = 0;
			student_person[i].student_english = 0;
			student_person[i].student_sum = 0;
			break;
		}
	}
    chinese_seqencing();
  	math_seqencing();
	english_seqencing();
	sum_seqencing();
	calc_chinese_avg();
	calc_math_avg();
	calc_english_avg();
	printf("删除成功");
	rand_key_exit();
}
void change_student(void)
{
	system("clear");
	int num=0,temp=0,age=0;
	char id[20],name[20],sex='0';
	printf("请输入要修改的学生的学号:");
	get_str(id,19);
	if(!is_is_id_exist(id))
	{
		return;
	}
    temp = id_found(id);
	printf("请输入要修改的信息:\n");
	printf("name=");
	get_str(name,20);
	strcpy(student_person[temp].student_name,name);
	printf("sex(1男2女)=");
	clear_stdin();
	scanf("%c",&student_person[temp].student_sex);
	printf("age=");
	clear_stdin();
	scanf("%d",&student_person[temp].student_age);
    chinese_seqencing();
  	math_seqencing();
	english_seqencing();
	sum_seqencing();
	calc_chinese_avg();
	calc_math_avg();
	printf("修改成功");
	rand_key_exit();
}
void reset_student_password(void)
{
	system("clear");
	int num=0;
	char id[20]={},new_password[12]={};
	printf("请输入学生学号:\n");
	get_str(id,19);
	if(!is_is_id_exist(id))
	{
		return;
	}
	int temp=id_found(id);
	printf("请输入新密码:\n");
    get_str(new_password,8);
	strcpy(student_person[temp].student_password,new_password);
	printf("重置成功");
	rand_key_exit();
}
void unlock_student_id(void)
{
	system("clear");
	char id[20]={};
	int num=0;
	printf("请输入要解锁的学生的学号:\n");
    get_str(id,19);
	if(!is_is_id_exist(id))
	{
		return;
	}
	int temp = id_found(id);
	student_person[temp].student_enter_time=0;
	 printf("解锁成功");
	 rand_key_exit();
}
void foud_studnt(void)
{
	system("clear");
	int num=0;
	char name[20]={};
	printf("请输入学生姓名:");
    get_str(name,19);
	int temp=name_found(name);
	if(!is_is_name_exist(name))
	{
		return;
	}
    for(int i=0;student_person[i].student_name[0];i++)
	{
       if(student_person[i].student_sex-48 <= 2 &&student_person[i].student_sex-48>0&&0 == strcmp(name,student_person[i].student_name))
	   {
		   printf("name=%s sex=%s age=%d id=%s\n",student_person[i].student_name,
		   '1' ==student_person[i].student_sex?"男":"女",student_person[i].student_age,student_person[i].student_id);
	   }
	}
	printf("查找完成");
	rand_key_exit();
}
void 
show_in_shool_student(void)
{
	system("clear");
	int num=0;
	 for(int i=0;student_person[i].student_name[0];i++)
	 {
		 if(student_person[i].student_sex -48<=2)
		 {
		 	printf("name=%s sex=%s id=%s age=%d\n",student_person[i].student_name,
		 	'1' ==student_person[i].student_sex?"男":"女",student_person[i].student_id,
			student_person[i].student_age);
		 }
	 }
	 printf("显示完成");
	 rand_key_exit();
}
void show_out_school_student(void)
{
	 system("clear");
	 int num=0;
	 for(int i=0;student_person[i].student_name[0];i++)
	 {
		 if(student_person[i].student_sex -48>2)
		 {
		 	printf("name=%s sex=%s id=%s age=%d\n",student_person[i].student_name,
		 	'3' ==student_person[i].student_sex?"男":"女",student_person[i].student_id,
			student_person[i].student_age);
		 }
	 }
	printf("显示成功");
	rand_key_exit();
}
