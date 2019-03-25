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
void solveBacktrackingPodas(pll& res, pll& parcial, int indice)
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
		//poda por factibilidad. Solo llamamos si el peso parcial es menor al limite
		if(parcial.first < w) solveBacktrackingPodas(res, parcial, i+1);

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

	for(int i = 0; i < n; i++)
	{
		ll wi, pi;
		cin>>wi>>pi;
		pedidos.push_back(make_pair(wi, pi));
	}


	pll inicial = make_pair(0,0);
	pll res = inicial;
	solveBacktrackingPodas(res, inicial, 0);

	cout<<res.second<<'\n';

	return 0;
}
