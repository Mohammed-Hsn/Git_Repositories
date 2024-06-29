#include <stdio.h>

int main(){
    int a,b,c;
    printf("--------------------\n");
    
    printf("Enter you number 1:\n --->\t");
    scanf("%d",&a);
    printf("Enter you number 2:\n --->\t");
    scanf("%d",&b);
    printf("Enter you number 3:\n --->\t");
    scanf("%d",&c);
    int sum = a+b+c;
    printf("The addition of %d,%d,%d is:\n --->\t%d\n",a,b,c,sum);
    printf("--------------------\n");

}