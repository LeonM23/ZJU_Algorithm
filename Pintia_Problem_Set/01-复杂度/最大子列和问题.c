 #include <stdio.h>

int MaxSubseqSum(int A[], int N){
    int maxSum = 0;
    for (int i = 0; i < N; ++i){
        int tmpSum = 0;
        for (int j = i; j < N; ++j){
            tmpSum += A[j];
            if (tmpSum > maxSum){
                maxSum = tmpSum;
            }
        }
    }
    return maxSum;
}

int MaxSubseqSum2(int A[], int left, int right){
    int maxSum = 0;

    if (left == right){
        if (A[left] > 0){
            return A[left];
        } else {
            return 0;
        }
    }

    int center = (left + right) / 2;
    int leftMaxSum = MaxSubseqSum2(A, left, center), rightMaxSum = MaxSubseqSum2(A, center + 1, right);
    int leftBorderSum = 0, leftBorderMaxSum = 0;
    int rightBorderSum = 0, rightBorderMaxSum = 0;
    for (int i = center; i >= left; --i){
        leftBorderSum += A[i];
        if (leftBorderSum > leftBorderMaxSum){
            leftBorderMaxSum = leftBorderSum;
        }
    }
    for (int i = center + 1; i <= right; ++i){
        rightBorderSum += A[i];
        if (rightBorderSum > rightBorderMaxSum){
            rightBorderMaxSum = rightBorderSum;
        }
    }

    maxSum = leftMaxSum > rightMaxSum ? leftMaxSum : rightMaxSum;
    maxSum = maxSum > (leftBorderMaxSum + rightBorderMaxSum) ? maxSum : (leftBorderMaxSum + rightBorderMaxSum);

    return maxSum;
}


int MaxSubseqSum3(int A[], int N){
    int maxSum = 0;
    int tmpSum = 0;
    for (int i = 0; i < N; ++i){
        tmpSum += A[i];
        if (tmpSum > maxSum){
            maxSum = tmpSum;
        } else if (tmpSum < 0){
            tmpSum = 0;
        }
    }

    return maxSum;
}


int main() {

    int num;
    scanf("%d", &num);
    int array[num];
    for (int i = 0; i < num; ++i) {
        scanf("%d", &array[i]);
    }

    printf("%d\n", MaxSubseqSum3(array, num));
    
    return 0;
}
