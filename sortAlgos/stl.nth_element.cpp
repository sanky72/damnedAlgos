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
    nth_element(arr, arr + 2, arr + n); 
    rep(i,0,n){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

// in this basically it sort the arr+2 and makes the array that all the elements before are <= to arr[index] and  >=  are later ones.
// arr + 2 = index 2 (in 0th indexing, and that will be pivot)