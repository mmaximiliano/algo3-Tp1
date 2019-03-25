#pragma GCC optimize("O3")
//~ #pragma GCC optimize("Ofast")
//~ #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi = vector<int>;
using vll = vector<ll>;

//dado un conj c, arma todos sus subconjuntos de tamaño maximo n a partir de m
void armarSubconjuntos(vector<pll>& c, vector<pll>& res, ll n, ll m)
{
	for(int i = 0; i < (1<<n); i++)
	{
		ll wi = 0;
		ll pi = 0;
		for(int j = 0; j < n; j++)
		{
			if(i & (1<<j))
			{
				wi += c[j+m].first;
				pi += c[j+m].second;
			}
		}
		res.push_back(make_pair(wi, pi));
	}
}


//para ordenar de mayor a menor segun el beneficio
bool ordenarPorValor(pll a, pll b)
{
	return (a.second < b.second);
}


vector<pll> filtrar(vector<pll>& v)
{
	vector<pll> res;
	ll currentW = v[0].first;
	ll currentP = v[0].second;
	res.push_back(make_pair(currentW, currentP));
	for(int i = 1; i < v.size(); i++)
	{
		if(v[i].first != currentW)
		{
			currentW = v[i].first;
			if(v[i].second > currentP)
			{
				currentP = v[i].second;
				res.push_back(make_pair(currentW, currentP));
			}
		}
	}
	return res;
}


ll binarySearch(vector<pll>& A, ll& x)
{
	int l = 0;
	int r = A.size()-1;
	while(l <= r)
	{
		int m = (l+r)/2;
		if (A[m].first < x) l = m+1;
		else if (A[m].first > x) r = m-1;
		else return A[m].second;
	}

	while(A[r].first > x) r--;
	return A[r].second;
}


ll solveMiddle(vector<pll>& T1, vector<pll>& T2, ll& w)
{
	ll res = 0;

	sort(T2.begin(), T2.end(), [](auto &left, auto &right) {return left.second > right.second;});					//ordeno T2 segun el beneficio de mayor a menor
	stable_sort(T2.begin(), T2.end(), [](auto &left, auto &right) {return left.first < right.first;});   	//ordeno T2 segun el peso de manera estable

	T2 = filtrar(T2);			//filtramos los subcjtos de T2 que pesan mas que otros de valor mayor o igual

	for(int i = 0; i < T1.size(); i++){
		ll complemento = w-T1[i].first;
		ll beneficio = binarySearch(T2, complemento);
		beneficio += T1[i].second;
		if(beneficio > res) res = beneficio;
	}

	return res;
}


int main(){
	ll n;
	cin >> n; 				//cantidad de pedidos disponibles
	ll w;
	cin >> w;					//capacidad del comprador

	//T1 y T2 van a contener los subconjuntos de cada mitad de pedidos
	vector<pll> pedidos(n);
	vector<pll> T1, T2;

	for(int i = 0; i < n; i++)
	{
		ll wi, pi;
		cin>>wi>>pi;
		pedidos[i] = make_pair(wi, pi);
	}

	armarSubconjuntos(pedidos, T1, n/2, 0);
	armarSubconjuntos(pedidos, T2, n-n/2, n/2);

	cout<<solveMiddle(T1, T2, w)<<'\n';


	return 0;
}
