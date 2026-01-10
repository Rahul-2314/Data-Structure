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
