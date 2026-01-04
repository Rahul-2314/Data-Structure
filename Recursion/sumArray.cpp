// #include <iostream>
#include <bits/stdc++.h>  //slow
using namespace std;

int sumArray(int arr[], int size){
    // base case
    if(size==0) return 0;
    if(size==1) return arr[0];

    // recursive relation
    return arr[0] + sumArray(arr+1, size-1);
}

int main(){
    int size = 5;
    int arr[size] = {1,2,3,4,5};
    int sol = sumArray(arr, size);
    cout<<"Sum is :"<<sol<<endl;

    return 0;
}