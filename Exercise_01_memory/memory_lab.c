/*******************************************************************************
 * Includes
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/*******************************************************************************
 * Definitions
 ******************************************************************************/

#define MEM_BLOCK_SIZE         (10000000U)   /* Kích thước mỗi khối cấp phát trong hàm out_of_memory(). */
#define MEM_LEAK_BLOCK_SIZE    (1000U)       /* Kích thước khối bị rò trong hàm memory_leak(). */

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

static void StackOverflow(uint32_t count);
static void OutOfMemory(void);
static void MemoryLeak(void);

/*******************************************************************************
 * Variables
 ******************************************************************************/

/* Không dùng biến toàn cục ở đây */

/*******************************************************************************
 * Code
 ******************************************************************************/

/**
 * @brief Hàm đệ quy gây tràn stack (có giới hạn để tránh đệ quy vô tận).
 */
static void StackOverflow(uint32_t count)
{
    /* assert để tránh lỗi tham số */
    assert(count > 0U);

    printf("Stack depth: %lu\n", (unsigned long)count);

    if (count < 100000U)  /* Giới hạn để tránh crash không kiểm soát */
    {
        StackOverflow(count + 1U);
    }
    else
    {
        printf("Reached maximum depth.\n");
    }
}

/**
 * @brief Hàm gây lỗi hết bộ nhớ (liên tục cấp phát cho đến khi malloc trả về NULL).
 */
static void OutOfMemory(void)
{
    int *pMem = NULL;

    while (1)
    {
        pMem = (int *)malloc(sizeof(int) * MEM_BLOCK_SIZE);
        if (pMem == NULL)
        {
            printf("Out of memory!\n");
            break; /* Không dùng exit(1) giữa chừng để tuân theo quy tắc return cuối hàm */
        }
    }
}

/**
 * @brief Hàm minh hoạ rò rỉ bộ nhớ (cấp phát mà không giải phóng).
 */
static void MemoryLeak(void)
{
    int *pMem = NULL;

    pMem = (int *)malloc(sizeof(int) * MEM_LEAK_BLOCK_SIZE);
    if (pMem != NULL)
    {
        printf("Allocated memory but did not free it -> leak!\n");
        /* intentionally not freeing pMem */
    }
    else
    {
        printf("Memory allocation failed!\n");
    }
}

/**
 * @brief Hàm main.
 */
int main(int argc, char *argv[])
{
    int retVal = 0;

    if (argc != 2)
    {
        printf("Usage:\n");
        printf("  %s stack_overflow   # Gây lỗi tràn ngăn xếp\n", argv[0]);
        printf("  %s out_of_memory    # Gây lỗi hết bộ nhớ\n", argv[0]);
        printf("  %s memory_leak      # Gây lỗi rò rỉ bộ nhớ\n", argv[0]);
        retVal = 1;
    }
    else
    {
        if (strcmp(argv[1], "stack_overflow") == 0)
        {
            StackOverflow(1U);
        }
        else if (strcmp(argv[1], "out_of_memory") == 0)
        {
            OutOfMemory();
        }
        else if (strcmp(argv[1], "memory_leak") == 0)
        {
            MemoryLeak();
        }
        else
        {
            printf("Unknown option: %s\n", argv[1]);
            retVal = 1;
        }
    }

    return retVal;
}
