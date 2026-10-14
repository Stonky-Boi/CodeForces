#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        int xor_value = 0;
        for (int &i : a)
        {
            cin >> i;
            xor_value ^= i;
        }
        if (xor_value == 0)
        {
            cout << "YES" << endl;
            continue;
        }
        bool possible = false;
        int prefix = 0;
        for (int i = 0; i < n - 1; i++)
        {
            prefix ^= a[i];
            int middle = 0;
            for (int j = i + 1; j < n - 1; j++)
            {
                middle ^= a[j];
                int suffix = xor_value ^ prefix ^ middle;
                if (prefix == middle && middle == suffix)
                {
                    possible = true;
                    break;
                }
            }
            if (possible)
                break;
        }
        cout << (possible ? "YES" : "NO") << endl;
    }
    return 0;
}