#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
void newf();
void view();
void saveas();
void modify();
void main()
{
int op;
do
{
printf("\nMENU\n");
printf("1.New\n");
printf("2.Open\n");
printf("3.Save As\n");
printf("4.Modify\n");
printf("5.Exit\n");
printf("Enter u'r choice: ");
scanf("%d",&op);
switch(op)
{
case 1:

newf();
break;
case 2:
view();
break;
case 3:
saveas();
break;
case 4:
modify();
break;
case 5:
exit(0);
default:
printf("\nWrong choice!!!");
break;
}
}while(op!=5);
}
void newf()
{
FILE *f;
char fname[20],c;
printf("\nEnter the Filename: ");
scanf("%s",fname);
printf("\nType the content and CTRL+Z to terminate:\n");
f=fopen(fname,"w");
rewind(f);
while((c=getchar())!=EOF)
{
putc(c,f);
}
fclose(f);
}
void view()
{
FILE *f;
char fname[20],c;
printf("\nEnter the name of the file:");
scanf("%s",&fname);
if(SearchPath(fname))
{
f=fopen(fname,"r");
while((c=getc(f))!=EOF)
{
printf("%c",c);
}
}
else
printf("\nThe file %s does not exist",fname);
fclose(f);

}
void saveas()
{
FILE *f1,*f2;
char c,sou[20],des[20];
printf("\nEnter the Source file name: ");
scanf("%s",sou);
if(SearchPath(sou))
{
printf("Enter the Destination file name: ");
scanf("%s",des);
f1=fopen(sou,"r");
f2=fopen(des,"w");
while((c=getc(f1))!=EOF)
{
putc(c,f2);
}
fclose(f1);
fclose(f2);
}
else
printf("\nFile does not exist");
getch();
}
void modify()
{
int ch1;
FILE *f1;
char c,*word,*sent,fname[20];
printf("Enter the filename to be modified: ");
scanf("%s",fname);
if(SearchPath(fname))
{
printf("\n1.Character");
printf("\n2.Word");
printf("\n3.Sentence");
printf("\nEnter U'r choice: ");
scanf("%d",&ch1);
if(ch1==1)
{
f1=fopen(fname,"a+");
fseek(f1, 0L, SEEK_END);
printf("Enter the character and CTRL+Z to exit:\n ");
while((c=getchar())!=EOF)
{
putc(c,f1);
}
}
else if(ch1==2)
{
printf("Enter the word: ");

scanf("%s",word);
f1=fopen(fname,"a+");
fseek(f1, 0L, SEEK_END);
fputs(word,f1);
}
else
{
printf("Enter the sentence and CTRL+Z to exit: ");
f1=fopen(fname,"a+");
fseek(f1, 0L, SEEK_END);
while((c=getchar())!=EOF)
{
putc(c,f1);
}
}
}
else
printf("\nFilename does not exist");
}