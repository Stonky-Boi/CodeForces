#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long int a, b, c;
        cin >> a >> b >> c;
        int anna = a, katie = b;
        if (c % 2 == 0)
        {
            anna += c / 2;
            katie += c / 2;
        }
        else
        {
            anna += (c / 2) + 1;
            katie += c / 2;
        }
        if (anna > katie)
            cout << "First" << endl;
        else
            cout << "Second" << endl;
    }
    return 0;
}