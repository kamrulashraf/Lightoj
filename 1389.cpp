#include <bits/stdc++.h>
using namespace std;
#define NN 105
int main()
{
    int test, cs = 1;
    scanf("%d",&test);
    while(test--){
       int n;
       scanf("%d",&n);
       string s;
       cin >> s;
       int res = 0;
       int mark[NN] = {0};
       for(int i = 0 ; i < s.size() ; i++){
           char x = s[i];
           if(x == '.' && mark[i] == 0){
                 if(i+1 < n){
                    mark[i+1] = 1;
                 }
                 if(i+2 < n){
                    mark[i+2] = 1;
                 }
                 res++;
           }
       }
       printf("Case %d: %d\n",cs++ , res);
    }
  return 0;
}
