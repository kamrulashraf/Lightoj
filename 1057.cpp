#include <bits/stdc++.h>
using namespace std;
#define N 21
#define BOUNDARY(x,y)  (x >= 0 && x <r && y>=0 && y < c)
#define rep(x,y)  for(int i=x;i<y;i++)
#define pii pair <int,int>
#define ff first
#define ss second
#define inf 1e9
int fx[] = {0,0,1,-1,1,1,-1,-1};
int fy[] = {1,-1,0,0,1,-1,1,-1};
int r , c , sz;
int vis[N][N] , level[N][N],dis[N][N] , dp[16][1<<17];
char ch[N][N];
void dfs(int x,int y){
  vis[x][y] = 1;
  queue <pii>  q;
  q.push(make_pair(x,y));
  while(!q.empty()){
    int x1 = q.front().ff;
    int y1 = q.front().ss;
    q.pop();
    for(int i = 0 ; i<8 ; i++){
       int xx = fx[i]+x1;
           int yy = fy[i]+y1;
           if( BOUNDARY(xx,yy) && vis[xx][yy] == 0){
             level[xx][yy] = level[x1][y1]+1;
             q.push(make_pair(xx,yy));
             vis[xx][yy] = 1;
           }
    }
  }
}
 
void clr(){
      memset(vis,0,sizeof vis);
        memset(level,0,sizeof level);
}
 
 
int call(int prev, int mask){
     int mmin = inf;
     if( mask == (1<<sz)-1) return dis[prev][0];
     if(dp[prev][mask] != -1) return dp[prev][mask];
     for(int i = 1 ; i < sz ; i++){
          if(mask & (1<<i)) continue;
          int temp = mask|(1<<i);
          mmin = min(mmin,dis[prev][i]+call(i,temp));
     }
     return dp[prev][mask] = mmin;
}
int main()
{
  // freopen("in.txt","r",stdin);
  int test , cs = 1;
  scanf("%d",&test);
  int savex , savey;
  while(test--){
    std::vector< pii > v;
        scanf("%d%d",&r,&c);
        v.push_back(make_pair(-1,-1));
       
       for(int i = 0 ; i< r ; i++){
           for(int j = 0 ; j < c ; j++){
              cin >> ch[i][j];
              if(ch[i][j] == 'x'){
                  v[0].ff = i;
                  v[0].ss = j;
              }
              else if(ch[i][j] == 'g'){
                  v.push_back(make_pair(i,j));
              }
           }
       }
 
        for(int i = 0 ; i< v.size() ; i++){
            clr();
              int x = v[i].ff;
              int y= v[i].ss;
              dfs(x,y);
            for(int j=0;j< v.size();j++){
                x = v[j].ff;
                y = v[j].ss;
                dis[i][j] = level[x][y];
            }
 
        }
         
         // for(int i = 0 ; i < v.size() ; i++){
         //      cout << v[i].ff << ' ' << v[i].ss << endl;
         // }
 
        //  for(int i = 0 ; i< r ; i++){
        //    for(int j=0; j< c ; j++){
        //      cout << level[i][j] << ' '  ;
        //    }
        //     cout << endl;
        // }
         
        //  for(int i = 0 ; i< v.size() ; i++){
        //    for(int j=0; j< v.size() ; j++){
        //      cout << i << ' ' << j << ' ' << dis[i][j] << endl;
        //    }
        // }
 
        sz = v.size();
        memset(dp,-1,sizeof dp);
        int res = call(0,1);
        printf("Case %d: %d\n",cs++ , res);
  }
}
