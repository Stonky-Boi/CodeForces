#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long int n;
        cin >> n;
        long int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        vector<long int> arrays;
        arrays.push_back(a[0]);
        for (int i = 0, j = 0; j < n - 1; j++)
        {
            if (arrays[i] + 1 < a[j + 1])
            {
                arrays.push_back(a[j + 1]);
                i++;
            }
        }
        cout << arrays.size() << endl;
    }
    return 0;
}