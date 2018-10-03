#include <bits/stdc++.h>
using namespace std;
int main()
{
 
    int test , cs = 1;
    scanf("%d",&test);
    getchar();
    while(test--){
       string s;
       stack < string > stback , stForword;
       stback.push("http://www.lightoj.com/");
       printf("Case %d:\n",cs++);
       while(getline(cin,s)){
          if(s == "QUIT") break;
          // varialble declar
          std::vector<string > v;
          string temp;
 
          // converting two stirng
          for(int i = 0 ; i < s.size() ; i++){
             if(s[i] == ' '){
                v.push_back(temp);
                temp.clear();
             }
             else temp += s[i];
          }
          v.push_back(temp);
 
          // condition
          bool flag = 0;
          if(v[0] == "VISIT"){
             stback.push(v[1]);
             while(stForword.size()) stForword.pop();
          }
          if(v[0] == "BACK"){
              if(stback.size() == 1){
                printf("Ignored\n");
                flag = 1;
              }
              else{
                temp.clear();
                temp = stback.top();
                stback.pop();
                stForword.push(temp);
              }
          }
          if(v[0] == "FORWARD"){
             if(stForword.size() == 0){
                printf("Ignored\n");
                flag = 1;
             }
             else{
                temp.clear();
                temp = stForword.top();
                stForword.pop();
                stback.push(temp);
             }
          }
          temp.clear();
          temp = stback.top();
          if(!flag)
            cout << temp << endl;
       }
    }
  return 0;
}
