#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int *array = new int[n];

    // nhập mảng
    for (int i = 0; i < n; i++)
    {
        cout << array[i];
    }

    // in mảng
    for (int i = 0; i < n; i++)
    {
        cout << array[i];
    }

    // tính tổng
    int *sum = new int;
    *sum = 0;
    for (int i = 0; i < n; i++)
    {
        *sum += array[i];
    }
    cout<< *sum << endl;
    delete sum;

    
    delete[] array;
    return 0;
}