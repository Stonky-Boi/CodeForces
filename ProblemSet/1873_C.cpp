#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<string> target(10);
        for (int i = 0; i < 10; i++)
            cin >> target[i];
        int points = 0;
        for (int i = 0; i < 5; i++)
            for (int j = i; j < target.size() - i; j++)
            {
                for (int k = i; k < target[j].size() - i; k++)
                {
                    if (target[j][k] == 'X')
                        points++;
                }
            }
        cout << points << endl;
    }
    return 0;
}