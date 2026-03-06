#include <bits/stdc++.h>
using namespace std;

void TimeOptimizedRotate(int arr[], int n, int d){
    // takes n+d space->n+d(d extra space then the arrray)
    d = d % n;
    int temp[d];
    for (int i = 0; i < d; i++)
    {
        temp[i] = arr[n - d + i];
    }
    for (int i = n - d - 1; i >= 0; i--)
    {
        cout << arr[i] << " " << arr[i + d] << endl;
        arr[i + d] = arr[i];
    }
    for (int i = 0; i < d; i++)
    {
        arr[i] = temp[i];
    }
}

void Reverse(int arr[], int start, int end){
    while (start <= end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}
void spaceOptimizedRotate(int arr[], int n, int d){
    // time->2n space->n(no extra space then array)
    Reverse(arr, 0, n);
    Reverse(arr, 0, d - 1);
    reverse(arr + d, arr + n); // reverse already exist in c++ stl
}

void moveZeroes(int arr[],int n){
    int j=-1;
    for(int i=0;i<n;i++){
      if(arr[i]==0){
        j=i;
        break;
      }
    }
    if(j==-1)return;
    for(int i=j+1;i<n;i++){
        if(arr[i]!=0){
            swap(arr[i],arr[j]);
            j++;
        }
    }
}

vector<int> UnionSortedArray(int arr1[],int n1,int arr2 [],int n2){
   int i=0;
   int j=0;
   vector<int> a;
   
   while(i<n1&&j<n2){
    if(arr1[i]<arr2[j]){

        if(a.empty()||arr1[i]!=a.back()){
       a.emplace_back(arr1[i]);
    }
       i++;
    }
    if(arr1[i]>arr2[j]){
        if(a.empty()||arr2[j]!=a.back()){
            a.emplace_back(arr2[j]);
        }
        j++;
    }
    if(arr1[i]==arr2[j]){
        if(a.empty()||arr2[j]!=a.back()){
            a.emplace_back(arr2[j]);
        }
        i++;
        j++;
    }
   }
   if(!a.empty()){

       while(i<n1){
           if(a.empty()||arr1[i]!=a.back()){
               a.emplace_back(arr1[i]);
            }
            i++;
        }
        
        while(j<n2){
            if(a.empty()||arr2[j]!=a.back()){
                a.emplace_back(arr2[j]);
            }
            j++;
        }
        
    }
   return a;
}

vector<int> IntersectionSortedArray(int arr1[],int n1,int arr2 [],int n2){
    int i=0;
    int j=0;
    vector <int>a;
    while(i<n1&&j<n2){
        if(arr1[i]<arr2[j]){
            i++;
        }else if(arr1[i]>arr2[j]){
            j++;
        }else{
            a.push_back(arr1[i]);
            i++;
            j++;
        }
    }

    return a;
}
int main()
{
    int n1;
    cin >> n1;
    int arr1[n1];
    for (int i = 0; i < n1; i++)
    {
        cin >> arr1[i];
    }
        int n2;
    cin >> n2;
    int arr2[n2];
    for (int i = 0; i < n2; i++)
    {
        cin >> arr2[i];
    }


    // int d;
    // cin >> d;
    // TimeOptimizedRotate(arr,n,d);
    // spaceOptimizedRotate(arr, n, d);


    // moveZeroes(arr1,n1);

    // for (int i = 0; i < n1; i++)
    // {
    //     cout << arr1[i] << " ";
    // }
    // cout<<endl;


    // vector<int> a=UnionSortedArray(arr1,n1,arr2,n2);
    vector<int> a=IntersectionSortedArray(arr1,n1,arr2,n2);
    for(int i:a){
        cout<<i<<" ";
    }


}