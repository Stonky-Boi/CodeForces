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
        int frequency[n + 1] = {0};
        long int result[n + 2] = {0};
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] <= n)
                frequency[a[i]]++;
        }
        long int mex = 0;
        while (frequency[mex] > 0)
            mex++;
        for (int i = 0; i <= mex; i++)
        {
            int left = frequency[i];
            int right = n - i;
            if (left <= right)
            {
                result[left] += 1;
                result[right + 1] -= 1;
            }
        }
        for (int k = 1; k <= n; k++)
            result[k] += result[k - 1];
        for (int k = 0; k <= n; k++)
            cout << result[k] << " ";
        cout << endl;
    }
    return 0;
}