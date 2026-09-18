#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long int W, H, x1, x2, y1, y2, w, h;
        cin >> W >> H >> x1 >> y1 >> x2 >> y2 >> w >> h;
        long int moves = LONG_MAX;
        if (x2 - x1 + w <= W)
            moves = min(moves, min(max(0L, w - x1), max(0L, x2 - (W - w))));
        if (y2 - y1 + h <= H)
            moves = min(moves, min(max(0L, h - y1), max(0L, y2 - (H - h))));
        if (moves == LONG_MAX)
            moves = -1;
        cout << moves << endl;
    }
    return 0;
}