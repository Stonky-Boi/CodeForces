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
        cin >> n;
        vector<int> position(n + 1);
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            position[x] = i;
        }
        int left = (n + 1) / 2;
        int right = (n + 2) / 2;
        while (left > 0)
        {
            if (left == right ||
                (position[left] < position[left + 1] && position[right - 1] < position[right]))
            {
                left--;
                right++;
            }
            else
                break;
        }
        cout << left << endl;
    }
    return 0;
}