Tóm tắt đề:
    - Cho 1 mảng a có n phần tử.
    - Được phép thay đổi 1 phần tử sao cho dãy sau khi đổi có dãy con giống nhau liên tiếp
    dài nhất.

Nhận xét :
    - Nếu đổi 1 thằng a[i] thành 1 số khác thì ta chắc chắn sẽ đổi qua 1 trong 2 thằng kế bên
    - Gọi f[i] là dãy con liên tiếp dài nhất có nhận vị trí i
    - Có 3 trường hợp xảy ra khi thay đổi giá trị a[i]. Mọi giá trị a[i] ghi dưới là đã đổi :
        + a[i] == a[i-1]. Lúc này thì f[i] sẽ là
        (độ dài dãy giống nhau liên tiếp Kết Thúc tại vị trí i-1) cộng với 1.
        + a[i] == a[i+1]. Lúc này thì f[i] sẽ là
        (độ dài dãy giống nhau liên tiếp Bắt Đầu tại vị trí i+1) cộng với 1.
        + a[i] == a[i-1] == a[i+1] thì lúc này f[i] sẽ là
        tổng của 2 trường hợp trên.
    - Từ 3 trường hợp nhận xét trên thì để dễ dàng xử lý thì ta cần Build 2 mảng sau.
        - gleft[i] là dãy con liên tiếp dài nhất có giá trị bằng i kết thúc tại vị trí i.
        - gright[i] là dãy con liên tiếp dài nhất có giá trị bằng i mà bắt đầu tại vị trí i.
        - Để build 2 mảng này thì khá đơn giản và xin để lại cho bạn đọc.
