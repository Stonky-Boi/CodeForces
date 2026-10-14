#include <iostream>
#include <vector>
using namespace std;

bool valid(vector<int> &proficient, int m, int time)
{
    long long possible = 0;
    for (const int &i : proficient)
        possible += (i > time ? time : i + (time - i) / 2);
    return possible >= m;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> a(m);
        vector<int> proficient(n, 0);
        for (int &i : a)
        {
            cin >> i;
            proficient[i - 1]++;
        }
        int left = 0, right = 2 * m;
        int time = 2 * m;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (valid(proficient, m, mid))
            {
                time = mid;
                right = mid - 1;
            }
            else
                left = mid + 1;
        }
        cout << time << endl;
    }
    return 0;
}