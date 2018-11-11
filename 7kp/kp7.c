#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct
{
    double real,im;
} complex_t;


struct node {
    complex_t info;
    struct node *next;
    struct node *prev;
};
typedef struct node zveno;


float modul ( complex_t a) {
    float result;
    result = sqrt ((a.real * a.real) + (a.im * a.im));
    return result;
}


complex_t delenie ( complex_t a, complex_t b) {
    complex_t result;
    double real;
    double im;
    
    real = (a.real * b.real + a.im * b.im) / (b.real * b.real + b.im * b.im);
    im = (b.real * a.im - a.real * b.im) / (b.real * b.real + b.im * b.im);
    
    result.real = real;
    result.im = im;
    
    return result;
}


int rows,cols;
int max;

zveno* create_head(complex_t chislo) {
    zveno *root;
    root = (zveno*)malloc(sizeof(zveno));
    root -> info.real = chislo.real;
    root -> info.im = chislo.im;
    root -> next = NULL;
    root -> prev = NULL;
    return(root);
}

zveno* add_elem(zveno *root, complex_t chislo) {
    zveno *temp, *p;
    temp = (zveno*)malloc(sizeof(zveno));
    p = root->next; // сохранение указателя на следующий узел
    root->next = temp; // предыдущий узел указывает на создаваемый
    temp->info.real = chislo.real;
    temp->info.im = chislo.im;    // сохранение поля данных добавляемого узла
    temp->next = p; // созданный узел указывает на следующий узел
    temp->prev = root; // созданный узел указывает на предыдущий узел
    if (p != NULL)
        p->prev = temp;
    return(temp);
}




void listprint(zveno *root) {
    zveno *p;
    p = root;
    do {
        if ( p->info.im != 0 ) printf("%g.%g " , p->info.real, p->info.im);
        if (p-> info.im == 0) printf("%g " , p->info.real);
        p = p->next; // переход к следующему узлу
    } while (p != NULL); // условие окончания обхода
}

int find_row(int i, complex_t mass[rows][cols]) {
    for (int a = i; a < rows; a++) {
        for (int j = 0; j < cols; j++) {
            if    (    (mass[a][j].real != 0 && mass[a][j].im == 0) || (mass[a][j].real == 0 && mass[a][j].im != 0) || (mass[a][j].real != 0 && mass[a][j].im != 0) ) return a;
        }
    }  return -1;
}

complex_t max_maitrix(complex_t mass[rows][cols]) {
    complex_t max1 ;
    max1.real = max1.im = 0;
    for (int i = 0;i < rows; i++) {
        for (int j= 0; j < cols; j++) {
            
            if (modul (mass[i][j]) > modul(max1)) { max1 = mass[i][j]; }
            
        }
    } return max1;
}

int find_col(complex_t mass[rows][cols], complex_t max) {
    for (int i = 0;i < rows; i++) {
        for (int j= 0; j < cols; j++) {
            if ((mass[i][j].im == max.im) && (mass[i][j].real == max.real)) {return j;}
        }
    } return 0;
}

