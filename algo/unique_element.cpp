#include<iostream>
using namespace std;

void unique_element(int arr[], int n){
  int ans = 0;
  for(int i = 0; i < n; i++){
    ans = ans ^ arr[i];
  }
  cout << ans << endl;
}

void printArr(int arr[], int size) {
  for (int i=0;i<size;i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

int main(){
  int arr[10]={1,2,3,4,5,2,3,4,};
  unique_element(arr, 10);
  printArr(arr,10);
}