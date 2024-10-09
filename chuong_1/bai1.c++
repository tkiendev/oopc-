// ============ Bài 1 ============

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int array[n];

    // nhập mảng
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    // số chính phương
    for (int i = 0; i < n; i++)
    {
        for (int j = 2; j < array[i]; j++)
        {
            if ((j * j) == array[i])
            {
                cout << array[i] << "\t";
            }
        }
    }

    // đếm số nguyên tố
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (array[i] == 2)
        {
            count++;
            break;
        }
        else
        {
            int check = true;
            for (int j = 2; j < array[i]; j++)
            {
                if (array[i] % j == 0)
                {
                    check = false;
                    break;
                }
            }
            if (check)
                count++;
        }
    }
    cout << count;

    // thêm vào vị trí k
    int k;
    int x;
    cin >> k;
    cin >> x;

    if (k < 0)
        k = 0;
    if (k > n)
        k = n;
    for (int i = n; i > k; i--)
    {
        array[i] = array[i - 1];
    }
    array[k] = x;
    n++;

    // xóa vị trí y trong mảng
    int y;
    if (y < 0)
        y = 0;
    if (y >= n)
        y = n - 1;
    for (int i = y; i < n - 1; i++)
    {
        array[i] = array[i + 1];
    }
    n--;

    // giảm dần
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (array[i] < array[j])
            {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
        cout << array[i] << "\t";
    }

    return 0;
}