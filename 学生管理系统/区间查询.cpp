/*
区间查询 
*/
void qjcx()
{
    FILE *fpn,*fp;
	char name[50],toname[50];
	char num[50],bj[50],yw[50],sx[50],yy[50];
	int f = 0;
	if((fpn = fopen("区间查询.txt","r")) == NULL || (fp = fopen("cx.txt","w+")) == NULL)   //打开文件，同上 
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
		printf("\n\tplease input the 符号:\n");
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
					remove("区间查询.txt");	//删除原文件
		            rename("cx.txt", "区间查询.txt");	//重命名新文件
					printf("\n");
	        		printf("\t ==================================================\n");
		    		printf("\t||          8----------输出结果                   ||\n");
		    		printf("\t||          9----------继续选择区间               ||\n");                //完成 
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
		        		scjg();
    	    		}
	        		else {
	        		system("cls");		//清屏 
	            		switch(choice) {
		    	    		case 8:scjg();break;//返回上一层
		    	    		case 9:qjcx();break;//返回上一层
		    	    		case 0:return;     //退出系统
		    	    		default:scjg();break;
		        		}
	        		}	
				} 
			}
		}
	} 
}




