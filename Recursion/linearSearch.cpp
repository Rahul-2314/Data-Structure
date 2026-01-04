#include<iostream>
using namespace std;

int linearSearch(int arr[], int size, int key){
    // base case
    if(size==0) return false;
    if(size==1) return arr[0]==key;

    if(arr[0]==key) return true;

    // recursive relation
    return linearSearch(arr+1, size-1, key);
}

int main(){
    int size = 5;
    int arr[size] = {1,2,3,4,5};
    int key = 5;
    
    bool sol = linearSearch(arr, size, key);
    cout<<"Found :"<<sol<<endl;

    return 0;
}