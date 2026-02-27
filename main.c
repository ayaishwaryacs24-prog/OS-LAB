#include <stdio.h>
  int main() {
    int a[100], n, i, key;
    int low, high, mid;
    int found = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements (sorted for binary search):\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);
    for(i = 0; i < n; i++) {
        if(a[i] == key) {
            printf("Linear Search: Element found at position %d\n", i + 1);
            found = 1;
            break;
        }
    }
    if(found == 0)
        printf("Linear Search: Element not found\n");
    low = 0;
    high = n - 1;
    found = 0;

    while(low <= high) {
        mid = (low + high) / 2;
    if(a[mid] == key) {
            printf("Binary Search: Element found at position %d\n", mid + 1);
            found = 1;
            break;
        }
        else if(a[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    if(found == 0)
        printf("Binary Search: Element not found\n");

    return 0;
}
