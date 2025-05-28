#include<stdio.h>

#define MaxLength 300

typedef int ElementType;
typedef int Position;

typedef struct {
    ElementType Elements[MaxLength];
    Position Last;
    /* last - 1 là phần tử cuối cùng của list */
    /* Last = 3 thì có thì trong mảng có 3 phần tử Last - 3 là phần tử cuối cùng*/
    /* last là chỉ số của phần tử sau phần tử cuối cùng */
} List;

/* Khởi tạo danh sách rỗng */
void makeNullList(List *L){
    L->Last = 0;
}
/* Kiểm tra List rỗng nếu Last == 0 thì return 1 ngược lại return 0 */
int emptyList(List L){
    return L.Last == 0;
}
/* Kiểm tra danh sách đầy */
int ListFull(List L){
    return L.Last == MaxLength;
}
/* chèn phần tử vào vị trí p */
void insertList(ElementType x, Position p, List *L){
    if(L->Last == MaxLength){
        printf("List Full");
        return;
    }
    Position i;
    for(i = L->Last; i >= p; i--){
        L->Elements[i] = L->Elements[i-1];
    }
    L->Elements[p - 1] = x;
    // vị trí 3 thì index = 2;
    L->Last++;
}
void insertFrontList(ElementType x,List *L){
    L->Elements[L->Last] = x;
    L->Last++;
}
void deleteList(Position p, List *L){
    if(p < 1 || p > L->Last){
        printf("Errol Position");
    } else if(emptyList(*(L))){
        printf("empty");
    }
    //  dời từ vị trí sau phần tử cần xóa lên 1 vị trí
    Position i;
    for(i = p - 1; i < L->Last; i++){
        L->Elements[i] = L->Elements[i + 1]; 
    }
    L->Last--;
}
/* Trả về phần tử tại vị trí P */
int retrieve(Position p, List L){
    if(p > L.Last){
        printf("Errol Position");
    }
    return L.Elements[p-1];
}
/* trả về vị trí của phần tử x */
Position locate(ElementType x, List L){
    Position i;
    for(i = 1; i <= L.Last; i++){
        if(retrieve(i, L) == x){
            return i;
        }
    }
    return 0;
}

/* in danh sách */
void print(List L){
    for(int i = 0; i < L.Last; i++){
        printf("%d ", L.Elements[i]);
    }
}



int main(){
    List li;
    makeNullList(&li);
    if(emptyList(li)){
        printf("Empty List\n");
    }
    for(int i = 0; i <= 10; i++){
        insertFrontList(i, &li);
    }
    print(li);
    printf("\n");
    insertList(5,4,&li);
    print(li);
    if(locate(4, li)){
        printf("\nPosition: %d", locate(4, li));
    }
    return 0;
}