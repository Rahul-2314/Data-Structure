#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    // constructor
    Node(int data){
        this->data = data;
        this->next = nullptr;
    }

    // destructor
    ~Node(){
        cout<< "memory free for node "<< this->data << endl;
    }
};

void print(Node* &head){
    if(head == nullptr){
        cout<< "Empty List"<<endl;
    } else{
        Node* temp = head;
        while(temp != nullptr){
            cout<< temp->data <<" ";
            temp = temp->next;
        }
    }
    cout<<endl;
}

void insertAtHead(Node* &head, Node* &tail, int data){
    if(head == nullptr){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }else {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }
}

void insertAtTail(Node* &head, Node* &tail, int data){
    if(tail == nullptr){
        Node* newNode = new Node(data);
        head  = newNode;
        tail = newNode;
    }else {
        Node* newNode = new Node(data);
        tail->next = newNode;
        tail = tail->next;
    }
};

void insertAtPosition(Node* &head, Node* &tail, int data, int position){
    // edge case
    if(position < 1){
        cout << "invalid position" << endl;
        return;
    }
    if(head == nullptr || position == 1){
        insertAtHead(head, tail, data);
        return ;
    }

    Node* temp = head;
    int count = 1;

    while(temp != nullptr && count < position-1){
        temp = temp->next;
        count++;
    }

    if(temp == nullptr){    //exceeds length
        cout<< "invalid position" <<endl;
        return ;
    }
    if(temp->next == nullptr){  //end of list
        insertAtTail(head, tail, data);
        return ;
    }

    Node* newNode = new Node(data);
    newNode->next = temp->next;
    temp->next = newNode;
};

void deleteNodeAtPosition(Node* &head, Node* &tail, int position){
    if(head == nullptr || position < 1){
        cout<<"either list is empty or invalid position"<<endl;
        return ;
    }

    if(position == 1){
        Node* temp = head;
        head = head->next;
        if(head == nullptr){
            tail = nullptr; // list become empty
        }

        temp->next = nullptr;
        delete temp;
    } 
    else {
        Node *prev = nullptr;
        Node *curr = head;

        int count = 1;
        while (curr != nullptr && count < position){
            prev = curr;
            curr = curr->next;
            count++;
        }

        if(curr == nullptr){
            cout<<"invalid position"<<endl;
            return ; //position out of bound
        }

        if(curr->next == nullptr){ //last node (deleting)
            tail = prev;
        }

        prev->next = curr->next;
        curr->next = nullptr;
        delete curr;

    }
}

int main(){
    Node* head = nullptr;
    Node* tail = nullptr;

    insertAtTail(head, tail, 20);
    insertAtHead(head, tail, 10);
    insertAtTail(head, tail, 30);
    insertAtTail(head, tail, 40);
    insertAtPosition(head, tail, 50, 3);

    print(head);

    deleteNodeAtPosition(head, tail, 3);
    print(head);
}