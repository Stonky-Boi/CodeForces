#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> x(n);
        map<int, vector<int>> position;
        for (int i = 0; i < n; i++)
        {
            cin >> x[i];
            position[x[i]].push_back(i + 1);
        }
        int A = x[0];
        int L = 1, R = 1;
        int max_score = 1;
        for (const auto &[a, p] : position)
        {
            int score = 1;
            int start = p[0];
            for (int i = 1; i < p.size(); i++)
            {
                int gain = 2 - (p[i] - p[i - 1]);
                if (score + gain < 1)
                {
                    score = 1;
                    start = p[i];
                }
                else
                    score += gain;
                if (score > max_score)
                {
                    max_score = score;
                    A = a;
                    L = start;
                    R = p[i];
                }
            }
        }
        cout << A << " " << L << " " << R << endl;
    }
    return 0;
}