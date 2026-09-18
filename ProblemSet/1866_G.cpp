#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Carriage
{
    long long start;
    long long end;
    long long passengers;
};

bool can_transport(vector<Carriage> carriage, long long Z)
{
    int N = carriage.size();
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    int index = 0;
    for (int position = 0; position < N; position++)
    {
        while (index < N && carriage[index].start <= position)
        {
            pq.push({carriage[index].end, index});
            index++;
        }
        long long capacity = Z;
        while (!pq.empty() && capacity > 0)
        {
            auto [end_position, carriage_index] = pq.top();
            pq.pop();
            if (position >= end_position)
                continue;
            if (carriage[carriage_index].passengers <= capacity)
            {
                capacity -= carriage[carriage_index].passengers;
                carriage[carriage_index].passengers = 0;
            }
            else
            {
                carriage[carriage_index].passengers -= capacity;
                capacity = 0;
                pq.push({end_position, carriage_index});
            }
        }
    }
    for (auto &c : carriage)
        if (c.passengers > 0)
            return false;
    return true;
}

int main()
{
    int N;
    cin >> N;
    vector<long long> A(N);
    long long total = 0, maxA = 0;
    for (auto &x : A)
    {
        cin >> x;
        total += x;
        if (x > maxA)
            maxA = x;
    }
    vector<int> D(N);
    for (auto &x : D)
        cin >> x;
    vector<Carriage> carriage(N);
    for (long long i = 0; i < N; i++)
        carriage[i] = {max(0LL, i - D[i]), min((long long)N, i + D[i] + 1), A[i]};
    sort(carriage.begin(), carriage.end(), [](const Carriage &a, const Carriage &b)
         { return a.start < b.start; });
    long long l = total / N, r = maxA + 1;
    while (l < r)
    {
        long long m = l + (r - l) / 2;
        if (can_transport(carriage, m))
            r = m;
        else
            l = m + 1;
    }
    cout << l << endl;
    return 0;
}