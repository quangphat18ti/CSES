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
#define LT "1640"
#define maxn 200005
#define sz(A) int( A.size() )

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int i , j , n , m , k;
int a[maxn];

multiset <pii> Set;

void nhap()
{
    cin >> n >> k;
    For( i , 1, n )
    {
        cin >> a[i];
        Set.insert( { a[i] , i } );
    }
}

void xuli()
{
    For( i , 1 , n )
    {
        Set.erase( Set.find( { a[i] , i } ) );

        auto res = Set.lower_bound( { k - a[i] , 0 } );
        if( res == Set.end() ) continue;

        pii tam = (*res);
        if( tam.fi != k - a[i] ) continue;
        cout << i << ' ' << tam.se << endl;
        return;
    }

    cout << "IMPOSSIBLE\n";
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

