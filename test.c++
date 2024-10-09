#include <iostream>
#include <iomanip>
using namespace std;
class HCN
{
private:
    float d, r;

public:
    void nhap();
    void inthongtin();
    float tinhchuvi();
    float tinhdientich();
    bool check();
};
void HCN::nhap()
{
    cout << "Nhap chieu rong: ";
    cin >> r;
    cout << "Nhap chieu dai: ";
    cin >> d;
}
void HCN::inthongtin()
{
    cout << "Chieu dai la: " << d << endl;
    cout << "Chieu rong la: " << r << endl;
    cout << "Chu vi HCN : " << tinhchuvi();
    cout << "Dien tich : " << tinhdientich();
    cout << "Dem: " << check();
}
float HCN::tinhchuvi()
{
    return 2 * (d + r);
}
float HCN::tinhdientich()
{
    return d * r;
}
bool HCN::check()
{
    if (r == 5)
        return true; // nếu đúng sẽ trả về true và thoát chương trình
    // nếu sai sẽ thoát if và chạy xuống dưới
    else
        return false;
}

int main()
{
    HCN a[100];
    int n;
    cout << "Nhap so HCN : ";
    cin >> n;
    cout << "Nhap thong tin cua HCN  " << endl;
    for (int i = 1; i < n; i++)
    {
        cout << " HCN thu i " << i + 1 << endl;
        a[i].nhap();
        cout << endl;
    }
    cout << "In thong tin cua HCN " << endl;
    for (int i = 1; i < n; i++)
    {
        cout << "HCN thu i " << i + 1 << endl;
        a[i].inthongtin();
        cout << endl;
    }
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i].check() == 1)
        {
            dem++;
        }
    }
    cout << "So HCN co chieu rong = 5 la: " << dem;
    return 0;
}