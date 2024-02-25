#include "StrList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct _node {
    char* _data;
    struct _node * _next;
} Node;

struct _StrList{
    Node* _head;
    size_t _size;
};
typedef struct _StrList StrList;



//------------------------------------------------
// Node implementation
//------------------------------------------------

Node* Node_alloc(char* data, Node* next) 
{
	Node* p = (Node*)malloc(sizeof(Node));
    if (p != NULL){
	p->_data = strdup(data);
	p->_next = next;}
	return p;
}

void Node_free(Node* node) {
    free(node->_data);
	free(node);
}

//------------------------------------------------
// List implementation
//------------------------------------------------

StrList* StrList_alloc() {
	StrList* list= (StrList*)malloc(sizeof(StrList));
    if (list != NULL){
	list->_head = NULL;
	list->_size = 0;}
	return list;
}

void StrList_free(StrList* StrList) {
	if (StrList==NULL) return;
	Node* p1= StrList->_head;
	Node* p2;
	while(p1) {
		p2= p1;
		p1= p1->_next;
		Node_free(p2);
	}
    //StrList->_head = NULL;
    //StrList->_size = 0;
	free(StrList);
}

size_t StrList_size(const StrList* StrList) {
    return StrList->_size;
}

void StrList_insertLast(StrList* StrList, const char* data){
    Node* new_node = Node_alloc(strdup(data),NULL); 
    
    if(StrList->_head == NULL){
        StrList->_head = new_node;
    }
    else{
        Node* p = StrList->_head;
        while(p->_next != NULL){
            p = p->_next;
        }
        p->_next = new_node;
    }
    ++(StrList->_size);
}

void StrList_insertAt(StrList* StrList, const char* data, int index){
    if (index < 0 || index > StrList->_size) { return; }

    if (index == 0) {
        StrList->_head = Node_alloc(strdup(data), StrList->_head);
        ++(StrList->_size);
        return;
    }

    Node* p = StrList->_head;
    for (int i = 0; i < index - 1; ++i) {
        p = p->_next;
    }
    p->_next = Node_alloc(strdup(data), p->_next);
    ++(StrList->_size);
}


char* StrList_firstData(const StrList* StrList){
	if (StrList && StrList->_head)
        return StrList->_head->_data;
    return NULL;
}

void StrList_print(const StrList* StrList){
   if(StrList){
   const Node* p1 = StrList->_head;
    while (p1){
        printf("%s ", p1->_data);
        p1 = p1->_next;
        }
    }
}

void StrList_printAt(const StrList* Strlist,int index){
    //if (Strlist->_size <= index || index < 0){return;}
    if (Strlist && index >= 0 && index < Strlist->_size){
   const Node* p1 = Strlist->_head;

    for(int i=0;i<index;i++){
        p1 = p1->_next;
    }

    printf(" %s",p1->_data);
    }
}

int StrList_printLen(const StrList* Strlist){
    if (Strlist){
    int counter = 0;

   const Node* p1 = Strlist->_head;

    for (size_t i = 0; i < Strlist->_size; i++){
        counter += strlen(p1->_data);
        p1 = p1->_next;
    }
    return counter;
    }
    return 0;
}

int StrList_count(StrList* StrList, const char* data){
    if (StrList) {
    int counter = 0;

    const Node* p1 = StrList->_head;

    while (p1){
        if(strcmp(p1->_data, data) == 0){counter++;}
        p1 = p1->_next;
    }
    return counter;
    }
    return 0;
}

void StrList_remove(StrList* StrList, const char* data) {
    if (StrList) {
        Node *current = StrList->_head;
        Node *prev = NULL;
        while (current) {
            if (strcmp(current->_data, data) == 0) {
                if (prev == NULL) {
                    StrList->_head = current->_next;
                } else {
                    prev->_next = current->_next;
                }
                free(current->_data);
                free(current);
                StrList->_size--;
                current = prev ? prev->_next : StrList->_head;
            } else {
                prev = current;
                current = current->_next;
            }
        }
    }
}

void StrList_removeAt(StrList* StrList, int index){
    
    if (StrList->_size <= index || index < 0){return;}

    Node* p1 = StrList->_head;
    Node* p2 = StrList->_head;

    for (size_t i = 0; i < index; i++){

        //if(StrList->_size != 0){
            for (size_t j = 0; j < i-1; j++){
                p2 = p2->_next;
            }
            p2->_next = p1->_next;
        //}
        Node_free(p1);
        --(StrList->_size);
    }
}

int StrList_isEqual(const StrList* StrList1, const StrList* StrList2){
    if (StrList1->_size != StrList2->_size){return 0;}

    Node* p1 = StrList1->_head;
    Node* p2 = StrList2->_head;

    while (p1 && p2) {
        if(strcmp(p1->_data,p2->_data)!=0){return 0;}
        p1 = p1->_next;
        p2 = p2->_next;   
    }

    return 1;
}

StrList* StrList_clone(const StrList* Strlist){
    StrList* ret = StrList_alloc();

	const Node* old= Strlist->_head;
	
    Node* * copy= &(ret->_head);
	
    ret->_size= Strlist->_size;
	
    while(old) {
		*copy= Node_alloc(old->_data,NULL);
		old= old->_next;
		copy= &((*copy)->_next);
	}
	return ret;
}

void StrList_reverse(StrList* StrList) {
    Node* current = StrList->_head;
    Node* prev = NULL;
    Node* next = NULL;

    while (current != NULL) {
        // Store next node
        next = current->_next;
        // Reverse current node's pointer
        current->_next = prev;
        // Move pointers one position ahead
        prev = current;
        current = next;
    }

    // Update head pointer to point to the new first node (which was the last node before reversal)
    StrList->_head = prev;
}

void StrList_sort(StrList* StrList) {
    if (StrList && StrList->_size > 1) {
        char *temp;
        Node *i, *j;
        for (i = StrList->_head; i != NULL; i = i->_next) {
            for (j = i->_next; j != NULL; j = j->_next) {
                if (strcmp(i->_data, j->_data) > 0) {
                    temp = i->_data;
                    i->_data = j->_data;
                    j->_data = temp;
                }
            }
        }
    }
}

int StrList_isSorted(StrList* StrList){
    if(StrList == NULL){return 1;}

    Node* p1 = StrList->_head;
    Node* p2 = StrList->_head->_next;

     for (p1 = StrList->_head; p1->_next != NULL; p1 = p1->_next) {
             if(strcmp(p1->_data,p2->_data) > 0){return 0;}
             p2 = p2->_next;
        }
    return 1;        
     }
