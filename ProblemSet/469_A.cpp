#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n] = {0};
    int p;
    cin >> p;
    while (p--)
    {
        int level_pass;
        cin >> level_pass;
        a[level_pass - 1] = 1;
    }
    int q;
    cin >> q;
    while (q--)
    {
        int level_pass;
        cin >> level_pass;
        a[level_pass - 1] = 1;
    }
    bool pass = true;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            pass = false;
            break;
        }
    }
    if (pass)
        cout << "I become the guy." << endl;
    else
        cout << "Oh, my keyboard!" << endl;
    return 0;
}