
#include <stdio.h>
//#include <stdlib.h>
#include <windows.h>
#include <string.h>

void gotoxy(int column, int line);


struct Teacher
{
    int sap;
    int exp;
    char name[20];
    char desg[30];
    char subject[3][5];
    int clas[3];
    int lab;
    int hours;
    int rank;
    int classs;
    char branch[10][5];
    char subjecta[10][5];

};
struct Subject
{
    char sname[5];
    char scode[7];
    int credits;
};
struct Branch
{
    char name[5];
    int sub;
    char teacher[5][20];
    char subject[5][5];
};
const char* getfield(char* line, int num)
{
    const char* tok;
    for (tok = strtok(line, ",");
            tok && *tok;
            tok = strtok(NULL, ",\n"))
    {
        if (!--num)
            return tok;
    }
    return NULL;
}
COORD coord = { 0, 0 };
void gotoxy(int x, int y) {
    coord.X = x; coord.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main()
{
    system("color b9");
    int c,f,i,no,rank,lab,classs,j,a,sap,h,s,b,k,l,credit,p,rslt,q,e,m,z,id,pass,x,kl;
    char sub[5],code[10],buffer[1024],line2[1024],*token,ch,cmp,*record,line1[1024],line3[1024],line4[1024],*line5;
    FILE *fp,*fc;
    struct Subject subj[5];
    struct Teacher tf[30];
    struct Branch tb[10];

    do{
            system("cls");
    printf("\n\n\n\t\t\t\t\t  THE TIMETABLE MANAGEMENT SYSTEM  \n\n\n\n");
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("              1. Administrator                      2. Student                           3. Teacher");
    printf("\n------------------------------------------------------------------------------------------------------------------------\n");
    printf("\n\n Enter Choice :");
    scanf("%d",&z);
    system("cls");
    if(z==1){


                    system("cls");
             printf("------------------------------------------------------------------------------------------------------------------------\n");
           printf("1.New Faculty   2. Search Faculty   3.Enter Subjects   4. Enter Branches   5.Student Time Table   6.Faculty Time Table  7.EXIT \n------------------------------------------------------------------------------------------------------------------------\n\nEnter Choice: ");
            }
    else if(z==2){
            printf("------------------------------------------------------------------------------------------------------------------------\n");
            printf("\t\t\t5.Display Time Table\t\t\t\t \t7.EXIT \n------------------------------------------------------------------------------------------------------------------------\n\nEnter Choice: ");
    }
    else if(z==3){
            printf("------------------------------------------------------------------------------------------------------------------------\n");
            printf(" \t\t\t6.Display Time Table\t\t\t \t7.EXIT \n------------------------------------------------------------------------------------------------------------------------\n\nEnter Choice: ");
    }
    scanf("%d",&c);
    switch(c)
    {
    case 1:
    {
        system("cls");
        printf("\n---------------------------------------------------\nEnter the Number of faculties you want to enter : ");
    //printf("\n---------------------------------------------------");
    scanf("%d",&f);
    printf("---------------------------------------------------");
        struct Teacher s[f],temp;
        for(i=0; i<f; i++)
        {
             printf("\n\nFor Faculty %d \n\n\nEnter the details below : \n",i);
            printf("\n\n\t\tEnter the name : ");
            scanf("%s",s[i].name);
            printf("\n\n\t\tEnter the Sapid: ");
            scanf("%d",&s[i].sap);
            system("CLS");
            printf("\t\t\n-------------------------------------------\n\tPlease choose the designation : \n-------------------------------------------\n");
            printf("\n\n\t\t1.Assistant Professor \n\n\n\t\t2.AP(SS) \n\n\n\t\t3.AP(SG)  \n\n\n\t\t4.Associate Professor  \n\n\n\t\t5. Professor\n\nSelect Choice: ");
            scanf("%d",&no);
            switch(no)
            {
            case 1:
            {
                strcpy(s[i].desg," Assistant Professor");
                s[i].rank=0;
                s[i].hours=16;
                s[i].lab=2;
                s[i].classs = s[i].hours-(2*s[i].lab);
                break;
            }
            case 2:
            {
                strcpy(s[i].desg," AP(SS)");
                s[i].hours=13;
                s[i].rank=1;
                s[i].lab=2;
                s[i].classs=s[i].hours-(2*s[i].lab);
                break;
            }
            case 3:
            {
                strcpy(s[i].desg," AP(SG)");
                s[i].hours=10;
                s[i].rank=2;
                s[i].lab=2;
                s[i].classs=s[i].hours-(2*s[i].lab);
                break;
            }
            case 4:
            {
                strcpy(s[i].desg," Associate Professor");
                s[i].hours=7;
                s[i].rank=3;
                s[i].lab=2;
                s[i].classs=s[i].hours-(2*s[i].lab);
                break;
            }
            case 5:
            {
                strcpy(s[i].desg,"  Professor");
                s[i].hours=3;
                s[i].rank=4;
                s[i].lab=0;
                s[i].classs=s[i].hours-(2*s[i].lab);
                break;
            }
            default:
            {
                printf("Please be Realistic \n");
            }
            }
            system("CLS");
            printf("\n------------------------------------------------\nEnter the no. of years of experience you have: ");
            scanf("%d",&s[i].exp);
            printf("------------------------------------------------");
            printf("\n\n\nPlease choose the subjects according to priority : \n");
            printf("\n\t\t\t\tOnly three Priorities allowed\n\n ");
            fp=fopen("subjects.csv","r+");
            if(fp==NULL)
                exit(1);
            k=0;
            while (fgets(line1, 1024, fp))
            {
                char* tmp = strdup(line1);
                printf("\t\t\t\t Subject : %s\n", getfield(tmp, 1));
                printf("\n\t\t\t\tYou want to choose this subject ? \n\n\t\t\t\tpress 1 to choose or 0 to pass: ");
                scanf("%d",&l);
                printf("\n");
                if(l==1)
                {
                    strcpy(s[i].subject[k],getfield(tmp,1));
                    k = k+1;
                }
                free(tmp);
            }
            for(j=0; j<3; j++)
            {
                printf("\n\n\t\t\t\t%d-%s",j,s[i].subject[j]);

            }
            system("cls");
            printf("---------------------\n");
            printf("Information Entered :\n");
            printf("---------------------\n");
            printf("\t\t\tName: %s\n",s[i].name);
            printf(" \n\t\t\tSap: %d\n",s[i].sap);
            printf("\n\t\t\tDesignation :%s \n",s[i].desg);
        }
        for(i = 0; i < f; i++)
        {
            for(j = 0; j < (f - i - 1); j++)
            {
                if(s[j].rank<s[j+1].rank)
                {
                    temp=s[j];
                    s[j]=s[j+1];
                    s[j+1]=temp;
                }
                else if(s[j].rank==s[j+1].rank)
                {
                    if(s[j].exp<s[j+1].exp)
                    {
                        temp=s[j];
                        s[j]=s[j+1];
                        s[j+1]=temp;
                    }
                }

            }
        }
        fp=fopen("details.csv","a+");
        p=0;
        for(i=0; i<f; i++)
        {
            fprintf(fp,"%d,%s,%s,%d,%d,%d,%s,%s,%s\n ",s[i].sap,s[i].name,s[i].desg,s[i].hours,s[i].classs,s[i].lab,s[i].subject[p],s[i].subject[p+1],s[i].subject[p+2]);

        }
        fclose(fp);
        break;
    }
    case 2:
    {
        system("cls");
        printf("-----------------\n");
        printf("Enter the sap id: ");
        scanf("%d",&sap);
        printf("\n-----------------\n\n");
        fp=fopen("details.csv","r");
        while (fgets(line3, 1024, fp))
        {
            char* tmp = strdup(line3);
            rslt=atoi(getfield(tmp,1));
            if(sap == rslt)
            {
                printf("%s\n",line3);
            }
            else
            free(tmp);
        }
        fclose(fp);
        break;
    }
    case 3:
    {
        system("cls");
        printf("---------------------------------------------------");
        printf("\nEnter The number of subjects you want to enter\t:");
        scanf("%d",&s);
        struct Subject sub[s];
        system("cls");
        for(i=0; i<s; i++)
        {
            printf("\n\nEnter Details for %d subject: ",i);
            printf("\n\n\n\t\t Enter the Name of Subject : ");
            scanf("%s",sub[i].sname);
            printf("\n\n\t\t Enter the Subject Code:");
            scanf("%s",sub[i].scode);
            printf("\n\n\t\t Enter the number of credits:");
            scanf("%d",&sub[i].credits);
            system("cls");
            printf("\n\n---------------------\n");
            printf("Information Entered:\n");
            printf("---------------------");
            printf("\n\n\t\t\tName : %s\n\n\t\t\tSubject Code : %s\n\n\t\t\tCredits :%d\n ",sub[i].sname,sub[i].scode,sub[i].credits);
            fp=fopen("subjects.csv","a+");
            fprintf(fp,"%s,%s,%d\n",sub[i].sname,sub[i].scode,sub[i].credits);
            fclose(fp);
        }
        break;

    }
    case 4:
    {
        system("cls");
        printf("\n----------------------------------------\n");
        printf("Enter The number of branches you want:");
        scanf("%d",&b);
        printf("----------------------------------------");
        struct Branch br[b];
        for(i=0; i<b; i++)
        {
            q=0;
           // printf("\n---------------------------");
            printf("\n\nEnter the name of Branch :");
            scanf("%s",br[i].name);
            fp=fopen("subjects.csv","r");

            while (fgets(line4, 1024, fp))
            {
                char* tmp = strdup(line4);
                strcpy(br[i].subject[q],getfield(tmp,1));
                q=q+1;
                free(tmp);
            }
            fclose(fp);
            for(j=0; j<5; j++)
            {
                printf("\t\t Branch : %d Subject :%s\n",i,br[i].subject[j]);
            }
            e=0;
            fp=fopen("branches.csv","a+");
            for(j=0; j<2; j++)
            {
                fprintf(fp,"%s,%s,%s,%s,%s,%s\n",br[j].name,br[j].subject[e],br[j].subject[e+1],br[j].subject[e+2],br[j].subject[e+3],br[j].subject[e+4]);
            }
            fclose(fp);


        }
        break;
    }
    case 5:
    {
        for(i=0;i<30;i++){
            for(j=0;j<10;j++){
                strcpy(tf[i].subjecta[j],"null");
                strcpy(tf[i].branch[j],"null");
                //printf("%s %s",tf[i].subjecta[j],tf[i].branch[j]);
            }
        }
        fc=fopen("branches.csv","r");
        i=0;
        j=0;
        while((line5=fgets(buffer,sizeof(buffer),fc))!=NULL)
        {
            record = strtok(line5,",");
            j=0;
            while(record != NULL)
            {
                if(j==0)
                {
                    strcpy(tb[i].name,record);
                }
                else if(j==1)
                {
                    strcpy(tb[i].subject[0],record);
                }
                else if(j==2)
                {
                    strcpy(tb[i].subject[1],record);
                }
                else if(j==3)
                {
                    strcpy(tb[i].subject[2],record);
                }
                else if(j==4)
                {
                    strcpy(tb[i].subject[3],record);
                }
                else if(j==5)
                {
                    strcpy(tb[i].subject[4],record);
                }
                record = strtok(NULL,",");
                j++;

            }
            i++;

        }
        fclose(fc);
        fc=fopen("details.csv","r");
        i=0;
        j=0;
        while((line5=fgets(buffer,sizeof(buffer),fc))!=NULL)
        {
            record = strtok(line5,",");
            j=0;
            while(record != NULL)
            {
                if(j==0)
                {
                    tf[i].sap=atoi(record);
                }
                else if(j==1)
                {
                    strcpy(tf[i].name,record);
                }
                else if(j==2)
                {
                    strcpy(tf[i].desg,record);
                }
                else if(j==3)
                {
                    tf[i].hours=atoi(record);
                }
                else if(j==4)
                {
                    tf[i].classs=atoi(record);
                }
                else if(j==5)
                {
                    tf[i].lab=atoi(record);
                }
                else if(j==6)
                {
                    strcpy(tf[i].subject[0],record);
                }
                else if(j==7)
                {
                    strcpy(tf[i].subject[1],record);
                }
                else if(j==8)
                {
                    strcpy(tf[i].subject[2],record);
                }
                record = strtok(NULL,",");
                j++;

            }
            i++;

        }
        system("cls");
        fclose(fc);
        printf("Choose the branch : ");
        for(j=0;j<10;j++){
            printf(" %d.%s\t",j+1,tb[j].name);
        }
        scanf("%d",&i);
        i=i-1;
        //for(i=0; i<10; i++)
        //{
            printf("\n\n                           BTECH COMPUTER SCIENCE WITH SPECIALIZATION IN  %s                   \n",tb[i].name);
            printf("\n----------------------------------------------------------------------------------------------------------------------");
            printf("\n        |  S No.  |  Semester  |   Name of Subject  |   Number of Credits  |  Faculty Assigned   |\n");
            printf("----------------------------------------------------------------------------------------------------------------------\n");
            for(j=0; j<5; j++)
            {
                for(m=0; m<3; m++)
                {
                    for(l=0; l<30; l++)
                    {  if(tf[l].classs>0)
                        {
                            if(strcmp(tb[i].subject[j],tf[l].subject[m])==0)
                            {

                                strcpy(tb[i].teacher[j],tf[l].name);
                                strcpy(tf[l].subjecta[i],tb[i].subject[j]);
                                strcpy(tf[l].branch[i],tb[i].name);
                                tf[l].classs=tf[l].classs-3;

                                break;
                                //printf("Load :%d  - %s\n",tf[l].classs,tf[l].name);
                            }

                        }
                        else
                        {
                            continue;
                        }
                    }

                }
               // system("cls");
                printf("        |   %d     |     5      |      %s          |          3           |         %s   |\n\n",j+1,tb[i].subject[j],tb[i].teacher[j]);

            }
            printf("----------------------------------------------------------------------------------------------------------------------");
       //}



        break;

    }
    case 6:
        {
            {
        for(i=0;i<30;i++){
            for(j=0;j<10;j++){
                strcpy(tf[i].subjecta[j],"null");
                strcpy(tf[i].branch[j],"null");
                //printf("%s %s",tf[i].subjecta[j],tf[i].branch[j]);
            }
        }
        fc=fopen("branches.csv","r");
        i=0;
        j=0;
        while((line5=fgets(buffer,sizeof(buffer),fc))!=NULL)
        {
            record = strtok(line5,",");
            j=0;
            while(record != NULL)
            {
                if(j==0)
                {
                    strcpy(tb[i].name,record);
                }
                else if(j==1)
                {
                    strcpy(tb[i].subject[0],record);
                }
                else if(j==2)
                {
                    strcpy(tb[i].subject[1],record);
                }
                else if(j==3)
                {
                    strcpy(tb[i].subject[2],record);
                }
                else if(j==4)
                {
                    strcpy(tb[i].subject[3],record);
                }
                else if(j==5)
                {
                    strcpy(tb[i].subject[4],record);
                }
                record = strtok(NULL,",");
                j++;

            }
            i++;

        }
        fclose(fc);
        fc=fopen("details.csv","r");
        i=0;
        j=0;
        while((line5=fgets(buffer,sizeof(buffer),fc))!=NULL)
        {
            record = strtok(line5,",");
            j=0;
            while(record != NULL)
            {
                if(j==0)
                {
                    tf[i].sap=atoi(record);
                }
                else if(j==1)
                {
                    strcpy(tf[i].name,record);
                }
                else if(j==2)
                {
                    strcpy(tf[i].desg,record);
                }
                else if(j==3)
                {
                    tf[i].hours=atoi(record);
                }
                else if(j==4)
                {
                    tf[i].classs=atoi(record);
                }
                else if(j==5)
                {
                    tf[i].lab=atoi(record);
                }
                else if(j==6)
                {
                    strcpy(tf[i].subject[0],record);
                }
                else if(j==7)
                {
                    strcpy(tf[i].subject[1],record);
                }
                else if(j==8)
                {
                    strcpy(tf[i].subject[2],record);
                }
                record = strtok(NULL,",");
                j++;

            }
            i++;

        }
        fclose(fc);
        for(i=0; i<10; i++)
        {
            //printf("\n\n-------------------------Btech Compter Science Engineering With Specialisation in  %s--------------------------------- \n",tb[i].name);
            for(j=0; j<5; j++)
            {
                for(m=0; m<3; m++)
                {
                    for(l=0; l<30; l++)
                    {  if(tf[l].classs>0)
                        {
                            if(strcmp(tb[i].subject[j],tf[l].subject[m])==0)
                            {

                                strcpy(tb[i].teacher[j],tf[l].name);
                                strcpy(tf[l].subjecta[i],tb[i].subject[j]);
                                strcpy(tf[l].branch[i],tb[i].name);
                                tf[l].classs=tf[l].classs-3;

                                break;
                                //printf("Load :%d  - %s\n",tf[l].classs,tf[l].name);
                            }

                        }
                        else
                        {
                            continue;
                        }
                    }

                }
               // system("cls");
               // printf("\n\n\t\t\t\t\t\t%s : %s\n",tb[i].subject[j],tb[i].teacher[j]);

            }
        }
        system("cls");
        printf("\n------------------------------------------------------------------------------------------------------------------------\n");
        printf(" S.no |      Name         |      SapId     |       Designation        | Branch : Subject |");
        printf("\n------------------------------------------------------------------------------------------------------------------------");
        for(i=00;i<30;i++){
            printf("\n\n %d    |     %s    |      %d     |    %s  | ",i+1,tf[i].name,tf[i].sap,tf[i].desg);
            for(k=0;k<10;k++){
                    if(strcmp(tf[i].branch[k],"null")==0&&strcmp(tf[i].subjecta[k],"null")==0){continue;}
                    else{
            printf("%s : %s | ",tf[i].branch[k],tf[i].subjecta[k]);}

            }
        }


        break;
    }

        }
    case 7:
    {
        exit(0);
    }



    }
    printf("\n\nEnter 1 to Continue  & 0 to exit.");
    scanf("%d",&kl);if(kl==0){exit(1);}

    }while(kl==1);

    return 0;
}
