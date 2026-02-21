#include <bits/stdc++.h>
using namespace std;

int reverse(int x)
{
    long result = 0;
    while (x != 0)
    {
        result = result * 10 + x % 10;
        x /= 10;
    }
    if (result >= pow(-2, 31) && result <= pow(2, 31) - 1)
        return (int)result;
    return 0;
}

int countDigits(int n)
{
    int count = 0;
    while (n > 0)
    {
        count = count + 1;
        n /= 10;
    }
    return count;
}

int countDigitsUsingLog(int n)
{
    return ((int)log10(n) + 1);
}

bool isPalindrome(int x)
{
    long result = 0;
    int y = x;
    while (y != 0)
    {
        result = result * 10 + y % 10;
        y /= 10;
    }
    if (x == (int)result && x >= 0)
    {
        return true;
    }
    return false;
}

bool isArmstrong(int n)
{
    int count = ((int)log10(n) + 1);
    int sum = 0;
    int x = n;
    while (x != 0)
    {
        sum += pow(x % 10, count);
        x /= 10;
    }
    return sum == n;
}

void printDivisors(int n){
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            cout << i << " ";
        }
    }
}

void OptimizedPrintDivisors(int n){
    vector<int> ls;
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            ls.push_back(i);
            if (i != n / i)
            {
                ls.push_back(n / i);
            }
        }
    }
    sort(ls.begin(), ls.end());
    for (int i : ls)
    {
        cout << i << " ";
    }
}

bool isPrime(int n){
    int count=0;
    for (int i = 1; i <=sqrt(n); i++)
    {
        if (n % i == 0)
        {
            count++;
            if (i != n / i)
            {
                count++;
            }
        }
    }
    return count==2;
}

void hcf(int m,int n){
   for(int i=min(m,n);i>0;i--){
    if(m%i==0 && n%i==0){
        cout<<i;
        break;
    }
   }
}
void equilateralAlgoHcf(int m,int n){
   while(m>0&& n>0){
    if(m>n)m=m%n;
    else n=n%m;
   }
   cout<<m+n;
}

int main()
{
    // cout << countDigitsUsingLog(2345235);
    // cout<<isPalindrome(121);
    // cout<<isArmstrong(0);
    // printDivisors(36);
    // OptimizedPrintDivisors(42);
    // cout<<isPrime(11);
    // hcf(6,9);
    equilateralAlgoHcf(10,52);
}