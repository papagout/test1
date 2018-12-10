#include "myfile.h"
#include "teacher.h"
#include "iofunction.h"
#include "tools.h"
#include "jiemian.h"
extern Student student_person[student_num];

float student_avg_english;
float student_avg_math;
float student_avg_chinese;

void init_show(void)
{
	system("clear");
	load();
	printf("\r按　q　键：退出学生管理系统;\n其他任意键继续输入id\n");
	clear_stdin();
	if( q == getch())
	{
		puttxt_base_information_teacher();
		puttxt_base_information_student();
		puttxt_grade_information_student();
		puttxt_base_information_manager();
		exit(0);
	}
	return;
}

//星号显示隐藏密码
void password_miss_getch(char* arr)
{
	for(int i=0; i<20;)
	{
		clear_stdin();
		arr[i] = getch();
		if (arr[i] ==127 && i>=0)
		{
			i==0? i:i--;
			printf("\b \b");
		}
		else if(arr[i] == 10)
		{
			arr[i] =  '\0';
			break;
		}
		else
		{
			i++;
			putchar('*');
		}
	}
	return;
}

void student_enter_password(char* str,char* str1)
{
	MOVETO(3,10);
	get_str_del(str,11,1);
	//clear_stdin();
	//scanf("%s",str);
	MOVETO(5,10);
	get_str_del(str1,11,2);
	//password_miss_getch(str1);
	return;
}

bool is_right_student ( char* str1,char* str2)
{
	for(int i=0; i < student_num ;i++)
	{
		if( !strcmp( str1,student_person[i].student_id ) )
		{	
			if( !strcmp( str2,student_person[i].student_password ) )
			{
				return true;	
			}
			return false;
		}
	}
	return false;
}

bool is_inschool_student(char* str1)
{
	for(int i=0; i < student_num ;i++)
	{
		if( !strcmp( str1,student_person[i].student_id )  && student_person[i].student_sex-zero <= 2 )
		{	
			return true;	
		}
	}
	return false;
}

void student_show_time(char* str1)      //显示学生次数
{
	for(int i=0; i < student_num ;i++)
	{
		if( !strcmp( str1,student_person[i].student_id ) )
		{	
			student_person[i].student_enter_time ++ ;
			if( student_person[i].student_enter_time <=3)
				printf("%d次错误密码! ！！ \n",student_person[i].student_enter_time ) ;
			sleep(1);
			return ;	
		}
	}
	printf("账号输入有错误，请重新输入\n");
	sleep(1);
	return ;
}

bool is_time_student_right(char* str1)  //输入次数少于３次
{
	for(int i=0; i < student_num ;i++)
	{
		if(!strcmp(str1,student_person[i].student_id))
		{	
			if( student_person[i].student_enter_time  >= 3)
				return true;
			else
			{
				return false;
			}
		}
	}
	return false;
}

void first_change_password(char* str ,int* num )
{
	char arr[20] = {};
	char arr1[20] = {};

	printf("\n－－－首次更改密码－－－\n");
	clear_stdin();
	if(scanf("%s",arr))
	{
		printf("请再次输入相同的密码\n");
		clear_stdin();
		scanf("%s",arr1);
		if(!strcmp(arr1,arr))
		{
			*num = 1;
			strcpy(str,arr);
			printf("更改成功\n");
		}
		else
		{
			*num=0;
			printf("没输入成功！！！\n");
		}
	}
	sleep(1);
	return;
}

void change_password(char* str)
{
	printf("\n－－－更改密码－－－\n");
	if(scanf("%s",str))
	{
		printf("更改成功\n");
	}
	else
	{
		printf("更改失败！！！\n");
	}
	sleep(1);
	return;
}

void student_system(char* str)
{	
	int i=0;
	for( i=0;  i< student_num; i++ )
	{
		if( !strcmp(str,student_person[i].student_id))
		{
			student_person[i].student_enter_time = 0;
			if(0 == student_person[i].enter_time)
			{
				first_change_password( student_person[i].student_password,  &student_person[i].enter_time );
			}
			if(0 == student_person[i].enter_time)
			{
				printf("首次更改密码失败！！\n退出学生系统\n");
				sleep(1);
				return;
			}
			break;
		}
	}
	for(int i=0;student_person[i].student_name[0];i++)
	{
		student_person[i].student_sum=(student_person[i].student_english+student_person[i].student_math+student_person[i].student_chinese);
	}
    chinese_seqencing();
  	math_seqencing();
	english_seqencing();
	sum_seqencing();
	calc_chinese_avg();
	calc_math_avg();
	calc_english_avg();
	while(1)
	{
		system("clear");
		printf("\n进入了student system\n\n");

		//学生信息包括：学号、密码、姓名、性别、年龄、语文、数学、英语、平均、总 分、排名 
	
		printf("student_name: %s\n\n",student_person[i].student_name);
		printf("student_id:   %s\n\n",student_person[i].student_id);
		printf("chinese:      %3.2f , avg:    %3.2f \n\n", student_person[i].student_chinese,  student_avg_chinese );
		printf("math   :      %3.2f , avg:    %3.2f \n\n", student_person[i].student_math, student_avg_math );
		printf("english:      %3.2f , avg:    %3.2f \n\n", student_person[i].student_english, student_avg_english );
		printf("\n选择ａ更改密码\n");
		printf("选择ｂ显示单科排名\n");
		printf("选择ｃ显示总分排名\n");
		printf("选择ｑ退出学生系统\n");

		switch(getch())
		{
			case a : change_password(student_person[i].student_password); break;
			case b : printf("\nchinese:  %d, math:  %d, english: %d\n\n",student_person[i].student_chinese_seqencing, student_person[i].student_math_seqencing,
								student_person[i].student_english_seqencing);sleep(1); break;
			case c : printf("\nsum:  %g ,  seqencing:        %d\n\n", student_person[i].student_sum , student_person[i].student_sum_seqencing);//排名
								sleep(1); break;
			case q : printf("\n你将要退出学生管理系统\n");sleep(1); return;
			default:  break;
		}
	}
}
