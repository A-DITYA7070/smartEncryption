#include<bits/stdc++.h>
using namespace std;
vector<int>plainTextToBit(string st){
        vector<int>ans;
        ans.push_back(0);
        for(int i=0;i<st.length();i++){
            int x=int(st[i]);
            vector<int>temp;
            while(x!=0){
                int dig=x%2;
                x=x/2;
                temp.push_back(dig);
            }
            reverse(temp.begin(),temp.end());
            for(auto it:temp){
                ans.push_back(it);
            }
        }
        return ans;
}

int main(){
string st="ADITYARAJ";
vector<int>ans=plainTextToBit(st);
cout<<ans.size()<<" ";
for(auto it:ans)cout<<it<<" ";
return 0;
}