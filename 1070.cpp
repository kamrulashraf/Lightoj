#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
long long mod;
struct MAT
{
     int r,c;
     ull a[2][2];
     MAT(int  a,int b){
        r = a;
        c = b;
     }
     void init(long long temp[]){
        for(long long i = 0 ; i<r*c ; i++){
            a[i/r][i%c] = (ull) temp[i];
        }
     }
     void print(){
          for(int i = 0 ; i< r ; i++){
             for(int j = 0; j < c ; j++){
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
         for(int i = 0 ; i< r ; i++){   // row 1st mat
             for(int j = 0 ; j< b.c ; j++){  // col 2nd mat
                   for(int k=0; k<c ;k++){   // col 1st matss
                      sum.a[i][j] += (ull) (a[i][k]*b.a[k][j]);
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
 
int main()
{
    long long test, cs= 1;
    scanf("%lld",&test);
    while(test--){
        long long a,b,n,d;
        scanf("%lld%lld%lld",&a,&b,&n);
        long long arr[] = {a,-b,1,0};
        MAT root(2,2);
        root.init(arr);
        // root.print();
        if(n==0){
            printf("Case %lld: %llu\n",cs++ ,(ull) 2);
            continue;
        }
        if(n == 1){
            printf("Case %lld: %llu\n",cs++ ,(ull) a);
            continue;
        }
        MAT res = pow(root,n-1);
        //res.print();
        ull ans = (ull) (res.a[0][0]*a+res.a[0][1]*2);
         printf("Case %lld: %llu\n",cs++ ,ans);
 
    }
}
