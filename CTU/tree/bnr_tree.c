#include<stdio.h>
#include<stdlib.h>

typedef int DataType;
#define Maxlength 100

struct BNtree{
    DataType data;
    struct BNtree *left;
    struct BNtree *right;
};
typedef struct BNtree* BNTree;
// Tạo cây rỗng
void makenullBNTree(BNTree *t){
    *t = NULL;
}

// Kiểm trâ cây rỗng
int emptyBNTree(BNTree t){
    return (t == NULL);
}

// Xác định con trái
BNTree leftChild(BNTree t){
    if(t != NULL) {
        return t->left;
    } else {
        return NULL;
    }
}

// Xác định anh em ruột phải 
BNTree rightChild(BNTree t){
    if(t != NULL){
        return t->right;
    } else {
        return NULL;
    }
}

// duyệt tiền tự Preorder
void PreOrder(BNTree t){
    printf("%d ", t->data);
    
    if(leftChild(t) != NULL){
        PreOrder(leftChild(t));
    }
    if(rightChild(t) != NULL){
        PreOrder(rightChild(t));
    }
}

void InOrder(BNTree t){
    if(leftChild(t) != NULL){
       InOrder(leftChild(t));
    }
    printf("%d ", t->data);
    
    if(rightChild(t) != NULL){
       InOrder(rightChild(t));
    }
}

void PostOrder(BNTree t){
    if(leftChild(t) != NULL){
       PostOrder(leftChild(t));
    }
    if(rightChild(t) != NULL){
       PostOrder(leftChild(t));
    }
    printf("%d ", t->data);
}

// Xác định số nút trong cây

int nb_nodes(BNTree t){
    if(emptyBNTree(t)){
        return 0;
    } else {
        return 1 + nb_nodes(t->left) + nb_nodes(t->right); 
    }
}

// Tạo cây mới từ 2 cây có sẵn

BNTree create2(DataType d, BNTree l, BNTree r){
    BNTree n;
    n = (struct BNtree*)malloc(sizeof(struct BNtree));
    n->data = d;
    n->left = l;
    n->right = r;
    return n;
}


int main(){
    BNTree t = create2(10, create2(12, create2(9, NULL, NULL), create2(7, NULL, NULL)),
                         create2(14, create2(30, NULL, NULL), create2(11, NULL, NULL))
    );
    PreOrder(t);
    printf("\n");
    InOrder(t);
    printf("\n");
    PostOrder(t);
    return 0;
}