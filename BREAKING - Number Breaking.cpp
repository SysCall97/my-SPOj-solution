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
#define all(v)        v.begin(), v.end()
#define allr(v)       v.rbegin(), v.rend()
#define mem(x,y)      memset(x , y , sizeof(x))
using namespace std;
typedef long long ll;
typedef pair<ll, ll> PI;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<ll> div(1000010, 1);
    for(ll i=2; i<1000009; ++i) {
        if(div[i]==1) {
            for(ll j=i; j<1000009; j+=i) {
                if(div[j]==1) div[j]=i;
            }
        }
    }

//    for(ll i=2; i<11; ++i) cout<<i<<" "<<div[i]<<el;
    ll t; cin>>t;
    for(ll Case=1; Case<=t; ++Case) {
        set<ll> st;
        ll n; cin>>n;
        ll j=div[n];
        while(n>1) {
            st.insert(j);
            n/=div[n];
            j=div[n];
        }
        cout<<"Case "<<Case<<": ";
        for(set<ll>:: iterator it=st.begin(); it!=st.end(); ++it) cout<<*it<<" ";
        cout<<el;
    }
    return 0;
}

