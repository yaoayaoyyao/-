void cjpx() {
	char subject[50];
	system("cls");		//清屏 
	head = Read1();
	printf("\n\tplease input the subject what you want:\n");
	scanf("%s",subject);
	if (strcmp(subject,"yw") != 0 && strcmp(subject,"sx") != 0 && strcmp(subject,"yy") != 0 && strcmp(subject,"source") != 0) {
		printf("\n\tYour input are wrong!");
		fclose(fpn);
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
	if (strcmp(subject,"source") != 0) {
		cjpx_source(head);
	}
	FILE *fp;
	int i = 0;
	fp = fopen("成绩排序.txt", "w+");
	stu_info *ptemp;
	ptemp = phead->next;
	while(pnew){
		i++;
		fprintf(fp,"%s %s %s %s %s %s %d %d\n", ptemp->name, ptemp->num, ptemp->bj, ptemp->yw, ptemp->sx, ptemp->yy, ptemp->source, i);
		pnew=pnew->next;
	}
	fclose(fp);
} 






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
	printf("||          0----------网络年级                   ||\n");                //完成 
	printf(" ==================================================\n");
	printf("************************************************\nPlease Enter\n");
	int choice = 0, f = 1 , i, source;
	char num[50],name[50],bj[50],yw[50],sx[50],yy[50];
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
			case 0:strcpy(scj,"allclass.txt");break;                        //退出系统
			default:jszjm();break;
		}
		cjpx();
		FILE *fp;
	    fp = fopen("成绩排序.txt", "r");
	    while(!feof(fp)) {
	    	fscanf(fp,"%s %s %s %s %s %s %d %d\n", name, num, bj, yw, sx, yy, source, i);
	    	printf("%s %s %s %s %s %s %d %d\n", name, num, bj, yw, sx, yy, source, i);
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
