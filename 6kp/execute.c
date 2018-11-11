#include <stdio.h> 
#include <stdlib.h> 

#include "student.h" 
#include "io.h" 

int stipend(int a , int b, int c, int d) {
	if (a >= 3 && b >= 4 && c >=4 && d >= 4) return 1;
	if (a >= 4 && b >= 4 && c >=3 && d >= 4) return 1;
	if (a >= 4 && b >= 3 && c >=4 && d >= 4) return 1;
    if (a >= 4 && b >= 4 && c >=4 && d >= 3) return 1;

	
	
	else return 0;
}

int main(int argc, char *argv[]) 
{ 
	if (argc != 2) { 
		printf("Usage:\n\t./execute DB_FILE\n"); 
		exit(0); 
	} 

	FILE *in = fopen(argv[1], "r"); 
	if (!in) { 
		printf("I/O Error: can't open file.\n"); 
		exit(1); 
	} 
	Student s; 
	while (student_read_txt(&s, in)){ 
		if (stipend(s.math, s.rus, s.physics, s.la) == 1) {
			student_print(&s); 

		} else (printf("wtf"));
	} 
	fclose(in); 
	return 0; 
}
