#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long int n, k;
        cin >> n >> k;
        bool a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int hikes = 0, block_size = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == 1)
            {
                hikes += (block_size + 1) / (k + 1);
                block_size = 0;
                continue;
            }
            else
                block_size++;
        }
        hikes += (block_size + 1) / (k + 1);
        cout << hikes << endl;
    }
    return 0;
}