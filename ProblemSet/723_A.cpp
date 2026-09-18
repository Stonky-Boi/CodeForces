#include <iostream>
using namespace std;

int main()
{
    int x1, x2, x3;
    cin >> x1 >> x2 >> x3;
    int distance = max(max(x1, x2), x3) - min(min(x1, x2), x3);
    cout << distance << endl;
    return 0;
}