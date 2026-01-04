#include <iostream>
using namespace std;

int power(int num, int pow){
    // base case
    if(pow == 0) return 1;
    if(pow == 1) return num;

    // recursive realtion  [fast exponentiation]
    int rel = power(num, pow/2);

    if(pow%2 == 0) return rel*rel;  //sol = (a^b/2)*(a^b/2) [even power];
    else return num*rel*rel;  //sol = a*(a^b/2)*(a^b/2) [odd power];
}

int main(){
    int num,pow;
    cout<<"Enter number :";
    cin>>num;
    cout<<"Enter power :";
    cin>>pow;

    int sol = power(num, pow);

    cout<<endl<<"Answer :"<<sol<<endl;

    return 0;
}