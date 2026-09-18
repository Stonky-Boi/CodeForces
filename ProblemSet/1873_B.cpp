#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int maximum_product = 0;
        for (int i = 0; i < n; i++)
        {
            int current_product = 1;
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    current_product *= (a[j] + 1);
                else
                    current_product *= a[j];
            }
            maximum_product = max(maximum_product, current_product);
        }
        cout << maximum_product << endl;
    }
    return 0;
}