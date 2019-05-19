int xxzjm()    
{
	system("cls");		//清屏 
	printf("\n =================学生主界面=================\n");
	printf("|| Enter                                      ||\n");
	printf("||          1----------成绩查询               ||\n");          //ok 
	printf("||          2----------查询本班成绩           ||\n");          //ok 
	printf("||          3----------成绩分析               ||\n");          //ok 
	printf("||          4----------成绩申诉               ||\n");
	printf("||          5----------返回上一层             ||\n");
	printf("||          0----------退出系统               ||\n");
	printf(" ==============================================\n");
	printf("************************************************\nPlease Enter\n");
	int choice;
	scanf("%d",&choice);  //记录用户的选择并作为返回值返回 
	return choice;
}
int jszjm()    
{
	system("cls");		//清屏 
	printf("\n ===================教师主界面===================\n");
	printf("|| Enter                                          ||\n");
	printf("||          1----------学生信息增加               ||\n");       //ok 
	printf("||          2----------删除学生信息               ||\n");       //ok 
	printf("||          3----------修改学生信息               ||\n");       //ok 
	printf("||          4----------查询学生信息               ||\n");       //ok 
	printf("||          5----------输出本班成绩               ||\n");       //ok 
	printf("||          6----------下载到文件中               ||\n");       //ok 
	printf("||          7----------成绩分析                   ||\n");       //ok 
	printf("||          8----------提醒管理员进行成绩的更新   ||\n");
	printf("||          9----------返回上一层                 ||\n");
	printf("||          0----------退出系统                   ||\n");
	printf(" ==================================================\n");
	printf("************************************************\nPlease Enter\n");
	int choice;
	scanf("%d",&choice);  //记录用户的选择并作为返回值返回 
	return choice;
}
int glyzjm()    
{
	system("cls");		//清屏 
	printf("\n ===================管理员主界面=================\n");
	printf("|| Enter                                          ||\n");
	printf("||          1----------查看代办选项               ||\n");
	printf("||          2----------进入教师端                 ||\n");
	printf("||          3----------增加账号和密码             ||\n");
	printf("||          4----------删除账号和密码             ||\n");
	printf("||          5----------修改账号和密码             ||\n");
	printf("||          6----------查找账号和密码             ||\n"); 
	printf("||          7----------录入所有账号和密码         ||\n");
	printf("||          8----------输出所有账号和密码         ||\n");
	printf("||          9----------手动重新录入学生信息       ||\n");       //ok
	printf("||          a----------返回上一层                 ||\n");
	printf("||          0----------退出系统                   ||\n");
	printf(" ==================================================\n");
	printf("************************************************\nPlease Enter\n");
	int choice;
	scanf("%d",&choice);  //记录用户的选择并作为返回值返回 
	return choice;
}
int dbjm()    
{
	system("cls");		//清屏 
	printf("\n ===================代办选项=================\n");
	printf("|| Enter                                      ||\n");
	printf("||          1----------密码注册               ||\n");
	printf("||          2----------密码修改               ||\n");
	printf("||          3----------密码找回               ||\n");
	printf("||          4----------成绩申诉               ||\n");
	printf("||          5----------更新成绩库             ||\n");      
	printf("||          a----------返回上一层             ||\n");
	printf("||          0----------退出系统               ||\n");
	printf(" ==============================================\n");
	printf("************************************************\nPlease Enter\n");
	int choice;
	scanf("%d",&choice);  //记录用户的选择并作为返回值返回 
	return choice;
}
int zcjm()    
{
	system("cls");		//清屏 
	printf("\n ====================注册界面==================\n");
	printf("|| Enter                                      ||\n");
	printf("||          1----------学生注册               ||\n");
	printf("||          2----------教师注册               ||\n");
	printf("||          0----------退出系统               ||\n");
	printf(" ==============================================\n");
	printf("************************************************\nPlease Enter\n");
	int choice;
	scanf("%d",&choice);  //记录用户的选择并作为返回值返回 
	switch(choice) {
		case 1:xxzc();break;//学生模式
		case 2:jszc();break;//教师注册
		case 0:return 0;    //退出系统
		default:break;
	}
}
int dljm()    
{
	system("cls");		//清屏 
	printf("\n ====================登录界面==================\n");
	printf("|| Enter                                        ||\n");
	printf("||          1----------学生登录               ||\n");
	printf("||          2----------教师登录               ||\n");
	printf("||          3----------管理员登录             ||\n");
	printf("||          0----------退出系统               ||\n");
	printf(" ==============================================\n");
	printf("************************************************\nPlease Enter\n");
	int choice;
	scanf("%d",&choice);  //记录用户的选择并作为返回值返回 
	switch(choice) {
		case 1:xxdl();break; //学生登录
		case 2:jsdl();break; //教师登录
		case 3:glydl();break;//管理员登录
		case 0:return 0;     //退出系统
		default:break;
	}
}
void xxdl()
{
	system("cls");		//清屏
	printf("***************************************************\n");
	printf("\n====================学生登录==================\n");
	FILE *fp;
	int num,scan_num;
	int password,scan_password;
	char p[20];
    int i=0;
	printf("\n   请输入你的账号:");
	scanf("%d",&scan_num);
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
        }
        else {
            i=i+1;
            printf("*");
        }
    }while(p[i]!='\n' && i<20);
            
    for(int j = 0; j < i; j++) {
         scan_password = (p[j] - '0') + scan_password * 10;
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
			if(fscanf(fp,"%d",&num)==-1)       //判断num还是否可以被读出
				break;
			fscanf(fp,"%d",&password);
			if(scan_num==num)                  //判断是否和输入的学号一样，如果一样输出 
			{
				if(scan_password==password)    //判断是否和输入的密码一样，如果一样输出 
			    {
			    	fclose(fp);
				    xxzjm();
				    return;
			    }
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
	    int choice;
	    scanf("%d",&choice);  //记录用户的选择并作为返回值返回 
	    switch(choice) {
			case 1:zjm();break;//返回上一层
			case 9:xsdl();break; //重新输入
			case 0:return;       //退出系统
			default:break;
		}
	}	
}
void jsdl()
{
	system("cls");		//清屏
	printf("***************************************************\n");
	printf("\n====================教师登录==================\n");
	FILE *fp;
	int num,scan_num;
	int password,scan_password;
	char p[20];
    int i=0;
	printf("\n   请输入你的账号:");
	scanf("%d",&scan_num);
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
        }
        else {
            i=i+1;
            printf("*");
        }
    }while(p[i]!='\n' && i<20);
            
    for(int j = 0; j < i; j++) {
         scan_password = (p[j] - '0') + scan_password * 10;
	} 
	
	if( (fp = fopen("Teacher' Work.txt","r")) == NULL)   //打开文件，同上
	{
		printf("Can't open the file.");
		exit(1);
	}
	else
	{
		while(!feof(fp))
		{
			if(fscanf(fp,"%d",&num)==-1)       //判断num还是否可以被读出
				break;
			fscanf(fp,"%d",&password);
			if(scan_num==num)                  //判断是否和输入的学号一样，如果一样输出 
			{
				if(scan_password==password)    //判断是否和输入的密码一样，如果一样输出 
			    {
			    	fclose(fp);
				    jszjm();
				    return;
			    }
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
	    int choice;
	    scanf("%d",&choice);  //记录用户的选择并作为返回值返回 
	    switch(choice) {
			case 1:zjm();break;//返回上一层
			case 9:jsdl();break; //重新输入
			case 0:return;       //退出系统
			default:break;
		}
	}
}
void glydl()
{
	system("cls");		//清屏
	printf("*****************************************************\n");
	printf("\n====================管理员登录==================\n");
	FILE *fp;
	int num,scan_num;
	int password,scan_password;
	char p[20];
    int i=0;
	printf("\n   请输入你的账号:");
	scanf("%d",&scan_num);
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
        }
        else {
            i=i+1;
            printf("*");
        }
    }while(p[i]!='\n' && i<20);
            
    for(int j = 0; j < i; j++) {
         scan_password = (p[j] - '0') + scan_password * 10;
	} 
	
	if( (fp = fopen("Admin' Work.txt","r")) == NULL)   //打开文件，同上
	{
		printf("Can't open the file.");
		exit(1);
	}
	else
	{
		while(!feof(fp))
		{
			if(fscanf(fp,"%d",&num)==-1)       //判断num还是否可以被读出
				break;
			fscanf(fp,"%d",&password);
			if(scan_num==num)                  //判断是否和输入的学号一样，如果一样输出 
			{
				if(scan_password==password)    //判断是否和输入的密码一样，如果一样输出 
			    {
			    	fclose(fp);
				    glyzjm();
				    return;
			    }
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
	    int choice;
	    scanf("%d",&choice);  //记录用户的选择并作为返回值返回 
	    switch(choice) {
			case 1:zjm();break;//返回上一层
			case 9:glydl();break; //重新输入
			case 0:return;       //退出系统
			default:break;
		}
	}	
}
int show_student_UI()
{
	int choice;
	printf("\nPlease input your class numble:");
	scanf("%d",&choice);
	switch(choice) {
		case 1:strcpy(s,"class1.txt");xxzjm();break;
		case 2:strcpy(s,"class2.txt");xxzjm();break;
		case 3:strcpy(s,"class3.txt");xxzjm();break;
		case 4:strcpy(s,"class4.txt");xxzjm();break;
	    case 5:strcpy(s,"class5.txt");xxzjm();break;
		default:printf("没有这个班级！！");return 0;
	}
}
int show_teacher_UI()
{
	int choice;
	printf("\nPlease input your class numble:");
	scanf("%d",&choice);
	switch(choice) {
		case 1:strcpy(s,"class1.txt");jszjm();break;
		case 2:strcpy(s,"class2.txt");jszjm();break;
		case 3:strcpy(s,"class3.txt");jszjm();break;
		case 4:strcpy(s,"class4.txt");jszjm();break;
	    case 5:strcpy(s,"class5.txt");jszjm();break;
		default:printf("没有这个班级！！");return 0;
	}
}
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
		int num;          //保存账号
		char p[20];
		printf("\tPlease student's Num:");
		scanf("%d",&num);
		while(num!=0)    //循环输入直到用户输入的Num=0时停止录入 
		{
		    int password = 0, i = 0;  //保存密码
			
			fprintf(fp,"%d ",num);  //将num以及一个空格保存到文件中，下同
			 
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
                }
                else {
                     i=i+1;
                     printf("*");
                }
            }while(p[i]!='\n' && i<20);
            
            for(int j = 0; j < i; j++) {
            	password = (p[j] - '0') + password * 10;
			} 
            
			fprintf(fp,"%d\n",password);
			
			printf("\n\tPlease student's Num:");
			scanf("%d",&num);
		
		}
		fclose(fp);   //关闭文件 
		printf("\n");
	    printf("\t ==================================================\n");
		printf("\t||          9----------返回登录界面               ||\n");                //完成 
	    printf("\t||          0----------退出系统                   ||\n");                //完成 
	    printf("\t ==================================================\n");
	    int choice;
	    scanf("%d",&choice);  //记录用户的选择并作为返回值返回 
	    switch(choice) {
			case 9:dljm();break;//返回上一层
			case 0:return;      //退出系统
			default:break;
		}
	}
}
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
		int num;          //保存账号
		char p[20];
		printf("\tPlease student's Num:");
		scanf("%d",&num);
		while(num!=0)    //循环输入直到用户输入的Num=0时停止录入 
		{
		    int password = 0, i = 0;  //保存密码
			
			fprintf(fp,"%d ",num);  //将num以及一个空格保存到文件中，下同
			 
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
                }
                else {
                     i=i+1;
                     printf("*");
                }
            }while(p[i]!='\n' && i<20);
            
            for(int j = 0; j < i; j++) {
            	password = (p[j] - '0') + password * 10;
			} 
            
			fprintf(fp,"%d\n",password);
			
			printf("\n\tPlease student's Num:");
			scanf("%d",&num);
		
		}
		fclose(fp);   //关闭文件 
		printf("\n");
	    printf("\t ==================================================\n");
		printf("\t||          9----------返回登录界面               ||\n");                //完成 
	    printf("\t||          0----------退出系统                   ||\n");                //完成 
	    printf("\t ==================================================\n");
	    int choice;
	    scanf("%d",&choice);  //记录用户的选择并作为返回值返回 
	    switch(choice) {
			case 9:dljm();break;//返回上一层
			case 0:return;      //退出系统
			default:break;
		}
	}
}

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
char zh[50];
printf("\n   请输入想查询信息学生的学号:");
scanf("%s", zh);
scan_num = pdzh(zh);
if (scan_num == 0) {
	printf("\t错误的输入！！"); 
}
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
int pdmm(char *password,char *p) 
{
	int i = strlen(password), f = 1;
	for (int j = 0; j <= i; j++) {
		if (password[j] != p[j]) {
			f = 0;
		}
	}
	return f;
}
int cxjm()    
{
	system("cls");		//清屏 
	printf("\n ====================查询界面==================\n");
	printf("|| Enter                                      ||\n");
	printf("||          1----------查询学生账号           ||\n");
	printf("||          2----------查询教师账号           ||\n");
	printf("||          3----------查询管理员账号         ||\n");
	printf("||          0----------退出系统               ||\n");
	printf(" ==============================================\n");
	printf("************************************************\nPlease Enter\n");
	int choice;
	scanf("%d",&choice);  //记录用户的选择并作为返回值返回 
	switch(choice) {
		case 1:strcpy(cx,"Student' Work.txt");query_admin();break;//查询学生
		case 2:strcpy(cx,"Teacher' Work.txt");query_admin();break;//查询教师
		case 3:strcpy(cx,"Admin' Work.txt");query_admin();break;  //查询管理员
		case 0:return 0;    //退出系统
		default:break;
	}
}
int scjm()    
{
	system("cls");		//清屏 
	printf("\n ====================查询界面==================\n");
	printf("|| Enter                                      ||\n");
	printf("||          1----------查询学生账号           ||\n");
	printf("||          2----------查询教师账号           ||\n");
	printf("||          3----------查询管理员账号         ||\n");
	printf("||          0----------退出系统               ||\n");
	printf(" ==============================================\n");
	printf("************************************************\nPlease Enter\n");
	int choice;
	scanf("%d",&choice);  //记录用户的选择并作为返回值返回 
	switch(choice) {
		case 1:strcpy(cx,"Student' Work.txt");query_admin();break;//查询学生
		case 2:strcpy(cx,"Teacher' Work.txt");query_admin();break;//查询教师
		case 3:strcpy(cx,"Admin' Work.txt");query_admin();break;  //查询管理员
		case 0:return 0;    //退出系统
		default:break;
	}
}
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
void Modify_num()
{
	FILE *fp;
	FILE *fpn; 
	char newfilename[] = "Students' Work temp.txt"; //一个临时文件 
	char num[50],tonum[50];
	int yw,sx,yy,toyw,tosx,toyy,f;
	char toname[20],tobj[20];				       //不能修改学号
	if( (fpn = fopen(newfilename,"w")) == NULL || (fp = fopen(s,"r")) == NULL)   //打开文件，同上 
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
	        		scanf("%d%d%d",&toyw,&tosx,&toyy);
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
				 fprintf(fpn,"%s %s %s %d %d %d\n",toname,tonum,tobj,toyw,tosx,toyy);
				 printf("\t已成功修改。");
		    }
			else
			{
				fprintf(fpn,"%s %s %s %d %d %d\n",namecpy,num,bj,yw,sx,yy);
			}
		}
		fclose(fp);
		fclose(fpn);
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
			default:break;
		}
	}	
}
}
int pdcj(int yw,int sx,int yy)
{
	if (yw < 0 || yw > 0 || sx < 0 || sx > 0 || yy < 0 || yy > 0) {
		    return 0;
	}
	return 1;
}
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
int pdcf(char *s2,char *num1)
{
	FILE *fp;
	char name[50],num[50],bj[50];
	int yw, sx, yy, f = 1;
	if( (fp = fopen(s,"r")) == NULL)   //打开文件，同上 
	{
		printf("Can't open the file.");
		exit(1);
	}
	while(!feof(fp)) {
		fscanf(fp,"%s %s %s %s %s %s\n",name,num,bj,yw,sx,yy);
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




void fhjsdl(){
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
			default:jsdl();break;
		}
	}
}



void fhxxdl(){
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
			case 9:jsdl();break; //重新输入
			case 0:return;       //退出系统
			default:xxdl();break;
		}
	}
}


void fhglydl(){
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




