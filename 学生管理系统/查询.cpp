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
		case 0:return 0;                         //�˳�ϵͳ
		default:jszjm();;break;
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
	printf("||          0----------�����꼶                   ||\n");                //��� 
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
		case 0:strcpy(sin,"allclass.txt");break;                        //�˳�ϵͳ
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
		printf("%s\n",yw);
	}
	fclose(fp);
	fclose(fpn);
	qjcx();
    }
}





