
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
#define mp            make_pair
#define Max           1000
#define all(v)        v.begin(), v.end()
#define allr(v)       v.rbegin(), v.rend()
#define mem(x,y)      memset(x , y , sizeof(x))
using namespace std;
typedef long long ll;
typedef pair<ll, ll> PI;


void solve() {
    vector<ll> d(1000005, 2), mp(1000005, 1), ans;
    for(ll i=2; i<1000005; ++i)
        for(ll j=i+i; j<1000005; j+=i) ++d[j];

    ans.pb(-1);
    for(ll i=2; i<1000001; ++i)
        for(ll j=i; j<1000001; j+=i) {
            if(d[j]<=3 || d[j]%d[i]!=0) {
                mp[j]=0;
            }
        }
    for(ll i=2; i<1000001; ++i) if(mp[i]) ans.pb(i);
    ll sz=ans.size();
    for(ll i=108; i<sz; i+=108) printf("%lld\n", ans[i]);
}

int main() {
    solve();
    return 0;
}
