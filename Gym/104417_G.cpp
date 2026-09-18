#include <iostream>
#include <map>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        long int n;
        cin >> n;
        map<int, vector<int>> a;
        for (int i = 1; i <= n; ++i)
        {
            int t;
            cin >> t;
            a[i - t].push_back(t);
        }
        long long int weight = 0;
        for (auto it = a.begin(); it != a.end(); it++)
        {
            vector<int> temp = it->second;
            sort(temp.rbegin(), temp.rend());
            for (int i = 0; i + 1 < temp.size(); i += 2)
            {
                int sum = temp[i] + temp[i + 1];
                if (sum <= 0)
                    break;
                weight += sum;
            }
        }
        cout << weight << endl;
    }
    return 0;
}