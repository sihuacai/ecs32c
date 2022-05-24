#include <stdio.h>

int main() {

	char input;
	float total = 0; 

	do {
		printf("Machine currently has $%.2f in it.\n", total);
		printf("Enter: ");
		scanf("%c%*c", &input);

		switch(input) {
			// putting in coins
			case 'h':
				total += 0.50; 
				break; 
			case 'q':
				total += 0.25;
				break; 
			case 'd':
				total += 0.10; 
				break; 
			case 'n': 
				total += 0.05;
				break;
			case 'p':
				total += 0.01; 
				break; 
			case 'x':
				break;
			
			// making drink selection
			case 's':
				if (total >= 2.00) {
					total -= 2.00; 
					printf("Enjoy your Sprite.\n");
				} else {
					float need = 2.00 - total; 
					printf("You need $%.2f more to afford Sprite.\n", need);
				}
				break; 
			case 'c':
				if (total >= 2.25) {
					total -= 2.25; 
					printf("Enjoy your Coke.\n");
				} else {
					float need = 2.25 - total; 
					printf("You need $%.2f more to afford Coke.\n", need);
				}
				break; 
			case 'm':
				if (total >= 1.50) {
					total -= 1.50; 
					printf("Enjoy your Mountain Dew.\n");
				} else {
					float need = 1.50 - total; 
					printf("You need $%.2f more to afford Mountain Dew.\n", need);
				}
				break; 

			default:
				printf("Invalid input.\n");	
		}
	} while (input != 'x');

	printf("Have a nice day.\n");
}
