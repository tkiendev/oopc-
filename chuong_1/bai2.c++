// ================= Bài 2 =================

#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char array[100];

    // nhập mảng
    cin.getline(array, 100);

    // xuất mảng xuôi
    cout << array << endl;

    // xuất mảng ngược
    int lengthArray = strlen(array); // tính độ dài của mảng
    for (int i = lengthArray - 1; i >= 0; i--)
    {
        cout << array[i];
    }

    return 0;
}