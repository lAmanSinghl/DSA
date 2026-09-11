#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countPrimes(int n)
    {
        if (n <= 2)
            return 0;

        vector<bool> prime(n, true);

        prime[0] = prime[1] = false;

        for (int i = 2; i * i < n; i++)
        {

            if (prime[i])
            {
                for (int j = i * i; j < n; j += i)
                {
                    prime[j] = false;
                }
            }
        }

        int count = 0;

        for (int i = 2; i < n; i++)
        {
            if (prime[i])
                count++;
        }

        return count;
    }
};
int countPrimes(int n)
{
    if (n <= 2)
        return 0;
    vector<bool> arr(n, true);
    for (int i = 4; i < n; i += 2)
    {
        arr[i] = false;
    }
    for (int i = 3; i * i < n; i += 2)
    {
        if (arr[i] == true)
        {
            for (int j = i * i; j < n; j += 2 * i)
            {
                arr[j] = false;
            }
        }
    }
    int cnt = 1;
    for (int i = 3; i < n; i += 2)
    {
        if (arr[i] == true)
            cnt++;
    }
    return cnt;
}
int main()
{

    return 0;
}