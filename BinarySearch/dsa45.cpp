#include <bits/stdc++.h>
using namespace std;

int find_days(vector<int> &weights, int mid)
{
    // We start with day=1 because even if all packages fit within the capacity,
    // they still need at least one day to be shipped. Every time the capacity
    // is exceeded, we start a new day and increment the counter.
    int days = 1, weightSum = 0;
    for (auto it : weights)
    {
        if (weightSum + it <= mid)
        {
            weightSum += it;
        }
        else
        {
            weightSum = it;
            days++;
        }
    }
    return days;
}

int shipWithinDays(vector<int> &weights, int days)
{
    // max_element() finds the largest element in the vector.
    // accumulate() computes the sum of all elements, with the third argument as the initial sum.
    int low = *max_element(weights.begin(), weights.end()), high = accumulate(weights.begin(), weights.end(), 0);
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int possibledays = find_days(weights, mid);
        if (possibledays <= days)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}

int main()
{
    int n;
    cin >> n;

    vector<int> weights(n);
    for (int i = 0; i < n; i++)
    {
        cin >> weights[i];
    }

    int days;
    cin >> days;

    cout << shipWithinDays(weights, days);

    return 0;
}