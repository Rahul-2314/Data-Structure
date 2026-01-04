#include <bits/stdc++.h>
using namespace std;

class Node{

    public:
        int data;
        Node* left;
        Node* right;

    Node(int d){
        this->data = d;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// BFS traversal
void levelOrderTraversal(Node* root){
    if(root == nullptr) return ;    //base case

    queue<Node *> q;
    q.push(root);

    q.push(nullptr);    //level-separator

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp == nullptr){    // one level completed - level separator logic
            cout<< endl;
            if(!q.empty()){     // has some child node
                q.push(nullptr);
            }
        }
        else{
            cout << temp->data << " ";

            if (temp->left){
                q.push(temp->left);
            }
            if (temp->right){
                q.push(temp->right);
            }
        }
    }
}

// in-order traversal
void inorder(Node* root){
    // base case
    if(root == nullptr){
        return ;
    }

    inorder(root->left);    //left
    cout<< root->data << " ";   //root
    inorder(root->right);   //right
}

// pre-order traversal
void preorder(Node* root){
    // base case
    if(root == nullptr){
        return ;
    }

    cout<< root->data << " ";   //root
    preorder(root->left);    //left
    preorder(root->right);   //right
}

// post-order traversal
void postorder(Node* root){
    // base case
    if(root == nullptr){
        return ;
    }

    postorder(root->left);    //left
    postorder(root->right);   //right
    cout<< root->data << " ";   //root
}

// searching
bool searchInBST(Node *root, int x) {
    // Write your code here.
    // base case
    if(root == nullptr) return false;
    if(root->data == x) return true;

    if(x < root->data){
        searchInBST(root->left, x);
    }
    else searchInBST(root->right, x);
}

// find min - max
Node* findMin(Node* root){      //leftmost node
    if(root == nullptr) return nullptr;

    while(root->left != nullptr){
        root = root->left;
    }
    return root;
}
Node* findMax(Node* root){      //leftmost node
    if(root == nullptr) return nullptr;

    while(root->right != nullptr){
        root = root->right;
    }
    return root;
}

// insertion
void insertIntoBST(Node* &root, int data){
    // base case
    if(root == nullptr){
        root = new Node(data);
        return ;
    }

    if(data < root->data){
        // insert in left subtree
        insertIntoBST(root->left, data);
    }
    // insert in right subtree
    else insertIntoBST(root->right, data);
}

void takeInput(Node* &root){
    int data;
    cin>> data;

    while(data != -1){
        insertIntoBST(root, data);
        cin>> data;
    }
}

// find inorder predecessor and successor


// deletion
Node* deleteFromBST(Node* root, int val){
    // base case
    if(root == nullptr) return root;

    if(root->data == val){
        // 0 child
        if(root->left == nullptr && root->right == nullptr){
            delete root;
            return nullptr;
        }
        // i child
        else if(root->left == nullptr || root->right == nullptr){
            Node* temp = root->left == nullptr ? root->right : root->left;
            delete root;
            return temp;
        }
        // 2 child
        else{
            // can pick either max from left subtree or min from right subtree
            Node* mini = findMin(root->right);
            root->data = mini->data;
            // delete node from that subtree
            root->right = deleteFromBST(root->right, mini->data);
            return root;
        }
    }
    else if(root->data > val){
        root->left = deleteFromBST(root->left, val);
    }
    else {
        root->right = deleteFromBST(root->right, val);
    }

    return root;
}



int main(){
    Node* root = nullptr;

    cout<< "Enter data to create BST :" << endl;
    takeInput(root);

    cout<< "Printing the BST :" << endl;
    levelOrderTraversal(root);

    cout<< endl << "Printing the BST inorder :" << endl;
    inorder(root);
    cout<< endl << "Printing the BST preorder:" << endl;
    preorder(root);
    cout<< endl << "Printing the BST postorder:" << endl;
    postorder(root);

    cout<<endl;
    cout<< "seaching node 21 :";
    if(searchInBST(root, 21)){
        cout<<"found" <<endl;
    } else{
        cout<<"not found"<<endl;
    }

    cout<< "Min value :" << findMin(root)->data << endl;
    cout<< "Max value :" << findMax(root)->data << endl;

    // deletion
    cout<<"deleted 8 " <<endl;
    root = deleteFromBST(root, 8);
    cout << "Printing the BST (after deletion) :" << endl;
    levelOrderTraversal(root);

    return 0;
}