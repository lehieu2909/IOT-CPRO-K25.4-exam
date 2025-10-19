#include <stdio.h>

/***************************************************************************************************************************************/
 /* Author: Lê Minh Hiếu*  /
 /* Practice Module 1 C */ 
 /**************************************************************************************************************************************/

/*Bai 1 - Bai 14*/
int main(void)
{
    unsigned int x = 0b00001000;   // 8
    int n = 1;
    int a = 5, b = 5;

    /* ---------------- Bài 1: Bật bit thứ n của x ---------------- */
    x |= (1 << n);
    printf("Bai 1 - Bat bit %d: x = %u (0x%X)\n", n, x, x);

    /* ---------------- Bài 2: Tắt bit thứ n của x ---------------- */
    x &= ~(1 << n);
    printf("Bai 2 - Tat bit %d: x = %u (0x%X)\n", n, x, x);

    /* ---------------- Bài 3: Đảo bit thứ n của x ---------------- */
    x ^= (1 << n);
    printf("Bai 3 - Dao bit %d: x = %u (0x%X)\n", n, x, x);

    /* ---------------- Bài 4: Kiểm tra bit thứ n có bật hay không ---------------- */
    printf("Bai 4 - Bit %d cua x %s bat\n", n, (x & (1 << n)) ? "da" : "chua");

    /* ---------------- Bài 5: Hoán đổi 2 số không dùng biến tạm ---------------- */
    int p = 3, q = 7;
    p ^= q ^= p ^= q;
    printf("Bai 5 - Hoan doi: p = %d, q = %d\n", p, q);

    /* ---------------- Bài 6: Kiểm tra n có phải lũy thừa của 2 không ---------------- */
    int val = 16;
    printf("Bai 6 - %d %s la luy thua cua 2\n", val, ((val != 0) && ((val & (val - 1)) == 0)) ? "la" : "khong");

    /* ---------------- Bài 7: Kiểm tra n chẵn hay lẻ ---------------- */
    int num = 11;
    printf("Bai 7 - %d la so %s\n", num, (num & 1) ? "le" : "chan");

    /* ---------------- Bài 8: Lấy bù 2 (two's complement) ---------------- */
    int t = 5;
    int two_comp = ~t + 1;
    printf("Bai 8 - Bu 2 cua %d = %d\n", t, two_comp);

    /* ---------------- Bài 9: Kiểm tra 2 số bằng nhau mà không dùng == ---------------- */
    int u = 12, v = 12;
    printf("Bai 9 - %d va %d %s bang nhau\n", u, v, ((u ^ v) == 0) ? "la" : "khong");

    /* ---------------- Bài 10: Tìm vị trí bit MSB ---------------- */
    unsigned int m = 0b01010000;  // MSB ở vị trí 6
#if defined(__GNUC__)
    int msb_pos = 31 - __builtin_clz(m);
    printf("Bai 10 - Vi tri MSB cua %u = %d\n", m, msb_pos);
#else
    // fallback nếu không có builtin
    int msb_pos = -1;
    for (int i = 31; i >= 0; i--) {
        if (m & (1u << i)) { msb_pos = i; break; }
    }
    printf("Bai 10 - Vi tri MSB cua %u = %d (fallback)\n", m, msb_pos);
#endif

    /* ---------------- Bài 11: Tìm vị trí bit LSB ---------------- */
#if defined(__GNUC__)
    int lsb_pos = __builtin_ctz(m);
    printf("Bai 11 - Vi tri LSB cua %u = %d\n", m, lsb_pos);
#else
    int lsb_pos = -1;
    for (int i = 0; i < 32; i++) {
        if (m & (1u << i)) { lsb_pos = i; break; }
    }
    printf("Bai 11 - Vi tri LSB cua %u = %d (fallback)\n", m, lsb_pos);
#endif

    /* ---------------- Bài 12: Đặt bit 1 ở ngoài cùng bên phải của n ---------------- */
    unsigned int r = 0b10100000;
    r |= (r + 1);
    printf("Bai 12 - Dat bit 1 o ngoai cung ben phai: r = 0x%X\n", r);

    /* ---------------- Bài 13: Xóa bit 1 ở ngoài cùng bên phải của n ---------------- */
    r &= (r - 1);
    printf("Bai 13 - Xoa bit 1 o ngoai cung ben phai: r = 0x%X\n", r);

    /* ---------------- Bài 14: Kiểm tra n có phải bội của 8 ---------------- */
    int check = 64;
    printf("Bai 14 - %d %s la boi cua 8\n", check, ((check & 7) == 0) ? "la" : "khong");

    return 0;
}