#include <stdio.h>
#include <string.h>

int main() 
{
	// read in user input strings
	char string1[31], string2[31];
	printf("Enter first string: \n");
	scanf("%30s", string1);	
	printf("Enter second string: \n");
	scanf("%30s", string2);

	int i, j, k;

	// count number of occurences of 
	// each letter in string 1
	int counts[31]; 
	for (i = 0; i < strlen(string1); i++) {
		int letter_count = 0; 
		for (j = 0; j < strlen(string2); j++) {
			if (string1[i] == string2[j])
				letter_count += 1;
		}
		counts[i] = letter_count;
	}
	
	// find max and print results 
	int most_index = 0; 
	for (k = 0; k < strlen(string1); k++) {
		if (counts[k] > counts[most_index])
			most_index = k;
	}
	
	printf("Most often: %c\n", string1[most_index]); 
       	printf("No. times: %d\n", counts[most_index]); 
}

