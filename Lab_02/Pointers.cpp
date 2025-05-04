//Menu driven program to check if the obtained number has a selected feature

#include <cstdio>
#include <math.h>

int len(int*);
int check(int*, int*);
int armstrong(int*,int*);
int palindrome(int*,int*);
int perfect(int*,int*);

int main()
{
    int *num=(int*)malloc(sizeof(int));
    int *length=(int*)malloc(sizeof(int));
    int *choice=(int*)malloc(sizeof(int));
    printf("Enter the number: ");
    scanf("%d",num);
    *length=len(num);
    printf("\n1. Armstrong \n2. Palindrome \n3. Perfect Number \n4. Exit \n");
    while(1)
    {
        printf("Enter Choice: ");
        scanf("%d", choice);
        switch(*choice)
        {
            case(1):
                if(armstrong(num, length)){printf("The number is armstrong\n");}
                else {printf("The number is NOT armstrong\n");}
                break;
            case(2):
                if(palindrome(num,length)){printf("The number is Palindrome\n");}
                else {printf("The number is NOT Palindrome\n");}
                break;
            case(3):
                if(perfect(num,length)){printf("The number is Perfect\n");}
                else {printf("The number is NOT Perfect\n");}
                break;
            case(4):
                exit(1);
        }
    }
}

int len(int *n)
{
    int *count=(int*)malloc(sizeof(int));
    int *i=(int*)malloc(sizeof(int));
    *count=0;
    *i=*n;
    while(*i>0)
    {
        *count+=1;
        *i/=10;
    }
    free(i);
    return *count;
}

int check(int *num, int *sum)
{
    if(*sum==*num){return 1;}
    else {return 0;}
}

int armstrong(int *num, int *len)
{
    int *sum=(int*)malloc(sizeof(int));
    int *i=(int*)malloc(sizeof(int));
    *i=*num;
    *sum=0;
    while(*i>0)
    {
        *sum+=pow(*i%10,*len);
        *i/=10;
    }
    return check(num, sum);
}

int palindrome(int *num, int *len)
{
    int *sum=(int*)malloc(sizeof(int));
    int *i=(int*)malloc(sizeof(int));
    int *leng=(int*)malloc(sizeof(int));
    *sum=0;
    *i=*num;
    *leng=*len;
    while(*i>0)
    {
        *leng-=1;
        *sum+=(*i%10)*pow(10,*leng);
        *i/=10;
    }
    return check(num,sum);
}

int perfect(int *num, int *len)
{
    int *sum=(int*)malloc(sizeof(int));
    int *i=(int*)malloc(sizeof(int));
    *sum=0;
    *i=*num/2;
    while(*i>0)
    {
        if((*num)%(*i)==0){(*sum)+=(*i);}
        *i-=1;
    }
    return check(num, sum);
}