#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b(n);
        for (int &i : a)
            cin >> i;
        for (int &i : b)
            cin >> i;
        int sum = 0, maximum = 0;
        int points = 0;
        for (int i = 0; i < min(n, k); i++)
        {
            sum += a[i];
            maximum = max(maximum, b[i]);
            points = max(points, sum + maximum * (k - i - 1));
        }
        cout << points << endl;
    }
    return 0;
}