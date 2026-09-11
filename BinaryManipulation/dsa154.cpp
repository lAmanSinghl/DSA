#include <bits/stdc++.h>
using namespace std;
int minBitFlips(int start, int goal)
{
    int gsxor=start^goal;
    int cnt=0;
    while(gsxor!=0){
        gsxor=gsxor&(gsxor-1);
        cnt++;
    }
    return cnt;
}
int main()
{

    return 0;
}