#include <iostream>
using namespace std;

void printArr(int arr[], int size){
    cout<<"Array is : ";
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl<<endl;
}

void inputArr(int arr[], int size){
    cout<<"Enter Array : ";
    for(int i=0; i<size; i++){
        cin>>arr[i];
    }
}

void sort(int arr[], int size){
    // base case
    if(size == 0 || size == 1) return ;

    // One case(round) solve
    for(int i=0; i<size-1; i++){
        if(arr[i]>arr[i+1]) swap(arr[i], arr[i+1]);
    }

    // recursive relation
    sort(arr, size-1);
}

int main(){
    int size;
    cout<<"Enter Size :";
    cin>>size;

    int arr[size];
    inputArr(arr,size);
    printArr(arr,size);
   
    sort(arr, size);
    cout<<"Sorting Array using bubbleSortRecursion ....."<<endl<<endl;
    printArr(arr,size);

    return 0;
}