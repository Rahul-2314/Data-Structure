#include <iostream>
using namespace std;


class Node {
    
    public:
    int data;
    Node* next;  //Node* acts like data type

    // constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    //destructor
    ~Node(){
        int value = this->data;
        if(this->next != NULL){
            delete this;
            this->next = NULL;
        }

        cout << "memory is free for data " << value << endl;
    }
};

void print(Node* &head){
    Node* temp = head;

    while(temp != NULL){
        cout<< temp->data <<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void insertAtHead(Node* &head, Node* &tail, int data) {
    if(head == NULL) {
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else {
        Node *temp = new Node(data); // create new node
        temp->next = head;
        head = temp;
    }
}

void insertAtTail(Node* &head, Node* &tail, int data) {
    if(tail == NULL) {
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else {
        Node *temp = new Node(data);
        tail->next = temp;
        tail = tail->next; // or, tail = temp; tail shift to next node
    }
}

void insertAtPosition(Node* &head, Node* &tail, int position, int data) {
    if(position == 1){  //insert at start position
        insertAtHead(head, tail, data);
        return ;
    }

    Node* temp = head;
    int count = 1;

    while(count < position-1){
        temp = temp->next;
        count++;
    }

    if(temp->next == NULL){  //insert at end position
        insertAtTail(head, tail, data);
        return ;
    }

    Node* insertingNode = new Node(data);
    insertingNode->next = temp->next;
    temp->next = insertingNode;
}

void deleteNode(Node* &head, Node* &tail, int position){
    // delete the starting node
    if(position == 1){
        Node* temp = head;
        head = head->next;

        temp->next = NULL;  // memory free starting node
        delete temp;
    }

    //delete any middle nodes or last nodes
    else {
        Node* prev = NULL;
        Node* curr = head;

        int count = 1;
        while(count < position){
            prev = curr;
            curr = curr->next;
            count++;
        }

        if(curr->next == NULL){
            tail = prev;
        }

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

int main(){
    // create a new node
    // Node* node1 = new Node(10);

    // head pointing to node1
    Node* head = NULL;
    Node* tail = NULL;
    // print(head);
    
    insertAtHead(head,tail, 20);
    print(head);

    insertAtTail(head, tail, 30);
    print(head);
    insertAtTail(head, tail, 40);
    print(head);

    insertAtPosition(head, tail, 2, 50);
    print(head);
    // insertAtPosition(head, tail, 1, 55);
    // print(head);
    // insertAtPosition(head, tail, 7, 500);
    // print(head);

    deleteNode(head, tail, 4);
    print(head);

    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;

    return 0;
}