#include<iostream>
#include<bits/stdc++.h>
using namespace std;



//Node Struct
struct Node {
    public:

    //Data
    int data;

    //Children    
    Node* left;
    Node* right;

};


//Inserting Nodes, not automatic
 struct Node* newNode(int key)
{

    //Creating New Node, fill with data
    Node* temp = new Node;
    temp->data = key;

    //Set children as empty
    temp->left = temp->right = NULL;
    return temp;
};


//Search through list using In-Order Search
bool Search(Node* node, int value) {

    //Failure Check
    if (node == NULL) {
        return false;
    }

    // Left Side Chceck
    bool result = Search(node->left, value);
    if(result) return true;
    
    //Right side check
    bool result2 = Search(node->right,value);
    return result2;
}


//In order traversal, left, root, right
void inorder(struct Node* node) {
    
    //Failure Check
    if (!node) {
        return;
    }

    //Recursive check for left the right, print values;
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);

}


//level order traversal to find the node, replace with deepest node, then delete deepest node
 Node* DeleteKey(struct Node* root, int key) {

    //Failure Check
    if (root==NULL) {
        return NULL;
    }

    //Checking if the Root is the chosen one to delete
    if (root->left == NULL && root->right == NULL) {
        if (root->data == key) {
            return NULL;
        } else {
            return root;
        }
    }


    // Create Queue with Nodes, add root
    queue<struct Node*> Q;
    Q.push(root);



    // Create a temporary Node to hold the current value in the check
    Node* temp;

    // Create an empty Node
    Node* key_node = NULL;

    // Create a node to hold the Last node
    Node* last;

    // While queue isnt empty, will iterate through every node
    while(!Q.empty()) {

        // Wquate temp with root at the front of the queue, removes root
        temp = Q.front();
        Q.pop();

        // Check if the current node is the right one
        if (temp->data == key) {
            key_node = temp;
        }

        //update the last position and search left
        if (temp->left) {
           last = temp;
            Q.push(temp->left);
        }

        //update the last position and search right
        if (temp->right) {
            last = temp;
            Q.push(temp->right);
        }

    }

    // If there is a node which has the key
    if (key_node != NULL) {

        // update the value of this key node w
        key_node->data = temp->data;
        
        //Delete the node with the key
        if(last->right == temp)
            last->right = NULL;
        else
            last->left = NULL;
        delete (temp);
    }
    return root;
}





int main(void){

    struct Node* root = newNode(9);
    root->left = newNode(2);
    root->left->left = newNode(4);
    root->left->right = newNode(7);
    root->right = newNode(8);
    root->left->left->right = newNode(12);

    /*
        Driver Code should make tree as so
                    9
                   / \
                  2   8
                 / \  
                4   7
                 \
                 12
    
    
    
    
    */
 
    cout << "Inorder traversal before deletion : ";
    inorder(root);
 
    int key = 7;
    root = DeleteKey(root, key);
    root = DeleteKey(root, 2);


    /*
        After Deletion Tree should be as follows
                    9
                   / \
                 12   8
                 /   
                4                        
    */


    cout << endl;
    cout << "Inorder traversal after deletion : ";
    inorder(root);
 
    return 0;


    return 0;
}
