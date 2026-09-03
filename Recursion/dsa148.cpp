#include <bits/stdc++.h>
using namespace std;
long long helper(long long n)
{
    if (n == 1)
        return 5;
    if (n == 2)
        return 20;
    if (n % 4 == 0)
    {
        long long x = helper(n / 2) % 1000000007;
        return (x) * (x) % 1000000007;
    }
    if (n % 2 == 0)
        return (4 * (helper(n - 1) % 1000000007)) % 1000000007;
    return (5 * (helper(n - 1) % 1000000007)) % 1000000007;
}
int countGoodNumbers(long long n)
{
    return helper(n);
}
int main()
{

    return 0;
}