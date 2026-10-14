#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int &i : a)
            cin >> i;
        bool exists = false;
        for (const int i : a)
        {
            if (i == k)
            {
                exists = true;
                break;
            }
        }
        cout << (exists ? "YES" : "NO") << endl;
    }
    return 0;
}