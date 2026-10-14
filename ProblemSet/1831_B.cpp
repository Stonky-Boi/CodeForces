#include <iostream>
#include <vector>
using namespace std;

vector<int> largest_subarray(vector<int> &arr, int n)
{
    vector<int> length(2 * n + 1, 0);
    int count = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i - 1] == arr[i])
            count++;
        else
        {
            length[arr[i - 1]] = max(length[arr[i - 1]], count);
            count = 1;
        }
    }
    length[arr[n - 1]] = max(length[arr[n - 1]], count);
    return length;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int &i : a)
            cin >> i;
        for (int &i : b)
            cin >> i;
        vector<int> length_a = largest_subarray(a, n);
        vector<int> length_b = largest_subarray(b, n);
        int length = 1;
        for (int i = 1; i <= 2 * n; i++)
            length = max(length, length_a[i] + length_b[i]);
        cout << length << endl;
    }
    return 0;
}