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

int32_t main(){
    int n;
    cin>>n;
    int arr[n];
    rep(i,0,n){
        cin>>arr[i];
    }
    partial_sort(arr  + 1, arr+ 3, arr+n);
    rep(i,0,n){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

// it will basically pick the correct positions for all the positions till from first parameter to arr + "whatever" (middle parameter) 
// [firstParameter, middleParameter)
// Referece -gfg - The worst-case O(N*log K) running time of partial_sort() doesn’t tell the whole story. 
// Its average-case running time on random input is O(N + K*log K + K*(log K)*(log Nk)).
