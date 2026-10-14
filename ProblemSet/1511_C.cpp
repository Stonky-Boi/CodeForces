#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    vector<int> index(51, -1);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (index[a[i]] == -1)
            index[a[i]] = i;
    }
    while (q--)
    {
        int t;
        cin >> t;
        cout << index[t] + 1 << " ";
        for (int &i : index)
        {
            if (i < index[t])
                i++;
        }
        index[t] = 0;
    }
    cout << endl;
    return 0;
}