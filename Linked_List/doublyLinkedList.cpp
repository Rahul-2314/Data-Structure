#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* prev;
    Node* next;

    // constructor
    Node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }

    // destructor
    ~Node(){
        int value = this->data;

        if(next != NULL){
            delete next;
            next = NULL;
        }
        cout<<"memory free for node with value "<<value<<endl;
    }
};

void print(Node* &head) {
    Node* temp = head;

    while(temp != NULL) {
        cout<< temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int getLength(Node* &head) {
    Node* temp = head;
    int length = 0;

    while(temp != NULL) {
        length++;
        temp = temp->next;
    }
    return length;
}

void insertAtHead(Node* &head, Node* &tail, int data){
    if(head == NULL){
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else {
        Node *temp = new Node(data);

        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertAtTail(Node* &head, Node* &tail, int data){
    if(tail == NULL){
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else {
        Node *temp = new Node(data);

        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void insertAtPosition(Node* &head, Node* &tail, int position, int data){
    Node* insertingNode = new Node(data);

    if(position == 1){
        insertAtHead(head, tail, data);
        return;
    }

    int count = 1;
    Node* temp = head;
    while(count < position-1){
        temp = temp->next;
        count++;
    }

    if(temp->next == NULL){
        insertAtTail(head, tail, data);
        return ;
    }

    insertingNode->next = temp->next;
    insertingNode->prev = temp;
    temp->next = insertingNode;
}

void deleteNode(Node* &head, Node* &tail, int position){
    if(position == 1) {
        Node* temp = head;

        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else {
        Node* curr = head;
        Node* prev = NULL;

        int count = 1;
        while(count < position){
            prev = curr;
            curr = curr->next;
            count++;
        }

        if(curr->next == NULL) {    // updating tail if deleting last node
            tail = prev;
        }

        curr->prev = NULL;
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }

}

int main(){
    // Node* node1 = new Node(10);
    // Node* head = node1;
    // Node* tail = node1;

    Node* head = NULL;
    Node* tail = NULL;

    print(head);

    insertAtHead(head, tail, 20);
    print(head);

    insertAtTail(head, tail, 30);
    print(head);

    insertAtPosition(head, tail, 3, 40);
    print(head);
    insertAtPosition(head, tail, 1, 50);
    print(head);
    insertAtPosition(head, tail, 2, 60);
    print(head);

    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;

    deleteNode(head, tail, 5);
    print(head);
    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;

    return 0;
}