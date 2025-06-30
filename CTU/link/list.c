#include<stdio.h>

// --> số phần tử tối đa
#define MaxLength 300

//--> Kiểu phần tử
typedef int ElementType;

// --> kiểu vị trí
typedef int Position;

// --> cấu trúc của một List
typedef struct {
    ElementType Element[MaxLength];   // --> mảng chứa các phần tử 
    Position Last;                    // --> độ dài danh sách
} List;

// --> Khởi tạo danh sách rỗng
void makeNullList(List *pl){
    pl->Last = 0;                     // --> cho độ dài danh sách bằng 0
}

// --> Kiểm tra danh sách rỗng (không rỗng thì trả về 0 , ngược lại trả về số khác 0 bất kì)
int emptyList(List l){
    return l.Last == 0;               // nếu đúng trả về 1, ngược lại trả về 0
}

// --> Kiểm tra danh sách có đầy hay không
int fullList(List l){
    return l.Last == MaxLength;       // --> xem độ dài danh sách có bằng độ dài tối đa
}

// --> xen phần tử x vào vị trí p
void insertList(ElementType x, Position p, List *l){
    if(fullList(*l)){
        printf("List is full");
        return;
    }
    if(p < 1 || p > l->Last){
        printf("errol position");
        return;
    }
    for(int i = l->Last; i >= p; i--){
        l->Element[i] = l->Element[i - 1];    // --> dời từ vịi trí p (index p - 1) trở về sau 1 đơn vị
    }
    l->Last++;                                // --> tăng số độ dài list
    l->Element[p - 1] = x;                    // gán x vào vị trí p (index p - 1)
}

// --> trả về phần tử tại vị trí p (index p - 1)
int retrieve(Position p, List l){
    if(emptyList(l)){
        printf("List is empty");
        return 0;
    } else if(p < 1 || p > l.Last){
        printf("errol position");
        return 0;
    } else {
        return l.Element[p - 1];

    }
}

// --> Duyệt list
void print(List l){
    Position i = 1;
    if(emptyList(l)){
        printf("List is empty");
        return;
    } else {
        while(i <= l.Last){
            printf("%d ", retrieve(i, l));
            i++;
        }
    }
}

// --> thêm phần tử vào list
void front(Position i,ElementType x, List *l){
    l->Element[i] = x;
    l->Last++;
}
int main(){
    List a;
    makeNullList(&a);
    Position i;
    for(i = 0; i < 5; i++){
        front(i, i + 5, &a);
    }
    print(a);
    insertList(12, 2, &a);
    insertList(12, 2, &a);
    insertList(12, 2, &a);
    insertList(12, 2, &a);
    insertList(12, 2, &a);
    printf("\n");
    print(a);




    return 0;
}