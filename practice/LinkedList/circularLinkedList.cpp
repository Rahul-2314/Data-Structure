#include <iostream>
using namespace std;

class CircularLinkedList {
private:
    struct Node {
        int data;
        Node* next;
    };
    
    Node* head;

public:
    CircularLinkedList() : head(nullptr) {}

    // Function to check if the list is empty
    bool isEmpty() {
        return head == nullptr;
    }

    // Insertion at the beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        if (isEmpty()) {
            newNode->next = newNode; // Pointing to itself (circular)
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != head) { // Traverse to the last node
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
            head = newNode;
        }
    }

    // Insertion at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        if (isEmpty()) {
            newNode->next = newNode; // Pointing to itself (circular)
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != head) { // Traverse to the last node
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    // Deletion from the beginning
    void deleteFromBeginning() {
        if (isEmpty()) {
            cout << "List is empty!" << endl;
            return;
        }
        if (head->next == head) { // Only one node
            delete head;
            head = nullptr;
        } else {
            Node* temp = head;
            Node* last = head;
            // Traverse to the last node
            while (last->next != head) {
                last = last->next;
            }
            head = head->next;
            last->next = head;
            delete temp;
        }
    }

    // Deletion from the end
    void deleteFromEnd() {
        if (isEmpty()) {
            cout << "List is empty!" << endl;
            return;
        }
        if (head->next == head) { // Only one node
            delete head;
            head = nullptr;
        } else {
            Node* temp = head;
            Node* prev = nullptr;
            // Traverse to the second last node
            while (temp->next != head) {
                prev = temp;
                temp = temp->next;
            }
            prev->next = head; // Make the second last node point to head
            delete temp;
        }
    }

    // Deletion of a specific value
    void deleteValue(int value) {
        if (isEmpty()) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        Node* prev = nullptr;
        do {
            if (temp->data == value) {
                if (temp == head) {
                    deleteFromBeginning();
                    return;
                } else {
                    prev->next = temp->next;
                    delete temp;
                    return;
                }
            }
            prev = temp;
            temp = temp->next;
        } while (temp != head);
        cout << "Value " << value << " not found in the list." << endl;
    }

    // Search an element
    bool search(int value) {
        if (isEmpty()) {
            return false;
        }
        Node* temp = head;
        do {
            if (temp->data == value) {
                return true;
            }
            temp = temp->next;
        } while (temp != head);
        return false;
    }

    // Display the list
    void display() {
        if (isEmpty()) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

    // Destructor to free memory
    ~CircularLinkedList() {
        if (head != nullptr) {
            Node* temp = head;
            while (head->next != temp) {
                Node* toDelete = head;
                head = head->next;
                delete toDelete;
            }
            delete head; // Delete the last node
        }
    }
};

int main() {
    CircularLinkedList cll;

    // Insertion at the beginning
    cll.insertAtBeginning(10);
    cll.insertAtBeginning(20);
    cll.insertAtBeginning(30);

    // Insertion at the end
    cll.insertAtEnd(40);
    cll.insertAtEnd(50);

    // Display the list
    cout << "List after insertions: ";
    cll.display();

    // Search
    cout << "Searching for 30: " << (cll.search(30) ? "Found" : "Not Found") << endl;

    // Deletion from the beginning
    cll.deleteFromBeginning();
    cout << "List after deleting from beginning: ";
    cll.display();

    // Deletion from the end
    cll.deleteFromEnd();
    cout << "List after deleting from end: ";
    cll.display();

    // Deletion of a specific value
    cll.deleteValue(40);
    cout << "List after deleting value 40: ";
    cll.display();

    // Deletion of non-existent value
    cll.deleteValue(100); // Value not in list

    // Check empty list edge case
    cll.deleteFromBeginning();
    cll.deleteFromEnd();
    cout << "List after deleting all elements: ";
    cll.display();

    return 0;
}
