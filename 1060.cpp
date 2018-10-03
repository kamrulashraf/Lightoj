#include <bits/stdc++.h>
using namespace std;
 
char s[25];
long long fac[25];
int mark[27];
void init(){
 
    fac[0] = 1;
    for(int i = 1 ; i<= 21 ; i++){
         fac[i] = fac[i-1]*i;
    }
}
 
 
void call(int n , int val){
    if(n==0) return;
 
    for(int i = 0 ; i< 26 ; i++){
            if(mark[i]){
                mark[i]--;
                long long temp = fac[n-1];
                for(int j = 0 ; j< 26 ; j++){
                     temp /= fac[mark[j]];
                }
                if(temp >= val){ // ami bosaite parbo
                      printf("%c",i+'a');
                      break;
                }
                else{
                    mark[i]++; // bosaite parbo na
                    val -= temp;
                }
            }
    }
 
    call(n-1,val);
}
int main()
{
    // freopen("in.txt","r",stdin);
    int test , cs = 1;
    scanf("%d",&test);
    init();
 
    while(test--){
         int n;
 
 
         memset(mark,0,sizeof(mark));
 
         printf("Case %d: ",cs++);
 
         getchar();
         scanf("%s",s);
         scanf("%d",&n);
         int sz = 0;
         for(int i = 0 ; s[i] ; i++){
             mark[s[i]-'a']++;
             sz++;
         }
 
         long long temp = fac[sz];
         for(int i = 0 ; i< 26 ; i++){
              temp /= fac[mark[i]];
         }
 
         if(temp < n) printf("Impossible\n");
         else{
             call(sz,n);
             printf("\n");
         }
    }
}
