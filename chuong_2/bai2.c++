#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class GV
{
private:
    char ht[30];
    int t;
    char bc[15];
    char cn[20];
    float bl;

public:
    void nhap()
    {
        cout << "Nhap ho ten: ";
        cin.ignore();
        cin.getline(ht, 30);
        cout << "Nhap tuoi: ";
        cin >> t;
        cin.ignore();
        cout << "Nhap bang cap: ";
        cin.getline(bc, 15);
        cout << "Nhap chuyen nganh: ";
        cin.getline(cn, 20);
        cout << "Nhap bac luong: ";
        cin >> bl;
    }

    void xuat()
    {
        cout << "Ho ten: " << ht << "\n"
             << "Tuoi: " << t << "\n"
             << "Bang cap: " << bc << "\n"
             << "Chuyen nganh: " << cn << "\n"
             << "Bac luong: " << bl << "\n"
             << "Tien luong co ban: " << tinh_luong() << "\n";
    }

    float tinh_luong()
    {
        return bl * 610;
    }

    float get_luong()
    {
        return tinh_luong();
    }

    string get_chuyen_nganh()
    {
        return string(cn);
    }
};

bool compareByChuyenNganh(GV a, GV b)
{
    return a.get_chuyen_nganh() < b.get_chuyen_nganh();
}

int main()
{
    int n;
    cout << "Nhap so luong giao vien: ";
    cin >> n;

    vector<GV> ds_gv(n);

    for (int i = 0; i < n; ++i)
    {
        cout << "Nhap thong tin giao vien thu " << i + 1 << ":\n";
        ds_gv[i].nhap();
    }

    cout << "\nDanh sach giao vien co tien luong nho hon 2000:\n";
    for (int i = 0; i < n; ++i)
    {
        if (ds_gv[i].get_luong() < 2000)
        {
            ds_gv[i].xuat();
        }
    }

    sort(ds_gv.begin(), ds_gv.end(), compareByChuyenNganh);

    cout << "\nDanh sach giao vien sap xep theo chuyen nganh:\n";
    for (int i = 0; i < n; ++i)
    {
        ds_gv[i].xuat();
    }

    return 0;
}
