#include <stddef.h>
#include "ll_cycle.h"

int ll_has_cycle(node *head) {
    /* your code here */
    node *tortoise = head;
    node *hare = head;

    while (1) {
        for (int i = 0; i < 2; ++i) {
            if (hare == NULL) {
                return 0;
            } else {
                hare = hare->next;
            }
        }

        tortoise = tortoise->next;

        if (tortoise == hare) {
            return 1;
        }
    }

    return 0;
}