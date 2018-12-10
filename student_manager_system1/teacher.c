#include "teacher.h"
#include "surface.h"
#include "managestudent.h"
#include "iofunction.h"
Teacher teacher[teacher_num];

void test_teacher2(char *user_id)//测试程序
{
    int temp=found_teacher_user_id(user_id);
	clear_stdin();
	printf("%5s",teacher[temp].name);
	printf("%5d  ",teacher[temp].birthyear);
	printf("%6s  ",'1' ==teacher[temp].sex?"男":"女");
	printf("%7s  ",teacher[temp].id);
	printf("%7d \n",teacher[temp].inyear);
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
	printf("------------------------------------\n");
}

int teacher_choice_function_one(char *user_id)//选择管理学生的成绩或信息和修改密码
{
	clear_stdin();
	int temp1=found_teacher_user_id(user_id);
	int temp=getch();
	switch(temp)
	{
		case one:show_student_informaton_news();break;
		case two:show_stdent_score_news();break;
		case three:change_self_password(teacher[temp1].password);break;
		case four:break;
		default:break;
	}
	return temp;
}

void teacher_choice_function_two(void)//管理学生的信息选择
{
	while(1)
	{
		
	    clear_stdin();
	    show_student_informaton_news();
	    int temp=getch();
	    switch(temp)
	    {
		    case one:add_student();break;
		    case two:del_student();break;
		    case three:change_student();break;
		    case four:reset_student_password();break;
		    case five:unlock_student_id();break;
		    case six:foud_studnt();break;
		    case seven:show_in_shool_student();break;
			case eight:show_out_school_student();break;
			case zero:more_add_student();break;
			case nine:return;
			default:break;
	    }
    }
}
void teacher_choice_function_three(void)//管理学生的成绩选择
{
	while(1)
	{
		clear_stdin();
		show_stdent_score_news();
		int temp=getch();
		switch(temp)
		{
			case one:add_score();break;
			case two:more_add_score();break;
			case three:change_score();break;
			case four:found_score();break;
			case five:seqencing_score();break;
			case nine:return;
			default:break;
		}
	}
}

void chinese_seqencing(void)
{
	float chinese_seqe[2000]={},temp=0;
	for(int i=0;student_person[i].student_name[0];i++)
	{
	     chinese_seqe[i]=student_person[i].student_chinese;
	}
	for(int i=0;student_person[i].student_name[0];i++)
	{
		for(int j=0;student_person[j].student_name[0];j++)
		{
			if(chinese_seqe[i]>chinese_seqe[j])
			{
				temp=chinese_seqe[j];
				chinese_seqe[j]=chinese_seqe[i];
				chinese_seqe[i]=temp;
			}
		}
	}
	for(int i=0;student_person[i].student_name[0];i++)
	{
		for(int j=0;student_person[j].student_name[0];j++)
		{
			if(student_person[i].student_chinese == chinese_seqe[j])
			{
				student_person[i].student_chinese_seqencing=j+1;
				break;
			}
		}
	}
}
void math_seqencing(void)
{
	float math_seqe[2000]={},temp=0;
	for(int i=0;student_person[i].student_name[0];i++)
	{
	     math_seqe[i]=student_person[i].student_math;
	}
	for(int i=0;student_person[i].student_name[0];i++)
	{
		for(int j=0;student_person[j].student_name[0];j++)
		{
			if(math_seqe[i]>math_seqe[j])
			{
				temp=math_seqe[j];
				math_seqe[j]=math_seqe[i];
				math_seqe[i]=temp;
			}
		}
	}
	for(int i=0;student_person[i].student_name[0];i++)
	{
		for(int j=0;student_person[j].student_name[0];j++)
		{
			if(student_person[i].student_math == math_seqe[j])
			{
				student_person[i].student_math_seqencing=j+1;
				break;
			}
		}
	}
}
void english_seqencing(void)
{
	float english_seqe[2000]={},temp=0;
	for(int i=0;student_person[i].student_name[0];i++)
	{
	     english_seqe[i]=student_person[i].student_english;
	}
	for(int i=0;student_person[i].student_name[0];i++)
	{
		for(int j=0;student_person[j].student_name[0];j++)
		{
			if(english_seqe[i]>english_seqe[j])
			{
				temp=english_seqe[j];
				english_seqe[j]=english_seqe[i];
				english_seqe[i]=temp;
			}
		}
	}
	for(int i=0;student_person[i].student_name[0];i++)
	{
		for(int j=0;student_person[j].student_name[0];j++)
		{
			if(student_person[i].student_english == english_seqe[j])
			{
				student_person[i].student_english_seqencing=j+1;
				break;
			}
		}
	}
}
void sum_seqencing(void)
{
	float sum_seqe[2000]={},temp=0;
	for(int i=0;student_person[i].student_name[0];i++)
	{
	     sum_seqe[i]=student_person[i].student_sum;
	}
	for(int i=0;student_person[i].student_name[0];i++)
	{
		for(int j=0;student_person[j].student_name[0];j++)
		{
			if(sum_seqe[i]>sum_seqe[j])
			{
				temp=sum_seqe[j];
				sum_seqe[j]=sum_seqe[i];
				sum_seqe[i]=temp;
			}
		}
	}
	for(int i=0;student_person[i].student_name[0];i++)
	{
		for(int j=0;student_person[j].student_name[0];j++)
		{
			if(student_person[i].student_sum == sum_seqe[j])
			{
				student_person[i].student_sum_seqencing=j+1;
				break;
			}
		}
	}
}

