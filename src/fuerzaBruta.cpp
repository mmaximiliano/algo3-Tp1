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

bool compPi(pll a, pll b) 				// funcion de comparacion para max_element
{ 
    return (a.second < b.second); 
}


int main() {
	
	ll n, w;							// w = capacidad del comprador
	cin >> n >> w; 						// n = cantidad de pedidos disponibles

	vector<pll> pedidos(n);				// vector con los valores wi, pi
	
	ll wi, pi, maxPi;	

	for(int i = 0; i < n; i++)			// obtengo los valores wi, pi
	{	
		cin>>wi>>pi;
		pedidos[i] = make_pair(wi, pi);
	}

	vector<pll> subSets(1<<n);	// todos los subconjuntos

	for(int i = 0; i < (1<<n); i++)		// armo los subconjuntos O(n2^n)
	{
		wi = 0;
		pi = 0;
		for(int j = 0; j < n; j++)
		{
			if(i & (1<<j))
			{
				wi += pedidos[j].first;
				pi += pedidos[j].second;
			}
		}
		if (wi>w)
		{
			pi = -1;
		}
		subSets[i] = make_pair(wi,pi);
	}

	// obtengo maximo pi
	maxPi = (*(max_element(subSets.begin(), subSets.end(), compPi))).second;
	cout << maxPi << "\n";

	return 0;
}