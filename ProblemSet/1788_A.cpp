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
        int twos = 0;
        for (int &i : a)
        {
            cin >> i;
            twos += (i == 2);
        }
        int k = -1;
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            count += (a[i] == 2);
            if (count * 2 == twos)
            {
                k = i + 1;
                break;
            }
        }
        cout << k << endl;
    }
    return 0;
}