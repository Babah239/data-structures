#include<vector>
#include<string>
#include<math.h>
#include<algorithm>
#include <iostream>

#define ll long long
using namespace std;
ll base = 1e9;
struct bigint
{
	vector<ll> v;
	bool sign;
	bigint()
	{
		sign = 1;
	}
	bigint(int n)
	{
		sign = n >= 0;
		n = abs(n);
		v.push_back(n);
	}
	bigint operator =(bigint x)
	{
		v.clear();
		sign = x.sign;
		for (int i = 0; i < x.v.size(); ++i) v.push_back(x.v[i]);
		return (*this);
	}
	bigint operator =(int x)
	{
		v.clear();
		v.push_back(abs(x));
		sign = x >= 0;
		return (*this);
	}
	bool operator ==(bigint x)
	{
		(*this).correct();
		x.correct();
		bool flag = sign == (x.sign);
		if (v.size() != x.v.size())flag = 0;
		else
		{
			for (int i = 0; i < v.size(); ++i)flag = flag && (v[i] == x.v[i]);
		}
		return flag;
	}
	bigint module()
	{
		bigint x = *this;
		x.sign = 1;
	}
	bigint reverse()
	{
		bigint ans = *this;
		ans.sign = !ans.sign;
		return ans;
	}
	bool zero()
	{
		bool flag = 1;
		for (int i = 0; i < v.size(); ++i)if (v[i] != 0)flag = 0;
		return flag;
	}
	void clear()
	{
		if ((*this).zero())
		{
			v.clear();
		}
		else while (v[v.size() - 1] == 0)  v.pop_back();
	}
	void correct()
	{
		(*this).clear();
		if ((*this).zero())
		{
			sign = 1;
		}
		else
		{
			if (v[v.size() - 1] < 0)
			{
				for (int i = 0; i < v.size(); ++i)v[i] *= -1;
				sign = !sign;
			}
			for (int i = 0; i < v.size() - 1; ++i)if (v[i] < 0)
			{
				v[i] += base;
				v[i + 1] -= 1;
			}
		}
		(*this).clear();
	}
	bool operator <(bigint x)
	{
		bool flag = 1;
		(*this).clear();
		x.clear();
		if (v.size() > x.v.size())return 0;
		else if (v.size() < x.v.size())return 1;
		else
		{
			for (int i = v.size() - 1; i >= 0; ++i)
				if (v[i] != x.v[i])
				{
					flag = 0;
					return v[i] < x.v[i];
					break;
				}
			if (flag)
				return 0;
		}
	}
	bigint operator +(bigint x)
	{
		ll k = 0;
		bigint ans;
		for (int i = 0; i < max(v.size(), x.v.size()); ++i)
		{
			if (i < v.size())k += v[i] * (sign ? (ll)1 : (ll)-1);
			if (i < x.v.size())k += x.v[i] * (x.sign ? (ll)1 : (ll)-1);
			k += base*base;
			ans.v.push_back(k%base);
			k = k / base - base;
		}
		ans.v.push_back(k);
		ans.correct();
		return ans;
	}
	bigint operator -(bigint x)
	{
		return (*this) + x.reverse();
	}
	bigint operator *(bigint x)
	{
		bigint ans;
		ans.sign = sign^x.sign;
		ll k, kold = 0;
		for (int i = 0; i < v.size() + x.v.size(); ++i)
		{
			k = kold;
			kold = 0;
			for (int j = 0; j < v.size(); ++j) if (i - j >= 0 && i - j < x.v.size())
			{
				k += v[j] * x.v[i - j];
				kold += k / base;
				k %= base;
			}
			ans.v.push_back(k);
		}
		ans.clear();
		return ans;
	}
	string to_str()
	{
		if ((*this).zero())return "0";
		else
		{
			string ans, s;
			(*this).clear();
			if (!sign)ans = "-";
			for (int i = v.size() - 1; i >= 0; --i)
			{
				s = to_string(v[i]);
				if (i != v.size() - 1)
					while (s.size() < 9)s = '0' + s;
				ans += s;
			}
			return ans;
		}
	}
};


int main()
{
	
}