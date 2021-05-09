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
#define LT "1625"
#define maxn 50
#define sz(A) int( A.size() )

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int i , j , n , m , k;
int x , y;
string s;
int ans = 0;

map <char , char> d;
char huong[5] = { 'U' , 'U' , 'D' , 'L' , 'R' };

bool check( int x , int y )
{
    return ( x >= 1 && x <= 7 && y >= 1 && y <= 7 );
}

void nhap()
{
    n = 7;
    cin >> s;   m = s.size();  s = " " + s;
    d['U'] = 'D';
    d['D'] = 'U';
    d['L'] = 'R';
    d['R'] = 'L';
}

void update( int &x , int &y , char tam )
{
    if( tam == 'U' ) x--;
    if( tam == 'D' ) x++;
    if( tam == 'L' ) y--;
    if( tam == 'R' ) y++;
}

void vet( int tam )
{
    if( tam > m )
    {
        if( x == n && y == n ) ans++;
        return;
    }

    if( s[tam] == '?' )
    {
        For( i , 1 , 4 )
        {
            update( x , y , huong[i] );
            if( !check( x , y ) )
            {
                update( x , y , d[huong[i]] );
                continue;
            }
            vet( tam + 1 );
            update( x , y , d[huong[i]] );
        }
    }
    else
    {
        update( x , y , s[tam] );
        if( !check( x , y )  )
        {
            update( x , y , d[s[tam]] );
            return;
        }
        vet(tam + 1);
        update( x , y , d[s[tam]] );
    }
}

void xuli()
{
    x = y = 1;
    vet(1);
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(LT".inp","r",stdin);
    freopen(LT".out","w",stdout);
    int t = 1;
//    cin >> t;
    while( t-- )
    {
        nhap();
        xuli();
    }
}

