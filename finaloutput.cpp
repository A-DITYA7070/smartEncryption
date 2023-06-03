#include<bits/stdc++.h>
using namespace std;
int main(){
string ans="";
vector<int>v(64,1);
int i=0;
while(i<63){
    int j=i+7;
    int p=0;
    int x=0;
    while(i<j){
       int t=pow(2,p);
       t=t*v[i];
       x=x+t;
       p++;
       i++;
    }
    cout<<x<<" ";
    cout<<char(x)<<" ";
}
cout<<ans;

return 0;
}