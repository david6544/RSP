#include<iostream>

using namespace std;

class list {
public:
    int item;
    list* next;

    list *searchlist(list *l, int goal);
    void insertlist(list **l, int data);
    list *itemahead(list *prior, list *target);
    void deletelist(list **prior, list **target);

};

list *list::searchlist(list *l, int goal) {
    if (l == NULL) {
        return(NULL);
    } else if (l->item == goal) {
        return l;
    } else {
        return(searchlist(l->next, goal));
    }
}

void list::insertlist(list **newl, int data) {
    list *newpoint;
    newpoint = new list();
    newpoint->item = data;
    newpoint->next = *newl;
    *newl = newpoint;
}

list *list::itemahead(list *prior, list *target){
    if ((prior == NULL) || (prior->next == NULL)){
        return NULL;
    } else if (prior->next == target) {
        return prior;
    } else {
        return (itemahead(prior->next, target));
    }
}

void list::deletelist(list **first, list **target) {
    list *lpoint;
    list *prior;

    lpoint = *first;
    prior = itemahead(*first,*target);

    if (prior == NULL) {
        *first = lpoint->next;
    } else {
        prior->next = (*target)->next;
    }
    //delete(*target);
}



int main(void) {
    list* first;
    list* second;
    list* last;
    
    first = new list();
    second = new list();
    last = new list();

    first->item = 3;
    first->next = second;

    second->item = 4;
    second->next = last;
    
    last->item = 6;
    last->next = NULL;

    cout << (first->searchlist(first, 6))->item << endl;

    list* newfirst;
    first->insertlist(&newfirst, 5);
    
    cout << (first->searchlist(newfirst, 5))->item << endl;

    newfirst->deletelist(&first,&newfirst);
    
    first->deletelist(&first,&second);

}