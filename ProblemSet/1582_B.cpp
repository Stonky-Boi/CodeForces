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
        vector<int> a(n);
        int zeroes = 0, ones = 0;
        for (int &i : a)
        {
            cin >> i;
            if (i == 0)
                zeroes++;
            else if (i == 1)
                ones++;
        }
        cout << (1ll << zeroes) * ones << endl;
    }
    return 0;
}