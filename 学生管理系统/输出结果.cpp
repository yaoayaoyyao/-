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
