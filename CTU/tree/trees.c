#include<stdio.h>

// cài đặt cây bằng mảng

#define MAXLENGTH 100 //chỉ số tối đa của mảng
#define NIL -1
typedef char DataType;
typedef int Node;
typedef struct{
    DataType Data[MAXLENGTH];
    //Lưu trữ nhãn (dữ liệu) của nút trong cây
    Node Parent[MAXLENGTH];
    /* Lưu trữ cha của các nút trong cây theo nguyên
    tắc: Cha của nút i sẽ lưu ở vị trí i trong mảng */
    int MaxNode; //Số nút thực sự trong cây
} Tree;

// Khởi tạo cây rỗng
void makenullTree(Tree *t){
    t->MaxNode = 0;
}

// Kiểm tra cây rỗng
int emptyTree(Tree t){
    return t.MaxNode == 0;
}

// xác định nút cha của nút trên cây (Node là int thôi)
Node parent(Node n, Tree t){
    if(emptyTree(t) || (n > t.MaxNode - 1)){
        return -1;
    } else {
        return t.Parent[n]; // trả về chỉ số của cha phần tử này thôi
    }
}

// Hàm xác định nhãn của một node
DataType label_Node(Node n, Tree t){
    if(!emptyTree(t) && (n <= t.MaxNode - 1)){
        return t.Data[n];
    } else {
        return -1;
    }
}

// hàm xác định nút gốc trong cây 
Node root(Tree t){
    // nếu cây rỗng thì trả về 0 ngược lại trả về -1 vì chỉ số của root là 0 nên cha nó là -1
    if(!emptyTree(t)){
        return 0;
    } else {
        return -1;
    }
}

// hàm nhập một cây vào chương trình

void readTree(Tree *t){
    int n;
    printf("Nhap so luong node: ");
    scanf("%d", &n);

    if(n > MAXLENGTH){
        printf("Error: So node vuot qua gioi han!\n");
        return;  // Thêm return tránh chạy tiếp
    }

    t->MaxNode = n;

    for(int i = 0; i < n; i++){
        printf("Nhap nhan cho nut %d: ", i);
        scanf(" %c", &t->Data[i]);  // Thêm space trước %c để tránh trôi

        printf("Nhap node cha cua nut %d: ", i);
        scanf("%d", &t->Parent[i]);
    }
}


// con trái nhất của một node
Node most_leftChild(Node n, Tree t){
    if(n < 0) return -1;
    Node i = n + 1; // hi vọng vị trí node đầu là con của n 
    int found = 0;
    // vì lưu trong mảng nên phần tử nào bên trái sẽ được lưu trước
    while((i < t.MaxNode ) && !found){
        if(t.Parent[i] == n){
            found = 1;
        } else {
            i += 1;
        }
    }
    if(found){
        return i;
    } else {
        return -1;
    }
}

// Hàm xác định anh em ruột phải của một nút
// Node thật ra là kiểu int
Node right_sibling(Node n, Tree t){
    Node i, parent;
    int found = 0;
    if(n < 0) return -1;
    parent = t.Parent[n];
    i = n + 1;
    while(i <= t.MaxNode - 1 && !found ){
        if(t.Parent[i] == parent){
            found = 1;
        } else {
            i += 1;
        }
    }
    if(found){
        return i;
    } else {
        return -1;
    }
}

// Duyệt tiền tự PreOrder
void PreOrder(Node n,Tree t){
    Node i;
    printf("%c ", label_Node(n, t));
    i = most_leftChild(n, t);
    while(i != -1){
        PreOrder(i, t);
        i = right_sibling(i, t);
    }
}

// Duyệt trung tự Inorder 
void Inorder(Node n, Tree t){
    Node i = most_leftChild(n, t);
    if(i != -1){
        Inorder(i, t);
    }
    printf("%c ", label_Node(n, t));
    i = right_sibling(i, t);
    while(i != - 1){
        Inorder(i, t);
        i = right_sibling(i, t);
    }
}

// Duyệt hậu tự PostOrder
void PostOrder(Node n, Tree t){
    Node i = most_leftChild(n, t);
    while(i != -1){
        PostOrder(i, t);
        i = right_sibling(i, t);
    }
    printf("%c ", label_Node(n, t));
}

int main(){
    Tree t;
    makenullTree(&t);
    readTree(&t);
    PreOrder(root(t), t);
    printf("\n");
    Inorder(root(t), t);
    printf("\n");
    PostOrder(root(t), t);
    return 0;
}