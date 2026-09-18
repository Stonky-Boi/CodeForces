#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int faces = 0;
    while (n--)
    {
        string s;
        cin >> s;
        if (s == "Tetrahedron")
            faces += 4;
        if (s == "Cube")
            faces += 6;
        if (s == "Octahedron")
            faces += 8;
        if (s == "Dodecahedron")
            faces += 12;
        if (s == "Icosahedron")
            faces += 20;
    }
    cout << faces << endl;
    return 0;
}