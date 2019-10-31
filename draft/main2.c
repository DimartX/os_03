#include <stdio.h>

void swap(int *a, int *b) {
    int t = (*a);
    (*a) = (*b);
    (*b) = t;
}

int partition(int *mass, int left, int right) {
    int pivot = mass[left];
    int leftwall = left;

    for (int i = left+1; i <= right; i++) {
        if (mass[i] < pivot) {
            swap(&mass[i], &mass[leftwall]);
            leftwall += 1;
        }
    }
    swap(&pivot, &mass[leftwall]);

    return leftwall;
}

void quicksort(int *mass, int left, int right) {
    if (left < right) {
        int pivot = partition(mass, left, right);
        quicksort(mass, left, pivot);
        quicksort(mass, pivot+1, right);
    }
}

int main() {
    int v[1000000];
    for (int i = 0; i < 1000000; i++) {
        scanf("%d ", &v[i]);
    }

    quicksort(v, 0, 999999);
    for (int i = 0; i < 1000000; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
    return 0;
}
