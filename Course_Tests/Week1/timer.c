#include <stdio.h>
#include <time.h>

int main(){

    double duration;
    clock_t start, end;
    start = clock();
    for (int i = 0; i < 10; ++i){
        printf("%d", i);
    }
    end = clock();
    printf("%lu\n", CLOCKS_PER_SEC);
    printf("%f\n", ((double)(end - start)) / CLOCKS_PER_SEC);

    return 0;
}
