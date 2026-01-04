// Question : 123 --> One Two Three
#include <iostream>
using namespace std;

void sayDigits(int n, string arr[]){
    // base case
    if(n==0) return ;

    // processing
    int digit = n % 10;
    n /= 10;

    // recursive relation call
    sayDigits(n,arr);

    cout<<arr[digit]<<" ";
}

int main(){
    int num;
    cout<<"Enter Number :";
    cin>>num;

    string arr[10] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};

    sayDigits(num,arr);

    return 0;
}