#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
#define N 1005
int mmax = 1001;
int tree[N][N];
bool vis[N][N];
int sum(int x , int y){
    int ret = 0;
    while(x){
        int indx = y;
        while(indx){
            ret += tree[x][indx];
            indx -= indx & -indx;
        }
        x -= x &-x;
    }
    return ret;
}
void update(int x , int y , int val){
     while(x <= mmax){
         int indx = y;
         while(indx <= mmax){
             tree[x][indx] += val;
             indx += indx & -indx;
         }
         x += x & -x;
     }
}
 
int query(int x , int y , int x1,int y1){
     int ret = sum(x1,y1);
     ret -= sum(x-1,y1);
     ret -= sum(x1,y-1);
     ret += sum(x-1,y-1);
     return ret;
}
int main()
{
     // freopen("inputf.in","r",stdin);
     int test , cs = 1, q, flag , x , y , x1,y1 ;
     scanf("%d",&test);
     while(test--){
        memset(tree,0,sizeof tree);
        memset(vis,0,sizeof vis);
        scanf("%d",&q);
        printf("Case %d:\n",cs++ );
        while(q--){
             scanf("%d",&flag);
             if(flag == 0){
                 scanf("%d%d",&x,&y);
                 x++ , y++;
                 if(vis[x][y]==0){
                    vis[x][y] = true;
                    update(x,y,1);
                 }
             }
             else{
                scanf("%d%d%d%d",&x,&y,&x1,&y1);
                x++ , y++ , x1++ , y1++;
                int res = query(x,y,x1,y1);
                printf("%d\n",res);
             }
        }
     }
}
