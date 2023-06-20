#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct book
{
    char bookName[50];
    char author[30];
    char isbnNo[13];
}bk;
struct student
{
    char nm[30];
    char bknm[50];
    char br[10];
    int rollNo;
    char date[8];
} stu;
void addbook()
{
   FILE *p=NULL;
   p=fopen("BookDetails.txt","a");
   printf("\nEnter details of the book to add :\n");
   printf("Name of the book : ");
   while(getchar()!='\n');
   scanf("%[^\n]s",bk.bookName);
   printf("Author Name : ");
   while(getchar()!='\n');
   scanf("%[^\n]s",bk.author);
   printf("ISBN No. : ");
   while(getchar()!='\n');
   scanf("%s",bk.isbnNo);
   fwrite(&bk,sizeof(bk),1,p);
   fclose(p);
}
void studentEntry()
{
   FILE *p=NULL;
   p=fopen("StudentDetails.txt","a");
   printf("\nEnter the details of the Student and book issued\n");
   printf("Name : ");
   while(getchar()!='\n');
   scanf("%[^\n]s",stu.nm);
   printf("Roll Number : ");
   fflush(stdin);
   scanf("%d",&stu.rollNo);
   printf("Book Issued : ");
   while(getchar()!='\n');
   scanf("%[^\n]s",stu.bknm);
   printf("Date Issued (in DDMMYYYY format) : ");
   while(getchar()!='\n');
   scanf("%[^\n]s",stu.date);
   fwrite(&stu,sizeof(struct student),1,p);
   fclose(p);
}
void display(int n)
{
    FILE *f;
    if(n==1)
    {
    f=fopen("BookDetails.txt","r");
    
    if(f==NULL)
    {
        printf("\nError! opening file.");
        exit(0);
    }
    else {
        int i=1;
        printf("\n\t\t**---BOOK LIST---**\n");
        printf("<--------------------------------------------->\n");
    while(fread(&bk,sizeof(bk),1,f)==1)
    {
        printf("\n%d) ",i++);
        printf("Title : %s\n",bk.bookName);
        printf(" Author : %s\n",bk.author);
        printf(" ISBN No. : %s\n",bk.isbnNo);
    }
    printf("\n<--------------------------------------------->\n");
    }
    fclose(f);
    }
    else{
        f=fopen("StudentDetails.txt","r");
        if(f==NULL)
    {
        printf("\nError! opening file");
    }
    else
    {
        int i=1;
    printf("\n\t**------BOOK ISSUE LIST------**");
    printf("\n<--------------------------------------------->\n");
    while(fread(&stu,sizeof(stu),1,f)==1)
    {
        printf("\n%d) ",i++);
        printf("Name of student : %s\n",stu.nm);
        printf(" Roll Number : %d\n",stu.rollNo);
        printf(" Book Name : %s\n",stu.bknm);
        printf(" Date Issued(DDMMYYYY) : ");
        for(int j=0;j<8;j++)
        {
            printf("%c",stu.date[j]);
            if(j==1||j==3)
            printf("-");
        }
        printf("\n");
    }
    printf("\n<--------------------------------------------->\n");
    }
    fclose(f);
}
}
void delete()
{   
    char name[50];
    int f=0;
    printf("\nEnter Book name to remove: ");
    while(getchar()!='\n');
    scanf("%[^\n]s",name);
    FILE *p1;
    FILE *p2;
    p1 = fopen("BookDetails.txt", "r");
    p2 = fopen("temp.txt", "w");

    while(fread(&bk, sizeof(bk), 1, p1)==1){
        if((strcasecmp(name,bk.bookName))==0){
            f=1;
        }else{
            fwrite(&bk,sizeof(bk), 1,p2);
        }
    }
    if(f==1){
        printf("\n\t\t***** DELETION SUCCESSFULL *****\n");
    }else{
        printf("\n\t\t!!! Record Not Found !!!\n");
    }
    fclose(p1);
    fclose(p2);
    remove("BookDetails.txt");
    rename("temp.txt", "BookDetails.txt");

}
void search()
{
    char name[30];
    printf("\nEnter a name to search---> ");
    while(getchar()!='\n');
   scanf("%[^\n]s",name);
    FILE *f;
    f=fopen("StudentDetails.txt","r");
    if(f==NULL)
    printf("\n!!ERROR OPENING FILE!!\n");
    else
    {
        int i=1;
        printf("\n\t\t***SEARCH RESULTS***");
        printf("\n<--------------------------------------------->\n");
       while(fread(&stu,sizeof(stu),1,f)==1)
       {
        if(strcasecmp(name,stu.nm)==0)
        {
            printf("\n%d) ",i++);
            printf("Name of student : %s\n",stu.nm);
            printf(" Roll Number : %d\n",stu.rollNo);
            printf(" Book Name : %s\n",stu.bknm);
            printf(" Date Issued(DD-MM-YYYY) : ");
            for(int j=0;j<8;j++)
            {
            printf("%c",stu.date[j]);
            if(j==1||j==3)
            printf("-");
            }
            printf("\n");
        }
       }
       if(i==1)
       printf("!!No record found!!\n"); 
       printf("\n<--------------------------------------------->\n"); 
    }
    fclose(f);
}
int main()
{
    int n=0;
    printf("\n*****ENTER THE NUMBERS FOR FOLLOWING TASKS AS PER NEED*****\n");
    while(n!=7)
    {
        printf("\n1. Add a book.\n");
        printf("2. Add the details of Student issuing book.\n");
        printf("3. Display Book record.\n");
        printf("4. Display Student record.\n");
        printf("5. Delete a Book.\n");
        printf("6. Search a Student in book issue list.\n");
        printf("7. To close the program.\n");
        printf("\nEnter your choice :------> ");
        scanf("%d",&n);
    switch(n)
    {
        
    case 1:
    addbook();  
    break;

    case 2:
    studentEntry();
    break;

    case 3:
    display(1);
    break;

    case 4:
    display(0);
    break;

    case 5:
    delete();
    break;

    case 6:
    search();
    break;

    case 7:
    printf("PROGRAM ENDS");
    break;

    default:
    printf("! ! Wrong choice. Enter again ! !\n");
    break;

    }
    }
    return 0;
}
