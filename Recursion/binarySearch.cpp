// #include <iostream>
#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int start, int end, int key){
    int mid = start + (end - start) / 2;

    // base case
    if(arr[mid]==key) return mid;  //element found
    if(start > end) return -1;     //element not found

    // recursive relation
    if(arr[mid]>key) return binarySearch(arr, 0, mid-1, key);
    return binarySearch(arr, mid+1, end, key);
}

int main(){
    int size = 5;
    int arr[size] = {0,1,2,3,4};
    int key = 5;

    int sol = binarySearch(arr, 0, size-1, key);
    cout<<"Found(index) :"<<sol<<endl;

    return 0;
}

// time complexity - O(log n)
// space complexity - O(log n)