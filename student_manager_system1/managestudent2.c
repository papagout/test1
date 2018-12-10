#include "managestudent.h"
#include  "teacher.h"
#include  "iofunction.h"
#include  "tools.h"
void add_score(void)
{
	system("clear");
	int num=0;
	float chi_num=0,math_num=0,eng_num=0,sum_num=0;
	char id[20]={};
	printf("请输入要添加成绩的学生学号:");
    get_str(id,19);
	if(!is_is_id_exist(id))
	{
		return;
	}
	int temp = id_found(id);
	printf("请输入语文成绩:");
	clear_stdin();
    scanf("%f",&student_person[temp].student_chinese);
	printf("请输入数学成绩:");
	clear_stdin();
    scanf("%f",&student_person[temp].student_math);
	printf("请输入英语成绩:");
	clear_stdin();
    scanf("%f",&student_person[temp].student_english);
	clear_stdin();
	student_person[temp].student_sum=(student_person[temp].student_english+
	student_person[i].student_math+student_person[i].student_chinese);
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
void change_score(void)
{
	system("clear");
	int num=0;
	char id[20];
	printf("请输入要修改学生的学号:");
	get_str(id,19);
	if(!is_is_id_exist(id))
	{
		return;
	}
	int temp=id_found(id);
	printf("请输入语文成绩:");
	clear_stdin();
    scanf("%f",&student_person[temp].student_chinese);
	printf("请输入数学成绩:");
	clear_stdin();
    scanf("%f",&student_person[temp].student_math);
	printf("请输入英语成绩:");
	clear_stdin();
    scanf("%f",&student_person[temp].student_english);
    chinese_seqencing();
  	math_seqencing();
	english_seqencing();
	sum_seqencing();
	calc_chinese_avg();
	calc_math_avg();
	calc_english_avg();
	printf("修改成功");
	rand_key_exit();
}
void found_score(void)
{
	system("clear");
	int num=0,temp=0;
	char id[20]={},name[20]={};
	printf("1.选择学号查询 2.选择姓名查询\n");
	clear_stdin();
    scanf("%d",&temp);
	if(1 == temp)
	{
		system("clear");
   	    printf("请输入学号:");
		get_str(id,19);
		if(!is_is_id_exist(id))
		{
			return;
		}
		int temp=id_found(id);
		printf("%s ",student_person[temp].student_name);
	    printf("%f ",student_person[temp].student_chinese);
    	printf("%f ",student_person[temp].student_math);
    	printf("%f",student_person[temp].student_english);
		printf("查找成功");
		rand_key_exit();
	}
	else
	{
		system("clear");
	    printf("请输入姓名:");
		get_str(name,19);
		if(!is_is_name_exist(name))
		{
			return;
		}
		for(int i=0;student_person[i].student_name[0];i++)
		{
			if(0 == strcmp(name,student_person[i].student_name))
			{
				printf("%s %f %f %f\n",student_person[i].student_name,student_person[i].student_chinese,
				student_person[i].student_math,student_person[i].student_english);
			}
		}
		printf("查找成功");
		rand_key_exit();
	}
}
void seqencing_score(void)
{
	system("clear");
	int num=0,temp=0;
	printf("1按语文成绩排序 2按数学成绩排序 3按英语成绩排序 4按总分排序\n");
    temp=getch();
	switch(temp)
	{
		case one:student_chinese_seqencing_show();break;
		case two:student_math_seqencing_show();break;
		case three:student_english_seqencing_show();break;
		case four:student_sum_seqencing_show();break;
		default:break;
	}
	 printf("显示完成");
	 rand_key_exit();
}
