#include <stdio.h>
int main()
{
 int a,b,t;
 scanf("%d", &t);
 while(t--){
    scanf("%d", &a);
    if(a>10)
        {b = a - 10;
        a = 10;}
    else {a = a;
          b= 0;}
    printf("%d %d\n", b, a);}
}
