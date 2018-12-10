#include "iofunction.h"
#include "teacher.h"
#include "managestudent.h"
#include "student.h"
//#include "managestudent2.h"
void change_self_password(char *str)//修改密码,传入密码所在位置
{
	system("clear");
	int num=0;
	char password[20]={};
	printf("请输入修改后的密码:\n");
	get_str(password,19);
	while(0 == password[0])
	{
		printf("密码为空，请重新输入:");
		get_str(password,19);
	}
	strcpy(str,password);
	printf("修改成功---------------,按1退出\n");
	
	while(49!=getch());
	return;
}
int found_teacher_user_id(char *user_id)
{
	for(int i=0;teacher[i].name[0];i++)
	{
		if(0 == strcmp(user_id,teacher[i].id))
		{
			return i;
		}
	}
	return -1;
}
void teacher_change_self_password(char *user_id)
{
	system("clear");
	int temp=found_teacher_user_id(user_id);
	if(0 ==teacher[temp].firstload)
	{
		printf("第一次登陆,一秒后跳转到修改密码界面\n");
		sleep(1);
		change_self_password(teacher[temp].password);
		teacher[temp].firstload=1;
	}
}
void init_password(char *str)
{
	strcpy(str,"000000");
}
int id_found(char *str)
{
	int temp=0;
	for(int i=0;student_person[i].student_id[0];i++)
	{
		if(0 == strcmp(student_person[i].student_id,str))
		{
			temp=i;
		}
	}
	return temp;
}
int name_found(char *str)
{
	int temp=0;
	for(int i=0;student_person[i].student_name[0];i++)
	{
		if(0 == strcmp(student_person[i].student_name,str))
		{
			temp=i;
		}
	}
	return temp;
}
bool is_name_exist(char *name)
{
	for(int i=0;student_person[i].student_name[0];i++)
	{
		if(0 == strcmp(name,student_person[i].student_name))
		{
			return true;
		}
	}
	return false;
}
bool is_id_exist(char *id)
{
	for(int i=0;student_person[i].student_name[0];i++)
	{
		if(0 == strcmp(id,student_person[i].student_id))
		{
			return true;
		}
	}
	return false;
}
bool is_is_id_exist(char *id)
{
	int temp=id_found(id);
	if(!is_id_exist(id) || 0 == strlen(id)
		||student_person[temp].student_sex-48>2)
	{
		//printf("---%d---\n",temp);
		//printf("***%c***\n",student_person[temp].student_sex);
		printf("学号不存在或输入的学号为空，即将退出\n");
		usleep(500000);
		return false;
	}
	return true;
}
bool is_is_name_exist(char *name)
{
	int temp=name_found(name);
	if(!is_name_exist(name)||0 == strlen(name)
		||student_person[temp].student_sex-48>2)
	{
		printf("姓名不存在或姓名为空，即将退出\n");
		usleep(500000);
		return false;
	}
	return true;
}
void clear_stdin(void)
{
	stdin->_IO_read_ptr=stdin->_IO_read_end;
}

char* get_str(char* str,size_t size)
{
	if(NULL == str) return str;
	
	clear_stdin();
	fgets(str,size,stdin);

	if(size-1 == strlen(str))
	{
		if('\n' == str[size-2])
				str[size-2] = '\0';
		else
			clear_stdin();
	}
	else
		str[strlen(str)-1] = '\0';
}
bool teacher_is_student(char *str,char *str1)
{
	if(0 == strcmp(str,str1))
	{
		return true;
	}
	return false;
}
void calc_chinese_avg(void)
{
	float avg_sum=0;
	int temp=0;
	for(int i=0;student_person[i].student_name[0];i++)
	{
		if(student_person[i].student_sex-48<=2)
		{
			avg_sum+=student_person[i].student_chinese;
			temp++;
		}
	}
	avg_sum/=temp;
    student_avg_chinese = avg_sum;
	
}
void calc_math_avg(void)
{
	float avg_sum=0;
	int temp=0;
	for(int i=0;student_person[i].student_name[0];i++)
	{
		if(student_person[i].student_sex-48<=2)
		{
			avg_sum+=student_person[i].student_math;
			temp++;
		}
	}
	avg_sum/=temp;
    student_avg_math = avg_sum;
	
}
void calc_english_avg(void)
{
	float avg_sum=0;
	int temp=0;
	for(int i=0;student_person[i].student_name[0];i++)
	{
		if(student_person[i].student_sex-48<=2)
		{
			avg_sum+=student_person[i].student_english;
			temp++;
		}
	}
	avg_sum/=temp;
    student_avg_english = avg_sum;	
}

