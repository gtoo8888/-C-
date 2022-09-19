///******************** 11.1 显示磁盘上的数据文件********************/
////#include <stdio.h> 
////int main(void)
////{
////	FILE *fp;
////	int n,i = 0;
////	fp = fopen("C:\\Users\\HP\\Desktop\\练习\\1-C语言\\15-文件操作\\1.txt","r");
////	while(!feof(fp))
////	{
////		fscanf(fp,"%d",&n);
////		printf("%5d",n);
////		i++;
////		if(i == 10)
////		{
////			printf("\n");
////			i = 0;
////		}
////
////	}
////	fclose(fp);
////	return 0;
////}
//
///******************** 11.2 创建一个文本文件2.txt********************/
////#include <stdio.h> 
////#include <stdlib.h> 
////int main(void)
////{
////	FILE *fp;
////	int ch;
////	if(!(fp = fopen("C:\\Users\\HP\\Desktop\\练习\\1-C语言\\15-文件操作\\2.txt","w")))
////	{
////		printf("error");
////		exit(1);
////	}
////	ch = getchar();
////	while(ch != EOF)
////	{
////		fputc(ch,fp);
////		ch = getchar();
////	}
////	fclose(fp);
////	return 0;
////}
//
///******************** 11.3 将2.txt读取出来并显示********************/
////#include <stdio.h> 
////#include <stdlib.h> 
////int main(void)
////{
////	FILE *fp;
////	int ch;
////	if(!(fp = fopen("C:\\Users\\HP\\Desktop\\练习\\1-C语言\\15-文件操作\\2.txt","r")))
////	{
////		printf("error");
////		exit(1);
////	}
////	ch = fgetc(fp);
////	while(ch != EOF)
////	{
////		printf("%c",ch);
////		ch = fgetc(fp);
////	}
////	fclose(fp);
////	return 0;
////}
//
///******************** 11.3 将一个文件拷贝到另一个文件里面********************/
//#include <stdio.h> 
//#include <stdlib.h> 
//static void copyFile(FILE *scource,FILE *intention);
//static FILE *openFile(char *prompt,char *mode);
//int main(void)
//{
//	FILE *source,*intention;
//	source = openFile("source:","r");
//	intention = openFile("intention:","w");
//	copyFile(source,intention);
//	fclose(source);
//	fclose(intention);
//	return 0;
//}
//
//static void copyFile(FILE *source,FILE *intention)
//{
//	int ch;
//	while((ch = getc(source)) != EOF)
//		putc(ch,intention);
//}
//
//static FILE *openFile(char *prompt,char *mode)
//{
//	char tmpFile[20];
//	FILE *reval = NULL;
//	while(1){
//		printf("%s",prompt);
//		gets(tmpFile);
//		reval = fopen(tmpFile,mode);
//		if(reval != NULL)
//			break;
//		printf("cant open the file\"%s\"\n",tmpFile);
//		exit(1);
//	}
//	return reval;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//

