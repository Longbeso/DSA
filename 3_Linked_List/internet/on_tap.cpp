#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    node *next;
};
#define node struct node


node *makeNode(int n){
    node *NewNode = (node*)malloc(sizeof(node));
    NewNode->data = n;
    NewNode->next = NULL;
    return NewNode;
}

void font_Node(node **head, int n){
    node* NewNode = makeNode(n);
    NewNode->next = *head;
    *head = NewNode;
}

void pushBack(node **head, int x){
    node *temp;
    temp = *head;
    node *NewNode = makeNode(x);
    if(temp == NULL){
        *head = NewNode;
        return;
    }
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = NewNode;

}
void print(node *head){
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
}
int main(){
    node *head = NULL;
    int n = 5;
    for(int i = n; i > 0; i--){
        pushBack(&head, i);
    }
    print(head);
    return 0;

}