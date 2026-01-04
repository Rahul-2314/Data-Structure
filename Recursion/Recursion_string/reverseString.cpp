#include<iostream>
using namespace std;

void reverse(string &str, int i, int j){
    // base case
    if(i > j) return ;

    swap(str[i], str[j]);
    i++;
    j--;
    
    // recursive relation
    reverse(str, i, j);
}

int main(){
    string name = "rahul";
    cout<<"Name is :"<<name<<endl;

    int i = 0;
    int j = name.length()-1;

    reverse(name, i, j);
    cout<<"Name is (reverse):"<<name<<endl;

    return 0;
}