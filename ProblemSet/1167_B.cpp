#include <iostream>
#include <vector>
using namespace std;

vector<int> v = {4, 8, 15, 16, 23, 42};

int query(int i, int j)
{
    int x;
    cout << "? " << i << " " << j << endl;
    cin >> x;
    return x;
}

bool exists(int x)
{
    for (int i : v)
    {
        if (x == i)
            return true;
    }
    return false;
}

int main()
{
    int p12 = query(1, 2);
    int p13 = query(1, 3);
    int a[6];
    for (int i : v)
    {
        if (p12 % i == 0 && p13 % i == 0)
        {
            int y = p12 / i;
            int z = p13 / i;
            if (exists(y) && exists(z) && y != i && z != i && y != z)
            {
                a[0] = i;
                break;
            }
        }
    }
    a[1] = p12 / a[0];
    a[2] = p13 / a[0];
    int p14 = query(1, 4);
    int p15 = query(1, 5);
    a[3] = p14 / a[0];
    a[4] = p15 / a[0];
    for (int i : v)
    {
        bool used = false;
        for (int j = 0; j < 5; j++)
        {
            if (a[j] == i)
                used = true;
        }
        if (!used)
        {
            a[5] = i;
            break;
        }
    }
    cout << "! ";
    for (int i : a)
        cout << i << " ";
    cout << endl;
}