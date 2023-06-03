#include<bits/stdc++.h>
using namespace std;
int decimalC(int n){
      int num = n;
    int dec_value = 0;
 
    // Initializing base value to 1, i.e 2^0
    int base = 1;
 
    int temp = num;
    while (temp) {
        int last_digit = temp % 10;
        temp = temp / 10;
 
        dec_value += last_digit * base;
 
        base = base * 2;
    }
    return dec_value;
}
   int BinaryToDecimal(vector<int>&num){
      int dec_value = 0;
      // Initializing base value to 1, i.e 2^0
      int base = 1;
      int n=num.size();
      int y=0;
      for(int i=num.size()-1;i>=0;i--){
         int x=pow(2,y)*num[i];
         dec_value+=x;
         y++;
      }
      return dec_value;
   }
int main(){
cout<<decimalC(1010)<<endl;
vector<int>num={1,0,1,0,1,0,1,0,1};
cout<<BinaryToDecimal(num);
return 0;
}