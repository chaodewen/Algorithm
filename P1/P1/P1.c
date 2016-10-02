//
//  P1.c
//  P1
//
//  Created by Dewen Chao on 16/3/18.
//  Copyright © 2016年 Dewen Chao. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int t, n;

typedef struct Node {
    int index;
    char name[11];
    int m;
    int *ref;
    int next;
}NodeType;

int bigger(char a[], char b[]) {
    int i = 0;
    while(a[i] == b[i]) {
        i ++;
    }
    if(a[i] < b[i]) {
        return 1;
    }
    else {
        return 0;
    }
}

void addNode(int order[], int num, int i, NodeType rec[]) {
    printf("addNode : %d\n", i);
    for(int j = 0; j < rec[i].m; j ++) {
        int isInOrder = 0;
        for(int k = 0; k < num; k ++) {
            if(order[k] == (rec[i].ref)[j]) {
                isInOrder = 1;
                break;
            }
        }
        if(isInOrder == 0) {
            addNode(order, num, (rec[i].ref)[j], rec);
        }
    }
    for(int j = 0; j < num; j ++) {
        if(bigger(rec[order[j]].name, rec[i].name)) {
            int temp = i;
            int temp2;
            int k = j;
            while(k <= num) {
                temp2 = order[j];
                order[j] = temp;
                temp = temp2;
                k ++;
            }
            break;
        }
    }
}

void solve(NodeType rec[]) {
    int order[1000];
    int num;
    for(int i = 0; i < n; i ++) {
        addNode(order, num, i, rec);
    }
    for(int i = 0; i < num; i ++) {
        printf("%s\n", rec[order[i]].name);
    }
}

int main() {
    while (~scanf("%d", &t)) {
        scanf("%d", &n);
        if(n > 0) {
            NodeType rec[n];
            for(int i = 0; i < n; i ++) {
                rec[i].m = 0;
                rec[i].index = i;
                scanf("%s %d", rec[i].name, &(rec[i].m));
                if(rec[i].m > 0) {
                    rec[i].ref = (int*) malloc(sizeof(int) * rec[i].m);
                    for(int j = 0; j < rec[i].m; j ++) {
                        scanf("%d", (rec[i].ref + j));
                    }
                }
            }
            solve(rec);
        }
    }
}