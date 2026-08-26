#include <bits/stdc++.h>
using namespace std;
int myAtoi(string s)
{
    int n = s.size();
    int num = 0;
    int cnt = 0;
    int sign=1;
    while (s[cnt] == ' ')
    {
        cnt++;
    }
    if (s[cnt]=='-')
    {
        sign*=-1;
        cnt++;
    }else if(s[cnt]=='+'){
        cnt++;
    }
    while(s[cnt]='0'){
        cnt++;
    }
    for (int i = cnt; i < n; i++)
    {
        num += (s[n - 1 - i] - '0') * pow(10, i-cnt);
    }
    num*=sign;
    return num;
}
int main()
{

    return 0;
}