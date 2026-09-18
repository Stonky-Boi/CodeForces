#include <iostream>
using namespace std;

void binary_tree(int a[], vector<int> &depth, int left, int right, int current_depth)
{
    if (left > right)
        return;
    int index_of_maximum_element = left;
    for (int i = left + 1; i <= right; i++)
    {
        if (a[i] > a[index_of_maximum_element])
            index_of_maximum_element = i;
    }
    depth[index_of_maximum_element] = current_depth;
    binary_tree(a, depth, left, index_of_maximum_element - 1, current_depth + 1);
    binary_tree(a, depth, index_of_maximum_element + 1, right, current_depth + 1);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        vector<int> depth(n, -1);
        binary_tree(a, depth, 0, n - 1, 0);
        for (int i = 0; i < n; i++)
            cout << depth[i] << " ";
        cout << endl;
    }
    return 0;
}