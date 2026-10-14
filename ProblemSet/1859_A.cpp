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
        for (int &i : a)
            cin >> i;
        vector<int> b, c;
        int minimum = *min_element(a.begin(), a.end()); // maximum also works
        for (const int &i : a)
        {
            if (i == minimum)
                b.push_back(i);
            else
                c.push_back(i);
        }
        if (c.empty())
            cout << -1 << endl;
        else
        {
            cout << b.size() << " " << c.size() << endl;
            for (const int &i : b)
                cout << i << " ";
            cout << endl;
            for (const int &i : c)
                cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}