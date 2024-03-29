 #include <stdio.h>


int* MaxSubseqSum(int A[], int N, int output[3]){
    int maxSum = -1;
    int tmpSum = 0;
    int left = 0, right = 0;

    for (int i = 0; i < N; ++i){
        tmpSum += A[i];
        if (tmpSum > maxSum){
            maxSum = tmpSum;
            output[1] = left;
            output[2] = i;
        } else if (tmpSum < 0){
            tmpSum = 0;
            left = i + 1;
        }
    }
    while (maxSum > 0 && A[output[1]] == 0){
        output[1]++;
    }

    if (maxSum < 0){
        maxSum = 0;
        output[1] = 0;
        output[2] = N - 1;
    }
    output[0] = maxSum;
    output[1] = A[output[1]];
    output[2] = A[output[2]];

    return output;
}


int main() {

    int num;
    scanf("%d", &num);
    int array[num];
    for (int i = 0; i < num; ++i) {
        scanf("%d", &array[i]);
    }

    int output[3] = {0, 0, 0};
    MaxSubseqSum(array, num, output);
    printf("%d %d %d", output[0], output[1], output[2]);
    
    return 0;
}
