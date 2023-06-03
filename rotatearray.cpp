#include<bits/stdc++.h>
using namespace std;
  vector<int>leftShifter(vector<int>&nums,int k){
        int n=nums.size();
        k=k%n;
        vector<int>ans(n);
        int j=0;
        for(int i=n-k;i<n;i++){
            ans[j++]=nums[i];
        }
        for(int i=0;i<n-k;i++){
            ans[j++]=nums[i];
        }
       return ans;
}
vector<int>rightShifter(vector<int>&nums,int k){
    int n=nums.size();
    k=k%n;
    vector<int>ans(n);
    int j=0;
    for(int i=k;i<n;i++){
        ans[j++]=nums[i];
    }
    for(int i=0;i<k;i++){
        ans[j++]=nums[i];
    }
    return ans;
}
int main(){
vector<int>v={23,12,2,3,4};
vector<int>ans=leftShifter(v,3);
for(auto it:ans)cout<<it<<" ";
vector<int>res=rightShifter(v,3);
cout<<endl;
for(auto it:res)cout<<it<<" ";
return 0;
}