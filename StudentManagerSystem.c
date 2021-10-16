#include <stdio.h>
#include <stdlib.h>
#define N 60			//定义的一个班最大人数
struct student//结构体
{
	long ID;		//长整型	学号
	char Name[10];	//浮点型	 姓名
	char Sex;		//浮点型	性别
	int Math;		//整型		数学成绩
	int English;	//整型		英语成绩
	int Clanguage;	//整型		C语言成绩
	int LA;			//整型		线性代数成绩
	int PE;			//整型		体育成绩
	float Average;	//实型		平均分
	int Sum;		//整型		总分
}stu[N];
void writestudent();//第一个功能：录入
void inturn();		//第二个功能：排序
void change();		//第三个功能：修改
void insert();		//第四个功能：插入
void del();			//第五个功能：删除
void search();		//第六个功能：查询
void menu()			//主菜单函数
{
	int i;
	char scan;
	for (i=0;i<5;i++)
	{
		printf("\n");
	}
	while(1)
	{

		printf("		==============================欢   迎   使   用   本   系   统============================\n");
		printf("		|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
		printf("		|*--------------------------------------------------------------------------------------*|\n");
		printf("		|*++++++++++++++++++++++++++++++《1》  录  入  学  生  成  绩+++++++++++++++++++++++++++*|\n");
		printf("		|*--------------------------------------------------------------------------------------*|\n");
		printf("		|*++++++++++++++++++++++++++++++《2》  将  学  生  成  绩  排  序+++++++++++++++++++++++*|\n");
		printf("		|*--------------------------------------------------------------------------------------*|\n");
		printf("		|*++++++++++++++++++++++++++++++《3》  插  入  学  生  成  绩+++++++++++++++++++++++++++*|\n");
		printf("		|*--------------------------------------------------------------------------------------*|\n");
		printf("		|*++++++++++++++++++++++++++++++《4》  修  改  学  生  成  绩+++++++++++++++++++++++++++*|\n");
		printf("		|*--------------------------------------------------------------------------------------*|\n");
		printf("		|*++++++++++++++++++++++++++++++《5》  删  除  学  生  成  绩+++++++++++++++++++++++++++*|\n");
		printf("		|*--------------------------------------------------------------------------------------*|\n");
		printf("		|*++++++++++++++++++++++++++++++《6》  查  询  学  生  成  绩+++++++++++++++++++++++++++*|\n");
		printf("		|*--------------------------------------------------------------------------------------*|\n");
		printf("		|*++++++++++++++++++++++++++++++《0》  退  出  系  统+++++++++++++++++++++++++++++++++++*|\n");
		printf("		|*--------------------------------------------------------------------------------------*|\n");
		printf("		|*                                                                                      *|\n");
		printf("		|*￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥*|\n");
		printf("		|*                                                                                      *|\n");
		printf("		|*￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥*|\n");
		printf("		|*                                                                                      *|\n");
		printf("		|*--------------------------------------学生成绩管理系统v1.4----------------------------*|\n");
		printf("		|*=========================本系统由兰州城市学院软件182班第11组完成======================*|\n");
		printf("		|*============================================================ 组长:刘鹏飞   组员:卢碧玉*|\n");         
		printf("		|________________________________________________________________________________________|\n");
		printf("\n");
		printf("\n");
		printf("		                                                                  请输入指令：");
		scanf("%s",&scan);
			if (scan=='1')//录入学生成绩
			{
				system("cls");
				writestudent();
				break;
			}
			if (scan=='2')//将学生成绩排序
			{
				system("cls");
				inturn();				
				break;
			}
			if (scan=='3')//插入学生成绩（增加）
			{
				system("cls");
				insert();
				break;
			}
			if (scan=='4')//修改学生成绩
			{
				system("cls");
				change();
				break;
			}
			if (scan=='5')//删除学生成绩
			{
				system("cls");
				del();
				break;
			}
			if (scan=='6')//查询学生成绩
			{
				system("cls");
				search();
				break;
			}
			if (scan=='0')//退出系统
			{
				printf("\n		                                 非常感谢您使用本系统，再见！\n");
				exit (0);
				break;
			}
			else 
			{
				system("cls");
				printf("\n");
				printf("		                                                    输入错误！！请重新输入命令");
				printf("		                                                                  请输入指令：");
				scanf("%s",&scan);
				printf("\n\n\n");
			}
	}
	menu();
}
void writestudent()//第一个功能：录入
{
	char op;
	int i;
	struct student st;
	for (i=0;i<5;i++)
	{
		printf("\n");
	}
	printf("\t\t|==============================================================================|\n");
	printf("\t\t|==========================请 选 择 要 执 行 的 命 令==========================|\n");
	printf("\t\t|******************************************************************************|\n");
	printf("\t\t|                                                                              |\n");
	printf("\t\t|=============================《1》录  入  成  绩==============================|\n");
	printf("\t\t|******************************************************************************|\n");
	printf("\t\t|                                                                              |\n");
	printf("\t\t|=============================《2》显  示  数  据==============================|\n");
	printf("\t\t|******************************************************************************|\n");
	printf("\t\t|                                                                              |\n");
	printf("\t\t|=============================《3》统  计  数  据==============================|\n");
	printf("\t\t|******************************************************************************|\n");
	printf("\t\t|                                                                              |\n");
	printf("\t\t|=============================《0》返 回 主 菜 单==============================|\n");
	printf("\t\t|******************************************************************************|\n");
	printf("\t\t|                                                                              |\n");
	printf("\t\t|==============================================================================|\n");
	printf("\t\t                                                                                \n");
	printf("\t\t                                                                                \n");
	printf("请输入要执行命令的序号：");
	scanf("%s",&op);
	if (op=='1')//第一个功能里的小功能：录入
	{
		FILE*fp=NULL;
		FILE *fn=NULL;
		int n;
		fp=fopen("D:\\information.txt","a+");
		fn=fopen("D:\\txtinformation.txt","a+");
		printf("		                                                                  输入录入学生数：");
		scanf("%d",&n);
		if (fp==NULL)
		{
			printf("打开文件失败!\n");
			exit(0);
			menu();
		}
		if (fn==NULL)
		{
			printf("打开文件失败!\n");
			exit(0);
			menu();
		}
		for (i=0;i<n;i++)
		{
			
			printf("学号：");
			scanf("%ld",&stu[i].ID);
			printf("姓名：");
			scanf("%s",&stu[i].Name);
			printf("性别：");
			scanf("%s",&stu[i].Sex);
			printf("数学成绩：");
			scanf("%d",&stu[i].Math);
			printf("英语成绩：");
			scanf("%d",&stu[i].English);
			printf("C语言成绩：");
			scanf("%d",&stu[i].Clanguage);
			printf("线性代数成绩:");
			scanf("%d",&stu[i].LA);
			printf("体育成绩：");
			scanf("%d",&stu[i].PE);
			stu[i].Sum=stu[i].Math+stu[i].English+stu[i].Clanguage+stu[i].LA+stu[i].PE;
			printf("总分为：%d\n",stu[i].Sum);
			stu[i].Average=(float)(stu[i].Math+stu[i].English+stu[i].Clanguage+stu[i].LA+stu[i].PE)/(float)5;
			printf("平均分为：%.2f\n",stu[i].Average);
		}
		for (i=0;i<n;i++)
		{
			fprintf(fn,"\t    %ld",stu[i].ID);
			fprintf(fn," %s",stu[i].Name);
			fprintf(fn," %c",stu[i].Sex);
			fprintf(fn," %d",stu[i].Math);
			fprintf(fn," %d",stu[i].English);
			fprintf(fn," %d",stu[i].Clanguage);
			fprintf(fn," %d",stu[i].LA);
			fprintf(fn," %d",stu[i].PE);
			fprintf(fn," %d",stu[i].Sum);
			fprintf(fn," %f\n",stu[i].Average);
		}
		fclose(fn);
		fwrite(stu,sizeof(struct student),n,fp);
		fclose(fp);
		printf("数据已保存在D:\\txtinformation.txt中\n");
		system("pause");
		system("cls");
		writestudent();
	}
	if(op=='2')//第一个功能里的小功能：显示
	{
		FILE *fo=NULL;
		fo=fopen("D:\\information.txt","r");
		if (fo==NULL)
		{
			printf("打开文件失败！\n");
			exit(0);
			menu();
		}
		else
		{
			printf("\t   学号 姓名 性 数 英 C  线 体 总分 平均分\n");
		}
		while (!feof(fo))
		{
			fread(&st,sizeof(struct student),1,fo);
			if(!feof(fo))
			printf("\t    %ld %s %c %d %d %d %d %d %d %f\n",st.ID,st.Name,st.Sex,st.Math,st.English,st.Clanguage,st.LA,st.PE,st.Sum,st.Average);
		}
		system("pause");
		system("cls");
		fclose(fo);
		writestudent();
	}
	if (op=='3')//第一个功能里的小功能：统计
	{
		int a=0,b=0,c=0,d=0,e=0,m=0,g=0;
		int Math[5]={0,0,0,0,0},English[5]={0,0,0,0,0},Clanguage[5]={0,0,0,0,0},LA[5]={0,0,0,0,0},PE[2]={0,0};
		struct student tem[N];
		FILE *fp=NULL;
		if ((fp=fopen("D:\\information.txt","r"))==NULL)
		{
			printf("打开文件失败！\n");
			exit(0);
		}
		system("cls");

		while (!feof(fp))
		{
			fread(&tem[g],sizeof(struct student),1,fp);
			if(!feof(fp))
			{
				printf("%s ",tem[g].Name);
				g++;
			}
		}
		printf("共%d名学生\n",g);
		printf("\n");
		for (i=0;i<g;i++)
		{
			if (90<=tem[i].Math&&tem[i].Math<100)
			{
				Math[4]++;
			}
			if (80<=tem[i].Math&&tem[i].Math<90)
			{
				Math[3]++;
			}
			if (70<=tem[i].Math&&tem[i].Math<80)
			{
				Math[2]++;
			}
			if (60<=tem[i].Math&&tem[i].Math<70)
			{
				Math[1]++;
			}
			if (tem[i].Math<60)
			{
				Math[0]++;
			}
			if(90<=tem[i].English&&tem[i].English<100)
			{
				English[4]++;
			}
			if(80<=tem[i].English&&tem[i].English<90)
			{
				English[3]++;
			}
			if(70<=tem[i].English&&tem[i].English<80)
			{
				English[2]++;
			}
			if(60<=tem[i].English&&tem[i].English<70)
			{
				English[1]++;
			}
			if(tem[i].English<60)
			{
				English[0]++;
			}
			if(90<tem[i].English&&tem[i].English<100)
            {
				Clanguage[4]++;
			}
			if(80<=tem[i].Clanguage&&tem[i].Clanguage<90)
			{
				Clanguage[3]++;
			}
			if(70<=tem[i].Clanguage&&tem[i].Clanguage<80)
			{
				Clanguage[2]++;
			}
			if(60<=tem[i].Clanguage&&tem[i].Clanguage<70)
			{
				Clanguage[1]++;
			}
			if(tem[i].Clanguage<60)
			{
				Clanguage[0]++;
			}
			if(90<tem[i].LA&&tem[i].LA<100)
            {
				LA[4]++;
			}
			if(80<=tem[i].LA&&tem[i].LA<90)
			{
				LA[3]++;
			}
			if(70<=tem[i].LA&&tem[i].LA<80)
			{
				LA[2]++;
			}
			if(60<=tem[i].LA&&tem[i].LA<70)
			{
				LA[1]++;
			}
			if(tem[i].LA<60)
			{
				LA[0]++;
            }
			if(tem[i].PE>=60)
			{
				PE[1]++;
			}
			if(tem[i].PE<60)
			{
				PE[0]++;
            }
			if (tem[i].Sum>=300)
			{
				m++;
			}
			if (tem[i].Math>=60)
			{
				a++;
			}
			if (tem[i].English>=60)
			{
				b++;
			}
			if (tem[i].Clanguage>=60)
			{
				c++;
			}
			if (tem[i].LA>=60)
			{
				d++;
			}
			if (tem[i].PE>=60)
			{
				e++;
			}
		}
		printf("总分超过300分的人数为:%d",m);
		printf("\n");
		printf("数学成绩超过60分的人数为:%d",a);
		printf("\n");
		printf("英语成绩超过60分的人数为:%d",b);
		printf("\n");
		printf("C语言成绩超过60分的人数为:%d",c);
		printf("\n");
		printf("线代成绩超过60分的人数为:%d",d);
		printf("\n");
		printf("体育成绩超过60分的人数为:%d",e);
		printf("\n");
		printf("数学成绩不及格人数:%d   英语成绩不及格人数:%d   C语言成绩不及格人数:%d   线性代数成绩不及格人数:%d\n",Math[0],English[0],Clanguage[0],LA[0]);
		printf("数学在60至70的人数:%d   英语在60至70的人数:%d   C语言在60至70的人数:%d   线性代数在60至70的人数:%d\n",Math[1],English[1],Clanguage[1],LA[1]);
		printf("数学在70至80的人数:%d   英语在70至80的人数:%d   C语言在70至80的人数:%d   线性代数在70至80的人数:%d\n",Math[2],English[2],Clanguage[2],LA[2]);
		printf("数学在80至90的人数:%d   英语在80至90的人数:%d   C语言在80至90的人数:%d   线性代数在80至90的人数:%d\n",Math[3],English[3],Clanguage[3],LA[3]);
		printf("数学在90至100的人数:%d  英语在90至100的人数:%d  C语言在90至100的人数:%d  线性代数在90至100的人数:%d\n",Math[4],English[4],Clanguage[4],LA[4]);
		printf("体育成绩及格的人数为:%d\t",PE[1]);
		printf("体育成绩不及格的人数为:%d\n",PE[0]);
		fclose(fp);
		system("pause");
		system("cls");
		writestudent();
	}
	if (op=='0')//第一个功能里的小功能：返回主菜单
	{
		system("cls");
		menu();
	}
	else 
	{
		printf("********输入错误！********\n");
		printf("请重新输入:");
		scanf("%s",&op);
		printf("\n\n\n");
	}
}
void inturn()//第二个功能：排序

{	
	struct student st;
	char op;
	int i,exchange;
	for (i=0;i<5;i++)
	{
		printf("\n");
	}
	printf("\t\t|==============================================================================|\n");
	printf("\t\t|==========================请 选 择 要 执 行 的 命 令==========================|\n");
	printf("\t\t|******************************************************************************|\n");
	printf("\t\t|                                                                              |\n");
	printf("\t\t|==========================《1》按 照 学 号 排（升）序=========================|\n");
	printf("\t\t|******************************************************************************|\n");
	printf("\t\t|                                                                              |\n");
	printf("\t\t|==========================《2》显 示 学 号 排（升）序=========================|\n");
	printf("\t\t|******************************************************************************|\n");
	printf("\t\t|                                                                              |\n");
	printf("\t\t|==========================《3》按 照 总 分 排（降）序=========================|\n");
	printf("\t\t|******************************************************************************|\n");
	printf("\t\t|                                                                              |\n");
	printf("\t\t|==========================《4》显 示 总 分 排（降）序=========================|\n");
	printf("\t\t|******************************************************************************|\n");
	printf("\t\t|                                                                              |\n");
	printf("\t\t|==============================《0》返 回 主 菜 单=============================|\n");
	printf("\t\t|******************************************************************************|\n");
	printf("\t\t|                                                                              |\n");
	printf("\t\t|==============================================================================|\n");
	printf("\t\t                                                                                \n");
	printf("\t\t                                                                                \n");
	printf("请输入要执行命令的序号：");
	scanf("%s",&op);
	if (op=='1')//第二个功能里的小功能：按照学号升序排序
	{
		FILE *fp,*fl,*fn;
		struct student tem[N];
		struct student temp;
		int g=0,i,j;
		fp=fopen("D:\\information.txt","r");
		fl=fopen("D:\\idsort.txt","w");
		fn=fopen("D:\\txtidsort.txt","w");
		if (fp==NULL)
		{
			printf("打开文件失败！\n");
			exit(0);
		}
		if (fl==NULL)
		{
			printf("打开文件失败！\n");
			exit(0);
		}
		if (fn==NULL)
		{
			printf("打开文件失败！\n");
			exit(0);
		}
		while (!feof(fp))
		{
			fread(&tem[g],sizeof(struct student),1,fp);
			if(!feof(fp))
			{
				g++;
			}
		}
		for (i=0;i<g-1;i++)
		{
			exchange=0;
			for (j=0;j<g-1-i;j++)
			{
				if (tem[j+1].ID<tem[j].ID)
				{
					temp=tem[j];
					tem[j]=tem[j+1];
					tem[j+1]=temp;
					exchange=1;
				}
			}
			if (!exchange)
			{
				break;
			}
		}
		printf("\n");
		printf("排序已经完成！");
		for (i=0;i<g;i++)
		{
			fprintf(fn,"\t    %ld",tem[i].ID);
			fprintf(fn," %s",tem[i].Name);
			fprintf(fn," %c",tem[i].Sex);
			fprintf(fn," %d",tem[i].Math);
			fprintf(fn," %d",tem[i].English);
			fprintf(fn," %d",tem[i].Clanguage);
			fprintf(fn," %d",tem[i].LA);
			fprintf(fn," %d",tem[i].PE);
			fprintf(fn," %d",tem[i].Sum);
			fprintf(fn," %f\n",tem[i].Average);
		}
		fclose(fn);
		fwrite(tem,sizeof(struct student),g,fl);
		fclose(fp);
		fclose(fl);
		printf("排序后的数据已经以二进制格式保存在D:\\idsort.txt中！！请查看");
		system("pause");
		system("cls");
		inturn();
	}
	if (op=='2')//第二个功能里的小功能：显示
	{
		FILE *fo=NULL;
		fo=fopen("D:\\idsort.txt","r");
		if (fo==NULL)
		{
			printf("打开文件失败！\n");
			exit(0);
			menu();
		}
		else
		{
			printf("\t   学号 姓名 性 数 英 C  线 体 总分 平均分\n");
		}
		while (!feof(fo))
		{
			fread(&st,sizeof(struct student),1,fo);
			if(!feof(fo))
			printf("\t    %ld %s %c %d %d %d %d %d %d %f\n",st.ID,st.Name,st.Sex,st.Math,st.English,st.Clanguage,st.LA,st.PE,st.Sum,st.Average);

		}
		system("pause");
		system("cls");
		fclose(fo);
		inturn();
	}
	if (op=='3')//第二个功能里的小功能：按照总分降序排序
	{
		FILE *fp,*fl,*fn;
		struct student tem[60];
		struct student temp;
		int g=0,i,j;
		fp=fopen("D:\\information.txt","r");
		fl=fopen("D:\\sumsort.txt","w");
		fn=fopen("D:\\txtsumsort.txt","w");
		if (fp==NULL)
		{
			printf("打开文件失败！\n");
			exit(0);
		}
		if (fl==NULL)
		{
			printf("打开文件失败！\n");
			exit(0);
		}
		if (fn==NULL)
		{
			printf("打开文件失败！\n");
		}
		while (!feof(fp))
		{
			fread(&tem[g],sizeof(struct student),1,fp);
			if(!feof(fp))
			{
				g++;
			}
		}
		printf("%d\n",g);
		for (i=0;i<g-1;i++)
		{
			exchange=0;
			for (j=0;j<g-1-i;j++)
			{
				if (tem[j+1].Sum>tem[j].Sum)
				{
					temp=tem[j+1];
					tem[j+1]=tem[j];
					tem[j]=temp;
					exchange=1;
				}
			}
			if (!exchange)
			{
				break;
			}
		}
		printf("\n");
		printf("排序已经完成！");
		for (i=0;i<g;i++)
		{
			fprintf(fn,"\t    %ld",tem[i].ID);
			fprintf(fn," %s",tem[i].Name);
			fprintf(fn," %c",tem[i].Sex);
			fprintf(fn," %d",tem[i].Math);
			fprintf(fn," %d",tem[i].English);
			fprintf(fn," %d",tem[i].Clanguage);
			fprintf(fn," %d",tem[i].LA);
			fprintf(fn," %d",tem[i].PE);
			fprintf(fn," %d",tem[i].Sum);
			fprintf(fn," %f\n",tem[i].Average);
		}
		fclose(fn);
		fwrite(tem,sizeof(struct student),g,fl);
		fclose(fp);
		fclose(fl);
		printf("排序后的数据已经以二进制格式保存在D:\\sumsort.txt中！！请查看");
		system("pause");
		system("cls");
		inturn();
	}
	if (op=='4')//第二个功能里的小功能：显示
	{
		FILE *fo=NULL;
		fo=fopen("D:\\sumsort.txt","r");
		if (fo==NULL)
		{
			printf("打开文件失败！\n");
			exit(0);
		}
		else
		{
			printf("\t   学号 姓名 性 数 英 C  线 体 总分 平均分\n");
		}
		while (!feof(fo))
		{
			fread(&st,sizeof(struct student),1,fo);
			if(!feof(fo))
			printf("\t    %ld %s %c %d %d %d %d %d %d %f\n",st.ID,st.Name,st.Sex,st.Math,st.English,st.Clanguage,st.LA,st.PE,st.Sum,st.Average);

		}
		fclose(fo);
		system("pause");
		system("cls");
		inturn();
	}
	if (op=='0')//第二个功能里的小功能：返回主菜单
	{
		system("cls");
		menu();
	}
	else 
	{
		printf("********输入错误！********\n");
		printf("请重新输入:");
		scanf("%s",&op);
		printf("\n\n\n");
	}
}
void insert()//第三个功能：插入学生成绩
{
		FILE *fp,*fl,*fm,*fn;
		int n,i,j,exchange,g=0;
		struct student temp;
		fp=fopen("D:\\information.txt","a+");
		printf("		                                                                  输入插入学生数：");
		scanf("%d",&n);
		if (fp==NULL)
		{
			printf("打开文件失败!\n");
			exit(0);
		}
		for (i=0;i<n;i++)
		{
			printf("学号：");
			scanf("%ld",&stu[i].ID);
			printf("姓名：");
			scanf("%s",&stu[i].Name);
			printf("性别：");
			scanf("%s",&stu[i].Sex);
			printf("数学成绩：");
			scanf("%d",&stu[i].Math);
			printf("英语成绩：");
			scanf("%d",&stu[i].English);
			printf("C语言成绩：");
			scanf("%d",&stu[i].Clanguage);
			printf("线性代数成绩:");
			scanf("%d",&stu[i].LA);
			printf("体育成绩：");
			scanf("%d",&stu[i].PE);
			stu[i].Sum=stu[i].Math+stu[i].English+stu[i].Clanguage+stu[i].LA+stu[i].PE;
			printf("总分为：%d\n",stu[i].Sum);
			stu[i].Average=(float)(stu[i].Math+stu[i].English+stu[i].Clanguage+stu[i].LA+stu[i].PE)/(float)5;
			printf("平均分为：%.2f\n",stu[i].Average);
		}	
		fwrite(stu,sizeof(struct student),n,fp);
		fclose(fp);
		fl=fopen("D:\\information.txt","r");
		if (fl==NULL)
		{
			printf("打开文件失败!\n");
			exit(0);
		}
		while (!feof(fl))
		{
			fread(&stu[g],sizeof(struct student),1,fl);
			if(!feof(fp))
			{
				g++;
			}
		}
		fclose(fl);
		fm=fopen("D:\\information.txt","w");
		fn=fopen("D:\\txtinformation.txt","w");
		if (fm==NULL)
		{
			printf("打开文件失败!\n");
			exit(0);
		}
		if (fn==NULL)
		{
			printf("打开文件失败!\n");
			exit(0);
		}
				for (i=0;i<g-1;i++)
		{
			exchange=0;
			for (j=0;j<g-1-i;j++)
			{
				if (stu[j+1].ID<stu[j].ID)
				{
					temp=stu[j];
					stu[j]=stu[j+1];
					stu[j+1]=temp;
					exchange=1;
				}
			}
			if (!exchange)
			{
				break;
			}
		}
		for (i=0;i<g;i++)
		{
			fprintf(fn,"\t    %ld",stu[i].ID);
			fprintf(fn," %s",stu[i].Name);
			fprintf(fn," %c",stu[i].Sex);
			fprintf(fn," %d",stu[i].Math);
			fprintf(fn," %d",stu[i].English);
			fprintf(fn," %d",stu[i].Clanguage);
			fprintf(fn," %d",stu[i].LA);
			fprintf(fn," %d",stu[i].PE);
			fprintf(fn," %d",stu[i].Sum);
			fprintf(fn," %f\n",stu[i].Average);
		}
		fclose(fn);
		fwrite(stu,sizeof(struct student),g,fm);
		printf("数据已以二进制格式保存在D:\\information.txt中\n");
		fclose(fm);
		system("pause");
		system("cls");
		menu();
}
void change()//第四个功能：修改学生信息
{
	FILE *fp,*fl,*fn;
	int g=0,i,v;
	long x;
	struct student tem[N];
	fp=fopen("D:\\information.txt","r");
	if (fp==NULL)
	{
		printf("打开文件失败!\n");
		exit(0);
	}
	while (!feof(fp))
	{
		fread(&tem[g],sizeof(struct student),1,fp);
		if(!feof(fp))
		{
			g++;
		}
	}
	fclose(fp);
	printf("请输入需要修改的学生的学号:");
	scanf("%ld",&x);
	for (i=0;i<g;i++)
	{
		if (tem[i].ID==x)
		{
			v=i;
			printf("姓名：");
			scanf("%s",&tem[v].Name);
			printf("性别：");
			scanf("%s",&tem[v].Sex);
			printf("数学成绩：");
			scanf("%d",&tem[v].Math);
			printf("英语成绩：");
			scanf("%d",&tem[v].English);
			printf("C语言成绩：");
			scanf("%d",&tem[v].Clanguage);
			printf("线性代数成绩:");
			scanf("%d",&tem[v].LA);
			printf("体育成绩：");
			scanf("%d",&tem[v].PE);
			tem[v].Sum=tem[v].Math+tem[v].English+tem[v].Clanguage+tem[v].LA+tem[v].PE;
			printf("总分为：%d\n",tem[v].Sum);
			tem[v].Average=(float)(tem[v].Math+tem[v].English+tem[v].Clanguage+tem[v].LA+tem[v].PE)/(float)5;
			printf("平均分为：%.2f\n",tem[v].Average);
		}
	}
	fl=fopen("D:\\information.txt","w");
	fn=fopen("D:\\txtinformation.txt","w");
	if (fl==NULL)
	{
		printf("打开文件失败!\n");
		exit(0);
		menu();
	}
	if (fn==NULL)
	{
		printf("打开文件失败!\n");
		exit(0);
		menu();
	}
	for (i=0;i<g;i++)
	{
		fprintf(fn,"\t    %ld",tem[i].ID);
		fprintf(fn," %s",tem[i].Name);
		fprintf(fn," %c",tem[i].Sex);
		fprintf(fn," %d",tem[i].Math);
		fprintf(fn," %d",tem[i].English);
		fprintf(fn," %d",tem[i].Clanguage);
		fprintf(fn," %d",tem[i].LA);
		fprintf(fn," %d",tem[i].PE);
		fprintf(fn," %d",tem[i].Sum);
		fprintf(fn," %f\n",tem[i].Average);
	}
	fclose(fn);
	fwrite(tem,sizeof(struct student),g,fl);
	printf("数据已以二进制格式保存！！请查看");
	fclose(fl);
	system("pause");
	system("cls");
	menu();
}
void del()//第五个功能：删除学生信息
{
	FILE *fp,*fl,*fn;
	struct student tem[N];
	int i,x,g=0,v,j;
	fp=fopen("D:\\information.txt","r");
	if (fp==NULL)
	{
		printf("文件打开失败!\n");
		exit(0);
		menu();
	}
	while (!feof(fp))
	{
		fread(&tem[g],sizeof(struct student),1,fp);
		if(!feof(fp))
		{
			g++;
		}
	}
	fn=fopen("D:\\txtinformation.txt","w");
	if (fn==NULL)
	{
		printf("打开文件失败!\n");
		exit(0);
		menu();
	}
	fclose(fp);
	printf("请输入要删除的学生学号:");
	scanf("%ld",&x);
	for (i=0;i<g;i++)
	{
		if (tem[i].ID==x)
		{
			v=i;
			for (j=v;j<g;j++)
			{
				tem[j]=tem[j+1];
			}
		}
	}
	fl=fopen("D:\\information.txt","w");
	if (fp==NULL)
	{
		printf("文件打开失败!\n");
		exit(0);
	}
	for (i=0;i<g-1;i++)
	{
		fprintf(fn,"\t    %ld",tem[i].ID);
		fprintf(fn," %s",tem[i].Name);
		fprintf(fn," %c",tem[i].Sex);
		fprintf(fn," %d",tem[i].Math);
		fprintf(fn," %d",tem[i].English);
		fprintf(fn," %d",tem[i].Clanguage);
		fprintf(fn," %d",tem[i].LA);
		fprintf(fn," %d",tem[i].PE);
		fprintf(fn," %d",tem[i].Sum);
		fprintf(fn," %f\n",tem[i].Average);
	}
	fclose(fn);
	fwrite(tem,sizeof(struct student),g-1,fl);
	fclose(fl);
	printf("数据已以二进制格式保存！！请查看");
	system("pause");
	system("cls");
	menu();
}
void search()//第六个功能：查找
{
	FILE *fp;
	int i,g=0,n;
	struct student tem[N];
	fp=fopen("D:\\information.txt","r");
	printf("请输入要查询的学生学号:");
	scanf("%ld",&n);
	if (fp==NULL)
	{
		printf("打开文件失败!\n");
		exit(0);
		menu();
	}
	while (!feof(fp))
	{
		fread(&tem[g],sizeof(struct student),1,fp);
		if (!feof(fp))
		{
			g++;
		}
	}
	for (i=0;i<g;i++)
	{
		if (n==tem[i].ID)
		{
			printf("\t   学号 姓名 性 数 英 C  线 体 总分 平均分\n");
			printf("\t    %ld %s %c %d %d %d %d  %d %d %f\n",tem[i].ID,tem[i].Name,tem[i].Sex,tem[i].Math,tem[i].English,tem[i].Clanguage,tem[i].LA,tem[i].PE,tem[i].Sum,tem[i].Average);
		}
	}
	fclose(fp);
	system("pause");
	system("cls");
	menu();
}
void main()//主函数
{
	menu();//菜单函数
}
