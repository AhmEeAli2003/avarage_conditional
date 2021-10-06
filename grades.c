#include<stdio.h>
#include<stdlib.h>
void main(void)
{
    int grade,i=0,j=0,k=0;
    int temp[10];
    printf("Input grades: "); scanf("%d",&grade);
    while(grade>0)
    {
        temp[i]=grade%10;
        if (temp[i] == 5) j++;
        else if (temp[i] == 2) k++;
        else exit(0);
        grade/=10;
        i++;
    }
    if(j==k) printf("=");
    else if(j>k) printf("5");
    else if(j<k) printf("2");
}
