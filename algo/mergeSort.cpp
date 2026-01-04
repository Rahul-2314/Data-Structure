#include <iostream>
using namespace std;

void printArr(int arr[], int size);
void inputArr(int arr[], int size);

void merge(int arr[], int low, int mid, int high){
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int left[n1], right[n2];

    // store array in two temporary arrays
    for(int i=0 ; i<n1; i++) left[i]=arr[low +i];
    for(int j=0; j<n2; j++) right[j]=arr[mid + 1 +j];

    // merge two sorted arrays
    int i=0, j=0, k=low;
    while(i < n1 && j < n2) {
        if(left[i] <= right[j]) arr[k++] = left[i++];
        else arr[k++] = right[j++];
    }

    // merge remaining elements
    while(i < n1) arr[k++] = left[i++];
    while(j < n2) arr[k++] = right[j++];
}

void mergeSort(int arr[], int low, int high){
    if(low >= high) return;

    int mid = low + (high - low) / 2;

    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
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
   
    mergeSort(arr, low, high);
    cout<<"Sorting Array using mergeSort ....."<<endl<<endl;
    printArr(arr,size);

    return 0;
}

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

// time complexity - O(n log n)
// space complexity - O(n)