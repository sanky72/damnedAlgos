#include <bits/stdc++.h>
//#include <boost/algorithm/string.hpp>
using namespace std;
typedef long long int ll;
#define int ll
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define endl "\n"
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define rev(a) (a).rbegin(), (a).rend()
#define pll pair<ll, ll>
#define rep(i, a, b) for (long long i = (a); i < (b); i++)
#define derep(i, a, b) for (long long i = (a); i >= (b); i--)
ll modi = 1000000007;

int32_t main()
{
    int n;
    cin >> n;
    int arr[n];
    rep(i, 0, n) cin >> arr[i];
    cout << "give the number you want to search " << endl;
    int target;
    cin >> target;
    int res = -1;
    int start = 0, end = n - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target)
        {
            res = mid;
            break;
        }
        else if (arr[mid] < target)
        {
            start = mid + 1;
        }
        else
            end = mid - 1;
    }
    cout << res << endl;
}
