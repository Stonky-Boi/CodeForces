#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int s;
        cin >> s;
        int root = sqrt(s);
        if (root * root == s)
            cout << "0 " << root << endl;
        else
            cout << "-1" << endl;
    }
    return 0;
}