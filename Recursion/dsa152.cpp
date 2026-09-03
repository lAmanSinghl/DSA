#include <bits/stdc++.h>
using namespace std;

bool ispossible(int index, string &s, string &s2)
{
    // If the word is longer than the remaining part of s,
    // it cannot possibly fit.
    if (s2.size() > s.size() - index)
        return false;

    // Check whether s2 matches s starting from index.
    for (int i = index; i < s2.size() + index; i++)
    {
        if (s[i] != s2[i - index])
            return false;
    }

    return true;
}

bool helper(int index, string &s, vector<string> &wordDict,
            vector<bool> &visitedAndFailed)
{
    // We have consumed the entire string.
    // Therefore, a valid word break has been found.
    if (index == s.size())
    {
        return true;
    }

    // Try every dictionary word from the current index.
    for (int i = 0; i < wordDict.size(); i++)
    {
        /*
            IMPORTANT RECURSION IDEA:

            At this point, we are asking:

                "Can I successfully break s starting from index?"

            If a dictionary word matches here, we move forward
            by the length of that word and recursively ask the
            exact same question from the new index.
        */

        if (ispossible(index, s, wordDict[i]) && !visitedAndFailed[index])
        {
            if (helper(index + wordDict[i].size(),
                       s, wordDict, visitedAndFailed))
            {
                // A deeper recursive call succeeded.
                // Its true propagates all the way back to the root.
                return true;
            }

            /*
                If helper() returned false:

                "This particular choice didn't work."

                We DON'T stop here.
                We simply continue the loop and try another
                dictionary word.

                false from an intermediate call basically means:
                "This path failed, go back and try another path."
            */
        }
    }

    /*
        BACKTRACKING / MEMOIZATION IDEA:

        We have now tried EVERY possible dictionary word
        starting from this index, and none of them worked.

        Therefore:

            helper(index) == false

        We remember that result so that if another recursive
        path reaches this same index later, we don't repeat
        all the work.

        Notice that we mark it ONLY AFTER trying everything.

        We cannot mark it at the beginning because we haven't
        yet determined that this index is impossible.
    */
    visitedAndFailed[index] = true;

    return false;
}

bool wordBreak(string s, vector<string> &wordDict)
{
    // visited[index] means:
    //
    // "We already completely explored the possibility of
    //  breaking the string starting from this index, and it failed."
    //
    // We only need to remember failed indices.
    //
    // Why don't we need to store successful indices?
    //
    // Because the moment ANY recursive path succeeds, true
    // propagates all the way back and the entire recursion ends.

    vector<bool> visitedAndFailed(s.size(), false);

    return helper(0, s, wordDict, visitedAndFailed);
}

int main()
{
    return 0;
}