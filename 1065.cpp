#include <bits/stdc++.h>
using namespace std;
long long mod;
struct MAT
{
     long long r,c;
     long long a[2][2];
     MAT(long long a,long long b){
        r = a;
        c = b;
     }
     void init(long long temp[]){
        for(long long i = 0 ; i<r*c ; i++){
            a[i/r][i%c] = temp[i];
        }
     }
     void print(){
          for(long long i = 0 ; i< r ; i++){
             for(long long j = 0; j < c ; j++){
                 cout << a[i][j] << ' ';
             }
             cout << endl;
          }
     }
     MAT operator*(MAT b){
         MAT sum(r,c);
         long long temp[r*c];
         memset(temp,0,sizeof temp);
         sum.init(temp);
         for(long long i = 0 ; i< r ; i++){   // row 1st mat
             for(long long j = 0 ; j< b.c ; j++){  // col 2nd mat
                   for(long long k=0; k<c ;k++){   // col 1st matss
                      sum.a[i][j] += (a[i][k]*b.a[k][j])%mod;
                   }
             }
         }
         return sum;
 
     }
};
 
MAT pow(MAT b , long long p){
    if(p == 0 || p == 1)
      return b;
    if(p&1){
        return b*pow(b,p-1);
    }
    else{
        MAT temp = pow(b,p/2);
        return temp*temp;
    }
 
}
long long power(long long b, long long p){
     if(p == 0 || p == 1) return b;
     if(p&1) return b*power(b,p-1);
     else{
        long long x = power(b,p/2);
        return x*x;
     }
}
int main()
{
    long long test, cs= 1;
    scanf("%lld",&test);
    while(test--){
        long long a,b,c,d;
        long long arr[] = {1,1,1,0};
        MAT root(2,2);
        root.init(arr);
        scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
        c--;
        if(c==-1 || c==0){
            long long ans;
            if(c==-1)
               ans = a;
            else ans = b;
            printf("Case %lld: %lld\n",cs++ ,ans);
            continue;
        }
        mod = power(10,d);
        MAT res = pow(root,c);
        long long ans = res.a[0][0]*b+res.a[0][1]*a;
        //res.print();
        ans %= mod;
        printf("Case %lld: %lld\n",cs++ ,ans);
 
    }
}
