#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 100


typedef struct MinHeapNode {
    char data;
    unsigned freq;
    struct MinHeapNode *left, *right;
} Node;

typedef struct MinHeap {
    unsigned size;
    unsigned capacity;
    Node** array;
} Heap;


Node* newNode(char data, unsigned freq) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;
    return temp;
}
Heap* createMinHeap(unsigned capacity) {
    Heap* minHeap = (Heap*)malloc(sizeof(Heap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (Node**)malloc(capacity * sizeof(Node*));
    return minHeap;
}

void swapNode(Node** a, Node** b) {
    Node* t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(Heap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
        smallest = right;

    if (smallest != idx) {
        swapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

Node* extractMin(Heap* minHeap) {
    Node* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    minHeap->size--;
    minHeapify(minHeap, 0);
    return temp;
}

void insertMinHeap(Heap* minHeap, Node* node) {
    minHeap->size++;
    int i = minHeap->size - 1;

    while (i && node->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = node;
}

void buildMinHeap(Heap* minHeap) {
    int n = minHeap->size - 1;
    for (int i = (n - 1) / 2; i >= 0; i--)
        minHeapify(minHeap, i);
}

int isLeaf(Node* root) {
    return !(root->left) && !(root->right);
}

void printCodes(Node* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }
    if (isLeaf(root)) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; i++)
            printf("%d", arr[i]);
        printf("\n");
    }
}

Node* buildHuffmanTree(char data[], int freq[], int size) {
    Node *left, *right, *top;
    Heap* minHeap = createMinHeap(size);

    for (int i = 0; i < size; ++i)
        minHeap->array[i] = newNode(data[i], freq[i]);

    minHeap->size = size;
    buildMinHeap(minHeap);

    while (minHeap->size != 1) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);

        top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        insertMinHeap(minHeap, top);
    }
    return extractMin(minHeap);
}

int main() {
    char str[] = "amritavishwavidyapeetham";
    int freq[256] = {0};

    for (int i = 0; i < strlen(str); i++)
        freq[(int)str[i]]++;

    char data[256];
    int frequency[256];
    int size = 0;

    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            data[size] = (char)i;
            frequency[size] = freq[i];
            size++;
        }
    }

    Node* root = buildHuffmanTree(data, frequency, size);

    int arr[MAX_TREE_HT], top = 0;
    printf("Huffman Codes:\n");
    printCodes(root, arr, top);

    return 0;
}
/*
Time Complexity: O(nlogn)
Space Complexity: O(n)
This is a lossless data compression algorithm that assigns codes to input characters based on the 
frequencies of the characters.
The major parts are building the huffman tree and traversing it to assign the code for the character
The algorithm uses a min heap ot build the tree by first creating leaf nodes for each input character
along with their frequency, then afterwards it continously retrieves the two most minimum values 
and creates a new internal node with their summed up frequency.This is repeated until only one node
is left, which is the root node.
*/