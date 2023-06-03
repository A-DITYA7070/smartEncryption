#include<bits/stdc++.h>
using namespace std;
vector<int>sArrayToArray(vector<string>&sarray){
   vector<pair<string,int>>v;
    vector<string>s2=sarray;
    vector<int>ans(sarray.size(),0);
    for(int i=0;i<s2.size();i++){
        v.push_back({s2[i],i});
    }

    sort(sarray.begin(),sarray.end());
    vector<int>vis(sarray.size(),0);
    for(int i=0;i<sarray.size();i++){
        string st=sarray[i];
        if(!vis[i]){
            for(int j=0;j<v.size();j++){
                if(st==v[j].first){
                    ans[v[j].second]=i;
                    vis[i]=true;
                }
            }
        }
    }
    return ans;
}
int main(){
vector<string>sarray;
for(int i=0;i<8;i++){
    string st;
    cin>>st;
    sarray.push_back(st);
}

vector<int>ans=sArrayToArray(sarray);

for(auto it:ans){
    cout<<it<<" ";
}
return 0;
}