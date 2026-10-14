#include <iostream>
#include <vector>
using namespace std;

int read_books(int n, int x)
{
    int k = 0;
    vector<int> books(n);
    for (int &i : books)
        cin >> i;
    for (const int &i : books)
    {
        if ((x | i) != x)
            break;
        k |= i;
    }
    return k;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int knowledge = 0;
        knowledge |= read_books(n, x);
        knowledge |= read_books(n, x);
        knowledge |= read_books(n, x);
        cout << (knowledge == x ? "Yes" : "No") << endl;
    }
    return 0;
}