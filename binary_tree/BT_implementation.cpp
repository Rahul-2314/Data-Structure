#include<bits/stdc++.h>
using namespace std;

class Node {
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

// construct tree
Node* buildTree(Node* root){
    int data;
    cout<<"Enter the data:";
    cin>>data;
    root = new Node(data);

    if(data == -1){
        return nullptr;
    }

    cout<<"Enter data for inserting in left of " <<data<<":"<<endl;
    root->left = buildTree(root->left);

    cout<<"Enter data for inserting in right of " <<data<<":"<<endl;
    root->right = buildTree(root->right);

    return root;
}

// construct tree - using level order (IMP*****)
void builtTreeFromLevelOrder(Node* &root){
    queue<Node*> q;

    // handle root node
    int data;
    cout<<"Enter data for root node :";
    cin>>data;
    root = new Node(data);

    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        // handle left node
        int leftNode;
        cout<<"Enter data for left node of "<< temp->data <<" :";
        cin>> leftNode;

        if(leftNode != -1){
            temp->left = new Node(leftNode);
            q.push(temp->left);
        }

        // handle right
        int rightNode;
        cout << "Enter data for right node of " << temp->data << " :";
        cin>> rightNode;

        if(rightNode != -1){
            temp->right = new Node(rightNode);
            q.push(temp->right);
        }
    }
}

// BFS
void levelOrderTraversal(Node* root){
    if (root == nullptr)
        return; // base case
        
    queue<Node*> q;
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



int main(){
    Node* root = nullptr;

    builtTreeFromLevelOrder(root);
    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1

    // level-order traversal (BFS)
    cout<< "level order traversal :"<<endl;
    levelOrderTraversal(root);
    cout<<endl;

    // inorder traversal
    cout <<endl << "inorder traversal :"<<endl;
    inorder(root);
    // preorder traversal
    cout <<endl << "preorder traversal :"<<endl;
    preorder(root);
    // postorder traversal
    cout <<endl << "postorder traversal :"<<endl;
    postorder(root);


    /*
    // creating a Tree
    root = buildTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    // level-order traversal (BFS)
    cout<< "level order traversal :"<<endl;
    levelOrderTraversal(root);
    cout<<endl;

    // inorder traversal
    cout <<endl << "inorder traversal :"<<endl;
    inorder(root);
    // preorder traversal
    cout <<endl << "preorder traversal :"<<endl;
    preorder(root);
    // postorder traversal
    cout <<endl << "postorder traversal :"<<endl;
    postorder(root);
    */


    return 0;
}
