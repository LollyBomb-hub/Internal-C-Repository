#include <stdio.h>
#include <string>
#include <vector>

#define V vector

using namespace std;

V<int> prefix(string s)
{
	int i = 1;
	int l = s.length();
	V<int> result(l, 0);
	for(; i < l; i++)
	{
		int k = result[i - 1];
		while((k > 0) && (s[i] != s[k]))
		{
			k = result[k - 1];
		}
		if(s[i] == s[k])
		{
			k++;
		}
		result[i] = k;
	}
	return result;
}

V<int> kmp(string p, string s)
{
	int pl = p.length();
	int sl = s.length();
	V<int> result(pl+1+sl, 0);
	V<int> prefix_function = prefix(p + "#" + s);
	int count = 0, i = 0;
	for(; i < sl; i++)
	{
		if(prefix_function[pl + i + 1] == pl)
		{
			result[count++] = i;
		}
	}
	return result;
}

V<int> zfunction(string s)
{
	int sl = s.length();
	V<int> zfunc(sl, 0);
	int left = 0, right = 0;
	int i = 0;
	for(; i < sl; i++)
	{
		zfunc[i] = max(0, min(right - i, zfunc[i - left]));
		while((i + zfunc[i] < sl) && (s[zfunc[i]] == s[i + zfunc[i]]))
		{
			zfunc[i]++;
		}
		if(i + zfunc[i] > right)
		{
			left = i;
			right = i + zfunc[i];
		}
	}
	return zfunc;
}

int subsearch(string text, string point)
{
	V<int> z = zfunction(text + "#" + point);
	int tl = text.length();
	int pl = point.length();
	int i = pl + 1;
	for(; i < tl + 1; i++)
	{
		if(z[i] == pl)
		{
			return i - pl - 1;
		}
	}
}

V<int> generate_template(string point)
{
	int l = point.length();
	V<int> t(l, 0);
	int i = 0;
	int j = t[0] = -1;
	while(i < l)
	{
		while((j > -1) && (x[i] != x[j]))
		{
			j = t[j];
		}
		i++; j++;
		if((i < l) && (x[i] == x[j]))
		{
			t[i] = t[j];
		}
		else
		{
			t[i] = j;
		}
	}
	return t;
}

V<int> ag(string text, string point)
{
	int tl = text.length();
	int pl = point.length();
	int dl = tl - pl;
	int l = 1;
	V<int> t = generate_template(point);
	V<int> result;
	for(; point[l - 1] == point[l]; l++);
	if(l == pl)
	{
		l = 0;
	}
	int i = l;
	int j = 0;
	int k = 0;
	while(j <= dl)
	{
		while((i < pl) && (point[i] == text[i + j]))
		{
			i++;
		}
		if(i >= pl)
		{
			while((k < l) && (point[k] == text[j + k]))
			{
				k++;
			}
			if(k >= l)
			{
				result.push_back(k);
			}
		}
		j += i - t[i];
		if(i == l)
		{
			k = max(0, k - 1);
		}
		else if(t[i] <= l)
		{
			k = max(0, t[i]);
			i = l;
		}
		else
		{
			k = l;
			i = t[i];
		}
	}
	return result;
}

int main(void)
{
	string p = "aba";
	string s = "babac";
	string test = "abcabcd";
	V<int> res = prefix(test);
	for(int i = 0; i < res.size(); i++)
		printf("%d ", res[i]);
	printf("\n");
	return 0;
}
