#include <bits/stdc++.h>
using namespace std;
vector<int> a[100020];
int in[100020];
int out[100020];
int n, m, x, y, cnt;
int dfn[100020];
int low[100020];
int stk[100020], ss;
int v[100020];
int r[100020], scc;
void tarjan(int x)
{
	dfn[x] = low[x] = ++cnt;
	stk[ss++] = x;
	v[x] = 1;
	for (int y: a[x])
	{
		if (!dfn[y])
		{
			tarjan(y);
			low[x] = min(low[x], low[y]);
		}
		else if (v[y])
		{
			low[x] = min(low[x], dfn[y]);
		}
	}
	if (dfn[x] == low[x])
	{
		scc++;
		int u;
		do
		{
			u = stk[--ss];
			r[u] = scc;
			v[u] = 0;
		}
		while (u != x);
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		while (scanf("%d", &x), x)
		{
			a[i].push_back(x);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (!dfn[i])
		{
			tarjan(i);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j: a[i])
		{
			if (r[i] != r[j])
			{
				out[r[i]]++;
				in[r[j]]++;
			}
		}
	}
	int cntout = 0, cntin = 0;
	for (int i = 1; i <= scc; i++)
	{
		if (!out[i])
		{
			cntout++;
		}
		if (!in[i])
		{
			cntin++;
		}
	}
	printf("%d\n", cntin);
	printf("%d\n", scc == 1 ? 0 : max(cntin, cntout));
	return 0;
}