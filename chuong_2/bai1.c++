#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class HinhChuNhat
{
public:
    double chieu_dai;
    double chieu_rong;
    double dien_tich;
    double chu_vi;

    HinhChuNhat(double dai, double rong)
    {
        chieu_dai = dai;
        chieu_rong = rong;
        dien_tich = tinh_dien_tich();
        chu_vi = tinh_chu_vi();
    }

    double tinh_dien_tich()
    {
        return chieu_dai * chieu_rong;
    }

    double tinh_chu_vi()
    {
        return 2 * (chieu_dai + chieu_rong);
    }
};

vector<HinhChuNhat> nhap_danh_sach()
{
    vector<HinhChuNhat> ds_hinh_chu_nhat;
    int so_luong;
    cout << "Nhập số lượng hình chữ nhật: ";
    cin >> so_luong;
    for (int i = 0; i < so_luong; ++i)
    {
        double dai, rong;
        cout << "Nhập chiều dài: ";
        cin >> dai;
        cout << "Nhập chiều rộng: ";
        cin >> rong;
        HinhChuNhat hcn(dai, rong);
        ds_hinh_chu_nhat.push_back(hcn);
    }
    return ds_hinh_chu_nhat;
}

void in_thong_tin(const vector<HinhChuNhat> &ds_hinh_chu_nhat)
{
    for (size_t i = 0; i < ds_hinh_chu_nhat.size(); ++i)
    {
        const HinhChuNhat &hcn = ds_hinh_chu_nhat[i];
        cout << "Hình chữ nhật " << i + 1
             << ": dài = " << hcn.chieu_dai
             << ", rộng = " << hcn.chieu_rong
             << ", diện tích = " << hcn.dien_tich
             << ", chu vi = " << hcn.chu_vi << '\n';
    }
}

HinhChuNhat tim_dien_tich_nho(const vector<HinhChuNhat> &ds_hinh_chu_nhat)
{
    return *min_element(ds_hinh_chu_nhat.begin(), ds_hinh_chu_nhat.end(), [](const HinhChuNhat &a, const HinhChuNhat &b)
                        { return a.dien_tich < b.dien_tich; });
}

HinhChuNhat tim_chu_vi_lon_nhat(const vector<HinhChuNhat> &ds_hinh_chu_nhat)
{
    return *max_element(ds_hinh_chu_nhat.begin(), ds_hinh_chu_nhat.end(), [](const HinhChuNhat &a, const HinhChuNhat &b)
                        { return a.chu_vi < b.chu_vi; });
}

int dem_chieu_rong_5(const vector<HinhChuNhat> &ds_hinh_chu_nhat)
{
    return count_if(ds_hinh_chu_nhat.begin(), ds_hinh_chu_nhat.end(), [](const HinhChuNhat &hcn)
                    { return hcn.chieu_rong == 5; });
}

int main()
{
    vector<HinhChuNhat> danh_sach_hcn = nhap_danh_sach();
    in_thong_tin(danh_sach_hcn);

    HinhChuNhat hcn_dien_tich_nho = tim_dien_tich_nho(danh_sach_hcn);
    cout << "Hình chữ nhật có diện tích nhỏ nhất: dài = " << hcn_dien_tich_nho.chieu_dai
         << ", rộng = " << hcn_dien_tich_nho.chieu_rong
         << ", diện tích = " << hcn_dien_tich_nho.dien_tich << '\n';

    HinhChuNhat hcn_chu_vi_lon_nhat = tim_chu_vi_lon_nhat(danh_sach_hcn);
    cout << "Hình chữ nhật có chu vi lớn nhất: dài = " << hcn_chu_vi_lon_nhat.chieu_dai
         << ", rộng = " << hcn_chu_vi_lon_nhat.chieu_rong
         << ", chu vi = " << hcn_chu_vi_lon_nhat.chu_vi << '\n';

    int so_luong_rong_5 = dem_chieu_rong_5(danh_sach_hcn);
    cout << "Số lượng hình chữ nhật có chiều rộng = 5: " << so_luong_rong_5 << '\n';

    return 0;
}