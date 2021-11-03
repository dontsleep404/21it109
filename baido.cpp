#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll nt[200001];
ll arr[200001];
const ll sodu = 1000000007;
ll mu(ll a, ll b){
    ll t = a;b--;
    ll tt = 1;
    while(b > 0){
        if (b == 0) break;
        if(b % 2 == 0) t= t*(t % sodu),b/=2;
        else tt = a*(tt%sodu),b--;
    }    
    return (tt*t)%sodu;
}
ll sqr(ll x) {
    return x*x;
}

ll po(ll a, ll b) {
    if (b == 0) return 1 % sodu;
    else
        if (b % 2 == 0)
            return sqr(po(a, b/2)) % sodu;
        else
            return a * (sqr(po(a, b/2)) % sodu) % sodu;
}
ll power(ll a, ll b, ll m)
{
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = ((res % m) * (a % m))
                  % m;
 
        a = ((a % m) * (a % m)) % m;
 
        b >>= 1;
    }
 
    return res % m;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n;cin>>n;
    ll index = -1;
    ll temp;
    ll x = 1;
    for(ll i=0;i<n;i++){
        cin >> temp;
        if(nt[temp] == 0) index++,arr[index]=temp;
        nt[temp]++;
        x=((x%sodu)*(temp%sodu))%sodu;        
    }
    ll p = 1;
    ll d = 1;
    for(ll i=0;i<=index;i++){
        //d= ((d%sodu)*((nt[arr[i]]+1)%(sodu-1)));
        ll val
            = power(arr[i],
                    (nt[arr[i]]) * (nt[arr[i]] + 1) / 2,
                    sodu);
 
        // Update the product
        p = (power(p, nt[arr[i]] + 1, sodu)
                   * power(val, d, sodu))
                  % sodu;
 
        // Update the count of divisors
        d = (d * (nt[arr[i]] + 1)) % (sodu - 1);
    }  
    cout << x << " " << d << endl;
    cout << p;
}
