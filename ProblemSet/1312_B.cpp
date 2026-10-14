#include <iostream>
#include <vector>
#include <algorithm>
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
        sort(a.begin(), a.end(), greater<int>());
        for (const int &i : a)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}