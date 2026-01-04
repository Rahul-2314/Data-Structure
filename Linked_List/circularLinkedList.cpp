#include<iostream>
#include<map>
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
        int value = this->data;

        if(this->next != NULL){
            delete this->next;
            this->next = NULL;
        }
        cout<<"memory free for node with value "<<value<<endl;
    }
};

void print(Node* tail){
    if(tail == NULL){
        cout<<"Linked list is empty"<<endl;
        return ;
    }
    
    // else
    Node* temp = tail;

    do {
        cout<<tail->data<<" ";
        tail = tail->next;
    }while(tail != temp);
    cout<<endl;
}

void insertNode(Node* &tail, int element, int value){
    if(tail == NULL){
        Node* temp = new Node(value);

        tail = temp;
        tail->next = temp;
    }
    else {
        Node* curr = tail;
        while(curr->data != element){
            curr = curr->next;
        }

        Node* temp = new Node(value);

        Node* forward = curr->next;
        curr->next = temp;
        temp->next = forward; 
    }
}

void deleteNode(Node* &tail, int value){
    if(tail == NULL){
        cout<<"Linked list is empty"<<endl;
        return ;
    }

    // assuming value present in linked list
    Node* prev = tail;
    Node* curr = prev->next;

    while(curr->data != value){
        prev = curr;
        curr = curr->next;
    }

    if(curr == prev){   // deleting single node linked list
        tail = NULL;
    }

    if(tail == curr){   // deleting 1st node
        tail = prev;
    }

    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
}

bool isCircular(Node* head){
    if(head == NULL){
        return true;
    }

    Node* temp = head->next;
    while(temp!=NULL && temp!=head){
        temp = temp->next;
    }
    
    if(temp == head){
        return true;
    }
    return false;
}

bool detectLoop(Node* head){
    if(head == NULL){
        return false;
    }

    map<Node*,bool> visited;

    Node* temp = head;
    while(temp != NULL){
        if(visited[temp]==true){
            cout<<"cycle present on element "<<temp->data<<endl;    //begining of cycle
            return true;
        }

        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}

Node* floydDetectCycle(Node* head){
    if(head == NULL){
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
        }
        slow = slow->next;

        if(slow == fast){
            cout<<"cycle present on element "<<slow->data<<endl;    //node is part of cycle
            return slow;
        }
    }
    return NULL;
}

Node* getStartingNode(Node* head){
    if(head == NULL){
        return NULL;
    }

    Node* slow = head;
    Node* intersection = floydDetectCycle(head);
    if(intersection == NULL){
        return NULL;
    }

    while(slow != intersection){
        slow = slow->next;
        intersection = intersection->next;
    }

    return slow;
}

void removeLoop(Node* head){
    if(head == NULL){
        return ;
    }

    Node* startOfLoop = getStartingNode(head);
    if(startOfLoop == NULL) return ;
    Node* temp = startOfLoop;

    while(temp->next != startOfLoop){
        temp = temp->next;
    }
    temp->next = NULL;
}

int main(){
    Node* tail = NULL;

    insertNode(tail, 1, 10);
    print(tail);
    insertNode(tail, 10, 20);
    print(tail);
    insertNode(tail, 10, 30);
    print(tail);

    deleteNode(tail, 30);
    print(tail);


    return 0;
}