#include <bits/stdc++.h>
using namespace std;
bool isAnagram(string s, string t)
{   
    int size= s.size();
    if (size != t.size())
        return false;
    int arr[26,0];
    for(int i=0;i<size;i++){
        arr[s[i]-'a']++;
        arr[t[i]-'a']--;
    }
    for(int i=0;i<size;i++){
        if(arr[i]!=0)return false;
    }
    return true;
}
int main()
{

    return 0;
}