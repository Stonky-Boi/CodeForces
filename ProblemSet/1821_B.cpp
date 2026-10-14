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
        vector<int> a(n), A(n);
        for (int &i : a)
            cin >> i;
        for (int &i : A)
            cin >> i;
        int l = -1, r = -1;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == A[i])
                continue;
            if (l == -1)
                l = i;
            r = i;
        }
        while (l - 1 >= 0 && A[l - 1] <= A[l])
            l--;
        while (r + 1 < n && A[r] <= A[r + 1])
            r++;
        cout << l + 1 << " " << r + 1 << endl;
    }
    return 0;
}