#include <bits/stdc++.h>

using namespace std;

map<int, char> m;
map<int, int> x, y;

bool check1(int i, int j, int k) {
     if(x[i] == x[j] && x[j] == x[k] && y[i] + y[j] + y[k] == x[i]) {
	    cout << x[i] << endl;
	    for(int h = 1; h <= y[i]; h++) {
	        for(int g = 1; g <= x[i]; g++)
	            cout << m[i];
	        cout << endl;
	    }
	    for(int h = 1; h <= y[j]; h++) {
	        for(int g = 1; g <= x[i]; g++)
	            cout << m[j];
	        cout << endl;
	    }
	    for(int h = 1; h <= y[k]; h++) {
	        for(int g = 1; g <= x[i]; g++)
	            cout << m[k];
	        cout << endl;
	    }
            return true;
    }
    return false;
}

bool check2(int i, int j, int k) {
    if(x[i] == x[j] + x[k] && y[j] == y[k] && y[j] + y[i] == x[i]) {
	    cout << x[i] << endl;
	    for (int h = 1; h <= y[i]; h++) {
		for (int g = 1; g <= x[i]; g++)
		    cout << m[i];
		cout << endl;
	    }

	    for(int h = 1; h <= y[j]; h++) {
		for(int g = 1; g <= x[j]; g++)
		    cout << m[j];
		for(int g = 1; g <= x[k]; g++)
		    cout << m[k];
		cout << endl;
	    }
    	    return true;
    }

    return false;
}

int main() {
    int xx1, yy1, xx2, yy2, xx3, yy3;
    m[1] = 'A'; m[2] = 'B'; m[3] = 'C';
    cin >> xx1 >> yy1 >> xx2 >> yy2 >> xx3 >> yy3;
    
    for (int mask = 0; mask <= 7; mask++) {
        if (mask & 1) { x[1] = yy1; y[1] = xx1;}
	else {x[1] = xx1; y[1] = yy1;}
	if (mask & 2) { x[2] = yy2; y[2] = xx2;}
	else {x[2] = xx2; y[2] = yy2;}
	if (mask & 4) { x[3] = yy3; y[3] = xx3;}
	else {x[3] = xx3; y[3] = yy3;}

	if(check1(1, 2, 3)) return 0;
	if(check2(1, 2, 3)) return 0;
	if(check2(2, 1, 3)) return 0;	
	if(check2(3, 2, 1)) return 0;
    }
    cout << -1 << endl;
    return 0;
}
