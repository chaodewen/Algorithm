//
//  main.cpp
//  RadixSort
//
//  Created by Dewen Chao on 15/10/21.
//  Copyright © 2015年 Dewen Chao. All rights reserved.
//

#include <iostream>

#define N 10

using namespace std;

// 返回num从右向左数第digit位的数字，出错返回-1
int getDigit(int num, int digit) {
    // 假设数字均不超过100位，末尾初值为0
    int dgt[100];
    int d = 0;
    while(num != 0) {
        dgt[d++] = num % 10;
        num /= 10;
    }
    if(d == 0) {
        return 0;
    }
    else if(d < digit) {
        return 0;
    }
    else {
        return dgt[digit - 1];
    }
}

// 基数排序最高位优先法（Most Significant Digit first）
// 时间复杂度为O(digit(N+radix))，唯一一个能达到O(N)的常见排序
void radixSortMSD(int arr[], int begin, int end, int digit) {
    // 基数，即桶的个数
    const int radix = 10;
    // 存储每个桶中的元素个数
    int count[radix];
    memset(count, 0, radix * sizeof(int));
    // 为桶分配空间
    int *pBucket = (int *) malloc((end - begin + 1) * sizeof(int));
    
    // 统计每个桶需要装的元素个数，桶按照最高位划分
    for(int i = begin; i <= end; i ++) {
        count[getDigit(arr[i], digit)] ++;
    }
    // 求出桶的边界索引，count[i]值为第i个桶的右边界索引+1
    for(int i = 1; i < radix; i ++) {
        count[i] += count[i - 1];
    }
    // 这里要从右向左扫描，保证排序稳定性，因为以count[]值为索引是从右向左遍历桶
    for(int i = end; i >= begin; i --) {
        // 计算digit位的值
        int d = getDigit(arr[i], digit);
        // 从右起放入桶中
        pBucket[count[d] - 1] = arr[i];
        // 桶d下一个元素的边界
        count[d] --;
    }
    // 此时count[]中存放每个桶的左起第一个值
    // 从桶中收集数据
    for(int i = begin, j = 0; i <= end; i ++, j ++) {
        arr[i] = pBucket[j];
    }
    // 释放桶所占空间
    free(pBucket);
    // 对各桶中数据进行再排序
    for(int i = 0; i < radix; i ++) {
        // 先找出第i个桶的左右边界
        int left = begin + count[i], right;
        if(i == radix - 1) {
            right = end;
        }
        else {
            right = begin + count[i + 1] - 1;
        }
        
        // 对第i个桶递归调用，进行基数排序，数位减小1
        if(left < right && digit > 1) {
            radixSortMSD(arr, left, right, digit - 1);
        }
    }
}

int main(int argc, const char * argv[]) {
    int arr[N];
    
    srand((unsigned int) time(NULL));
    
    for(int i = 0; i < N; i ++) {
        arr[i] = rand() % 100;
        cout << arr[i] << " ";
    }
    cout << endl;
    
    radixSortMSD(arr, 0, N - 1, 2);
    
    for(int i = 0; i < N; i ++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    // Debug
//    for(int i = 0; i < 10000; i ++) {
//        for(int j = 0; j < N; j ++) {
//            arr[j] = rand() % 100;
//        }
//        radixSortMSD(arr, 0, N - 1, 2);
//        for(int j = 0; j < N - 1; j ++) {
//            if(arr[j] > arr[j + 1]) {
//                cout << "Error!" << endl;
//            }
//        }
//    }
    
    return 0;
}
