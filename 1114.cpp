#include <bits/stdc++.h>
using namespace std;
#define N 1000005
#define pii pair < int ,int>
#define ff first
#define ss second
 
char ch[1000005];
 
int main()
{
     //freopen("in.txt","r" , stdin);
    ios_base::sync_with_stdio(true);cin.tie(NULL);
      int test , cs =  1 ;
      cin>>test;
      string s;
      while(test--){
         int n;
         cin >> n;
         getchar();
         map < string , int > hit;
         for(int i = 0 ; i< n ; i++){
             cin >> s;
//             cout << s << endl;
             if(s.size() > 2) sort(s.begin()+1, s.end()-1);
             hit[s]++;
         }
 
         cin >> n;
         getchar();
         printf("Case %d:\n", cs++);
         for(int i = 0 ; i< n ; i++){
            getline(cin , s);
//            cout << s << endl;
            stringstream ss(s);
            int res = 1;
            while(ss >> s){
               if(s.size() > 2)
                 sort(s.begin()+1, s.end()-1);
 
               res *= hit[s];
            }
            printf("%d\n",res);
         }
 
      }
 
}
