#include<iostream>
#include<algorithm>
using namespace std;

void print_array(int arr[], int size) {
  for(int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }
  cout<<endl;
}

void selection_sort(int arr[],int n){
  for(int i = 0 ; i < n-1 ; i++){
    int minIndex = i;

    for(int j = i+1 ; j < n ; j++){
      if(arr[j] < arr[minIndex])
        minIndex = j;
    }
    swap(arr[minIndex] , arr[i]);
  }
}

int main() {
  int arr[5]={64,25,12,22,11};
  int n=5;
  cout<<"Original Array : ";
  print_array(arr, n);

  selection_sort(arr,n);
  
  cout<<"Sorted Array : ";
  print_array(arr, n);
}