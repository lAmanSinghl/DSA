#include <bits/stdc++.h>
using namespace std;
// This approach can overflow. For example, if M = 10^9 and we need to find
// its 10th root, repeatedly multiplying the numbers may exceed the integer limit.

// Therefore, instead of computing the complete power, we:
// 1 -> if x^n == M
// 0 -> if x^n < M
// 2 -> if x^n > M (or exceeds M during computation)


//    int ntimes(int n,int x){
//      int ans=1;
//      for(int i=0;i<n;i++){
//          ans*=x;
//      }
//      return ans;
//    }


//So we do this
int ntimes(int n, int x, int m)
{
    long long ans = 1;
    for (int i = 0; i < n; i++)
    {
        ans *= x;
        // As soon as the computed value exceeds M, return 2 immediately.
        // This prevents unnecessary multiplications and avoids overflow in many cases.
        if (ans > m)
            return 2;
    }
    if (ans == m)
        return 1;
    return 0;
}

int NthRoot(int N, int M)
{
    int low = 1, high = M;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int val = ntimes(N, mid, M);
        if (val == 1)
            return mid;
        else if (val == 0)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int N, M;
    cin >> N >> M;

    cout << NthRoot(N, M);

    return 0;
}