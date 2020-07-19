#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

int option;
int flag;
char back;
char stu_file[30];
char roll[30];
time_t t;



FILE *fptr;

struct Student
{
    char roll[30];
    char name[20];
    char major[15];
    char year[10];
    int age;
    char id[20];


}stu[6];



void menu(void);
void add_record(void);
void search_student(void);
void edit_record(void);
void erase_record(void);
void recent_action(void);

int main()
{
    time(&t);
    system("color B0");
    printf("\n\t\tYANGON UNIVERSITY OF DISTANCE EDUCATION");
    printf("\n\t\t=======================================");

    printf("\n\n[1]Search Student\t[2]Add Record\t[3]Edit Record\t[4]Erase Record\t[5]Recent Actions   [6]Exit Program");
    printf("\n============================================================================================================");

    menu();


    return main();
}

void menu()
{
    GO:
    printf("\nEnter Your Command :");
    scanf("%d",&option);

    switch(option)
    {
        case 1:search_student();break;
        case 2:add_record();break;
        case 3:edit_record();break;
        case 4:erase_record();break;
        case 5:recent_action();break;
        case 6:exit(0);
        default:
            printf("\n\aWrong Command !");
            goto GO;
    }

}

void add_record()
{
    printf("\n\tAdding Record ");
    printf("\n\t==============");

    GO:
    printf("\nEnter Student Roll Number :");
    fflush(stdin);
    gets(stu[0].roll);
    printf("\nEnter Student Name :");
    gets(stu[1].name);
    printf("\nEnter Specialized Major :");
    gets(stu[2].major);
    printf("\nEnter Current Year :");
    gets(stu[3].year);
    printf("\nEnter Student Age :");
    scanf("%d",&stu[4].age);
    printf("\nEnter Student NRC :");
    fflush(stdin);
    gets(stu[5].id);

    strcpy(stu_file,stu[0].roll);
    strcat(stu_file,".txt");

    fptr=fopen(stu_file,"w");
    if(fptr==0)
    {
        printf("\nRecreating the file .........");
        fptr=fopen(stu_file,"a");
    }
    fwrite(&stu,sizeof(stu),1,fptr);
    fclose(fptr);
    printf("\nAdded Successfully.......");

    fptr=fopen("Recent_Action.txt","a");
    if(fptr==0)
    {
        printf("\nRecreating the file ......");
        fptr=fopen("Recent_Action.txt","a");
    }
    fprintf(fptr,"A new student named %s is added  at %s",stu[1].name,ctime(&t));
    fclose(fptr);

    printf("\nOne More (Y/N) :");
    back=getch();
    if(toupper(back)=='Y')
        goto GO;


}

void search_student()
{
    printf("\n\tSearching Student Information");
    printf("\n\t=============================");

    GO:
    printf("\nEnter Roll Number to search :");
    fflush(stdin);
    gets(roll);
    strcpy(stu_file,roll);
    strcat(stu_file,".txt");
    fptr=fopen(stu_file,"r");
    if(fptr==0)
    {
        printf("\nRecreating the file .......");
        fptr=fopen(stu_file,"r");
    }

    while(fread(&stu,sizeof(stu),1,fptr))
    {
        if(strcmp(roll,stu[0].roll)==0)
        {
            printf("\nStudent Roll Number :%s",stu[0].roll);
            printf("\nStudent Name :%s",stu[1].name);
            printf("\nSpecialized Major :%s",stu[2].major);
            printf("\nCurrent Year :%s",stu[3].year);
            printf("\nStudent Age :%d",stu[4].age);
            printf("\nStudent NRC :%s",stu[5].id);
            flag=0;
            break;
        }
    }
    fclose(fptr);

    if(flag)
        printf("\n\aThis student data is not available !");

    fptr=fopen("Recent_Action.txt","a");
    if(fptr==0)
    {
        printf("\nRecreating the file ......");
        fptr=fopen("Recent_Action.txt","a");
    }
    fprintf(fptr," Roll Number %s was searched at %s",stu[0].roll,ctime(&t));
    fclose(fptr);

    printf("\nOne More (Y/N) :");
    back=getch();
    if(toupper(back)=='Y')
        goto GO;


}

