#include<iostream>
using namespace std;

char toLowerCase(char ch){
    if((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
        return ch;
    else{
        return ch - 'A' + 'a';
    }
}

int getLength(char arr[]){
    int size = 0;
    for(int i=0 ; arr[i]!='\0' ; i++){
        size++;
    }
    return size;
}

void reverse(char arr[] , int size){
    int s = 0;
    int e = size - 1;

    while (s<e){
        swap(arr[s++],arr[e--]);
    }
}

bool is_palindrome(char arr[] , int size){
    int start = 0;
    int end = size-1;

    while(start <= end){
        if(toLowerCase(arr[start++]) != toLowerCase(arr[end--])){
            return 0;
        }
    }
    return 1;
}

int printArr(int arr[], int size){
    for(int i=0 ; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    char arr[10];
    cout<<"enter char :";
    cin>>arr;

    cout<<"Output :";
    cout<<arr<<endl;

    cout<<"size :";
    int len = getLength(arr);
    cout<<len<<endl;

    reverse(arr,len);
    cout<<"reverse :"<<arr<<endl;

    cout<<"Check Palindrome :";
    cout<<is_palindrome(arr,len)<<endl;

    return 0;
}