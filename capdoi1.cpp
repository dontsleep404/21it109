#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll binsearch(ll arr[],ll l,ll r,ll v){
    if(v == arr[l]) return l;
    if(v == arr[r]) return r;
    while(l<=r){
        ll m = (l+r)/2;      
        if(arr[m] == v){
            return m;
        }
        if(arr[m] > v) 
        r = m-1;
        else l = m+1;
    }
    return -1;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,k;
    cin >> n >> k;
    ll arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];
    sort(arr,arr+n);
    ll dem = 0;
    for(int i=0;i<n-1;i++){
        if(k - arr[i] < arr[i]) break;
        ll pos = binsearch(arr,i+1,n-1,k- arr[i]);
        if(pos!=-1){
            dem++;
            ll l = pos-1;
            ll r = pos+1;
            while (arr[l]==k-arr[i]) l--,dem++;
            while (arr[r]==k-arr[i]) r++,dem++;
        }
    }
    cout << dem;
}
