#include <bits/stdc++.h>
using namespace std;
int singleNumber2(vector<int> &nums)
{
    int ones = 0, twoes = 0;
    for (auto it : nums)
    {
        ones = (ones ^ it) & (~twoes);
        twoes = (twoes ^ it) & (~ones);
    }
    return ones;
}

int main()
{

    return 0;
}