#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, h;
        cin >> x >> h;

        int half = x / 2;

        int ans = 0;

        if (h - 5 * half <= 0)
        {
            while (h > 0)
            {
                h -= half;
                ans++;
            }
        }
        else
        {
            ans = 5;
            h -= 5 * half;

            while (h > 0)
            {
                h -= x;
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
