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

void countSort(int arr[], int n, int exp) 
{ 
	int output[n]; 
	int i, count[10] = {0}; 

	for (i = 0; i < n; i++) 
		count[ (arr[i]/exp)%10 ]++; 

	for (i = 1; i < 10; i++) 
		count[i] += count[i - 1]; 

	for (i = n - 1; i >= 0; i--) 
	{ 
		output[count[ (arr[i]/exp)%10 ] - 1] = arr[i]; 
		count[ (arr[i]/exp)%10 ]--; 
	} 
 
	for (i = 0; i < n; i++) 
		arr[i] = output[i]; 
} 

int getMax(int arr[], int n) 
{ 
    int mx = arr[0]; 
    for (int i = 1; i < n; i++) 
        if (arr[i] > mx) 
            mx = arr[i]; 
    return mx; 
} 

void radixsort(int arr[], int n) 
{ 
	// Find the maximum number to know number of digits 
	int m = getMax(arr, n);

	// Do counting sort for every digit. Note that instead 
	// of passing digit number, exp is passed. exp is 10^i 
	// where i is current digit number 
	for (int exp = 1; m/exp > 0; exp *= 10) 
		countSort(arr, n, exp); 
} 

void print(int arr[], int n) 
{ 
	for (int i = 0; i < n; i++) 
		cout << arr[i] << " "; 
} 

int32_t main() 
{ 
	int n;
    cin>>n;
    int arr[n];
    rep(i,0,n){
        cin>>arr[i];
    }
	radixsort(arr, n); 
	print(arr, n); 
	return 0; 
} 

//Reference - gog