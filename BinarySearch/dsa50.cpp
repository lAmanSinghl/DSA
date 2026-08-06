#include <bits/stdc++.h>
using namespace std;

double minMaxDist(vector<int> &stations, int k)
{
    if(stations.size()==1)return 0;
    int n = stations.size();
    vector<int> howMany(n - 1, 0);
    for (int gasStations = 1; gasStations <= k; gasStations++)
    {
        long double maxSection = -1;
        int maxInd = -1;
        for (int i = 0; i < n - 1; i++)
        {
            long double diff = stations[i + 1] - stations[i];
            long double sectionLength = diff / (long double)(howMany[i] + 1);
            if (maxSection < sectionLength)
            {
                maxSection = sectionLength;
                maxInd = i;
            }
        }
        howMany[maxInd]++;
    }
    long double ans=-1;
    for(int i=0;i<n-1;i++){
        long double dif= stations[i + 1] - stations[i];
        long double sectionLen=(dif / (long double)(howMany[i] + 1));
        ans=max(ans,sectionLen);
    }
    return ans;
}
double minMaxDistUsingPriorityQueue(vector<int> &stations, int k)
{
    if(stations.size()==1)return 0;
    int n = stations.size();
    vector<int> howMany(n - 1, 0);
    priority_queue <pair<long double,int>> pq;
    for(int i=0;i<n-1;i++){
        pq.emplace(stations[i+1] - stations[i], i);;
    }
    for (int gasStations = 1; gasStations <= k; gasStations++)
    {
        auto tp=pq.top();
        pq.pop();
        int sectionInd=tp.second;
        howMany[sectionInd]++;
        long double diff=stations[sectionInd+1]-stations[sectionInd];
        long double newsectionLen=diff/(long double)(howMany[sectionInd]+1);
        pq.push({newsectionLen,sectionInd});
    }

    return pq.top().first;
}


int numberOfGasStationsRequired(vector <int> stations,long double k){
    int n=stations.size();
    int cnt=0;
    for(int i=0;i<n-1;i++){
        int numberOfInBetween=(stations[i+1]-stations[i])/k;
        if((stations[i+1]-stations[i])/k==numberOfInBetween*k){
            numberOfInBetween--;
        }
        cnt+=numberOfInBetween;
    }
    return cnt;

}

double minMaxDistUsingBinarySearch(vector<int> &stations, int k)
{
    int n=stations.size();
    long double low=0,high=0;
    for(int i=0;i<n-1;i++){
        high=max(high,(long double)(stations[i+1]-stations[i]));
    }
    long double diff=1e-6;
    while(high-low>diff){
        long double mid=(high+low)/2.0;
        int cnt=numberOfGasStationsRequired(stations,mid);
        if(cnt>k){
            low=mid;
        }else{
            high=mid;
        }
    }
    return high;
}

int main()
{
    int n;
    cin >> n;

    vector<int> stations(n);
    for (int i = 0; i < n; i++)
    {
        cin >> stations[i];
    }

    int k;
    cin >> k;

    cout << fixed << setprecision(6) << minMaxDist(stations, k);

    return 0;
}