using System;

public class DaySo
{
    // Field: mảng 1 chiều các số nguyên
    private int[] mang;

    // Số phần tử thực tế của dãy
    private int n;


    // Default constructor: dãy rỗng
    public DaySo()
    {
        n = 0;
        mang = new int[0];
    }

    // Constructor tạo dãy có n phần tử (mặc định giá trị 0)
    public DaySo(int n)
    {
        if (n < 0)
            throw new ArgumentException("Số phần tử không được âm.", nameof(n));

        this.n = n;
        mang = new int[n];
    }

    // Constructor từ mảng int[] có sẵn
    public DaySo(int[] arr)
    {
        if (arr == null)
            throw new ArgumentNullException(nameof(arr));

        n = arr.Length;
        mang = new int[n];
        Array.Copy(arr, mang, n);
    }
    //copy constructor
    public DaySo(DaySo other)
    {
        if (other == null)
            throw new ArgumentNullException(nameof(other));

        n = other.n;
        mang = new int[n];
        Array.Copy(other.mang, mang, n);
    }


    public int N
    {
        get { return n; }
    }

    //indexer
    public int this[int i]
    {
        get
        {
            if (i < 0 || i >= n)
                throw new IndexOutOfRangeException(
                    $"Chỉ số {i} nằm ngoài phạm vi [0, {n - 1}].");
            return mang[i];
        }
        set
        {
            if (i < 0 || i >= n)
                throw new IndexOutOfRangeException(
                    $"Chỉ số {i} nằm ngoài phạm vi [0, {n - 1}].");
            mang[i] = value;
        }
    }

    //nhap xuat 
    public void Nhap()
    {
        Console.Write("Nhập số phần tử n: ");
        n = int.Parse(Console.ReadLine());

        if (n < 0)
            throw new ArgumentException("Số phần tử không được âm.");

        mang = new int[n];

        for (int i = 0; i < n; i++)
        {
            Console.Write($"Nhập phần tử thứ {i}: ");
            mang[i] = int.Parse(Console.ReadLine());
        }
    }

    public void Xuat()
    {
        if (n == 0)
        {
            Console.WriteLine("Dãy rỗng.");
            return;
        }

        Console.Write("Dãy số: ");
        for (int i = 0; i < n; i++)
        {
            Console.Write(mang[i]);
            if (i < n - 1)
                Console.Write(", ");
        }
        Console.WriteLine();
    }

    // Trả về một DaySo mới chỉ gồm các số chẵn
    public DaySo TimSoChan()
    {
        // Đếm số chẵn trước
        int dem = 0;
        for (int i = 0; i < n; i++)
        {
            if (mang[i] % 2 == 0)
                dem++;
        }

        // Tạo mảng kết quả
        int[] ketQua = new int[dem];
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            if (mang[i] % 2 == 0)
                ketQua[j++] = mang[i];
        }

        return new DaySo(ketQua);
    }

    //override
    public override string ToString()
    {
        if (n == 0)
            return "DaySo[]";

        return "DaySo[" + string.Join(", ", mang) + "]";
    }
}