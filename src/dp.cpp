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


int main() {
	
	int n, w;							// w = capacidad del comprador
	cin >> n >> w; 						// n = cantidad de pedidos disponibles

	vector<pii> pedidos(n);				// vector con los valores wi, pi
	
	int wi, pi;	

	for(int i = 0; i < n; i++)			// obtengo los valores wi, pi
	{	
		cin>>wi>>pi;
		pedidos[i] = make_pair(wi, pi);
	}

	int dp[n][w];

	for(int i = 0; i < n; i++){
		for(int j = 0; j < w; j++){
			if(i==0 || j==0){
				dp[i][j] = 0;
			}else{
				if(pedidos[i-1].first <= j){
					dp[i][j] = max(dp[i-1][j], pedidos[i-1].second + dp[i-1][j-pedidos[i].first]); 
					
				}else{
					dp[i][j] = dp[i-1][j];
				}

			}
		}
	}


	cout << dp[n][w] << "\n"; 
	return 0;
}