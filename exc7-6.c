/* Exercise 7-6
    Write a program to compare two files, printing the first line where they differ*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

//void filecompare(FILE *fp1, FILE *fp2);

int main(int argc, char *argv[])
{
    FILE *fp1,*fp2;
    void filecompare(FILE *fp1, FILE *fp2);

    if(argc != 3)
        {
            fprintf(stderr,"comp: need two file names\n");
            exit(1);
        }
    else    
        {
            if((fp1 = fopen(*++argv, "r")) == NULL)
            {
                fprintf(stderr,"comp:can't open %s\n",*argv);
                exit(1);
            }
            else if((fp2 = fopen(*++argv, "r")) == NULL)
            {
                fprintf(stderr,"comp:can't open %s\n",*argv);
                exit(1);
            }
            else
            {
                filecompare(fp1,fp2);
                fclose(fp1);
                fclose(fp2);
            }    
        }
    exit(0);
}

void filecompare(FILE *fp1, FILE *fp2)
{
    char l1[MAX];
    char l2[MAX];
    char *lp1,*lp2;

    while((lp1 = fgets(l1,MAX,fp1)) != NULL && (lp2 = fgets(l2,MAX,fp2)) != NULL)
    {
        if(lp1 == l1 && lp2 == l2)
        {
            if(strcmp(l1,l2) != 0)
            {
                printf("difference in line: %s\n",l1);
                lp1 = lp2 = NULL;
            }  
        }
         else if (lp1 != l1 && lp2 == l2)
        {
            printf("first file end: %s\n",l1);
        }
        else if (lp1 == l1 && lp2 != l2)
        {
            printf("second file end: %s\n",l2);
        } 
    }
    
    /*
    int c;
    lp1 = fgets(l1,MAX,fp1);
    lp2 = fgets(l2,MAX,fp2);

    c = strcmp(l1,l2);
    if(c == 0){
    printf("Differing lines:\n");
    }
    else if(c < 0){
    printf("=== : \n%s\n", l1);
    }
    else{
    printf("=== : \n%s\n", l2);
    }*/
}
