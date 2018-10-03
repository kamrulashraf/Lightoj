#include <bits/stdc++.h>
using namespace std;
int main()
{
    int test , cs =  1;
    scanf("%d",&test);
    getchar();
    while(test--){
         string s,s1;
         int hit[150] = {0};
         int mark[150] = {0};
         getline(cin , s);
         getline(cin,s1);
         for(int i = 0 ; i< s.size() ; i++){
             char ch = tolower(s[i]);
             hit[ch]++;
         }
         for(int i = 0 ; i< s1.size() ; i++){
             char ch = tolower(s1[i]);
             mark[ch]++;
         }
         
         bool flag = 0;
         for(int i = 'a'; i <= 'z' ; i++){
            // cout << (char) i << ' ' << hit[i] << ' ' << mark[i] << endl;
            if(hit[i] != mark[i]) flag = 1;
         }
 
         if(flag) printf("Case %d: No\n",cs++);
         else printf("Case %d: Yes\n",cs++);
 
    }
}
