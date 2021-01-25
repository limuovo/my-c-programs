#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define N 4

struct student//����һ������ѧ����Ϣ�Ľṹ������
{
	char no[10];//ѧ��
	char name[8];//����
	char sex[5];//�Ա�
	char age[5];//����
	char note[5];//��ע
};
struct student stu[N];//����ȫ�ֱ���
void menu()//�˵�����
{
	    printf("\n");
	    printf("           * * * * * * * * * * * * * * * * \n");
		printf("          *    a.�����ѧ���Ļ�����Ϣ      *\n");
		printf("          *    b.���ļ��ж���ѧ��������Ϣ  *\n");
		printf("          *    c.ѧ��������Ϣ�������ļ�    *\n");
		printf("          *    d.ѧ��������Ϣɾ��          *\n");
		printf("          *    e.ѧ��������Ϣ�޸�          *\n");
		printf("          *    f.ѧ��������Ϣ��ѯ          *\n");
		printf("          *    g.�˳�ϵͳ                  *\n");
		printf("           * * * * * * * * * * * * * * * * \n");
		printf("\n");
        printf("������ѡ��:(a ~ g)\n");
}


void input()//ѧ��������Ϣ��¼��
{
	int i;
	int n;
	printf("���������ѧ������");
	scanf("%d",&n);
	for(i=N-n;i<N;i++)
	{
        printf("������ѧ���Ļ�����Ϣ:\n");
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
	printf("������Ϣ�Ƿ�������ȷ��\n");
	printf("\n");
	for(i=N-n;i<N;i++)
	{
		printf("%s   %s   %s   %s   %s\n",stu[i].no,stu[i].name,stu[i].sex, stu[i].age,stu[i].note);
	}
}


void save() //ѧ����Ϣ����
{
    FILE * fp;
	int i;
    fp= fopen("d:\\student.txt","w");
	if (fp == NULL)
	 {  
		printf("�ļ�������!\n");
	    exit(0);
	 }
	for(i=0;i<N;i++)//�ڴ˴��ж�������ռ���ȵ���ѧ����Ϣ�����ļ��еĸ�ʽ
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
	printf("����ɹ���\n");
}


void Delete()//ɾ��������
{
 FILE*fp;
 fp=fopen("d:\\student.txt","w");
 char number[10];
 int f,i;
 bool flag=false;
 printf("ɾ��ѧ����Ϣ:\n");
 printf("������ѧ��:\n");
 scanf("%s",number);
 for (int i =0;i<N;i++)
 {
  if (!strcmp(number,stu[i].no))
  {
	  for(f=i;f<N;f++)//����strcpy�����������е���һλԪ�ؽ���һλ���ǴӶ�ʵ��ɾ������
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
	   printf("��ѧ��������!:\n");
	   Delete();
	}
   for(i=0;i<N;i++)
   {
     fprintf(fp,"%s  %s  %s  %s  %s\n",stu[i].no,stu[i].name,stu[i].sex, stu[i].age,stu[i].note);

   }
   printf("ɾ���ɹ���\n");
   fclose(fp);
}


void search()//���Һ���
{ 

	int f;
	FILE*fp;
	fp=fopen("d:\\student.txt","rb");
    for(f=0;f<N;f++)
	{	
		fscanf(fp,"%s%s%s%s%s",stu[f].no,stu[f].name,stu[f].sex,stu[f].age,stu[f].note);
	}
	bool flag=false;//����һ��bool���ͽ����ж�
    int m;
	int i;
	printf("    1 ��ѧ�Ų�ѯ\n");
	printf("    2 ��������ѯ\n");
	printf("    3 ���Ա��ѯ\n");
	printf("    4 �������ѯ\n");
	printf("������ѡ�");
	printf("\n");
	scanf("%d",&m);
	switch(m)
	{
	case 1: 
		 char num[10];
		 printf("������ѧ��:\n");
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
				 printf("��ѧ��������.\n");
			 }
		  
		 
       break;
	   case 2:
		 printf("����������:\n");
		 char na[10];//����һ������������
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
		  printf("��ѧ��������.\n");
		 }
		break;
	   case 3: 
		 char ch[5];
		 printf("�������Ա�:\n");
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
		  printf("��ѧ��������.\n");
		 }
		break;
	   case 4: 
		 char num_age[5];
		 printf("����������:\n");
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
		  printf("��ѧ��������.\n");
		 }
		break;
	    default:
		break;
	}
	

}


