#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;
        int erased = n + 1;
        for (char c = 'a'; c <= 'z'; c++)
        {
            int removed = 0;
            bool possible = true;
            int l = 0, r = n - 1;
            while (l <= r)
            {
                if (s[l] == s[r])
                {
                    l++;
                    r--;
                }
                else if (s[l] == c)
                {
                    l++;
                    removed++;
                }
                else if (s[r] == c)
                {
                    r--;
                    removed++;
                }
                else
                {
                    possible = false;
                    break;
                }
            }
            if (possible)
                erased = min(erased, removed);
        }
        cout << (erased == n + 1 ? -1 : erased) << endl;
    }
    return 0;
}