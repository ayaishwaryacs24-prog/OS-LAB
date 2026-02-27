#include <stdio.h>

int main() {
    int a[100], n, i;
    int min, position;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    min = a[0];
    position = 0;
    for(i = 1; i < n; i++) {
        if(a[i] < min) {
            min = a[i];
            position = i;
        }
    }
printf("Smallest number = %d\n", min);
    printf("Position = %d\n", position + 1);
    return 0;
}
