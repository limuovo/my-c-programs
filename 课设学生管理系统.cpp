#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define N 4

struct student//定义一个包含学生信息的结构体数组
{
	char no[10];//学号
	char name[8];//姓名
	char sex[5];//性别
	char age[5];//年龄
	char note[5];//备注
};
struct student stu[N];//定义全局变量
void menu()//菜单函数
{
	    printf("\n");
	    printf("           * * * * * * * * * * * * * * * * \n");
		printf("          *    a.添加新学生的基本信息      *\n");
		printf("          *    b.从文件中读入学生基本信息  *\n");
		printf("          *    c.学生基本信息保存至文件    *\n");
		printf("          *    d.学生基本信息删除          *\n");
		printf("          *    e.学生基本信息修改          *\n");
		printf("          *    f.学生基本信息查询          *\n");
		printf("          *    g.退出系统                  *\n");
		printf("           * * * * * * * * * * * * * * * * \n");
		printf("\n");
        printf("请输入选项:(a ~ g)\n");
}


void input()//学生基本信息的录入
{
	int i;
	int n;
	printf("请输入添加学生数：");
	scanf("%d",&n);
	for(i=N-n;i<N;i++)
	{
        printf("请输入学生的基本信息:\n");
		printf("no:\n");
        scanf("%s",stu[i].no);
		printf("name:\n");
		scanf("%s",stu[i].name);
		printf("sex:\n");
		scanf("%s",stu[i].sex);
		printf("age:\n");
		scanf("%s",stu[i].age);
		printf("note:\n");
		scanf("%s",stu[i].note);
	}
	printf("\n");
	printf("请检查信息是否输入正确！\n");
	printf("\n");
	for(i=N-n;i<N;i++)
	{
		printf("%s   %s   %s   %s   %s\n",stu[i].no,stu[i].name,stu[i].sex, stu[i].age,stu[i].note);
	}
}


void save() //学生信息保存
{
    FILE * fp;
	int i;
    fp= fopen("d:\\student.txt","w");
	if (fp == NULL)
	 {  
		printf("文件不存在!\n");
	    exit(0);
	 }
	for(i=0;i<N;i++)//在此处判断姓名所占长度调整学生信息存入文件中的格式
	{
		if(strlen(stu[i].name)==4)
        {
			fprintf(fp,"%s    %s   %s  %s  %s\n",stu[i].no,stu[i].name,stu[i].sex, stu[i].age,stu[i].note);
		}
        else if(strlen(stu[i].name)==6)
		{
            fprintf(fp,"%s  %s   %s  %s  %s\n",stu[i].no,stu[i].name,stu[i].sex, stu[i].age,stu[i].note);
		}
	}
	fclose(fp);
    fflush(fp);
	printf("保存成功！\n");
}


void Delete()//删除函数；
{
 FILE*fp;
 fp=fopen("d:\\student.txt","w");
 char number[10];
 int f,i;
 bool flag=false;
 printf("删除学生信息:\n");
 printf("请输入学号:\n");
 scanf("%s",number);
 for (int i =0;i<N;i++)
 {
  if (!strcmp(number,stu[i].no))
  {
	  for(f=i;f<N;f++)//调用strcpy函数令数组中的下一位元素将上一位覆盖从而实现删除功能
	  {
		   strcpy(stu[f].name,stu[f+1].name);
		   strcpy(stu[f].note,stu[f+1].note);
		   strcpy(stu[f].no,stu[f+1].no);
		   strcpy(stu[f].sex,stu[f+1].sex);
		   strcpy(stu[f].age,stu[f+1].age);
	  } 
	  flag=true;
  }
 
 }
   if(!flag)
	{
	   printf("该学生不存在!:\n");
	   Delete();
	}
   for(i=0;i<N;i++)
   {
     fprintf(fp,"%s  %s  %s  %s  %s\n",stu[i].no,stu[i].name,stu[i].sex, stu[i].age,stu[i].note);

   }
   printf("删除成功！\n");
   fclose(fp);
}


