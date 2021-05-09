///

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define pb push_back
#define For( i , a , b ) for(int i = int(a) ; i <= int(b) ; i++)
#define FOr( i , a , b ) for(int i = int(a) ; i >= int(b) ; i--)
#define fi first
#define se second
#define mp make_pair
#define LT "1620"
#define maxn 200005
#define sz(A) int( A.size() )

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int i , j , n , k;
int a[maxn];
ll m;

void nhap()
{
    cin >> n >> m;
    For(i, 1, n) cin >> a[i];
}

bool check( ll s )
{
    ll ans = 0;
    For( i , 1 , n )
    {
        ans += s/a[i];
        if( ans >= m ) return 1;
    }
    return 0;
}

void xuli()
{
    ll l = 0 , r = 1e18;
    while( l <= r )
    {
        ll mid = (l + r) >> 1;
        if( check(mid) ) r = mid - 1;
        else l = mid + 1;
    }
    cout << r + 1 << endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    freopen(LT".inp","r",stdin);
//    freopen(LT".out","w",stdout);
    int t = 1;
//    cin >> t;
    while( t-- )
    {
        nhap();
        xuli();
    }
}

