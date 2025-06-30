#include<stdio.h>
#include<malloc.h>

typedef int ElementType;       // --> Kiểu phần tử 

struct Node{                   // --> cấu trúc của một Node
    ElementType Element;
    struct Node* Next;
};
typedef struct Node* Position; // --> định nghĩa kiểu vị trí (vị trí của a2 là con trỏ trỏ vào Node a1)

typedef Position List;         // --> định nghĩa tên của node

// --> Khởi tạo danh sách rỗng 
void makeNullList(List *l){
    (*l) = (struct Node*)malloc(sizeof(struct Node));
    (*l)->Next = NULL;
}

// --> Kiểm tra danh sách rỗng
int emptyList(List l){
    return (l->Next == NULL);
}

// --> xác định nội dung phần tử 
ElementType retrieve(Position p, List l){
// Position là con trỏ trở tới phần tử trước phần tử cần truy cập
    if(p->Next != NULL){
        return p->Next->Element;
    }
}

// --> xen một phần tử vào danh sách
void insertList(Position p, ElementType x , List l){
    List k;
    k = (struct Node*)malloc(sizeof(struct Node));
    k->Element = x;
    k->Next = p->Next;
    p->Next = k;
}

// --> xóa một phần tử khỏi danh sách
void deleteList(Position p, List *l){
    Position temp;
    if(p->Next != NULL){
        temp = p->Next;
        p->Next = temp->Next;
        free(temp);   
    }

}
