#include<stdio.h>

int timquayranh(int thoigianquayranh[],int cash){
    int min = 0;
    for(int i = 1; i < cash; i++){
        if(thoigianquayranh[i] < thoigianquayranh[min]){
            min = i;
        }
    }
    return min;
}

int main(){
    int thoigianden[100];
    int thoigianquayranh[100]; // tượng trưng cho mỗi quầy
    int customer;
    scanf("%d", &customer);
    int cash;
    scanf("%d", &cash);
    int thoigianxuly;
    scanf("%d", &thoigianxuly);
    int thoigiankhachden;
    scanf("%d", &thoigiankhachden);
    int thoigianchuan;
    scanf("%d", &thoigianchuan);
    for(int i = 0; i < customer; i++){
        thoigianden[i] = i * thoigiankhachden;
    }  
    
    for(int soquay = 1; soquay <= cash; soquay++){
        for(int i = 0; i < soquay; i++){
            thoigianquayranh[i] = 0;
        }
        int tongthoigiancho = 0;
        // bắt đầu xử lý từng khách và tìm tổng thời gian chờ của tất cả các khách
        for(int i = 0; i < customer; i++){
            // 1. lấy thời gian khách đến
            int denluc = thoigianden[i];
            // 2. tìm quầy rảnh sớm nhất
            int quayphuhop = timquayranh(thoigianquayranh, soquay);
            // 3. tính thời gian bắt đầu phục vụ
            int batdauluc = (denluc > thoigianquayranh[quayphuhop]) ? denluc : thoigianquayranh[quayphuhop];
            // 4. tính thời gian khách phải chờ
            int thoigiancho = batdauluc - denluc;
            tongthoigiancho += thoigiancho;
            // 5. cập nhật lại thời gian rảnh cho quầy đó
            thoigianquayranh[quayphuhop] = batdauluc + thoigianxuly;
        }
        // 6. tính thời gian chờ trung bình sau khi xử lý hết khách hàng
        double trungbinh = (double)tongthoigiancho / customer;
        // 7. Kiểm tra điều kiện dừng
        printf("So quay: %d; Thoi gian cho trung binh: %.1f giay\n", soquay, trungbinh);

        if (trungbinh <= thoigianchuan) {
            printf("\n=> Can mo %d quay thu ngan.\n", soquay);
            break;
        }
    }
}