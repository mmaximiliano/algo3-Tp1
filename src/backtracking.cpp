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


vector<pll> pedidos;
ll w;


//SIN PODAS
void solveBacktracking(pll& res, pll& parcial, int indice)
{
	for(int i = indice; i < pedidos.size(); i++)
	{
		//incluyo pedidos[i] en la solucion
		parcial.first += pedidos[i].first;
		parcial.second += pedidos[i].second;

		if(parcial.first <= w && parcial.second > res.second || parcial.second == res.second && parcial.first < res.first)
		{
			res.first = parcial.first;
			res.second = parcial.second;
		}

		//pasamos al proximo elemento
		solveBacktracking(res, parcial, i+1);

		//excluimos pedidos[i] de la solucion
		parcial.first -= pedidos[i].first;
		parcial.second -= pedidos[i].second;
	}

	return;
}


//CON PODAS
void solveBacktrackingPodas(pll& res, pll& parcial, int indice, ll b_total)
{
	for(int i = indice; i < pedidos.size(); i++)
	{
		//incluyo pedidos[i] en la solucion
		parcial.first += pedidos[i].first;
		parcial.second += pedidos[i].second;
		b_total -= pedidos[i].second;


		if(parcial.first <= w && parcial.second > res.second || parcial.second == res.second && parcial.first < res.first)
		{
			res.first = parcial.first;
			res.second = parcial.second;
		}


		//pasamos al proximo elemento
		//poda por factibilidad. Solo llamamos si el peso parcial es menor al limite
		//poda por optimalidad. Si no puedo llegar a sumar el mejor beneficio parcial, no sigo.
		if(parcial.first < w && parcial.second+b_total > res.second)
			solveBacktrackingPodas(res, parcial, i+1, b_total);

		//excluimos pedidos[i] de la solucion
		parcial.first -= pedidos[i].first;
		parcial.second -= pedidos[i].second;
	}

	return;
}




int main() {

	ll n;
	cin >> n; 				//cantidad de pedidos disponibles

	cin >> w;					//capacidad del comprador

	ll b_total = 0;		//guardo el beneficio total para la poda por optimalidad

	for(int i = 0; i < n; i++)
	{
		ll wi, pi;
		cin>>wi>>pi;
		b_total += pi;
		pedidos.push_back(make_pair(wi, pi));
	}


	pll inicial = make_pair(0,0);
	pll res = inicial;
	solveBacktrackingPodas(res, inicial, 0, b_total);

	cout<<res.second<<'\n';

	return 0;
}
