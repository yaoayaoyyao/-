void cjpx() {
	char subject[50];
	system("cls");		//���� 
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
	fp = fopen("�ɼ�����.txt", "w+");
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
	printf("||          0----------�����꼶                   ||\n");                //��� 
	printf(" ==================================================\n");
	printf("************************************************\nPlease Enter\n");
	int choice = 0, f = 1 , i, source;
	char num[50],name[50],bj[50],yw[50],sx[50],yy[50];
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
			case 0:strcpy(scj,"allclass.txt");break;                        //�˳�ϵͳ
			default:jszjm();break;
		}
		cjpx();
		FILE *fp;
	    fp = fopen("�ɼ�����.txt", "r");
	    while(!feof(fp)) {
	    	fscanf(fp,"%s %s %s %s %s %s %d %d\n", name, num, bj, yw, sx, yy, source, i);
	    	printf("%s %s %s %s %s %s %d %d\n", name, num, bj, yw, sx, yy, source, i);
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
