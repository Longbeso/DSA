#include<iostream>
#include<unordered_map>
using namespace std;

/*
 1. Định nghĩa
    + Tương tự như map thì unordered_map được sử dụng để lưu trữ dữ liệu theo cặp key - value. 
      Các hàm của map thì unordered_map đều có nhưng khác nhau về độ phức tạp.
    + unordered_map được cài đặt bởi cấu trúc dữ liệu bảng băm - hash table.
      Bạn cần thêm thư viện "unordered_map" vào để có thể sử dụng container này.
 2. Đặc điểm
    + unordered_map lưu trữ phần tử với các key là riêng biệt
    + Các phần tử trong unordered_map không có thứ tự

   * Khai báo 
     unordered_map <key_data_type, value_data_type> map_name;
 3. Hàm find, count , erase
   Cách dùng 3 hàm phổ biến này của unordered_map tương tự như map, điều khác biệt duy nhất đó là vì unordered_map được 
   cài đặt bởi bẳng băm thay vì cây đỏ đen Red-black tree như map nên sẽ có sự khác nhau về độ phức tạp.
   Độ phức tạp trung bình của 3 hàm này là O(1), tuy nhiên trong trường hợp tệ nhất (Worst case) thì nó có thể là O(N). 
   Hàm insert trong unordered_map cũng tương tự như vậy về độ phức tạp.   



*/


int main(){
    unordered_map<int,string> mp;
    int n; cout << "Nhap so phan tu: " ;cin >> n;
    for(int i = 0; i < n;i++){
      int k;
      string v;
      cout << "Nhap key: ";
      cin >> k;
      cin.ignore();
      cout << "Nhap Value: ";
      getline(cin,v);
      mp[k] = v;
    }
    for(unordered_map<int,string>::iterator it = mp.begin(); it != mp.end();it++){
      cout << "Key " << (*it).first << " co gia tri la" << (*it).second << endl;
    }


    return 0;
}