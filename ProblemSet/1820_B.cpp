#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.size();
        s += s;
        int max_block = 0, curr_block = 0;
        for (const char &c : s)
        {
            curr_block = (c == '1' ? curr_block + 1 : 0);
            max_block = max(max_block, curr_block);
        }
        if (max_block == 2 * n)
        {
            cout << 1ll * n * n << endl;
            continue;
        }
        int a = (max_block + 1) / 2;
        int b = (max_block + 2) / 2;
        cout << 1ll * a * b << endl;
    }
    return 0;
}