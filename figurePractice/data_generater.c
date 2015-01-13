#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <string>

double NormalDistribution(){
	double v1, v2, s = 0;
	
	do{
		v1 = 2 * ( (double) rand() / RAND_MAX ) - 1;
		v2 = 2 * ( (double) rand() / RAND_MAX ) - 1;
		s = v1 * v1 + v2 * v2;
	}while(s >= 1 || s == 0);
	
	s = sqrt( (-2 * log(s)) / s);
	
	return v1 * s;
}

double A(){	
	return ( (double) rand() / RAND_MAX ) * 100;
}
double B(){
	return NormalDistribution() * 20 + 50;
}
double C(){
	return NormalDistribution() * 10 + 50;
}

void makeoutput(double (*target_method)(), std::string functionName, std::string it_num){
	std::string filename = functionName+"_"+it_num+".txt";
	FILE *out = fopen(filename.c_str(), "w");
	
	for(int i = 0;i < atoi(it_num.c_str());i++){
		fprintf(out, "%f\n", target_method());
	}
	fclose(out);
}

int main(){
	char method;
	int (*target_method)();

	srand( (unsigned)time(NULL) );	

	makeoutput(A, "A", "10");
	makeoutput(A, "A", "10000");
	makeoutput(B, "B", "10");
	makeoutput(B, "B", "10000");
	makeoutput(C, "C", "10");
	makeoutput(C, "C", "10000");

	return 0;
}
