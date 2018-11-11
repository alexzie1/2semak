#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

#include "student.h" 
#include "io.h" 

/* Student IO */ 
int student_read_txt(Student *s, FILE *in) 
{ 
fscanf(in, "%s", s->surname); 
fscanf(in, "%s", s->initials); 
fscanf(in, "%s", s->gender); 
fscanf(in, "%d", &(s->school));
fscanf(in, "%d", &(s->math));
fscanf(in, "%d", &(s->rus)); 
fscanf(in, "%d", &(s->physics));  
fscanf(in, "%d", &(s->la));

return !feof(in); 
} 

int student_read_bin(Student *s, FILE *in) 
{ 
fread(s->surname, sizeof(char), STR_SIZE, in); 
fread(s->initials, sizeof(char), 3, in); 
fread(s->gender, sizeof(char), 2, in); 
fread(&(s->school), sizeof(int), 1, in); 

fread(&(s->math), sizeof(int), 1, in);
fread(&(s->rus), sizeof(int), 1, in); 
fread(&(s->physics), sizeof(int), 1, in);  
fread(&(s->la), sizeof(int), 1, in);

return !feof(in); 
} 

void student_write_bin(Student *s, FILE *out) 
{ 
fwrite(s->surname, sizeof(char), STR_SIZE, out); 
fwrite(s->initials, sizeof(char), 3, out); 
fwrite(s->gender, sizeof(char), 2, out); 
fwrite(&(s->school), sizeof(int), 1, out); 

fwrite(&(s->math), sizeof(int), 1, out);
fwrite(&(s->rus), sizeof(int), 1, out);
fwrite(&(s->physics), sizeof(int), 1, out); 
fwrite(&(s->la), sizeof(int), 1, out);
} 

void student_print(Student *s) 
{ 
printf("Name: %s\n", s->surname); 
printf("Initials: %s\n", s->initials); 
printf("Gender: %s\n", s->gender); 
printf("group: %d\n", s->school); 

printf("MA: %d\n", s->math);
printf("DM: %d\n", s->rus);
printf("INFor: %d\n", s->physics);  
printf("LA: %d\n", s->la); 

printf("\n"); 
}
