///******************** 13.1 使用标准IO********************/
//#include <stdio.h>
//#include <stdlib.h>
//
//int main(int argc,char *argv[])
//{
//	int ch;
//	FILE *fp;
//	unsigned long count = 0;
//	if(argc != 2)
//	{
//		printf("%s\n",argv[0]);
//		exit (EXIT_FAILURE);
//	}
//	if((fp = fopen(argv[1],"r")) == NULL)
//	{
//		printf("%s\n",argv[1]);
//		exit (EXIT_FAILURE);
//	}
//	while((ch = getc(fp)) != EOF)
//	{
//		putc(ch,stdout);
//		count++;
//	}
//	fclose(fp);
//	printf("%s %lu\n",argv[1],count);
//	return 0;
//}

/******************** 13.2 使用标准IO********************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#define LEN 40

int main(int argc,char *argv[])
{
	FILE *in,*out;
	int ch;
	char name[LEN];
	int count = 0;
	if(argc < 2)
	{
		fprintf(stderr,"%s\n",argv[0]);
		exit(EXIT_FAILURE);
	}
	if((in = fopen(argv[1],"r")) == NULL)
	{
		fprintf(stderr,"%s\n",argv[1]);
		exit (EXIT_FAILURE);
	}
	strncpy(name,argv[1],LEN - 5);
	name[LEN - 5] = '\0';
	strcat(name,".red");
	if((out = fopen(name,"w")) == NULL)
	{
		fprintf(stderr,("Cant \n"));
		exit(3);
	}
	while((ch = getc(in)) != EOF)
		if(count++ % 3 == 0)
			putc(ch,out);
	if(fclose(in) != 0 || fclose(out) != 0)
		fprintf(stderr,"ERROR\n");
	return 0;
}
