#include <iostream>
using namespace std;

int twotopower(int n){
    if(n==0)
        return 1;
    else
        return 2 * twotopower(n-1);
}

int main(){
    int n;
    cout<<"Enter twotopower :";
    cin>>n;
    int sol = twotopower(n);
    cout<<"Result :"<<sol<<endl;

    return 0;
}