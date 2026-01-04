#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    // constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    // destructor
    ~Node(){
        int data = this->data;
        if(this->next != NULL){
            delete this;
            this->next = NULL;
        }

        cout<< "memory free for node "<< data<< endl;
    }
};

void print(Node* &head){
    if(head == NULL){
        cout<< "Empty List"<<endl;
    } else{
        Node* temp = head;
        while(temp != NULL){
            cout<< temp->data <<" ";
            temp = temp->next;
        }
    }
    cout<<endl;
}

void insertAtHead(Node* &head, Node* &tail, int data){
    if(head == NULL){
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }else {
        Node* temp = new Node(data);
        temp->next = head;
        head = temp;
    }
}

void insertAtTail(Node* &head, Node* &tail, int data){
    if(tail == NULL){
        Node* temp = new Node(data);
        head  = temp;
        tail = temp;
    }else {
        Node* temp = new Node(data);
        tail->next = temp;
        tail = tail->next;
    }
};

void insertAtPosition(Node* &head, Node* &tail, int data, int position){
    if(position == 1){
        insertAtHead(head, tail, data);
        return ;
    }

    Node* temp = head;
    int i = 1;

    while(i < position-1){
        temp = temp->next;
        i++;

        if(temp->next == NULL){
            insertAtTail(head, tail, data);
            return;
        }
    }

    Node* newNode = new Node(data);
    newNode->next = temp->next;
    temp->next = newNode;
};

void deleteNodeAtPosition(Node* &head, Node* &tail, int position){
    if(position == 1){
        Node* temp = head;
        head = head->next;

        temp->next = NULL;
        delete temp;
    } 
    else {
        Node *prev = NULL;
        Node *curr = head;

        int count = 1;
        while (count < position){
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
    Node* head = NULL;
    Node* tail = NULL;

    insertAtTail(head, tail, 20);
    insertAtHead(head, tail, 10);
    insertAtTail(head, tail, 30);
    insertAtTail(head, tail, 40);
    insertAtPosition(head, tail, 50, 3);

    print(head);

    deleteNodeAtPosition(head, tail, 3);
    print(head);
}