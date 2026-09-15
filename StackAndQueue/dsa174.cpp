#include <bits/stdc++.h>
using namespace std;
// This is better sol bro
int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();
    vector<int> pse(n);
    vector<int> nse(n);
    stack<int> psest;
    stack<int> nsest;
    for (int i = 0; i < n; i++)
    {
        while (!psest.empty() && heights[psest.top()] >= heights[i])
            psest.pop();
        pse[i] = psest.empty() ? -1 : psest.top();
        psest.push(i);

        while (!nsest.empty() && heights[nsest.top()] >= heights[n - i - 1])
            nsest.pop();
        nse[n - i - 1] = nsest.empty() ? n : nsest.top();
        nsest.push(n - i - 1);
    }

    int maxArea = 0;
    for (int i = 0; i < n; i++)
    {
        maxArea = max(maxArea, (((i - pse[i]) + (nse[i] - i) - 1) * heights[i]));
    }
    return maxArea;
}
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

int main()
{

    return 0;
}