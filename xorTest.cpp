#include<bits/stdc++.h>
using namespace std;
vector<int> xorOperation(vector<int>&nums,vector<int>&key){
    vector<int>ans;
    for(int i=0;i<nums.size();i++){
        int x = nums[i]^key[i];
        ans.push_back(x);
    }
    return ans;
}
int main(){
vector<int>nums = {0,1,0,1,0,1,1,1,0,0,1,1,0,1,0,1};
vector<int>ans = xorOperation(nums,nums);
// for(auto it:ans)cout<<it<<" ";
// cout<<char(127)<<" "<<char(126)<<" "<<char(125)<<endl;
// cout<<int(char(127))<<endl;.
// cout<<char(127);
cout<<"Ñ";
return 0;
}