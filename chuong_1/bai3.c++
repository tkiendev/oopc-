// ================= Bài 3 =================

#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char arrayStr[100];
    char arrayStr2[100];

    // nhập chuỗi
    cout << "nhập mảng 1:";
    cin.getline(arrayStr, 100);
    cout << "\nnhập mảng 2: ";
    cin.getline(arrayStr2, 100);

    // so sánh chuỗi
    int length = strlen(arrayStr);
    int length_2 = strlen(arrayStr2);

    cout << (length == length_2) ? "2 mảng bằng nhau" : "2 mảng không bằng nhau";

    return 0;
}
