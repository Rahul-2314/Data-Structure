#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }

    ~Node(){
        cout<<"memory free for node "<< this->data <<endl;
    }
};

void print(Node* &head){
    if(head == nullptr){
        cout<<"empty list"<<endl;
        return ;
    }

    Node* temp = head;
    do{
        cout<< temp->data << " ";
        temp = temp->next;
    }while(temp != head);
    cout<<endl;
}

void insertAtHead(Node* &head, Node* &tail, int data){
    if(head == nullptr){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        tail->next = head;
    } else{
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        tail->next = head;
    }
}

void insertAtTail(Node* &head, Node* &tail, int data){
    if(tail == nullptr){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        tail->next = head;
    } else{
        Node* newNode = new Node(data);
        newNode->next = head;
        tail->next = newNode;
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
        return;
    }
    
    Node* temp = head;
    int count = 1;

    while(temp->next != head && count < position-1){
        temp = temp->next;
        count++;
    };

    if(count < position - 1){
        cout << "invalid position" << endl;
        return ;
    }
    if(temp == tail){
        insertAtTail(head, tail, data);
        return;
    }

    // inserting node
    Node* newNode = new Node(data);

    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteNode(Node* &head, Node* &tail, int position){
    // edge case
    if(head == nullptr || position < 1){
        cout<<"either empty list or invalid position"<<endl;
        return ;
    }

    if(position == 1){
        if(head == tail){
            Node* temp = head;

            tail->next = nullptr;
            head = tail = nullptr;

            delete temp;
        } else{
            Node* temp = head;

            tail->next = temp->next;
            head = temp->next;
            temp->next = nullptr;

            delete temp;
        }
    } else{
        Node* prev = nullptr;
        Node* curr = head;

        int count = 1;
        while(count < position && prev != tail){
            prev = curr;
            curr = curr->next;
            count++;
        }

        if(prev == tail && curr == head){
            cout<<"invalid position"<< endl;
            return ;
        }
        if(curr == tail){
            tail = prev;
            tail->next = head;

            delete curr;
        } else{
            prev->next = curr->next;
            curr->next = nullptr;

            delete curr;
        }
    }
}

int main(){
    Node* head = nullptr;
    Node* tail = nullptr;

    insertAtHead(head, tail, 20);
    insertAtTail(head, tail, 30);
    insertAtHead(head, tail, 10);
    insertAtPosition(head, tail, 40, 4);
    print(head);

    deleteNode(head, tail, 3);
    print(head);
    
    return 0;
}