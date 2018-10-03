#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
    int i , j , k , t , x ,y ,ans;
    int test;
    cin >> test;
    for(t = 1 ; t<= test ; t++)
    {
        cin >> x >> y;
        int ans = max(x,y)*4 + 19;
        if(x>y) ans += (x-y)*4;
        printf("Case %d: %d\n", t , ans);
    }
}
 
