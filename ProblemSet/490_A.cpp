#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> programming, maths, pe;
    int t;
    for (int i = 1; i <= n; i++)
    {
        cin >> t;
        if (t == 1)
            programming.push_back(i);
        else if (t == 2)
            maths.push_back(i);
        else
            pe.push_back(i);
    }
    int w = min(min(programming.size(), maths.size()), pe.size());
    cout << w << endl;
    for (int i = 0; i < w; i++)
        cout << programming[i] << " " << maths[i] << " " << pe[i] << endl;
    return 0;
}