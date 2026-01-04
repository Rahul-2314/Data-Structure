#include<iostream>
using namespace std;

int main(){
  int a,b;
  cout<<"enter the value of a :";
  cin>>a;
  cout<<endl;
  cout<<"enter the value of b :";
  cin>>b;
  cout<<endl;
  char op;
  cout<<"enter the operation you want to perform :";
  cin>>op;
  cout<<endl;

  switch(op){
    case '+': cout<<"Ans :"<<(a+b)<<endl;
    break;
    case '-': cout<<"Ans :"<<(a-b)<<endl;
    break;
    case '*': cout<<"Ans :"<<(a*b)<<endl;
    break;
    case '/': cout<<"Ans :"<<(a/b)<<endl;
    break;
    case '%': cout<<"Ans :"<<(a%b)<<endl;
    break;
    default: cout<<"please enter a valid operation"<<endl;
  }

  return 0;
}
