#include <iostream>
#include <set>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, xk, yk, xq, yq;
        cin >> a >> b >> xk >> yk >> xq >> yq;
        set<pair<int, int>> king, queen;
        pair<int, int> direction[4] = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
        for (const auto &[dx, dy] : direction)
        {
            king.insert({xk + a * dx, yk + b * dy});
            king.insert({xk + b * dx, yk + a * dy});
            queen.insert({xq + a * dx, yq + b * dy});
            queen.insert({xq + b * dx, yq + a * dy});
        }
        int positions = 0;
        for (const auto &[x, y] : king)
        {
            if (queen.find({x, y}) != queen.end())
                positions++;
        }
        cout << positions << endl;
    }
    return 0;
}