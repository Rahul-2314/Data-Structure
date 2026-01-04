#include<iostream>
using namespace std;

int main(){
  int n;
  cout<<"Enter Number for Prime check :";
  cin>>n;
  if(n<=1){
    cout<<"Result :"<<"Not Prime";
    return 0;
  }
  else if(n==2){
    cout<<"Result :"<<"Prime";
    return 0;
  }
  else{
    for(int i=2;i<n;i++){
      if(n%i==0){
        cout<<"Result : "<<"Not Prime";
        break;
        return 0;
      }
      else{
        cout<<"Result : "<<"Prime";
        return 0;
      }
    }
  }
}