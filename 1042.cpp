#include <bits/stdc++.h>
using namespace std;
bool cmp(int a , int b){
   return a>b;
}
int main()
{
   int test , cs = 1;
   scanf("%d",&test);
   while(test--){
        long long n;
        scanf("%lld",&n);
        std::vector<int > v;
        while(n){
            v.push_back(n%2);
            n/=2;
        }
        int save = -1;
        v.push_back(0);
        int flag =0 ;
        // for(auto x : v)
        //    cout << x ;
        //  cout << endl;
        for(int i = 0 ; i< v.size() ; i++){
            if(v[i] == 1 && flag == 0){
              flag = 1;
              continue;
            }
            if(flag == 1 && v[i] == 0){
                save = i-1;
                swap(v[i-1],v[i]);
                break;
            }
        }
       sort(v.begin() , v.begin()+save+1, cmp);
       
       // for(auto x : v)
       //    cout << x ;
       //  cout << endl;
       long long res = 0;
       for(int i = 0 ;  i < v.size() ; i++){
             res += pow(2,i)*v[i];
       }
       printf("Case %d: %lld\n",cs++ ,res );
 
 
   }
}
