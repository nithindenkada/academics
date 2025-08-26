#include <stdio.h>
int LinearSearch(int *a, int s, int k)
{
    for (int i = 0; i < s; i++)
    {
        if (a[i] == k)
            return i;
    }
    return -1;
}
int main()
{
    char filename[100];
    int key;
    int i, size;
    printf("Enter name of file: ");
    scanf("%s", filename);
    printf("number to search: ");
    scanf("%d", &key);
    FILE *file = fopen(filename, "r");
    if (file == NULL){
    printf("File not found");
    return 1;
    }
    int num = 0;
    while (fscanf(file, "%d", &num) != EOF)
        size++;
    rewind(file);

    int a[size];
    for (i = 0; i < size; i++)
        fscanf(file, "%d", &a[i]);
    fclose(file);
    
    int index = LinearSearch(a, size, key);
    if (index == -1)
        printf("%d not found\n", key);
    else
        printf("%d found at position %d\n", key, index + 1);
}