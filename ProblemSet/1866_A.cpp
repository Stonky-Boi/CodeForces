#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int closest = 1e6;
    for (int &i : a)
    {
        cin >> i;
        closest = min(closest, abs(i - 0));
    }
    cout << closest << endl;
    return 0;
}