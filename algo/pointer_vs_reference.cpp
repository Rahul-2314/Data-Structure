#include <iostream>
using namespace std;

void b(int &i);

void a(int *i){
    char ch = 'a';
    cout<<*i<<ch<<endl<<i<<endl;
    b(*i);
}

void b(int& i){
    cout<<i<<endl<<i<<endl;
    // a(i);
}

int main(){
    int i = 5;
    a(&i);
}