def extended_gcd_iterative(a, b):
    # Khởi tạo
    x0, y0, r0 = 1, 0, a
    x1, y1, r1 = 0, 1, b

    # Lặp lại cho đến khi r1 bằng 0
    while r1 != 0:
        q = r0 // r1  # Tính q_k-1
        # Cập nhật các giá trị của x, y, r cho bước tiếp theo
        x0, x1 = x1, x0 - q * x1
        y0, y1 = y1, y0 - q * y1
        r0, r1 = r1, r0 - q * r1

    # Kết quả cuối cùng là r0, x0, y0
    return r0, x0, y0


def find_min_x(a, b):
    gcd, x, y = extended_gcd_iterative(a, b)
    if x <= 0:
        k = (-x // (b // gcd)) + 1
        x += k * (b // gcd)
        y -= k * (a // gcd)
    return x


a = 252
b = 198
result = find_min_x(a, b)
print("a) x =", result)

# b) a = 16261, b = 85652
a = 16261
b = 85652
result = find_min_x(a, b)
print("b) x =", result)

# c) a = 139024789, b = 93278890
a = 139024789
b = 93278890
result = find_min_x(a, b)
print("c) x =", result)

a = 6
b = 3
result = find_min_x(a, b)
print("a) x =", result)
