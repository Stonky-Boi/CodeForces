#include <iostream>
#include <vector>
#include <algorithm>
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
        long long sum = 0;
        for (int &i : a)
        {
            cin >> i;
            sum += i;
        }
        sort(a.begin(), a.end(), greater<int>());
        long long x = sum / 2;
        long long moves = sum - x;
        for (const int &i : a)
        {
            if (x <= 0)
                break;
            moves++;
            x -= i;
        }
        cout << moves << endl;
    }
    return 0;
}