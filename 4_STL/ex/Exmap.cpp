#include<iostream>
#include<map>
using namespace std;
    //for(int i = 0; i < 14;i++){
    //     mp[arr[i]] = 1;
    // }
    // cout << "So phan tu khac nhau trong arr la: " << mp.size() << endl;
    // for(auto at : mp){
    //     cout << "mp[" << at.first << "] = " << at.second << endl;
    // }

    // EX2:
    /*
        for(int i = 0; i < 14;i++){
        mp[arr[i]]++;
        }
        for(map<int,int>::iterator it = mp.begin(); it != mp.end();it++){
            cout << (*it).first << " : " << (*it).second << endl;
        }
    
    
    */
   /*
        EX3:
        map<int, int> mp;
    int a[14] = {0};
    for(int i = 0; i < 14;i++){ 
        mp[arr[i]]++;
    }
    for(int i = 0; i < 14;i++){
        if(mp[arr[i]] != 0){
            cout << arr[i] << " Xuat hien " << mp[arr[i]] << " lan. " << endl;
            mp[arr[i]] = 0;
        }
    }
   
   
   */
#define N 4
int main(){
    map<string,string> mp;
    int n; cout << "Nhap so sinh vien can luu tru: "; cin >> n;
    for(int i = 0; i < n; i++){
        string k, v;
        cout << "Nhap mssv thu " << i + 1 << " : ";
        cin >> k;
        cout << "Nhap ten sinh vien thu " << i + 1 << " : ";
        cin >> v;
        //mp.insert(make_pair(k,v));
        //mp.insert({k,v});
        mp[k] = v;
    }    
    string mssv;
    cout << "Nhap mssv can tim: "; cin >> mssv;
    cout << "Ten sinh vien ung voi msss: " << mssv << " la: " << mp[mssv] << endl;
    return 0;
}