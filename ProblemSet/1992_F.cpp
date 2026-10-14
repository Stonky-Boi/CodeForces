#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for (int &i : a)
            cin >> i;
        vector<int> used(x + 1, 0);
        vector<int> st = {1};
        used[1] = 1;
        int bad = 1;
        for (int i = 0; i < n; i++)
        {
            if (x % a[i] != 0)
                continue;
            int size = st.size();
            bool good = false;
            for (int j = 0; j < size; j++)
            {
                int d = st[j];
                if (d > x / a[i])
                    continue;
                int nd = d * a[i];
                if (nd == x)
                {
                    good = true;
                    break;
                }
                if (!used[nd])
                {
                    used[nd] = 1;
                    st.push_back(nd);
                }
            }
            if (good)
            {
                bad++;
                for (const int &d : st)
                    used[d] = 0;
                st.clear();
                st.push_back(1);
                used[1] = 1;
                if (a[i] != 1)
                {
                    st.push_back(a[i]);
                    used[a[i]] = 1;
                }
            }
        }
        cout << bad << endl;
    }
    return 0;
}