#include <bits/stdc++.h>
using namespace std;
long long dp[3][55] , save[55][5];
std::vector< int > v;
 
long long call(int indx , int prev){
        if(indx >= 45) return 1;
        if(save[indx][prev] != -1) return save[indx][prev];
        dp[0][indx] = call(indx+1,0);
        dp[1][indx] = call(indx+1,1);
        if(prev == 0){
             return save[indx][prev] = dp[0][indx]+dp[1][indx];
        }
        else return save[indx][prev] = dp[0][indx];
}
 
 
void print(int indx , long long n){
      if( n <= 0 || indx >= 45) return;
      if(dp[0][indx] >= n){
         v.push_back(0);
         print(indx+1,n);
      }
      else{
         v.push_back(1);
         print(indx+1,n-dp[0][indx]);
      }
}
int main()
{
       // freopen("in.txt","r",stdin);
 
     memset(save , -1 ,sizeof(save));
     call(0,0);
     int test , cs = 1;
     scanf("%d",&test);
     while(test--){
          int n ;
          scanf("%d",&n);
          n++;
          print(0,n);
 
          bool flag = 0;
          printf("Case %d: ",cs++);
          for(int i = 0 ; i < v.size()  ; i++){
              if(v[i] == 0 && flag == 0) continue;
              printf("%d",v[i]);
              flag = 1;
          }
          v.clear();
          printf("\n");
 
     }
}
