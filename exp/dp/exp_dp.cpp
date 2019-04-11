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


int main()
{
	ll REPS = 30;

    // Header del csv
    cout << "n,w,time,res" <<endl; 

    //fijo w
	for (int w = 0; w < 30; w+=2)
	{
		//vario n
		for(int n = 0; n < 30; n+=2) {
	
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
	            
	            int dp[n+1][w+1];
	
				for(int i = 0; i <= n; i++){
					for(int j = 0; j <= w; j++){
						if(i==0 || j==0){
							dp[i][j] = 0;
						}else{
							if(pedidos[i-1].first <= j){
								dp[i][j] = max(dp[i-1][j], pedidos[i-1].second + dp[i-1][j-pedidos[i-1].first]);
							}else{
								dp[i][j] = dp[i-1][j];
							}
						}
					}
				}
	
	            auto time_end = std::chrono::steady_clock::now();
	            ll time_fb = std::chrono::duration_cast<std::chrono::nanoseconds>(time_end - time_start).count();
	
	            total_fb += time_fb;
			}
			
			// Promedio de tiempo
			total_fb /= REPS;
	
			// Escribo a stdout, podria escribir directamente en un archivo especifico
	        cout << n << "," << w << "," << total_fb  << ","<< dp[n][w] << "\n";
		}
	}

	return 0;
}