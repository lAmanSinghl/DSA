#include <bits/stdc++.h>
using namespace std;
//Striver Cleaner helper
bool dfs(vector<vector<char>> &board, string &word, int i, int j, int idx)
{
    // If all characters matched, return true
    if (idx == word.size())
        return true;

    // Check boundaries and character match
    if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[idx])
    {
        return false;
    }

    // Store current character and mark as visited
    char temp = board[i][j];
    board[i][j] = '#';

    // Explore all four directions
    bool found = dfs(board, word, i + 1, j, idx + 1) ||
                 dfs(board, word, i - 1, j, idx + 1) ||
                 dfs(board, word, i, j + 1, idx + 1) ||
                 dfs(board, word, i, j - 1, idx + 1);

    // Restore the character (backtracking)
    board[i][j] = temp;

    return found;
}
bool helper(int index, int i, int j, vector<vector<char>> &board, string word)
{
    if (index == word.size() - 1)
    {
        return true;
    }
    board[i][j] = '-1';
    if (j + 1 < board[0].size() && board[i][j + 1] == word[index + 1])
    {
        if (helper(index + 1, i, j + 1, board, word))
            return true;
    }
    if (i + 1 < board.size() && board[i + 1][j] == word[index + 1])
    {
        if (helper(index + 1, i + 1, j, board, word))
            return true;
    }
    if (j - 1 >= 0 && board[i][j - 1] == word[index + 1])
    {
        if (helper(index + 1, i, j - 1, board, word))
            return true;
    }
    if (i - 1 >= 0 && board[i - 1][j] == word[index + 1])
    {
        if (helper(index + 1, i - 1, j, board, word))
            return true;
    }
    board[i][j] = word[index];
    return false;
}
bool exist(vector<vector<char>> &board, string word)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (board[i][j] == word[0])
            {
                if (helper(0, i, j, board, word))
                    return true;
            }
        }
    }
    return false;
}
int main()
{

    return 0;
}