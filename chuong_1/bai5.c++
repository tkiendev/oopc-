#include <iostream>
using namespace std;

struct PhanSo
{
    int tu;
    int mau;
};

void nhapPhanSo(PhanSo &ps)
{
    cout << "Nhap tu so: ";
    cin >> ps.tu;
    do
    {
        cout << "Nhap mau so (khac 0): ";
        cin >> ps.mau;
        if (ps.mau == 0)
        {
            cout << "Mau so phai khac 0. Vui long nhap lai.\n";
        }
    } while (ps.mau == 0);
}

PhanSo tongPhanSo(PhanSo ps1, PhanSo ps2)
{
    PhanSo tong;
    tong.tu = ps1.tu * ps2.mau + ps2.tu * ps1.mau;
    tong.mau = ps1.mau * ps2.mau;
    return tong;
}

PhanSo hieuPhanSo(PhanSo ps1, PhanSo ps2)
{
    PhanSo hieu;
    hieu.tu = ps1.tu * ps2.mau - ps2.tu * ps1.mau;
    hieu.mau = ps1.mau * ps2.mau;
    return hieu;
}

void rutGon(PhanSo &ps)
{
    int a = abs(ps.tu);
    int b = abs(ps.mau);
    while (a != b)
    {
        if (a > b)
            a -= b;
        else
            b -= a;
    }
    ps.tu /= a;
    ps.mau /= a;
}

void xuatPhanSo(PhanSo ps)
{
    rutGon(ps);
    cout << ps.tu << "/" << ps.mau << endl;
}

int main()
{
    int n;
    cout << "Nhap so luong phan so: ";
    cin >> n;
    PhanSo *ps = new PhanSo[n];
    for (int i = 0; i < n; ++i)
    {
        cout << "Nhap phan so thu " << i + 1 << ":\n";
        nhapPhanSo(ps[i]);
    }

    PhanSo tong = {0, 1};
    PhanSo hieu = ps[0];
    for (int i = 0; i < n; ++i)
    {
        tong = tongPhanSo(tong, ps[i]);
        if (i > 0)
        {
            hieu = hieuPhanSo(hieu, ps[i]);
        }
    }

    cout << "Tong cac phan so: ";
    xuatPhanSo(tong);
    cout << "Hieu cac phan so: ";
    xuatPhanSo(hieu);

    delete[] ps;
    return 0;
}