void search()//查找函数
{ 

	int f;
	FILE*fp;
	fp=fopen("d:\\student.txt","rb");
    for(f=0;f<N;f++)
	{	
		fscanf(fp,"%s%s%s%s%s",stu[f].no,stu[f].name,stu[f].sex,stu[f].age,stu[f].note);
	}
	bool flag=false;//定义一个bool类型进行判断
    int m;
	int i;
	printf("    1 按学号查询\n");
	printf("    2 按姓名查询\n");
	printf("    3 按性别查询\n");
	printf("    4 按年龄查询\n");
	printf("请输入选项：");
	printf("\n");
	scanf("%d",&m);
	switch(m)
	{
	case 1: 
		 char num[10];
		 printf("请输入学号:\n");
		 scanf("%s",num);
		 for ( i=0;i<N;i++)
		 {
		    if (!strcmp(num,stu[i].no))
			{
			   if(strlen(stu[i].name)==4)
			   {
				 printf("%s    %s  %s  %s  %s\n",stu[i].no,stu[i].name,stu[i].sex, stu[i].age,stu[i].note);
			   }
		    	else if(strlen(stu[i].name)==6)
				{
				 printf("%s  %s  %s  %s  %s\n",stu[i].no,stu[i].name,stu[i].sex, stu[i].age,stu[i].note);	
				}
			   flag=true;
			}
		
		 }
		    if(!flag)
			 { 
				 printf("该学生不存在.\n");
			 }
		  
		 
       break;
	   case 2:
		 printf("请输入姓名:\n");
		 char na[10];//定义一个姓名的数组
		 scanf("%s",na);
		 for ( i =0;i<N;i++)
		 {
		  if (!strcmp(na,stu[i].name))
		  {
		   if(strlen(stu[i].name)==4)
		   { 
		      printf("%s    %s  %s  %s  %s\n",stu[i].no,stu[i].name,stu[i].sex, stu[i].age,stu[i].note);
		   }
           else if(strlen(stu[i].name)==6)
		   {
              printf("%s  %s  %s  %s  %s\n",stu[i].no,stu[i].name,stu[i].sex, stu[i].age,stu[i].note);	
		   }
		   flag = true;
		  }
		 }
		 if (!flag)
		 {
		  printf("该学生不存在.\n");
		 }
		break;
	   case 3: 
		 char ch[5];
		 printf("请输入性别:\n");
	      scanf("%s",ch);
		  for(i=0;i<N;i++)
		  { 
		  if (!strcmp(ch,stu[i].sex))
		  {
		     if(strlen(stu[i].name)==4)
			 {
			   printf("%s    %s  %s  %s  %s\n",stu[i].no,stu[i].name,stu[i].sex, stu[i].age,stu[i].note);
			 }
            else if(strlen(stu[i].name)==6)
			 {
               printf("%s  %s  %s  %s  %s\n",stu[i].no,stu[i].name,stu[i].sex, stu[i].age,stu[i].note);	
			 }
		     flag = true;
		  }
		  }
		 if (!flag)
		 {
		  printf("该学生不存在.\n");
		 }
		break;
	   case 4: 
		 char num_age[5];
		 printf("请输入年龄:\n");
		 scanf("%s",num_age);
		 for ( i =0;i<N;i++)
		 {
		  if (!strcmp(num_age,stu[i].age))
		  {
		    if(strlen(stu[i].name)==4)
			{
	 		   printf("%s    %s  %s  %s  %s\n",stu[i].no,stu[i].name,stu[i].sex, stu[i].age,stu[i].note);
			}
           else if(strlen(stu[i].name)==6)
			{
               printf("%s  %s  %s  %s  %s\n",stu[i].no,stu[i].name,stu[i].sex, stu[i].age,stu[i].note);	
			}
		    flag = true;
		  }
		 }
		 if (!flag)
		 {
		  printf("该学生不存在.\n");
		 }
		break;
	    default:
		break;
	}
	

}


