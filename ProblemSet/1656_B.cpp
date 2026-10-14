#include <iostream>
#include <vector>
#include <set>
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
        set<int> seen;
        bool possible = false;
        for (const int &i : a)
        {
            if (seen.find(i - k) != seen.end() || seen.find(i + k) != seen.end())
            {
                possible = true;
                break;
            }
            seen.insert(i);
        }
        cout << (possible ? "YES" : "NO") << endl;
    }
    return 0;
}