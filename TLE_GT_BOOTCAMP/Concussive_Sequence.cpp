#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> v(n);
        for (auto &x : v)
            cin >> x;
        sort(v.begin(), v.end());

        vector<ll> b(n);
        int ind = 0;
        for (int i = 0; i < n; i++)
        {
            if (ind >= n)
                ind = 1;
            b[ind] = v[i];
            ind += 2;
        }

        vector<ll> c(n);
        ind = 1;
        for (int i = 0; i < n; i++)
        {
            if (ind >= n)
                ind = 0;
            c[ind] = v[i];
            ind += 2;
        }

        auto verify = [&](vector<ll> &A)
        {
            for (auto i = 1; i < A.size() - 1; i++)
            {
                if (A[i] > A[i - 1] && A[i] > A[i + 1])
                    continue;
                if (A[i] < A[i - 1] && A[i] < A[i + 1])
                    continue;
                return false;
            }
            return true;
        };

        if (verify(b))
        {
            for (auto &e : b)
            {
                cout << e << " ";
            }
        }
        else if (verify(c))
        {
            for (auto &e : c)
            {
                cout << e << " ";
            }
        }
        else
        {
            cout << -1;
        }
        cout << endl;
    }
    return 0;
}