void modi()//信息修改函数
{
	FILE*fp;//定义修改密码文件的指针
	FILE*fp1;//定义学生信息文件的指针
	char a[7];
	char b[7];
	char c[10];
	char ch;
	int i=0;
	int f;
	bool temp=false;
    fp1=fopen("d:\\student.txt","r");
    for(f=0;f<N;f++)//从文件中将信息读到结构体中
	{	
		fscanf(fp1,"%s%s%s%s%s",stu[f].no,stu[f].name,stu[f].sex,stu[f].age,stu[f].note);
	}
	fclose(fp1);
	printf("请输入修改密码:\n");
	scanf("%s",b);
	if((fp=fopen("d:\\1.txt","r"))==NULL)
	{
		printf("打开文件夹失败！");
		exit(0);
	}
	ch=fgetc(fp);
	while(ch!=EOF&&i<6)
	{
		 a[i] = ch;
		 ch=fgetc(fp);
	     i++;
            
	 }
	 a[6] = '\0'; 
	 fclose(fp);
     while(1)
	 {
	 if (!strcmp(a,b))
	 {
	   break;
	 }
	 else
	 {
	   printf("密码错误！请重新输入密码：\n");
	   scanf("%s",b);
	 }
	 }
	 printf("请输入需要修改信息学生的学号：\n");
	 scanf("%s",c);
     for(f=0;f<N;f++)
	 {
        if (!strcmp(c,stu[f].no))
			{
			   printf("%s   %s  %s  %s  %s\n",stu[f].no,stu[f].name,stu[f].sex,stu[f].age,stu[f].note);
			   printf("\n");
			   printf("请输入新的信息：\n");
               printf("no:\n");
			   scanf("%s",stu[f].no);
			   printf("name:\n");
			   scanf("%s",stu[f].name);
			   printf("sex:\n");
			   scanf("%s",stu[f].sex);
			   printf("age:\n");
			   scanf("%s",stu[f].age);
			   printf("note:\n");
			   scanf("%s",stu[f].note);
			   temp=true;
			   break;
               
               
			}
		
	 }
	   if(!temp)
		{
			printf("该学生不存在！\n");
		}
   
}


int secretcode(char b[6])//密码验证函数
{
	FILE*fp;
	char c[7];
	int i=0;
	char ch;
	 if ((fp=fopen("d:\\2.txt","r"))==NULL)
	 {
		printf("打开文件失败!\n");
		exit(0);
	 }

	ch=fgetc(fp);
	while (ch!=EOF&&i<6)
	 {
	        c[i] = ch;
			ch=fgetc(fp);
	        i++;
            
	 }
	 c[6] = '\0';
	 if (!strcmp(b,c))//判断字符串b和c是否相等，是返回值0，否返回值1
	 {
	     return 0;
	 }
	 else
	 {
		 return 1;
	 }
	 fclose(fp);
}

void read()//从文件中读取学生信息
{   
	int i;
	FILE*fp;
	fp=fopen("d:\\student.txt","r");
    for(i=0;i<N;i++)
	{	
		fscanf(fp,"%s%s%s%s%s",stu[i].no,stu[i].name,stu[i].sex,stu[i].age,stu[i].note);
	  	if(strlen(stu[i].name)==4)
        {
			printf("%s    %s  %s  %s  %s\n",stu[i].no,stu[i].name,stu[i].sex, stu[i].age,stu[i].note);
		}
        else if(strlen(stu[i].name)==6)
		{
            printf("%s  %s  %s  %s  %s\n",stu[i].no,stu[i].name,stu[i].sex, stu[i].age,stu[i].note);	
		}
	 
	}		
	printf("\n");
	printf("读取成功！\n");
    fclose(fp);
   

} 

   
main(int argc, char* argv[])
{   

	char a[7];//存储用户输入的登录密码 
	char n;
	int code;
	printf("请输入登陆密码：\n");
	
   while(1)
   {   
	   scanf("%s",a);
	   code=secretcode(a);//如果用户输入密码正确，code=0; 
	   if(code!=0)
	   {
		   printf("密码错误！");
		   printf("\n");
	   }
	   else
	   break;

   }
	   printf("**************欢迎进入班级档案管理系统！****************\n");
	   printf("\n\n");
       menu();//打印菜单 
	   while(scanf("%c",&n)!=EOF)//读用户指令 
		{
			switch(n)
			{
			   case 'a':
				   input();//输入学生信息 
				   menu();break;
			   case 'b':read();//读写学生信息 
				   menu();break;
			   case 'c':save();//保存学生信息到文件 
				   menu();break;
			   case 'd':Delete();//删除特定学生信息 
				   menu();break;
			   case 'e':modi();//修改学生信息 
				   menu();break;
			   case 'f':search();//查找学生信息 
				   menu();break;
			   case 'g':exit(0);//终止程序 
				   menu();break;

			 }
          }
	
	return 0;
}



