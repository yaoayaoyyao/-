int xxzjm()    
{
	system("cls");		//���� 
	printf("\n =================ѧ��������=================\n");
	printf("|| Enter                                      ||\n");
	printf("||          1----------�ɼ���ѯ               ||\n");          //ok 
	printf("||          2----------��ѯ����ɼ�           ||\n");          //ok 
	printf("||          3----------�ɼ�����               ||\n");          //ok 
	printf("||          4----------�ɼ�����               ||\n");
	printf("||          5----------������һ��             ||\n");
	printf("||          0----------�˳�ϵͳ               ||\n");
	printf(" ==============================================\n");
	printf("************************************************\nPlease Enter\n");
	int choice;
	scanf("%d",&choice);  //��¼�û���ѡ����Ϊ����ֵ���� 
	return choice;
}
int jszjm()    
{
	system("cls");		//���� 
	printf("\n ===================��ʦ������===================\n");
	printf("|| Enter                                          ||\n");
	printf("||          1----------ѧ����Ϣ����               ||\n");       //ok 
	printf("||          2----------ɾ��ѧ����Ϣ               ||\n");       //ok 
	printf("||          3----------�޸�ѧ����Ϣ               ||\n");       //ok 
	printf("||          4----------��ѯѧ����Ϣ               ||\n");       //ok 
	printf("||          5----------�������ɼ�               ||\n");       //ok 
	printf("||          6----------���ص��ļ���               ||\n");       //ok 
	printf("||          7----------�ɼ�����                   ||\n");       //ok 
	printf("||          8----------���ѹ���Ա���гɼ��ĸ���   ||\n");
	printf("||          9----------������һ��                 ||\n");
	printf("||          0----------�˳�ϵͳ                   ||\n");
	printf(" ==================================================\n");
	printf("************************************************\nPlease Enter\n");
	int choice;
	scanf("%d",&choice);  //��¼�û���ѡ����Ϊ����ֵ���� 
	return choice;
}
int glyzjm()    
{
	system("cls");		//���� 
	printf("\n ===================����Ա������=================\n");
	printf("|| Enter                                          ||\n");
	printf("||          1----------�鿴����ѡ��               ||\n");
	printf("||          2----------�����ʦ��                 ||\n");
	printf("||          3----------�����˺ź�����             ||\n");
	printf("||          4----------ɾ���˺ź�����             ||\n");
	printf("||          5----------�޸��˺ź�����             ||\n");
	printf("||          6----------�����˺ź�����             ||\n"); 
	printf("||          7----------¼�������˺ź�����         ||\n");
	printf("||          8----------��������˺ź�����         ||\n");
	printf("||          9----------�ֶ�����¼��ѧ����Ϣ       ||\n");       //ok
	printf("||          a----------������һ��                 ||\n");
	printf("||          0----------�˳�ϵͳ                   ||\n");
	printf(" ==================================================\n");
	printf("************************************************\nPlease Enter\n");
	int choice;
	scanf("%d",&choice);  //��¼�û���ѡ����Ϊ����ֵ���� 
	return choice;
}
int dbjm()    
{
	system("cls");		//���� 
	printf("\n ===================����ѡ��=================\n");
	printf("|| Enter                                      ||\n");
	printf("||          1----------����ע��               ||\n");
	printf("||          2----------�����޸�               ||\n");
	printf("||          3----------�����һ�               ||\n");
	printf("||          4----------�ɼ�����               ||\n");
	printf("||          5----------���³ɼ���             ||\n");      
	printf("||          a----------������һ��             ||\n");
	printf("||          0----------�˳�ϵͳ               ||\n");
	printf(" ==============================================\n");
	printf("************************************************\nPlease Enter\n");
	int choice;
	scanf("%d",&choice);  //��¼�û���ѡ����Ϊ����ֵ���� 
	return choice;
}
int zcjm()    
{
	system("cls");		//���� 
	printf("\n ====================ע�����==================\n");
	printf("|| Enter                                      ||\n");
	printf("||          1----------ѧ��ע��               ||\n");
	printf("||          2----------��ʦע��               ||\n");
	printf("||          0----------�˳�ϵͳ               ||\n");
	printf(" ==============================================\n");
	printf("************************************************\nPlease Enter\n");
	int choice;
	scanf("%d",&choice);  //��¼�û���ѡ����Ϊ����ֵ���� 
	switch(choice) {
		case 1:xxzc();break;//ѧ��ģʽ
		case 2:jszc();break;//��ʦע��
		case 0:return 0;    //�˳�ϵͳ
		default:break;
	}
}
int dljm()    
{
	system("cls");		//���� 
	printf("\n ====================��¼����==================\n");
	printf("|| Enter                                        ||\n");
	printf("||          1----------ѧ����¼               ||\n");
	printf("||          2----------��ʦ��¼               ||\n");
	printf("||          3----------����Ա��¼             ||\n");
	printf("||          0----------�˳�ϵͳ               ||\n");
	printf(" ==============================================\n");
	printf("************************************************\nPlease Enter\n");
	int choice;
	scanf("%d",&choice);  //��¼�û���ѡ����Ϊ����ֵ���� 
	switch(choice) {
		case 1:xxdl();break; //ѧ����¼
		case 2:jsdl();break; //��ʦ��¼
		case 3:glydl();break;//����Ա��¼
		case 0:return 0;     //�˳�ϵͳ
		default:break;
	}
}
void xxdl()
{
	system("cls");		//����
	printf("***************************************************\n");
	printf("\n====================ѧ����¼==================\n");
	FILE *fp;
	int num,scan_num;
	int password,scan_password;
	char p[20];
    int i=0;
	printf("\n   ����������˺�:");
	scanf("%d",&scan_num);
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
        }
        else {
            i=i+1;
            printf("*");
        }
    }while(p[i]!='\n' && i<20);
            
    for(int j = 0; j < i; j++) {
         scan_password = (p[j] - '0') + scan_password * 10;
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
			if(fscanf(fp,"%d",&num)==-1)       //�ж�num���Ƿ���Ա�����
				break;
			fscanf(fp,"%d",&password);
			if(scan_num==num)                  //�ж��Ƿ�������ѧ��һ�������һ����� 
			{
				if(scan_password==password)    //�ж��Ƿ�����������һ�������һ����� 
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
		printf("\t||          1----------������һ��                 ||\n"); 
		printf("\t||          9----------��������                   ||\n");                //��� 
	    printf("\t||          0----------�˳�ϵͳ                   ||\n");                //��� 
	    printf("\t ==================================================\n");
	    int choice;
	    scanf("%d",&choice);  //��¼�û���ѡ����Ϊ����ֵ���� 
	    switch(choice) {
			case 1:zjm();break;//������һ��
			case 9:xsdl();break; //��������
			case 0:return;       //�˳�ϵͳ
			default:break;
		}
	}	
}
void jsdl()
{
	system("cls");		//����
	printf("***************************************************\n");
	printf("\n====================��ʦ��¼==================\n");
	FILE *fp;
	int num,scan_num;
	int password,scan_password;
	char p[20];
    int i=0;
	printf("\n   ����������˺�:");
	scanf("%d",&scan_num);
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
        }
        else {
            i=i+1;
            printf("*");
        }
    }while(p[i]!='\n' && i<20);
            
    for(int j = 0; j < i; j++) {
         scan_password = (p[j] - '0') + scan_password * 10;
	} 
	
	if( (fp = fopen("Teacher' Work.txt","r")) == NULL)   //���ļ���ͬ��
	{
		printf("Can't open the file.");
		exit(1);
	}
	else
	{
		while(!feof(fp))
		{
			if(fscanf(fp,"%d",&num)==-1)       //�ж�num���Ƿ���Ա�����
				break;
			fscanf(fp,"%d",&password);
			if(scan_num==num)                  //�ж��Ƿ�������ѧ��һ�������һ����� 
			{
				if(scan_password==password)    //�ж��Ƿ�����������һ�������һ����� 
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
		printf("\t||          1----------������һ��                 ||\n"); 
		printf("\t||          9----------��������                   ||\n");                //��� 
	    printf("\t||          0----------�˳�ϵͳ                   ||\n");                //��� 
	    printf("\t ==================================================\n");
	    int choice;
	    scanf("%d",&choice);  //��¼�û���ѡ����Ϊ����ֵ���� 
	    switch(choice) {
			case 1:zjm();break;//������һ��
			case 9:jsdl();break; //��������
			case 0:return;       //�˳�ϵͳ
			default:break;
		}
	}
}
void glydl()
{
	system("cls");		//����
	printf("*****************************************************\n");
	printf("\n====================����Ա��¼==================\n");
	FILE *fp;
	int num,scan_num;
	int password,scan_password;
	char p[20];
    int i=0;
	printf("\n   ����������˺�:");
	scanf("%d",&scan_num);
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
        }
        else {
            i=i+1;
            printf("*");
        }
    }while(p[i]!='\n' && i<20);
            
    for(int j = 0; j < i; j++) {
         scan_password = (p[j] - '0') + scan_password * 10;
	} 
	
	if( (fp = fopen("Admin' Work.txt","r")) == NULL)   //���ļ���ͬ��
	{
		printf("Can't open the file.");
		exit(1);
	}
	else
	{
		while(!feof(fp))
		{
			if(fscanf(fp,"%d",&num)==-1)       //�ж�num���Ƿ���Ա�����
				break;
			fscanf(fp,"%d",&password);
			if(scan_num==num)                  //�ж��Ƿ�������ѧ��һ�������һ����� 
			{
				if(scan_password==password)    //�ж��Ƿ�����������һ�������һ����� 
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
		printf("\t||          1----------������һ��                 ||\n"); 
		printf("\t||          9----------��������                   ||\n");                //��� 
	    printf("\t||          0----------�˳�ϵͳ                   ||\n");                //��� 
	    printf("\t ==================================================\n");
	    int choice;
	    scanf("%d",&choice);  //��¼�û���ѡ����Ϊ����ֵ���� 
	    switch(choice) {
			case 1:zjm();break;//������һ��
			case 9:glydl();break; //��������
			case 0:return;       //�˳�ϵͳ
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
		default:printf("û������༶����");return 0;
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
		default:printf("û������༶����");return 0;
	}
}
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
		int num;          //�����˺�
		char p[20];
		printf("\tPlease student's Num:");
		scanf("%d",&num);
		while(num!=0)    //ѭ������ֱ���û������Num=0ʱֹͣ¼�� 
		{
		    int password = 0, i = 0;  //��������
			
			fprintf(fp,"%d ",num);  //��num�Լ�һ���ո񱣴浽�ļ��У���ͬ
			 
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
		fclose(fp);   //�ر��ļ� 
		printf("\n");
	    printf("\t ==================================================\n");
		printf("\t||          9----------���ص�¼����               ||\n");                //��� 
	    printf("\t||          0----------�˳�ϵͳ                   ||\n");                //��� 
	    printf("\t ==================================================\n");
	    int choice;
	    scanf("%d",&choice);  //��¼�û���ѡ����Ϊ����ֵ���� 
	    switch(choice) {
			case 9:dljm();break;//������һ��
			case 0:return;      //�˳�ϵͳ
			default:break;
		}
	}
}
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
		int num;          //�����˺�
		char p[20];
		printf("\tPlease student's Num:");
		scanf("%d",&num);
		while(num!=0)    //ѭ������ֱ���û������Num=0ʱֹͣ¼�� 
		{
		    int password = 0, i = 0;  //��������
			
			fprintf(fp,"%d ",num);  //��num�Լ�һ���ո񱣴浽�ļ��У���ͬ
			 
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
		fclose(fp);   //�ر��ļ� 
		printf("\n");
	    printf("\t ==================================================\n");
		printf("\t||          9----------���ص�¼����               ||\n");                //��� 
	    printf("\t||          0----------�˳�ϵͳ                   ||\n");                //��� 
	    printf("\t ==================================================\n");
	    int choice;
	    scanf("%d",&choice);  //��¼�û���ѡ����Ϊ����ֵ���� 
	    switch(choice) {
			case 9:dljm();break;//������һ��
			case 0:return;      //�˳�ϵͳ
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
printf("\n   ���������ѯ��Ϣѧ����ѧ��:");
scanf("%s", zh);
scan_num = pdzh(zh);
if (scan_num == 0) {
	printf("\t��������룡��"); 
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
	system("cls");		//���� 
	printf("\n ====================��ѯ����==================\n");
	printf("|| Enter                                      ||\n");
	printf("||          1----------��ѯѧ���˺�           ||\n");
	printf("||          2----------��ѯ��ʦ�˺�           ||\n");
	printf("||          3----------��ѯ����Ա�˺�         ||\n");
	printf("||          0----------�˳�ϵͳ               ||\n");
	printf(" ==============================================\n");
	printf("************************************************\nPlease Enter\n");
	int choice;
	scanf("%d",&choice);  //��¼�û���ѡ����Ϊ����ֵ���� 
	switch(choice) {
		case 1:strcpy(cx,"Student' Work.txt");query_admin();break;//��ѯѧ��
		case 2:strcpy(cx,"Teacher' Work.txt");query_admin();break;//��ѯ��ʦ
		case 3:strcpy(cx,"Admin' Work.txt");query_admin();break;  //��ѯ����Ա
		case 0:return 0;    //�˳�ϵͳ
		default:break;
	}
}
int scjm()    
{
	system("cls");		//���� 
	printf("\n ====================��ѯ����==================\n");
	printf("|| Enter                                      ||\n");
	printf("||          1----------��ѯѧ���˺�           ||\n");
	printf("||          2----------��ѯ��ʦ�˺�           ||\n");
	printf("||          3----------��ѯ����Ա�˺�         ||\n");
	printf("||          0----------�˳�ϵͳ               ||\n");
	printf(" ==============================================\n");
	printf("************************************************\nPlease Enter\n");
	int choice;
	scanf("%d",&choice);  //��¼�û���ѡ����Ϊ����ֵ���� 
	switch(choice) {
		case 1:strcpy(cx,"Student' Work.txt");query_admin();break;//��ѯѧ��
		case 2:strcpy(cx,"Teacher' Work.txt");query_admin();break;//��ѯ��ʦ
		case 3:strcpy(cx,"Admin' Work.txt");query_admin();break;  //��ѯ����Ա
		case 0:return 0;    //�˳�ϵͳ
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
	char newfilename[] = "Students' Work temp.txt"; //һ����ʱ�ļ� 
	char num[50],tonum[50];
	int yw,sx,yy,toyw,tosx,toyy,f;
	char toname[20],tobj[20];				       //�����޸�ѧ��
	if( (fpn = fopen(newfilename,"w")) == NULL || (fp = fopen(s,"r")) == NULL)   //���ļ���ͬ�� 
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
			if(strcmp(tonum, num) == 0 && f == 1)    //�ж��Ƿ�������ѧ��һ�������һ������
			{
				 fprintf(fpn,"%s %s %s %d %d %d\n",toname,tonum,tobj,toyw,tosx,toyy);
				 printf("\t�ѳɹ��޸ġ�");
		    }
			else
			{
				fprintf(fpn,"%s %s %s %d %d %d\n",namecpy,num,bj,yw,sx,yy);
			}
		}
		fclose(fp);
		fclose(fpn);
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
	if( (fp = fopen(s,"r")) == NULL)   //���ļ���ͬ�� 
	{
		printf("Can't open the file.");
		exit(1);
	}
	while(!feof(fp)) {
		fscanf(fp,"%s %s %s %s %s %s\n",name,num,bj,yw,sx,yy);
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




void fhjsdl(){
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
			default:jsdl();break;
		}
	}
}



void fhxxdl(){
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
			case 9:jsdl();break; //��������
			case 0:return;       //�˳�ϵͳ
			default:xxdl();break;
		}
	}
}


void fhglydl(){
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




