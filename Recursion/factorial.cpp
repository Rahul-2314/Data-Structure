#include <iostream>
using namespace std;

int factorial(int n){
    if(n==0 || n==1)
        return 1;
    else
        return n * factorial(n-1);
}

int main(){
    int n;
    cout<<"Enter Number :";
    cin>>n;
    int sol = factorial(n);
    cout<<"Factorial Result :"<<sol<<endl;

    return 0;
}

// time complexity - O(n)
// space complexity - O(n)