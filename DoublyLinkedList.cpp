#include<iostream>
using namespace std;

//Node class
class Node {
    public:
    
    //Data member
    int data;

    //pointers to previous and next nodes
    Node* next;
    Node* prior;
    
    //default constructor
    Node() {
        data = 0;
        next = NULL;
        prior = NULL;
    }

    //Valued Constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->prior = NULL;
    }
};


//Wrapping class to hold head node reference
class DLlist {
    public:
    Node* head;

    // Functions for Linked list
    void insert_at_tail(int newdata);
    void insert_at_head(int newdata);
    void display();

};


//Insertion at head of list      O(1)
void DLlist::insert_at_head(int newdata){
    

    // Create new node and make its next point to the head
    Node * newnode = new Node(newdata);
    newnode->next = this->head;
    
    // Check if head is empty and if it isnt make it point backwards to the new node
    if (head != NULL) {
        head->prior = newnode;
    }

    //replace the headnode
    head = newnode;


}

//Insertion at tail of list     O(N)
void DLlist::insert_at_tail( int newdata){

    //Check if head exists
    if (head == NULL) {
        insert_at_head(newdata);
        return;
    }


    // Create new node and guiding node
    Node * newnode = new Node(newdata);
    Node * temp = head;
    
    // go through each node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    //set pointers on the end where the guiding node currently resides
    temp->next = newnode;
    newnode->prior = temp;
}


//Display List      O(n)
void DLlist::display() {
    
    // create guiding node
    Node* temp = head;

    //parse through all nodes and print values
    while(temp != NULL) {
        cout << temp->data << " --> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main(void) {
    DLlist list;
    list.head = NULL;

       // Function call
    list.insert_at_tail(1);
    list.insert_at_tail(2);
    list.insert_at_tail(3);
    list.insert_at_tail(4);
    list.insert_at_tail(5);
 
    cout << "After insertion at tail: ";
    list.display();
 
    cout << "After insertion at head: ";
    list.insert_at_head(0);
 
    list.display();
}
