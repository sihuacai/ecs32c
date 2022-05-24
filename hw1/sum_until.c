#include <stdio.h>

int main() {
	int sum = 0; 
	int count = 0; 
	int user_input;

	do {
		printf("Enter integer: ");
		scanf("%d", &user_input);
		
		sum += user_input; 
		count += 1; 

	} while (count < 5 &&  sum < 800);
	
	printf("Final sum: %d\n", sum);
}
