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
