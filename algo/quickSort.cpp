#include<bits/stdc++.h>
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

void quickSort(int arr[], int low, int high){
    int i, j, pivot;
    if(low<high){
        i = low;
        j = high;
        pivot = low;
        
        while(i<j){
            while(arr[i]<=arr[pivot] && i<high)
                i++;
            while(arr[j]>arr[pivot])
                j--;
            
            if(i<j)
                swap(arr[i], arr[j]);
        }
        swap(arr[j], arr[pivot]);
        quickSort(arr, low, j-1);
        quickSort(arr, j+1, high);

    }
}

int main(){
    int size;
    cout<<"Enter Size :";
    cin>>size;

    int arr[size];
    inputArr(arr,size);
    printArr(arr,size);

    int low = 0;
    int high = size-1;
   
    quickSort(arr, low, high);
    cout<<"Sorting Array using quickSort ....."<<endl<<endl;
    printArr(arr,size);

    return 0;
}