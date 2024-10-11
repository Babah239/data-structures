#include <iostream>
#include <iterator>
#define null NULL
using namespace std;

struct Treap
{
	int x;
	int y;
	int size;
	Treap *Left;
	Treap *Right;
	//Treap *Parent;
	Treap()
	{
	}
	Treap(int a, int b)
	{
		x = a;
		y = b;
		Left = null;
		Right = null;
		//Parent = null;
		size = 1;
	}
	Treap(int a, int b, Treap *l, Treap *r)
	{
		x = a;
		y = b;
		Left = l;
		Right = r;
		//Parent = null;
		//if(Left!=null) (*Left).Parent = this;
		//if (Right!= null) (*Right).Parent = this;
		size = 1;
		if (Left != null)size += (*Left).size;
		if (Right != null)size += (*Right).size;
	}
	Treap(int a, int b, Treap *l, Treap *r, Treap *p)
	{
		x = a;
		y = b;
		Left = l;
		Right = r;
		size = 1;
		//Parent = p;
		//if(Left!=null) (*Left).Parent = this;
		//if(Right!=null) (*Right).Parent = this;
		if (Left != null)size += (*Left).size;
		if (Right != null)size += (*Right).size;
	}
	Treap *Merge(Treap *L, Treap *R)
	{
		if (L == null) return R;
		else if (R == null) return L;

		else if ((*L).y > (*R).y)
		{
			Treap *newR = Merge((*L).Right, R);
			return new Treap((*L).x, (*L).y, (*L).Left, newR);
		}
		else
		{
			Treap *newL = Merge(L, (*R).Left);
			return new Treap((*R).x, (*R).y, newL, (*R).Right);
		}
	}
	void Split(int a, Treap **L, Treap **R)
	{
		Treap *newTree = null;
		if (x <= a)
		{
			if (Right == null)
				*R = null;
			else
				(*Right).Split(a, &newTree, R);
			*L = new Treap(x, y, Left, newTree);
		}
		else
		{
			if (Left == null)
				*L = null;
			else
				(*Left).Split(a, L, &newTree);
			*R = new Treap(x, y, newTree, Right);
		}
	}
	Treap *Add(int a, int b)
	{
		if (this == null)
		{
			return new Treap(a, b);
		}
		else
		{
			Treap *l = null, *r = null;
			Split(a, &l, &r);
			Treap *m = new Treap(a, b);
			return Merge(Merge(l, m), r);
		}
	}
	Treap *Add(int a)
	{
		int b = engine();
		return Add(a, b);
	}
	Treap *erase(int x)
	{
		Treap *L, *T, *R;
		Split(x - 1, &L, &T);
		Split(x, &T, &R);
		return Merge(L, R);
	}
	int find(int k)
	{
		int s = 0;
		if (Left != null)s = (*Left).size;
		if (k <= s)return (*Left).find(k);
		else if (k == s + 1)return x;
		else return (*Right).find(k - s - 1);
	}
};
int main()
{
	
}
