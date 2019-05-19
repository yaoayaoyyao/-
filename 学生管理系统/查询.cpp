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
		case 0:return 0;                         //退出系统
		default:jszjm();;break;
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
	printf("||          0----------网络年级                   ||\n");                //完成 
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
		case 0:strcpy(sin,"allclass.txt");break;                        //退出系统
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
		printf("%s\n",yw);
	}
	fclose(fp);
	fclose(fpn);
	qjcx();
    }
}