void student_chinese_seqencing_show(void)
{
	for(int i=0;student_person[i].student_name[0];i++)
	{
		for(int j=0;student_person[j].student_name[0];j++)
		{
			if(i+1 == student_person[j].student_chinese_seqencing)
			{
				if(student_person[i].student_sex-48>2)
				{
					continue;
				}
				else
				{
					printf("%s %g %d\n",student_person[j].student_name,
					student_person[j].student_chinese,
					student_person[j].student_chinese_seqencing);
				}
			}
		}
	}
}
void student_math_seqencing_show(void)
{
	for(int i=0;student_person[i].student_name[0];i++)
	{
		for(int j=0;student_person[j].student_name[0];j++)
		{
			if(i+1 == student_person[j].student_math_seqencing)
			{
				if(student_person[i].student_sex-48>2)
				{
					continue;
				}
				else
				{
					printf("%s %g %d\n",student_person[j].student_name,
					student_person[j].student_math,
					student_person[j].student_math_seqencing);
				}
			}
		}
	}
}
void student_english_seqencing_show(void)
{
	for(int i=0;student_person[i].student_name[0];i++)
	{
		for(int j=0;student_person[j].student_name[0];j++)
		{
			if(i+1 == student_person[j].student_english_seqencing)
			{
				if(student_person[i].student_sex-48>2)
				{
					continue;
				}
				else
				{
					printf("%s %g %d\n",student_person[j].student_name,
					student_person[j].student_english,
					student_person[j].student_english_seqencing);
				}
			}
		}
	}
}
void student_sum_seqencing_show(void)
{
	for(int i=0;student_person[i].student_name[0];i++)
	{
		for(int j=0;student_person[j].student_name[0];j++)
		{
			if(i+1 == student_person[j].student_sum_seqencing)
			{
				if(student_person[i].student_sex-48>2)
				{
					continue;
				}
				else
				{
					printf("%s %g %d\n",student_person[j].student_name,
					student_person[j].student_sum,
					student_person[j].student_sum_seqencing);
				}
			}
		}
	}
}

bool is_right_teacher ( char* str1,char* str2)
{
	for(int i=0; i < teacher_num ;i++)
	{
		if( !strcmp( str1,teacher[i].id ))
		{	
			if( !strcmp( str2,teacher[i].password ) )
			{
				return true;	
			}
			return false;
		}
	}
	return false;
}


bool is_inschool_teacher ( char* str1)
{
	for(int i=0; i < teacher_num ;i++)
	{
		if( !strcmp( str1,teacher[i].id )  && !teacher[i].del)
		{	
			return true;	
		}
	}
	return false;
}

void teacher_show_time(char* str1)      //显示老师次数
{
	for(int i=0; i < teacher_num ;i++)
	{
		if( !strcmp( str1,teacher[i].id ) )
		{	
			teacher[i].lock ++ ;
			if( teacher[i].lock <=3)
				printf("%d次错误密码！！ \n",teacher[i].lock ) ;
			sleep(2);
			return ;	
		}
	}
	printf("账号输入有错误，请重新输入\n");
	sleep(2);
	return ;
}

bool is_time_teacher_right(char* str1)  //输入次数少于３次
{
	for(int i=0; i < teacher_num ;i++)
	{
		if(!strcmp(str1,teacher[i].id))
		{	
			if( teacher[i].lock  >= 3)
				return true;
			else
			{
				return false;
			}
		}
	}
	return false;
}

