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
        int size = 1;
        int i = 0;
        while (i < n)
        {
            while (i + 1 < n && a[i] == a[i + 1])
                i++;
            if (i == n - 1)
                break;
            if (a[i] < a[i + 1])
            {
                while (i + 1 < n && a[i] <= a[i + 1])
                    i++;
            }
            else
            {
                while (i + 1 < n && a[i] >= a[i + 1])
                    i++;
            }
            size++;
        }
        cout << size << endl;
    }
    return 0;
}