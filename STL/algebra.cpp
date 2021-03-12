#include <stdio.h>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

const double fib_sqrt = (1. + sqrt(5)) / 2;

int phi(int n)
{
	//Euler function
	int result = n;
	for(int i = 2; i*i <= n; i++)
		if(n % i == 0)
		{
			while(n % i == 0)
				n /= i;
			result -= result / i;
		}
	if(n > 1)
		result -= result / n;
	return result;
}

double fpow(double a, int n)
{
	if(n == 0)
		return 1;
	if(n % 2)
		return fpow(a, n - 1) * a;
	else
	{
		double b = fpow(a, n/2);
		return b*b;
	}
}

int gcd(int a, int b)
{
	//Euclid algorithm
	return b ? gcd(b, a % b) : a;
}

int lcm(int a, int b)
{
	return (a / gcd(a, b)) * b;
}

int egcd(int a, int b, int *x, int *y)
{
	if (a == 0)
	{
		(*x) = 0;
		(*y) = 1;
		return b;
	}
	int x1, y1;
	int d = egcd(b%a, a, &x1, &y1);
	(*x) = y1 - (b / a) * x1;
	(*y) = x1;
	return d;
}

bool any_sol(int a, int b, int c, int *x0, int *y0, int *g)
{
	(*g) = egcd(abs(a), abs(b), x0, y0);
	if (c % (*g) != 0)
		return false;
	(*x0) *= c / (*g);
	(*y0) *= c / (*g);
	if (a < 0)   (*x0) *= -1;
	if (b < 0)   (*y0) *= -1;
	return true;
}

void shift_solution (int *x, int *y, int a, int b, int cnt) {
	(*x) += cnt * b;
	(*y) -= cnt * a;
}

int find_all_solutions (int a, int b, int c, int minx, int maxx, int miny, int maxy) {
	int x, y, g;
	if (!any_sol(a, b, c, &x, &y, &g))
		return 0;
	a /= g;  b /= g;

	int sign_a = a>0 ? +1 : -1;
	int sign_b = b>0 ? +1 : -1;

	shift_solution (&x, &y, a, b, (minx - x) / b);
	if (x < minx)
		shift_solution (&x, &y, a, b, sign_b);
	if (x > maxx)
		return 0;
	int lx1 = x;

	shift_solution (&x, &y, a, b, (maxx - x) / b);
	if (x > maxx)
		shift_solution (&x, &y, a, b, -sign_b);
	int rx1 = x;

	shift_solution (&x, &y, a, b, - (miny - y) / a);
	if (y < miny)
		shift_solution (&x, &y, a, b, -sign_a);
	if (y > maxy)
		return 0;
	int lx2 = x;

	shift_solution (&x, &y, a, b, - (maxy - y) / a);
	if (y > maxy)
		shift_solution (&x, &y, a, b, sign_a);
	int rx2 = x;

	if (lx2 > rx2)
		swap (lx2, rx2);
	int lx = max (lx1, lx2);
	int rx = min (rx1, rx2);

	return (rx - lx) / abs(b) + 1;
}

int fib(int n)
{
	n--;
	double res = (1. + fib_sqrt) / 2;
	return round(fpow(res, n) / fib_sqrt);
}

int g_code(int n)
{
	return n^(n >> 1);
}

int rev_g_code(int g)
{
	int n = 0;
	for(; g; g >>= 1)
		n ^= g;
	return n;
}

int discrete_log(int a, int b, int m)
{
	int n = (int) sqrt (m + .0) + 1;

	int an = 1;
	for (int i=0; i<n; ++i)
		an = (an * a) % m;

	map<int,int> vals;
	for (int i=1, cur=an; i<=n; ++i)
	{
		if (!vals.count(cur))
			vals[cur] = i;
		cur = (cur * an) % m;
	}

	for (int i=0, cur=b; i<=n; ++i)
	{
		if (vals.count(cur)) {
			int ans = vals[cur] * n - i;
			if (ans < m)
				return ans;
		}
		cur = (cur * a) % m;
	}
	return -1;
}

int factmod(int n, int p)
{
	int res = 1;
	while (n > 1)
	{
		res = (res * ((n/p) % 2 ? p-1 : 1)) % p;
		for (int i=2; i<=n%p; ++i)
			res = (res * i) % p;
		n /= p;
	}
	return res % p;
}

long long algebraic_sum(long long a0, long long d, long long n)
{
	return n * (2 * a0 + d * (n - 1)) / 2;
}

int main(void)
{
	long long n, res = 0ll;
	scanf("%lld", &n);
	long long s1, s2;
	if(n % 2)
	{
		s1 = algebraic_sum(1ll, 2ll, (n + 1ll) / 2ll);
		s2 = algebraic_sum(2ll, 2ll, (n - 1ll) / 2ll);
	}
	else
	{
		s1 = algebraic_sum(1ll, 2ll, n / 2ll);
		s2 = algebraic_sum(2ll, 2ll, n / 2ll);
	}
	res = s2 - s1;
	printf("%lld\n", res);
	return 0;
}
