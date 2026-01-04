#include<iostream>
using namespace std;

void intersection_element(int arr1[],int arr2[],int len1,int len2){
  bool intersection_found = false;
  for(int i=0;i<len1;i++){
    for(int j=0;j<len2;j++){
      if(arr1[i]==arr2[j]){
        cout<<arr1[i]<<" ";
        intersection_found=true;
        break;
      }
    }
  }
  if(!intersection_found){
    cout<<-1<<endl;
  }
}

void printArr(int arr[], int size) {
  for (int i=0;i<size;i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

int main(){
  int arr1[5]={1,2,3,4,5};
  int arr2[5]={4,5,6,7,8};

  int len1 = sizeof(arr1)/sizeof(arr1[0]);
  int len2 = sizeof(arr2)/sizeof(arr2[0]);

  cout<<"arr1 :"<<" ";
  printArr(arr1,5);
  cout<<"arr2 :"<<" ";
  printArr(arr2,5);
  cout<<"intersection elements :"<<" ";
  intersection_element(arr1,arr2,len1,len2);
  cout<<endl;
  
  return 0;
}