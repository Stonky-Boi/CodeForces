#include <iostream>
#include <vector>
using namespace std;

struct person
{
    int a, b;
};

bool valid(vector<person> &f, int k)
{
    int rank = 0;
    for (const auto &[a, b] : f)
    {
        if (rank == k)
            break;
        if (b >= rank && a >= k - rank - 1)
            rank++;
    }
    return rank == k;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<person> f(n);
        for (auto &[a, b] : f)
            cin >> a >> b;
        int l = 0, r = n;
        int people;
        while (l <= r)
        {
            int m = l + (r - l) / 2;
            if (valid(f, m))
            {
                people = m;
                l = m + 1;
            }
            else
                r = m - 1;
        }
        cout << people << endl;
    }
    return 0;
}