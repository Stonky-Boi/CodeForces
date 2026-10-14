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
        vector<int> component(n);
        for (int i = 0; i < n; i++)
            component[i] = i;
        vector<pair<int, int>> operations(n);
        for (int x = n - 1; x >= 1; x--)
        {
            vector<int> first(x, -1);
            for (int i = 0; i < component.size(); i++)
            {
                int v = component[i];
                int r = a[v] % x;
                if (first[r] == -1)
                    first[r] = i;
                else
                {
                    int j = first[r];
                    operations[x] = {component[j] + 1, v + 1};
                    component.erase(component.begin() + i);
                    break;
                }
            }
        }
        cout << "YES" << endl;
        for (int i = 1; i < n; i++)
            cout << operations[i].first << " " << operations[i].second << endl;
    }
    return 0;
}