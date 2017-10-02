#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

struct Teacher{
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
  };
  struct Subject{
  char sname[5];
  char scode[7];
  int credits;
  };
  struct Branch{
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

int main()
{
    system("color e4");
    int c,f,i,no,rank,lab,classs,j,a,sap,h,s,b,k,l,credit,p,rslt,q,e,m;
    char sub[5],code[10],buffer[1024],line2[1024],*token,ch,cmp,*record,*line;
    FILE *fp,*fc;
    struct Subject subj[5];
    struct Teacher tf[2];
    struct Branch tb[2];
    A:{
    system("cls");
    printf("\n\n\n\n\n\t\t\t\t\t Welcome To Time Table Management System  \n");
    printf("1.New Faculty\t 2. Search Faculty \t3.Enter Subjects\t 4. Enter Branches \t 5.Display Time Table \t6.EXIT \n");
    scanf("%d",&c);
    switch(c){
case 1:{
    system("cls");
    printf("\t\t\t\t\t Enter the Number of faculties you want to enter :\n");
    scanf("%d",&f);
    struct Teacher s[f],temp;
    for(i=0;i<f;i++){
            printf("\t\t\t\tFor Faculty %d , Enter the details below : \n",i);
            printf("\t\t\t\tEnter the name :");
            scanf("%s",s[i].name);
            printf("\t\t\t\tEnter the Sapid: \n");
            scanf("%d",&s[i].sap);
            printf("\t\t\tPlease choose the designation : \n");
            printf("\t\t\t\t 1.Assistant Professor\n \t\t\t2.AP(SS)\n \t\t\t3.AP(SG) \n \t\t\t4.Associate Professor \n \t\t\t5. Professor\n");
            scanf("%d",&no);
            switch(no){
        case 1:
            {strcpy(s[i].desg," Assistant Professor");
            s[i].rank=0;
            s[i].hours=16;
            s[i].lab=2;
            s[i].classs = s[i].hours-(2*s[i].lab);
            break;
            }
        case 2:
            {strcpy(s[i].desg," AP(SS)");
            s[i].hours=13;
            s[i].rank=1;
            s[i].lab=2;
            s[i].classs=s[i].hours-(2*s[i].lab);
            break;}
        case 3:
            {strcpy(s[i].desg," AP(SG)");
            s[i].hours=10;
            s[i].rank=2;
            s[i].lab=2;
            s[i].classs=s[i].hours-(2*s[i].lab);
            break;}
        case 4:
            {strcpy(s[i].desg," Associate Professor");
            s[i].hours=7;
            s[i].rank=3;
            s[i].lab=2;
            s[i].classs=s[i].hours-(2*s[i].lab);
            break;}
        case 5:
            {strcpy(s[i].desg,"  Professor");
            s[i].hours=3;
            s[i].rank=4;
            s[i].lab=0;
            s[i].classs=s[i].hours-(2*s[i].lab);
            break;}
        default:{
            printf("Please be Realistic \n");
            }}
            printf("\t\t\tEnter the no. of years of experience you have: \n");
            scanf("%d",&s[i].exp);
            printf("\t\t Please choose the subjects according to priority : \n");
            printf("\t\t Only three Priorities allowed. Press one if you want to choose desired Subject: \n");
                fp=fopen("subjects.csv","r+");
            k=0;
                while (fgets(line, 1024, fp))
    {
        char* tmp = strdup(line);
        printf("\t\t Subject : %s\n", getfield(tmp, 1));
        printf("\t\tYou want to choose this subject ? press 1 to choose or 0 to pass: \n ");
                scanf("%d",&l);
                if(l==1){
                    strcpy(s[i].subject[k],getfield(tmp,1));
                    k = k+1;
                }
        free(tmp);
    }
        for(j=0;j<3;j++){
            printf("\n\t\t%d-%s",j,s[i].subject[j]);
        }
            printf(" \n \t\t\tInformation Entered :\n");
            printf("\t\t\tName: %s\n",s[i].name);
            printf(" \t\t\tSap: %d\n",s[i].sap);
            printf("\t\t\tDesignation :%s \n",s[i].desg);
            }
            for(i = 0; i < f; i++){
            for(j = 0; j < (f - i - 1); j++){
        if(s[j].rank<s[j+1].rank){
            temp=s[j];
            s[j]=s[j+1];
            s[j+1]=temp;
        }
        else if(s[j].rank==s[j+1].rank){
            if(s[j].exp<s[j+1].exp){
                temp=s[j];
                s[j]=s[j+1];
                s[j+1]=temp;
            }
        }

    }
}
            fp=fopen("details.csv","a+");
            p=0;
            for(i=0;i<f;i++){
                    fprintf(fp,"%d,%s,%s,%d,%d,%d,%s,%s,%s\n ",s[i].sap,s[i].name,s[i].desg,s[i].hours,s[i].classs,s[i].lab,s[i].subject[p],s[i].subject[p+1],s[i].subject[p+2]);

            }
            fclose(fp);
            break;
            }
        case 2:{
        printf("\n\t\t\t Enter the sap id: \n");
        scanf("%d",&sap);
        fp=fopen("details.csv","r");
         while (fgets(line, 1024, fp))
    {
        char* tmp = strdup(line);
                rslt=atoi(getfield(tmp,1));
                if(sap ==rslt){
                 printf("%s\n",line);
                }
        free(tmp);
    }
    fclose(fp);
        break;}
        case 3:{
            system("cls");
            printf("\n\n\t\t\tEnter The number of subjects you want to enter :\n");
            scanf("%d",&s);
            struct Subject sub[s];
            system("cls");
            for(i=0;i<s;i++){
                printf("\n\n \t\t\tEnter Details for %d subject:\n ",i);
                printf("\t\t\t Enter the Name of Subject :\n ");
                scanf("%s",sub[i].sname);
                printf("\t\t\t Enter the Subject Code:\n");
                scanf("%s",sub[i].scode);
                printf("\t\t\t Enter the number of credits:\n");
                scanf("%d",&sub[i].credits);
                printf("\n\t\t\t Information Entered:\n");
                printf("\t\tName : %s\n\t\t Subject Code : %s\n\t\t Credits :%d\n ",sub[i].sname,sub[i].scode,sub[i].credits);
                fp=fopen("subjects.csv","a+");
                fprintf(fp,"%s,%s,%d\n",sub[i].sname,sub[i].scode,sub[i].credits);
                fclose(fp);
            }
            break;

        }
        case 4:{
            system("cls");
            //printf("\n\t\t\tEnter The number of branches you want:\n");
            //scanf("%d",&b);
            b=2;
//            printf("\n\t\t Enter the number of subjects:\n");
//            scanf("%d",&k);
            k=5;
            struct Branch br[b];
            for(i=0;i<b;i++){
                    q=0;
                    printf("\n\t\tEnter the name of Branch :\n");
            scanf("%s",br[i].name);
            fp=fopen("subjects.csv","r");
            while (fgets(line, 1024, fp))
    {
        char* tmp = strdup(line);
        strcpy(br[i].subject[q],getfield(tmp,1));
        q=q+1;
        free(tmp);
    }
    fclose(fp);
    for(j=0;j<5;j++){
        printf("\t\t Branch : %d Subject :%s\n",i,br[i].subject[j]);
    }
    e=0;
    fp=fopen("branches.csv","a+");
    for(j=0;j<2;j++){
        fprintf(fp,"%s,%s,%s,%s,%s,%s\n",br[j].name,br[j].subject[e],br[j].subject[e+1],br[j].subject[e+2],br[j].subject[e+3],br[j].subject[e+4]);
    }
    fclose(fp);


           } break;
        }
        case 5:{
            fc=fopen("branches.csv","r");
            i=0;j=0;
             while((line=fgets(buffer,sizeof(buffer),fc))!=NULL)
   {
     record = strtok(line,",");
     j=0;
     while(record != NULL)
     {
      if(j==0){
        strcpy(tb[i].name,record);
      }
      else if(j==1){
        strcpy(tb[i].subject[0],record);
      }
      else if(j==2){
        strcpy(tb[i].subject[1],record);
      }
      else if(j==3){
        strcpy(tb[i].subject[2],record);
      }
      else if(j==4){
        strcpy(tb[i].subject[3],record);
      }
      else if(j==5){
        strcpy(tb[i].subject[4],record);
      }
      record = strtok(NULL,",");
      j++;

     }
     i++;

   }
    fclose(fc);
 for(i=0;i<2;i++){
            printf("\n%s %s %s %s %s %s \n",tb[i].name,tb[i].subject[0],tb[i].subject[1],tb[i].subject[2],tb[i].subject[3],tb[i].subject[4]);
        }
        fc=fopen("details.csv","r");
            i=0;j=0;
             while((line=fgets(buffer,sizeof(buffer),fc))!=NULL)
   {
     record = strtok(line,",");
     j=0;
     while(record != NULL)
     {
      if(j==0){
        tf[i].sap=atoi(record);
       }
      else if(j==1){
        strcpy(tf[i].name,record);
      }
      else if(j==2){
        strcpy(tf[i].desg,record);
      }
      else if(j==3){
         tf[i].hours=atoi(record);
      }
      else if(j==4){
         tf[i].classs=atoi(record);
      }
      else if(j==5){
       tf[i].lab=atoi(record);
      }
      else if(j==6){
         strcpy(tf[i].subject[0],record);
      }
      else if(j==7){
        strcpy(tf[i].subject[1],record);
      }
      else if(j==8){
         strcpy(tf[i].subject[2],record);
      }
      record = strtok(NULL,",");
      j++;

     }
     i++;

   }
    fclose(fc);
    for(i=0;i<2;i++){
        printf("For branch %d \n",i);
        for(j=0;j<5;j++){
                for(m=0;m<3;m++){
                       for(l=0;l<2;l++) {
                            if(tf[l].classs>0){
                    if(strcmp(tb[i].subject[j],tf[l].subject[m])==0){
                        strcpy(tb[i].teacher[j],tf[l].name);
                        tf[l].classs=tf[l].classs-3;
                        printf("Load :%d  - %s\n",tf[l].classs,tf[l].name);
                    }
                    else{
                        continue;
                    }
                        }
                        else {
                            break;}
                        }

                }
                printf("%s %s \n",tb[i].subject[j],tb[i].teacher[j]);

}}


break;
        }
        case 6:{
            exit(0);}



    }
    }

    return 0;
}
