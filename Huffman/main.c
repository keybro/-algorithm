#include <stdio.h>

int main() {
    printf("Hello, World!\n");
    return 0#include <stdio.h>
             #include <stdlib.h>
             #include <string.h>
    typedef struct {
        int weight;
        int lchild, rchild, parent;
        typedef char** HuffmanCode;
        HuffmanCode HC;
        HuffmanTree HT;
        int s1, s2;
        void SelectMin(HuffmanTree tree, int n) {
            if (tree[i].parent == 0) {
                break;
            }
        }
        for (int i = 1; i <= n; i++) {
            if (tree[i].parent == 0 && tree[i].weight < tree[min].weight) {
            }
        }
        s1 = min;
        for (int i = 1; i <= n; i++) {
            if (tree[i].parent == 0 && i != s1) {
                break;
            }
        }
        for (int i = 1; i <= n; i++) {
            if (tree[i].parent == 0 && tree[i].weight < tree[min].weight && i != s1) {         min = i;
            }
        }
        s2 = min;
    }
    void Huffman(HuffmanTree tree, int* w, int n) {
        tree = (HuffmanTree)malloc((m + 1) * sizeof(HTNode));
        for (int i = 1; i <= m; i++) {
            tree[i].lchild = 0;
            tree[i].rchild = 0;
            tree[i].parent = 0;
            if (i <= n) {
            }
            else {
                tree[i].weight = 0;
            }
        }
        for (int i = n + 1; i <= m; i++) {
            SelectMin(tree, i - 1);
            tree[s1].parent = tree[s2].parent =i;
            tree[i].lchild = s1,tree[i].rchild = s2;
            tree[i].weight = tree[s1].weight + tree[s2].weight;
        }
        HC = (HuffmanCode)malloc((n + 1) * (sizeof(char*)));
        char* cd;
        cd = (char*)malloc(n * sizeof(char));
        for (int i = 1; i <= n; i++) {
            start = n - 1;
            if (tree[f].lchild == j) cd[--start] = '0';
            else cd[--start] = '1';
        }
        HC[i] = (char*)malloc((n - start) * sizeof(char));
        strcpy(HC[i], &cd[start]);
        free(cd);
    }
    int main() {
        int n = 8;
        int w[100] = { 0,8,6,4,1,2,3,3,1 };
        for (int i = 1; i <= n; i++) {
            printf("%d:%s\n", w[i],HC[i]);
        }
    }

}
