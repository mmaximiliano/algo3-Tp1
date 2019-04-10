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

bool compPi(pll &a, pll &b) 				// funcion de comparacion para max_element
{ 
    return (a.second < b.second); 
}

ll bruteForce(vector<pll> &pedidos, ll &n, ll &w){
	ll maxPi = 0;
	ll indice = 1;
	ll wi,pi;
	indice = indice << n;

	for(ll i = 0; i < indice; i++)			// armo los subconjuntos O(n2^n)
	{
		wi = 0;
		pi = 0;
		for(ll j = 0; j < n; j++)
		{
			if(i & (1<<j))
			{
				wi += pedidos[j].first;		//sumo los pesos
				pi += pedidos[j].second;	//sumo los beneficios
			}
		}
		if (wi>w)
		{
			pi = -1;
		}
		maxPi = max(maxPi, pi);				//me quedo con el maximo hasta el momento
	}
	return maxPi;
}

int main() {
	
	ll n, w;								// w = capacidad del comprador
	cin >> n >> w; 							// n = cantidad de pedidos disponibles

	vector<pll> pedidos(n);					// vector con los valores wi, pi
	
	ll wi, pi;
	ll maxP = 0;	

	for(ll i = 0; i < n; i++)				// obtengo los valores wi, pi
	{	
		cin>>wi>>pi;
		pedidos[i] = make_pair(wi, pi);
	}

	maxP = bruteForce(pedidos,n,w);

	cout << maxP << "\n";

	return 0;
}