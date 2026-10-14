#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        long long pos;
        cin >> s >> pos;
        int n = s.size();
        int length = n;
        while (pos > length)
        {
            pos -= length;
            length--;
        }
        int removals = n - length;
        string st;
        for (const char &c : s)
        {
            while (!st.empty() && st.back() > c && removals > 0)
            {
                st.pop_back();
                removals--;
            }
            st.push_back(c);
        }
        while (removals > 0)
        {
            st.pop_back();
            removals--;
        }
        cout << st[pos - 1];
    }
    return 0;
}