void modi()//��Ϣ�޸ĺ���
{
	FILE*fp;//�����޸������ļ���ָ��
	FILE*fp1;//����ѧ����Ϣ�ļ���ָ��
	char a[7];
	char b[7];
	char c[10];
	char ch;
	int i=0;
	int f;
	bool temp=false;
    fp1=fopen("d:\\student.txt","r");
    for(f=0;f<N;f++)//���ļ��н���Ϣ�����ṹ����
	{	
		fscanf(fp1,"%s%s%s%s%s",stu[f].no,stu[f].name,stu[f].sex,stu[f].age,stu[f].note);
	}
	fclose(fp1);
	printf("�������޸�����:\n");
	scanf("%s",b);
	if((fp=fopen("d:\\1.txt","r"))==NULL)
	{
		printf("���ļ���ʧ�ܣ�");
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
	   printf("��������������������룺\n");
	   scanf("%s",b);
	 }
	 }
	 printf("��������Ҫ�޸���Ϣѧ����ѧ�ţ�\n");
	 scanf("%s",c);
     for(f=0;f<N;f++)
	 {
        if (!strcmp(c,stu[f].no))
			{
			   printf("%s   %s  %s  %s  %s\n",stu[f].no,stu[f].name,stu[f].sex,stu[f].age,stu[f].note);
			   printf("\n");
			   printf("�������µ���Ϣ��\n");
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
			printf("��ѧ�������ڣ�\n");
		}
   
}


int secretcode(char b[6])//������֤����
{
	FILE*fp;
	char c[7];
	int i=0;
	char ch;
	 if ((fp=fopen("d:\\2.txt","r"))==NULL)
	 {
		printf("���ļ�ʧ��!\n");
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
	 if (!strcmp(b,c))//�ж��ַ���b��c�Ƿ���ȣ��Ƿ���ֵ0���񷵻�ֵ1
	 {
	     return 0;
	 }
	 else
	 {
		 return 1;
	 }
	 fclose(fp);
}

void read()//���ļ��ж�ȡѧ����Ϣ
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
	printf("��ȡ�ɹ���\n");
    fclose(fp);
   

} 

   
main(int argc, char* argv[])
{   

	char a[7];//�洢�û�����ĵ�¼���� 
	char n;
	int code;
	printf("�������½���룺\n");
	
   while(1)
   {   
	   scanf("%s",a);
	   code=secretcode(a);//����û�����������ȷ��code=0; 
	   if(code!=0)
	   {
		   printf("�������");
		   printf("\n");
	   }
	   else
	   break;

   }
	   printf("**************��ӭ����༶��������ϵͳ��****************\n");
	   printf("\n\n");
       menu();//��ӡ�˵� 
	   while(scanf("%c",&n)!=EOF)//���û�ָ�� 
		{
			switch(n)
			{
			   case 'a':
				   input();//����ѧ����Ϣ 
				   menu();break;
			   case 'b':read();//��дѧ����Ϣ 
				   menu();break;
			   case 'c':save();//����ѧ����Ϣ���ļ� 
				   menu();break;
			   case 'd':Delete();//ɾ���ض�ѧ����Ϣ 
				   menu();break;
			   case 'e':modi();//�޸�ѧ����Ϣ 
				   menu();break;
			   case 'f':search();//����ѧ����Ϣ 
				   menu();break;
			   case 'g':exit(0);//��ֹ���� 
				   menu();break;

			 }
          }
	
	return 0;
}



