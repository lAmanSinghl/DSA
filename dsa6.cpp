#include <bits/stdc++.h>
using namespace std;

void selection_sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i; j < n; j++)
        {

            if (arr[min] > arr[j])
            {
                min = j;
            }
        }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

void bubble_sort(int arr[], int n)
{
    for (int i = n - 1; i >= 1; i--)
    {
        int didswap = 0;
        for (int j = 0; j <= i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                didswap = 1;
            }
        }
        if (!didswap)
        {
            break;
        }
    }
}

void insertion_sort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = i; j > 0 && (arr[j - 1] > arr[j]); j--)
        {
            cout << "swapping:" << arr[j] << " " << arr[j - 1] << endl;
            int temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
        }
    }
}

void merge(int arr[], int start, int mid, int end)
{
 int sorted[end-start+1];
 int i=start;
 int j=mid+1;
 int k=0;
 while(i<=mid&&j<=end){
    if(arr[i]<=arr[j]){
        sorted[k]=arr[i];
        i++;
        k++;
    }else{
        sorted[k]=arr[j];
        j++;
        k++;
    }
 }
 while(j<=end){
        sorted[k]=arr[j];
        j++;
        k++;    
    }
 while(i<=mid){
        sorted[k]=arr[i];
        i++;
        k++;
 }
 for(int i=start;i<=end;i++){
    arr[i]=sorted[i-start];
 }

}

void merge_sort(int arr[], int start, int end)
{
    if (start >= end)
        return;
    int mid = (start + end) / 2;
    merge_sort(arr, start, mid);
    merge_sort(arr, mid + 1, end);
    merge(arr, start, mid, end);
}

int pivot_position(int arr[],int start,int end){
    int pivot=arr[start];
    int i=start;
    int j=end;
    while(j>i){
       while(arr[i]<=pivot){
        i++;
       }
       while(arr[j]>pivot){
        j--;
       }
       if(j>i){
        int temp=arr[j];
        arr[j]=arr[i];
        arr[i]=temp;
       }
    }
        arr[start]=arr[j];
        arr[j]=pivot; 
        return j;  
}

void quick_sort(int arr[],int start,int end){
    if(start>end)return;
      int pivot=arr[end];
      int q=pivot_position(arr,start,end);
      quick_sort(arr,start,q-1);
      quick_sort(arr,q+1,end); 
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // selection_sort(arr,n);
    // bubble_sort(arr,n);
    // insertion_sort(arr,n);
    // merge_sort(arr, 0, n - 1);
    quick_sort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}