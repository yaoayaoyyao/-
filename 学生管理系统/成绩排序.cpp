#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include <malloc.h>
int count = 0;
/*
转换成绩 
*/
int zhcj(char *a) 
{
	int len = strlen(a), cj = 0;
	for (int i = 0; i < len; i++) {
		if (a[i] < '0' || a[i] > '9') {
			cj = -1;
			break;
		}
		cj = cj * 10 + (a[i]-'0');
	}
	return cj;
}
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
struct student * Read1()                            //从文件读到链表(学生信息)
{
	int i = 0,a,b,d;
	char ch;
	FILE *fp,*fpn;
	fp = fopen("class1.txt", "r");
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
	    	i++;
	    	a = zhcj(pnew->yw);
		    b = zhcj(pnew->sx);
		    d = zhcj(pnew->yy);
		    pnew->source = a + b + d;
	    	//fprintf(fpn,"%s %s %s %s %s %s %d\n", pnew->name, pnew->num, pnew->bj, pnew->yw, pnew->sx, pnew->yy, i);
			count++;
			pnew->next = NULL;
			pend->next = pnew;
			pend = pnew;
		}
	}
	pend->next = NULL;
	fclose(fp);
	return phead;
}
void BubbleSort(struct student *head){
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
void print(stu_info *phead) {
	FILE *fpn;
	int i = 0, source, a, b, d;
	fpn = fopen("成绩排序.txt", "w+");
	stu_info *pnew;
	pnew = phead->next;
	while(pnew){
		i++;
		fprintf(fpn,"%s %s %s %s %s %s %d %d\n", pnew->name, pnew->num, pnew->bj, pnew->yw, pnew->sx, pnew->yy, pnew->source, i);
		//printf("%s\n",ptemp->yw);
		pnew=pnew->next;
	}
}
int main() {
	head = Read1();
	BubbleSort(head);
	print(head);
}
