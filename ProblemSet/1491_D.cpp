#include <iostream>
using namespace std;

int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        if (u > v)
        {
            cout << "NO" << endl;
            continue;
        }
        int balance = 0;
        bool valid = true;
        for (int i = 0; i < 30; i++)
        {
            if ((u >> i) & 1)
                balance++;
            if ((v >> i) & 1)
                balance--;
            if (balance < 0)
            {
                valid = false;
                break;
            }
        }
        cout << (valid ? "YES" : "NO") << endl;
    }
    return 0;
}