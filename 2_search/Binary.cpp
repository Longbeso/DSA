#include<iostream>
using namespace std;
#define N 10
int Binary_search(const int arr[], int left, int right, int x){
    while(left <= right){
        int mid = (left + right) / 2;
        if(x > arr[mid]){
            left = mid + 1;
        } else if(x < arr[mid]){
            right = mid - 1;
        } else {
            return mid;
        }
    }
    return -1;
}
void merge(int arr[], int left, int mid, int right){ // hàm trộn 2 mảng
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];
    for(int i = 0; i < n1; i++){ // copy vào mảng trái
        L[i] = arr[left + i];
        
    }
    for(int j = 0; j < n2; j++){ // copy vào mảng phải
        R[j] = arr[mid + j + 1];
    }
    int i = 0, j = 0, k = left;
    while(i < n1 && j < n2){ // trộn 2 mảng trái phải lại
        if(L[i] < R[j]){
            arr[k] = L[i];
            i++;
            k++;
        } else {
            arr[k] = R[j];
            k++;
            j++;
        }
    }
    while(i < n1){ // nếu mảng trái còn dư thì thêm nốt phần còn lại
        arr[k] = L[i];
        k++;
        i++;
    }
    while(j < n2){ // nếu mảng phải còn dư thì thêm nốt phần còn lại
        arr[k] = R[j];
        k++;
        j++;
    }
}

void mergeSort(int arr[], int left, int right){
    if(left < right){
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid); // đệ qui cho mảng bên trái để nó tiếp tục chia mảng ra tới khi nào còn 1 phần tử
        mergeSort(arr, mid + 1, right); // tương tự
        merge(arr, left, mid, right); // trộn mảng lại sau khi chia
    }
}
int main(){
    int x;
    int arr[N] = {1, 6, 8, 3, 5, 2, 20, 12, 8, 14};
    int left = 0, right = N - 1;
    mergeSort(arr,left, right);
    cout << "Mang sau khi sap xep" << endl;
    for(auto it : arr){
        cout << it << " ";
    }
    cout << endl;
    cout << "Nhap x can tim: ";
    cin >> x;
    cout << "Vi tri cua x la: " << Binary_search(arr, left, right, x) << endl;
    return 0;
}