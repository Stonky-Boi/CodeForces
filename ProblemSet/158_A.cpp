#include <iostream>
using namespace std;

int main()
{
    int n, k;
    int participants = 0;
    cin >> n >> k;
    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        a.push_back(t);
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= a[k - 1] && a[i] > 0)
            participants++;
    }
    cout << participants << endl;
    return 0;
}