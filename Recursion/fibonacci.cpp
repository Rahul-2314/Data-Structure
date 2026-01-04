#include <iostream>
using namespace std;

int fibonacci(int n){
    if(n == 0 || n == 1) return n;
    return fibonacci(n-1) + fibonacci(n-2);
}

int main(){
    int num;
    cout<<"Enter number :";
    cin>>num;
    cout<<num<<"th "<<"Fibonacci number is :"<<fibonacci(num-1)<<endl;

    return 0;
}

// time complexity - O(2^n)
// space complexity - O(n)