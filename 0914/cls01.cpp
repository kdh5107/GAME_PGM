#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int main(void)
{
	char input;
	while(true){
		scanf("%c", &input);
		printf("%c", &input);
		if(input=='\n'){
			break;
		}
	}
	printf("goodbye");	
	return 0;
}
