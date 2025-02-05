#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define FOR(i,a,b) for (int i = (a); i <= (b); ++i)
#define NFOR(i,a,b) for(int i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
typedef long long ll; typedef pair <int, int> ii; typedef vector <int> vi; const int inf = 1e9 + 7;
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class T> void dbs(string str, T t) {cerr << str << " : " << t << "\n";}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cerr << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void prc(T a, T b) {cerr << "["; for (T i = a; i != b; ++i) {if (i != a) cerr << ", "; cerr << *i;} cerr << "]\n";}

ii operator+(const ii &x, const ii &y) {
    return ii(x.F+y.F, x.S+y.S);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    int n, k; cin >> n >> k;
    ii q; cin >> q.F >> q.S;
    set<pair<int, int>> s;
    FOR (i, 0, k - 1) {
        int xx, yy; cin >> xx >> yy;
        s.insert({xx, yy});
    }
    int ans = 0;
    FOR (dx, -1, 1) {
        FOR (dy, -1, 1) {
            if (dx == 0 and dy == 0) continue;
            ii now = q;
            while (now.F >= 1 and now.F <= n and now.S >= 1 and now.S <= n) {
                if (s.count(now)) break;
                ++ans;
                now = now + ii(dx, dy);
            }
        }
    }
    cout << ans - 8;

    return 0;
}

