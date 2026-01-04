#include<iostream>
using namespace std;

int main() {
  int n;
  cout<<"enter number :";
  cin>>n;
  
  long long sum =0;
  
  if(n<=0){
    cout<<"Enter valid number :"<<endl;
  }else if (n==1){
    cout<<"0"<<endl;
  }else{
    long long a=0;
    long long b=1;
    
    cout<<a<<" "<<b<<" ";
    sum=a+b;
    for(int i=1;i<=n-2;i++){
      long long nextnumber=a+b;
      cout<<nextnumber<<" ";
      sum+=nextnumber;
      a=b;
      b=nextnumber;
    }
    cout<<endl;
  }
  cout<<"Sum :"<<sum<<endl;
}