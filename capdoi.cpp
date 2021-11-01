#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll binsearchfirst(ll arr[],ll l,ll r,ll v){
    if(arr[l] >= v) return l-1;
    if(arr[r] < v) return  r;
    ll m = (l+r)/2;
    while(l<=r){
        if(arr[m] < v && arr[m+1] >= v) return m;
        if(arr[m] >= v) 
        r = m-1;
        else l = m+1;
        m = (l+r)/2;
    }
    return -1;
}
ll binsearchend(ll arr[],ll l,ll r,ll v){
    if(arr[r] <= v) return r+1;
    if(arr[l] > v) return  l;
    ll m = (l+r)/2;  
    while(l<=r){        
        if(arr[m] > v && arr[m-1] <= v) return m;  
        if(arr[m] > v) 
        r = m-1;
        else l = m+1;
        m = (l+r)/2;  
    }
    return -1;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n,k;
    cin >> n >> k;
    ll arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];
    sort(arr,arr+n);
    ll dem = 0;
    for(int i=0;i<n-1;i++){
        if(k - arr[i] < arr[i]) break;
        ll d = binsearchend(arr,i+1,n-1,k - arr[i]) - binsearchfirst(arr,i+1,n-1,k - arr[i]) - 1;
        //ll pos = binsearch(arr,i+1,n-1,k- arr[i]);
        dem+=d;
    }
    cout << dem;
}
