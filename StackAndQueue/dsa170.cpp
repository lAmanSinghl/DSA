#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int trap(vector<int> &height)
    {

        int l = 0, r = height.size() - 1;

        int lmax = -1, rmax = -1;
        int trappedWater = 0;

        while (l <= r)
        {

            // We choose the side with the smaller height
            // because that side decides how much water can be trapped.
            if (height[l] <= height[r])
            {

                // Update the maximum height seen from the left
                lmax = max(lmax, height[l]);

                // If current height is smaller than lmax,
                // the difference is the water trapped here.
                trappedWater += lmax - height[l];

                // Move left because we have already handled this position
                l++;
            }
            else
            {

                // We choose right because right height is smaller.
                // Update the maximum height seen from the right.
                rmax = max(rmax, height[r]);

                // Difference between right maximum and current height
                // is the water trapped at this position.
                trappedWater += rmax - height[r];

                // Move right because we have already handled this position
                r--;
            }
        }

        return trappedWater;
    }
};
int main()
{

    return 0;
}