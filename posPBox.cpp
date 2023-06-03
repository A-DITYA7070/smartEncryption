#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>ArrangepBox(vector<vector<int>>&temp,vector<int>&sarray){
    vector<vector<int>>res(temp.size(),vector<int>(temp[0].size()));
    for(int i=0;i<temp.size();i++){
        int t=sarray[i];
        for(int j=0;j<temp[i].size();j++){
            res[t][j]=temp[i][j];
        }
    }
    return res;
}
int main(){
vector<int>sarray={0,3,1,5,6,7,2,4};
vector<vector<int>>temp={
    {1,2,3},
    {40,50,6},
    {7,7,8},
    {3,2,4},
    {10,2,34},
    {4,5,6},
    {232,342,2},
    {221,23,2},
};
vector<vector<int>>res(temp.size(),vector<int>(temp[0].size(),0));
res=ArrangepBox(temp,sarray);
for(auto it:res){
    for(auto i:it){
        cout<<i<<" ";
    }cout<<endl;
}
return 0;
}