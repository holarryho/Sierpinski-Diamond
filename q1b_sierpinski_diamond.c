#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h> 
  
bool is_power_of_two(int n) 
{ 
   return (ceil(log2(n)) == floor(log2(n))); 
} 
  

void print_row(int row, int height, int level)
{
	int space,star;

	if(level == 1){

		for(space = height - row; space >= 1; space--){
			printf(" ");
		}
		for(star = 1; star <= 2*row - 1; star++){
			printf("*");
		}

		for(space = height - row; space >= 1; space--){
			printf(" ");
		}
	}
	
	else if(row <= height/2){
		for(space = height/2; space >= 1; space--){
			printf(" ");
		}
		print_row(row, height/2, level - 1);
		for(space = height/2; space >= 1; space--){
			printf(" ");
		}
	}

	else{
		print_row(row - height/2, height/2, level - 1);
		printf(" ");
		print_row(row - height/2, height/2, level - 1);
	}



}


int main(int argc, char* argv[])
{
	if(argc != 3){
		return printf("ERROR: Wrong number of arguments. Two required\n");
	}

	int diamond_height = atoi(argv[1]);
	int level_input = atoi(argv[2]);
	int triangle_height = diamond_height/2 + 1;

	if(diamond_height%2 == 0 || diamond_height <= 0){
		return printf("ERROR: Bad argument. Height must be positive odd integer\n");
	}

	if(level_input <= 0){
		return printf("ERROR: Level has to be greater than or equal to 1\n");
	}

	if((!(is_power_of_two(triangle_height))) || triangle_height < pow(2, level_input - 1)){
		return printf("ERROR: Height does not allow evenly dividing requested number of levels\n");	
	}

	int row;
	for(row = 1; row <= triangle_height; row++){
		print_row(row, triangle_height, level_input);
		printf("\n");
	}
	for(row = triangle_height - 1; row > 0; row--){
		print_row(row, triangle_height, level_input);
		printf("\n");	
	}
}