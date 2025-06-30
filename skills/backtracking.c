#include<stdio.h>

// int ra tất cả các số nhị phân có n bit

int n, x[100];

void print(){
    for(int i = 0; i < n;i++){
        printf("%d", x[i]);
    }
    printf("\n");
}

// Mỗi vòng for có 2 lần lặp
// ta thực hiện hàm try với đối số là 1 
//    lần lặp đầu tiên gán x[i] = 0;
//    kiểm tra chưa được thì gọi lại hàm đệ quy và tăng i++;
//    tiếp tục gán và kiểm tra nếu chưa thỏa đk thì 
//    tăng i++
//    nếu đủ đk thì in lúc này in ra                                              000
//  lúc này chỉ mới hoàn thành vòng for đầu của hàm try(i = 3);
//  tiếp tục với vòng 2 của của hàm try(i = 3) ta gán x[3] = 1;
//  lúc này in ra                                                                 001
// * thế là xong hàm try(i = 3) đầu tiên trong vòng for của try(2);
// *** tức mỗi hàm try có 2 vòng for và mỗi vòng for lại có 2 hàm try với đối số ++;
// sau đó chương trình tiếp tục chạy vòng for thứ 2 của hàm try(i = 2); tức là trường hợp 01x
// lúc này gán x[2] = 1 và tiếp tục chạy để gán cho x[3] 2 giá trị 0 và 1
// sau đó chạy đệ quy hàm try(i = 3); đây là 2 hàm try khác trong trường hợp x[1] = 0 và x[2] = 1;
// tức là hàm try(i = 3) thứ 1 trong vòng for thứ 2 của hàm try(2) (vì mỗi hàm try(i = 2) có 2 hàm try(i = 3) do nó có 2 vòng lập nên gọi 2 lần);
// vòng for này thì ra gán x[3] = 1 và kiểm tra nếu được thì in lúc này in ra    010   
//  lúc này xong vòng for thú 1 của hàm try(3) nằm trong vòng for 2 của hàm try(i = 2)
// tiếp tục với try(i = 3) thứ 2 ta gán x[3] = 1 tức in ra                       011
// tiếp tục quay lui như thế




void try(int i){
    for(int j = 0; j <= n; j++){
        x[i] = j;
        if(i == n){
            print();
        } else {
            try(i + 1);
        }
    }
}



int main(){


    return 0;
}