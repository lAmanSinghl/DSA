#include <bits/stdc++.h>
using namespace std;

int divide(int dividend, int divisor)
{
    if (divisor == dividend)
        return 1;

    // sign = 0 → result should be positive
    // sign = 1 → result should be negative
    int sign = 0;

    // One number is negative and the other is positive
    if (divisor < 0 && dividend > 0)
        sign++;

    if (divisor > 0 && dividend < 0)
        sign++;

    // Convert both numbers to positive values.
    // long long is used because abs(INT_MIN) = 2147483648,
    // which cannot fit inside an int.
    long long n = llabs(dividend);
    long long d = llabs(divisor);

    long long quotient = 0;

    while (n >= d)
    {

        int cnt = 0;

        // Keep doubling the divisor using left shift.
        // d << cnt means d * 2^cnt.
        // Find the largest power of 2 multiple of d
        // that is still <= n.
        while (n >= (d << (cnt + 1)))
            cnt++;

        // Subtract that large multiple from n.
        n = n - (d << cnt);

        // Since we subtracted d * 2^cnt,
        // add 2^cnt to the quotient.
        quotient += 1LL << cnt;
    }

    // 2^31 cannot be represented as a positive int.
    // If the result is negative, -2^31 is valid → INT_MIN.
    if (quotient == 1LL << 31 && sign)
        return INT_MIN;

    // If the positive result reaches/exceeds 2^31 - 1,
    // clamp it to INT_MAX.
    if (quotient >= (1LL << 31) - 1 && !sign)
        return INT_MAX;

    // Apply the negative sign if needed.
    if (sign)
        return (~quotient) + 1;

    // Otherwise return the positive quotient.
    return quotient;
}

int main()
{

    return 0;
}