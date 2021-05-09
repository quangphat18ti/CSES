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
#define LT "1755"
#define maxn
#define sz(A) int( A.size() )

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int i , j , n , m , k;
string s;
int d[30];

void nhap()
{
    cin >> s;
    n = s.size(); s = " " + s;
    For( i , 1 , n ) d[s[i] - 'A' + 1]++;
}

void xuli()
{
    int dem = 0 , res = 0;
    For( i , 1 , 26 )
    {
        dem += d[i] % 2;
        if( d[i] % 2 ) res = i , d[i]--;
    }

    if( dem >= 2 ) { cout << "NO SOLUTION\n"; return; }

    vector<int> ans;
    For( i , 1 , 26 )
    {
        int tam = d[i] / 2;
        d[i] -= tam;
        while( tam-- ) ans.pb(i);
    }

    if( res )  ans.pb(res);

    for( int u : ans ) cout << char( u + 'A' - 1 );

    int tam = ans.size() - 1 - dem;
    FOr( i , tam , 0 ) cout << char( ans[i] + 'A' - 1 );
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
