#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string x, y;
        cin >> x >> y;
        int min_cost[2] = {0, 1000000000};
        for (int i = 0; i < x.size(); i++)
        {
            int next[2] = {1000000000, 1000000000};
            for (int prev : {0, 1})
            {
                for (int curr : {0, 1})
                {
                    int required_x = prev ^ curr;
                    int cost = min_cost[prev];
                    if (x[i] - '0' != required_x)
                        cost++;
                    if (y[i] - '0' != curr)
                        cost++;
                    next[curr] = min(next[curr], cost);
                }
            }
            min_cost[0] = next[0];
            min_cost[1] = next[1];
        }
        cout << min(min_cost[0], min_cost[1]) << endl;
    }
    return 0;
}