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


int main()
{
	ll REPS = 30;
	ll w = 25;
	ll res = 0;

    // Header del csv
    cout << "n,w,time,res" <<endl; 
	
	for(ll n = 0; n < 26; n+=2) {

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


		for(int rep = 0; rep < REPS; ++rep) {

            auto time_start = std::chrono::steady_clock::now();    
            
            res = bruteForce(pedidos, n, w);

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