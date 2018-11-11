
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Наша структура
struct node
{
    int info;                           //Информационное поле
    struct node *l, *r;                        //Левая и Правая часть дерева
};

typedef struct node zveno;
struct node *tree = NULL;                      //Объявляем переменную, тип которой структура Дерево



/*ФУНКЦИЯ ЗАПИСИ ЭЛЕМЕНТА В БИНАРНОЕ ДЕРЕВО*/
void push(int a, struct node **t)
{
    if ((*t) == NULL)                   //Если дерева не существует
    {
        (*t) = malloc(sizeof(struct node));                //Выделяем память
        (*t)->info = a;                 //Кладем в выделенное место аргумент a
        (*t)->l = (*t)->r = NULL;       //Очищаем память для следующего роста
        return;                         
    }
    //Дерево есть
    if (a > (*t)->info) push(a, &(*t)->r); //Если аргумент а больше чем текущий элемент, кладем его вправо
    else push(a, &(*t)->l);         //Иначе кладем его влево
}

/*ФУНКЦИЯ ОТОБРАЖЕНИЯ ДЕРЕВА НА ЭКРАНЕ*/
void print (struct node *t, int u)
{
    if (t == NULL) {return;}                  //Если дерево пустое, то отображать нечего, выходим
    else //Иначе
    {
        print(t->l, ++u);                   //С помощью рекурсивного посещаем левое поддерево
        for (int i=0; i<u; ++i)  printf("|");
        printf("%d", t->info);
        printf("\n");            //И показываем элемент
        u--;
    }
    print(t->r, ++u);                       //С помощью рекурсии посещаем правое поддерево
}

int maxim (int x,int y)
{
    if (x > y) return x;
    else return y;
}

int height(struct node *p)
{
    struct node *temp=p;
    int h1=0, h2=0;
    if (p==NULL) return(0);
    if (p->l) {
        h1=height(p->l);
    }
    
    if (p->r){
        h2=height(p->r);
        }
    return (maxim(h1,h2)+1);
}

int getWidth(struct node* root, int level)
{
    if (!root) return 0;
    if (level == 1) return 1;
    else if (level > 1) return (getWidth(root->l, level-1) +  getWidth(root->r, level-1));
    else return 0;
}

int getMaxWidth(struct node* root)
{
    int maxWdth = 0;
    int i;
    int width = 0 ;
    int h = height(root);
    for( i = 1; i<= h; i++)
    {
        width = getWidth(root, i);
        if(width > maxWdth)
        maxWdth  = width;
    }
    return maxWdth;
}

void Delete_1 (struct node **r, struct node **q)
{
    struct node *s;
    
    if ((**r).r==NULL)
    { (**q).info = (**r).info; *q = *r;
        s = *r; *r = (**r).l;  }
    else Delete_1 (&((**r).r),q);
}

void Delete (struct node **Tree, int k)
// Удаление вершины k из бинарного дерева.
// *Tree - указатель на вершину дерева.
{
    struct node *q;
    
    if (*Tree==NULL) printf("Вершина с заданным ключом не найдена!\n");
    else
        if (k<(**Tree).info) Delete (&((**Tree).l),k);
        else
            if (k>(**Tree).info) Delete (&((**Tree).r),k);
            else  {
                q = *Tree;
                if ((*q).r==NULL) { *Tree = (*q).l;  }
                else
                    if ((*q).l==NULL) { *Tree = (*q).r; }
                    else Delete_1 (&((*q).l),&q);
            }
}



int main (void) {
    int l;
    int n;                              //Количество элементов
    int s;
    char cmd;
    int aloha;                       //Число, передаваемое в дерево
    printf("введите количество элементов  ");
    scanf("%d", &n);                           //Вводим количество элементов
    
    for (int i=0; i<n; ++i)
    {
        printf("ведите число  ");
        scanf("%d", &s);                       //Считываем элемент за элементом
        
        push(s, &tree);                 //И каждый кладем в дерево
    }
    printf("ваше дерево\n");
    print(tree, 0);
    
    l=getMaxWidth(tree);
    
    printf("Max ширина = ");
    printf("%d", getMaxWidth(tree));
    printf("\n");
    
    zveno *err;
    
    while (scanf("%c", &cmd) == 1) {
        if (cmd == '+') {
            if (scanf("%d", &aloha) == 1)
                push(aloha, &tree);
                print(tree,0);
                printf("Max ширина = ");
                printf("%d", getMaxWidth(tree));
                printf("\n");
            
        } if (cmd == '-') {
            if (scanf("%d", &aloha) == 1)
                Delete( &tree, aloha);
            
            print(tree,0);
            printf("Max ширина = ");
            printf("%d", getMaxWidth(tree));
            printf("\n");
        }
    }
    //printf("%n", &l);
    
    
}
