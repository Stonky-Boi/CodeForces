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
        long long minimum = 0, maximum = 0;
        for (int &i : a)
        {
            cin >> i;
            minimum += i;
            maximum += (i + x - 1) / x;
        }
        minimum = (minimum + x - 1) / x;
        cout << minimum << " " << maximum << endl;
    }
    return 0;
}