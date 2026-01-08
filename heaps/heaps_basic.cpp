#include <bits/stdc++.h>
using namespace std;

class heap {
public:
    int arr[100];
    int size;

    heap() {
        size = 0;
    }

    // insertion - O(log n)
    void insert(int val) {
        arr[size] = val;
        int index = size;
        size++;

        while (index > 0) {
            int parent = (index - 1) / 2;

            if (arr[parent] < arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            } else {
                return;
            }
        }
    }

    void print() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // deletion - O(log n)
    void deleteFromHeap() {
        if (size == 0) {
            cout << "Nothing to delete" << endl;
            return;
        }

        // put last element at root
        arr[0] = arr[size - 1];
        size--;

        int i = 0;
        while (i < size) {
            int leftIndex = 2 * i + 1;
            int rightIndex = 2 * i + 2;
            int largest = i;

            if (leftIndex < size && arr[largest] < arr[leftIndex]) {
                largest = leftIndex;
            }
            if (rightIndex < size && arr[largest] < arr[rightIndex]) {
                largest = rightIndex;
            }

            if (largest != i) {
                swap(arr[i], arr[largest]);
                i = largest;
            } else {
                return;
            }
        }
    }
};

/* ---------- Heapify Logic (0 Indexing) ---------- */
void heapifyLogic(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[largest] < arr[left]) {
        largest = left;
    }
    if (right < n && arr[largest] < arr[right]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[largest], arr[i]);
        heapifyLogic(arr, n, largest);
    }
}

void heapify(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapifyLogic(arr, n, i);
    }
}

// heap sort - O(n log n)
void heapSort(int arr[], int n) {
    int t = n;

    while (t > 1) {
        swap(arr[0], arr[t - 1]);
        t--;
        heapifyLogic(arr, t, 0);
    }
}

int main() {
    heap h;

    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    h.print();

    h.deleteFromHeap();
    h.print();

    int arr[] = {54, 53, 55, 52, 50};
    int n = 5;

    heapify(arr, n);
    cout << "===== after heapify ======" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "======== after heap-sort =========" << endl;
    heapSort(arr, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
