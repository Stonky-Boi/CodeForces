#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n), position(n + 1);
    for (int &x : a)
        cin >> x;
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        position[b[i]] = i;
    }
    int fined = 0;
    int max_exit = -1;
    for (const int &i : a)
    {
        if (position[i] < max_exit)
            fined++;
        max_exit = max(max_exit, position[i]);
    }
    cout << fined << endl;
}