#include <iostream>
using namespace std;

int main()
{
    int a[26] = {0}, n;
    cin >> n;
    while (n--)
    {
        char s;
        cin >> s;
        if ((int)s > 64 && (int)s < 91)
            s = (char)((int)s + 32);
        a[(int)s - 97] = 1;
    }
    bool pangram = true;
    for (int i = 0; i < 26; i++)
    {
        if (a[i] == 0)
        {
            pangram = false;
            break;
        }
    }
    if (pangram)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}