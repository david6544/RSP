#include<iostream>

using namespace std;

class BStree {
    int data;
    BStree *left, *right;

    public:
    BStree();
    BStree(int data);
    BStree* insert(BStree* node, int data);
    void inorder(BStree* node);
};

BStree::BStree() {
    data = 0;
    left = right = NULL;
}

BStree::BStree(int data) {
    this->data = data;
    left = right = NULL;
}

BStree* BStree::insert(BStree* root, int data) {
    if(!root) {
        return new BStree(data); //makes new root
    } else if (data > root->data) {
        root->right = insert(root->right,data);
    } else if (data < root->data) {
        root->left = insert(root->left, data);
    } 
    return root;
}

void BStree::inorder(BStree* root) {
    if(root != NULL) {
    inorder(root->left);
    cout << root->data << endl;
    inorder(root->right);
    }
}


int main(void){

    BStree b;
    BStree *root = NULL;
    root = b.insert(root, 4);
    b.insert(root, 2);
    b.insert(root, 3);
    b.insert(root, 9);
    b.insert(root, 7);
    b.insert(root, 6);
    b.insert(root, 23);    

    b.inorder(root);

} 





//----------------------------------------------------------------
/* BStree *searchtree(BStree *node, int data) {
    if (node == NULL) {
        return(NULL);
    } else if (node->item == data) {
        return  node;
    } else if (data < node->item){
        return(searchtree(node->left,data));
    } else {
        return(searchtree(node->right,data));
    }
}

BStree *findmin(BStree *node) {
    BStree *min;

    if (node == NULL) {
        return(NULL);
    }

    min = node;

    while(min->left != NULL) {
        min = min->left;
    }
    return(min);

}

BStree *findmax(BStree *node) {
    BStree *max;

    if (node == NULL) {
        return(NULL);
    }

    max = node;

    while(max->right != NULL) {
        max = max->right;
    }
    return(max);

} */

/* void traversal(BStree *node) {
    if (node != NULL) {
        traversal(node->left);
        process_item
    }
} */

/* void insert(BStree **node,int data, BStree * parent) {
    BStree *temp;
    
    if(*node == NULL) {
        temp = new BStree;
        temp->item = data;
        temp->left = parent->right = NULL;
        temp->parent = parent;
        *node = temp;
        return;
    }

     if (data < (*node)->item) {
        insert(&((*node)->left),data,*node);
     } else {
        insert(&((*node)->right),data,*node);    
     }
} */
/* 
BStree* insert(BStree* root, int data) {
    if(!root) {
        return new BStree(data);
    }
}*/
