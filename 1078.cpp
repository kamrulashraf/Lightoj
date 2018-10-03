#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a , b, test,cse = 0;
    scanf("%d", &test);
    while(test--){
        scanf("%d %d", &a , &b);
        int m = a , n = b;
        int counter = 0;
        while(b%a){
           int temp = 10*(b%a);
           b = temp+n;
                                        //    cout << b << endl;
           counter++;
        }
 
     printf("Case %d: %d\n", ++cse , counter+1);
    }
}
