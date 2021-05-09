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
#define LT "1622"
#define maxn 15
#define sz(A) int( A.size() )

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int i , j , n , m , k;
string s;
unordered_map <string , int> dd;
vector<string> ans;
string res = "";
int d[maxn];
int a[maxn];

void nhap()
{
    cin >> s;
    n = s.size();
    For( i , 1 , n ) a[i] = s[i - 1] - 'a';
    sort( a + 1 , a + n + 1 );
    s = " ";
    For( i , 1 , n ) s = s + char( a[i] + 'a');
}

void vet( int tam )
{
    if( tam > n )
    {
        if( dd[res] ) return;
        dd[res] = 1;
        ans.pb(res);
    }

    For( i , 1 , n )
    {
        if( d[i] ) continue;
        d[i] = 1;
        res += s[i];
        vet(tam + 1);
        d[i] = 0;
        res.erase( res.size() - 1 , 1 );
    }
}

void xuli()
{
    vet(1);
    cout << ans.size() << endl;
    for( string tam : ans ) cout << tam << endl;
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

