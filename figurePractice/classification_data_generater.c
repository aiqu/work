#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>

static int prob_data_A[5][5] = {
	{80, 5, 5, 5, 5},
	{5, 80, 5, 5, 5},
	{5, 5, 80, 5, 5},
	{5, 5, 5, 80, 5},
	{5, 5, 5, 5, 80}};

static int prob_data_B[5][5] = {
	{60, 10, 10, 10, 10},
	{10, 60, 10, 10, 10},
	{10, 10, 60, 10, 10},
	{10, 10, 10, 60, 10},
	{10, 10, 10, 10, 60}};

static int prob_data_C[5][5] = {
	{60, 5, 10, 20, 5},
	{10, 50, 5, 30, 5},
	{5, 5, 60, 25, 5},
	{5, 5, 5, 80, 5},
	{5, 5, 5, 40, 45}};

void genClassData(FILE* out, char class_name, int it_num, int a, int b, int c, int d, int e){
	int lottery;
	for(int i = 0;i < it_num;i++){
		char result_class = 'A';
		lottery = rand()%100;

		if(lottery <= a){
		}else if(lottery <= a+b)
			result_class = 'B';
		else if(lottery <= a+b+c)
			result_class = 'C';
		else if(lottery <= a+b+c+d)
			result_class = 'D';
		else
			result_class = 'E';

		fprintf(out, "%c\t%c\n", class_name, result_class);
	}
}

void genData(std::string filename, int it_num, int prob_data[5][5]){
	FILE* out = fopen(filename.c_str(), "w");
	genClassData(out, 'A', it_num, prob_data[0][0], prob_data[0][1], prob_data[0][2], prob_data[0][3], prob_data[0][4]);
	genClassData(out, 'B', it_num, prob_data[1][0], prob_data[1][1], prob_data[1][2], prob_data[1][3], prob_data[1][4]);
	genClassData(out, 'C', it_num, prob_data[2][0], prob_data[2][1], prob_data[2][2], prob_data[2][3], prob_data[2][4]);
	genClassData(out, 'D', it_num, prob_data[3][0], prob_data[3][1], prob_data[3][2], prob_data[3][3], prob_data[3][4]);
	genClassData(out, 'E', it_num, prob_data[4][0], prob_data[4][1], prob_data[4][2], prob_data[4][3], prob_data[4][4]);
	fclose(out);
}

int main(){
	srand( (unsigned int)time(NULL) );
	
	genData("type_A_10.txt", 10, prob_data_A);
	genData("type_A_10000.txt", 10000, prob_data_A);
	genData("type_B_10.txt", 10, prob_data_B);
	genData("type_B_10000.txt", 10000, prob_data_B);
	genData("type_C_10.txt", 10, prob_data_C);
	genData("type_C_10000.txt", 10000, prob_data_C);

	return 0;
}
