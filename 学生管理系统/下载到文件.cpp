#include <stdio.h>
int main()
{
   FILE *fp = NULL, *out = NULL;
   int ch;
   out = fopen("out.txt","w");
   fp = fopen("class1.txt", "r");
   ch=fgetc(fp); //从fp所指文件的当前指针位置读取一个字符
    while(ch!=EOF) //判断刚读取的字符是否是文件结束符
    {
    	fputc(ch,out); //若不是结束符，将它写入out所指文件
        ch=fgetc(fp); //继续从fp所指文件中读取下一个字符
    } //完成将fp所指文件的内容输出到屏幕上显示
   fclose(fp);
   fclose(out);
}