void edit_record()
{
    printf("\n\tEditing Record");
    printf("\n\t==============");

    char name[20];
    char major[15];
    char year[10];
    int age;
    char id[20];

    GO:
    printf("\nEnter Student Roll Number :");
    fflush(stdin);
    gets(roll);

    printf("\n(1)Student Name");
    printf("\n(2)Specialized Major");
    printf("\n(3)Current Year");
    printf("\n(4)Student Age");
    printf("\n(5)Student NRC");
    BACK:
    printf("\nChoose the one you want to edit :");
    scanf("%d",&option);

    strcpy(stu_file,roll);
    strcat(stu_file,".txt");
    fptr=fopen(stu_file,"r+");
    if(fptr==0)
    {
        printf("\nRecreating the file .....");
        fptr=fopen(stu_file,"r+");
    }

    switch(option)
    {
    case 1:
        while(fread(&stu,sizeof(stu),1,fptr))
        {
            printf("\nOld Student Name :%s",stu[1].name);
            printf("\nEnter New Student Name :");
            fflush(stdin);
            gets(name);
            strcpy(stu[1].name,name);
            fseek(fptr,0,SEEK_CUR);
            fptr=fopen(stu_file,"w");
            fwrite(&stu,sizeof(stu),1,fptr);
            if(fptr==0)
                printf("\nFile Error !");
            else
                printf("\nEdited Successfully !");
            break;
        }
        fclose(fptr);
        break;
    case 2:
        while(fread(&stu,sizeof(stu),1,fptr))
        {
            printf("\nOld Specialized Major :%s",stu[2].major);
            printf("\nEnter New Specialized Major :");
            fflush(stdin);
            gets(major);
            strcpy(stu[2].major,major);
            fseek(fptr,0,SEEK_CUR);
            fptr=fopen(stu_file,"w");
            fwrite(&stu,sizeof(stu),1,fptr);
            if(fptr==0)
                printf("\nFile Error !");
            else
                printf("\nEdited Successfully !");
            break;
        }
        fclose(fptr);
        break;
    case 3:
        while(fread(&stu,sizeof(stu),1,fptr))
        {
            printf("\nOld Current Year :%s",stu[3].year);
            printf("\nEnter New Current Year :");
            fflush(stdin);
            gets(year);
            strcpy(stu[3].year,year);
            fseek(fptr,0,SEEK_CUR);
            fptr=fopen(stu_file,"w");
            fwrite(&stu,sizeof(stu),1,fptr);
            if(fptr==0)
                printf("\nFile Error !");
            else
                printf("\nEdited Successfully !");
            break;
        }
        fclose(fptr);
        break;
    case 4:
        while(fread(&stu,sizeof(stu),1,fptr))
        {
            printf("\nOld Student Age :%d",stu[4].age);
            printf("\nEnter New Student Age :");
            scanf("%d",&age);
            stu[4].age=age;
            fseek(fptr,0,SEEK_CUR);
            fptr=fopen(stu_file,"w");
            fwrite(&stu,sizeof(stu),1,fptr);
            if(fptr==0)
                printf("\nFile Error !");
            else
                printf("\nEdited Successfully !");
            break;
        }
        fclose(fptr);
        break;
    case 5:
        while(fread(&stu,sizeof(stu),1,fptr))
        {
            printf("\nOld Student NRC :%s",stu[5].id);
            printf("\nEnter New Student NRC :");
            fflush(stdin);
            gets(id);
            strcpy(stu[5].id,id);
            fseek(fptr,0,SEEK_CUR);
            fptr=fopen(stu_file,"w");
            fwrite(&stu,sizeof(stu),1,fptr);
            if(fptr==0)
                printf("\nFile Error !");
            else
                printf("\nEdited Successfully !");
            break;
        }
        fclose(fptr);
        break;

    default :
        printf("\n\aWrong Command !");
        goto BACK;

    }



    fptr=fopen("Recent_Action.txt","a");
    if(fptr==0)
    {
        printf("\nRecreating the file ......");
        fptr=fopen("Recent_Action.txt","a");
    }
    switch(option)
    {
    case 1:
        fprintf(fptr,"'%s' was edited at %s",stu[1].name,ctime(&t));
        break;
    case 2:
        fprintf(fptr,"'%s' was edited at %s",stu[2].major,ctime(&t));
        break;
    case 3:
        fprintf(fptr,"'%s' was edited at %s",stu[3].year,ctime(&t));
        break;
    case 4:
        fprintf(fptr,"'%d' was edited at %s",stu[4].age,ctime(&t));
        break;
    case 5:
        fprintf(fptr,"'%s' was edited at %s",stu[5].id,ctime(&t));
        break;
    }
    fclose(fptr);


    printf("\nOne More (Y/N) :");
    back=getch();
    if(toupper(back)=='Y')
        goto GO;

}

void erase_record()
{
    GO:
    printf("\nEnter Roll Number to erase :");
    fflush(stdin);
    gets(roll);
    strcpy(stu_file,roll);
    strcat(stu_file,".txt");
    fptr=fopen(stu_file,"w");
    if(fptr==0)
        printf("\nFile Error !");

    remove(stu_file);
    printf("\nErased Successfully !");
    fclose(fptr);

    fptr=fopen("Recent_Action.txt","a");
    if(fptr==0)
    {
        printf("\nRecreating the file ......");
        fptr=fopen("Recent_Action.txt","a");
    }
    fprintf(fptr,"%s was erased at %s",stu_file,ctime(&t));
    fclose(fptr);

    printf("\nOne More (Y/N) :");
    back=getch();
    if(toupper(back)=='Y')
        goto GO;


}

void recent_action()
{
    char read[100];
    fptr=fopen("Recent_Action.txt","r");
    if(fptr==0)
    {
        printf("\nRecreating the file ......");
        fptr=fopen("Recent_Action.txt","r");
    }
    while(!feof(fptr))
    {
        fgets(read,100,fptr);
        printf("\n%s",read);
    }
    fclose(fptr);

}
















