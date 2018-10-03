#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll test , a,cse = 0 ;
    char s[20];
    cin >> test;
    while(test--){
        int f = 0;
        scanf("%lld %s", &a , s);
        if(strcmp(s,"Alice") == 0){
            if(a%3 == 2 || a%3 == 0) f = 1;
            if(f) printf("Case %d: Alice\n",++cse);
            else printf("Case %d: Bob\n",++cse);
        }
        else{
            if(a%3 == 0) f = 1;
            if(!f) printf("Case %d: Bob\n",++cse);
            else printf("Case %d: Alice\n",++cse);
        }
 
 
    }
}
 
