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

// I love this font
// ooo damn
// i'm loving this

int findKRotation(int arr[], int n)
{
    // code here
    int res = -1;
    int start = 0, end = n - 1;
    if (arr[start] <= arr[end])
    {
        return 0;
    }
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        int next = (mid + 1) % n;
        int prev = (mid + n - 1) % n;
        // cout << mid << " " << arr[mid] << " and start end are " << start << " " << end << endl;
        if (arr[mid] < arr[prev] && arr[mid] < arr[next])
        {
            res = mid;
            break;
        }
        else if (arr[mid] >= arr[0])
        {
            start = mid + 1;
        }
        else if (arr[mid] <= arr[n - 1])
            end = mid - 1;
    }
    // cout << res << endl;
    return res; //for right shift
}
int32_t main()
{
    int n;
    cin >> n;
    int arr[n];
    rep(i, 0, n) cin >> arr[i];
    cout << " the number of rotations are " << endl;
    cout << findKRotation(arr, n) << endl;
    // cout << n - res << endl; // for leftwise shift
}