#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct person
{
    int a, b;

    bool operator<(const person &other) const
    {
        return b < other.b;
    }
};

class FenwickTree
{
    vector<int> tree;

public:
    FenwickTree(int n) : tree(n + 1, 0) {}

    void add(int i, int x)
    {
        while (i < tree.size())
        {
            tree[i] += x;
            i += i & -i;
        }
    }

    int sum(int i)
    {
        int x = 0;
        while (i > 0)
        {
            x += tree[i];
            i -= i & -i;
        }
        return x;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<person> people(n);
        for (auto &[a, b] : people)
            cin >> a >> b;
        sort(people.begin(), people.end());
        vector<int> values;
        for (const auto &[a, _] : people)
            values.push_back(a);
        sort(values.begin(), values.end());
        FenwickTree bit(n);
        long long greetings = 0;
        int processed = 0;
        for (const auto &[a, _] : people)
        {
            int i = lower_bound(values.begin(), values.end(), a) - values.begin() + 1;
            greetings += processed - bit.sum(i);
            bit.add(i, 1);
            processed++;
        }
        cout << greetings << endl;
    }
    return 0;
}