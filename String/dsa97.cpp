#include <bits/stdc++.h>
using namespace std;
string largestOddNumber(string num)
{
    int j = num.size() - 1;
    if (j < 0)
    return "";
    while (j >= 0 && (num[j] - '0') % 2 != 1)
    {
        j--;
    }
    return num.substr(0, j + 1);
}
int main()
{

    return 0;
}