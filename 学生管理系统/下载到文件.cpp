#include <stdio.h>
int main()
{
   FILE *fp = NULL, *out = NULL;
   int ch;
   out = fopen("out.txt","w");
   fp = fopen("class1.txt", "r");
   ch=fgetc(fp); //��fp��ָ�ļ��ĵ�ǰָ��λ�ö�ȡһ���ַ�
    while(ch!=EOF) //�жϸն�ȡ���ַ��Ƿ����ļ�������
    {
    	fputc(ch,out); //�����ǽ�����������д��out��ָ�ļ�
        ch=fgetc(fp); //������fp��ָ�ļ��ж�ȡ��һ���ַ�
    } //��ɽ�fp��ָ�ļ��������������Ļ����ʾ
   fclose(fp);
   fclose(out);
}
