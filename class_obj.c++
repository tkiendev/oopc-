#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
class HCN
{
    // riêng tư
private:
    float d, r;
    // định nghĩa các hàm thành phần
public:
    void nhap();
    void xuat();
    float chu_vi();
    float dien_tich();
    bool check_r();
};
void HCN::nhap()
{
    cin >> d >> r;
}

void HCN::xuat()
{
    cout << "chieu dai: " << d << endl
         << "chieu trong " << r << endl;
}

float HCN::dien_tich()
{
    return d * r;
}
float HCN::chu_vi()
{
    return (d + r) * 2;
}
bool check_r()
{
    if (r == 5)
        return true;
    return false;
}
int main()
{
    vector<HCN> a;
    HCN h1;
    int n;
    cin >> n;
    cout << "nhap thong tin cua doi tuong" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "nhap hinh so: " << i + 1 << endl;
        h1.nhap();
        a.push_back(h1);
    }

    int len = a.size();
    cout << "=================in thong tin HCN================" << endl;
    for (int i = 0; i < len; i++)
    {
        cout << "hinh chu nhat so: " << i + 1 << endl;
        a[i].xuat();
    }

    int count = 0;
    for (int i = 0; i < len; i++)
    {
        bool ket_qua = a[i].check_r();
        if (ket_qua)
        {
            count++;
        }
    }
    cout << "hinh co chieu rong = 5 " << count;
    return 0;
}