int main() {
    complex_t d;
    complex_t o;
    o.real = o.im = 0;
    complex_t help;
    printf ("ВВедите количество строк \n");
    scanf ("%d", &rows);
    printf ("ВВедите количество столбцов \n");
    scanf ("%d", &cols);
    complex_t mass[rows][cols];
    printf ("Введите матрицу \n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf ("%lf %lf", &d.real, &d.im);
            mass[i][j] = d;
        }
    }
    printf ("Ваша матрица \n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            
            if (mass[i][j].im == 0 ) printf("%g + %gi", mass[i][j].real, mass[i][j].im);
            if (mass[i][j].im > 0 ) printf("%g + %gi", mass[i][j].real, mass[i][j].im);
            if (mass[i][j].im < 0 ) printf("%g %gi", mass[i][j].real, mass[i][j].im);
            printf (" ");
        } printf ("\n");
    }
    int otv;
    zveno *head, *spisok;
    head = create_head(o);
    spisok = head;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            otv = find_row(i, mass);
            if ( otv != -1) {
                help.real = otv+1;
                help.im = 0;
                spisok = add_elem(spisok,help);
            } else {
                spisok = add_elem(spisok,o);
                spisok = add_elem(spisok,o);
                listprint(head);
                complex_t max1 = max_maitrix(mass);
                printf("Максимальный элемент ");
                if (max1.im == 0 ) printf("%g + %gi ", max1.real, max1.im);
                printf("\n");
                
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        
                        if (mass[i][j].im == 0 ) printf("%g + %gi", mass[i][j].real, mass[i][j].im);
                        if (mass[i][j].im > 0 ) printf("%g + %gi", mass[i][j].real, mass[i][j].im);
                        if (mass[i][j].im < 0 ) printf("%g %gi", mass[i][j].real, mass[i][j].im);
                        printf (" ");
                    } printf ("\n");
                }
                
                
                exit(1);}
            break;
        } break;
    }
    for (int i = otv; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            
            if (j != cols - 1) {
                if    (    (mass[i][j].real != 0 && mass[i][j].im == 0) || (mass[i][j].real == 0 && mass[i][j].im != 0) || (mass[i][j].real != 0 && mass[i][j].im != 0) ) {
                    help.real = j+1;
                    help.im = 0;
                    spisok = add_elem(spisok, help);
                    spisok = add_elem(spisok, mass[i][j]);
                }
            } if (j == cols - 1) {
                if (i != rows - 1) {
                    if    (    (mass[i][j].real != 0 && mass[i][j].im == 0) || (mass[i][j].real == 0 && mass[i][j].im != 0) || (mass[i][j].real != 0 && mass[i][j].im != 0) )
                    {
                        help.real = j+1;
                        help.im = 0;
                        spisok = add_elem(spisok, help);
                        spisok = add_elem(spisok, mass[i][j]);
                    }
                    otv = find_row(i + 1, mass);
                    if (otv != -1) {
                        help.real = otv+1;
                        help.im = 0;
                        spisok = add_elem(spisok,o);
                        spisok = add_elem(spisok, help);
                        i = otv - 1; }
                    
                } else if (i == rows - 1) {
                    if    (    (mass[i][j].real != 0 && mass[i][j].im == 0) || (mass[i][j].real == 0 && mass[i][j].im != 0) || (mass[i][j].real != 0 && mass[i][j].im != 0) )
                    {
                        help.real = j+1;
                        help.im = 0;
                        spisok = add_elem(spisok, help);
                        spisok = add_elem(spisok, mass[i][j]);
                    }
                }
            }
            
        }
    }
    spisok = add_elem(spisok, o);
    spisok = add_elem(spisok, o);
    printf("Матрица в виде 1 вектора \n");
    listprint(head);
    printf("\n");
    int jj;
    int del;
    int drob;
    complex_t dele;
    complex_t max1 = max_maitrix(mass);
    printf("Максимальный элемент ");
    if (max1.im == 0 ) printf("%g + %gi ", max1.real, max1.im);
    if (max1.im > 0 ) printf("%g + %gi ", max1.real, max1.im);
    if (max1.im < 0 ) printf("%g %gi ", max1.real, max1.im);
    printf("\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            jj = find_col(mass, max1);
            if (j != jj) {
                if (mass[i][j].im == 0 ) printf("%g + %gi ", mass[i][j].real, mass[i][j].im);
                if (mass[i][j].im > 0 ) printf("%g + %gi ", mass[i][j].real, mass[i][j].im);
                if (mass[i][j].im < 0 ) printf("%g %gi ", mass[i][j].real, mass[i][j].im);
                printf (" ");
            } else if (j == jj) {
                dele = delenie( mass[i][j], max1);
                if (dele.im == 0 ) printf("%g + %gi ", dele.real, dele.im);
                if (dele.im > 0 ) printf("%g + %gi ", dele.real, dele.im);
                if (dele.im < 0 ) printf("%g %gi ", dele.real, dele.im);
            }
        } printf ("\n");
    }
    return 0;
}
