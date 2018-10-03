#include <bits/stdc++.h>
using namespace std;
#define NN 60
#define pii pair < int, int >
#define ff first
#define ss second
map < int , int >  parent;
void init(){
   for(int i=0;i<=50 ; i++)
       parent[i] = i;
}
int find(int n){
    if(n == parent[n]){
        return n;
    }
    else parent[n] = find(parent[n]);
}
 
bool makeUnion(int a , int b){
     int tempA = find(a);
     int tempB = find(b);
     if(tempA == tempB) return 0;
     parent[tempA] =tempB;
     return 1;
}
int main()
{
   int test, cs = 1;
   scanf("%d",&test);
   while(test--){
      int n;
      long long tot = 0;
      init();
      scanf("%d",&n);
      std::vector< pair < long long , pii > >v;
      for(int i=0;i<n;i++){
         for(int j=0;j<n;j++){
            long long w;
            scanf("%lld",&w);
            tot += w;
            v.push_back({w, {i,j}});
         }
      }
 
      sort(v.begin(), v.end());
      long long sum = 0;
 
      for(int i=0;i<v.size();i++){
        long long w = v[i].ff;
        int aa = v[i].ss.ff;
        int bb = v[i].ss.ss;
        // cout << aa << ' ' << bb << ' ' << w << endl;
        if(w){
            if(makeUnion(aa,bb)) sum+=w;
        }
      }
      int temp = find(0);
      int flag = 1;
      for(int i = 1 ; i< n ; i++){
         if(find(i) != temp) flag = 0;
      }
      if(flag == 0) tot = -1;
      else tot -= sum;
      printf("Case %d: %lld\n",cs++ , tot);
      v.clear();
   }
}
 
