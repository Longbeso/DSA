#include<stdio.h>

// push đẩy phần tử vào stack
// pop xóa
// top lấy 
// size số lượng
// empty kiểm tra mảng rỗng

/* cài đặt bằng array và linked list */

/* cài đặt ngăn xếp bằng cách dử dụng mảng */

// int n = 0, stack[100];
// void push(int x){
//     stack[n] = x;
//     ++n;
// }
// void pop(){
//     if(n >= 1){
//         --n;
//     }
// }
// int top(){
//     return stack[n - 1];
// }
// int size(){
//     return n;
// }

// void print(){

// }
// int main(){
//     int i;
//     for(i = 1; i <= 10; i++){
//         push(i);
//     }
//     int m = size();
//     printf("%d \n", m);
//     for(i = m - 1; i >= 0 ; i-- ){
//         printf("%d ", stack[i]);
//     }
//     printf("\n%d ", size());
//     return 0;
// }


typedef struct {
    int data;
    Node *next;
} Node;

Node *makeNode(int x){
    Node *Newnode = (Node*)malloc(sizeof(Node));
    Newnode->data = x;
    Newnode->next = NULL;
    return Newnode;
}
void push(Node **top, int x){
    Node *newnode = makeNode(x);
    if(*top == NULL){
        *top = newnode;
        return;
    }
    newnode->next = *top;
    *top = newnode;
}
void pop(Node **top){
    // xóa thì xóa thằng trên đầu
    // là thằng vào sau cùng
    if(*top != NULL){
        Node *temp = *top;
        (*top) = temp->next;
        free(temp);
    }
}

int Top(Node **top){
    if(*top != NULL){
        return (*top)->data;
    }
}

int size(Node *top){
    int cnt = 0;
    while(top != NULL){
        ++cnt;
        top = top->next;
    }
    return cnt;
}