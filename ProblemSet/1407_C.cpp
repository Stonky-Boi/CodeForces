#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> p(n);
    int max_index = 0;
    for (int i = 1; i < n; i++)
    {
        cout << "? " << i + 1 << " " << max_index + 1 << endl;
        int x;
        cin >> x;
        cout << "? " << max_index + 1 << " " << i + 1 << endl;
        int y;
        cin >> y;
        if (x > y)
            p[i] = x;
        else
        {
            p[max_index] = y;
            max_index = i;
        }
    }
    p[max_index] = n;
    cout << "! ";
    for (const int &i : p)
        cout << i << " ";
    cout << endl;
    return 0;
}