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
        int s1 = n + 1, s2 = n + 1; // last element of subsequences
        int penalty = 0;
        for (int &i : a)
        {
            cin >> i;
            if (s1 > s2)
                swap(s1, s2);
            if (i <= s1)
                s1 = i;
            else if (i <= s2)
                s2 = i;
            else
            {
                s1 = i;
                penalty++;
            }
        }
        cout << penalty << endl;
    }
    return 0;
}