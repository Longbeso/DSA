#include<iostream>
#include<set>
using namespace std;

/*
Multiset trong C++ cũng được cài đặt bằng cấu trúc dữ liệu cây nhị phân tìm kiếm (binary search tree) tương tự như set
đặc điểm khác biệt nhất so với set đó là nó có thể lưu trữ các giá trị trùng nhau.
*/

/*Lưu được các giá trị trùng nhau*/

/*

 1. Đặc điểm
    Các phần tử trong multiset có thứ tự mặc định theo thứ tự tăng dần
    Các phần tử trong multiset có thể trùng nhau
    Các phần tử trong multiset không thể thay đổi, chỉ có thể xóa hoặc thêm vào
    Multiset không hỗ trợ truy cập phần tử thông qua chỉ số 
 2. Khai báo
    multiset<data_type> Name_mt_set;
 3. Các hàm find, count , erase
    + Hàm find sẽ trả về giá trị đầu tiên nếu tìm thấy trong multiset nếu có nhiều hơn 1 giá trị
      Tức nó sẽ trả về iterator đầu tiên của số đó nếu thấy còn không nó trả về iterator end
    + Hàm count 
*/
int main(){
    multiset<int> mt;
    mt.insert(1);
    mt.insert(1);
    mt.insert(14);
    mt.insert(3);
    mt.insert(9);
    mt.insert(2);
    mt.insert(2);
    mt.insert(56);
    mt.insert(56);
    mt.insert(12);
    mt.insert(2);
    mt.insert(9);
    mt.insert(12);
    cout << "    So phan tu cua multiset la: " << mt.size() << endl;
    for(multiset<int>::iterator it = mt.begin(); it != mt.end() ; it++){
        cout << *it << " " ;
    }
    cout << "\n    Cac ham khac set!!!" << endl;
    cout << "1. Ham find !!!" << endl;
    multiset<int> ms = {1, 1, 1, 2, 2, 3, 3, 3, 3, 3, 4};
    cout << "    So phan tu cua multiset la: " << ms.size() << endl;
    auto it = ms.find(3);
    if (it != ms.end()) {
        cout << "    3 xuat hien trong multiset\n";
        cout << "    Vi tri dau tien cua 3 trong multiset: " << distance(ms.begin(), it) << endl;
    } else {
        cout << "    3 khong xuat hien trong multiset\n";
    }
    cout << "2. ham count dem so lan suat hien !!!" << endl;
    cout << "    so lan xuat hien cua 3 la: " << ms.count(3) << endl;
    cout << "3. hàm erase !!! neu xoa bang gia tri thi no se xoa het con xoa bang iterator thi xoa 1" << endl;
    cout << "\n" ;
    cout << "    So phan tu ban dau la: ";
    for(int ea : ms){
        cout << ea << " ";
    }
    multiset<int>::iterator et = ms.find(3);
    ms.erase(et);
    cout << "    Sau khi xoa: " ;
    for(int ea : ms){
        cout << ea << " ";
    }
    return 0;
}