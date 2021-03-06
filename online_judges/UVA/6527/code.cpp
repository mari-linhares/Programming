#include <bits/stdc++.h>
#define ll long long int
#define MAX 60

using namespace std;

int bin_num[MAX];
ll memo[MAX][2][MAX];

ll dp(int pos, int value, ll sum) {
	if(pos == -1) return sum;
	if(memo[pos][value][sum] != -1) return memo[pos][value][sum];
	
	ll ans = 0;
	if(value) ans += dp(pos - 1, value, sum + 1) + dp(pos - 1, value, sum);
	else if(bin_num[pos] == 0) ans += dp(pos - 1, value, sum);
	else ans += dp(pos - 1, 1, sum) + dp(pos - 1, 0, sum + 1);

	memo[pos][value][sum] = ans;
	return ans;
}

ll answer(ll x) {

	int count = 0;	
	while(x != 0) {
		bin_num[count] = x % 2;
		x /= 2;
		count++;
	}

	memset(memo, -1, sizeof(memo));
	return dp(count - 1, 0, 0);
}

int main() {

	ll a, b;
	while(scanf("%lld %lld", &a, &b) != EOF) printf("%lld\n", answer(b) - answer(a - 1));

	return 0;
}
