#include <iostream>
using namespace std;

int main()
{
    long int n;
    cin >> n;
    vector<bool> composites(n + 1, false);
    composites[1] = true;
    for (int i = 2; i * i <= n; i++)
    {
        if (!composites[i])
        {
            for (int j = i * i; j <= n; j += i)
                composites[j] = true;
        }
    }
    for (int x = 4; x < n; x++)
    {
        int y = n - x;
        if (composites[x] && composites[y])
        {
            cout << x << " " << y << endl;
            break;
        }
    }
    return 0;
}