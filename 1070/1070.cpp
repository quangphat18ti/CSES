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
#define LT "1070"
#define maxn 1000005
#define sz(A) int( A.size() )

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int i , j , n , m , k;

void nhap()
{
    cin >> n;
}

void xuli()
{
    if( n == 1 ) { cout << 1 << endl; return; }
    if( n <= 3 ) { cout << "NO SOLUTION"; return; }

    vi ans;
    for( int i = 2 ; i <= n ; i += 2 ) ans.pb( i );
    for( int i = 1 ; i <= n ; i += 2 ) ans.pb(i);
    for( int u : ans ) cout << u << ' ';
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

