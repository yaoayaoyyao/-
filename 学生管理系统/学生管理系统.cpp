#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include <malloc.h>
typedef struct student{
	char name[20];
	char num[20];
	char bj[20];
	char yw[20];
    char sx[20];
    char yy[20];
    int source;
    struct student *next;
}stu_info;
stu_info  *head, *phead, *pend,*pnew,*temp;
int dljm();
int xxzjm();
int jszjm();
int glyzjm();
void jsdl();
void query_admin(); 
void query_all_admin();
void Modify_admin();
void query_teacher_qjcxjm(); 
struct student * Read1(); 
void cjpx();
void pdcx();
void query_teacher_num();
void Del_admin();
int zcjm();
int zhcj(char *a);
char s[20],nums[20],cx[50],sin[20],scj[20],op_num[20];
/*
排序查询界面 
*/
void cjpxjm()
{
	printf("\n ===================查询班级===================\n");
	printf("|| Enter                                          ||\n");
	printf("||          1----------网络1班                    ||\n");                //完成 
	printf("||          2----------网络2班                    ||\n");                //完成 
	printf("||          3----------网络3班                    ||\n");                //完成 
	printf("||          4----------网络4班                    ||\n");                //完成
	printf("||          5----------网络5班                    ||\n");                //完成 
	printf("||          6----------网络年级                   ||\n");                //完成 
	printf("||          0----------退出系统                   ||\n");                //完成 
	printf(" ==================================================\n");
	printf("************************************************\nPlease Enter\n");
	int choice = 0, f = 1;
	char num[50],name[50],bj[50],yw[50],sx[50],yy[50] , i[50], source[50];
	char c[20],s6[50];
	scanf("%s", c);  //记录用户的选择并作为返回值返回 
	for (int i = 0; i < strlen(c); i++) {
		if (c[i] < '0' || c[i] > '9') {
			f = 0;
		}
		choice = choice * 10 + (c[i] - '0');
	}
	if (f == 0) {
		printf("输入有误。");
		jszjm();
	}
	else{
		system("cls");		//清屏
		switch(choice) {
			case 1:strcpy(scj,"class1.txt");break;        //学生信息增加
			case 2:strcpy(scj,"class2.txt");break;       //删除学生信息
			case 3:strcpy(scj,"class3.txt");break;       //修改学生信息
			case 4:strcpy(scj,"class4.txt");break;       //查询学生信息
			case 5:strcpy(scj,"class5.txt");break;                     //返回上一层
			case 6:strcpy(scj,"allclass.txt");break;                        //退出系统
			case 0:return;                        //退出系统
			default:jszjm();break;
		}
		if(choice != 0) { 
		cjpx();
		FILE *fp;
	    if ((fp = fopen("成绩排序.txt", "r")) == NULL) {
	    	printf("error");
	    	exit(1);
		}
	    while(!feof(fp)) {
	    	fscanf(fp,"%s %s %s %s %s %s %s %s\n", name, num, bj, yw, sx, yy , source, i);
	    	printf("\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", name, num, bj, yw, sx, yy , source, i);
		}
		fclose(fp);
		printf("\n");
	    printf("\t ==================================================\n");
		printf("\t||          9----------返回上一层                 ||\n");                //完成 
	    printf("\t||          0----------退出系统                   ||\n");                //完成 
	    printf("\t ==================================================\n");
	    choice = 0;
		f = 1;
		scanf("%s", c);  //记录用户的选择并作为返回值返回 
		for (int i = 0; i < strlen(c); i++) {
			if (c[i] < '0' || c[i] > '9') {
				f = 0;
			}
			choice = choice * 10 + (c[i] - '0');
		}
		if (f == 0) {
			printf("输入有误。");
			jszjm();
		}
		else {
		system("cls");		//清屏 
		    switch(choice) {
				case 9:jszjm();break;//返回上一层
				case 0:return;     //退出系统
				default:jszjm();break;
			}
		}
		}	
    }
}
/*
从文件读到链表(学生信息)
返回值：phead 
*/
struct student * Read1()                          
{
	char ch;
	int a,b,d;
	FILE *fp,*fpn;
	fp = fopen(scj, "r");
	fpn = fopen("成绩排序.txt", "w+");
	if (fp == NULL) {
		printf("error\n");
		exit(1);
	} else {
		phead = pend = (struct student*)malloc(sizeof(struct student));
    	while (!feof(fp)) {
			pnew = (struct student*)malloc(sizeof(struct student));
			fscanf(fp, "%s ", pnew->name);
	    	fscanf(fp, "%s ", pnew->num);
	    	fscanf(fp, "%s ", pnew->bj);
	    	fscanf(fp, "%s ", pnew->yw);
	    	fscanf(fp, "%s ", pnew->sx);
	    	fscanf(fp, "%s\n", pnew->yy);
	    	a = zhcj(pnew->yw);
		    b = zhcj(pnew->sx);
		    d = zhcj(pnew->yy);
		    pnew->source = a + b + d;
			pnew->next = NULL;
			pend->next = pnew;
			pend = pnew;
		}
	}
	pend->next = NULL;
	fclose(fp);
	return phead;
}
/*
链表排序 
*/
void cjpx_yw(struct student *head)      //语文 
{
	struct student *cur,*tail,*q,*p,*ptemp;
	int yw1,yw2,count = 0;
	cur=head;
	ptemp = NULL;
	if(cur==NULL||cur->next==NULL){
		return;
	}
	while(cur->next->next!=ptemp){
		tail = cur;
		while(tail->next->next != ptemp){
			p = tail->next;
			q = p->next;
			yw1 = zhcj(p->yw);
			yw2 = zhcj(q->yw);
			if(yw1 < yw2){
			    p->next = q->next;
				q->next = p;
				tail->next = q;
			} 
			tail = tail->next;
		}
		ptemp = tail->next;
	    cur = head;
	}
}
void cjpx_sx(struct student *head)      //数学 
{
	struct student *cur,*tail,*q,*p,*ptemp;
	int sx1,sx2,count = 0;
	cur=head;
	ptemp = NULL;
	if(cur==NULL||cur->next==NULL){
		return;
	}
	while(cur->next->next!=ptemp){
		tail = cur;
		while(tail->next->next != ptemp){
			p = tail->next;
			q = p->next;
			sx1 = zhcj(p->sx);
			sx2 = zhcj(q->sx);
			if(sx1 < sx2){
			    p->next = q->next;
				q->next = p;
				tail->next = q;
			} 
			tail = tail->next;
		}
		ptemp = tail->next;
	    cur = head;
	}
}
void cjpx_yy(struct student *head)      //英语 
{
	struct student *cur,*tail,*q,*p,*ptemp;
	int yy1,yy2,count = 0;
	cur=head;
	ptemp = NULL;
	if(cur==NULL||cur->next==NULL){
		return;
	}
	while(cur->next->next!=ptemp){
		tail = cur;
		while(tail->next->next != ptemp){
			p = tail->next;
			q = p->next;
			yy1 = zhcj(p->yy);
			yy2 = zhcj(q->yy);
			if(yy1 < yy2){
			    p->next = q->next;
				q->next = p;
				tail->next = q;
			} 
			tail = tail->next;
		}
		ptemp = tail->next;
	    cur = head;
	}
}
void cjpx_source(struct student *head)      //总分 
{
	struct student *cur,*tail,*q,*p,*ptemp;
	int count = 0;
	cur=head;
	ptemp = NULL;
	if(cur==NULL||cur->next==NULL){
		return;
	}
	while(cur->next->next!=ptemp){
		tail = cur;
		while(tail->next->next != ptemp){
			p = tail->next;
			q = p->next;
			if(p->source < q->source){
			    p->next = q->next;
				q->next = p;
				tail->next = q;
			} 
			tail = tail->next;
		}
		ptemp = tail->next;
	    cur = head;
	}
}
/*
排序 
*/
void cjpx() 
{
	char subject[50];
	system("cls");		//清屏 
	head = Read1();
	printf("\n\tplease input the subject what you want:");
	scanf("%s",subject);
	if (strcmp(subject,"yw") != 0 && strcmp(subject,"sx") != 0 && strcmp(subject,"yy") != 0 && strcmp(subject,"source") != 0) {
		printf("\n\tYour input are wrong!");
		cjpxjm();
	}
	if(strcmp(subject,"yw") == 0) {
		cjpx_yw(head);
	}
	if (strcmp(subject,"sx") == 0) {
		cjpx_sx(head);
	}
	if (strcmp(subject,"yy") == 0) {
		cjpx_yy(head);
	}
	if (strcmp(subject,"source") == 0) {
		cjpx_source(head);
	}
	FILE *fp;
	int i = 0;
	fp = fopen("成绩排序.txt", "w+");
	stu_info *ptemp;
	ptemp = head->next;
	while(ptemp){
		i++;
		fprintf(fp,"%s %s %s %s %s %s %d %d\n", ptemp->name, ptemp->num, ptemp->bj, ptemp->yw, ptemp->sx, ptemp->yy, ptemp->source, i);
		ptemp=ptemp->next;
	}
	fclose(fp);
} 
/*
输出结果 
*/
void scjg() 
{
	FILE *fp,*fpn;
	char name[50],toname[50],ch;
	char num[50],bj[50],yw[50],sx[50],yy[50];
	if((fp = fopen("区间查询.txt","r")) == NULL )   //打开文件，同上 
	{
		printf("Can't open the file.");
		exit(1);
	}
	ch=fgetc(fp);
    if(ch==EOF) {
        printf("\n\t区间错误\n");
    }
    else { 
        fseek(fp,0,SEEK_SET);
        printf("\n\t姓名\t学号\t班级\t语文\t数学\t英语\n");
        //fgetc(fp);
	    while(!feof(fp)) {
		    fscanf(fp,"%s %s %s %s %s %s\n",name,num,bj,yw,sx,yy);
		    printf("\t%s\t%s\t%s\t%s\t%s\t%s\n",name,num,bj,yw,sx,yy);
	    }
	} 
	fclose(fp);
	printf("\n");
	    printf("\t ==================================================\n");
		printf("\t||          9----------返回上一层                 ||\n");                //完成 
	    printf("\t||          0----------退出系统                   ||\n");                //完成 
	    printf("\t ==================================================\n");
	    int choice = 0, f = 1;
	char c[20];
	scanf("%s", c);  //记录用户的选择并作为返回值返回 
	for (int i = 0; i < strlen(c); i++) {
		if (c[i] < '0' || c[i] > '9') {
			f = 0;
		}
		choice = choice * 10 + (c[i] - '0');
	}
	if (f == 0) {
		printf("输入有误。");
		query_teacher_qjcxjm();
	}
	else {
	system("cls");		//清屏 
	    switch(choice) {
			case 9:query_teacher_qjcxjm();break;//返回上一层
			case 0:return;     //退出系统
			default:query_teacher_qjcxjm();break;
		}
	}	
}
/*
区间查询 
*/
void qjcx()
{
    FILE *fpn,*fp;
	char name[50],toname[50];
	char num[50],bj[50],yw[50],sx[50],yy[50];
	int f = 0;
	if((fpn = fopen("区间查询.txt","r")) == NULL || (fp = fopen("cx.txt","w+")) == NULL)   //打开文件，同上 
	{
		printf("Can't open the file.");
		exit(1);
	}
	char subject[50],interval[50],in[50];
	printf("\n\tplease input the subject:\n");
	printf("\t(eg. chinese please input yw)");
	scanf("%s",subject);
	if (strcmp(subject,"yw") != 0 && strcmp(subject,"sx") != 0 && strcmp(subject,"yy") != 0) {
		printf("\n\tYour input are wrong!");
		fclose(fpn);
		pdcx();
	}
	else {
		printf("\n\tplease input the 符号:\n");
		printf("\t(eg. '<'  )");
		scanf("%s",in);
		f = strlen(in);
		if (f >= 2 && in[1] != '=') {
			printf("\n\tYour input are wrong!");
			fclose(fpn);
			pdcx();
		}
		else{ 
			if (in[0] != '<' && in[0] != '>') {
				printf("\n\tYour input are wrong!");
				fclose(fpn);
				pdcx();
			}
			else{ 
				printf("\n\tplease input the interval:\n");
				printf("\t(eg. '60' )");
				scanf("%s",interval);
				if (zhcj(interval) < 0 || zhcj(interval) > 100) {
					printf("\n\tYour input are wrong!");
					fclose(fpn);
					pdcx();
				}
				else{
					while(!feof(fpn)) {
						fscanf(fpn,"%s %s %s %s %s %s\n",name,num,bj,yw,sx,yy);
						if (strcmp(subject,"yw") == 0) {
							if (in[0] == '<') {
								if (f == 2){ 
						    		if (zhcj(yw) <= zhcj(interval)) {
							 		   fprintf(fp,"%s %s %s %s %s %s\n",name,num,bj,yw,sx,yy);
						    		}
								} 
								if (f == 1) {
									if (zhcj(yw) < zhcj(interval)) {
							  			fprintf(fp,"%s %s %s %s %s %s\n",name,num,bj,yw,sx,yy);
						   		 	}
								}
							}
							if (in[0] == '>') {
								if (f == 2){ 
						    		if (zhcj(yw) >= zhcj(interval)) {
							    		fprintf(fp,"%s %s %s %s %s %s\n",name,num,bj,yw,sx,yy);
						    		}
								} 
								if (f == 1) {
									if (zhcj(yw) > zhcj(interval)) {
							    		fprintf(fp,"%s %s %s %s %s %s\n",name,num,bj,yw,sx,yy);
						    		}
								}
							} 
						}
						if (strcmp(subject,"sx") == 0) {
							if (in[0] == '<') {
								if (f == 2){ 
						    		if (zhcj(sx) <= zhcj(interval)) {
							    		fprintf(fp,"%s %s %s %s %s %s\n",name,num,bj,yw,sx,yy);
						    		}
								} 
								if (f == 1) {
									if (zhcj(sx) < zhcj(interval)) {
							    		fprintf(fp,"%s %s %s %s %s %s\n",name,num,bj,yw,sx,yy);
						    		}
								}
							}
							if (in[0] == '>') {
								if (f == 2){ 
						    		if (zhcj(sx) >= zhcj(interval)) {
							   		   fprintf(fp,"%s %s %s %s %s %s\n",name,num,bj,yw,sx,yy);
						   			}
								} 
								if (f == 1) {
									if (zhcj(sx) > zhcj(interval)) {
							    		fprintf(fp,"%s %s %s %s %s %s\n",name,num,bj,yw,sx,yy);
						    		}
								}
							} 
						}
						if (strcmp(subject,"yy") == 0) {
							if (in[0] == '<') {
								if (f == 2){ 
						    		if (zhcj(yy) <= zhcj(interval)) {
							    		fprintf(fp,"%s %s %s %s %s %s\n",name,num,bj,yw,sx,yy);
						    		}
								} 
								if (f == 1) {
									if (zhcj(yy) < zhcj(interval)) {
							    		fprintf(fp,"%s %s %s %s %s %s\n",name,num,bj,yw,sx,yy);
						    		}
								}
							}
							if (in[0] == '>') {
								if (f == 2){ 
						    		if (zhcj(yy) >= zhcj(interval)) {
							    		fprintf(fp,"%s %s %s %s %s %s\n",name,num,bj,yw,sx,yy);
						   		    }
								} 
								if (f == 1) {
									if (zhcj(yy) > zhcj(interval)) {
							    		fprintf(fp,"%s %s %s %s %s %s\n",name,num,bj,yw,sx,yy);
						    		}
								}
							} 
						}
					}
					fclose(fpn);
					fclose(fp);
					remove("区间查询.txt");	//删除原文件
		            rename("cx.txt", "区间查询.txt");	//重命名新文件
					printf("\n");
	        		printf("\t ==================================================\n");
		    		printf("\t||          8----------输出结果                   ||\n");
		    		printf("\t||          9----------继续选择区间               ||\n");                //完成 
	        		printf("\t||          0----------退出系统                   ||\n");                //完成 
	        		printf("\t ==================================================\n");
	        		int choice = 0;
	        		f = 1; 
    	    		char c[20];
	        		scanf("%s", c);  //记录用户的选择并作为返回值返回 
	        		for (int i = 0; i < strlen(c); i++) {
	    	    		if (c[i] < '0' || c[i] > '9') {
	    		  		    f = 0;
    	    			}
	        			choice = choice * 10 + (c[i] - '0');
	        		}
    	    		if (f == 0) {
	    	    		printf("输入有误。");
		        		scjg();
    	    		}
	        		else {
	        		system("cls");		//清屏 
	            		switch(choice) {
		    	    		case 8:scjg();break;//返回上一层
		    	    		case 9:qjcx();break;//返回上一层
		    	    		case 0:return;     //退出系统
		    	    		default:scjg();break;
		        		}
	        		}	
				} 
			}
		}
	} 
}
/*
区间查询界面 
*/
void query_teacher_qjcxjm()
{
	printf("\n ===================查询班级===================\n");
	printf("|| Enter                                          ||\n");
	printf("||          1----------网络1班                    ||\n");                //完成 
	printf("||          2----------网络2班                    ||\n");                //完成 
	printf("||          3----------网络3班                    ||\n");                //完成 
	printf("||          4----------网络4班                    ||\n");                //完成
	printf("||          5----------网络5班                    ||\n");                //完成 
	printf("||          6----------网络年级                   ||\n");                //完成 
	printf("||          9----------返回上一层                 ||\n");                //完成 
	printf("||          0----------退出系统                   ||\n");                //完成 
	printf(" ==================================================\n");
	printf("************************************************\nPlease Enter\n");
	int choice = 0, f = 1;
	char c[20],s6[50];
	scanf("%s", c);  //记录用户的选择并作为返回值返回 
	for (int i = 0; i < strlen(c); i++) {
		if (c[i] < '0' || c[i] > '9') {
			f = 0;
		}
		choice = choice * 10 + (c[i] - '0');
	}
	if (f == 0) {
		printf("输入有误。");
		jszjm();
	}
	else{
	system("cls");		//清屏
	switch(choice) {
		case 1:strcpy(sin,"class1.txt");break;        //学生信息增加
		case 2:strcpy(sin,"class2.txt");break;       //删除学生信息
		case 3:strcpy(sin,"class3.txt");break;       //修改学生信息
		case 4:strcpy(sin,"class4.txt");break;       //查询学生信息
		case 5:strcpy(sin,"class5.txt");break;                     //返回上一层
		case 6:strcpy(sin,"allclass.txt");break;                        //退出系统
		case 9:jszxt();break;                     //返回上一层
		case 0:return;                        //退出系统
		default:jszjm();break;
	}
    FILE *fp,*fpn;
	char name[50],toname[50];
	char num[50],bj[50],yw[50],sx[50],yy[50];
	if((fpn = fopen("区间查询.txt","w+")) == NULL || (fp = fopen(sin,"r")) == NULL)   //打开文件，同上 
	{
		printf("Can't open the file.");
		exit(1);
	}
	while(!feof(fp)) {
		fscanf(fp,"%s %s %s %s %s %s\n",name,num,bj,yw,sx,yy);
		fprintf(fpn,"%s %s %s %s %s %s\n",name,num,bj,yw,sx,yy);
	}
	fclose(fp);
	fclose(fpn);
	qjcx();
    }
}
/*
班级总成绩 
*/
void query_teacher_bj(){
	FILE *fp;
	char name[50],toname[50],s6[50]="class0.txt";
	char num[50],bj[50],yw[50],sx[50],yy[50];
	int f = 1;
	printf("\n\tplease input the class numble:");
	scanf("%c", &s6[20]);
	scanf("%c", &s6[5]);
	if((fp = fopen(s6,"r")) == NULL)   //打开文件，同上 
	{
		printf("Can't open the file.");
		exit(1);
	}
	printf("\n\t姓名\t学号\t班级\t语文\t数学\t英语\n");
	while(!feof(fp)){
		fscanf(fp,"%s %s %s %s %s %s\n",name,num,bj,yw,sx,yy);
		printf("\t%s\t%s\t%s\t%s\t%s\t%s\n",name,num,bj,yw,sx,yy);
	}
	fclose(fp);
	printf("\n");
	    printf("\t ==================================================\n");
		printf("\t||          9----------返回上一层                 ||\n");                //完成 
	    printf("\t||          0----------退出系统                   ||\n");                //完成 
	    printf("\t ==================================================\n");
	    int choice = 0;
	char c[20];
	scanf("%s", c);  //记录用户的选择并作为返回值返回 
	for (int i = 0; i < strlen(c); i++) {
		if (c[i] < '0' || c[i] > '9') {
			f = 0;
		}
		choice = choice * 10 + (c[i] - '0');
	}
	if (f == 0) {
		printf("输入有误。");
		pdcx();
	}
	else {
	system("cls");		//清屏 
	    switch(choice) {
			case 9:pdcx();break;//返回上一层
			case 0:return;     //退出系统
			default:pdcx();break;
		}
	}	
}
/*
名字查询 
*/
void query_teacher_name(){ 
	FILE *fp;
	char name[50],toname[50];
	char num[50],bj[50],yw[50],sx[50],yy[50];
	int f = 0;
	if((fp = fopen(s,"r")) == NULL)   //打开文件，同上 
	{
		printf("Can't open the file.");
		exit(1);
	}
	printf("\n\tplease input the name:");
	scanf("%s",toname);
	while(!feof(fp)){
		fscanf(fp,"%s %s %s %s %s %s\n",name,num,bj,yw,sx,yy);
		if(strcmp(name,toname)==0) {
			f = 1;
	        printf("\n\t姓名\t学号\t班级\t语文\t数学\t英语\n");
			printf("\t%s\t%s\t%s\t%s\t%s\t%s\n",name,num,bj,yw,sx,yy);
			break;
		}
	}
	if (f == 0) {
		printf("没有此同学。");
	}
	fclose(fp);
	printf("\n");
	    printf("\t ==================================================\n");
		printf("\t||          9----------返回上一层                 ||\n");                //完成 
	    printf("\t||          0----------退出系统                   ||\n");                //完成 
	    printf("\t ==================================================\n");
	    int choice = 0;
	    f = 1;
	char c[20];
	scanf("%s", c);  //记录用户的选择并作为返回值返回 
	for (int i = 0; i < strlen(c); i++) {
		if (c[i] < '0' || c[i] > '9') {
			f = 0;
		}
		choice = choice * 10 + (c[i] - '0');
	}
	if (f == 0) {
		printf("输入有误。");
		pdcx();
	}
	else {
	system("cls");		//清屏
	    switch(choice) {
			case 9:pdcx();break;//返回上一层
			case 0:return;     //退出系统
			default:pdcx();break;
		}
	}	
}
/*
(教师）查询方式
*/
void pdcx()
{
	printf("\n ===================查询方式===================\n");
	printf("|| Enter                                          ||\n");
	printf("||          1----------学号查询                   ||\n");                //完成 
	printf("||          2----------姓名查询                   ||\n");                //完成 
	printf("||          3----------班级查询                   ||\n");                //完成 
	printf("||          4----------按成绩区间查询             ||\n");                //完成
	printf("||          8----------返回上一层                 ||\n");                //完成 
	printf("||          0----------退出系统                   ||\n");                //完成 
	printf(" ==================================================\n");
	printf("************************************************\nPlease Enter\n");
	int choice = 0, f = 1;
	char c[20];
	scanf("%s", c);  //记录用户的选择并作为返回值返回 
	for (int i = 0; i < strlen(c); i++) {
		if (c[i] < '0' || c[i] > '9') {
			f = 0;
		}
		choice = choice * 10 + (c[i] - '0');
	}
	if (f == 0) {
		printf("输入有误。");
		jszjm();
	}
	else{
	system("cls");		//清屏
	switch(choice) {
		case 1:query_teacher_num();break;        //学生信息增加
		case 2:query_teacher_name();break;       //删除学生信息
		case 3:query_teacher_bj();break;       //修改学生信息
		case 4:query_teacher_qjcxjm();break;       //查询学生信息
		case 8:jszjm();;break;                     //返回上一层
		case 0:return;                         //退出系统
		default:jszjm();;break;
	}
}
}
/*
账号判断重复项 
*/
int zhpdcf(const char *s2,const char *num1)
{
	FILE *fp;
	char password[50],num[50];
	int f = 1;
	if( (fp = fopen(s2,"r")) == NULL)   //打开文件，同上 
	{
		printf("Can't open the file.");
		exit(1);
	}
	while(!feof(fp)) {
		fscanf(fp,"%s ",num);
		fscanf(fp,"%s\n",password);
		if (strcmp(num1, num) == 0) {
			f = 0;
			printf("\n\t已有此账号。\n");
		}
	}
	if (f == 0) {
		return 0;
	}
	else {
		return 1;
	}	
}
/*
学生信息判断重复项 
*/
int pdcf(char *s2,char *num1)
{
	FILE *fp;
	char name[50],num[50],bj[50],a[20],b[20],d[20];
	int f = 1;
	if( (fp = fopen(s2,"r")) == NULL)   //打开文件，同上 
	{
		printf("Can't open the file.");
		exit(1);
	}
	while(!feof(fp)) {
		fscanf(fp,"%s ",name);
		fscanf(fp,"%s ",num);
		fscanf(fp,"%s ",bj);
		fscanf(fp,"%s %s %s\n",a,b,d);
		if (strcmp(num1, num) == 0) {
			f = 0;
			printf("\n\t已有此同学。\n");
		}
	}
	if (f == 0) {
		return 0;
	}
	else {
		return 1;
	}	
}
/*
转换成绩 
*/
int zhcj(char *a) 
{
	int len = strlen(a), num = 0;
	for (int i = 0; i < len; i++) {
		if (a[i] < '0' || a[i] > '9') {
			num = -1;
			break;
		}
		num = num * 10 + (a[i]-'0');
	}
	return num;
}
/*
修改账号界面 
*/
int xgjm()    
{
	system("cls");		//清屏 
	printf("\n ====================删除界面==================\n");
	printf("|| Enter                                        ||\n");
	printf("||          1----------学生账号                 ||\n");
	printf("||          2----------教师账号                 ||\n");
	printf("||          3----------管理员账号               ||\n");
	printf("||          9----------返回上一层               ||\n");
	printf("||          0----------退出系统                 ||\n");
	printf(" ============================================\n");
	printf("************************************************\nPlease Enter\n");
	int choice;
	scanf("%d",&choice);  //记录用户的选择并作为返回值返回 
	switch(choice) {
		case 1:strcpy(cx,"Student' Work.txt");Modify_admin();break;//查询学生
		case 2:strcpy(cx,"Teacher' Work.txt");Modify_admin();break;//查询教师
		case 3:strcpy(cx,"Admin' Work.txt");Modify_admin();break;  //查询管理员
		case 9:glyzjm();break;  //查询管理员
		case 0:return 0;    //退出系统
		default:glyzjm();break;
	}
}
/*
删除账号界面 
*/
int scjm()    
{
	system("cls");		//清屏 
	printf("\n ====================删除界面==================\n");
	printf("|| Enter                                        ||\n");
	printf("||          1----------学生账号                 ||\n");
	printf("||          2----------教师账号                 ||\n");
	printf("||          3----------管理员账号               ||\n");
	printf("||          9----------返回上一层               ||\n");
	printf("||          0----------退出系统                 ||\n");
	printf(" ============================================\n");
	printf("************************************************\nPlease Enter\n");
	int choice;
	scanf("%d",&choice);  //记录用户的选择并作为返回值返回 
	switch(choice) {
		case 1:strcpy(cx,"Student' Work.txt");Del_admin();break;//查询学生
		case 2:strcpy(cx,"Teacher' Work.txt");Del_admin();break;//查询教师
		case 3:strcpy(cx,"Admin' Work.txt");Del_admin();break;  //查询管理员
		case 9:glyzjm();break;  //查询管理员
		case 0:return 0;    //退出系统
		default:glyzjm();break;
	}
}
/*
查询全部账号界面 
*/
int cxjm_all()    
{
	system("cls");		//清屏 
	printf("\n ====================查询界面==================\n");
	printf("|| Enter                                        ||\n");
	printf("||          1----------学生账号                 ||\n");
	printf("||          2----------教师账号                 ||\n");
	printf("||          9----------返回上一层               ||\n");
	printf("||          0----------退出系统                 ||\n");
	printf(" ============================================\n");
	printf("************************************************\nPlease Enter\n");
	int choice;
	scanf("%d",&choice);  //记录用户的选择并作为返回值返回 
	switch(choice) {
		case 1:strcpy(cx,"Student' Work.txt");query_all_admin();break;//查询学生
		case 2:strcpy(cx,"Teacher' Work.txt");query_all_admin();break;//查询教师
		case 9:glyzjm();break;  //查询管理员
		case 0:return 0;    //退出系统
		default:glyzjm();break;
	}
}
/*
查询单个账号界面 
*/
int cxjm()    
{
	system("cls");		//清屏 
	printf("\n ====================查询界面==================\n");
	printf("|| Enter                                      ||\n");
	printf("||          1----------查询学生账号           ||\n");
	printf("||          2----------查询教师账号           ||\n");
	printf("||          3----------查询管理员账号         ||\n");
	printf("||          9----------返回上一层               ||\n");
	printf("||          0----------退出系统               ||\n");
	printf(" ==============================================\n");
	printf("************************************************\nPlease Enter\n");
	int choice;
	scanf("%d",&choice);  //记录用户的选择并作为返回值返回 
	switch(choice) {
		case 1:strcpy(cx,"Student' Work.txt");query_admin();break;//查询学生
		case 2:strcpy(cx,"Teacher' Work.txt");query_admin();break;//查询教师
		case 3:strcpy(cx,"Admin' Work.txt");query_admin();break;  //查询管理员
		case 9:glyzjm();break;  //查询管理员
		case 0:return 0;    //退出系统
		default:glyzjm();break;
	}
}
/*
判断成绩是否正确
*/
int pdcj(int yw,int sx,int yy)
{
	if (yw < 0 || yw > 100 || sx < 0 || sx > 100 || yy < 0 || yy > 100) {
		    return 0;
	}
	return 1;
}
/*
判断名字是否正确
*/
int pdmz(char *name)
{
	int len = strlen(name);
	for (int i = 0; i < len; i++) {
		if (name[i] > 0) {
		    return 0;
	    }
	}
	return 1;
}
/*
判断密码是否相同
*/
int pdmm(char *p,char *password) 
{
	int i = strlen(password), f = 0;
	for (int j = 0; j < i; j++) {
		if (password[j] != p[j]) {
			f = 1;
		}
	}
	if (p[i] != 13) {
		f = 1;
	}
	return f;
}
/*
判断班级是否正确
*/
int pdbj(char *bj)
{
	int len = strlen(bj), num = 0;
	if (bj[0] > 0 || bj[2] > 0) {
		return 0;
	}
	if (bj[4] < '0' || bj[4] > '9') {
		return 0;
	}
	return 1;
}
/*
判断账号是否正确 
*/
int pdzh(char *zh)
{
	int len = strlen(zh), num = 0;
	for(int i = 0; i < len; i++){
		if (zh[i] < '0' || zh[i] > '9') {
			return 0;
		}
		num = num * 10 + (zh[i] - '0');
    }
	return num;
}
/*
1.1.1.成绩查询（输入学号）
*/
void query_num()
{
	system("cls");		//清屏 
	FILE *fp;
	char num[50],scan_num[50];
	int yw, sx, yy, i = 0, f;
	if( (fp = fopen(s,"r")) == NULL)   //打开文件，同上 
	{
		printf("Can't open the file.");
		exit(1);
	}
	else 
	{
		f = pdzh(nums);
		if (f == 0) {
			printf("\t错误的输入！！"); 
		}
		else {
		    system("cls");		//清屏
			printf("\n\t学号\t姓名\t班级\t语文\t数学\t英语\n");
			while(!feof(fp))
			{
				char namecpy[20], bj[20];
				fscanf(fp, "%s", namecpy);
				fscanf(fp, "%s",  num);
				if(strcmp(nums, num) == 0)    //判断是否和输入的学号一样，如果一样输出 
				{
					i = 1;
					fscanf(fp, "%s", bj);
					fscanf(fp, "%d%d%d\n", &yw, &sx, &yy);
					printf("\t%s\t%s\t%s\t%d\t%d\t%d\n", num, namecpy, bj, yw, sx, yy);
					break;
				}
			}
		}
		fclose(fp);
		if (i == 0) {
			printf("\t没有这个学生。");
		}
		printf("\n");
	    printf("\t ==================================================\n");
		printf("\t||          9----------返回上一层                 ||\n");                //完成 
	    printf("\t||          0----------退出系统                   ||\n");                //完成 
	    printf("\t ==================================================\n");
	    int choice = 0, f = 1;
	char c[20];
	scanf("%s", c);  //记录用户的选择并作为返回值返回 
	for (int i = 0; i < strlen(c); i++) {
		if (c[i] < '0' || c[i] > '9') {
			f = 0;
		}
		choice = choice * 10 + (c[i] - '0');
	}
	if (f == 0) {
		printf("输入有误。");
		xxzjm();
	}
	else {
	    switch(choice) {
			case 9:xxzjm();break;//返回上一层
			case 0:return;     //退出系统
			default:xxzjm();break;
		}
	}	
}
}
/*
1.1.2.查询本班成绩
*/
void query()
{	
	system("cls");		//清屏 
	FILE *fp;
	char num[50];
	int yw, sx, yy;
	printf("\n\t学号\t姓名\t班级\t语文\t数学\t英语\n");
	printf("\t============================================\n");
	if( (fp = fopen(s,"r")) == NULL)   //打开文件，同上
	{
		printf("Can't open the file.");
		exit(1);
	}
	else
	{	
		while(!feof(fp))
		{
			char namecpy[20], bj[20];
		    fscanf(fp, "%s ",namecpy);
			fscanf(fp, "%s ", num);
			fscanf(fp, "%s ", bj);
			fscanf(fp, "%d %d %d\n",&yw,&sx,&yy);
			printf("\t%s\t%s\t%s\t%d\t%d\t%d\n", num, namecpy, bj, yw, sx, yy);
		}
		fclose(fp);
		printf("\n\t============================================\n\n");
	    printf("\t ==================================================\n");
		printf("\t||          9----------返回上一层                 ||\n");                //完成 
	    printf("\t||          0----------退出系统                   ||\n");                //完成 
	    printf("\t ==================================================\n");
	    int choice = 0, f = 1;
	char c[20];
	scanf("%s", c);  //记录用户的选择并作为返回值返回 
	for (int i = 0; i < strlen(c); i++) {
		if (c[i] < '0' || c[i] > '9') {
			f = 0;
		}
		choice = choice * 10 + (c[i] - '0');
	}
	if (f == 0) {
		printf("输入有误。");
		xxzjm();
	}
	else {
	    switch(choice) {
			case 9:xxzjm();break;//返回上一层
			case 0:return;     //退出系统
			default:xxzjm();break;
		}
	}
}
}
/*
1.1.3.成绩分析
*/
void fx_num()
{
	system("cls");		//清屏 
	char pmfw[50];
	int op = 1;
	printf("\n\t查询班级排名 or 年级排名：");
	scanf("%s",pmfw);
	if (strcmp(pmfw,"班级排名") == 0) {
		strcpy(scj,s);
	}
	else if (strcmp(pmfw,"年级排名") == 0) {
		strcpy(scj,"allclass.txt");
	}
	else {
		op = 0;
		printf("your input are wrong.");
		xxzjm();
	}
	if(op == 1){ 
	cjpx();
	FILE *fp;
	char num[50];
	int yw, sx, yy, i = 0,pm;
	int source;
	if( (fp = fopen("成绩排序.txt","r")) == NULL)   //打开文件，同上 
	{
		printf("Can't open the file.");
		exit(1);
	}
	else
	{
		system("cls");		//清屏
			while(!feof(fp))
			{
				char namecpy[20], bj[20];
				fscanf(fp, "%s ", namecpy);
				fscanf(fp,"%s ", num);
				if(strcmp(op_num, num) == 0)    //判断是否和输入的学号一样，如果一样输出 
				{
					i = 1;
					fscanf(fp, "%s ", bj);
					fscanf(fp, "%d %d %d %d %d\n", &yw, &sx, &yy, &source, &pm);
					printf("\n\t姓名\t学号\t班级\t语文\t数学\t英语\t总分\t排名\n");
					printf("\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\n\n\t", namecpy, num, bj, yw, sx, yy,source,pm);
					if(source<180)
				    {
				    	printf("未及格");
				    }
					if(source>=180 && source<240)
			  	   {
				  	  	printf("中等");
				    }
				    if(source>=240 && source<270)
				    {
				    	printf("良好");
				    }
				    if(source>=270 && source<=300)
				    {
				    	printf("优秀");
				    }
					break;
				}
			}
		}
		fclose(fp);
		if (i == 0) {
			printf("\n\t没有这个学生。");
		}
		printf("\n");
	    printf("\t ==================================================\n");
		printf("\t||          9----------返回上一层                 ||\n");                //完成 
	    printf("\t||          0----------退出系统                   ||\n");                //完成 
	    printf("\t ==================================================\n");
	    int choice = 0, f = 1;
	char c[20];
	scanf("%s", c);  //记录用户的选择并作为返回值返回 
	for (int i = 0; i < strlen(c); i++) {
		if (c[i] < '0' || c[i] > '9') {
			f = 0;
		}
		choice = choice * 10 + (c[i] - '0');
	}
	if (f == 0) {
		printf("输入有误。");
		xxzjm();
	}
	else {
	    switch(choice) {
			case 9:xxzjm();break;//返回上一层
			case 0:return;     //退出系统
			default:xxzjm();break;
		}
	}	
}
} 
/*
1.1.学生主界面
*/
int xxzjm()    
{
	system("cls");		//清屏 
	printf("\n =================学生主界面=================\n");
	printf("|| Enter                                      ||\n");
	printf("||          1----------成绩查询               ||\n");          //ok 
	printf("||          2----------查询本班成绩           ||\n");          //ok 
	printf("||          3----------成绩分析               ||\n");          //ok
	printf("||          4----------返回上一层             ||\n");          //ok
	printf("||          0----------退出系统               ||\n");          //ok
	printf(" ==============================================\n");
	printf("************************************************\nPlease Enter\n");
	int choice = 0, f = 1;
	char c[20];
	scanf("%s", c);  //记录用户的选择并作为返回值返回 
	for (int i = 0; i < strlen(c); i++) {
		if (c[i] < '0' || c[i] > '9') {
			f = 0;
		}
		choice = choice * 10 + (c[i] - '0');
	}
	if (f == 0) {
		printf("输入有误。");
		xxzjm();
	}
	else{
    switch(choice) {
		case 1:query_num();break;    //成绩查询
		case 2:query();break;        //查询本班成绩
		case 3:fx_num();break;       //成绩分析
	    case 4:dljm();break;         //返回上一层
		case 0:return 0;             //退出系统
		default:dljm();break;
	}
}
}
/*
1.2.7.1 班级成绩分析
*/
void countspec()
{
	system("cls");		//清屏 
	printf(" ==============================================\n");
	printf("|| Enter                                      ||\n");
	printf("||          1----------查看未及格的同学       ||\n");
	printf("||          2----------查看中等的同学         ||\n");
	printf("||          3----------查看良好的同学         ||\n");
	printf("||          4----------查看优秀的同学         ||\n");
	printf("||          5----------返回教师端	      ||\n");
	printf("||          0----------退出系统	              ||\n");
	printf(" ==============================================\n");
	printf("************************************************\nPlease Enter\n");
	int choice = 0, f = 1;
	char c[20];
	scanf("%s", c);  //记录用户的选择并作为返回值返回 
	for (int i = 0; i < strlen(c); i++) {
		if (c[i] < '0' || c[i] > '9') {
			f = 0;
		}
		choice = choice * 10 + (c[i] - '0');
	}
	if (f == 0) {
		printf("输入有误。");
		jszjm();
	}
	else {
	if(choice==1)
	{
		printf("\n\t**********************Query********************\n\n");
	    printf("\t姓名\t学号\t班级\t语文\t数学\t英语\t总分数\n");
		FILE *fp;
		char num[50];
		int source,yw,sx,yy;
		if( (fp = fopen("Fail Student.txt","r")) == NULL)   //打开文件，同上 
		{
			printf("Can't open the file.");
			exit(1);
		}
		else
		{	
			while(!feof(fp))
			{
				char namecpy[20],bj[20];
				fscanf(fp,"%s ",namecpy);
				fscanf(fp,"%s ", num);
				fscanf(fp,"%s ",bj);
				fscanf(fp,"%d %d %d %d\n",&yw,&sx,&yy,&source);
				printf("\t%s\t%s\t%s\t%d\t%d\t%d\t%d\n",namecpy,num,bj,yw,sx,yy,source);
			}
			fclose(fp);
			printf("\n");
			system("pause");
			countspec();	//调用自身查询其他等级
			return;
		}
	} 
	if(choice==1)
	{
		printf("\n\t**********************Query********************\n\n");
	    printf("\t姓名\t学号\t班级\t语文\t数学\t英语\t总分数\n");
		FILE *fp;
		char num[50];
		int yw,sx,yy,source;
		if( (fp = fopen("Fail Student.txt","r")) == NULL)   //打开文件，同上 
		{
			printf("Can't open the file.");
			exit(1);
		}
		else
		{	
			while(!feof(fp))
			{
				char namecpy[20],bj[20];
				fscanf(fp,"%s ",namecpy);
				fscanf(fp,"%s ", num);
				fscanf(fp,"%s ",bj);
				fscanf(fp,"%d %d %d %d\n",&yw,&sx,&yy,&source);
				printf("\t%s\t%s\t%s\t%d\t%d\t%d\t%d\n",namecpy,num,bj,yw,sx,yy,source);
			}
			fclose(fp);
			printf("\n");
			system("pause");
			countspec();	//调用自身查询其他等级 
		}
	}
	if(choice==2)
	{
		printf("\n\t**********************Query********************\n\n");
	    printf("\t姓名\t学号\t班级\t语文\t数学\t英语\t总分数\n");
		FILE *fp;
		char num[50];
		int yw,sx,yy,source;
		if( (fp = fopen("Medium Student.txt","r")) == NULL)   //打开文件，同上 
		{
			printf("Can't open the file.");
			exit(1);
		}
		else
		{	
			while(!feof(fp))
			{
				char namecpy[20],bj[20];
				fscanf(fp,"%s ",namecpy);
				fscanf(fp,"%s ", num);
				fscanf(fp,"%s ",bj);
				fscanf(fp,"%d %d %d %d\n",&yw,&sx,&yy,&source);
				printf("\t%s\t%s\t%s\t%d\t%d\t%d\t%d\n",namecpy,num,bj,yw,sx,yy,source);
			}
			fclose(fp);
			printf("\n");
			system("pause");
			countspec();	//调用自身查询其他等级 
		}
	}
	if(choice==3)
	{
		printf("\n\t**********************Query********************\n\n");
	    printf("\t姓名\t学号\t班级\t语文\t数学\t英语\t总分数\n");
		FILE *fp;
		char num[50];
		int yw,sx,yy,source;
		if( (fp = fopen("Good Student.txt","r")) == NULL)   //打开文件，同上 
		{
			printf("Can't open the file.");
			countspec();
		}
		else
		{	
			while(!feof(fp))
			{
				char namecpy[20],bj[20];
				fscanf(fp,"%s ",namecpy);
				fscanf(fp,"%s ", num);
				fscanf(fp,"%s ",bj);
				fscanf(fp,"%d %d %d %d\n",&yw,&sx,&yy,&source);
				printf("\t%s\t%s\t%s\t%d\t%d\t%d\t%d\n",namecpy,num,bj,yw,sx,yy,source);
			}
			fclose(fp);
			printf("\n");
			system("pause");
			countspec();	//调用自身查询其他等级 
		}	
	}
	if(choice==4)
	{
		printf("\n\t**********************Query********************\n\n");
	    printf("\t姓名\t学号\t班级\t语文\t数学\t英语\t总分数\n");
		FILE *fp;
		char num[50];
		int yw,sx,yy,source;
		if( (fp = fopen("Excellent Student.txt","r")) == NULL)   //打开文件，同上 
		{
			printf("Can't open the file.");
			exit(1);
		}
		else
		{	
			while(!feof(fp))
			{
				char namecpy[20],bj[20];
				fscanf(fp,"%s ",namecpy);
				fscanf(fp,"%s ", num);
				fscanf(fp,"%s ",bj);
				fscanf(fp,"%d %d %d %d\n",&yw,&sx,&yy,&source);
				printf("\t%s\t%s\t%s\t%d\t%d\t%d\t%d\n",namecpy,num,bj,yw,sx,yy,source);
			}
			fclose(fp);
			printf("\n");
			system("pause");
			countspec();	//调用自身查询其他等级 
		}	
	}
	if(choice==5)
	{
		jszjm();
	}
	if(choice==0)
	{
		return;
	}
	else{
		jszjm();
	}
}
}
/*
1.2.7.2 统计未及格，中等，良好，优秀的人数 
*/
void count()
{	
	system("cls");		//清屏 
	printf("\n **********************Count********************\n\n");	
	printf("\n\t   未及格     中等     良好     优秀\n");
	FILE *fp;
	FILE *fpf;
	FILE *fpm;
	FILE *fpg;
	FILE *fpe;
	int count_fail=0;
	int count_medium=0;
	int count_good=0;
	int count_excellent=0;
	char failname[] ="Fail Student.txt";
	char mediumname[] ="Medium Student.txt";
	char goodname[] ="Good Student.txt";
	char excellentname[] ="Excellent Student.txt";
	char num[50];
	int source,yw,sx,yy;
	if( (fp = fopen(s,"r")) == NULL || (fpf = fopen(failname,"w")) == NULL||(fpm = fopen(mediumname,"w")) == NULL||(fpg = fopen(goodname,"w")) == NULL||(fpe = fopen(excellentname,"w")) == NULL)   //打开文件，同上 
	{
		printf("Can't open the file.");
		exit(1);
	}
	else
	{	
		while(!feof(fp))
		{
			char namecpy[20],bj[20];
			fscanf(fp,"%s ",namecpy);
			fscanf(fp,"%s ", num);
			fscanf(fp,"%s ",bj);
			fscanf(fp,"%d %d %d\n",&yw,&sx,&yy);
			source = yw + sx + yy;
			if(source<180)
			{
				count_fail++;
				fprintf(fpf,"%s %s %s %d %d %d %d\n",namecpy,num,bj,yw,sx,yy,source);
			}
			if(source>=180 && source<240)
			{
				count_medium++;
				fprintf(fpm,"%s %s %s %d %d %d %d\n",namecpy,num,bj,yw,sx,yy,source);
			}
			if(source>=240 && source<270)
			{
				count_good++;
				fprintf(fpg,"%s %s %s %d %d %d %d\n",namecpy,num,bj,yw,sx,yy,source);
			}
			if(source>=270 && source<=300)
			{
				count_excellent++;
				fprintf(fpe,"%s %s %s %d %d %d %d\n",namecpy,num,bj,yw,sx,yy,source);
			}
		}
		fclose(fp);
		fclose(fpf);
		fclose(fpm);
		fclose(fpg);
		fclose(fpe);
		printf("\t   %d人        %d人      %d人      %d人\n",count_fail,count_medium,count_good,count_excellent);
    	system("pause");
		countspec();
		remove(failname); 
	    remove(mediumname);
		remove(goodname);
		remove(excellentname);
	}
}
/*
1.2.6.下载到文件中
*/
void download() {
    FILE *fp = NULL, *out = NULL;
    int ch;
    out = fopen("本班成绩.txt","w");
    fp = fopen(s, "r");
    fputs(" 姓名  学号 班级   语文 数学 英语\n", out);
    ch=fgetc(fp); //从fp所指文件的当前指针位置读取一个字符
    while(ch!=EOF) //判断刚读取的字符是否是文件结束符
    {
	    fputc(ch,out); //若不是结束符，将它写入out所指文件
        ch=fgetc(fp); //继续从fp所指文件中读取下一个字符
    } //完成将fp所指文件的内容输出到屏幕上显示
   fclose(fp);
   fclose(out);
}
/*
1.2.5查询本班成绩
*/
void query_teacher()
{	
	system("cls");		//清屏 
	FILE *fp;
	char num[50];
	int yw, sx, yy;
	printf("\n\t学号\t姓名\t班级\t语文\t数学\t英语\n");
	printf("\t============================================\n");
	if( (fp = fopen(s,"r")) == NULL)   //打开文件，同上
	{
		printf("Can't open the file.");
		exit(1);
	}
	else
	{	
		while(!feof(fp))
		{
			char namecpy[20], bj[20];
		    fscanf(fp, "%s ",namecpy);
			fscanf(fp, "%s ", num);
			fscanf(fp, "%s ", bj);
			fscanf(fp, "%d %d %d\n",&yw,&sx,&yy);
			printf("\t%s\t%s\t%s\t%d\t%d\t%d\n", num, namecpy, bj, yw, sx, yy);
		}
		fclose(fp);
	    printf("\n\t============================================\n\n");
	    printf("\t ==================================================\n");
		printf("\t||          9----------返回上一层                 ||\n");                //完成 
	    printf("\t||          0----------退出系统                   ||\n");                //完成 
	    printf("\t ==================================================\n");
	   int choice = 0, f = 1;
	char c[20];
	scanf("%s", c);  //记录用户的选择并作为返回值返回 
	for (int i = 0; i < strlen(c); i++) {
		if (c[i] < '0' || c[i] > '9') {
			f = 0;
		}
		choice = choice * 10 + (c[i] - '0');
	}
	if (f == 0) {
		printf("输入有误。");
		jszjm();
	}
	else {
	    switch(choice) {
			case 9:jszjm();break;//返回上一层
			case 0:return;     //退出系统
			default:jszjm();break;
		}
	}
}
}
/*
1.2.4 (教师)成绩查询（输入学号）
*/
void query_teacher_num()
{
	system("cls");		//清屏 
	FILE *fp;
	char num[50],scan_num[50];
	int yw, sx, yy, i = 0, f;
	char c;
	if((fp = fopen(s,"r")) == NULL)   //打开文件，同上 
	{
		printf("Can't open the file.");
		exit(1);
	}
	else
	{ 
	    printf("\n   请输入想查询信息学生的学号:");
	    scanf("%s", scan_num);
	    f = pdzh(scan_num);
	    if (f == 0) {
	    	printf("\t错误的输入！！"); 
	    }
		else {
		    system("cls");		//清屏
		    printf("\n\t姓名\t学号\t班级\t语文\t数学\t英语\n");
			while(!feof(fp))
			{
				char namecpy[20], bj[20];
				fscanf(fp, "%s ", namecpy);
				fscanf(fp, "%s ",  num);
				if(strcmp(scan_num, num) == 0)    //判断是否和输入的学号一样，如果一样输出 
				{
					i = 1;
					fscanf(fp, "%s ", bj);
					fscanf(fp, "%d %d %d\n", &yw, &sx, &yy);
					printf("\t%s\t%s\t%s\t%d\t%d\t%d\n", num, namecpy, bj, yw, sx, yy);
					break;
				}
			}
		} 
		fclose(fp);
		if (i == 0) {
			printf("没有此同学。");
		}
		printf("\n");
	    printf("\t ==================================================\n");
		printf("\t||          9----------返回上一层                 ||\n");                //完成 
	    printf("\t||          0----------退出系统                   ||\n");                //完成 
	    printf("\t ==================================================\n");
	    int choice = 0, f = 1;
	char c[20];
	scanf("%s", c);  //记录用户的选择并作为返回值返回 
	for (int i = 0; i < strlen(c); i++) {
		if (c[i] < '0' || c[i] > '9') {
			f = 0;
		}
		choice = choice * 10 + (c[i] - '0');
	}
	if (f == 0) {
		printf("输入有误。");
		pdcx();
	}
	else {
		system("cls");		//清屏 
	    switch(choice) {
			case 9:pdcx();break;//返回上一层
			case 0:return;     //退出系统
			default:pdcx();break;
		}
	}	
}
}
/*
1.2.3.修改学生信息
*/
void Modify_num()
{
	FILE *fp;
	FILE *fpn,*fpo; 
	char newfilename[] = "Students' Work temp.txt"; //一个临时文件 
	char num[50],tonum[50];
	int yw,sx,yy,toyw,tosx,toyy,f,f1 = 0;
	char a[20],b[20],d[20];
	char toname[20],tobj[20];				       //不能修改学号
	if( (fpn = fopen(newfilename,"w")) == NULL || (fp = fopen(s,"r")) == NULL || (fpo = fopen("allclass.txt","r")) == NULL)   //打开文件，同上 
	{
		printf("\tCan't open the file.");
		exit(1);
	}
	else
	{	
	    system("cls");		//清屏 
		printf("   请输入想修改信息学生的学号:");  //获得修改的信息 
		scanf("%s", tonum);	
		f = pdzh(tonum);
		if (f == 0) {
			printf("\t错误的输入！！"); 
		}
		else {
	    	printf("\n\tPlease Student's Name:");
	  	    scanf("%s",toname);
	  	    f = pdmz(toname);
	    	if (f == 0) {
			    printf("\t这是错误的输入。");
	    	}
	    	else{
		    	printf("\n\tPlease Student's class:");
	    		scanf("%s",tobj);
	    		f = pdbj(tobj);
	    		if (f == 0) {
				    printf("\t这是错误的输入。");
	    		}
	    		else {
	        		printf("\tPlease Student's Source:");
	        		scanf("%s %s %s",a,b,d);
	        		yw = zhcj(a);
	        	    sx = zhcj(b);
	        	    yy = zhcj(d);
	        		f = pdcj(yw,sx,yy);
	        		if (f == 0) {
				         printf("\t这是错误的输入。");
	    		    }
				}
			}
		}
		while(!feof(fp)) {
			char namecpy[20],bj[20];
			fscanf(fp,"%s ", namecpy); 
			fscanf(fp,"%s ", num);
    		fscanf(fp,"%s ", bj);
			fscanf(fp,"%d %d %d\n",&yw,&sx,&yy);
			if(strcmp(tonum, num) == 0 && f == 1)    //判断是否和输入的学号一样，如果一样覆盖
			{
				f1 = 1;
				 fprintf(fpn,"%s %s %s %d %d %d\n",toname,tonum,tobj,toyw,tosx,toyy);
				 fprintf(fpo,"%s %s %s %d %d %d\n",toname,tonum,tobj,toyw,tosx,toyy);
				 printf("\t已成功修改。");
		    }
			else
			{
				fprintf(fpn,"%s %s %s %d %d %d\n",namecpy,num,bj,yw,sx,yy);
				fprintf(fpo,"%s %s %s %d %d %d\n",namecpy,num,bj,yw,sx,yy);
			}
		}
		if (f1 == 0) {
			printf("\n\t没有此同学。\n");
		}
		fclose(fp);
		fclose(fpn);
		fclose(fpo);
		remove(s);	//删除原文件
		rename(newfilename, s);	//重命名新文件
		printf("\n");
	    printf("\t ==================================================\n");
		printf("\t||          9----------返回上一层                 ||\n");                //完成 
	    printf("\t||          0----------退出系统                   ||\n");                //完成 
	    printf("\t ==================================================\n");
	    int choice = 0, f = 1;
	char c[20];
	scanf("%s", c);  //记录用户的选择并作为返回值返回 
	for (int i = 0; i < strlen(c); i++) {
		if (c[i] < '0' || c[i] > '9') {
			f = 0;
		}
		choice = choice * 10 + (c[i] - '0');
	}
	if (f == 0) {
		printf("输入有误。");
		jszjm();
	}
	else {
	    switch(choice) {
			case 9:jszjm();break;//返回上一层
			case 0:return;     //退出系统
			default:jszjm();break;
		}
	}	
}
}
/*
1.2.2删除学生信息
*/
void Del_num()
{
	FILE *fp;
	FILE *fpn,*fpo; 
	char newfilename[] = "Students' Work temp.txt"; //一个临时文件
	char num[50],tonum[50];
	int yw,sx,yy,f;				    
	if( (fpn = fopen(newfilename,"w")) == NULL || (fp = fopen(s,"r")) == NULL || (fpo = fopen("allclass.txt","r")) == NULL)   //打开文件，同上 
	{
		printf("Can't open the file.");
		exit(1);
	}
	else
	{	
		system("cls");		//清屏 
		printf("   请输入想删除信息学生的学号:");  //获得删除的信息 
		scanf("%s", tonum);
		f = pdzh(tonum);
		if (f == 0) {
			printf("\n\t错误的输入。\n");
		}
		while(!feof(fp))
		{
			char namecpy[20],bj[20];
			fscanf(fp,"%s ",namecpy); 
			fscanf(fp,"%s ", num);
			fscanf(fp,"%s ",bj);
			fscanf(fp,"%d %d %d\n",&yw,&sx,&yy);
			if(strcmp(tonum, num) == 0)    //判断是否和输入的学号一样，如果一样跳过写入临时文件 
			{
					;//做一次空操作
					printf("\t已成功删除。");
			}
			else
			{
				fprintf(fpn,"%s %s %s %d %d %d\n",namecpy,num,bj,yw,sx,yy);
				fprintf(fpo,"%s %s %s %d %d %d\n",namecpy,num,bj,yw,sx,yy);
			}
		}
		fclose(fp);
		fclose(fpn);
		fclose(fpo);
		remove(s);	//删除原文件
		rename(newfilename, s);	//重命名新文件
		printf("\n");
	    printf("\t ==================================================\n");
		printf("\t||          9----------返回上一层                 ||\n");                //完成 
	    printf("\t||          0----------退出系统                   ||\n");                //完成 
	    printf("\t ==================================================\n");
	    int choice = 0, f = 1;
	char c[20];
	scanf("%s", c);  //记录用户的选择并作为返回值返回 
	f=1;
	for (int i = 0; i < strlen(c); i++) {
		if (c[i] < '0' || c[i] > '9') {
			f = 0;
		}
		choice = choice * 10 + (c[i] - '0');
	}
	if (f == 0) {
		printf("输入有误。");
		jszjm();
	}
	else {
	    switch(choice) {
			case 9:jszjm();break;//返回上一层
			case 0:return;     //退出系统
			default:jszjm();break;
		}
	}	
}
} 
/*
1.2.1学生信息增加
*/
void record()
{
	system("cls");		//清屏 
	FILE *fp,*fpn;
	if ((fpn = fopen(s,"a")) == NULL || (fp = fopen("allclass.txt","a")) == NULL) //打开文件，如果打开失败给用户提示 
	{
		printf("Can't open the file.");
		exit(1);
	}
	else
	{
	    char name[20];  //保存姓名
		int num;        //保存学号
		char bj[20];    //保存班级 
		char a[20],b[20],d[20];
		int yw, sx, yy,f = 1;     //保存成绩:语文，数学，英语 
		printf("\tPlease Student's Num:\n");
		printf("\t(if you want to stop, input 0)");
		char zh[50];
		scanf("%s", zh);
		num = pdzh(zh);
		if (num == 0) {
			printf("\t错误的输入！！");
		} 
		while(num!=0)    //循环输入直到用户输入的Num=0时停止录入 
		{
			    f= pdcf(s,zh);
		        if (f == 0) {
			        break;
		        }
				printf("\tPlease Student's Name:");   //录入姓名 
				scanf("%s",name);
				f = pdmz(name);
				if (f == 0) {
					printf("\t错误的输入！！");
					break;
				}
				
			    printf("\tPlease Student's Class:");   //录入班级 
				scanf("%s",bj);
				f = pdbj(bj);
				if (f == 0) {
					printf("\t错误的输入！！");
					break;
				}
				
	      	  	printf("\tPlease Student's Source:");
	        	scanf("%s %s %s", a, b, d);
	        	yw = zhcj(a);
	        	sx = zhcj(b);
	        	yy = zhcj(d);
	        	f = pdcj(yw,sx,yy);
	        	if (f == 0) {
				    printf("\t错误的输入。");
				    break;
	    		}
	        	
				fprintf(fp,"%s ", name);
				fprintf(fp,"%s ", zh);  //将num以及一个空格保存到文件中，下同 
				fprintf(fp,"%s ", bj);
				fprintf(fp,"%d %d %d\n", yw,sx,yy);
				
				fprintf(fpn,"%s ", name);
				fprintf(fpn,"%s ", zh);  //将num以及一个空格保存到文件中，下同 
				fprintf(fpn,"%s ", bj);
				fprintf(fpn,"%d %d %d\n", yw,sx,yy);
	        	
	        	printf("\n\t已成功添加。\n\n");
				printf("\tPlease Student's Num:\n");
		    	printf("\t(if you want to stop, input 0)");
				scanf("%s", zh);
				f = pdcf(s,zh);
		        if (f == 0) {
			        break;
		        }
				num = pdzh(zh);
				if (num == 0) {
					printf("\t错误的输入！！");
					break; 
				}
			}
		//}
		fclose(fp);   //关闭文件 
		fclose(fpn);
		printf("\n");
	    printf("\t ==================================================\n");
		printf("\t||          9----------返回上一层                 ||\n");                //完成 
	    printf("\t||          0----------退出系统                   ||\n");                //完成 
	    printf("\t ==================================================\n");
	    int choice = 0, l = 1;
	char c[20];
	scanf("%s", c);  //记录用户的选择并作为返回值返回 
	for (int i = 0; i < strlen(c); i++) {
		if (c[i] < '0' || c[i] > '9') {
			l = 0;
		}
		choice = choice * 10 + (c[i] - '0');
	}
	if (l == 0) {
		printf("输入有误。");
		jszjm();
	}
	else {
	    switch(choice) {
			case 9:jszjm();break;//返回上一层
			case 0:return;     //退出系统
			default:jszjm();break;
		}
	}
	}
}
/*
1.2.教师主系统程序一览表
*/
int jszjm()    
{
	system("cls");		//清屏 
	printf("\n ===================教师主界面===================\n");
	printf("|| Enter                                          ||\n");
	printf("||          1----------学生信息增加               ||\n");                //完成 
	printf("||          2----------删除学生信息               ||\n");                //完成 
	printf("||          3----------修改学生信息               ||\n");                //完成 
	printf("||          4----------查询学生信息               ||\n");                //完成
	printf("||          5----------输出全部成绩               ||\n");                //完成
	printf("||          6----------下载到文件中               ||\n");                //完成
	printf("||          7----------成绩分析                   ||\n");                //完成
	printf("||          8----------成绩排序                   ||\n");                //完成
	printf("||          9----------返回上一层                 ||\n");                //完成 
	printf("||          0----------退出系统                   ||\n");                //完成 
	printf(" ==================================================\n");
	printf("************************************************\nPlease Enter\n");
	int choice = 0, f = 1;
	char c[20];
	scanf("%s", c);  //记录用户的选择并作为返回值返回 
	for (int i = 0; i < strlen(c); i++) {
		if (c[i] < '0' || c[i] > '9') {
			f = 0;
		}
		choice = choice * 10 + (c[i] - '0');
	}
	if (f == 0) {
		printf("输入有误。");
		jszjm();
	}
	else{
	system("cls");		//清屏 
	switch(choice) {
		case 1:record();break;           //学生信息增加
		case 2:Del_num();break;          //删除学生信息
		case 3:Modify_num();break;       //修改学生信息
		case 4:pdcx();break;           //查询学生信息
	    case 5:query_teacher();break;    //输出本班成绩
		case 6:download();break;         //下载到文件中
		case 7:count();break;            //成绩分析
		case 8:cjpxjm();;break;              //返回上一层
		case 9:jszjm();;break;              //返回上一层
		case 0:return 0;                 //退出系统
		default:jszjm();;break;
	}
}
}
/*
1.3.9.手动重新录入学生信息
*/
void Modify_admin_num()
{
	FILE *fp;
	FILE *fpn,*fpo; 
	char newfilename[] = "Students' Work temp.txt"; //一个临时文件 
	char num[50],tonum[50];
	char a[20],b[20],d[20];
	int yw,sx,yy,toyw,tosx,toyy,f,f1;
	char toname[20],tobj[20],clas[20]="class0.txt";
	system("cls");		//清屏 
	printf("   请输入被修改信息的学生所属的班级:");  //获得修改的班级
	getchar();
	scanf("%c",&clas[5]);
	if( (fpn = fopen(newfilename,"w")) == NULL || (fp = fopen(clas,"r")) == NULL || (fpo = fopen("allclass.txt","r")) == NULL)   //打开文件，同上 
	{
		printf("\tCan't open the file.");
		exit(1);
	}
	else{
	    printf("\n   请输入被修改信息学生的学号:");  //获得修改的信息
	    scanf("%s", tonum); 				   //不能修改学号
	    f = pdzh(tonum);
	    if (f == 0) {
	    	printf("\t错误的输入！！");
		}
	    else
	    {	
	    printf("\n\tPlease Student's Name:");
	    scanf("%s",toname);
	    f = pdbj(tobj);
	    if (f == 0) {
	    	printf("\t错误的输入！！");
	    }
	    else{
	        printf("\n\tPlease Student's class:");
	        scanf("%s",tobj);
	        f = pdbj(tobj);
	        if (f == 0) {
	    	    printf("\t错误的输入！！");
	        }
	        else {
	            printf("\tPlease Student's Source:");
	            scanf("%d%d%d",a,b,d);
	            yw = zhcj(a);
	        	sx = zhcj(b);
	        	yy = zhcj(d);
				f = pdcj(yw,sx,yy);
	        	if (f == 0) {
			        printf("\t这是错误的输入。");
	    	    }    
	        }
		}
	}
	f1 = 0;
		while(!feof(fp))
		{
		    	char namecpy[20],bj[20];
		    	fscanf(fp,"%s ",namecpy); 
		    	fscanf(fp,"%s ", num); 
			    fscanf(fp,"%s ",bj);  
		    	fscanf(fp,"%d %d %d\n",&yw,&sx,&yy);
		    	if(strcmp(tonum, num) == 0 && f == 1)    //判断是否和输入的学号一样，如果一样覆盖
		    	{
		    		f1 = 1;
		    		fprintf(fpn,"%s %s %s %d %d %d\n",toname,tonum,tobj,toyw,tosx,toyy);
		    		fprintf(fpo,"%s %s %s %d %d %d\n",toname,tonum,tobj,toyw,tosx,toyy);
		    		printf("\t已成功录入！！");
		    	}
		    	else
		    	{
		    		fprintf(fpn,"%s %s %s %d %d %d\n",namecpy,num,bj,yw,sx,yy);
		    		fprintf(fpo,"%s %s %s %d %d %d\n",namecpy,num,bj,yw,sx,yy);
		    	}
	    	}
	    if (f == 0) {
	    	printf("\n\t没有此同学。\n");
		}
		fclose(fp);
		fclose(fpn);
		fclose(fpo);
		remove(clas);	//删除原文件
		rename(newfilename, clas);	//重命名新文件
		printf("\n");
	    printf("\t ==================================================\n");
		printf("\t||          9----------返回上一层                 ||\n");                //完成 
	    printf("\t||          0----------退出系统                   ||\n");                //完成 
	    printf("\t ==================================================\n");
	    int choice = 0, f = 1;
	char c[20];
	scanf("%s", c);  //记录用户的选择并作为返回值返回 
	for (int i = 0; i < strlen(c); i++) {
		if (c[i] < '0' || c[i] > '9') {
			f = 0;
		}
		choice = choice * 10 + (c[i] - '0');
	}
	if (f == 0) {
		printf("输入有误。");
		glyzjm();
	}
	else {
	    switch(choice) {
			case 9:glyzjm();break;//返回上一层
			case 0:return;     //退出系统
			default:glyzjm();break;
		}
	}
	}	
}
/*
1.3.8.输出所有账号和密码
*/
void query_all_admin()
{	
	system("cls");		//清屏
	printf("\n\t账号\t\t密码\n");
	FILE *fp;
	char num[50],password[50];
	if( (fp = fopen(cx,"r")) == NULL)   //打开文件，同上
	{
		printf("Can't open the file.");
		exit(1);
	}
	else
	{	
		while(!feof(fp))
		{
			fscanf(fp,"%s ", num);
			fscanf(fp,"%s\n", password);
			printf("\t%s\t\t%s\n",num,password);
		}
		fclose(fp);
		printf("\n");
	    printf("\t ==================================================\n");
		printf("\t||          9----------返回上一层                 ||\n");                //完成 
	    printf("\t||          0----------退出系统                   ||\n");                //完成 
	    printf("\t ==================================================\n");
	    int choice = 0, f = 1;
	char c[20];
	scanf("%s", c);  //记录用户的选择并作为返回值返回 
	for (int i = 0; i < strlen(c); i++) {
		if (c[i] < '0' || c[i] > '9') {
			f = 0;
		}
		choice = choice * 10 + (c[i] - '0');
	}
	if (f == 0) {
		printf("输入有误。");
		glyzjm();
	}
	else {
	    switch(choice) {
			case 9:glyzjm();break;//返回上一层
			case 0:return;     //退出系统
			default:glyzjm();break;
		}
	}
}
}
/*
1.3.6.查找账号和密码
*/
void query_admin()
{
	FILE *fp;
	char num[50],scan_num[50], password[50];
	int i = 0, f = 1;
	system("cls");		//清屏
	if( (fp = fopen(cx,"r")) == NULL)   //打开文件，同上 
	{
		printf("Can't open the file.");
		exit(1);
	}
	
	else
	{
	    if (strcmp(cx, "Admin' Work.txt") != 0){
		    printf("\n   请输入想查询的账号:");
	        scanf("%s", scan_num);
	    }
	    else {
		    strcpy(scan_num,nums);
	    }
	    f = pdzh(scan_num);
		if (f == 0) {
			printf("\t错误的输入！！");
		}
		while(!feof(fp))
		{
			fscanf(fp,"%s ", num);
			fscanf(fp,"%s\n", password);
			if(strcmp(scan_num, num) == 0 && f == 1)    //判断是否和输入的账号一样，如果一样输出 
			{
				i = 1;		
	            printf("\n\t账号\t\t密码\n");
				printf("\t%s\t\t%s\n",num,password);
				break;
			}
		}
		fclose(fp);
		if (i == 0) {
			printf("\t没有这个账号。");
		}
		printf("\n");
	    printf("\t ==================================================\n");
		printf("\t||          9----------返回上一层                 ||\n");                //完成 
	    printf("\t||          0----------退出系统                   ||\n");                //完成 
	    printf("\t ==================================================\n");
	    int choice = 0;
	char c[20];
	f = 1;
	scanf("%s", c);  //记录用户的选择并作为返回值返回 
	for (int i = 0; i < strlen(c); i++) {
		if (c[i] < '0' || c[i] > '9') {
			f = 0;
		}
		choice = choice * 10 + (c[i] - '0');
	}
	if (f == 0) {
		printf("输入有误。");
		glyzjm();
	}
	else {
	    switch(choice) {
			case 9:glyzjm();break;//返回上一层
			case 0:return;     //退出系统
			default:glyzjm();break;
		}
	}	
}
}
/*
1.3.5.修改账号和密码
*/
void Modify_admin()
{
	FILE *fp;
	FILE *fpn; 
	char newfilename[] = "Admin' Work temp.txt"; //一个临时文件 
	char num[50],tonum[50];
	char password[50],topassword[50];
	char p[20];
    int i=0, f = 1;
	system("cls");		//清屏
	if (strcmp(cx, "Admin' Work.txt") != 0){
		printf("\n   请输入想修改的账号:");
	    scanf("%s", tonum);
	}
	else {
		strcpy(tonum,nums);
	}
	f = pdzh(tonum);
	if (f == 0) {
		printf("\t错误的输入！！");
	}
	else {
	printf("\tPlease admin's password:");
	do {
          p[i]=getch();
          if(p[i]=='\r')
              break;
          if(p[i]=='\b') {
              if(i==0) {
                  printf("\a");
                  continue;
              }
              i=i-1;
              printf("\b");
              printf(" ");
              printf("\b");
          }
          else {
                i=i+1;
                printf("*");
          }
    }while(p[i]!='\n' && i<20);
            
    for(int j = 0; j < i; j++) {
         topassword[j] = p[j];
	} 

	i = 0;
}	        
	if( (fpn = fopen(newfilename,"w")) == NULL || (fp = fopen(cx,"r")) == NULL)   //打开文件，同上 
	{
		printf("Can't open the file.");
		exit(1);
	}
	else
	{	
		while(!feof(fp))
		{
			fscanf(fp,"%s ", num);   
			fscanf(fp,"%s\n", password);
			if(strcmp(tonum, num) == 0 && f == 1)    //判断是否和输入的账号一样，如果一样覆盖 
			{
				i = 1;
				fprintf(fpn,"%s %s\n",tonum,topassword);
				printf("\n\t修改成功。");
			}
			else
			{
				fprintf(fpn,"%s %s\n",num,password);
			}
		}
		fclose(fp);
		fclose(fpn);
		remove(cx);	//删除原文件
		rename(newfilename, cx);	//重命名新文件
		if (i == 0) {
			printf("\n\t不存在此账号。"); 
		}
		printf("\n");
	    printf("\t ==================================================\n");
		printf("\t||          9----------返回上一层                 ||\n");                //完成 
	    printf("\t||          0----------退出系统                   ||\n");                //完成 
	    printf("\t ==================================================\n");
	    int choice = 0;
	char c[20];
	f = 1;
	scanf("%s", c);  //记录用户的选择并作为返回值返回 
	for (int i = 0; i < strlen(c); i++) {
		if (c[i] < '0' || c[i] > '9') {
			f = 0;
		}
		choice = choice * 10 + (c[i] - '0');
	}
	if (f == 0) {
		printf("输入有误。");
		glyzjm();
	}
	else {
	    switch(choice) {
			case 9:glyzjm();break;//返回上一层
			case 0:return;     //退出系统
			default:glyzjm();break;
		}
	}	
}
} 
/*
1.3.4.删除账号和密码
*/
void Del_admin()
{
	FILE *fp;
	FILE *fpn; 
	char newfilename[] = "Admin temp.txt"; //一个临时文件 
	char num[50],tonum[50],password[50], f = 1;
	system("cls");		//清屏					    
	if( (fpn = fopen(newfilename,"w")) == NULL || (fp = fopen(cx,"r")) == NULL)   //打开文件，同上 
	{
		printf("Can't open the file.");
		exit(1);
	}
	else
	{	
	    if (strcmp(cx, "Admin' Work.txt") != 0){
		    printf("\n   请输入想删除的账号:");
	        scanf("%s", tonum);
	    }
	    else {
		    strcpy(tonum,nums);
	    }
	    f = pdzh(tonum);
		if (f == 0) {
			printf("\t错误的输入！！");
		}
		while(!feof(fp))
		{
			fscanf(fp,"%s ", num);  
			fscanf(fp,"%s\n", password);
			if(strcmp(tonum, num) == 0 && f == 1)    //判断是否和输入的学号一样，如果一样跳过写入临时文件 
			{
				printf("删除成功。");//做一次空操作 
			}
			else
			{
				fprintf(fpn,"%s %s",num,password);
			}
		}
		fclose(fp);
		fclose(fpn);
		remove(cx);	//删除原文件
		rename(newfilename, cx);	//重命名新文件
		printf("\n");
	    printf("\t ==================================================\n");
		printf("\t||          9----------返回上一层                 ||\n");                //完成 
	    printf("\t||          0----------退出系统                   ||\n");                //完成 
	    printf("\t ==================================================\n");
	    int choice = 0;
	char c[20];
	f = 1;
	scanf("%s", c);  //记录用户的选择并作为返回值返回 
	for (int i = 0; i < strlen(c); i++) {
		if (c[i] < '0' || c[i] > '9') {
			f = 0;
		}
		choice = choice * 10 + (c[i] - '0');
	}
	if (f == 0) {
		printf("输入有误。");
		glyzjm();
	}
	else {
	    switch(choice) {
			case 9:glyzjm();break;//返回上一层
			case 0:return;     //退出系统
			default:glyzjm();break;
		}
	}	
}
} 
/*
1.3.3.增加账号和密码
*/
void record_admin()
{
	system("cls");		//清屏
	FILE *fp;
	if( (fp = fopen("Admin' Work.txt","a")) == NULL ) //打开文件，如果打开失败给用户提示 
	{
		printf("Can't open the file.");
		exit(1);
	}
	else
	{
		int num, f = 1;          //保存账号
		printf("\tPlease Student's Num:\n");
		printf("\t(if you want to stop, input 0)");
		char zh[50];
		scanf("%s", zh);
		num = pdzh(zh);
		if (num == 0) {
			printf("\t错误的输入！！");
		}
		while(num!=0)    //循环输入直到用户输入的Num=0时停止录入 
		{
			f= zhpdcf("Admin' Work.txt",zh);
		    if (f == 0) {
		        break;
	        }
		        
		    char password[50];     //保存密码
		    char p[20];
            int i=0;
            
			fprintf(fp,"%s ",num);  //将num以及一个空格保存到文件中，下同
			 
			printf("\tPlease admin's password:");   //录入密码 
			 
			do {
                p[i]=getch();
                if(p[i]=='\r')
                     break;
                if(p[i]=='\b') {
                     if(i==0) {
                          printf("\a");
                          continue;
                     }
                     i=i-1;
                     printf("\b");
                     printf(" ");
                     printf("\b");
                }
                else {
                     i=i+1;
                     printf("*");
                }
            }while(p[i]!='\n' && i<20);
            
            for(int j = 0; j < i; j++) {
            	password[j] = p[j];
			} 
            
			fprintf(fp,"%s\n",password);
			
			printf("\tPlease Student's Num:\n");
		    printf("\t(if you want to stop, input 0)");
			scanf("%s", zh);
			num = pdzh(zh);
			if (num == 0) {
				printf("\t错误的输入！！");
				break;
			}
			f= zhpdcf("Admin' Work.txt",zh);
		    if (f == 0) {
		        break;
	        }
		}
		fclose(fp);   //关闭文件 
		printf("\n");
	    printf("\t ==================================================\n");
		printf("\t||          9----------返回上一层                 ||\n");                //完成 
	    printf("\t||          0----------退出系统                   ||\n");                //完成 
	    printf("\t ==================================================\n");
	    int choice = 0;
	    f = 1;
	char c[20];
	scanf("%s", c);  //记录用户的选择并作为返回值返回 
	for (int i = 0; i < strlen(c); i++) {
		if (c[i] < '0' || c[i] > '9') {
			f = 0;
		}
		choice = choice * 10 + (c[i] - '0');
	}
	if (f == 0) {
		printf("输入有误。");
		glyzjm();
	}
	else {
	    switch(choice) {
			case 9:zcjm();break;//返回上一层
			case 0:return;     //退出系统
			default:glyzjm();break;
		}
	}
}
}
/*
1.3.管理员主系统程序一览表
*/
int glyzjm()    
{
	system("cls");		//清屏 
	printf("\n ===================管理员主界面=================\n");
	printf("|| Enter                                          ||\n");
	printf("||          1----------返回主界面                 ||\n");       //ok
	printf("||          2----------进入教师端                 ||\n");       //ok
	printf("||          3----------增加账号和密码             ||\n");       //ok
	printf("||          4----------删除账号和密码             ||\n");       //ok
	printf("||          5----------修改账号和密码             ||\n");       //ok
	printf("||          6----------查找账号和密码             ||\n");       //ok
	printf("||          7----------输出所有账号和密码         ||\n");       //ok
	printf("||          8----------手动重新录入学生信息       ||\n");       //ok
	printf("||          0----------退出系统                   ||\n");       //ok
	printf(" ==================================================\n");
	printf("************************************************\nPlease Enter\n");
	int choice = 0, f = 1;
	char c[20];
	scanf("%s", c);  //记录用户的选择并作为返回值返回 
	for (int i = 0; i < strlen(c); i++) {
		if (c[i] < '0' || c[i] > '9') {
			f = 0;
		}
		choice = choice * 10 + (c[i] - '0');
	}
	if (f == 0) {
		printf("输入有误。");
		glyzjm();
	}
	else{
	switch(choice) {
		case 1:dljm();break;            //返回上一层
		case 2:jsdl();break;            //进入教师端
		case 3:zcjm();break;            //增加账号和密码
		case 4:scjm();break;            //删除账号和密码
	    case 5:xgjm();break;    //修改账号和密码
		case 6:cxjm();break;            //查找账号和密码
     	case 7:cxjm_all();break;        //输出所有账号和密码
     	case 8:Modify_admin_num();break;//手动重新录入学生信息
		case 0:return 0;                //退出系统
		default:dljm();break;
	}
    }
}
/*
学生登录界面
*/ 
void xxdl()
{
	system("cls");		//清屏
	printf("****************************************************\n");
	printf("\n=====================学生登录==================\n");
	FILE *fp;
	char num[50],scan_num[50];
	char password[50],scan_password[50];
	char p[20];
    int i=0,f;
	printf("\n   请输入你的账号:");
	scanf("%s", scan_num);
	strcpy(nums, scan_num);
	printf("\n   请输入你的密码:");
	do {
        p[i]=getch();
        if(p[i]=='\r')
            break;
        if(p[i]=='\b') {
            if(i==0) {
                printf("\a");
                continue;
            }
            i=i-1;
            printf("\b");
            printf(" ");
            printf("\b");
        }
        else {
            i=i+1;
            printf("*");
        }
    }while(p[i]!='\n' && i<20);
            
    for(int j = 0; j < i; j++) {
         scan_password[j] = p[j];
	} 
	
	if( (fp = fopen("Student' Work.txt","r")) == NULL)   //打开文件，同上
	{
		printf("Can't open the file.");
		exit(1);
	}
	else
	{
		while(!feof(fp))
		{
			char clas[20]="class0.txt";
			fscanf(fp,"%s", num);
			fscanf(fp,"%s", password);
			if(strcmp(scan_num, num) == 0 && pdmm(p,password) == 0)                  //判断是否和输入的学号一样，如果一样输出 
			{
			    fclose(fp);
			    clas[5]=num[1];
				strcpy(s,clas);
				strcpy(op_num,scan_num);
				xxzjm();
				return;
			}
		}
		fclose(fp);
		printf("\n\tYour input are wrong.");
		printf("\n");
	    printf("\t ==================================================\n");
		printf("\t||          1----------返回上一层                 ||\n"); 
		printf("\t||          9----------重新输入                   ||\n");                //完成 
	    printf("\t||          0----------退出系统                   ||\n");                //完成 
	    printf("\t ==================================================\n");
	    int choice = 0, f = 1;
		char c[20];
		scanf("%s", c);  //记录用户的选择并作为返回值返回 
		for (int i = 0; i < strlen(c); i++) {
			if (c[i] < '0' || c[i] > '9') {
				f = 0;
			}
			choice = choice * 10 + (c[i] - '0');
		}
		if (f == 0) {
			printf("输入有误。");
			xxdl();
		}
		else{	
	    switch(choice) {
			case 1:dljm();break;//返回上一层
			case 9:xxdl();break; //重新输入
			case 0:return;       //退出系统
			default:xxdl();break;
		}
	}
    }
}
/*
教师登录界面
*/ 
void jsdl()
{
	system("cls");		//清屏
	printf("**************************************************\n");
	printf("\n====================教师登录==================\n");
	FILE *fp;
	char num[50],scan_num[50];
	char password[50],scan_password[50];
	char p[20];
    int i=0;
	printf("\n   请输入你的账号:");
	scanf("%s", scan_num);
	strcpy(nums, scan_num);
	printf("\n   请输入你的密码:");
	do {
        p[i]=getch();
        if(p[i]=='\r')
            break;
        if(p[i]=='\b') {
            if(i==0) {
                printf("\a");
                continue;
            }
            i=i-1;
            printf("\b");
            printf(" ");
            printf("\b");
        }
        else {
            i=i+1;
            printf("*");
        }
    }while(p[i]!='\n' && i<20);
	
	if( (fp = fopen("Teacher' Work.txt","r")) == NULL)   //打开文件，同上
	{
		printf("Can't open the file.");
		exit(1);
	}
	else
	{
		while(!feof(fp))
		{
			fscanf(fp,"%s", num);
			fscanf(fp,"%s", password);
			if(strcmp(scan_num, num) == 0 && pdmm(p,password) == 0 )                 //判断是否和输入的学号一样，如果一样输出 
			{
			    fclose(fp);
			    strcpy(s,"allclass.txt");
				jszjm();
				return;
			}
		}
		fclose(fp);
		printf("\n\tYour input are wrong.");
		printf("\n");
	    printf("\t ==================================================\n");
		printf("\t||          1----------返回上一层                 ||\n"); 
		printf("\t||          9----------重新输入                   ||\n");                //完成 
	    printf("\t||          0----------退出系统                   ||\n");                //完成 
	    printf("\t ==================================================\n");
	    int choice = 0, f = 1;
		char c[20];
		scanf("%s", c);  //记录用户的选择并作为返回值返回 
		for (int i = 0; i < strlen(c); i++) {
			if (c[i] < '0' || c[i] > '9') {
				f = 0;
			}
			choice = choice * 10 + (c[i] - '0');
		}
		if (f == 0) {
			printf("输入有误。");
			jsdl();
		}
		else{	
	    switch(choice) {
			case 1:dljm();break;//返回上一层
			case 9:jsdl();break; //重新输入
			case 0:return;       //退出系统
			default:dljm();break;
		}
	}
	}
}
/*
管理员登录界面
*/ 
void glydl()
{
	system("cls");		//清屏
	printf("*****************************************************\n");
	printf("\n====================管理员登录==================\n");
	FILE *fp;
	char num[50],scan_num[50];
	char password[50];
	char p[20];
    int i=0;
	printf("\n   请输入你的账号:");
	scanf("%s", scan_num);
	strcpy(nums, scan_num);
	printf("\n   请输入你的密码:");
	do {
        p[i]=getch();
        if(p[i]=='\r')
            break;
        if(p[i]=='\b') {
            if(i==0) {
                printf("\a");
                continue;
            }
            i=i-1;
            printf("\b");
            printf(" ");
            printf("\b");
        }
        else {
            i=i+1;
            printf("*");
        }
    }while(p[i]!='\n' && i<20);
	
	if( (fp = fopen("Admin' Work.txt","r")) == NULL)   //打开文件，同上
	{
		printf("Can't open the file.");
		exit(1);
	}
	while(!feof(fp))
	{
		fscanf(fp,"%s ", num);
		fscanf(fp,"%s\n", password);
		if(strcmp(scan_num, num) == 0 && pdmm(p, password) == 0)                  //判断是否和输入的学号一样，如果一样输出 
		{
			fclose(fp);
			glyzjm();
			return;
		}
	}
	fclose(fp);
	printf("\n\tYour input are wrong.");
	printf("\n");
	printf("\t ==================================================\n");
	printf("\t||          1----------返回上一层                 ||\n"); 
	printf("\t||          9----------重新输入                   ||\n");                //完成 
	printf("\t||          0----------退出系统                   ||\n");                //完成 
	printf("\t ==================================================\n");
	int choice = 0, f = 1;
	char c[20];
	scanf("%s", c);  //记录用户的选择并作为返回值返回 
	for (int i = 0; i < strlen(c); i++) {
		if (c[i] < '0' || c[i] > '9') {
			f = 0;
		}
		choice = choice * 10 + (c[i] - '0');
	}
	if (f == 0) {
		printf("输入有误。");
		glydl();
	}
	else{
	    switch(choice) {
			case 1:dljm();break;//返回上一层
			case 9:glydl();break; //重新输入
			case 0:return;       //退出系统
			default:glydl();break;
		}
	}
}
/*
学生注册界面 
*/
void xxzc()
{
	system("cls");		//清屏
	FILE *fp;
	if( (fp = fopen("Student' Work.txt","a")) == NULL ) //打开文件，如果打开失败给用户提示 
	{
		printf("Can't open the file.");
		exit(1);
	}
	else
	{
		printf("****************************************************\n");
	    printf("\n ====================学生注册==================\n");
		int num, f = 1;          //保存账号
		char p[20],zh[50],password[50];
		printf("\tPlease Student's Num:\n");
		printf("\t(if you want to stop, input 0)");
		scanf("%s", zh);
		num = pdzh(zh);
        if (num == 0) {
	        printf("\t错误的输入！！"); 
        }
		while(num!=0)    //循环输入直到用户输入的Num=0时停止录入 
		{
			f= zhpdcf("Student' Work.txt",zh);
		    if (f == 0) {
		        break;
	        }
	        
		    int i = 0;  //保存密码
			
			fprintf(fp,"%s ",zh);  //将num以及一个空格保存到文件中，下同
			 
			printf("\tPlease student's password:");   //录入密码 
			 
			do {
		           
                p[i]=getch();
                if(p[i]=='\r')
                     break;
                if(p[i]=='\b') {
                     if(i==0) {
                          printf("\a");
                          continue;
                     }
                     i=i-1;
                     printf("\b");
                     printf(" ");
                     printf("\b");
                }
                else {
                     i=i+1;
                     printf("*");
                }
            }while(p[i]!='\n' && i<20);
            
            for(int j = 0; j < i; j++) {
            	password[j] = p[j];
			} 
            
			fprintf(fp,"%s\n",password);
			
			printf("\n\tPlease Student's Num:\n");
		    printf("\t(if you want to stop, input 0)");
			scanf("%s", zh);
		    num = pdzh(zh);
            if (num == 0) {
	            printf("\t错误的输入！！"); 
            }
            f= zhpdcf("Student' Work.txt",zh);
		    if (f == 0) {
		        break;
	        }
		}
		fclose(fp);   //关闭文件 
		printf("\n");
	    printf("\t ==================================================\n");
	    printf("\t||          8----------返回登录界面               ||\n");                //完成 
		printf("\t||          9----------返回上一层                 ||\n");                //完成 
	    printf("\t||          0----------退出系统                   ||\n");                //完成 
	    printf("\t ==================================================\n");
	    int choice = 0;
	    f = 1;
		char c[20];
		scanf("%s", c);  //记录用户的选择并作为返回值返回 
		for (int i = 0; i < strlen(c); i++) {
			if (c[i] < '0' || c[i] > '9') {
				f = 0;
			}
			choice = choice * 10 + (c[i] - '0');
		}
		if (f == 0) {
			printf("输入有误。");
			dljm();
		}
		else {
	    	switch(choice) {
	    		case 8:dljm();break;//返回上一层
				case 9:zcjm();break;//返回上一层
				case 0:return;      //退出系统
				default:dljm();break;
			}
		}
	}
}
/*
教师注册界面 
*/
void jszc()
{
	system("cls");		//清屏
	FILE *fp;
	if( (fp = fopen("Teacher' Work.txt","a")) == NULL ) //打开文件，如果打开失败给用户提示 
	{
		printf("Can't open the file.");
		exit(1);
	}
	else
	{
		printf("****************************************************\n");
	    printf("\n ====================教师注册==================\n");
		int num, f = 1;          //保存账号
		char p[20],zh[50];
		printf("\tPlease Student's Num:\n");
		printf("\t(if you want to stop, input 0)");
		scanf("%s", zh);
		num = pdzh(zh);
        if (num == 0) {
	        printf("\t错误的输入！！"); 
        }
		while(num!=0)    //循环输入直到用户输入的Num=0时停止录入 
		{
			f= zhpdcf("Teacher' Work.txt",zh);
		    if (f == 0) {
		        break;
	        }
			
		    int i = 0;  //保存密码
			
			fprintf(fp,"%s ",zh);  //将num以及一个空格保存到文件中，下同
			 
			printf("\tPlease teacher's password:");   //录入密码 
			 
			do {
		           
                p[i]=getch();
                if(p[i]=='\r')
                     break;
                if(p[i]=='\b') {
                     if(i==0) {
                          printf("\a");
                          continue;
                     }
                     i=i-1;
                     printf("\b");
                     printf(" ");
                     printf("\b");
                }
                else {
                     i=i+1;
                     printf("*");
                }
            }while(p[i]!='\n' && i<20);
            
			fprintf(fp,"%s\n",p);
			
			printf("\n\tPlease Student's Num:\n");
		    printf("\t(if you want to stop, input 0)");
			scanf("%s", zh);
			num = pdzh(zh);
        	if (num == 0) {
	        	printf("\t错误的输入！！"); 
       	 	}
       	 	
		    f= zhpdcf("Teacher' Work.txt",zh);
		    if (f == 0) {
		        break;
	        }
		}
		fclose(fp);   //关闭文件 
		printf("\n");
	    printf("\t ==================================================\n");
	    printf("\t||          8----------返回登录界面               ||\n");                //完成 
		printf("\t||          9----------返回上一层                 ||\n");                //完成 
	    printf("\t||          0----------退出系统                   ||\n");                //完成 
	    printf("\t ==================================================\n");
	    int choice = 0;
	    f = 1;
	char c[20];
	scanf("%s", c);  //记录用户的选择并作为返回值返回 
	for (int i = 0; i < strlen(c); i++) {
		if (c[i] < '0' || c[i] > '9') {
			f = 0;
		}
		choice = choice * 10 + (c[i] - '0');
	}
	if (f == 0) {
		printf("输入有误。");
		dljm();
	}
	else {
	    switch(choice) {
			case 8:dljm();break;//返回登录界面
			case 9:zcjm();break;//返回上一层
			case 0:return;      //退出系统
			default:dljm();break;
		}
	}
}
}
/*
用户注册界面 
*/
int zcjm()    
{
	system("cls");		//清屏 
	printf("\n ====================注册界面==================\n");
	printf("|| Enter                                      ||\n");
	printf("||          1----------学生注册               ||\n");
	printf("||          2----------教师注册               ||\n");
	printf("||          3----------管理员注册             ||\n");
	printf("||          9----------返回上一层             ||\n");
	printf("||          0----------退出系统               ||\n");
	printf(" ==============================================\n");
	printf("************************************************\nPlease Enter\n");
	int choice = 0, f = 1;
	char c[20];
	scanf("%s", c);  //记录用户的选择并作为返回值返回 
	for (int i = 0; i < strlen(c); i++) {
		if (c[i] < '0' || c[i] > '9') {
			f = 0;
		}
		choice = choice * 10 + (c[i] - '0');
	}
	if (f == 0) {
		printf("输入有误。");
		dljm();
	}
	else {
	switch(choice) {
		case 1:xxzc();break;         //学生注册
		case 2:jszc();break;         //教师注册
		case 3:record_admin();break; //管理员注册
		case 9:glyzjm();break;       //返回上一层
		case 0:return 0;             //退出系统
		default:dljm();break;
	}
	}
}
/*
1.登录界面
*/
int dljm()    
{
	system("cls");		//清屏 
	printf("\n ===================登录界面=================\n");
	printf("|| Enter                                      ||\n");
	printf("||          1----------学生登录               ||\n");
	printf("||          2----------教师登录               ||\n");
	printf("||          3----------管理员登录             ||\n");
	printf("||          4----------用户注册               ||\n");
	printf("||          0----------退出系统               ||\n");
	printf(" ==============================================\n");
	printf("************************************************\nPlease Enter\n");
	int choice = 0, f = 1;
	char c[20];
	scanf("%s", c);  //记录用户的选择并作为返回值返回 
	for (int i = 0; i < strlen(c); i++) {
		if (c[i] < '0' || c[i] > '9') {
			f = 0;
		}
		choice = choice * 10 + (c[i] - '0');
	}
	if (f == 0) {
		printf("输入有误。");
		dljm();
	}
	else {
		switch(choice) {
			case 1:xxdl();break; //学生登录
			case 2:jsdl();break; //教师登录
			case 3:glydl();break;//管理员登录
			case 4:glydl();break;//用户注册
			case 0:return 0;     //退出系统
			default:dljm();break;
		}
	}
}
/*
主程序（封装查询）
*/
int main() {
	system("color f0");
	dljm();
}


