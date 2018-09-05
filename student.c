#include<stdio.h>
#include<stdlib.h>
typedef struct student
{
	int sno;
	char name[20];
	int sex;
	int class;
	float score;
	struct student* next;

}stu;
stu* head;
void PrintMenu();
void AddNode(stu* q);
void InIt();
void Reserch();
void ReadStudent();
void WriteStudent();
void AddStudent();
void BrowseStudent();
void DeleteStudent();
void UpdateStudent();

int main()
{
	int n;
	InIt();
	PrintMenu();
	scanf("%d",&n);
	while(n!=0)
	{
	switch(n)
	{
		case 1:
			AddStudent();
			break;
		case 2:
			Reserch();
			break;
		case 3:
			ReadStudent();
			break;
		case 4:
			WriteStudent();
			break;
		case 5:
			BrowseStudent();
			break;
		case 6:
			DeleteStudent();
			break;
		case 7:
			UpdateStudent();
			break;
		default:
			printf("ERROR");
	}
	PrintMenu();
	scanf("%d",&n);
	}
	return 0;
}
void PrintMenu()
{
	printf("************************\n");
	printf("1.增加学生   2.查询学生\n");
	printf("3.读取信息   4.保存信息\n");
	printf("5.浏览信息   6.删除信息\n");
	printf("7.更新信息   0.退出系统\n");
	printf("************************\n");
}
void AddNode(stu* q)
{
	stu* p=head;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	p->next=q;
	q->next=NULL;
//	q->next=head->next;
//	head->next=q;

}
void InIt()
{
	head=(stu*)malloc(sizeof(stu));
	head->next=NULL;

}
void Reserch()
{
	int n;
	int flag=0;
	stu* q=head->next;
	printf("请输入要查找的学号：");
	scanf("%d",&n);
	while(q!=NULL)
	{
		if(q->sno==n)
		{
			flag=1;
			break;
		}
		q=q->next;
	}
	if(1==flag)
	{
		printf("学号：%d \n""姓名：%s \n""性别：%d \n""班级：%d \n""成绩：%.0f\n", q->sno,q->name,q->sex,q->class,q->score);
	}
	else
		printf("查无此人！\n");
}
void ReadStudent()
{
	FILE* fp=fopen("data","r");
	if(NULL==fp)
	{
		perror("fopen");
		exit(1);
	}
	char c;
	while(1)
	{
		stu* q;
		q=(stu*)malloc(sizeof(stu));
		q->next=NULL;
	
	    fscanf(fp,"%d""%s""%d""%d""%f",&(q->sno),q->name,&(q->sex),&(q->class),&(q->score));
		if(feof(fp)!=0)
			break;
		AddNode(q);
	}
	fclose(fp);
	printf("读取成功!\n");
}
void WriteStudent()
{
	FILE* fp=fopen("data","w");
	stu* q=head->next;
	while(q!=NULL)
	{
		fprintf(fp,"%d ""%s ""%d ""%d ""%f\n", q->sno,q->name,q->sex,q->class,q->score);
		q=q->next;
	}
	fclose(fp);
	printf("保存成功！\n");

}
void AddStudent()
{
	stu* q;
	q=(stu*)malloc(sizeof(stu));
	printf("请输入学号：");
		scanf("%d",&(q->sno));
	printf("请输入姓名：");
		scanf("%s",q->name);
	printf("请输入性别：");
		scanf("%d",&(q->sex));
	printf("请输入班级：");
		scanf("%d",&(q->class));
	printf("请输入分数：");
		scanf("%f",&(q->score));

	AddNode(q);
	printf("添加成功！\n");
}
void BrowseStudent()
{
	int i=1;
	stu* q=head->next;
	while(q!=NULL)
	{
		printf("第%d个学生的信息为：\n",i);
		printf("学号：%d \n""姓名：%s \n""性别：%d \n""班级：%d \n""成绩：%.0f\n", q->sno,q->name,q->sex,q->class,q->score);
		i++;
		q=q->next;
	}
}
void DeleteStudent()
{
	stu* q=head->next;
	stu* p=head;
	int n;
	int flag=0;
	printf("请输入想要删除的学生学号：\n");
	scanf("%d",&n);
	while(q!=NULL)
	{
		if(q->sno==n)
		{
			flag=1;
			p->next=q->next;
			free(q);
			break;
		}
		p=q;
		q=q->next;
	}
	if(flag==1)
	printf("删除完成！\n");
	else printf("无此学生！\n");
}
void UpdateStudent()
{
	printf("请输入要更新学生的学号：\n");
	int n;
	int flag=0;
	scanf("%d",&n);
	stu* q=head->next;

	while(q!=NULL)
	{
		if(q->sno==n)
			flag=1;
			break;
		q=q->next;
	}
	if(1==flag)
	{
		q->sno=n;
		printf("请输入新的班级：\n");
		scanf("%d",&n);
		q->class=n;
		printf("请输入新的成绩：\n");
		scanf("%d",&n);
		q->score=n;
		printf("更新成功！\n");
	}
	else
		printf("无此学生！\n");
}
