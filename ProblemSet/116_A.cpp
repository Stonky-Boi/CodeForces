#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int capacity = 0;
    int passengers = 0;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        passengers += b - a;
        if (capacity < passengers)
            capacity = passengers;
    }
    cout << capacity << endl;
    return 0;
}