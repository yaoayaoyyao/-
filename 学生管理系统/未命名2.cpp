#include<stdio.h>
#include<string.h>
int main() {
	char s[20];
	FILE *fp;
	int yw,sx,yy,num,choice;
	scanf("%d",&choice);
	if(choice == 1) {
		strcpy(s,"class1.txt");
	}
	if( (fp = fopen(s,"r")) == NULL)   //���ļ���ͬ��
	{
		printf("Can't open the file.");
		return 0;//exit(1);
	}
	else
	{	
		while(!feof(fp))
		{
			char namecpy[20], bj[20];
		    fscanf(fp, "%s",namecpy);
			if(fscanf(fp,"%d",&num)==-1)  //�ж�num���Ƿ���Ա����� 
				break;
			fscanf(fp, "%s", bj);
			fscanf(fp, "%d %d %d",&yw,&sx,&yy);
			printf("\t   %d        %s        %s     %d       %d     %d\n", num, namecpy, bj, yw, sx, yy);
		}
		fclose(fp);
	}
}
