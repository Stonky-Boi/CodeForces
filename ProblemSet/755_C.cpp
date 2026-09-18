#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<bool> visited(n);
    int pairs = 0;
    for (int i = 0; i < n; i++)
    {
        int relative;
        cin >> relative;
        if (i + 1 == relative)
            pairs += 2;
        else if (!visited[relative - 1])
        {
            pairs++;
            visited[relative - 1] = true;
        }
    }
    cout << pairs / 2 << endl;
    return 0;
}