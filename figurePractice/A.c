#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cmath>

double NormalDistribution(){
	float v1, v2, s = 0;
	
	do{
		v1 = 2 * ( (float) rand() / RAND_MAX ) - 1;
		v2 = 2 * ( (float) rand() / RAND_MAX ) - 1;
		s = v1 * v1 + v2 * v2;
	}while(s >= 1 || s == 0);
	
	s = sqrt( (-2 * log(s)) / s);
	
	return v1 * s;
}

int A(){	
	return rand()%100;
}
int B(){
	return ( (int)NormalDistribution() ) * 20 + 50;
}
int C(){
	return ( (int)NormalDistribution() ) * 10 + 50;
}

int main(){
	char method;
	int it_num, i;
	int (*target_method)();
	FILE *out = fopen("out.txt", "w");

	srand( (unsigned)time(NULL) );	


	printf("method, iteration num\n");
	
	scanf("%c, %d", &method, &it_num);
	
	switch(method){
	case 'A':
		target_method = A;
		break;
	case 'B':
		target_method = B;
		break;
	case 'C':
		target_method = C;
		break;
	}
	
	for(i = 0;i < it_num;i++){
		fprintf(out, "%d\n", target_method());
	}
	fclose(out);

	return 0;
}
