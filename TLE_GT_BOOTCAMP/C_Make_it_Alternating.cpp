#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 998244353

ll fact[20000013];
int main()
{
    ll t;
    cin >> t;

    fact[0] = 1;
    for (ll i = 1; i <= 20000013; i++)
    {
        fact[i] = fact[i - 1] * i % MOD;
    }

    while (t--)
    {
        string s;
        cin >> s;
        ll n = s.size();

        char f = s[0];
        ll x = 1;
        ll c = 1;
        ll ways = 1;

        for (int i = 1; i < n; i++)
        {
            if (f != s[i])
            {
                (ways *= c) %= MOD;
                c = 1;
                x++;
                f = s[i];
            }
            else
            {
                c++;
            }
        }
        (ways *= c) %= MOD;

        ll ans = (ways * fact[n - x]) % MOD;
        cout << n - x << " " << ans << endl;
    }

    return 0;
}
