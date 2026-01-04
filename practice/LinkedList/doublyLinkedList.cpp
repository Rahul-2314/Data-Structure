#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* prev;
    Node* next;

    // constructor
    Node(int data){
        this->data = data;
        this->prev = nullptr;
        this->next = nullptr;
    }

    // destructor
    ~Node(){
        // int data = this->data;
        // if(this->prev != nullptr || this->next != nullptr){
        //     delete this;
        //     this->prev = nullptr;
        //     this->next = nullptr;
        // }

        cout<< "memory free for node "<< this->data << endl;
    }
};

void print(Node* &head){
    Node* temp = head;

    if(temp == nullptr){
        cout<<"empty list"<<endl;
        return;
    }

    while(temp != nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }cout<<endl;
};

int getLength(Node* &head){
    Node* temp = head;
    
    if(head == nullptr){
        return 0;
    }
    
    int length = 0;
    while(temp != nullptr){
        length++;
        temp = temp->next;
    }
    return length;
}

void insertAtHead(Node* &head, Node* &tail, int data){
    if(head == nullptr){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    } else{
        Node* newNode = new Node(data);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void insertAtTail(Node* &head, Node* &tail, int data){
    if(tail == nullptr){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    } else{
        Node* newNode = new Node(data);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

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
        count++;
        temp = temp->next;
    }
    
    if(temp == nullptr){    //exceeds length
        cout<< "invalid position" << endl;
        return;
    }
    if(temp->next == nullptr){  //end of list
        insertAtTail(head, tail, data);
        return ;
    }

    Node* newNode = new Node(data);
    // rigth side connection
    temp->next->prev = newNode;
    newNode->next = temp->next;
    // left side connection
    newNode->prev = temp;
    temp->next = newNode;

}

void deleteNode(Node* &head, Node* &tail, int position){
    if(head == nullptr || position < 1){
        cout<<"either empty list or invalid position"<<endl;
        return ;
    }

    if(position == 1){
        Node* temp = head;

        // free memory (break connections)
        head = temp->next;
        if(head != nullptr){
            head->prev = nullptr;
        } else{
            tail = nullptr; //list become empty
        }

        if(temp->next != nullptr){
            temp->next->prev = nullptr;
        }
        temp->next = nullptr;
        delete temp;
    } else{
        Node* currNode = head;
        Node* prevNode = nullptr;

        int count = 1;
        while(currNode != nullptr && count < position){
            count++;
            prevNode = currNode;
            currNode = currNode->next;
        }

        if(currNode == nullptr){
            //position out of bound
            cout<<"invalid position"<<endl;
            return ;
        }

        if(currNode->next == nullptr){ //last node (deleting)
            tail = prevNode;
        }

        // right side connection (also handling nullptrptr)
        if(currNode->next != nullptr){
            currNode->next->prev = prevNode;
        }
        // left side connection
        prevNode->next = currNode->next;
        // free connection
        currNode->next = nullptr;
        currNode->prev = nullptr;

        delete currNode;
    }
}

int main(){
    Node* head = nullptr;
    Node* tail = nullptr;


    insertAtHead(head, tail, 10);
    insertAtTail(head, tail, 30);
    insertAtPosition(head, tail, 20, -2);
    insertAtPosition(head, tail, 40, 3);
    print(head);

    deleteNode(head, tail, 3);

    print(head);
    cout<< "length: "<<getLength(head)<<endl;

    return 0;
}