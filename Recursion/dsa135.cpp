#include <bits/stdc++.h>
using namespace std;

void helper(vector<vector<int>> &sol, int index, vector<int> &vec, vector<int> &candidates, int target)
{

    if (target == 0)
    {
        sol.push_back(vec);
        return;
    }

    for (int i = index; i < candidates.size(); i++)
    {
        if (candidates[index] > target)
            break;
        if (i > index && candidates[i - 1] == candidates[i])
            continue;
        vec.push_back(candidates[i]);
        helper(sol, i + 1, vec, candidates, target - candidates[i]);
        vec.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    vector<vector<int>> sol;
    vector<int> vec;
    sort(candidates.begin(), candidates.end());
    helper(sol, 0, vec, candidates, target);

    return sol;
}

int main()
{

    return 0;
}