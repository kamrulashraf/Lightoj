#include <bits/stdc++.h>
using namespace std;
#define ll long long
std::vector< ll > a , b;
void subset(int i , ll sum , vector < ll > &a , vector < ll > &res){
      res.push_back(sum);
      if(i < a.size()){
          subset(i+1,sum,a,res);
          subset(i+1,sum+a[i],a,res);
          subset(i+1,sum+a[i]+a[i],a,res);
      }
}
int main()
{
   int test , cs = 1;
   scanf("%d",&test);
   while(test--){
       ll n , maxW;
       a.clear(); b.clear();
       scanf("%lld%lld",&n,&maxW);
       for(int i = 0 ; i< n ; i++){
           ll temp;
           scanf("%lld",&temp);
           if(i&1) a.push_back(temp);
           else b.push_back(temp);
       }
 
       std::vector< ll > v1,v2;
       subset(0,0, a , v1);
       subset(0,0,b,v2);
       bool flag = 0;
       sort(v2.begin(),v2.end());
       for(int i=0;i<v1.size();i++){
            ll temp = maxW - v1[i];
            if(temp < 0) continue;
            int pos = lower_bound(v2.begin(),v2.end(),temp) - v2.begin();
            if(v2[pos] == temp){
               flag = 1;
               break;
            }
       }
 
       if(flag == 1){
          printf("Case %d: Yes\n",cs++ );
       } else printf("Case %d: No\n",cs++  );
   }
}
