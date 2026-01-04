// dynamic memory allocation of 2D array
#include <iostream>
using namespace std;

int main(){
    int row,col;
    cout<<"enter row and col:";
    cin>>row>>col;
    
    // allocate
    int **arr = new int*[row];
    
    // create array
    for(int i=0; i<row; i++){
        arr[i] = new int[col];
    }
    
    // input elements
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cin>>arr[i][j];
        }
    }
    cout<<endl;
    
    // output or display array
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout<<arr[i][j]<<" ";
        }cout<<endl;
    }
    cout<<endl;
    
    // free array memory
    for(int i=0; i<row; i++){
        delete [] arr[i];
    }
    delete [] arr;
    
    
    return 0;
}