#include <iostream>
#include <set>
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
        set<char> distinct;
        int k = 0;
        while (k < n)
        {
            if (distinct.find(s[k]) == distinct.end())
            {
                distinct.insert(s[k]);
                k++;
            }
            else
                break;
        }
        bool balanced = true;
        for (int i = k; i < n; i++)
        {
            if (s[i] != s[i - k])
            {
                balanced = false;
                break;
            }
        }
        cout << (balanced ? "YES" : "NO") << endl;
    }
    return 0;
}