#include "student.h"
#include "myfile.h"
#include "manager.h"
#include "teacher.h"
#include "surface.h"
#include "iofunction.h"
#include "ctrlcur.h"

Student student_person[student_num];

int main()
{
	int* student_p = malloc(sizeof(student_person));

	gettxt_base_information_teacher();
	gettxt_base_information_student();
	gettxt_grade_information_student();
	gettxt_base_information_manager();
	
	char user_id[25]={}, user_password[25]={};

	while(1)
	{	
		init_show();
		student_enter_password(user_id,user_password);
		
		int	len_id = strlen(user_id);
		
		// 学生系统部分
		if(len_id == 8)
		{
			if(! is_inschool_student(user_id) )
			{
				MOVETO(10,1);
				printf("\n无法查询此学生\n");
				sleep(1);
			}
			//判断有没有超过３次
			else if( is_time_student_right(user_id) )  
			{
				MOVETO(10,1);
				printf("请联系教师修改密码\n");
				sleep(2);
			}
			//判断密码是否正确
			else if( is_right_student ( user_id, user_password ))
			{
				//进入学生系统
				student_system(user_id);
			}
			else
			{
				//显示提示信息
				student_show_time(user_id);
			}
		}

		//老师
		else if(len_id == 6)
		{ 
		
			if(! is_inschool_teacher (user_id))
			{
				MOVETO(10,1);
				printf("\n无法查询该教师\n");
				sleep(1);
			}
	
			else if( is_time_teacher_right(user_id) )  //输入次数少于３次
			{
				MOVETO(10,1);
				printf("请联系其他管理员修改密码\n");
				sleep(2);
			}
			else if( is_right_teacher ( user_id, user_password ))
			{
				teacher_change_self_password(user_id);
		        calc_chinese_avg();
		        calc_math_avg();
		        calc_english_avg();
    			while(1)
    			{
			   		int temp=0;
				   	teacher_show();
	   				test_teacher2(user_id);           //显示教师基本信息;
			        student_manage_show();
				    temp = teacher_choice_function_one(user_id);
				    if('1' == temp)
				    {
			       	   teacher_choice_function_two();
	   				}
				    else if('2' == temp)
	   				{
		       	   	   teacher_choice_function_three();
	   				}
					else if('4' == temp)
					{
						break;
					}
  				}
			}
			else
			{
				teacher_show_time(user_id);
			}
		}
	
		//管理员
		else if(len_id == 10)
		{
			if( is_time_manager_right(user_id) )  //输入次数少于３次
			{
				MOVETO(10,1);
				printf("请联系超级管理员修改密码\n");
				sleep(2);
			}
			else if( is_right_manager ( user_id, user_password ))
			{
				chose_manager(user_id);
			}
			else
			{
				manager_show_time(user_id);
			}

		}
		
		//超级管理员			//suid: xxxx  supass: test
		else if(!strcmp(user_id,SUID) && !strcmp(user_password,SUPASS))	
		{
			chose_sumanager();
		}
		else
		{
			MOVETO(10,1);
			printf("输入错误！！！\n");
			sleep(1);
		}
	}
	return 0;
}
