# Memory Error Simulator

## 1. What – Dự án là gì?
Đây là chương trình mô phỏng các lỗi thường gặp trong lập trình C:  
- **Stack Overflow**: Tràn ngăn xếp do đệ quy sâu.  
- **Out of Memory**: Hết bộ nhớ khi cấp phát liên tục.  
- **Memory Leak**: Rò rỉ bộ nhớ khi cấp phát mà không giải phóng.

Mục đích là để kiểm thử, học cách nhận biết và xử lý các lỗi này.

---

## 2. Why – Tại sao làm?
Các lỗi về bộ nhớ thường khó phát hiện, đặc biệt trong hệ thống nhúng.  
Chương trình giúp luyện tập cách:  
- Nhận biết hành vi khi chương trình gặp lỗi bộ nhớ.  
- Thử nghiệm công cụ debug / valgrind.  
- Học cách tuân thủ coding convention an toàn.

---

## 3. Who – Ai thực hiện?
- **Tác giả**: Lê Hiếu  
- **Vai trò**: Sinh viên kỹ thuật / Embedded developer

---

## 4. Where – Ứng dụng ở đâu?
- Môi trường: Linux / Windows có hỗ trợ `gcc`.  
- Dùng trong các bài học về quản lý bộ nhớ, debug, hoặc kiểm thử hệ thống.

---

## 5. When – Thời gian?
- **Bắt đầu**: 10/2025  
- **Phiên bản hiện tại**: v1.0  
- **Trạng thái**: Hoàn thiện bản cơ bản

---

## 6. How – Cách sử dụng

### 6.1. Biên dịch
```bash
gcc -Wall -Wextra -o mem_error_simulator main.c
