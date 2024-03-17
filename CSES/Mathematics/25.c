#include<stdio.h>
#include<stdlib.h>
int main()  {
    int * p = (int *)malloc(0);
    scanf("%d", p);
    printf("%d ", *p);
}
