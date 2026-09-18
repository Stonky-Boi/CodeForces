#include <iostream>
using namespace std;

bool prime(int x)
{
    if (x < 2)
        return false;
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            return false;
            break;
        }
    }
    return true;
}

int main()
{
    int n, m;
    cin >> n >> m;
    bool next = true;
    for (int i = n + 1; i < m; i++)
    {
        if (prime(i))
        {
            next = false;
            break;
        }
    }
    if (next && prime(m))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}