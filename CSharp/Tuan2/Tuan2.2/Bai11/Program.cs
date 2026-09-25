using System;
using Bai4;

public class DayPhanSo
{
    //field
    private PhanSo[] danhSach;
    private int n;

    //constructor
    public DayPhanSo()
    {
        n = 0;
        danhSach = new PhanSo[0];
    }

    public DayPhanSo(int n)
    {
        if (n < 0)
            throw new ArgumentException("Số phần tử không được âm.", nameof(n));

        this.n = n;
        danhSach = new PhanSo[n];
        for (int i = 0; i < n; i++)
            danhSach[i] = new PhanSo(0, 1);
    }

    public DayPhanSo(PhanSo[] arr)
    {
        if (arr == null)
            throw new ArgumentNullException(nameof(arr));

        n = arr.Length;
        danhSach = new PhanSo[n];
        for (int i = 0; i < n; i++)
            danhSach[i] = new PhanSo(arr[i]);
    }

    // Copy constructor
    public DayPhanSo(DayPhanSo other)
    {
        if (other == null)
            throw new ArgumentNullException(nameof(other));

        n = other.n;
        danhSach = new PhanSo[n];
        for (int i = 0; i < n; i++)
            danhSach[i] = new PhanSo(other.danhSach[i]);
    }


    public int N { get { return n; } }

    //indexer
    public PhanSo this[int i]
    {
        get
        {
            if (i < 0 || i >= n)
                throw new IndexOutOfRangeException(
                    $"Chỉ số {i} nằm ngoài phạm vi [0, {n - 1}].");
            return danhSach[i];
        }
        set
        {
            if (i < 0 || i >= n)
                throw new IndexOutOfRangeException(
                    $"Chỉ số {i} nằm ngoài phạm vi [0, {n - 1}].");
            if (value == null)
                throw new ArgumentNullException(nameof(value));

            danhSach[i] = new PhanSo(value);
        }
    }

    //nhap xuat
    public void Nhap()
    {
        Console.Write("Nhập số phân số n: ");
        n = int.Parse(Console.ReadLine());

        if (n < 0)
            throw new ArgumentException("Số phần tử không được âm.");

        danhSach = new PhanSo[n];

        for (int i = 0; i < n; i++)
        {
            Console.WriteLine($"\nPhân số thứ {i + 1}:");
            Console.Write("  Tử số: ");
            int tu = int.Parse(Console.ReadLine());
            Console.Write("  Mẫu số: ");
            int mau = int.Parse(Console.ReadLine());

            danhSach[i] = new PhanSo(tu, mau);
        }
    }

    public void Xuat()
    {
        if (n == 0)
        {
            Console.WriteLine("Dãy rỗng.");
            return;
        }

        Console.Write("Dãy phân số: ");
        for (int i = 0; i < n; i++)
        {
            Console.Write(danhSach[i]);
            if (i < n - 1)
                Console.Write(", ");
        }
        Console.WriteLine();
    }

    //tinh tong n
    public PhanSo TinhTong()
    {
        // Phần tử trung hòa của phép cộng phân số là 0/1
        PhanSo tong = new PhanSo(0, 1);

        for (int i = 0; i < n; i++)
            tong = tong + danhSach[i];

        return tong;
    }

    //override 
    public override string ToString()
    {
        if (n == 0)
            return "DayPhanSo[]";

        return "DayPhanSo[" + string.Join(", ", danhSach) + "]";
    }
}
class Program
{
    public static void Main()
    {
        // Tạo dãy phân số từ mảng có sẵn
        PhanSo[] arr = {
            new PhanSo(1, 2),
            new PhanSo(1, 3),
            new PhanSo(1, 6)
        };
        DayPhanSo ds = new DayPhanSo(arr);

        Console.WriteLine("Dãy phân số:");
        ds.Xuat();

        // Tính tổng
        PhanSo tong = ds.TinhTong();
        Console.WriteLine($"Tổng = {tong}");
    
    }
}
