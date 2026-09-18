#include <iostream>
using namespace std;

int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        long long n;
        cin >> n;
        long long l = n - 1;
        long long r = 2 * (n - 1);
        while (l < r)
        {
            long long m = (l + r + 1) / 2;
            long long bridges = (m + 1) / 2;
            long long nodes_in_cycle = n - bridges;
            long long edges_in_cycle = nodes_in_cycle * (nodes_in_cycle - 1) / 2;
            if (m - bridges <= edges_in_cycle)
                l = m;
            else
                r = m - 1;
        }
        cout << l << endl;
    }
}