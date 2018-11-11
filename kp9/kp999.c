
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#define MAXSTRING 100
#define MAXELEM 100

struct ln
{
    int key;
    char str[MAXSTRING];
};

int qs(struct ln  line[MAXELEM], int first, int last, int kolvo)
{
    struct ln t;
    if (first < last)
    {
        int left = first, right = last, middle = line[(left + right) / 2].key;
        do
        {
            while (line[left].key < middle) left++;
            while (line[right].key > middle) right--;
            if (left <= right)
            {
                t = line[left];
                line[left] = line[right];
                line[right] = t;
                left++;
                right--;
            }
        } while (left <= right);
        qs(line, first, right,kolvo);
        qs(line, left, last,kolvo);
    } return 0;
}

int sprint(int n,struct ln line[MAXELEM])
{
    printf("\nKey:\tElement:\n");
    for (int i = 0; i<n; i++)
        printf("%d %s", line[i].key, line[i].str);
    return 0;
}

void randomize()
{
    long a = time(0);
    srand(a);
}

int randperm(int n, struct ln line[MAXELEM])
{
    struct ln temp;
    for (int i = 0; i<n; i++)
    {
        int j = rand() % n;
        temp = line[i];
        line[i] = line[j];
        line[j] = temp;
    } return 0;
}



int bsearch1(int n, struct ln line[MAXELEM])
{
    int m, left = 0, right = n - 1;
    int key;
    printf("Enter key: ");
    scanf("%d", &key);
    while (left<right) {
        m = (left + right) / 2;
        if (key>line[m].key)
            left = m + 1;
        else  right = m;
    }
    if (key == line[left].key)
        printf("Key is found:\n%d %s", key, line[left].str);
    else printf("Key not found\n");
    return 0;
}

int menu() {
    int m;
    printf("\n");
    printf("1 - Print file\n");
    printf("2 - quicksort \n");
    printf("3 - Random\n");
    printf("4 - Binary search\n");
    printf("\nEnter action: ");
    scanf("%d", &m);
    return m;
}

int main(int argc, char *argv[])
{
    struct ln line[MAXELEM];
    
    int n;
    FILE *f;
    int i;
    int m;
    int z = 0;
    if (argc==1)
    {if( (f=fopen("in1.txt","r")) == NULL ) {printf("File doesn't exists\n"); return 1;}}
    else
        if( (f=fopen(argv[1],"r")) == NULL ) {printf("File doesn't exists\n"); return 1;}
    n = 0;
    while (!feof(f))
    {
        fscanf(f, "%d", &line[n].key);
        fgets(line[n].str, MAXSTRING, f);
        n++;
    } n--;
    while (1)
    {
        m = menu();
        switch (m)
        {
            case 1: {sprint(n,line); break; }
            case 2: {qs( line,0,n-1,n);z = 1; break; }
            case 3: {randperm(n, line); z = 0; break; }
            case 4: {if (z)bsearch1(n, line); else printf("You should sort first\n"); break; }
            case 0: {fclose(f); return 0; }
            default: {printf("\nInvalide menu action\n"); break; }
        }
    }
}
