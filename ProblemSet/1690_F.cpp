#include <iostream>
#include <vector>
using namespace std;

long long gcd(long long a, long long b)
{
    while (b)
    {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

long long lcm(long long a, long long b)
{
    return (a / gcd(a, b)) * b;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;
        vector<int> p(n);
        for (int &i : p)
        {
            cin >> i;
            i--;
        }
        vector<bool> visited(n, false);
        long long operations = 1;
        for (int i = 0; i < n; i++)
        {
            if (visited[i])
                continue;
            vector<int> cycle;
            int curr = i;
            while (!visited[curr])
            {
                visited[curr] = true;
                cycle.push_back(curr);
                curr = p[curr];
            }
            int k = cycle.size();
            int period = k;
            for (int d = 1; d <= k; d++)
            {
                if (k % d != 0)
                    continue;
                bool valid = true;
                for (int j = 0; j < k; j++)
                {
                    if (s[cycle[j]] != s[cycle[(j + d) % k]])
                    {
                        valid = false;
                        break;
                    }
                }
                if (valid)
                {
                    period = d;
                    break;
                }
            }
            operations = lcm(operations, period);
        }
        cout << operations << endl;
    }
    return 0;
}