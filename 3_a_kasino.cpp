#include<bits/stdc++.h>
using namespace std;
using ll = uint64_t;

constexpr ll MOD = 1e9 + 7;
int n, m;
ll t;

void init_matrix(ll A[]);
void multiply_matrix(ll A[], ll B[], ll C[]); // result in C
void power_matrix(ll A[], ll t);
void mat_mul_vec(ll A[], ll a[], ll b[]);
ll dot_prod(ll A[], int row, ll B[], int col);
void matrix_copy(ll from[], ll to[]);
void matrix_print(ll A[]);
void identity_matrix(ll A[]);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;
	ll A[n*n];
	init_matrix(A);

	int i, j;
	while(m--)
	{
		cin >> i >> j;
		A[(j - 1)*n + i - 1] = 1;
		
	}
	for(int i = 0; i < n; i++) A[i*n + i] = 1;
	

	ll a[n];
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		
	}
	cin >> t;
	

	power_matrix(A, t);


	ll res[n]; //result stored here
	mat_mul_vec(A, a, res);

	for(int i = 0; i < n; i++) cout << res[i] << ' ';
	cout <<'\n';
}

void matrix_print(ll A[])
{
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << A[i*n + j] << ' ';
		} cout << '\n';
	}
	cout << '\n';
}

void power_matrix(ll A[], ll t)
{
	ll B[n*n];
	ll res[n*n];
	init_matrix(B);
	identity_matrix(res);
	while(t)
	{	
		if(t & 1)
		{
			multiply_matrix(res, A, B);
			matrix_copy(B, res);
		}

		t >>= 1;

		multiply_matrix(A, A, B);
		matrix_copy(B, A);
	}
	matrix_copy(res, A);
}

void identity_matrix(ll A[])
{
	init_matrix(A);
	for(int i = 0; i < n; i++) A[i*n + i] = 1;
}

void init_matrix(ll A[])
{
	for(int i = 0; i < n * n; i++)
		A[i] = 0;
}

void multiply_matrix(ll A[], ll B[], ll C[])
{
	init_matrix(C);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			C[i*n + j] = dot_prod(A, i, B, j);
		}
	}
}

ll dot_prod(ll A[], int row, ll B[], int col)
{
	ll res = 0;
	for(int i = 0; i < n; i++){
		res = ((res % MOD) + ((A[row * n + i] % MOD) * (B[i * n + col] % MOD)) % MOD) % MOD;
	}
	return res;
}

void mat_mul_vec(ll A[], ll a[], ll b[])
{
	for(int i = 0; i < n; i++){
		b[i] = 0;
		for(int j = 0; j < n; j++){
			b[i] = ((b[i] % MOD) + ((A[i*n + j] % MOD)*(a[j] % MOD)) % MOD) % MOD;
		}
	}
}

void matrix_copy(ll from[], ll to[])
{
	for(int i = 0; i < n*n; i++) to[i] = from[i];
}