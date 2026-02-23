#include <bits/stdc++.h>
using namespace std;


int main(){
    // //Number Hashing 

    // int n;
    // cin>>n;
    // int arr[n];
    // for(int i=0;i<n;i++){
    //     cin>>arr[i];
    // }
    //  int hash[13]={0};   
    //  for(int i=0;i<n;i++){
    //     ++hash[arr[i]];
    //  }
    // int q;
    // cin>>q;
    // while(q--){
    //     int number;
    //     cin>>number;
    //     cout<<number<<":"<<hash[number]<<endl;
    // }

    
    // //char hashing
    // string s;
    // cin>>s;
    // //pre compute
    // int hash[256]={0};
    // for(int i=0;i<s.size();i++){
    //     hash[s[i]]++;
    // }
    // int q;
    // cin>>q;
    // while (q--)
    // {
    //    char c;
    //    cin>>c;
    //    //fetch
    //    cout<<c<<":"<<hash[c]<<endl;
    // }
    
    int n;
    cin>>n;
    int arr[n];
    // map<int,int> mp; 
    // sorted-map=map takes log(n)in best average and worst case
    // unordered-map  best and avergae cases are O(1),worst is O(n)
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        cin>>arr[i];
         mp[arr[i]]++;
    }


    for(int i=0;i<n;i++){
       
    }
    
    //map iterator
    // for(auto it:mp){
    //     cout<<it.first<<"->"<<it.second<<endl;
    // }
    int q;
    cin>>q;
    while(q--){
        int number;
        cin>>number;
        //fetch
        cout<<number<<":"<<mp[number]<<endl;
    }
}