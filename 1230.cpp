#include <stdio.h>
//list, vector로 segmentation fault --> 다 받지 말고 일부만 체크해볼 것.
int arr[4000];
 
int main(void) {
    int CN, ON, x, y, s, i, j, k, l;
    char o[2];
    for (i = 0; i < 10; i++) {
        scanf("%d", &CN);
        for (j = 0; j < CN; j++) {
            scanf("%d", &arr[j]);
        }
        scanf("%d", &ON);
        for (j = 0; j < ON; j++) {
            scanf("%s", o);
            if (o[0] == 'A') {
                x = CN;
            }
            else {
                scanf("%d", &x);
            }
            scanf("%d", &y);
            if (o[0] == 'I' || o[0] == 'A') {
                for (k = 0; k < y; k++) {
                    scanf("%d", &s);
                    if (x + k >= 0 && x + k <= CN && x + k < 4000) {
                        for (l = CN - 1; l >= x + k; l--) {
                            if (l < 3999) {
                                arr[l + 1] = arr[l];
                            }
                        }
                        arr[x + k] = s;
                        CN++;
                        if (CN > 4000) {
                            CN = 4000;
                        }
                    }
                }
            }
            else if (o[0] == 'D') {
                if (x >= 0 && x < CN) {
                    for (k = x; k < CN - y; k++) {
                        arr[k] = arr[k + y];
                    }
                    CN -= y;
                }
            }
        }
        printf("#%d", i + 1);
        for (j = 0; j < 10; j++) {
            printf(" %d", arr[j]);
        }
        printf("\n");
    }
}
