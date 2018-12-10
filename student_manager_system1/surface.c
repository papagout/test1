#include "surface.h"
#include "teacher.h"
void teacher_show(void)
{
	system("clear");
	printf("--------------教师系统--------------\n");
	printf("姓名   ");
	printf("年龄   ");
	printf("性别   ");
	printf("工号       ");
	printf("工龄       ");
	printf("\n");
}
void student_manage_show(void)
{
	printf("*********************\n");
	printf(">> 1进入学生信息管理\n");
	printf(">> 2进入学生成绩管理\n");
	printf(">> 3修改密码\n");
	printf(">> 4退出教师界面\n");
	printf("******************\n");
}
void show_student_informaton_news(void)
{
	system("clear");
	printf("----------学生信息管理-----------\n");
	printf("|        ~0添加多个学生~        |\n");
	printf("|        ~1添加学生~            |\n");
	printf("|        ~2删除学生~            |\n");
	printf("|      ~3修改学生信息~          |\n");
	printf("|      ~4重置学生密码~          |\n");
	printf("|      ~5解锁学生帐号~          |\n");
	printf("|      ~6查询学生信息~          |\n");
	printf("|     ~7显示所有在读生~         |\n");
	printf("|     ~8显示所有退学生~         |\n");
	printf("|         ~9来返回~             |\n");
	printf("---------------------------------\n");

}
void show_stdent_score_news(void)
{
	system("clear");
	printf("------------学生成绩管理------------\n");
	printf("|         1添加学生成绩            |\n");
	printf("|         2添加多个学生成绩        |\n");
	printf("|         3修改学生                |\n");
	printf("|         4查询学生成绩            |\n");
	printf("|         5显示学生成绩排名        |\n");
	printf("|         9返回                    |\n");
	printf("------------------------------------\n");
  
}
void show_teacher_password(void)
{
	system("clear");
	printf("确认要修改按1，按2返回\n");
}
