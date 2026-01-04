#include <iostream>
using namespace std;

int gcd(int a , int b){
    if (b==0){
        return a;
    }
    return gcd(b , a%b );
}

int main() {
    int a;
    int b;
    cout<<"Enter first number :";
    cin>>a;
    cout<<"Enter second number :";
    cin>>b;
    cout<<endl;

    cout<<"Greater Common Divisor :";
    cout<<gcd(a , b)<<endl;

}