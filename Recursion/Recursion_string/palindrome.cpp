#include <iostream>
using namespace std;

bool checkPalindrome(string str, int i, int j){
    // base case
    if(i > j) return true; //if i>j then all previous cases are true 

    // recursive relation
    if(str[i] != str[j]) return false;
    else return checkPalindrome(str, i+1, j-1);

}

int main(){
    string str = "rahul";

    int i = 0;
    int j = str.length()-1;

    cout<<"Palindrome :"<<checkPalindrome(str, i, j)<<endl;

    return 0;
}