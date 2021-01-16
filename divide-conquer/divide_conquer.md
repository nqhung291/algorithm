# Divide and Conquer

## 1. Mô hình chia để trị

```python
# MERGE SORT PSEUDOCODE
def solve(int n):
	if n == 0: 
		return
	solve(n/2)
	solve(n/2)
	for i in range(n):
		// MERGE
```

## 2. Mô hình giảm để trị (Decrease and Conquer)

- Tìm kiếm nhị phân trên các số nguyên

```python
def p(i):
	return arr[i] >= x	

lo = 0, hi = n-1
while lo < hi:
	m = (lo + hi) / 2
	if p(m):
		hi = m
	else:
		lo = m + 1
if lo == hi and p(lo) is True:
	print('ket qua')
else:
	print('Khong ton tai phan tu thoa man')
```

- Tìm kiếm nhị phân trên các số thực

    Trên các số thực, khoảng [lo, hi] bị chia vô hạn lần mà không dừng ở 1 số thực nào cụ thể

    Thay vào đó có thể tìm được 1 số thực j' rất sát với lời giải đúng j, j' sai số khoảng EPS = $2^{-30}$

```python
double EPS = 1e-10
lo = -1000.0
hi = 1000.0
while hi - lo > EPS:
	double mid = (lo + hi) / 2.0
	if p(mid):
		hi = mid
	else:
		lo = mid
```

- Hàm p có thể thay đổi tùy thuộc vào bài toán
    - Tìm căn bậc 2 của x

        ```python
        def p(j: int):
        	return j * j >= x
        ```

    - Tìm nghiệm của hàm f(x)

        ```python
        def p(x: double):
        	return f(x) >= 0.0
        ```

- Tìm kiếm nhị phân câu trả lời

    Tính chất tìm kiếm nhị phân: Nếu i là 1 lời giải thì tất cả j > i cũng là lời giải

    p(i) kiểm tra nếu i là 1 lời giải thì có thể áp dụng 1 cách đơn giản tìm kiếm nhị phân trên p để nhận được lời giải nhỏ nhất hoặc lớn nhất

- Nhị phân hàm mũ

```python
def pow(x, n):
	if n == 0:
		return 1
	if n % 2 != 0:
		return x * pow(x, n-1)
	else:
		st = pow(x, n / 2)
		return st * st
```

- Mô hình giải các bài tập chia để trị theo tìm kiếm nhị phân:

    ```python
    def p(i):
    	return arr[i] >= x	

    lo = 0, hi = n-1, ans
    while lo <= hi:
    	m = (lo + hi) / 2
    	if p(m):
    		ans = m
    		hi = m - 1
    	else:
    		lo = m + 1
    return ans
    ```