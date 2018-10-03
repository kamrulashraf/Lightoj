#include <bits/stdc++.h>
using namespace std;
int main()
{
   ios_base::sync_with_stdio(false);cin.tie(NULL);
   int test , cs = 1;
   scanf("%d", &test);
   while(test--){
      int n;
      vector < pair<int,int> > v;
      long long sum = 0;
      scanf("%d",&n);
      vector < pair < int,int> > a(n);
      for(int i = 0 ; i< n ; i++){
          scanf("%d%d", &a[i].first,&a[i].second);
      }
      for(int i = 0 ; i< n ; i++){
         for(int j = i+1 ; j< n ; j++){
             v.push_back({a[i].first+a[j].first, a[i].second+a[j].second});
         }
      }
      int counter = 0, ans = 0;
      sort(v.begin() , v.end());
      for(int i = 1 ; i< v.size() ; i++){
          if(v[i] == v[i-1]){
             ++counter;
             ans += counter;
 
          }
          else counter = 0;
      }
      printf("Case %d: %d\n",cs++,ans);
      v.clear();
      a.clear();
   }
 
}
