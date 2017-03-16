#include <iostream>
#include <cmath>
using namespace std;


void Seidel(int size){
	double EPSILON = 0.00001; // error iterativo como tolerancia
	double A[size][size];
	double B[size];
	double S[size]; //Array with the solutions
	double OS[size];  //Array with old solutions
	double E[size]; //Array with th error of each variable
	cout<<"Enter the right hand side constants : " << endl;
  for(int i = 0; i < size; i++) {
      cin >> B[i];
  }
  cout<<"Enter the coefficients row wise : " << endl;
  for(int i = 0; i < size; i++) {
      for(int j = 0; j < size; j++) {
          cin>>A[i][j];
      }
  }
	for (int i = 0; i < size; ++i)
	{
		S[i] = 0;
		OS[i] = -999999;
		E[i] = (S[i]-OS[i]);
	}

	bool errorCheck = false;
	for (int i = 0; i < size; ++i)
	{
		if(E[i] <= EPSILON){
			errorCheck = true;
			break;
		}
	}

	int counter=0;

	while(!errorCheck){
		for (int i = 0; i < size; ++i)
		{
			double sum = 0;
			for (int j = 0; j < size; ++j)
			{
				if (j != i)
				{
					sum += A[i][j]*S[j];
				}
			}
			OS[i] = S[i];
			S[i] = (B[i] - sum)/A[i][i];

			E[i] = (S[i]-OS[i]);


		}

		for (int i = 0; i < size; ++i)
		{
			if(abs(E[i]) > EPSILON){
				break;
			}
			errorCheck = true;
		}
		counter++;
	}

	cout << "The Solution is : " << endl;
	for (int i = 0; i < size; ++i)
	{
		cout<<"x("<<i<<") = "<<S[i]<<"\n";
	}
}

int main(){
	int size;
	int solutions[] = {7,6,12};

	int n, l;
	float x [n];
	cout<<"Enter the value of n : " << endl;
	cin>>n;
	gaussSeidel(n);
	cout<<"The Solution is : " << endl;

	return 0;
}
