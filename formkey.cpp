#include<bits/stdc++.h>
using namespace std;
    vector<int>formKey(int x){
        vector<int>ans;
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
        return ans;
    }
int main(){
vector<int>ans=formKey(59);
for(auto it:ans)cout<<it<<" ";
return 0;
}