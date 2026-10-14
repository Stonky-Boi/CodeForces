#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> w(n);
        for (int &i : w)
            cin >> i;
        int l = 0, r = n - 1;
        int alice = w[0], bob = w[n - 1];
        int candies = 0;
        while (l < r)
        {
            if (alice == bob)
                candies = max(candies, l + 1 + n - r);
            if (alice <= bob)
                alice += w[++l];
            else
                bob += w[--r];
        }
        cout << candies << endl;
    }
    return 0;
}