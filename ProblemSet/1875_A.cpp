#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, n;
        cin >> a >> b >> n;
        vector<int> x(n);
        long long time = b;
        for (int &i : x)
        {
            cin >> i;
            time += min(a - 1, i);
        }
        cout << time << endl;
    }
    return 0;
}