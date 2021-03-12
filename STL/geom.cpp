#include <stdio.h>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

unsigned segments_union_measure (const vector <pair <int,int> > & a)
{
	unsigned n = a.size();
	vector <pair <int,bool> > x (n*2);
	for (unsigned i=0; i<n; i++)
	{
		x[i*2] = make_pair (a[i].first, false);
		x[i*2+1] = make_pair (a[i].second, true);
	}

	sort (x.begin(), x.end());

	unsigned result = 0;
	unsigned c = 0;
	for (unsigned i=0; i<n*2; i++)
	{
		if (c && i)
			result += unsigned (x[i].first - x[i-1].first);
		if (x[i].second)
			++c;
		else
			--c;
	}
	return result;
}

int main(void)
{
	return 0;
}
