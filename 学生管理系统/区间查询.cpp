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




