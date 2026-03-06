#include <bits/stdc++.h>
using namespace std;

int findSecondelarget(int arr[],int n){
    int largest=arr[0];
    int secondelargest=INT_MIN;
   for(int i=0;i<n;i++){
    if(arr[i]>largest){
        secondelargest=largest;
        largest=arr[i];
    }else if(arr[i]>secondelargest&&arr[i]<largest){
        secondelargest=arr[i];
    }
   }
   return secondelargest;
}

int findSecondeSmallest(int arr[],int n){
    int Smallest=arr[0];
    int secondeSmallest=INT_MIN;
   for(int i=0;i<n;i++){
    if(arr[i]<Smallest){
        secondeSmallest=Smallest;
        Smallest=arr[i];
    }else if(arr[i]<secondeSmallest&&arr[i]>Smallest){
        secondeSmallest=arr[i];
    }
   }
   return secondeSmallest;
}

int removeDuplicates(int arr[],int n){
    int j=0;
    for(int i=0;i<n;i++){
      if(arr[i]!=arr[j]){
        swap(arr[i],arr[j+1]);
        j++;
      }
    }
    return j;
}
int main(){
   int n;
   cin>>n;
   int arr[n];
   for(int i=0;i<n;i++){
    cin>>arr[i];
   }
//    cout<<findSecondelarget(arr,n)<<endl;
//    cout<<findSecondeSmallest(arr,n);
      int k=removeDuplicates(arr,n);
      for(int i=0;i<=k;i++){
        cout<<arr[i]<<" ";
      }
      

}