#include<vector>
#include<math.h>
#include<algorithm>
#include <iostream>
#define ll long long
using namespace std;
int a[100000];
struct SegmentTree {
	vector <ll> t;
	int half;
	SegmentTree(int n) {
		half = 1;
		while (half < n) half *= 2;
		t = vector <ll>(half * 2);
		for (int i = 0; i < n; i++)
			t[i + half] = a[i];
		for (int i = half - 1; i >= 1; i--)
			t[i] = t[i * 2] + t[i * 2 + 1];
	}
	void add(int pos, int val) {
		for (pos += half; pos > 0;
			pos /= 2)
			t[pos] += val;
	}
	ll sum(int lo, int hi) {
		ll res = 0;
		for (lo += half, hi += half;
			lo < hi;
			lo /= 2, hi /= 2) {
			if (lo & 1)
				res += t[lo++];
			if (hi & 1)
				res += t[--hi];
		}
		return res;
	}
};
int main()
{
	
}
