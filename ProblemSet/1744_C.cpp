#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        char c;
        string s;
        cin >> n >> c >> s;
        int time = 0, green = 0;
        s += s;
        n *= 2;
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == 'g')
                green = i;
            if (s[i] == c)
                time = max(time, green - i);
        }
        cout << time << endl;
    }
    return 0;
}