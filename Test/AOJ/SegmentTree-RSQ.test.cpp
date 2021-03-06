#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_B"

#include <bits/stdc++.h>
using namespace std;
#include "../../DataStructure/SegmentTree.cpp"
typedef long long ll;

int main() {
	ll n, q;
	cin >> n >> q;
	SegmentTree<ll> segtree(n+10, true, 0, 0, 
	[](ll x, ll y){ return x + y; },
	[](ll x, ll y){ return x + y; },
	[](ll x, ll btm, ll tp){ return x * (tp - btm); });

	segtree.update(0, n, 0);
	while(q--) {
		int com;
		cin >> com;
		if(com == 0) {
			ll x, y, z;
			cin >> x >> y;
			segtree.update(--x, y);
		} else {
			ll x, y, z;
			cin >> x >> y;
			cout << segtree.get(--x, y) << endl;
		}
		// segtree.print(n);
	}
	return 0;
}