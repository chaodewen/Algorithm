//
//  main.cpp
//  HeapSort
//
//  Created by Dewen Chao on 15/10/19.
//  Copyright © 2015年 Dewen Chao. All rights reserved.
//

#include <iostream>

#define N 10

using namespace std;

// 已知除heap[start]外满足大顶堆定义，函数调整heap[start~end]为大顶堆
void heapAdjust(int heap[], int start, int end) {
    // 从start~end中最后一个非叶子节点向start遍历
    int i = 2 * start + 1;
    // end为最后一个序号，可以遍历到
    while(i <= end) {
        // 存储左右节点中较大值对应的序号
        int bigIndex = i;
        // bigIndex < end避免了没有右子节点时越界
        if(bigIndex < end && heap[bigIndex] < heap[bigIndex + 1]) {
            bigIndex ++;
        }
        // 大的子节点与根节点比较，若子节点大则换位
        // 若根节点大说明这部分已经是大顶堆，不需要其它操作跳出循环
        if(heap[bigIndex] > heap[start]) {
            int temp = heap[start];
            heap[start] = heap[bigIndex];
            heap[bigIndex] = temp;
            // 换位操作完成后根结点变为被换子节点的位置
            start = bigIndex;
            // i为新根节点的左子节点
            i = 2 * bigIndex + 1;
        }
        else {
            break;
        }
    }
}

// 堆排序是一种树形选择排序，是对直接选择排序的有效改进
// 它要解决两个问题：
// 1.如何由一个无序序列建成一个堆？
// 2.如何在输出堆顶元素之后，调整剩余元素成为一个新的堆？
// 堆排序每次输出堆顶，然后将剩下的部分重新调整为大顶堆，循环操作即可得到排序后的数组
// 最后一个非叶子节点是第⌊N/2⌋个节点，序号为(N-1)/2
void heapSort(int heap[], int len) {
    // 建立大顶堆，方法是从最后一个非叶子节点起到根节点进行筛选（heapAdjust）
    for(int i = (len - 1) / 2; i >= 0; i --) {
        heapAdjust(heap, i, len - 1);
    }
    // 进行排序
    for(int i = len - 1; i > 0; i --) {
        // 最后一个元素和第一元素进行交换
        // 输出根节点（当前堆最大值）后用最后一个节点替代根节点，要处理的区间长度减一
        int temp = heap[0];
        heap[0] = heap[i];
        heap[i] = temp;
        // 然后将剩下的无序元素继续筛选（heapAdjust）为大顶堆
        heapAdjust(heap, 0, i - 1);
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
    
    heapSort(arr, N);
    
    for(int i = 0; i < N; i ++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    // 正确性验证
//    for(int i = 0; i < 10000; i ++) {
//        int record[N];
//        for(int j = 0; j < N; j ++) {
//            arr[j] = rand() % 100;
//            record[j] = arr[j];
//        }
//        heapSort(arr, N);
//        for(int j = 0; j < N - 1; j ++) {
//            if(arr[j] > arr[j + 1]) {
//                cout << "Error:" << endl;
//                // Debug
//                for(int j = 0; j < N; j ++) {
//                    cout << record[j] << " ";
//                }
//                cout << endl;
//                for(int j = 0; j < N; j ++) {
//                    cout << arr[j] << " ";
//                }
//                cout << endl;
//                break;
//            }
//        }
//    }
    
    return 0;
}
