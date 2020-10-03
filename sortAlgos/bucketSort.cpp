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

void bucketSort(float arr[], int n) 
{ 
	// 1) Create n empty buckets 
	vector<float> b[n]; 
	
	// 2) Put array elements in different buckets 
	for (int i=0; i<n; i++) 
	{ 
	int bi = n*arr[i]; // Index in bucket 
	b[bi].push_back(arr[i]); 
	} 

	// 3) Sort individual buckets 
	for (int i=0; i<n; i++) 
	sort(b[i].begin(), b[i].end()); 

	// 4) Concatenate all buckets into arr[] 
	int index = 0; 
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < b[i].size(); j++) 
		arr[index++] = b[i][j]; 
} 

int32_t main() 
{ 
	int n;
    cin>>n;
    float arr[n];
    rep(i,0,n){
        cin>>arr[i];
    }
	bucketSort(arr, n); 

	for (int i=0; i<n; i++) 
	cout << arr[i] << " "; 
	return 0; 
} 


// now bucket sort is basically used for floating point numbers which are uniform in a range