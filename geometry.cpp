#include<math.h>
#include<algorithm>
#include <iostream>
#include <random>
#define ld long double
using namespace std;
ld _e = 1e-10;
struct line
{
	ld a;
	ld b;
	ld c;
	line operator =(line x)
	{
		a = x.a;
		b = x.b;
		c = x.c;
		return x;
	}
};
struct point
{
	ld x;
	ld y;
	ld z;
	point() {}
	point(ld a, ld b)
	{
		x = a;
		y = b;
		z = 1;
	}
	point operator =(point a)
	{
		x = a.x;
		y = a.y;
		z = a.z;
		return *this;
	}
	point operator +(point p)
	{
		point ans(x + p.x, y + p.y);
		return ans;
	}
	point operator -(point p)
	{
		point ans(x - p.x, y - p.y);
		return ans;
	}
	point operator *(ld a)
	{
		point ans(x*a, y*a);
		return ans;
	}
	ld operator * (point p)
	{
		return x*p.x + y*p.y;
	}
	point operator /(ld a)
	{
		point ans(x / a, y / a);
		return ans;
	}
	bool operator ==(point p)
	{
		return (x*p.y - y*p.x == 0) && (y*p.z - z*p.y == 0) && (x*p.z - z*p.x == 0);
	}
	bool operator <(point p)
	{
		/*if (x / z < p.x / p.z - _e)return 1;
		else if (x / z > p.x / p.z + _e)return 0;
		else if (y / z < p.y / p.z - _e)return 1;
		else return 0;*/
		if (x < 0 && p.x >= 0)return 0;
		else if (x >= 0 && p.x < 0)return 1;
		else return y / x < p.y / p.x;
	}
	ld operator %(point p)
	{
		return (*this).rotate()*p;
	}
	ld size()
	{
		return sqrt(x*x + y*y);
	}
	ld arg()
	{
		if (abs(x) < _e)
		{
			if (y > 0)return _Pi / (ld)2;
			else return (ld)3 * _Pi / (ld)2;
		}
		else if (abs(y) < _e)
		{
			if (x > (ld)0)return 0;
			else return _Pi;
		}
		else
		{
			ld a = atan(y / x);
			if (a < (ld)0)a += _Pi;
			if (y < (ld)0)a += _Pi;
			return a;
		}
	}
	point rotate()
	{
		point ans(-y, x);
		return ans;
	}
	point rotate(ld a)
	{
		point ans;
		ans.z = z;
		ans.x = x*cos(a) - y*sin(a);
		ans.y = y*cos(a) + x*sin(a);
		return ans;
	}
	point rotate(int a)
	{
		ld b = (ld)a / (ld)180 * _Pi;
		return (*this).rotate(b);
	}
	void input()
	{
		int a, b;
		cin >> a >> b;
		x = a;
		y = b;
		z = 1;
	}
	void output()
	{
		cout << x / z << ' ' << y / z << ' ';
	}
	void simplify()
	{
		x /= z;
		y /= z;
		z = 1;
	}
	bool incident(line p)
	{
		return abs(x*p.a + y*p.b + z*p.c) < _e;
	}
	bool degenerate()
	{
		return abs(x) < _e&&abs(y) < _e&&abs(z) < _e;
	}
	bool infitite()
	{
		return !((*this).degenerate()) && abs(z)<_e;
	}
	bool lie(point a, point b)
	{
		if (a == b)return (*this) == a;
		if (abs(a.x / a.z - b.x / b.z) > _e)return (b.x / b.z - x / z)*(x / z - a.x / a.z) >= (ld)0;
		else return  (b.y / b.z - y / z)*(y / z - a.y / a.z) >= (ld)0;
	}
};
point intersect(line p, line q)
{
	point ans;
	ans.x = p.c*q.b - p.b*q.c;
	ans.y = p.a*q.c - p.c*q.a;
	ans.z = p.b*q.a - p.a*q.b;
	return ans;
}
line draw(point p, point q)
{
	line ans;
	ans.a = p.z*q.y - p.y*q.z;
	ans.b = p.x*q.z - p.z*q.x;
	ans.c = p.y*q.x - p.x*q.y;
	return ans;
}
ld area(point p, point q, point r)
{
	p.simplify();
	q.simplify();
	r.simplify();
	return (p.x*q.y - p.y*q.x + q.x*r.y - q.y*r.x + r.x*p.y - r.y*p.x) / 2;
}
ld dist(point p, point q)
{
	p.simplify();
	q.simplify();
	return sqrt((p.x - q.x)*(p.x - q.x) + (p.y - q.y)*(p.y - q.y));
}
point min(point a, point b)
{
	if (a < b)return a;
	else return b;
}
point max(point a, point b)
{
	if (a < b)return b;
	else return a;
}
ld arg(point p, point q)
{
	return acos(p*q / p.size() / q.size());
}

int main()
{

}