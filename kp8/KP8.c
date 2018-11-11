#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct node {
	int info;
	struct node *next;
	struct node *prev;
};

typedef struct node zveno;

zveno* create_head(int a) {
	zveno *root;
	root = (zveno*)malloc(sizeof(zveno));
	root -> info = a;
	root -> next = NULL;
	root -> prev = NULL;
	return(root);
}

zveno* add_elem(zveno *root, int chislo) {
	zveno *temp, *p;
	temp = (zveno*)malloc(sizeof(zveno));
	p = root->next; // сохранение указателя на следующий узел
	root->next = temp; // предыдущий узел указывает на создаваемый
	temp->info = chislo; // сохранение поля данных добавляемого узла
	temp->next = p; // созданный узел указывает на следующий узел
	temp->prev = root; // созданный узел указывает на предыдущий узел
	if (p != NULL)
		p->prev = temp;
	return(temp);
}

zveno * deletelem(zveno *root) {
	zveno *prev, *next;
	prev = root->prev; // узел, предшествующий root
	next = root->next; // узел, следующий root
	if (prev != NULL)
		prev->next = root->next; // переставляем указатель
	if (next != NULL)
		next->prev = root->prev; // переставляем указатель
	free(root); // освобождаем память удаляемого элемента
	return(prev);
}

void listprint(zveno *root) {
	zveno *p;
	p = root;
	do {
		printf("%d ", p->info); // вывод значения элемента p
		p = p->next; // переход к следующему узлу
	} while (p != NULL); // условие окончания обхода
}

zveno * find_uzel(zveno *root, int znach) {

	zveno *prev, *next;
	while (root->info != znach) {
	prev = root->prev; // узел, предшествующий root
	next = root->next; // узел, следующий за root
	if (next != NULL)
		root = next; }// переставляем указатель
	 // освобождаем память удаляемого элемента
	return(root);
}

zveno * find_last(zveno *root) {
	zveno *prev, *next;
	while (root->next != NULL) {
	prev = root->prev; // узел, предшествующий root
	next = root->next; // узел, следующий за root
	if (next != NULL)
		root = next; }// переставляем указатель
	 // освобождаем память удаляемого элемента
	return(root);

}



int main (void) {
	zveno *head, *spisok;
	int num;
	int lenght;
	int l;
	printf("ВВедите кол-во элементов: ");
	scanf("%d", &l);
	printf("a = ");
	scanf("%d", &num);

	lenght++;

	head = create_head(num);
	spisok = head;
	for (int i = 0; i < l - 1; i++) {
		printf("a = ");
		scanf("%d", &num);
		lenght++;
		spisok = add_elem(spisok, num);
	}
	listprint(head);
	printf("\n");
	printf("Длина списка= ");
	printf("%d", lenght);
	printf("\n");

	char cmd;
	int aloha;
	int ish;
	zveno* err;
	
	while (scanf("%c", &cmd) == 1) {
        if (cmd == '+') {
            if (scanf("%d%d", &aloha, &ish ) == 2) {
            	err = find_uzel(head, aloha);
            	spisok = add_elem(err,ish);
            	listprint(head);
				printf("\n");
				lenght++;
				printf("Длина списка= ");
				printf("%d" , lenght);
				printf("\n");
			}    
        } if (cmd == '-') {
        	if (scanf("%d", &aloha) == 1) {
        		err = find_uzel(head, aloha);
        		spisok = deletelem(err);
        		listprint(head);
				printf("\n");

				lenght--;
				printf("Длина списка= ");
				printf("%d", lenght);
				printf("\n");
        	}
        }   if (cmd == '*') {
        		if (scanf("%d%d", &aloha, &ish) == 2){
        			if (lenght > ish) {
        				printf("k < razmera massiva");
        				printf("\n");
        				listprint(head);
						  printf("\n");
						  printf("Длина списка= ");
						  printf("%d", lenght);
						  printf("\n");
        			} else {
        				err = find_last(spisok);
        				while ( lenght < ish) {
        					
        					spisok = add_elem(err, aloha);
        					lenght++;
        				} listprint(head);
						  printf("\n");
						  printf("Длина списка= ");
						  printf("%d", lenght);
						  printf("\n");
        			}
        		}
        }
    }
}


	
