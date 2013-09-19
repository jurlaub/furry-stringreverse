#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	This is from memory, not consulting any sources. 

	List of things I would want to reference or check if I 
	wasn't doing this from memory (i.e. my memory is weak):
		1) tmp character
		2) sizeof function. For char does it include the end of line termination character?
		3) pointer arithmetic - See reversUsingPTRS()
		4) malloc and char. Is the (+1) needed?
			Answer through reasoning: malloc(sizeof(char) * 5) gives space for 5 char sized 
			blocks of memory with an index base of 0; the +1 would be needed for '/0'.
			For example: "hello" would need an extra space to be "hello'/0'"

*/

char* reverseUsingPTRS(char* s){


	int size = strlen(s);		//assuming it returns count of char in array not EOL terminator.
	char* newString = (char*)malloc((size + 1) * sizeof(char));  	//(+1)for end of line terminator (may not need this) 
	
	int count = 0;

	while(count < size){

		/*
			I think this is how pointer arithmetic works. I would want to reference 
			a source to make sure its the correct syntax.

			(size-1) needed for 0 based index
		*/
		*(newString + count) = *(s + ((size-1)-count));			
		count++;
	}
	*(newString + size) = '\0';   // 

	return newString;

}




char* reverseInPlace(char* s){

	char tmp = 'h'; 		// this is not how I have done this in the past
	int size = strlen(s);
	int i;

	for(i = 0; i < size/2; i++){
		tmp = s[i];
		s[i] = s[(size-1)-i];
		s[(size-1)-i] = tmp;
	}

	return s;
}



int main(void){

	char test[] = "hello";
	char *pt;
	pt = test;
	


	printf("Reverse in place:\n %s \n", pt );
	printf(" %s\n", reverseInPlace(pt) );
	printf("Reverse using pointers:\n %s \n %s \n", pt, reverseUsingPTRS(pt));
	


	return 0;
}

