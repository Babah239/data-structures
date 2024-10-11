#include<vector>
#include<math.h>
#include<algorithm>
#include <iostream>
#include <iomanip>
#define ll long long

ll a[100010];
struct SegmentTree {
	vector <ll> t;
	int half;
	SegmentTree(int n) {
		half = 1;
		while (half < n) half *= 2;
		t = vector <ll>(half * 2);
		for (int i = 0; i < n; i++)
		{
			t[i + half] = a[i];
		}
		for (int i = n; i < half; ++i)t[i + half] = 1e10;
		for (int i = half - 1; i >= 1; i--)
			if (t[2 * i] < t[2 * i + 1])
			{
				t[i] = t[i * 2];
			}
			else
			{
				t[i] = t[2 * i + 1];
			}
	}
	void change(int pos1, ll val) {
		int pos = pos1 + half;
		t[pos] = val;
		pos /= 2;
		for (; pos > 0; pos /= 2)
			t[pos] = min(t[pos * 2], t[pos * 2 + 1]);
	}
	ll Min(int lo, int hi) {
		ll res = 1e10;
		for (lo += half, hi += half; lo < hi; lo /= 2, hi /= 2)
		{
			if (lo & 1) if (t[lo++] < res)
			{
				res = t[lo - 1];
			}
			if (hi & 1)if (t[--hi] < res)
			{
				res = t[hi];
			}
		}
		return res;
	}
};
int main()
{
	
}