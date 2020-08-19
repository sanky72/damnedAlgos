#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define int ll
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define pb push_back
#define all(a) (a).begin(),(a).end()
#define rev(a) (a).rbegin(),(a).rend()
#define pll pair<ll,ll>
#define rep(i,a,b) for(long long i = (a); i < (b); i++)
#define derep(i,a,b) for(long long i = (a); i>=(b); i--)
//taking range to 0 to 10
void countingSort(int arr[], int n){
    int count[11] = {0}, output[n];
    rep(i, 0, n)count[arr[i]]++;
    rep(i, 1, 11)count[i] += count[i-1];
    rep(i, 0, n)output[--count[arr[i]]] = arr[i];
    rep(i, 0, n)cout<<output[i]<<" ";
    cout<<endl;
}
int32_t main(){
    int n;
    cin>>n;
    int arr[n];
    rep(i,0,n){
        cin>>arr[i];
    }
    countingSort(arr, n);
}