#include <iostream>
#include <vector>
#include <map>
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
        map<int, int> freq;
        for (int &i : a)
        {
            cin >> i;
            freq[i]++;
        }
        bool possible = false;
        if (freq.size() == 1)
            possible = true;
        else if (freq.size() == 2)
        {
            int f1 = freq.begin()->second;
            int f2 = freq.rbegin()->second;
            if (n % 2 == 0)
                possible = (f1 == n / 2 && f2 == n / 2);
            else
                possible = (f1 == (n + 1) / 2 && f2 == n / 2) || (f2 == (n + 1) / 2 && f1 == n / 2);
        }
        cout << (possible ? "Yes" : "No") << endl;
    }
    return 0;
}