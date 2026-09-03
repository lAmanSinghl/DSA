#include <bits/stdc++.h>
using namespace std;
// bool helper(int index, long long &x, string &s, int sign)
// {
//     if (index == s.size() || x == -1 && s[index] != ' ' && s[index] != '+' && s[index] != '-' && !(s[index] >= '0' && s[index] <= '9') || x != -1 && !(s[index] >= '0' && s[index] <= '9') || x > 2147483648)
//     {
//         if (x == -1)
//             x = 0;
//         x = x * sign;
//         if (x < INT_MIN)
//         {
//             x = INT_MIN;
//         }
//         else if (x > INT_MAX)
//         {
//             x = INT_MAX;
//         }
//         return false;
//     }
//     if (s[index] == '+')
//     {
//         if (x == -1)
//             x = 0;
//     }
//     else if (s[index] == '-')
//     {
//         if (x == -1)
//             x = 0;
//         sign = -1;
//     }
//     else if (s[index] >= '0' && s[index] <= '9')
//     {
//         if (x == -1)
//             x = 0;
//         x = 10 * x + (s[index] - '0');
//     }
//     if (helper(index + 1, x, s, sign))
//         return true;
//     return false;
// }
// int myAtoi(string s)
// {
//     long long x = -1;
//     helper(0, x, s, 1);
//     return x;
// }
// int main()
// {

//     return 0;
// }
//CLEANER CODE FOR THIS 
class Solution {
public:
    int helper(int index, const string& s, long long num, int sign, bool started) {

        // End of string
        if (index == s.size()) {
            return num * sign;
        }

        char ch = s[index];

        // Before number/sign has started
        if (!started) {

            // Skip leading spaces
            if (ch == ' ') {
                return helper(index + 1, s, num, sign, false);
            }

            // Sign
            if (ch == '+' || ch == '-') {
                return helper(index + 1, s, num,
                             ch == '-' ? -1 : 1, true);
            }

            // First digit
            if (ch >= '0' && ch <= '9') {
                num = ch - '0';
                return helper(index + 1, s, num, sign, true);
            }

            // Invalid character before number
            return 0;
        }

        // Number has started → only digits are allowed
        if (ch < '0' || ch > '9') {
            long long result = num * sign;

            if (result < INT_MIN) return INT_MIN;
            if (result > INT_MAX) return INT_MAX;

            return result;
        }

        // Add current digit
        num = num * 10 + (ch - '0');

        // Prevent unnecessary recursion after overflow
        if (num > 2147483648LL) {
            return sign == -1 ? INT_MIN : INT_MAX;
        }

        return helper(index + 1, s, num, sign, true);
    }

    int myAtoi(string s) {
        return helper(0, s, 0, 1, false);
    }
};