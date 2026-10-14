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
        vector<int> p(n);
        for (int &i : p)
            cin >> i;
        vector<int> sequence;
        for (int i = 0; i < n;)
        {
            sequence.push_back(p[i]);
            if (i == n - 1)
                break;
            int j = i;
            if (p[i + 1] > p[i])
            {
                while (j + 1 < n && p[j + 1] > p[j])
                    j++;
            }
            else
            {
                while (j + 1 < n && p[j + 1] < p[j])
                    j++;
            }
            i = j;
        }
        cout << sequence.size() << endl;
        for (const int &i : sequence)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}