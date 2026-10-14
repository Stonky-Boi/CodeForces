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
        vector<vector<int>> a(n);
        vector<int> freq(2e5 + 1, 0);
        for (vector<int> &v : a)
        {
            int k;
            cin >> k;
            v.resize(k);
            for (int &i : v)
            {
                cin >> i;
                freq[i]++;
            }
        }
        bool possible = false;
        for (vector<int> &v : a)
        {
            bool unique = false;
            for (const int &i : v)
            {
                if (freq[i] == 1)
                {
                    unique = true;
                    break;
                }
            }
            if (!unique)
            {
                possible = true;
                break;
            }
        }
        cout << (possible ? "Yes" : "No") << endl;
    }
    return 0;
}