#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

struct NS
{
    int ngay;
    int thang;
    int nam;
};

class KH
{
private:
    char ht[30];
    NS ns;
    char cmt[10];
    char k[50];

public:
    void nhap()
    {
        cout << "Nhap ho ten: ";
        cin.ignore();
        cin.getline(ht, 30);
        cout << "Nhap ngay sinh (ngay thang nam): ";
        cin >> ns.ngay >> ns.thang >> ns.nam;
        cin.ignore();
        cout << "Nhap so CMT: ";
        cin.getline(cmt, 10);
        cout << "Nhap ho khau: ";
        cin.getline(k, 50);
    }

    void xuat()
    {
        cout << "Ho ten: " << ht << "\n"
             << "Ngay sinh: " << ns.ngay << "/" << ns.thang << "/" << ns.nam << "\n"
             << "So CMT: " << cmt << "\n"
             << "Ho khau: " << k << "\n";
    }

    char *get_ht()
    {
        return ht;
    }

    NS get_ns()
    {
        return ns;
    }
};

bool compareByName(KH a, KH b)
{
    return strcmp(a.get_ht(), b.get_ht()) < 0;
}

int main()
{
    int n;
    cout << "Nhap so luong khach hang: ";
    cin >> n;

    vector<KH> ds_kh(n);

    for (int i = 0; i < n; ++i)
    {
        cout << "Nhap thong tin khach hang thu " << i + 1 << ":\n";
        ds_kh[i].nhap();
    }

    sort(ds_kh.begin(), ds_kh.end(), compareByName);

    cout << "\nDanh sach khach hang theo thu tu tang dan cua ho ten:\n";
    for (int i = 0; i < n; ++i)
    {
        ds_kh[i].xuat();
    }

    cout << "\nDanh sach khach hang co sinh nhat thang 12:\n";
    for (int i = 0; i < n; ++i)
    {
        if (ds_kh[i].get_ns().thang == 12)
        {
            ds_kh[i].xuat();
        }
    }

    return 0;
}
