#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Hocsinh
{
    string ms;
    string ht;
    string qq;
    float td;
};

void nhapHocsinh(Hocsinh &hs)
{
    cout << "Nhap ma so (7 ky tu): ";
    cin >> hs.ms;
    cout << "Nhap ho va ten (toi da 30 ky tu): ";
    cin.ignore();
    getline(cin, hs.ht);
    cout << "Nhap que quan (toi da 30 ky tu): ";
    getline(cin, hs.qq);
    cout << "Nhap tong diem: ";
    cin >> hs.td;
}

void nhapDanhSach(vector<Hocsinh> &ds, int n)
{
    for (int i = 0; i < n; ++i)
    {
        Hocsinh hs;
        cout << "Nhap thong tin hoc sinh thu " << i + 1 << ":\n";
        nhapHocsinh(hs);
        ds.push_back(hs);
    }
}

bool soSanhDiemGiamDan(const Hocsinh &a, const Hocsinh &b)
{
    return a.td > b.td;
}

void inDanhSachTheoDiem(vector<Hocsinh> &ds)
{
    sort(ds.begin(), ds.end(), soSanhDiemGiamDan);
    cout << "\nDanh sach hoc sinh theo thu tu giam dan cua tong diem:\n";
    for (const auto &hs : ds)
    {
        cout << "Ma so: " << hs.ms << ", Ho va ten: " << hs.ht << ", Que quan: " << hs.qq << ", Tong diem: " << hs.td << endl;
    }
}

void inDanhSachQueNamDinh(const vector<Hocsinh> &ds)
{
    cout << "\nDanh sach hoc sinh co que quan tai Nam Dinh:\n";
    for (const auto &hs : ds)
    {
        if (hs.qq == "Nam Dinh")
        {
            cout << "Ma so: " << hs.ms << ", Ho va ten: " << hs.ht << ", Que quan: " << hs.qq << ", Tong diem: " << hs.td << endl;
        }
    }
}

int main()
{
    int n;
    cout << "Nhap so luong hoc sinh: ";
    cin >> n;
    vector<Hocsinh> ds;
    nhapDanhSach(ds, n);
    inDanhSachTheoDiem(ds);
    inDanhSachQueNamDinh(ds);
    return 0;
}
