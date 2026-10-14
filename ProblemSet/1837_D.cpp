#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;
        int depth = 0;
        bool positive = true, negative = true;
        vector<int> color(n);
        int curr_color = (s[0] == '(' ? 1 : 2);
        for (int i = 0; i < n; i++)
        {
            depth += (s[i] == '(' ? 1 : -1);
            if (depth > 0)
                negative = false;
            else if (depth < 0)
                positive = false;
            color[i] = curr_color;
            if (depth == 0 && i + 1 < n)
                curr_color = (s[i + 1] == '(' ? 1 : 2);
        }
        if (depth != 0)
            cout << -1 << endl;
        else if (positive || negative)
        {
            cout << 1 << endl;
            for (int i = 0; i < n; i++)
                cout << "1 ";
            cout << endl;
        }
        else
        {
            cout << 2 << endl;
            for (const int &i : color)
                cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}