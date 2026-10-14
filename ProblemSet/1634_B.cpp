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
        long long y;
        cin >> n >> x >> y;
        vector<int> a(n);
        long long sum = 0;
        for (int &i : a)
        {
            cin >> i;
            sum += i;
        }
        cout << ((sum + x) % 2 == y % 2 ? "Alice" : "Bob") << endl;
    }
    return 0;
}