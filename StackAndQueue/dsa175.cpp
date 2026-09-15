#include <bits/stdc++.h>
using namespace std;
int optimalLargestRectangleArea(vector<int> &heights)
{
    int n = heights.size();
    vector<int> pse(n);
    stack<int> psest;
    int maxArea = 0;
    for (int i = 0; i < n; i++)
    {
        while (!psest.empty() && heights[psest.top()] >= heights[i])
        {
            maxArea = max(maxArea, (((psest.top() - pse[psest.top()]) + (i - psest.top()) - 1) * heights[psest.top()]));
            psest.pop();
        }
        pse[i] = psest.empty() ? -1 : psest.top();
        psest.push(i);
    }
    while (!psest.empty())
    {
        int x = psest.top();
        psest.pop();
        int y = psest.empty() ? -1 : psest.top();
        maxArea = max(maxArea, (((x - y) + (n - x) - 1) * heights[x]));
    }
    return maxArea;
}
int maximalRectangle(vector<vector<char>> &matrix)
{
    vector<vector<int>> work(matrix.size(), vector<int>(matrix[0].size()));
    for (int j = 0; j < matrix[0].size(); j++)
    {
        int cnt = 0;
        for (int i = 0; i < matrix.size(); i++)
        {
            if (matrix[i][j] == '0')
            {
                cnt = 0;
                continue;
            }
            cnt++;
            work[i][j] = cnt;
        }
    }
    int maxArea = 0;
    for (int i = 0; i < matrix.size(); i++)
    {
        maxArea = max(maxArea, optimalLargestRectangleArea(work[i]));
    }
    return maxArea;
}
int main()
{

    return 0;
}