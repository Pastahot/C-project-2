#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#pragma warning(disable : 4996)

//Binárne vyhladavanie
int binary_search(int array[], int cislo, int low, int high)
{
    int i = 0;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (array[mid] == cislo)
            break;
        else if (array[mid] < cislo)
        {
            i++;
            low = mid + 1;
        }
        else {
            high = mid - 1;
            i++;
        }
    }

    return i;
}

int binary_main() {

    FILE* binary_file_write = fopen("binary_out.txt", "w");
    int* array = (int*)malloc(10000 * sizeof(int));

    for (int y = 0; y < 1000; y++)
    {
        for (int i = 0; i < 10000; i++)
        {
            array[i] = i;
        }

        int x = rand() % 10000;
        int result = binary_search(array, x, 0, 10000 - 1);
        (result == 1);

        fprintf(binary_file_write, "%d\n", result);
    }
    fclose(binary_file_write);
    return 0;

}

int count_binary()
{
    FILE* binary_file_read = fopen("binary_out.txt", "r");
    int i = 0, sum = 0, n = 0, avg = 0;
    while (fscanf(binary_file_read, "%d", &n) != EOF)
    {

        sum += n;
        i++;
        avg = (sum / i);
    }
    printf("Priemerny pocet porovnani pouzitim binarneho vyhladavania je %d.\n", avg);
    fclose(binary_file_read);
    return 1;
}

//Lineárne vyhladavanie
int linear_search(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == x)
            break;

    return i;
}

int linear_main(void)
{
    FILE* linear_file_write = fopen("linear_out.txt", "w");
    int* array = (int*)malloc(10000 * sizeof(int));
    int i,y;

    for (y = 0; y < 1000; y++)
    {

        for (i = 0; i < 10000; i++)
        {
            array[i] = i;
        }

        int x = rand() % 10000;
        int result = linear_search(array, i, x);
        (result == 1);
        fprintf(linear_file_write, "%d\n", result);
    }
    fclose(linear_file_write);
    return 0;
}

int count_linear()
{
    FILE* linear_file_read = fopen("linear_out.txt", "r");
    int i = 0, sum = 0, n = 0, avg = 0;
    while (fscanf(linear_file_read, "%d", &n) != EOF)
    {

        sum += n;
        i++;
        avg = (sum / i);
    }
    printf("Priemerny pocet porovnani pouzitim linearneho vyhladavania je %d.\n", avg);
    fclose(linear_file_read);
    return 1;
}


void binary()
{
    binary_main();
    count_binary();
}

void linear()
{
    linear_main();
    count_linear();
}


int main()
{
    binary();
    linear();
    return 1;
}