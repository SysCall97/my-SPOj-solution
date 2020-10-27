/***************************************************************
 *    Name:  KAZI NUR  ALAM MASHRY                             *
 *  School:  MAWLANA BHASHANI SCIENCE & TECHNOLOGY UNIVERSITY  *
 *           CSE (14TH BATCH)                                  *
 ***************************************************************/
#include<bits/stdc++.h>
#define INF           0x3f3f3f3f
#define el            '\n'
#define x             first
#define y             second
#define pi            acos(-1.0)
#define pb            push_back
#define Max           10000
#define all(v)        v.begin(), v.end()
#define allr(v)       v.rbegin(), v.rend()
#define mem(x,y)      memset(x , y , sizeof(x))
using namespace std;
typedef long long ll;
typedef pair<ll, ll> PI;

ll mod=1000000007;
ll n;
map<ll, ll> mp;
vector<ll> cnt(10000010, 0), dp(10000010, INF), p;

void preCalculation() {
    dp[1]=1;
    for(ll i=2; i<10000004; ++i) {
        if(dp[i]==INF) {
            dp[i]=i;
            mp[i]=INF;
            for(ll j=i+i; j<10000004; j+=i) dp[j]=min(dp[j], i);
        }
    }
//    for(ll i=1; i<37; ++i) cout<<i<<" "<<dp[i]<<el;
}

void func(vector<ll>& v, vector<ll>& g, ll sz) {
    map<ll, ll> mp1;
    vector<ll> st;

    for(ll i=0; i<sz; ++i) {
        if(v[i]==1) continue;
        ll j=v[i];
        while(j>1) {
            ++mp1[dp[j]];
            if(mp1[dp[j]]==1) st.pb(dp[j]);
            j=j/dp[j];
        }
    }

    for(ll i: st) {
        mp[i]=min(mp[i], mp1[i]);
        ++cnt[i];
        if(cnt[i]==n) g.pb(i);
    }
//    for(ll i: st) cout<<i<<" "<<mp1[i]<<" ";
//    cout<<el<<el;
}

ll big_mod(ll n, ll p, ll mod) {
    if(p==0) return 1;
    if(p%2) return ((n%mod)*big_mod(n,p-1,mod))%mod;
    else {
        ll ans = big_mod(n,p/2,mod);
        return (ans*ans)%mod;
    }
}

int main() {
    preCalculation();
    ll m, k, ans=1;
    vector<ll> g;

    scanf("%lld", &n);
    for(ll i=0; i<n; ++i) {
        scanf("%lld", &m);
        vector<ll> v(m);
        for(ll j=0; j<m; ++j) scanf("%lld", &v[j]);
        func(v, g, m);
    }

//    for(ll i=0; i<g.size(); ++i) cout<<g[i]<<" "<<mp[g[i]]<<el;

    for(ll i: g) ans=(ans*big_mod(i, mp[i], mod))%mod;
    printf("%lld\n", ans);

    return 0;
}
