#include <bits/stdc++.h>
using namespace std;

/* ---------- Custom Comparator for Min Heap ---------- */
struct MinHeapCompare {
    bool operator()(int a, int b) {
        return a > b;   // Min-Heap
    }
};

/* ---------- Custom Class ---------- */
class Student {
public:
    int marks;
    string name;

    Student(int m, string n) {
        marks = m;
        name = n;
    }
};

/* ---------- Comparator for Custom Class ---------- */
struct StudentCompare {
    bool operator()(const Student &s1, const Student &s2) {
        return s1.marks < s2.marks; // Max-Heap by marks
    }
};

int main() {

    /* ================= MAX HEAP ================= */
    cout << "Max Heap:\n";
    priority_queue<int> maxHeap;
    maxHeap.push(10);
    maxHeap.push(30);
    maxHeap.push(20);
    maxHeap.push(5);

    while (!maxHeap.empty()) {
        cout << maxHeap.top() << " ";
        maxHeap.pop();
    }
    cout << "\n\n";

    /* ================= MIN HEAP ================= */
    cout << "Min Heap:\n";
    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(10);
    minHeap.push(30);
    minHeap.push(20);
    minHeap.push(5);

    while (!minHeap.empty()) {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
    cout << "\n\n";

    /* ========== PRIORITY QUEUE OF PAIRS ========== */
    cout << "Priority Queue of Pairs (Max Heap):\n";
    priority_queue<pair<int,int>> pairPQ;
    pairPQ.push({2, 100});
    pairPQ.push({5, 200});
    pairPQ.push({1, 50});

    while (!pairPQ.empty()) {
        cout << pairPQ.top().first << " " << pairPQ.top().second << "\n";
        pairPQ.pop();
    }
    cout << "\n";

    /* ======== CUSTOM COMPARATOR (MIN HEAP) ======= */
    cout << "Custom Comparator Min Heap:\n";
    priority_queue<int, vector<int>, MinHeapCompare> customMinHeap;
    customMinHeap.push(40);
    customMinHeap.push(10);
    customMinHeap.push(30);

    while (!customMinHeap.empty()) {
        cout << customMinHeap.top() << " ";
        customMinHeap.pop();
    }
    cout << "\n\n";

    /* ======== PRIORITY QUEUE WITH CLASS ========= */
    cout << "Priority Queue with Custom Class:\n";
    priority_queue<Student, vector<Student>, StudentCompare> studentPQ;

    studentPQ.push(Student(85, "Rahul"));
    studentPQ.push(Student(92, "Aman"));
    studentPQ.push(Student(78, "Riya"));

    while (!studentPQ.empty()) {
        Student s = studentPQ.top();
        cout << s.name << " " << s.marks << "\n";
        studentPQ.pop();
    }

    return 0;
}
