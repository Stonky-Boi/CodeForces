#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int w[2 * n];
    for (int i = 0; i < 2 * n; i++)
        cin >> w[i];
    sort(w, w + 2 * n);
    int min_instability = INT_MAX;
    for (int i = 0; i < 2 * n; i++)
    {
        for (int j = i + 1; j < 2 * n; j++)
        {
            int temp[100], index = 0;
            for (int k = 0; k < 2 * n; k++)
            {
                if (k != i && k != j)
                    temp[index++] = w[k];
            }
            int instability = 0;
            for (int k = 0; k < 2 * n - 2; k += 2)
                instability += temp[k + 1] - temp[k];
            if (instability < min_instability)
                min_instability = instability;
        }
    }
    cout << min_instability << endl;
    return 0;
}