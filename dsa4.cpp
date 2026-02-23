#include <bits/stdc++.h>
using namespace std;

void printName(int i, int n)
{
    cout << "Running for->i:" << i << " n:" << n << endl;
    if (i > n)
    {
        return;
    }
    cout << "raj" << endl;
    printName(i + 1, n);
}

void backtrackPrint1toN(int m, int n)
{

    if (m < 1)
    {
        return;
    }
    backtrackPrint1toN(m - 1, n);
    cout << m << " ";
}

void backtrackPrintNto1(int m, int n)
{

    if (m > n)
    {
        return;
    }
    backtrackPrint1toN(m + 1, n);
    cout << m << " ";
}

void reverseArray(int i, int arr[], int n){

    if (i >= n / 2)
        return;
    swap(arr[i], arr[n - i - 1]);
    reverseArray(i + 1, arr, n);
}

bool isPalindrome(int i,string &s){
    if(i>=s.size()/2)return true;
    if(s[i]!=s[s.size()-i-1]) return false;
    return isPalindrome(i+1,s);
}

 int fib(int n) {
        if(n<=1){
            return n;
        }

        return fib(n-1)+fib(n-2);
    }
    
 int forfib(int n){
    if(n <= 1) return n;
    int a = 0, b = 1;
    for(int i = 2; i <= n; i++) {
        int n = a + b;
        a = b;
        b = n;
    }
    return b;
 }
int main()
{
    // printName(1,3);
    // backtrackPrint1toN(5,5);

    // This is for reversing Array
    // int n;
    // cin >> n;
    // int arr[n];
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }
    // cout << "Your array:";
    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;
    // cout << "Reversed Array:";
    // reverseArray(0, arr, n);
    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }
     
    
    //String palindrome check
    // string s;
    // cin>>s;
    // cout<<endl<<isPalindrome(0,s);

    cout<<fib(4);

    return 0;
}