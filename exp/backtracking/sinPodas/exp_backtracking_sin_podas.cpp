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


//SIN PODAS
void solveBacktracking(pll& res, pll& parcial, int indice, vector<pll> &pedidos, ll w)
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
		solveBacktracking(res, parcial, i+1, pedidos, w);

		//excluimos pedidos[i] de la solucion
		parcial.first -= pedidos[i].first;
		parcial.second -= pedidos[i].second;
	}

	return;
}


int main()
{
	ll REPS = 30;
	ll w = 25;
	pll res = make_pair(0,0);
	pll parcial = res;

    // Header del csv
    cout << "n,w,time,res" <<endl; 
	
	for(ll n = 0; n < 30; n+=2) {

		ll total_fb = 0;
		//creo vector de n posiciones
		vector<pll> pedidos(n);

		ll wi, pi;

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


		for(int rep = 0; rep < REPS; ++rep) {
			//reinicio res y parcial
			res = make_pair(0,0);
			parcial = res;

            auto time_start = std::chrono::steady_clock::now();    
            
            solveBacktracking(res, parcial, 0, pedidos, w);

            auto time_end = std::chrono::steady_clock::now();

            ll time_fb = std::chrono::duration_cast<std::chrono::nanoseconds>(time_end - time_start).count();

            total_fb += time_fb;
		}
		
		// Promedio de tiempo
		total_fb /= REPS;

		// Escribo a stdout, podria escribir directamente en un archivo especifico
        cout << n << "," << w << "," << total_fb  << ","<< res.second << "\n";
	}


	return 0;
}