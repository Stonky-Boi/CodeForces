#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int m = 2 * n;
    vector<int> c(m);
    for (int i = 0; i < m; i++)
        cin >> c[i];
    vector<int> next(m, m);
    stack<int> st;
    for (int i = m - 1; i >= 0; i--)
    {
        while (!st.empty() && c[st.top()] < c[i])
            st.pop();
        if (!st.empty())
            next[i] = st.top();
        st.push(i);
    }
    vector<int> length;
    vector<pair<int, int>> blocks;
    int position = 0;
    while (position < m)
    {
        int end = next[position];
        if (end == m)
            end = m;
        blocks.push_back({position, end});
        length.push_back(end - position);
        position = end;
    }
    int k = length.size();
    vector<vector<bool>> dp(k + 1, vector<bool>(n + 1, false));
    dp[0][0] = true;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            dp[i + 1][j] = dp[i][j];
            if (j >= length[i] && dp[i][j - length[i]])
                dp[i + 1][j] = true;
        }
    }
    if (!dp[k][n])
    {
        cout << -1 << endl;
        return 0;
    }
    vector<bool> take(k, false);
    int remaining = n;
    for (int i = k; i > 0; i--)
    {
        if (dp[i - 1][remaining])
            take[i - 1] = false;
        else
        {
            take[i - 1] = true;
            remaining -= length[i - 1];
        }
    }
    vector<int> a, b;
    for (int i = 0; i < k; i++)
    {
        for (int j = blocks[i].first; j < blocks[i].second; j++)
        {
            if (take[i])
                a.push_back(c[j]);
            else
                b.push_back(c[j]);
        }
    }
    for (const int &i : a)
        cout << i << " ";
    cout << endl;
    for (const int &i : b)
        cout << i << " ";
    cout << endl;
    return 0;
}