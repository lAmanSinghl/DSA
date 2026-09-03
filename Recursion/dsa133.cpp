#include <bits/stdc++.h>
using namespace std;
void getsequences(int index, vector<string>&sequences,string &temp, string &s, int n)
{
   if(index>=n)sequences.push_back(temp);
   string temp2=temp;
   temp.push_back(s[index]);
   getsequences(index+1,sequences,temp,s,n);
   temp.pop_back();
   getsequences(index+1,sequences,temp2,s,n);
   
}
vector<string> powerSet(string &s)
{
    vector<string> sequences;
    string temp="";
   getsequences(0, sequences,temp, s, s.size());
    return sequences;
}
int main()
{

    return 0;
}