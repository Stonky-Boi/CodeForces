#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &i : a)
            cin >> i;
        int sum = accumulate(a.begin(), a.end(), 0);
        cout << (sum % 2 == 0 ? "YES" : "NO") << endl;
    }
    return 0;
}