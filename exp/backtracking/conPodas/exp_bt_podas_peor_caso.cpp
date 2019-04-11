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


bool peorOrden(const pll &a, const pll &b)
{
    if(a.first < b.first) return true;
    else if (a.first == b.first) return (a.second < b.second);
    else return false;
}


//CON PODAS
void solveBacktrackingPodas(pll& res, pll& parcial, int indice, vector<pll>& pedidos, ll w, ll b_total)
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
			solveBacktrackingPodas(res, parcial, i+1, pedidos, w, b_total);

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

	for(ll n = 0; n < 50; n+=2) {

		ll total_fb = 0;
		//creo vector de n posiciones
		vector<pll> pedidos(n);

		ll wi, pi;
    ll b_total = 0;

		//utilizo una distribucion uniforme
		std::default_random_engine generator;
  	std::uniform_int_distribution<ll> distribution(1,w);

  		//relleno el vector con valores random
		for(ll i = 0; i < n; i++)
		{
			wi = distribution(generator);
			pi = distribution(generator);
      b_total+=pi;

			pedidos[i] = make_pair(wi, pi);
		}

    sort(pedidos.begin(), pedidos.end(), peorOrden);

		for(int rep = 0; rep < REPS; ++rep) {
			//reinicio res y parcial
			res = make_pair(0,0);
			parcial = res;

            auto time_start = std::chrono::steady_clock::now();

            solveBacktrackingPodas(res, parcial, 0, pedidos, w, b_total);

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
