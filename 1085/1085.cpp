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
#define LT "1085"
#define maxn 200005
#define sz(A) int( A.size() )

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int i , j , n , m , k;
int a[maxn];

void nhap()
{
    cin >> n >> k;
    For( i , 1 , n ) cin >> a[i];
}

bool check( ll s )
{
    int dem = 0 , i = 1;
    ll res = 0;
    while( i <= n )
    {
        res = 0;
        while( i <= n && res + a[i] <= s ) res += a[i++];
        dem++;
        if( dem > k ) return 0;
    }
    if( dem > k ) return 0;
    return 1;
}

void xuli()
{
    ll l = *max_element( a + 1 , a + n + 1 ) , r = 1e15;
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
