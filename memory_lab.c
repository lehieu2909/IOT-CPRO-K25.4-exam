#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Stack overflow
void stack_overflow(int count) {
    printf("Stack overflow: %d\n", count);
    stack_overflow(count + 1); // đệ quy vô hạn gây tràn stack
}

// Out of memory (OOM)
void out_of_memory() {
    while (1) {
        int *MEM = (int*) malloc(sizeof(int) * 10000000);
        if (MEM == NULL) {
            printf("Out of memory!\n");
            exit(1);
        }
    }
}

// Memory leak
void memory_leak() {
    int *MEM = (int*) malloc(sizeof(int) * 1000);
    printf("Allocated memory but did not free it -> leak!\n");
    // cố tình không gọi free(MEM);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage:\n");
        printf("  %s stack_overflow   # gây lỗi tràn ngăn xếp\n", argv[0]);
        printf("  %s out_of_memory    # gây lỗi hết bộ nhớ\n", argv[0]);
        printf("  %s memory_leak      # gây lỗi rò rỉ bộ nhớ\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "stack_overflow") == 0) {
        stack_overflow(1);
    } else if (strcmp(argv[1], "out_of_memory") == 0) {
        out_of_memory();
    } else if (strcmp(argv[1], "memory_leak") == 0) {
        memory_leak();
    } else {
        printf("Unknown option: %s\n", argv[1]);
    }

    return 0;
}
