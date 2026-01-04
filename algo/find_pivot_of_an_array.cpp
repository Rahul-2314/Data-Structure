#include<iostream>
using namespace std;

void printArray(int arr[],int n){
  for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

int getPivot(int arr[],int n){
  int s = 0;
  int e = n-1;
  int mid = s+ (e-s)/2;
  while(s<e){
    if(arr[mid]>=arr[0]){
      s = mid+1;
    }
    else{
      e = mid;
    }
    mid = s + (e-s)/2;
  }
  return s;
}

int main(){
  int arr[5]={7,9,1,2,3};
  cout<<"Array :";
  printArray(arr,5);
  int pivot = getPivot(arr,5);
  cout<<"Pivot Element's Index :"<<pivot<<endl;
  int pivot_element = arr[pivot];
  cout<<"Pivot Element :"<<pivot_element<<endl;

  return 0;
}