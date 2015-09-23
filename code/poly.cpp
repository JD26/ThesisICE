#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

class FL {
	private:		
		mat A;
		int n;
		mat I;

	public:
		FL(mat a) {						 
			A = a;
			n = A.n_rows;
			I = eye<mat>(n,n);
		}
		
		vec Coef() {
			mat C = A;
			vec c(n);
			for(int i = 1; i <= (n-1); i++) {
				c(i-1) = -trace(C)/i;
			 	C = A*(C + c(i-1)*I);
			}
			c(n-1) =  -trace(C)/n;
			return c;
		}	
};

int main() {
	mat A = "3 6 2; 2 5 2; 1 2 3";
	FL fl(A);
	cout<<fl.Coef();	
	return 0;
}
