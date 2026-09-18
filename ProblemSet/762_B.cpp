#include <iostream>
using namespace std;

int main()
{
    int a, b, c, m;
    cin >> a >> b >> c;
    cin >> m;
    pair<long long, string> mouse[m];
    for (auto &[val, port] : mouse)
        cin >> val >> port;
    sort(mouse, mouse + m);
    long long cost = 0, computers = 0;
    for (auto &[val, port] : mouse)
    {
        if (port == "USB" && a > 0)
        {
            a--;
            cost += val;
            computers++;
        }
        else if (port == "PS/2" && b > 0)
        {
            b--;
            cost += val;
            computers++;
        }
        else if (c > 0)
        {
            c--;
            cost += val;
            computers++;
        }
    }
    cout << computers << " " << cost << endl;
    return 0;
}