#include<iostream> 
#include<vector> 

// 1. Khai báo
// vector<data_type> vector_name;
// ví dụ vector<int> vt;
// vector có kiểu dữ liệu là int và có tên là vt
// 2. các hàm thông dụng

// size() : Trả về số lượng phần tử trong vector. Độ phức tạp O(1)

// push_back() : Thêm phần tử vào cuối vector. Độ phức tạp O(1)

// pop_back() : Xóa phần tử cuối cùng trong vector. Độ phức tạp O(1)

using namespace std;
int main(){
    // 1.Khai báo và duyệt vector
    vector<int> v;
    v.push_back(12);
    v.push_back(17);
    v.push_back(12);
    v.push_back(110);
    cout << "so phan tu cua vector int la: " << v.size() << endl;
    cout << "duyet vector bang chi so" << endl;
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << "\nduyet vector bang ranged-base for loop" << endl;
    for(int i : v){
        cout << i << " " ;
    }
    // 2. khai báo kiểu string hoặc nhiều kiểu khác nhau
    cout << "vector string" << endl;
    vector<string> str = {"Long" , "Beo", "Ne"};
    str.push_back("Con");
    str.push_back("HiHa");
    cout << "So phan tu cua vector string la: " << str.size() << endl;
    for(string i : str){
        cout << i << " ";
    }
    // 3. Nhập phần tử từ bàn phím
    int x;
    vector<int> ve;
    for(int i = 0; i < 10; i++){
     
        cout << "\nNhap phan tu thu " << i << ":";
        cin >> x;
        ve.push_back(x);
    }
    for(int i : ve){
        cout << i << " ";
    }
        // 4. khai báo vector với n phần tử chưa biết
    int n;
    int j;
    cout << "\nNhap n: ";
    cin >> n;
    vector<int> vn(n);
    for(int i = 0; i < n; i++){
        cout << "\nNhap phan tu thu " << i + 1 << ": ";
        cin >> vn[i];
    }
    for(int i : vn){
        cout << i << " ";
    }

    // 5. Mảng 2 chiều
    cout << "\nNhap so hang va so cot cho mang 2 chieu: ";
    int r, c;
    cin >> r >> c;
    vector<vector<int>> ar2;
    for(int i = 0; i < r; i++){
        vector<int> row;
        for(int j = 0; j < c; j++){
            cout << "Nhap phan tu hang " << i + 1 << " cot " << j + 1 << ": ";
            int tmp ;
            cin >> tmp;
            row.push_back(tmp);
        }
        ar2.push_back(row);
    }
    cout << endl << "Duyet mang 2 chieu " << endl;
    for(int i = 0 ; i < r; i++){
        for(int j = 0; j < c;j++){
            cout << "Phan tu hang " << i + 1 << " Cot " << j + 1 << ": " <<ar2[i][j] <<endl;
        }
        cout << endl;
    }
    return 0;
}