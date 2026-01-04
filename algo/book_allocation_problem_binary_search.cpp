#include<iostream>
using namespace std;

bool isPossible(int arr[], int n, int m, int mid) {
    int studentCount = 1;
    int pageSum = 0;

    for(int i = 0; i < n; i++) {
        if(pageSum + arr[i] <= mid) {
            pageSum += arr[i];
        }
        else {
            studentCount++;
            if(studentCount > m || arr[i] > mid) {
                return false;
            }
            pageSum = arr[i];
        }
        if(studentCount > m) {
            return false;
        }
    }
    return true;
}

int allocateBooks(int arr[], int n, int m) {
    
    if(m>n) return -1;  //if student > no of books

    int s = 0;
    int sum = 0;

    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }
    int e = sum;
    int ans = -1;
    int mid;

    while(s <= e) {
        mid = s + (e - s) / 2;
        if(isPossible(arr, n, m, mid)) {
            ans = mid;
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
    }
    return ans;
}

int main() {
    int n;
    int m;

    cout << "Number of books: ";
    cin >> n;

    cout << "Number of Students: ";
    cin >> m;

    int arr[n];
  cout<<"Enter no of pages below :"<<endl;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

  cout<<endl;
  cout << "Minimum number of pages assigned : " << allocateBooks(arr, n, m) << endl;
}

// Time Complexity: O(n log n), where 'n' is the number of books.

// Space Complexity: O(1)

