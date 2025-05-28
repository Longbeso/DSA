#include<stdio.h>

typedef int ElementType;

typedef struct{
    ElementType Element;
    Node *next;
} Node;

typedef Node* Position;
typedef Position List;

/*                định nghĩa            *
/* vị trí p của một phần tử chính là con trỏ trỏ tới node trước đó của nó  */




/* tạo vùng nhớ header con trỏ quản lý các node trong list */
void makeNullList(List *L){
    (*L) = (Node*)malloc(sizeof(Node));
    (*L)->next = NULL;
}
/* kiểm tra mảng rỗng */
int emptyList(List L){
    return L->next == NULL;
}

/* xác định nối dung phần tử */
/* Position và List là như nhau đều là con trỏ trỏ tới một node */
int retrieve(Position p, List L){
    if(p->next != NULL){
        return p->next->Element;
    }
    return 0;
}
int main(){


    return 0;
}