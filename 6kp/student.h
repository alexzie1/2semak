#ifndef _STUDENT_H_ 
#define _STUDENT_H_ 

#define STR_SIZE 24 

typedef struct { 
char surname[STR_SIZE]; 
char initials[3]; 
char gender[2]; 
int school; 
int math;
int rus;
int physics;
int la;
} Student; 


#endif 

