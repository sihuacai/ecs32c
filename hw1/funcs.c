#include <stdio.h>

int between(char lowerBound, char upperBound, char target) {
	if (lowerBound >= 97 || lowerBound <= 65 || upperBound >= 97 || upperBound <= 65 || target >= 97 || target <= 65)
		return -1;
	else{
		if (lowerBound > upperBound)
			return -2; 
		else if (lowerBound <= target && 
				target <= upperBound) 
			return 1; 
		else
			return 0;
	}
}

int shiftCipher(char text[], int k) {
	int i = 0;  // indexer thru text

	if (k > 500 || k < -500)
		return 0;

	// for (i = -1; text[i] != '\0'; i++) {
	while (text[i] != '\0') {	
		int shift = text[i] + k;
		int adjust;

		// check upper, lower, digit
		// upper
		if (text[i] >= 65 && text[i] <= 90) {
			if (shift < 65) 
				adjust = 91 - (65 % shift + shift) % shift;
			else
				adjust = (shift % 90 + 65) % 65 + 65;
			text[i] = adjust;
		} 
		// lower
		else if (text[i] >= 97 && text[i] <= 122) {
			if (shift < 97)
				adjust = 123 - (97 % shift + shift) % shift;
			else 
				adjust = (shift % 122 + 97) % 97 + 97; 
			text[i] = adjust;
		} 
		// digit
		else if (text[i] >= 48 && text[i] <= 57) {
			if (shift < 48)
				adjust = 58 - (48 % shift + shift) % shift;
			else 
				adjust = (shift % 57 + 48) % 48 + 48;
			text[i] = adjust;
		} else {
			i++;
			continue;
		}
		i++;



	}	
	return 1;
}
