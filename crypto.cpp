#include<bits/stdc++.h>
using namespace std;
class Utils{
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
    public:
    // Utils();
   
//    converts the plain text to its binary bits..

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
        int num=64-ans.size();
        vector<int>res;
        for(int i=0;i<num;i++){
            res.push_back(0);
        }
        for(auto it:ans){
            res.push_back(it);
        }
        return res;
    }

    // left shift the array by k positions..

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

    // right shift the array by k positions...

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
    
    // key setup..
    
    vector<int>keySetup(int hr,int min,int sec){
       vector<int>res1;
       vector<int>res2;
       vector<int>res3;
       res1=formKey(hr);
       res2=formKey(min);
       res3=formKey(sec);
       
       int n=res1.size()+res2.size()+res3.size();

       vector<int>ans;
        
       int num=16-n;

       for(int i=0;i<num;i++){
        ans.push_back(0);
       }

       for(auto it:res1)ans.push_back(it);
       for(auto it:res2)ans.push_back(it);
       for(auto it:res3)ans.push_back(it);

       return ans;
    }
    
    // setting up the positons of pbox according to sarray...

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

    // divide key from 16 bits to 8bits... before dividing right shift according to round number...

    vector<vector<int>>DividedKeys(vector<int>&key){
        vector<int>res=rightShifter(key,0);
        vector<vector<int>>ans;
        vector<int>k1;
        vector<int>k2;
        for(int i=0;i<key.size();i++){
            if(i>=0 && i<8){
                k1.push_back(key[i]);
            }else if(i>=8){
                k2.push_back(key[i]);
            }
        }
        ans.push_back(k1);
        ans.push_back(k2);
        return ans;
    }
    
    // converting 64bits to string....

    string Cipher_text(vector<int>&v){
        string ans="";
        int i=0;
        while(i<63){
            int j=i+7;
            int p=0;
            int x=0;
            int t=0;
            while(i<j){
                t=pow(2,p)*v[i];
                x=x+t;
                i++;
                p++;
            }
            ans+=char(x);
        }
        return ans;
    }
};

class SmartEncryption{
    public:
    // initial encyption function..
    vector<int>InitialEncryptionFunc(vector<int>&v,vector<int>&key){
        vector<int>ans;
        for(int i=0;i<key.size();i++){
           int x=v[i]^key[i];
           ans.push_back(x);
        }
        return ans;
    }
    // setting up s-array ...

