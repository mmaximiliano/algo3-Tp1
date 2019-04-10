#pragma GCC optimize("O3")
#include <chrono>
#include <random>
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi = vector<int>;
using vll = vector<ll>;

//-------Funciones Auxiliares--------

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
		if(complemento <= 0)
		{
			if(T1[i].second > res && T1[i].first <= w) res = T1[i].second;
		}
		else
		{
			ll beneficio = binarySearch(T2, complemento);
			beneficio += T1[i].second;
			if(beneficio > res) res = beneficio;
		}
	}


	return res;
}

//-------Fin Funciones Auxiliares---------

int main()
{
	ll REPS = 30;
	ll w = 25;
	ll res = 0;

    // Header del csv
    cout << "n,w,time,res" <<endl; 
	
	for(ll n = 0; n < 45; n+=2) {

		ll total_fb = 0;
		//creo vector de n posiciones
		vector<pll> pedidos(n);

		ll wi, pi;
		ll maxP = 0;	

		//utilizo una distribucion uniforme
		std::default_random_engine generator;
  		std::uniform_int_distribution<ll> distribution(1,w);

  		//relleno el vector con valores random
		for(ll i = 0; i < n; i++)	
		{	
			wi = distribution(generator);
			pi = distribution(generator);
			
			pedidos[i] = make_pair(wi, pi);
		}

		vector<pll> T1, T2;

		for(int rep = 0; rep < REPS; ++rep) {

            auto time_start = std::chrono::steady_clock::now();    
            
            armarSubconjuntos(pedidos, T1, n/2, 0);
			armarSubconjuntos(pedidos, T2, n-n/2, n/2);
			res = solveMiddle(T1, T2, w);
            

            auto time_end = std::chrono::steady_clock::now();
            ll time_fb = std::chrono::duration_cast<std::chrono::nanoseconds>(time_end - time_start).count();

            total_fb += time_fb;
		}
		
		// Promedio de tiempo
		total_fb /= REPS;

		// Escribo a stdout, podria escribir directamente en un archivo especifico
        cout << n << "," << w << "," << total_fb  << ","<< res << "\n";
	}


	return 0;
}