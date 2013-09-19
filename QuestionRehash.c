#include <stdio.h>
#include <stdlib.h>
#include <string.h>



/*
	This was the second attempt using pointers and pointer arithmetic. 

	This code does not change the original string.
*/
char* reverseUsingPTRS(char* s){


	int size = strlen(s);		
	char* newString = (char*)malloc((size + 1) * sizeof(char));  	//(+1)for end of line terminator 
	
	int count = 0;

	/*
		I think this is how pointer arithmetic works. I would want to reference 
		a source to make sure its the correct syntax. (turns out I was correct).

		(size-1) needed for 0 based index
	*/

	while(count < size){

		*(newString + count) = *(s + ((size-1)-count));			
		count++;
	}
	*(newString + size) = '\0';   // 

	return newString;

}

/*
	This was the first version of the code.
		works even with an even or odd number of array elements.

		This code changes the original string
*/
char* reverseInPlace(char* s){

	char tmp = 'h'; 		
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

