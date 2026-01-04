#include <iostream>
using namespace std;

bool isSorted(int arr[], int size){
    // base case
    if(size==0||size==1) return true;
    if(arr[0]>arr[1]) return false;

    // recursive relation
    return isSorted(arr+1, size-1);
}

int main(){
    int size = 5;
    int arr[size] = {1,2,3,4,5};
    bool sol = isSorted(arr, size);
    cout<<"Sorted :"<<sol<<endl;

    return 0;
}