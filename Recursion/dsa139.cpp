#include <bits/stdc++.h>
using namespace std;
bool ispossible(int row, int col, vector<string> &board, int n)
{
    int duprow = row;
    int dupcol = col;
    while (row >= 0 && col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        row--;
        col--;
    }
    row = duprow;
    col = dupcol;
    while (col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        col--;
    }
    row = duprow;
    col = dupcol;
    while (row < n && col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        row++;
        col--;
    }
    return true;
}
void helper(int col, vector<string> &board, vector<vector<string>> &sets, int n)
{
    if (col == n)
    {
        sets.push_back(board);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (ispossible(row, col, board, n))
        {

            board[row][col] = 'Q';
            helper(col + 1, board, sets, n);
            board[row][col] = '.';
        }
    }
}
vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> sets;
    vector<string> board;
    string s(n, '.');
    for (int i = 0; i < n; i++)
    {
        board.push_back(s);
    }
    helper(0, board, sets, n);
    return sets;
}









void helper(int col, vector<string> &board, vector<vector<string>> &sets, int n,vector<int>&leftrow,vector<int>&lowerdigonal,vector<int>&upperdiognal)
{
    if (col == n)
    {
        sets.push_back(board);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (!leftrow[row]&&!upperdiognal[row]&&!lowerdigonal[row])
        {

            board[row][col] = 'Q';

            leftrow[row]=1;
            lowerdigonal[row+col]=1;
            upperdiognal[n-1+col-row]=1;

            helper(col + 1, board, sets, n);
            board[row][col] = '.';

            leftrow[row]=0;
            lowerdigonal[row+col]=0;
            upperdiognal[n-1+col-row]=0;
        }
    }
}
vector<vector<string>> solveNQueensWithoutIspossibleOptimal(int n)
{
    vector<vector<string>> sets;
    vector<string> board;
    vector<int>leftrow(n,0),lowerdigonal(2*n-1,0),upperdiognal(2*n-1,0);
    string s(n, '.');
    for (int i = 0; i < n; i++)
    {
        board.push_back(s);
    }

    helper(0, board, sets, n,leftrow,lowerdigonal,upperdiognal);
    return sets;
}
int main()
{

    return 0;
}