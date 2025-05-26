#include<iostream>
#include<map>
using namespace std;

/*
 1. Định nghĩa
    + Map là một cấu trúc dữ liệu được xây dựng sẵn trong C++, nó lưu trữ dữ liệu theo cặp khóa (key) và giá trị (value). 
      Mỗi phần tử trong map là một ánh xạ từ key sang value. Ví dụ đơn giản bạn có thể hình dung map có thể lưu trữ 
      các sinh viên và mã sinh viên tương ứng của họ và giúp bạn truy vấn nhanh tên sinh viên thông qua mã sinh viên. 
    + Để sử dụng được map bạn cần thêm thư viện "map" vào chương trình của mình.
 2. Tính chất
    + Các key trong map là riêng biệt, không có 2 key trùng nhau
    + Map duy trì thứ tự các phần tử theo giá trị key tăng dần
    + Map tìm kiếm giá trị key với độ phức tạp O(logN)
    + Map không hỗ trợ truy cập thông qua chỉ số như mảng hay vector, string.
    + Mỗi phần tử trong map chính là 1 pair 
 3. Khai báo
    + cần khai báo thư viện map
    + map<key_data_type, value_data_type> map_name;

 4. Các hàm cơ bản
    insert() : Thêm phần tử vào trong map với độ phức tạp 
    size()   : Trả về số phần tử trong map 
    clear()  : Xóa toàn bộ phần tử trong map
    empty()  : Kiểm tra vector rỗng
 
 5. Ví dụ
    * Duyệt map
    Ex1:
    
    map<int,int> mp;
    int N = 5;
    for(int i = 0; i < N; i++){
        int v;
        cin >> v;
        mp[i] = v;
    }
    int i = 0;
    for(pair<int, int> it : mp){
        cout << "mp[" << it.first << "] = " << it.second << endl;
    }

    Ex2:

    map<int,int> mp;
    int N = 5;
    for(int i = 0; i < N; i++){
        int k,v;
        cout << "Nhap key: ";
        cin >> k;
        cout << "Nhap Value: ";
        cin >> v;
        mp[k] = v;
    }
    
    for(map<int,int>::iterator it = mp.begin(); it != mp.end(); it++){
        cout << "mp[" << (*it).first << "] = " << (*it).second << endl;
    }

    * Thêm bằng insert
    map<int,int> mp;
    mp.insert({key, value});
    or
    mp.insert(make_pair(key, value);
*/


int main(){
    map<int,int> mp;
    int N = 5;
    for(int i = 0; i < N; i++){
        int k,v;
        cout << "Nhap key: ";
        cin >> k;
        cout << "Nhap Value: ";
        cin >> v;
        mp[k] = v;
    }
    
    for(auto at : mp){
        cout << "mp[" << at.first << "] = " << at.second << endl;
    }
    return 0;
}