#include <bits/stdc++.h>
using namespace std;
int romanToInt(string s)
{
    int n = s.size();
    int num = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'I')
        {
            if (i != n - 1 && s[i + 1] == 'V')
            {
                num += 4;
                i++;
            }
            else if (i != n - 1 && s[i + 1] == 'X')
            {
                num += 9;
                i++;
            }
            else
            {
                num += 1;
            }
        }
        else if (s[i] == 'V')
        {
            num += 5;
        }
        else if (s[i] == 'X')
        {
            if (i != n - 1 && s[i + 1] == 'L')
            {
                num += 40;
                i++;
            }
            else if (i != n - 1 && s[i + 1] == 'C')
            {
                num += 90;
                i++;
            }
            else
            {
                num += 10;
            }
        }
        else if (s[i] == 'L')
        {
            num += 50;
        }
        else if (s[i] == 'C')
        {
            if (i != n - 1 && s[i + 1] == 'D')
            {
                num += 400;
                i++;
            }
            else if (i != n - 1 && s[i + 1] == 'M')
            {
                num += 900;
                i++;
            }
            else
            {
                num += 100;
            }
        }
        else if (s[i] == 'D')
        {
            num += 500;
        }
        else if (s[i] == 'M')
        {
            num += 1000;
        }
    }
    return num;
}
int romanToInt(string s)
{
    unordered_map<char,int>mpp={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
    int nums=0;
    int n=s.size();
    for(int i=0;i<n;i++){
        if(i<n-1&&mpp[s[i]]<mpp[s[i+1]]){
            nums-=mpp[s[i]];
        }else{
            nums+=mpp[s[i]];
        }
    }
    return nums;
}
int main()
{

    return 0;
}