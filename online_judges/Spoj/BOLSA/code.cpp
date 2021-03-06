#include <bits/stdc++.h> 

#define MAX 40100 
#define EPS 1e-7

#define ll long long int
#define F first
#define S second 
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define vi vector<int> 
#define vpii vector<pair<int,int> >
 
using namespace std; 

char c;
int n;
double ans, x;
priority_queue<double> buy, sell;

int main() {
 
    while(scanf("%d",&n) != EOF) {
        
        if(n == 0) break;

        ans = 0;
        while(!buy.empty()) buy.pop();
        while(!sell.empty()) sell.pop();

        for(int i = 0; i < n; i++) {

            scanf("\n%c %lf", &c, &x);

            if (c == 'C') buy.push(x);
			else sell.push(-x);

			if (!buy.empty() && !sell.empty()) {
				if (buy.top() >= -sell.top()) {
					ans += buy.top() - (-1*sell.top());
					buy.pop(); sell.pop();
				}
				else buy.top();
			}
		}

		cout << setprecision(2) << fixed << ans << endl;

	}

	return 0; 
}
