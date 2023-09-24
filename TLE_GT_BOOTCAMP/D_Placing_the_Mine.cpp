#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool verify(vector<long long> &a, long long mid)
{
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<long long> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        long long l = 1, r = n;
        while (l <= r)
        {
            long long mid = l + (r - l) / 2;
            if ()
        }
    }

    return 0;
}
