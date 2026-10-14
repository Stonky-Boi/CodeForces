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
        for (int &i : a)
            cin >> i;
        int skip_points = a[0];
        int block = 0;
        for (int i = 1; i < n; i++)
        {
            if (a[i] == 1)
                block++;
            else
            {
                skip_points += block / 3;
                block = 0;
            }
        }
        skip_points += block / 3;
        cout << skip_points << endl;
    }
    return 0;
}