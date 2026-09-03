#include <bits/stdc++.h>
using namespace std;
            //            candidates = {2, 3} target = 5
            //              index=0, target=5, vec=[]
            //                   /              \
            //                TAKE              SKIP
            //                 2                 3
            //                 |                 |
            //         index=0,target=3      index=1,target=5
            //            vec=[2]              vec=[]
            //              /    \                /    \
            //           TAKE   SKIP           TAKE   SKIP
            //            2       3              3      -
            //            |       |              |      
            //     target=1   target=3       target=2
            //     vec=[2,2]   vec=[2]       vec=[3]
            //        /          /  \           /
            //     TAKE        TAKE SKIP      TAKE
            //       X           X    X         X
            //   target=-1   target=0       target=-1
            //                            vec=[3,2]

void helper(vector<vector<int>> &sol, int index,
            vector<int> &vec, vector<int> &candidates,
            int target)
{
    // If we have considered all candidates,
    // check whether we have reached the target.
    if (index == candidates.size())
    {
        // target == 0 means the current vector
        // is a valid combination.
        if (target == 0)
        {
            sol.push_back(vec);
        }

        // No more candidates to consider.
        return;
    }

    // TAKE the current candidate only if it
    // does not make the target negative.
    if (candidates[index] <= target)
    {
        // Add the current candidate to the combination.
        vec.push_back(candidates[index]);

        // Keep the same index because the current
        // candidate can be used multiple times.
        helper(sol, index, vec, candidates,
               target - candidates[index]);

        // BACKTRACK: remove the candidate so we can
        // explore other possible combinations.
        vec.pop_back();
    }

    // SKIP the current candidate and move
    // to the next candidate.
    helper(sol, index + 1, vec, candidates, target);
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> sol;
    vector<int> vec;

    // Start recursion from index 0 with an
    // empty combination and the original target.
    helper(sol, 0, vec, candidates, target);

    // Return all valid combinations.
    return sol;
}
int main()
{

    return 0;
}