#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isPrime(ll n)
{
    if (n <= 1)
        return false;
    for (ll i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;

    return true;
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        if (n <= 2)
        {
            cout << -1 << endl;
            continue;
        }

        vector<ll> ans;

        for (ll i = 3; i <= n; i++)
        {
            ans.push_back(i);
        }
        if (isPrime(abs(1 - (n - 1))) && isPrime(abs(2 - n)))
        {
            ans.push_back(1);
            ans.push_back(2);
        }
        else if (isPrime(abs(2 - (n - 1))) && isPrime(abs(1 - (n))))
        {
            ans.push_back(2);
            ans.push_back(1);
        }
        else
        {
            cout << -1 << endl;
            continue;
        }
        for (auto x : ans)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}
