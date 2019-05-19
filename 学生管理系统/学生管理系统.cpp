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
�����ѯ���� 
*/
void cjpxjm()
{
	printf("\n ===================��ѯ�༶===================\n");
	printf("|| Enter                                          ||\n");
	printf("||          1----------����1��                    ||\n");                //��� 
	printf("||          2----------����2��                    ||\n");                //��� 
	printf("||          3----------����3��                    ||\n");                //��� 
	printf("||          4----------����4��                    ||\n");                //���
	printf("||          5----------����5��                    ||\n");                //��� 
	printf("||          6----------�����꼶                   ||\n");                //��� 
	printf("||          0----------�˳�ϵͳ                   ||\n");                //��� 
	printf(" ==================================================\n");
	printf("************************************************\nPlease Enter\n");
	int choice = 0, f = 1;
	char num[50],name[50],bj[50],yw[50],sx[50],yy[50] , i[50], source[50];
	char c[20],s6[50];
	scanf("%s", c);  //��¼�û���ѡ����Ϊ����ֵ���� 
	for (int i = 0; i < strlen(c); i++) {
		if (c[i] < '0' || c[i] > '9') {
			f = 0;
		}
		choice = choice * 10 + (c[i] - '0');
	}
	if (f == 0) {
		printf("��������");
		jszjm();
	}
	else{
		system("cls");		//����
		switch(choice) {
			case 1:strcpy(scj,"class1.txt");break;        //ѧ����Ϣ����
			case 2:strcpy(scj,"class2.txt");break;       //ɾ��ѧ����Ϣ
			case 3:strcpy(scj,"class3.txt");break;       //�޸�ѧ����Ϣ
			case 4:strcpy(scj,"class4.txt");break;       //��ѯѧ����Ϣ
			case 5:strcpy(scj,"class5.txt");break;                     //������һ��
			case 6:strcpy(scj,"allclass.txt");break;                        //�˳�ϵͳ
			case 0:return;                        //�˳�ϵͳ
			default:jszjm();break;
		}
		if(choice != 0) { 
		cjpx();
		FILE *fp;
	    if ((fp = fopen("�ɼ�����.txt", "r")) == NULL) {
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
		printf("\t||          9----------������һ��                 ||\n");                //��� 
	    printf("\t||          0----------�˳�ϵͳ                   ||\n");                //��� 
	    printf("\t ==================================================\n");
	    choice = 0;
		f = 1;
		scanf("%s", c);  //��¼�û���ѡ����Ϊ����ֵ���� 
		for (int i = 0; i < strlen(c); i++) {
			if (c[i] < '0' || c[i] > '9') {
				f = 0;
			}
			choice = choice * 10 + (c[i] - '0');
		}
		if (f == 0) {
			printf("��������");
			jszjm();
		}
		else {
		system("cls");		//���� 
		    switch(choice) {
				case 9:jszjm();break;//������һ��
				case 0:return;     //�˳�ϵͳ
				default:jszjm();break;
			}
		}
		}	
    }
}
/*
���ļ���������(ѧ����Ϣ)
����ֵ��phead 
*/
struct student * Read1()                          
{
	char ch;
	int a,b,d;
	FILE *fp,*fpn;
	fp = fopen(scj, "r");
	fpn = fopen("�ɼ�����.txt", "w+");
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
�������� 
*/
void cjpx_yw(struct student *head)      //���� 
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
void cjpx_sx(struct student *head)      //��ѧ 
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
void cjpx_yy(struct student *head)      //Ӣ�� 
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
void cjpx_source(struct student *head)      //�ܷ� 
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
���� 
*/
void cjpx() 
{
	char subject[50];
	system("cls");		//���� 
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
	fp = fopen("�ɼ�����.txt", "w+");
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
������ 
*/
void scjg() 
{
	FILE *fp,*fpn;
	char name[50],toname[50],ch;
	char num[50],bj[50],yw[50],sx[50],yy[50];
	if((fp = fopen("�����ѯ.txt","r")) == NULL )   //���ļ���ͬ�� 
	{
		printf("Can't open the file.");
		exit(1);
	}
	ch=fgetc(fp);
    if(ch==EOF) {
        printf("\n\t�������\n");
    }
    else { 
        fseek(fp,0,SEEK_SET);
        printf("\n\t����\tѧ��\t�༶\t����\t��ѧ\tӢ��\n");
        //fgetc(fp);
	    while(!feof(fp)) {
		    fscanf(fp,"%s %s %s %s %s %s\n",name,num,bj,yw,sx,yy);
		    printf("\t%s\t%s\t%s\t%s\t%s\t%s\n",name,num,bj,yw,sx,yy);
	    }
	} 
	fclose(fp);
	printf("\n");
	    printf("\t ==================================================\n");
		printf("\t||          9----------������һ��                 ||\n");                //��� 
	    printf("\t||          0----------�˳�ϵͳ                   ||\n");                //��� 
	    printf("\t ==================================================\n");
	    int choice = 0, f = 1;
	char c[20];
	scanf("%s", c);  //��¼�û���ѡ����Ϊ����ֵ���� 
	for (int i = 0; i < strlen(c); i++) {
		if (c[i] < '0' || c[i] > '9') {
			f = 0;
		}
		choice = choice * 10 + (c[i] - '0');
	}
	if (f == 0) {
		printf("��������");
		query_teacher_qjcxjm();
	}
	else {
	system("cls");		//���� 
	    switch(choice) {
			case 9:query_teacher_qjcxjm();break;//������һ��
			case 0:return;     //�˳�ϵͳ
			default:query_teacher_qjcxjm();break;
		}
	}	
}
/*
�����ѯ 
*/
void qjcx()
{
    FILE *fpn,*fp;
	char name[50],toname[50];
	char num[50],bj[50],yw[50],sx[50],yy[50];
	int f = 0;
	if((fpn = fopen("�����ѯ.txt","r")) == NULL || (fp = fopen("cx.txt","w+")) == NULL)   //���ļ���ͬ�� 
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
		printf("\n\tplease input the ����:\n");
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
					remove("�����ѯ.txt");	//ɾ��ԭ�ļ�
		            rename("cx.txt", "�����ѯ.txt");	//���������ļ�
					printf("\n");
	        		printf("\t ==================================================\n");
		    		printf("\t||          8----------������                   ||\n");
		    		printf("\t||          9----------����ѡ������               ||\n");                //��� 
	        		printf("\t||          0----------�˳�ϵͳ                   ||\n");                //��� 
	        		printf("\t ==================================================\n");
	        		int choice = 0;
	        		f = 1; 
    	    		char c[20];
	        		scanf("%s", c);  //��¼�û���ѡ����Ϊ����ֵ���� 
	        		for (int i = 0; i < strlen(c); i++) {
	    	    		if (c[i] < '0' || c[i] > '9') {
	    		  		    f = 0;
    	    			}
	        			choice = choice * 10 + (c[i] - '0');
	        		}
    	    		if (f == 0) {
	    	    		printf("��������");
		        		scjg();
    	    		}
	        		else {
	        		system("cls");		//���� 
	            		switch(choice) {
		    	    		case 8:scjg();break;//������һ��
		    	    		case 9:qjcx();break;//������һ��
		    	    		case 0:return;     //�˳�ϵͳ
		    	    		default:scjg();break;
		        		}
	        		}	
				} 
			}
		}
	} 
}
/*
�����ѯ���� 
*/
void query_teacher_qjcxjm()
{
	printf("\n ===================��ѯ�༶===================\n");
	printf("|| Enter                                          ||\n");
	printf("||          1----------����1��                    ||\n");                //��� 
	printf("||          2----------����2��                    ||\n");                //��� 
	printf("||          3----------����3��                    ||\n");                //��� 
	printf("||          4----------����4��                    ||\n");                //���
	printf("||          5----------����5��                    ||\n");                //��� 
	printf("||          6----------�����꼶                   ||\n");                //��� 
	printf("||          9----------������һ��                 ||\n");                //��� 
	printf("||          0----------�˳�ϵͳ                   ||\n");                //��� 
	printf(" ==================================================\n");
	printf("************************************************\nPlease Enter\n");
	int choice = 0, f = 1;
	char c[20],s6[50];
	scanf("%s", c);  //��¼�û���ѡ����Ϊ����ֵ���� 
	for (int i = 0; i < strlen(c); i++) {
		if (c[i] < '0' || c[i] > '9') {
			f = 0;
		}
		choice = choice * 10 + (c[i] - '0');
	}
	if (f == 0) {
		printf("��������");
		jszjm();
	}
	else{
	system("cls");		//����
	switch(choice) {
		case 1:strcpy(sin,"class1.txt");break;        //ѧ����Ϣ����
		case 2:strcpy(sin,"class2.txt");break;       //ɾ��ѧ����Ϣ
		case 3:strcpy(sin,"class3.txt");break;       //�޸�ѧ����Ϣ
		case 4:strcpy(sin,"class4.txt");break;       //��ѯѧ����Ϣ
		case 5:strcpy(sin,"class5.txt");break;                     //������һ��
		case 6:strcpy(sin,"allclass.txt");break;                        //�˳�ϵͳ
		case 9:jszxt();break;                     //������һ��
		case 0:return;                        //�˳�ϵͳ
		default:jszjm();break;
	}
    FILE *fp,*fpn;
	char name[50],toname[50];
	char num[50],bj[50],yw[50],sx[50],yy[50];
	if((fpn = fopen("�����ѯ.txt","w+")) == NULL || (fp = fopen(sin,"r")) == NULL)   //���ļ���ͬ�� 
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
�༶�ܳɼ� 
*/
void query_teacher_bj(){
	FILE *fp;
	char name[50],toname[50],s6[50]="class0.txt";
	char num[50],bj[50],yw[50],sx[50],yy[50];
	int f = 1;
	printf("\n\tplease input the class numble:");
	scanf("%c", &s6[20]);
	scanf("%c", &s6[5]);
	if((fp = fopen(s6,"r")) == NULL)   //���ļ���ͬ�� 
	{
		printf("Can't open the file.");
		exit(1);
	}
	printf("\n\t����\tѧ��\t�༶\t����\t��ѧ\tӢ��\n");
	while(!feof(fp)){
		fscanf(fp,"%s %s %s %s %s %s\n",name,num,bj,yw,sx,yy);
		printf("\t%s\t%s\t%s\t%s\t%s\t%s\n",name,num,bj,yw,sx,yy);
	}
	fclose(fp);
	printf("\n");
	    printf("\t ==================================================\n");
		printf("\t||          9----------������һ��                 ||\n");                //��� 
	    printf("\t||          0----------�˳�ϵͳ                   ||\n");                //��� 
	    printf("\t ==================================================\n");
	    int choice = 0;
	char c[20];
	scanf("%s", c);  //��¼�û���ѡ����Ϊ����ֵ���� 
	for (int i = 0; i < strlen(c); i++) {
		if (c[i] < '0' || c[i] > '9') {
			f = 0;
		}
		choice = choice * 10 + (c[i] - '0');
	}
	if (f == 0) {
		printf("��������");
		pdcx();
	}
	else {
	system("cls");		//���� 
	    switch(choice) {
			case 9:pdcx();break;//������һ��
			case 0:return;     //�˳�ϵͳ
			default:pdcx();break;
		}
	}	
}
/*
���ֲ�ѯ 
*/
void query_teacher_name(){ 
	FILE *fp;
	char name[50],toname[50];
	char num[50],bj[50],yw[50],sx[50],yy[50];
	int f = 0;
	if((fp = fopen(s,"r")) == NULL)   //���ļ���ͬ�� 
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
	        printf("\n\t����\tѧ��\t�༶\t����\t��ѧ\tӢ��\n");
			printf("\t%s\t%s\t%s\t%s\t%s\t%s\n",name,num,bj,yw,sx,yy);
			break;
		}
	}
	if (f == 0) {
		printf("û�д�ͬѧ��");
	}
	fclose(fp);
	printf("\n");
	    printf("\t ==================================================\n");
		printf("\t||          9----------������һ��                 ||\n");                //��� 
	    printf("\t||          0----------�˳�ϵͳ                   ||\n");                //��� 
	    printf("\t ==================================================\n");
	    int choice = 0;
	    f = 1;
	char c[20];
	scanf("%s", c);  //��¼�û���ѡ����Ϊ����ֵ���� 
	for (int i = 0; i < strlen(c); i++) {
		if (c[i] < '0' || c[i] > '9') {
			f = 0;
		}
		choice = choice * 10 + (c[i] - '0');
	}
	if (f == 0) {
		printf("��������");
		pdcx();
	}
	else {
	system("cls");		//����
	    switch(choice) {
			case 9:pdcx();break;//������һ��
			case 0:return;     //�˳�ϵͳ
			default:pdcx();break;
		}
	}	
}
/*
(��ʦ����ѯ��ʽ
*/
void pdcx()
{
	printf("\n ===================��ѯ��ʽ===================\n");
	printf("|| Enter                                          ||\n");
	printf("||          1----------ѧ�Ų�ѯ                   ||\n");                //��� 
	printf("||          2----------������ѯ                   ||\n");                //��� 
	printf("||          3----------�༶��ѯ                   ||\n");                //��� 
	printf("||          4----------���ɼ������ѯ             ||\n");                //���
	printf("||          8----------������һ��                 ||\n");                //��� 
	printf("||          0----------�˳�ϵͳ                   ||\n");                //��� 
	printf(" ==================================================\n");
	printf("************************************************\nPlease Enter\n");
	int choice = 0, f = 1;
	char c[20];
	scanf("%s", c);  //��¼�û���ѡ����Ϊ����ֵ���� 
	for (int i = 0; i < strlen(c); i++) {
		if (c[i] < '0' || c[i] > '9') {
			f = 0;
		}
		choice = choice * 10 + (c[i] - '0');
	}
	if (f == 0) {
		printf("��������");
		jszjm();
	}
	else{
	system("cls");		//����
	switch(choice) {
		case 1:query_teacher_num();break;        //ѧ����Ϣ����
		case 2:query_teacher_name();break;       //ɾ��ѧ����Ϣ
		case 3:query_teacher_bj();break;       //�޸�ѧ����Ϣ
		case 4:query_teacher_qjcxjm();break;       //��ѯѧ����Ϣ
		case 8:jszjm();;break;                     //������һ��
		case 0:return;                         //�˳�ϵͳ
		default:jszjm();;break;
	}
}
}
/*
�˺��ж��ظ��� 
*/
int zhpdcf(const char *s2,const char *num1)
{
	FILE *fp;
	char password[50],num[50];
	int f = 1;
	if( (fp = fopen(s2,"r")) == NULL)   //���ļ���ͬ�� 
	{
		printf("Can't open the file.");
		exit(1);
	}
	while(!feof(fp)) {
		fscanf(fp,"%s ",num);
		fscanf(fp,"%s\n",password);
		if (strcmp(num1, num) == 0) {
			f = 0;
			printf("\n\t���д��˺š�\n");
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
ѧ����Ϣ�ж��ظ��� 
*/
int pdcf(char *s2,char *num1)
{
	FILE *fp;
	char name[50],num[50],bj[50],a[20],b[20],d[20];
	int f = 1;
	if( (fp = fopen(s2,"r")) == NULL)   //���ļ���ͬ�� 
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
			printf("\n\t���д�ͬѧ��\n");
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
ת���ɼ� 
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
�޸��˺Ž��� 
*/
int xgjm()    
{
	system("cls");		//���� 
	printf("\n ====================ɾ������==================\n");
	printf("|| Enter                                        ||\n");
	printf("||          1----------ѧ���˺�                 ||\n");
	printf("||          2----------��ʦ�˺�                 ||\n");
	printf("||          3----------����Ա�˺�               ||\n");
	printf("||          9----------������һ��               ||\n");
	printf("||          0----------�˳�ϵͳ                 ||\n");
	printf(" ============================================\n");
	printf("************************************************\nPlease Enter\n");
	int choice;
	scanf("%d",&choice);  //��¼�û���ѡ����Ϊ����ֵ���� 
	switch(choice) {
		case 1:strcpy(cx,"Student' Work.txt");Modify_admin();break;//��ѯѧ��
		case 2:strcpy(cx,"Teacher' Work.txt");Modify_admin();break;//��ѯ��ʦ
		case 3:strcpy(cx,"Admin' Work.txt");Modify_admin();break;  //��ѯ����Ա
		case 9:glyzjm();break;  //��ѯ����Ա
		case 0:return 0;    //�˳�ϵͳ
		default:glyzjm();break;
	}
}
/*
ɾ���˺Ž��� 
*/
int scjm()    
{
	system("cls");		//���� 
	printf("\n ====================ɾ������==================\n");
	printf("|| Enter                                        ||\n");
	printf("||          1----------ѧ���˺�                 ||\n");
	printf("||          2----------��ʦ�˺�                 ||\n");
	printf("||          3----------����Ա�˺�               ||\n");
	printf("||          9----------������һ��               ||\n");
	printf("||          0----------�˳�ϵͳ                 ||\n");
	printf(" ============================================\n");
	printf("************************************************\nPlease Enter\n");
	int choice;
	scanf("%d",&choice);  //��¼�û���ѡ����Ϊ����ֵ���� 
	switch(choice) {
		case 1:strcpy(cx,"Student' Work.txt");Del_admin();break;//��ѯѧ��
		case 2:strcpy(cx,"Teacher' Work.txt");Del_admin();break;//��ѯ��ʦ
		case 3:strcpy(cx,"Admin' Work.txt");Del_admin();break;  //��ѯ����Ա
		case 9:glyzjm();break;  //��ѯ����Ա
		case 0:return 0;    //�˳�ϵͳ
		default:glyzjm();break;
	}
}
/*
��ѯȫ���˺Ž��� 
*/
int cxjm_all()    
{
	system("cls");		//���� 
	printf("\n ====================��ѯ����==================\n");
	printf("|| Enter                                        ||\n");
	printf("||          1----------ѧ���˺�                 ||\n");
	printf("||          2----------��ʦ�˺�                 ||\n");
	printf("||          9----------������һ��               ||\n");
	printf("||          0----------�˳�ϵͳ                 ||\n");
	printf(" ============================================\n");
	printf("************************************************\nPlease Enter\n");
	int choice;
	scanf("%d",&choice);  //��¼�û���ѡ����Ϊ����ֵ���� 
	switch(choice) {
		case 1:strcpy(cx,"Student' Work.txt");query_all_admin();break;//��ѯѧ��
		case 2:strcpy(cx,"Teacher' Work.txt");query_all_admin();break;//��ѯ��ʦ
		case 9:glyzjm();break;  //��ѯ����Ա
		case 0:return 0;    //�˳�ϵͳ
		default:glyzjm();break;
	}
}
/*
��ѯ�����˺Ž��� 
*/
int cxjm()    
{
	system("cls");		//���� 
	printf("\n ====================��ѯ����==================\n");
	printf("|| Enter                                      ||\n");
	printf("||          1----------��ѯѧ���˺�           ||\n");
	printf("||          2----------��ѯ��ʦ�˺�           ||\n");
	printf("||          3----------��ѯ����Ա�˺�         ||\n");
	printf("||          9----------������һ��               ||\n");
	printf("||          0----------�˳�ϵͳ               ||\n");
	printf(" ==============================================\n");
	printf("************************************************\nPlease Enter\n");
	int choice;
	scanf("%d",&choice);  //��¼�û���ѡ����Ϊ����ֵ���� 
	switch(choice) {
		case 1:strcpy(cx,"Student' Work.txt");query_admin();break;//��ѯѧ��
		case 2:strcpy(cx,"Teacher' Work.txt");query_admin();break;//��ѯ��ʦ
		case 3:strcpy(cx,"Admin' Work.txt");query_admin();break;  //��ѯ����Ա
		case 9:glyzjm();break;  //��ѯ����Ա
		case 0:return 0;    //�˳�ϵͳ
		default:glyzjm();break;
	}
}
/*
�жϳɼ��Ƿ���ȷ
*/
int pdcj(int yw,int sx,int yy)
{
	if (yw < 0 || yw > 100 || sx < 0 || sx > 100 || yy < 0 || yy > 100) {
		    return 0;
	}
	return 1;
}
/*
�ж������Ƿ���ȷ
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
�ж������Ƿ���ͬ
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
�жϰ༶�Ƿ���ȷ
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
�ж��˺��Ƿ���ȷ 
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
1.1.1.�ɼ���ѯ������ѧ�ţ�
*/
void query_num()
{
	system("cls");		//���� 
	FILE *fp;
	char num[50],scan_num[50];
	int yw, sx, yy, i = 0, f;
	if( (fp = fopen(s,"r")) == NULL)   //���ļ���ͬ�� 
	{
		printf("Can't open the file.");
		exit(1);
	}
	else 
	{
		f = pdzh(nums);
		if (f == 0) {
			printf("\t��������룡��"); 
		}
		else {
		    system("cls");		//����
			printf("\n\tѧ��\t����\t�༶\t����\t��ѧ\tӢ��\n");
			while(!feof(fp))
			{
				char namecpy[20], bj[20];
				fscanf(fp, "%s", namecpy);
				fscanf(fp, "%s",  num);
				if(strcmp(nums, num) == 0)    //�ж��Ƿ�������ѧ��һ�������һ����� 
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
			printf("\tû�����ѧ����");
		}
		printf("\n");
	    printf("\t ==================================================\n");
		printf("\t||          9----------������һ��                 ||\n");                //��� 
	    printf("\t||          0----------�˳�ϵͳ                   ||\n");                //��� 
	    printf("\t ==================================================\n");
	    int choice = 0, f = 1;
	char c[20];
	scanf("%s", c);  //��¼�û���ѡ����Ϊ����ֵ���� 
	for (int i = 0; i < strlen(c); i++) {
		if (c[i] < '0' || c[i] > '9') {
			f = 0;
		}
		choice = choice * 10 + (c[i] - '0');
	}
	if (f == 0) {
		printf("��������");
		xxzjm();
	}
	else {
	    switch(choice) {
			case 9:xxzjm();break;//������һ��
			case 0:return;     //�˳�ϵͳ
			default:xxzjm();break;
		}
	}	
}
}
/*
1.1.2.��ѯ����ɼ�
*/
void query()
{	
	system("cls");		//���� 
	FILE *fp;
	char num[50];
	int yw, sx, yy;
	printf("\n\tѧ��\t����\t�༶\t����\t��ѧ\tӢ��\n");
	printf("\t============================================\n");
	if( (fp = fopen(s,"r")) == NULL)   //���ļ���ͬ��
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
		printf("\t||          9----------������һ��                 ||\n");                //��� 
	    printf("\t||          0----------�˳�ϵͳ                   ||\n");                //��� 
	    printf("\t ==================================================\n");
	    int choice = 0, f = 1;
	char c[20];
	scanf("%s", c);  //��¼�û���ѡ����Ϊ����ֵ���� 
	for (int i = 0; i < strlen(c); i++) {
		if (c[i] < '0' || c[i] > '9') {
			f = 0;
		}
		choice = choice * 10 + (c[i] - '0');
	}
	if (f == 0) {
		printf("��������");
		xxzjm();
	}
	else {
	    switch(choice) {
			case 9:xxzjm();break;//������һ��
			case 0:return;     //�˳�ϵͳ
			default:xxzjm();break;
		}
	}
}
}
/*
1.1.3.�ɼ�����
*/
void fx_num()
{
	system("cls");		//���� 
	char pmfw[50];
	int op = 1;
	printf("\n\t��ѯ�༶���� or �꼶������");
	scanf("%s",pmfw);
	if (strcmp(pmfw,"�༶����") == 0) {
		strcpy(scj,s);
	}
	else if (strcmp(pmfw,"�꼶����") == 0) {
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
	if( (fp = fopen("�ɼ�����.txt","r")) == NULL)   //���ļ���ͬ�� 
	{
		printf("Can't open the file.");
		exit(1);
	}
	else
	{
		system("cls");		//����
			while(!feof(fp))
			{
				char namecpy[20], bj[20];
				fscanf(fp, "%s ", namecpy);
				fscanf(fp,"%s ", num);
				if(strcmp(op_num, num) == 0)    //�ж��Ƿ�������ѧ��һ�������һ����� 
				{
					i = 1;
					fscanf(fp, "%s ", bj);
					fscanf(fp, "%d %d %d %d %d\n", &yw, &sx, &yy, &source, &pm);
					printf("\n\t����\tѧ��\t�༶\t����\t��ѧ\tӢ��\t�ܷ�\t����\n");
					printf("\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\n\n\t", namecpy, num, bj, yw, sx, yy,source,pm);
					if(source<180)
				    {
				    	printf("δ����");
				    }
					if(source>=180 && source<240)
			  	   {
				  	  	printf("�е�");
				    }
				    if(source>=240 && source<270)
				    {
				    	printf("����");
				    }
				    if(source>=270 && source<=300)
				    {
				    	printf("����");
				    }
					break;
				}
			}
		}
		fclose(fp);
		if (i == 0) {
			printf("\n\tû�����ѧ����");
		}
		printf("\n");
	    printf("\t ==================================================\n");
		printf("\t||          9----------������һ��                 ||\n");                //��� 
	    printf("\t||          0----------�˳�ϵͳ                   ||\n");                //��� 
	    printf("\t ==================================================\n");
	    int choice = 0, f = 1;
	char c[20];
	scanf("%s", c);  //��¼�û���ѡ����Ϊ����ֵ���� 
	for (int i = 0; i < strlen(c); i++) {
		if (c[i] < '0' || c[i] > '9') {
			f = 0;
		}
		choice = choice * 10 + (c[i] - '0');
	}
	if (f == 0) {
		printf("��������");
		xxzjm();
	}
	else {
	    switch(choice) {
			case 9:xxzjm();break;//������һ��
			case 0:return;     //�˳�ϵͳ
			default:xxzjm();break;
		}
	}	
}
} 
/*
1.1.ѧ��������
*/
int xxzjm()    
{
	system("cls");		//���� 
	printf("\n =================ѧ��������=================\n");
	printf("|| Enter                                      ||\n");
	printf("||          1----------�ɼ���ѯ               ||\n");          //ok 
	printf("||          2----------��ѯ����ɼ�           ||\n");          //ok 
	printf("||          3----------�ɼ�����               ||\n");          //ok
	printf("||          4----------������һ��             ||\n");          //ok
	printf("||          0----------�˳�ϵͳ               ||\n");          //ok
	printf(" ==============================================\n");
	printf("************************************************\nPlease Enter\n");
	int choice = 0, f = 1;
	char c[20];
	scanf("%s", c);  //��¼�û���ѡ����Ϊ����ֵ���� 
	for (int i = 0; i < strlen(c); i++) {
		if (c[i] < '0' || c[i] > '9') {
			f = 0;
		}
		choice = choice * 10 + (c[i] - '0');
	}
	if (f == 0) {
		printf("��������");
		xxzjm();
	}
	else{
    switch(choice) {
		case 1:query_num();break;    //�ɼ���ѯ
		case 2:query();break;        //��ѯ����ɼ�
		case 3:fx_num();break;       //�ɼ�����
	    case 4:dljm();break;         //������һ��
		case 0:return 0;             //�˳�ϵͳ
		default:dljm();break;
	}
}
}
/*
1.2.7.1 �༶�ɼ�����
*/
void countspec()
{
	system("cls");		//���� 
	printf(" ==============================================\n");
	printf("|| Enter                                      ||\n");
	printf("||          1----------�鿴δ�����ͬѧ       ||\n");
	printf("||          2----------�鿴�еȵ�ͬѧ         ||\n");
	printf("||          3----------�鿴���õ�ͬѧ         ||\n");
	printf("||          4----------�鿴�����ͬѧ         ||\n");
	printf("||          5----------���ؽ�ʦ��	      ||\n");
	printf("||          0----------�˳�ϵͳ	              ||\n");
	printf(" ==============================================\n");
	printf("************************************************\nPlease Enter\n");
	int choice = 0, f = 1;
	char c[20];
	scanf("%s", c);  //��¼�û���ѡ����Ϊ����ֵ���� 
	for (int i = 0; i < strlen(c); i++) {
		if (c[i] < '0' || c[i] > '9') {
			f = 0;
		}
		choice = choice * 10 + (c[i] - '0');
	}
	if (f == 0) {
		printf("��������");
		jszjm();
	}
	else {
	if(choice==1)
	{
		printf("\n\t**********************Query********************\n\n");
	    printf("\t����\tѧ��\t�༶\t����\t��ѧ\tӢ��\t�ܷ���\n");
		FILE *fp;
		char num[50];
		int source,yw,sx,yy;
		if( (fp = fopen("Fail Student.txt","r")) == NULL)   //���ļ���ͬ�� 
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
			countspec();	//���������ѯ�����ȼ�
			return;
		}
	} 
	if(choice==1)
	{
		printf("\n\t**********************Query********************\n\n");
	    printf("\t����\tѧ��\t�༶\t����\t��ѧ\tӢ��\t�ܷ���\n");
		FILE *fp;
		char num[50];
		int yw,sx,yy,source;
		if( (fp = fopen("Fail Student.txt","r")) == NULL)   //���ļ���ͬ�� 
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
			countspec();	//���������ѯ�����ȼ� 
		}
	}
	if(choice==2)
	{
		printf("\n\t**********************Query********************\n\n");
	    printf("\t����\tѧ��\t�༶\t����\t��ѧ\tӢ��\t�ܷ���\n");
		FILE *fp;
		char num[50];
		int yw,sx,yy,source;
		if( (fp = fopen("Medium Student.txt","r")) == NULL)   //���ļ���ͬ�� 
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
			countspec();	//���������ѯ�����ȼ� 
		}
	}
	if(choice==3)
	{
		printf("\n\t**********************Query********************\n\n");
	    printf("\t����\tѧ��\t�༶\t����\t��ѧ\tӢ��\t�ܷ���\n");
		FILE *fp;
		char num[50];
		int yw,sx,yy,source;
		if( (fp = fopen("Good Student.txt","r")) == NULL)   //���ļ���ͬ�� 
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
			countspec();	//���������ѯ�����ȼ� 
		}	
	}
	if(choice==4)
	{
		printf("\n\t**********************Query********************\n\n");
	    printf("\t����\tѧ��\t�༶\t����\t��ѧ\tӢ��\t�ܷ���\n");
		FILE *fp;
		char num[50];
		int yw,sx,yy,source;
		if( (fp = fopen("Excellent Student.txt","r")) == NULL)   //���ļ���ͬ�� 
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
			countspec();	//���������ѯ�����ȼ� 
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
1.2.7.2 ͳ��δ�����еȣ����ã���������� 
*/
void count()
{	
	system("cls");		//���� 
	printf("\n **********************Count********************\n\n");	
	printf("\n\t   δ����     �е�     ����     ����\n");
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
	if( (fp = fopen(s,"r")) == NULL || (fpf = fopen(failname,"w")) == NULL||(fpm = fopen(mediumname,"w")) == NULL||(fpg = fopen(goodname,"w")) == NULL||(fpe = fopen(excellentname,"w")) == NULL)   //���ļ���ͬ�� 
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
		printf("\t   %d��        %d��      %d��      %d��\n",count_fail,count_medium,count_good,count_excellent);
    	system("pause");
		countspec();
		remove(failname); 
	    remove(mediumname);
		remove(goodname);
		remove(excellentname);
	}
}
/*
1.2.6.���ص��ļ���
*/
void download() {
    FILE *fp = NULL, *out = NULL;
    int ch;
    out = fopen("����ɼ�.txt","w");
    fp = fopen(s, "r");
    fputs(" ����  ѧ�� �༶   ���� ��ѧ Ӣ��\n", out);
    ch=fgetc(fp); //��fp��ָ�ļ��ĵ�ǰָ��λ�ö�ȡһ���ַ�
    while(ch!=EOF) //�жϸն�ȡ���ַ��Ƿ����ļ�������
    {
	    fputc(ch,out); //�����ǽ�����������д��out��ָ�ļ�
        ch=fgetc(fp); //������fp��ָ�ļ��ж�ȡ��һ���ַ�
    } //��ɽ�fp��ָ�ļ��������������Ļ����ʾ
   fclose(fp);
   fclose(out);
}
/*
1.2.5��ѯ����ɼ�
*/
void query_teacher()
{	
	system("cls");		//���� 
	FILE *fp;
	char num[50];
	int yw, sx, yy;
	printf("\n\tѧ��\t����\t�༶\t����\t��ѧ\tӢ��\n");
	printf("\t============================================\n");
	if( (fp = fopen(s,"r")) == NULL)   //���ļ���ͬ��
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
		printf("\t||          9----------������һ��                 ||\n");                //��� 
	    printf("\t||          0----------�˳�ϵͳ                   ||\n");                //��� 
	    printf("\t ==================================================\n");
	   int choice = 0, f = 1;
	char c[20];
	scanf("%s", c);  //��¼�û���ѡ����Ϊ����ֵ���� 
	for (int i = 0; i < strlen(c); i++) {
		if (c[i] < '0' || c[i] > '9') {
			f = 0;
		}
		choice = choice * 10 + (c[i] - '0');
	}
	if (f == 0) {
		printf("��������");
		jszjm();
	}
	else {
	    switch(choice) {
			case 9:jszjm();break;//������һ��
			case 0:return;     //�˳�ϵͳ
			default:jszjm();break;
		}
	}
}
}
/*
1.2.4 (��ʦ)�ɼ���ѯ������ѧ�ţ�
*/
void query_teacher_num()
{
	system("cls");		//���� 
	FILE *fp;
	char num[50],scan_num[50];
	int yw, sx, yy, i = 0, f;
	char c;
	if((fp = fopen(s,"r")) == NULL)   //���ļ���ͬ�� 
	{
		printf("Can't open the file.");
		exit(1);
	}
	else
	{ 
	    printf("\n   ���������ѯ��Ϣѧ����ѧ��:");
	    scanf("%s", scan_num);
	    f = pdzh(scan_num);
	    if (f == 0) {
	    	printf("\t��������룡��"); 
	    }
		else {
		    system("cls");		//����
		    printf("\n\t����\tѧ��\t�༶\t����\t��ѧ\tӢ��\n");
			while(!feof(fp))
			{
				char namecpy[20], bj[20];
				fscanf(fp, "%s ", namecpy);
				fscanf(fp, "%s ",  num);
				if(strcmp(scan_num, num) == 0)    //�ж��Ƿ�������ѧ��һ�������һ����� 
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
			printf("û�д�ͬѧ��");
		}
		printf("\n");
	    printf("\t ==================================================\n");
		printf("\t||          9----------������һ��                 ||\n");                //��� 
	    printf("\t||          0----------�˳�ϵͳ                   ||\n");                //��� 
	    printf("\t ==================================================\n");
	    int choice = 0, f = 1;
	char c[20];
	scanf("%s", c);  //��¼�û���ѡ����Ϊ����ֵ���� 
	for (int i = 0; i < strlen(c); i++) {
		if (c[i] < '0' || c[i] > '9') {
			f = 0;
		}
		choice = choice * 10 + (c[i] - '0');
	}
	if (f == 0) {
		printf("��������");
		pdcx();
	}
	else {
		system("cls");		//���� 
	    switch(choice) {
			case 9:pdcx();break;//������һ��
			case 0:return;     //�˳�ϵͳ
			default:pdcx();break;
		}
	}	
}
}
/*
1.2.3.�޸�ѧ����Ϣ
*/
void Modify_num()
{
	FILE *fp;
	FILE *fpn,*fpo; 
	char newfilename[] = "Students' Work temp.txt"; //һ����ʱ�ļ� 
	char num[50],tonum[50];
	int yw,sx,yy,toyw,tosx,toyy,f,f1 = 0;
	char a[20],b[20],d[20];
	char toname[20],tobj[20];				       //�����޸�ѧ��
	if( (fpn = fopen(newfilename,"w")) == NULL || (fp = fopen(s,"r")) == NULL || (fpo = fopen("allclass.txt","r")) == NULL)   //���ļ���ͬ�� 
	{
		printf("\tCan't open the file.");
		exit(1);
	}
	else
	{	
	    system("cls");		//���� 
		printf("   ���������޸���Ϣѧ����ѧ��:");  //����޸ĵ���Ϣ 
		scanf("%s", tonum);	
		f = pdzh(tonum);
		if (f == 0) {
			printf("\t��������룡��"); 
		}
		else {
	    	printf("\n\tPlease Student's Name:");
	  	    scanf("%s",toname);
	  	    f = pdmz(toname);
	    	if (f == 0) {
			    printf("\t���Ǵ�������롣");
	    	}
	    	else{
		    	printf("\n\tPlease Student's class:");
	    		scanf("%s",tobj);
	    		f = pdbj(tobj);
	    		if (f == 0) {
				    printf("\t���Ǵ�������롣");
	    		}
	    		else {
	        		printf("\tPlease Student's Source:");
	        		scanf("%s %s %s",a,b,d);
	        		yw = zhcj(a);
	        	    sx = zhcj(b);
	        	    yy = zhcj(d);
	        		f = pdcj(yw,sx,yy);
	        		if (f == 0) {
				         printf("\t���Ǵ�������롣");
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
			if(strcmp(tonum, num) == 0 && f == 1)    //�ж��Ƿ�������ѧ��һ�������һ������
			{
				f1 = 1;
				 fprintf(fpn,"%s %s %s %d %d %d\n",toname,tonum,tobj,toyw,tosx,toyy);
				 fprintf(fpo,"%s %s %s %d %d %d\n",toname,tonum,tobj,toyw,tosx,toyy);
				 printf("\t�ѳɹ��޸ġ�");
		    }
			else
			{
				fprintf(fpn,"%s %s %s %d %d %d\n",namecpy,num,bj,yw,sx,yy);
				fprintf(fpo,"%s %s %s %d %d %d\n",namecpy,num,bj,yw,sx,yy);
			}
		}
		if (f1 == 0) {
			printf("\n\tû�д�ͬѧ��\n");
		}
		fclose(fp);
		fclose(fpn);
		fclose(fpo);
		remove(s);	//ɾ��ԭ�ļ�
		rename(newfilename, s);	//���������ļ�
		printf("\n");
	    printf("\t ==================================================\n");
		printf("\t||          9----------������һ��                 ||\n");                //��� 
	    printf("\t||          0----------�˳�ϵͳ                   ||\n");                //��� 
	    printf("\t ==================================================\n");
	    int choice = 0, f = 1;
	char c[20];
	scanf("%s", c);  //��¼�û���ѡ����Ϊ����ֵ���� 
	for (int i = 0; i < strlen(c); i++) {
		if (c[i] < '0' || c[i] > '9') {
			f = 0;
		}
		choice = choice * 10 + (c[i] - '0');
	}
	if (f == 0) {
		printf("��������");
		jszjm();
	}
	else {
	    switch(choice) {
			case 9:jszjm();break;//������һ��
			case 0:return;     //�˳�ϵͳ
			default:jszjm();break;
		}
	}	
}
}
/*
1.2.2ɾ��ѧ����Ϣ
*/
void Del_num()
{
	FILE *fp;
	FILE *fpn,*fpo; 
	char newfilename[] = "Students' Work temp.txt"; //һ����ʱ�ļ�
	char num[50],tonum[50];
	int yw,sx,yy,f;				    
	if( (fpn = fopen(newfilename,"w")) == NULL || (fp = fopen(s,"r")) == NULL || (fpo = fopen("allclass.txt","r")) == NULL)   //���ļ���ͬ�� 
	{
		printf("Can't open the file.");
		exit(1);
	}
	else
	{	
		system("cls");		//���� 
		printf("   ��������ɾ����Ϣѧ����ѧ��:");  //���ɾ������Ϣ 
		scanf("%s", tonum);
		f = pdzh(tonum);
		if (f == 0) {
			printf("\n\t��������롣\n");
		}
		while(!feof(fp))
		{
			char namecpy[20],bj[20];
			fscanf(fp,"%s ",namecpy); 
			fscanf(fp,"%s ", num);
			fscanf(fp,"%s ",bj);
			fscanf(fp,"%d %d %d\n",&yw,&sx,&yy);
			if(strcmp(tonum, num) == 0)    //�ж��Ƿ�������ѧ��һ�������һ������д����ʱ�ļ� 
			{
					;//��һ�οղ���
					printf("\t�ѳɹ�ɾ����");
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
		remove(s);	//ɾ��ԭ�ļ�
		rename(newfilename, s);	//���������ļ�
		printf("\n");
	    printf("\t ==================================================\n");
		printf("\t||          9----------������һ��                 ||\n");                //��� 
	    printf("\t||          0----------�˳�ϵͳ                   ||\n");                //��� 
	    printf("\t ==================================================\n");
	    int choice = 0, f = 1;
	char c[20];
	scanf("%s", c);  //��¼�û���ѡ����Ϊ����ֵ���� 
	f=1;
	for (int i = 0; i < strlen(c); i++) {
		if (c[i] < '0' || c[i] > '9') {
			f = 0;
		}
		choice = choice * 10 + (c[i] - '0');
	}
	if (f == 0) {
		printf("��������");
		jszjm();
	}
	else {
	    switch(choice) {
			case 9:jszjm();break;//������һ��
			case 0:return;     //�˳�ϵͳ
			default:jszjm();break;
		}
	}	
}
} 
/*
1.2.1ѧ����Ϣ����
*/
void record()
{
	system("cls");		//���� 
	FILE *fp,*fpn;
	if ((fpn = fopen(s,"a")) == NULL || (fp = fopen("allclass.txt","a")) == NULL) //���ļ��������ʧ�ܸ��û���ʾ 
	{
		printf("Can't open the file.");
		exit(1);
	}
	else
	{
	    char name[20];  //��������
		int num;        //����ѧ��
		char bj[20];    //����༶ 
		char a[20],b[20],d[20];
		int yw, sx, yy,f = 1;     //����ɼ�:���ģ���ѧ��Ӣ�� 
		printf("\tPlease Student's Num:\n");
		printf("\t(if you want to stop, input 0)");
		char zh[50];
		scanf("%s", zh);
		num = pdzh(zh);
		if (num == 0) {
			printf("\t��������룡��");
		} 
		while(num!=0)    //ѭ������ֱ���û������Num=0ʱֹͣ¼�� 
		{
			    f= pdcf(s,zh);
		        if (f == 0) {
			        break;
		        }
				printf("\tPlease Student's Name:");   //¼������ 
				scanf("%s",name);
				f = pdmz(name);
				if (f == 0) {
					printf("\t��������룡��");
					break;
				}
				
			    printf("\tPlease Student's Class:");   //¼��༶ 
				scanf("%s",bj);
				f = pdbj(bj);
				if (f == 0) {
					printf("\t��������룡��");
					break;
				}
				
	      	  	printf("\tPlease Student's Source:");
	        	scanf("%s %s %s", a, b, d);
	        	yw = zhcj(a);
	        	sx = zhcj(b);
	        	yy = zhcj(d);
	        	f = pdcj(yw,sx,yy);
	        	if (f == 0) {
				    printf("\t��������롣");
				    break;
	    		}
	        	
				fprintf(fp,"%s ", name);
				fprintf(fp,"%s ", zh);  //��num�Լ�һ���ո񱣴浽�ļ��У���ͬ 
				fprintf(fp,"%s ", bj);
				fprintf(fp,"%d %d %d\n", yw,sx,yy);
				
				fprintf(fpn,"%s ", name);
				fprintf(fpn,"%s ", zh);  //��num�Լ�һ���ո񱣴浽�ļ��У���ͬ 
				fprintf(fpn,"%s ", bj);
				fprintf(fpn,"%d %d %d\n", yw,sx,yy);
	        	
	        	printf("\n\t�ѳɹ���ӡ�\n\n");
				printf("\tPlease Student's Num:\n");
		    	printf("\t(if you want to stop, input 0)");
				scanf("%s", zh);
				f = pdcf(s,zh);
		        if (f == 0) {
			        break;
		        }
				num = pdzh(zh);
				if (num == 0) {
					printf("\t��������룡��");
					break; 
				}
			}
		//}
		fclose(fp);   //�ر��ļ� 
		fclose(fpn);
		printf("\n");
	    printf("\t ==================================================\n");
		printf("\t||          9----------������һ��                 ||\n");                //��� 
	    printf("\t||          0----------�˳�ϵͳ                   ||\n");                //��� 
	    printf("\t ==================================================\n");
	    int choice = 0, l = 1;
	char c[20];
	scanf("%s", c);  //��¼�û���ѡ����Ϊ����ֵ���� 
	for (int i = 0; i < strlen(c); i++) {
		if (c[i] < '0' || c[i] > '9') {
			l = 0;
		}
		choice = choice * 10 + (c[i] - '0');
	}
	if (l == 0) {
		printf("��������");
		jszjm();
	}
	else {
	    switch(choice) {
			case 9:jszjm();break;//������һ��
			case 0:return;     //�˳�ϵͳ
			default:jszjm();break;
		}
	}
	}
}
/*
1.2.��ʦ��ϵͳ����һ����
*/
int jszjm()    
{
	system("cls");		//���� 
	printf("\n ===================��ʦ������===================\n");
	printf("|| Enter                                          ||\n");
	printf("||          1----------ѧ����Ϣ����               ||\n");                //��� 
	printf("||          2----------ɾ��ѧ����Ϣ               ||\n");                //��� 
	printf("||          3----------�޸�ѧ����Ϣ               ||\n");                //��� 
	printf("||          4----------��ѯѧ����Ϣ               ||\n");                //���
	printf("||          5----------���ȫ���ɼ�               ||\n");                //���
	printf("||          6----------���ص��ļ���               ||\n");                //���
	printf("||          7----------�ɼ�����                   ||\n");                //���
	printf("||          8----------�ɼ�����                   ||\n");                //���
	printf("||          9----------������һ��                 ||\n");                //��� 
	printf("||          0----------�˳�ϵͳ                   ||\n");                //��� 
	printf(" ==================================================\n");
	printf("************************************************\nPlease Enter\n");
	int choice = 0, f = 1;
	char c[20];
	scanf("%s", c);  //��¼�û���ѡ����Ϊ����ֵ���� 
	for (int i = 0; i < strlen(c); i++) {
		if (c[i] < '0' || c[i] > '9') {
			f = 0;
		}
		choice = choice * 10 + (c[i] - '0');
	}
	if (f == 0) {
		printf("��������");
		jszjm();
	}
	else{
	system("cls");		//���� 
	switch(choice) {
		case 1:record();break;           //ѧ����Ϣ����
		case 2:Del_num();break;          //ɾ��ѧ����Ϣ
		case 3:Modify_num();break;       //�޸�ѧ����Ϣ
		case 4:pdcx();break;           //��ѯѧ����Ϣ
	    case 5:query_teacher();break;    //�������ɼ�
		case 6:download();break;         //���ص��ļ���
		case 7:count();break;            //�ɼ�����
		case 8:cjpxjm();;break;              //������һ��
		case 9:jszjm();;break;              //������һ��
		case 0:return 0;                 //�˳�ϵͳ
		default:jszjm();;break;
	}
}
}
/*
1.3.9.�ֶ�����¼��ѧ����Ϣ
*/
void Modify_admin_num()
{
	FILE *fp;
	FILE *fpn,*fpo; 
	char newfilename[] = "Students' Work temp.txt"; //һ����ʱ�ļ� 
	char num[50],tonum[50];
	char a[20],b[20],d[20];
	int yw,sx,yy,toyw,tosx,toyy,f,f1;
	char toname[20],tobj[20],clas[20]="class0.txt";
	system("cls");		//���� 
	printf("   �����뱻�޸���Ϣ��ѧ�������İ༶:");  //����޸ĵİ༶
	getchar();
	scanf("%c",&clas[5]);
	if( (fpn = fopen(newfilename,"w")) == NULL || (fp = fopen(clas,"r")) == NULL || (fpo = fopen("allclass.txt","r")) == NULL)   //���ļ���ͬ�� 
	{
		printf("\tCan't open the file.");
		exit(1);
	}
	else{
	    printf("\n   �����뱻�޸���Ϣѧ����ѧ��:");  //����޸ĵ���Ϣ
	    scanf("%s", tonum); 				   //�����޸�ѧ��
	    f = pdzh(tonum);
	    if (f == 0) {
	    	printf("\t��������룡��");
		}
	    else
	    {	
	    printf("\n\tPlease Student's Name:");
	    scanf("%s",toname);
	    f = pdbj(tobj);
	    if (f == 0) {
	    	printf("\t��������룡��");
	    }
	    else{
	        printf("\n\tPlease Student's class:");
	        scanf("%s",tobj);
	        f = pdbj(tobj);
	        if (f == 0) {
	    	    printf("\t��������룡��");
	        }
	        else {
	            printf("\tPlease Student's Source:");
	            scanf("%d%d%d",a,b,d);
	            yw = zhcj(a);
	        	sx = zhcj(b);
	        	yy = zhcj(d);
				f = pdcj(yw,sx,yy);
	        	if (f == 0) {
			        printf("\t���Ǵ�������롣");
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
		    	if(strcmp(tonum, num) == 0 && f == 1)    //�ж��Ƿ�������ѧ��һ�������һ������
		    	{
		    		f1 = 1;
		    		fprintf(fpn,"%s %s %s %d %d %d\n",toname,tonum,tobj,toyw,tosx,toyy);
		    		fprintf(fpo,"%s %s %s %d %d %d\n",toname,tonum,tobj,toyw,tosx,toyy);
		    		printf("\t�ѳɹ�¼�룡��");
		    	}
		    	else
		    	{
		    		fprintf(fpn,"%s %s %s %d %d %d\n",namecpy,num,bj,yw,sx,yy);
		    		fprintf(fpo,"%s %s %s %d %d %d\n",namecpy,num,bj,yw,sx,yy);
		    	}
	    	}
	    if (f == 0) {
	    	printf("\n\tû�д�ͬѧ��\n");
		}
		fclose(fp);
		fclose(fpn);
		fclose(fpo);
		remove(clas);	//ɾ��ԭ�ļ�
		rename(newfilename, clas);	//���������ļ�
		printf("\n");
	    printf("\t ==================================================\n");
		printf("\t||          9----------������һ��                 ||\n");                //��� 
	    printf("\t||          0----------�˳�ϵͳ                   ||\n");                //��� 
	    printf("\t ==================================================\n");
	    int choice = 0, f = 1;
	char c[20];
	scanf("%s", c);  //��¼�û���ѡ����Ϊ����ֵ���� 
	for (int i = 0; i < strlen(c); i++) {
		if (c[i] < '0' || c[i] > '9') {
			f = 0;
		}
		choice = choice * 10 + (c[i] - '0');
	}
	if (f == 0) {
		printf("��������");
		glyzjm();
	}
	else {
	    switch(choice) {
			case 9:glyzjm();break;//������һ��
			case 0:return;     //�˳�ϵͳ
			default:glyzjm();break;
		}
	}
	}	
}
/*
1.3.8.��������˺ź�����
*/
void query_all_admin()
{	
	system("cls");		//����
	printf("\n\t�˺�\t\t����\n");
	FILE *fp;
	char num[50],password[50];
	if( (fp = fopen(cx,"r")) == NULL)   //���ļ���ͬ��
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
		printf("\t||          9----------������һ��                 ||\n");                //��� 
	    printf("\t||          0----------�˳�ϵͳ                   ||\n");                //��� 
	    printf("\t ==================================================\n");
	    int choice = 0, f = 1;
	char c[20];
	scanf("%s", c);  //��¼�û���ѡ����Ϊ����ֵ���� 
	for (int i = 0; i < strlen(c); i++) {
		if (c[i] < '0' || c[i] > '9') {
			f = 0;
		}
		choice = choice * 10 + (c[i] - '0');
	}
	if (f == 0) {
		printf("��������");
		glyzjm();
	}
	else {
	    switch(choice) {
			case 9:glyzjm();break;//������һ��
			case 0:return;     //�˳�ϵͳ
			default:glyzjm();break;
		}
	}
}
}
/*
1.3.6.�����˺ź�����
*/
void query_admin()
{
	FILE *fp;
	char num[50],scan_num[50], password[50];
	int i = 0, f = 1;
	system("cls");		//����
	if( (fp = fopen(cx,"r")) == NULL)   //���ļ���ͬ�� 
	{
		printf("Can't open the file.");
		exit(1);
	}
	
	else
	{
	    if (strcmp(cx, "Admin' Work.txt") != 0){
		    printf("\n   ���������ѯ���˺�:");
	        scanf("%s", scan_num);
	    }
	    else {
		    strcpy(scan_num,nums);
	    }
	    f = pdzh(scan_num);
		if (f == 0) {
			printf("\t��������룡��");
		}
		while(!feof(fp))
		{
			fscanf(fp,"%s ", num);
			fscanf(fp,"%s\n", password);
			if(strcmp(scan_num, num) == 0 && f == 1)    //�ж��Ƿ��������˺�һ�������һ����� 
			{
				i = 1;		
	            printf("\n\t�˺�\t\t����\n");
				printf("\t%s\t\t%s\n",num,password);
				break;
			}
		}
		fclose(fp);
		if (i == 0) {
			printf("\tû������˺š�");
		}
		printf("\n");
	    printf("\t ==================================================\n");
		printf("\t||          9----------������һ��                 ||\n");                //��� 
	    printf("\t||          0----------�˳�ϵͳ                   ||\n");                //��� 
	    printf("\t ==================================================\n");
	    int choice = 0;
	char c[20];
	f = 1;
	scanf("%s", c);  //��¼�û���ѡ����Ϊ����ֵ���� 
	for (int i = 0; i < strlen(c); i++) {
		if (c[i] < '0' || c[i] > '9') {
			f = 0;
		}
		choice = choice * 10 + (c[i] - '0');
	}
	if (f == 0) {
		printf("��������");
		glyzjm();
	}
	else {
	    switch(choice) {
			case 9:glyzjm();break;//������һ��
			case 0:return;     //�˳�ϵͳ
			default:glyzjm();break;
		}
	}	
}
}
/*
1.3.5.�޸��˺ź�����
*/
void Modify_admin()
{
	FILE *fp;
	FILE *fpn; 
	char newfilename[] = "Admin' Work temp.txt"; //һ����ʱ�ļ� 
	char num[50],tonum[50];
	char password[50],topassword[50];
	char p[20];
    int i=0, f = 1;
	system("cls");		//����
	if (strcmp(cx, "Admin' Work.txt") != 0){
		printf("\n   ���������޸ĵ��˺�:");
	    scanf("%s", tonum);
	}
	else {
		strcpy(tonum,nums);
	}
	f = pdzh(tonum);
	if (f == 0) {
		printf("\t��������룡��");
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
	if( (fpn = fopen(newfilename,"w")) == NULL || (fp = fopen(cx,"r")) == NULL)   //���ļ���ͬ�� 
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
			if(strcmp(tonum, num) == 0 && f == 1)    //�ж��Ƿ��������˺�һ�������һ������ 
			{
				i = 1;
				fprintf(fpn,"%s %s\n",tonum,topassword);
				printf("\n\t�޸ĳɹ���");
			}
			else
			{
				fprintf(fpn,"%s %s\n",num,password);
			}
		}
		fclose(fp);
		fclose(fpn);
		remove(cx);	//ɾ��ԭ�ļ�
		rename(newfilename, cx);	//���������ļ�
		if (i == 0) {
			printf("\n\t�����ڴ��˺š�"); 
		}
		printf("\n");
	    printf("\t ==================================================\n");
		printf("\t||          9----------������һ��                 ||\n");                //��� 
	    printf("\t||          0----------�˳�ϵͳ                   ||\n");                //��� 
	    printf("\t ==================================================\n");
	    int choice = 0;
	char c[20];
	f = 1;
	scanf("%s", c);  //��¼�û���ѡ����Ϊ����ֵ���� 
	for (int i = 0; i < strlen(c); i++) {
		if (c[i] < '0' || c[i] > '9') {
			f = 0;
		}
		choice = choice * 10 + (c[i] - '0');
	}
	if (f == 0) {
		printf("��������");
		glyzjm();
	}
	else {
	    switch(choice) {
			case 9:glyzjm();break;//������һ��
			case 0:return;     //�˳�ϵͳ
			default:glyzjm();break;
		}
	}	
}
} 
/*
1.3.4.ɾ���˺ź�����
*/
void Del_admin()
{
	FILE *fp;
	FILE *fpn; 
	char newfilename[] = "Admin temp.txt"; //һ����ʱ�ļ� 
	char num[50],tonum[50],password[50], f = 1;
	system("cls");		//����					    
	if( (fpn = fopen(newfilename,"w")) == NULL || (fp = fopen(cx,"r")) == NULL)   //���ļ���ͬ�� 
	{
		printf("Can't open the file.");
		exit(1);
	}
	else
	{	
	    if (strcmp(cx, "Admin' Work.txt") != 0){
		    printf("\n   ��������ɾ�����˺�:");
	        scanf("%s", tonum);
	    }
	    else {
		    strcpy(tonum,nums);
	    }
	    f = pdzh(tonum);
		if (f == 0) {
			printf("\t��������룡��");
		}
		while(!feof(fp))
		{
			fscanf(fp,"%s ", num);  
			fscanf(fp,"%s\n", password);
			if(strcmp(tonum, num) == 0 && f == 1)    //�ж��Ƿ�������ѧ��һ�������һ������д����ʱ�ļ� 
			{
				printf("ɾ���ɹ���");//��һ�οղ��� 
			}
			else
			{
				fprintf(fpn,"%s %s",num,password);
			}
		}
		fclose(fp);
		fclose(fpn);
		remove(cx);	//ɾ��ԭ�ļ�
		rename(newfilename, cx);	//���������ļ�
		printf("\n");
	    printf("\t ==================================================\n");
		printf("\t||          9----------������һ��                 ||\n");                //��� 
	    printf("\t||          0----------�˳�ϵͳ                   ||\n");                //��� 
	    printf("\t ==================================================\n");
	    int choice = 0;
	char c[20];
	f = 1;
	scanf("%s", c);  //��¼�û���ѡ����Ϊ����ֵ���� 
	for (int i = 0; i < strlen(c); i++) {
		if (c[i] < '0' || c[i] > '9') {
			f = 0;
		}
		choice = choice * 10 + (c[i] - '0');
	}
	if (f == 0) {
		printf("��������");
		glyzjm();
	}
	else {
	    switch(choice) {
			case 9:glyzjm();break;//������һ��
			case 0:return;     //�˳�ϵͳ
			default:glyzjm();break;
		}
	}	
}
} 
/*
1.3.3.�����˺ź�����
*/
void record_admin()
{
	system("cls");		//����
	FILE *fp;
	if( (fp = fopen("Admin' Work.txt","a")) == NULL ) //���ļ��������ʧ�ܸ��û���ʾ 
	{
		printf("Can't open the file.");
		exit(1);
	}
	else
	{
		int num, f = 1;          //�����˺�
		printf("\tPlease Student's Num:\n");
		printf("\t(if you want to stop, input 0)");
		char zh[50];
		scanf("%s", zh);
		num = pdzh(zh);
		if (num == 0) {
			printf("\t��������룡��");
		}
		while(num!=0)    //ѭ������ֱ���û������Num=0ʱֹͣ¼�� 
		{
			f= zhpdcf("Admin' Work.txt",zh);
		    if (f == 0) {
		        break;
	        }
		        
		    char password[50];     //��������
		    char p[20];
            int i=0;
            
			fprintf(fp,"%s ",num);  //��num�Լ�һ���ո񱣴浽�ļ��У���ͬ
			 
			printf("\tPlease admin's password:");   //¼������ 
			 
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
				printf("\t��������룡��");
				break;
			}
			f= zhpdcf("Admin' Work.txt",zh);
		    if (f == 0) {
		        break;
	        }
		}
		fclose(fp);   //�ر��ļ� 
		printf("\n");
	    printf("\t ==================================================\n");
		printf("\t||          9----------������һ��                 ||\n");                //��� 
	    printf("\t||          0----------�˳�ϵͳ                   ||\n");                //��� 
	    printf("\t ==================================================\n");
	    int choice = 0;
	    f = 1;
	char c[20];
	scanf("%s", c);  //��¼�û���ѡ����Ϊ����ֵ���� 
	for (int i = 0; i < strlen(c); i++) {
		if (c[i] < '0' || c[i] > '9') {
			f = 0;
		}
		choice = choice * 10 + (c[i] - '0');
	}
	if (f == 0) {
		printf("��������");
		glyzjm();
	}
	else {
	    switch(choice) {
			case 9:zcjm();break;//������һ��
			case 0:return;     //�˳�ϵͳ
			default:glyzjm();break;
		}
	}
}
}
/*
1.3.����Ա��ϵͳ����һ����
*/
int glyzjm()    
{
	system("cls");		//���� 
	printf("\n ===================����Ա������=================\n");
	printf("|| Enter                                          ||\n");
	printf("||          1----------����������                 ||\n");       //ok
	printf("||          2----------�����ʦ��                 ||\n");       //ok
	printf("||          3----------�����˺ź�����             ||\n");       //ok
	printf("||          4----------ɾ���˺ź�����             ||\n");       //ok
	printf("||          5----------�޸��˺ź�����             ||\n");       //ok
	printf("||          6----------�����˺ź�����             ||\n");       //ok
	printf("||          7----------��������˺ź�����         ||\n");       //ok
	printf("||          8----------�ֶ�����¼��ѧ����Ϣ       ||\n");       //ok
	printf("||          0----------�˳�ϵͳ                   ||\n");       //ok
	printf(" ==================================================\n");
	printf("************************************************\nPlease Enter\n");
	int choice = 0, f = 1;
	char c[20];
	scanf("%s", c);  //��¼�û���ѡ����Ϊ����ֵ���� 
	for (int i = 0; i < strlen(c); i++) {
		if (c[i] < '0' || c[i] > '9') {
			f = 0;
		}
		choice = choice * 10 + (c[i] - '0');
	}
	if (f == 0) {
		printf("��������");
		glyzjm();
	}
	else{
	switch(choice) {
		case 1:dljm();break;            //������һ��
		case 2:jsdl();break;            //�����ʦ��
		case 3:zcjm();break;            //�����˺ź�����
		case 4:scjm();break;            //ɾ���˺ź�����
	    case 5:xgjm();break;    //�޸��˺ź�����
		case 6:cxjm();break;            //�����˺ź�����
     	case 7:cxjm_all();break;        //��������˺ź�����
     	case 8:Modify_admin_num();break;//�ֶ�����¼��ѧ����Ϣ
		case 0:return 0;                //�˳�ϵͳ
		default:dljm();break;
	}
    }
}
/*
ѧ����¼����
*/ 
void xxdl()
{
	system("cls");		//����
	printf("****************************************************\n");
	printf("\n=====================ѧ����¼==================\n");
	FILE *fp;
	char num[50],scan_num[50];
	char password[50],scan_password[50];
	char p[20];
    int i=0,f;
	printf("\n   ����������˺�:");
	scanf("%s", scan_num);
	strcpy(nums, scan_num);
	printf("\n   �������������:");
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
	
	if( (fp = fopen("Student' Work.txt","r")) == NULL)   //���ļ���ͬ��
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
			if(strcmp(scan_num, num) == 0 && pdmm(p,password) == 0)                  //�ж��Ƿ�������ѧ��һ�������һ����� 
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
		printf("\t||          1----------������һ��                 ||\n"); 
		printf("\t||          9----------��������                   ||\n");                //��� 
	    printf("\t||          0----------�˳�ϵͳ                   ||\n");                //��� 
	    printf("\t ==================================================\n");
	    int choice = 0, f = 1;
		char c[20];
		scanf("%s", c);  //��¼�û���ѡ����Ϊ����ֵ���� 
		for (int i = 0; i < strlen(c); i++) {
			if (c[i] < '0' || c[i] > '9') {
				f = 0;
			}
			choice = choice * 10 + (c[i] - '0');
		}
		if (f == 0) {
			printf("��������");
			xxdl();
		}
		else{	
	    switch(choice) {
			case 1:dljm();break;//������һ��
			case 9:xxdl();break; //��������
			case 0:return;       //�˳�ϵͳ
			default:xxdl();break;
		}
	}
    }
}
/*
��ʦ��¼����
*/ 
void jsdl()
{
	system("cls");		//����
	printf("**************************************************\n");
	printf("\n====================��ʦ��¼==================\n");
	FILE *fp;
	char num[50],scan_num[50];
	char password[50],scan_password[50];
	char p[20];
    int i=0;
	printf("\n   ����������˺�:");
	scanf("%s", scan_num);
	strcpy(nums, scan_num);
	printf("\n   �������������:");
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
	
	if( (fp = fopen("Teacher' Work.txt","r")) == NULL)   //���ļ���ͬ��
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
			if(strcmp(scan_num, num) == 0 && pdmm(p,password) == 0 )                 //�ж��Ƿ�������ѧ��һ�������һ����� 
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
		printf("\t||          1----------������һ��                 ||\n"); 
		printf("\t||          9----------��������                   ||\n");                //��� 
	    printf("\t||          0----------�˳�ϵͳ                   ||\n");                //��� 
	    printf("\t ==================================================\n");
	    int choice = 0, f = 1;
		char c[20];
		scanf("%s", c);  //��¼�û���ѡ����Ϊ����ֵ���� 
		for (int i = 0; i < strlen(c); i++) {
			if (c[i] < '0' || c[i] > '9') {
				f = 0;
			}
			choice = choice * 10 + (c[i] - '0');
		}
		if (f == 0) {
			printf("��������");
			jsdl();
		}
		else{	
	    switch(choice) {
			case 1:dljm();break;//������һ��
			case 9:jsdl();break; //��������
			case 0:return;       //�˳�ϵͳ
			default:dljm();break;
		}
	}
	}
}
/*
����Ա��¼����
*/ 
void glydl()
{
	system("cls");		//����
	printf("*****************************************************\n");
	printf("\n====================����Ա��¼==================\n");
	FILE *fp;
	char num[50],scan_num[50];
	char password[50];
	char p[20];
    int i=0;
	printf("\n   ����������˺�:");
	scanf("%s", scan_num);
	strcpy(nums, scan_num);
	printf("\n   �������������:");
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
	
	if( (fp = fopen("Admin' Work.txt","r")) == NULL)   //���ļ���ͬ��
	{
		printf("Can't open the file.");
		exit(1);
	}
	while(!feof(fp))
	{
		fscanf(fp,"%s ", num);
		fscanf(fp,"%s\n", password);
		if(strcmp(scan_num, num) == 0 && pdmm(p, password) == 0)                  //�ж��Ƿ�������ѧ��һ�������һ����� 
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
	printf("\t||          1----------������һ��                 ||\n"); 
	printf("\t||          9----------��������                   ||\n");                //��� 
	printf("\t||          0----------�˳�ϵͳ                   ||\n");                //��� 
	printf("\t ==================================================\n");
	int choice = 0, f = 1;
	char c[20];
	scanf("%s", c);  //��¼�û���ѡ����Ϊ����ֵ���� 
	for (int i = 0; i < strlen(c); i++) {
		if (c[i] < '0' || c[i] > '9') {
			f = 0;
		}
		choice = choice * 10 + (c[i] - '0');
	}
	if (f == 0) {
		printf("��������");
		glydl();
	}
	else{
	    switch(choice) {
			case 1:dljm();break;//������һ��
			case 9:glydl();break; //��������
			case 0:return;       //�˳�ϵͳ
			default:glydl();break;
		}
	}
}
/*
ѧ��ע����� 
*/
void xxzc()
{
	system("cls");		//����
	FILE *fp;
	if( (fp = fopen("Student' Work.txt","a")) == NULL ) //���ļ��������ʧ�ܸ��û���ʾ 
	{
		printf("Can't open the file.");
		exit(1);
	}
	else
	{
		printf("****************************************************\n");
	    printf("\n ====================ѧ��ע��==================\n");
		int num, f = 1;          //�����˺�
		char p[20],zh[50],password[50];
		printf("\tPlease Student's Num:\n");
		printf("\t(if you want to stop, input 0)");
		scanf("%s", zh);
		num = pdzh(zh);
        if (num == 0) {
	        printf("\t��������룡��"); 
        }
		while(num!=0)    //ѭ������ֱ���û������Num=0ʱֹͣ¼�� 
		{
			f= zhpdcf("Student' Work.txt",zh);
		    if (f == 0) {
		        break;
	        }
	        
		    int i = 0;  //��������
			
			fprintf(fp,"%s ",zh);  //��num�Լ�һ���ո񱣴浽�ļ��У���ͬ
			 
			printf("\tPlease student's password:");   //¼������ 
			 
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
	            printf("\t��������룡��"); 
            }
            f= zhpdcf("Student' Work.txt",zh);
		    if (f == 0) {
		        break;
	        }
		}
		fclose(fp);   //�ر��ļ� 
		printf("\n");
	    printf("\t ==================================================\n");
	    printf("\t||          8----------���ص�¼����               ||\n");                //��� 
		printf("\t||          9----------������һ��                 ||\n");                //��� 
	    printf("\t||          0----------�˳�ϵͳ                   ||\n");                //��� 
	    printf("\t ==================================================\n");
	    int choice = 0;
	    f = 1;
		char c[20];
		scanf("%s", c);  //��¼�û���ѡ����Ϊ����ֵ���� 
		for (int i = 0; i < strlen(c); i++) {
			if (c[i] < '0' || c[i] > '9') {
				f = 0;
			}
			choice = choice * 10 + (c[i] - '0');
		}
		if (f == 0) {
			printf("��������");
			dljm();
		}
		else {
	    	switch(choice) {
	    		case 8:dljm();break;//������һ��
				case 9:zcjm();break;//������һ��
				case 0:return;      //�˳�ϵͳ
				default:dljm();break;
			}
		}
	}
}
/*
��ʦע����� 
*/
void jszc()
{
	system("cls");		//����
	FILE *fp;
	if( (fp = fopen("Teacher' Work.txt","a")) == NULL ) //���ļ��������ʧ�ܸ��û���ʾ 
	{
		printf("Can't open the file.");
		exit(1);
	}
	else
	{
		printf("****************************************************\n");
	    printf("\n ====================��ʦע��==================\n");
		int num, f = 1;          //�����˺�
		char p[20],zh[50];
		printf("\tPlease Student's Num:\n");
		printf("\t(if you want to stop, input 0)");
		scanf("%s", zh);
		num = pdzh(zh);
        if (num == 0) {
	        printf("\t��������룡��"); 
        }
		while(num!=0)    //ѭ������ֱ���û������Num=0ʱֹͣ¼�� 
		{
			f= zhpdcf("Teacher' Work.txt",zh);
		    if (f == 0) {
		        break;
	        }
			
		    int i = 0;  //��������
			
			fprintf(fp,"%s ",zh);  //��num�Լ�һ���ո񱣴浽�ļ��У���ͬ
			 
			printf("\tPlease teacher's password:");   //¼������ 
			 
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
	        	printf("\t��������룡��"); 
       	 	}
       	 	
		    f= zhpdcf("Teacher' Work.txt",zh);
		    if (f == 0) {
		        break;
	        }
		}
		fclose(fp);   //�ر��ļ� 
		printf("\n");
	    printf("\t ==================================================\n");
	    printf("\t||          8----------���ص�¼����               ||\n");                //��� 
		printf("\t||          9----------������һ��                 ||\n");                //��� 
	    printf("\t||          0----------�˳�ϵͳ                   ||\n");                //��� 
	    printf("\t ==================================================\n");
	    int choice = 0;
	    f = 1;
	char c[20];
	scanf("%s", c);  //��¼�û���ѡ����Ϊ����ֵ���� 
	for (int i = 0; i < strlen(c); i++) {
		if (c[i] < '0' || c[i] > '9') {
			f = 0;
		}
		choice = choice * 10 + (c[i] - '0');
	}
	if (f == 0) {
		printf("��������");
		dljm();
	}
	else {
	    switch(choice) {
			case 8:dljm();break;//���ص�¼����
			case 9:zcjm();break;//������һ��
			case 0:return;      //�˳�ϵͳ
			default:dljm();break;
		}
	}
}
}
/*
�û�ע����� 
*/
int zcjm()    
{
	system("cls");		//���� 
	printf("\n ====================ע�����==================\n");
	printf("|| Enter                                      ||\n");
	printf("||          1----------ѧ��ע��               ||\n");
	printf("||          2----------��ʦע��               ||\n");
	printf("||          3----------����Աע��             ||\n");
	printf("||          9----------������һ��             ||\n");
	printf("||          0----------�˳�ϵͳ               ||\n");
	printf(" ==============================================\n");
	printf("************************************************\nPlease Enter\n");
	int choice = 0, f = 1;
	char c[20];
	scanf("%s", c);  //��¼�û���ѡ����Ϊ����ֵ���� 
	for (int i = 0; i < strlen(c); i++) {
		if (c[i] < '0' || c[i] > '9') {
			f = 0;
		}
		choice = choice * 10 + (c[i] - '0');
	}
	if (f == 0) {
		printf("��������");
		dljm();
	}
	else {
	switch(choice) {
		case 1:xxzc();break;         //ѧ��ע��
		case 2:jszc();break;         //��ʦע��
		case 3:record_admin();break; //����Աע��
		case 9:glyzjm();break;       //������һ��
		case 0:return 0;             //�˳�ϵͳ
		default:dljm();break;
	}
	}
}
/*
1.��¼����
*/
int dljm()    
{
	system("cls");		//���� 
	printf("\n ===================��¼����=================\n");
	printf("|| Enter                                      ||\n");
	printf("||          1----------ѧ����¼               ||\n");
	printf("||          2----------��ʦ��¼               ||\n");
	printf("||          3----------����Ա��¼             ||\n");
	printf("||          4----------�û�ע��               ||\n");
	printf("||          0----------�˳�ϵͳ               ||\n");
	printf(" ==============================================\n");
	printf("************************************************\nPlease Enter\n");
	int choice = 0, f = 1;
	char c[20];
	scanf("%s", c);  //��¼�û���ѡ����Ϊ����ֵ���� 
	for (int i = 0; i < strlen(c); i++) {
		if (c[i] < '0' || c[i] > '9') {
			f = 0;
		}
		choice = choice * 10 + (c[i] - '0');
	}
	if (f == 0) {
		printf("��������");
		dljm();
	}
	else {
		switch(choice) {
			case 1:xxdl();break; //ѧ����¼
			case 2:jsdl();break; //��ʦ��¼
			case 3:glydl();break;//����Ա��¼
			case 4:glydl();break;//�û�ע��
			case 0:return 0;     //�˳�ϵͳ
			default:dljm();break;
		}
	}
}
/*
�����򣨷�װ��ѯ��
*/
int main() {
	system("color f0");
	dljm();
}


