#include <bits/stdc++.h>
using namespace std;
void helper(int i, int j, string &s, vector<string> &sol, int n, vector<vector<int>> &maze)
{
    if (i == n - 1 && j == n - 1)
    {
        sol.push_back(s);
        return;
    }
    
    if (i + 1 < n && maze[i + 1][j] == 1)
    {
        s.push_back('D');
        helper(i + 1, j, s, sol, n, maze);
        s.pop_back();
        maze[i][j] = 1;
    }
    if (j - 1 >= 0 && maze[i][j - 1] == 1)
    {
        maze[i][j] = 0;
        s.push_back('L');
        helper(i, j - 1, s, sol, n, maze);
        s.pop_back();
        maze[i][j] = 1;
    }

    if (j + 1 < n && maze[i][j + 1] == 1)
    {
        maze[i][j] = 0;
        s.push_back('R');
        helper(i, j + 1, s, sol, n, maze);
        s.pop_back();
        maze[i][j] = 1;
    }

    if (i - 1 >= 0 && maze[i - 1][j] == 1)
    {
        maze[i][j] = 0;
        s.push_back('U');
        helper(i - 1, j, s, sol, n, maze);
        s.pop_back();
        maze[i][j] = 1;
    }
}
vector<string> ratInMaze(vector<vector<int>> &maze)
{
    vector<string> sol;
    if (maze.empty() || maze[0][0] == 0)
        return sol;
    string s;
    int n = maze.size();
    helper(0, 0, s, sol, n, maze);
    return sol;
}
int main()
{

    return 0;
}