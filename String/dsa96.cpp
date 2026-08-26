#include <bits/stdc++.h>
using namespace std;
string reverseWords(string s)
{
    int i = s.size() - 1;

    string sol = "";
    while (i >= 0 && s[i] == ' ')
    {
        i--;
    }
    int j = i;
    while (i >= 0)
    {
        if (i==0||s[i-1] ==' ')
        {
            sol.append(&s[i], j - i+1);
            if(i==0)break;
            i--;
            sol+=s[i];
            while(i>=0&&s[i]==' '){
                i--;
            }
            j = i;
        }
        else
        {
            i--;
        }
    }
    return sol;
}
int main()
{

    return 0;
}