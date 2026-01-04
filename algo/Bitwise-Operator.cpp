#include <iostream>
using namespace std;

int main(){
  
  int a=4;
  int b=6;

  cout<<"a&b :" <<(a&b)<<endl;
  cout<<"a|b :" <<(a|b) <<endl;
  cout<<" ~a :" << ~a <<endl;
  cout<<"a^b :" <<(a^b) <<endl;
  cout<<"a<<2 :" <<(a<<2) <<endl;
  cout<<"a>>2 :" <<(a>>2) <<endl;
  cout<<endl;
  
  cout<<(a++)<<endl; // return 4, then increment
  cout<<(++a)<<endl; // increment then return 6
  cout<<(a--)<<endl; // return 6, then decrement
  cout<<(--a)<<endl; // decrement then return 4


  return 0;
}