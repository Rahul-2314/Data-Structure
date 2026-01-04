#include <iostream>
using namespace std;

int main() {
  cout << "Enter the number of lines: ";
  int n;
  cin >> n;
  int row = 1;
  while (row <= n) {
    //   print spaces (1st triangle)
    int space = n - row;
    while (space > 0) {
      cout << " ";
      space--;
    }
    // print 2nd triangle
    int j = 1;
    while (j <= row) {
      cout << j;
      j++;
    }
    // print 3rd triangle
    int start = row - 1;
    while (start > 0) {
      cout << start;
      start--;
    }

    cout << endl;
    row++;
  }
  return 0;
}