    vector<int>s_array(vector<string>&sarray){
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
    // implementing intial encryption..
    vector<int> InitialEncrypt(vector<int>&v,vector<int>&key){
        vector<int>p1;
        vector<int>p2;
        vector<int>p3;
        vector<int>p4;

        for(int i=0;i<64;i++){
           if(i>=0 && i<16){
              p1.push_back(v[i]);
           }else if(i>=16 && i<32){
              p2.push_back(v[i]);
           }else if(i>=32 && i<48){
            p3.push_back(v[i]);
           }else if(i>=48){
            p4.push_back(v[i]);
           }
        }
        p1=InitialEncryptionFunc(p1,key);
        p2=InitialEncryptionFunc(p2,key);
        p3=InitialEncryptionFunc(p3,key);
        p4=InitialEncryptionFunc(p4,key);

        vector<int>ans;
        for(auto it:p1)ans.push_back(it);
        for(auto it:p2)ans.push_back(it);
        for(auto it:p3)ans.push_back(it);
        for(auto it:p4)ans.push_back(it);

        return ans;
    }

    // converting into 8-bit small p-boxes...

    vector<vector<int>> convertToPBoxes(vector<int>&v){
        vector<int>p1,p2,p3,p4,p5,p6,p7,p8;
        for(int i=0;i<v.size();i++){
            if(i>=0 && i<8){
                p1.push_back(v[i]);
            }else if(i>=8 && i<16){
                p2.push_back(v[i]);
            }else if(i>=16 && i<24){
                p3.push_back(v[i]);
            }else if(i>=24 && i<32){
                p4.push_back(v[i]);
            }else if(i>=32 && i<40){
                p5.push_back(v[i]);
            }else if(i>=40 && i<48){
                p6.push_back(v[i]);
            }else if(i>=48 && i<56){
                p7.push_back(v[i]);
            }else if(i>=56 && i<64){
                p8.push_back(v[i]);
            }
        }
        vector<vector<int>>p_Boxes;
        p_Boxes.push_back(p1);
        p_Boxes.push_back(p2);
        p_Boxes.push_back(p3);
        p_Boxes.push_back(p4);
        p_Boxes.push_back(p5);
        p_Boxes.push_back(p6);
        p_Boxes.push_back(p7);
        p_Boxes.push_back(p8);

        return p_Boxes;
    }
};
int main(){
cout<<"Enter the message to encrypt "<<endl;
string plain_text;
getline(cin,plain_text);

cout<<"Enter the key "<<endl;
cout<<"Enter hour min ans sec "<<endl;
int hr,min,sec;
cin>>hr>>min>>sec;

// s-array from mendelevs periodic table...

vector<string>sarray={"ar","k","ca","sc","ti","v","cr","mn"};

// initializing class...

Utils ul;
SmartEncryption sm;

string cipher_text;

vector<int>key=ul.keySetup(hr,min,sec);

cout<<"printing keys"<<endl;
for(auto it:key)cout<<it<<" ";cout<<endl;
int i=0;
while(i<plain_text.length()){ 
    string st;
    for(int j=0;j<9;j++){
        if(i<plain_text.length()){
            st+=plain_text[i];
        }else if(i>plain_text.length()){
            break;
        }
        i++;
    }
    // plaintext to Bit conversion..
    vector<int>plainText_to_Bit;
    plainText_to_Bit=ul.plainTextToBit(st);
                
    // for round one...
    cout<<"left shifted bits "<<endl;
    vector<int>leftshiftedbits=ul.leftShifter(plainText_to_Bit,1);
    for(auto it:leftshiftedbits){
        cout<<it<<" ";
    }cout<<endl;

    vector<int>initialencryption=sm.InitialEncrypt(leftshiftedbits,key);
    
    cout<<"initial encrypted "<<endl;

    for(auto it:initialencryption)cout<<it<<" ";cout<<endl;

    cout<<"converting to p-boxes "<<endl;

    vector<vector<int>>pBox=sm.convertToPBoxes(initialencryption);

    for(auto it:pBox){
        for(auto i:it){
            cout<<i<<" ";
        }cout<<endl;
    }
    
    // getting corresponding positions based on sarray...

    vector<int>positions=sm.s_array(sarray);

    // rotating positions based on round numbers..
    
    vector<int>finalpos=ul.leftShifter(positions,0);

    // setting up the positions of pBox according to sarray positions...
    
    vector<vector<int>>afterArrange=ul.ArrangepBox(pBox,finalpos);

    // printing after arrangement...

    cout<<"after arranging "<<endl;
    for(auto it:afterArrange){
        for(auto i:it){
            cout<<i<<" ";
        }cout<<endl;
    }
    
    // dividing the keys into two parts...

    cout<<"dividing the keys "<<endl;
    vector<vector<int>>dividedkeys=ul.DividedKeys(key);
    vector<int>key1=dividedkeys[0];
    vector<int>key2=dividedkeys[1];
    
    cout<<"printing key1 "<<endl;
    for(auto it:key1)cout<<it<<" ";cout<<endl;
    cout<<"printing key2 "<<endl;
    for(auto it:key2)cout<<it<<" ";cout<<endl;
    
    // performing xor operation p-Boxes with first key...
    vector<vector<int>>pBoxafterFirstXor;
    for(int k=0;k<afterArrange.size();k++){
        vector<int>xorfunc;
        xorfunc=sm.InitialEncryptionFunc(afterArrange[k],key1);
        pBoxafterFirstXor.push_back(xorfunc);
    }
    
    // printing p-boxes after xor with first key...
    cout<<"printing after xor "<<endl;

    for(auto it:pBoxafterFirstXor){
        for(auto i:it){
            cout<<i<<" ";
        }cout<<endl;
    }
    
    // shifting the positoin of sarray based on round no...

    finalpos=ul.leftShifter(finalpos,0);

    // arranging p-boxes again after shifting the sarray...

    vector<vector<int>>SecArrangePBox=ul.ArrangepBox(pBoxafterFirstXor,finalpos);

    // printing once again after rearranging...

    cout<<"printing after 2nd arange "<<endl;

    for(auto it:SecArrangePBox){
        for(auto i:it){
            cout<<i<<" ";
        }cout<<endl;
    }

    // performing last xor operation with the key2..

    vector<vector<int>>pBoxafterSecondXor;
    for(int k=0;k<SecArrangePBox.size();k++){
        vector<int>xorfunc;
        xorfunc=sm.InitialEncryptionFunc(SecArrangePBox[k],key1);
        pBoxafterSecondXor.push_back(xorfunc);
    }

    // printing the p-box after 2nd xor function..

    cout<<"printing after 2nd xor "<<endl;

    for(auto it:pBoxafterSecondXor){
        for(auto i:it){
            cout<<i<<" ";
        }cout<<endl;
    }

    // converting back into 64 bits after 2nd xor operation...

    vector<int>finalop;
    for(int l=0;l<pBoxafterSecondXor.size();l++){
        for(auto it:pBoxafterSecondXor[l]){
            finalop.push_back(it);
        }
    }

    // printing the final 64 bit array ...

    cout<<"printing final 64 bit array "<<endl;

    for(auto it:finalop){
        cout<<it<<" ";
    }cout<<endl;

    // printing cipher text....

    cipher_text=ul.Cipher_text(finalop);
    cout<<cipher_text<<" ";

}    


return 0;
}