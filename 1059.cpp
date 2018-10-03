#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define rep(i,x,y)  for(int i = x ; i< y ;i++)
#define F(i,x)  for(int i = 0 ; i< x ; i++)
using namespace std;
#define pii pair < int , int>
#define vpp vector < pii >
#define ff first
#define ss second
#define N 3000005
#define PI acos(-1.0)
#define PB push_back
#define MP make_pair
#define ll long long
#define READ()  freopen("in.txt","r" , stdin)
#define scana(x) scanf("%d",&x)
#define scanaa(x,y) scanf("%d%d",&x,&y)
#define scanaaa(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define MEMO(arr)  memset(arr , 0 , sizeof arr)
#define MEM(arr)  memset(arr,-1,sizeof arr)
 
const long long MOD[] = {1000000007LL, 2117566807LL};
const long long BASE[] = {1572872831LL, 1971536491LL};
 
 
int par[N];
int find(int a){
    if(par[a] == a) return a;
    return par[a] = find(par[a]);
}
 
 
bool makeUinon(int a ,int b){
   int tempa = find(a);
   int tempb = find(b);
   if(tempa == tempb) return 0;
   else{
      par[tempa] = tempb;
      return 1;
   }
}
 
 
void init(int n){
   rep(i,0,n+1) par[i] = i;
   return ;
}
int main()
{
  // READ();
   int test , cs = 1;
   scana(test);
   while(test--){
      vector < pair < int , pii > >v;
      int node , edge , air;
      scanaaa(node,edge,air);
      rep(i,0,edge){
         int a , b , c;
         scanaaa(a,b,c);
         if(c < air){
            v.push_back(MP(c,MP(a,b)));
         }
      }
      init(node);
      sort(v.begin(),v.end());
      int res = 0;
      for(int i = 0 ; i< v.size() ; i++){
          int a  = v[i].ss.ff;
          int b = v[i].ss.ss;
          int c = v[i].ff;
          // cout << a << ' ' << b << ' ' << c << endl;
          if(makeUinon(a,b)){
             res += c;
          }
      }
 
      int counter = 0;
      map < int , int > mark;
      for(int i = 1 ; i<= node  ; i++){
          int temp = find(i);
          if(mark[temp] == 0) counter++;
          mark[temp] = 1;
      }
 
      printf("Case %d: %d %d\n",cs++ , res+counter*air, counter);
   }
}
