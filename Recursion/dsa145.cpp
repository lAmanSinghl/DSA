#include <bits/stdc++.h>
using namespace std;

void helper(int index, int k, int target, vector<int> &numbers, vector<vector<int>> &sol)
{
    if (index == k)
    {
        if (target == 0)
        {
            sol.push_back(numbers);
        }
        return;
    }
    for (int i = numbers.empty() ? 1 : numbers.back() + 1; i < 10; i++)
    {
        if (target >= i)
        {
            numbers.push_back(i);
            helper(index + 1, k, target - i, numbers, sol);
            numbers.pop_back();
        }
    }
}

vector<vector<int>> combinationSum3(int k, int n)
{
    vector<vector<int>> sol;
    vector<int> numbers;
    helper(0, k, n, numbers, sol);
    return sol;
}
int main()
{

    return 0;
}