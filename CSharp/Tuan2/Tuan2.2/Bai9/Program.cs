using System;

public class Mang2Chieu
{
    private int[,] mang;

    private int soDong;    
    private int soCot;     


    // Default constructor: mảng rỗng 0x0
    public Mang2Chieu()
    {
        soDong = 0;
        soCot = 0;
        mang = new int[0, 0];
    }

    // Constructor tạo mảng n x m, mặc định giá trị 0
    public Mang2Chieu(int n, int m)
    {
        if (n < 0 || m < 0)
            throw new ArgumentException("Số dòng và số cột không được âm.");

        soDong = n;
        soCot = m;
        mang = new int[n, m];
    }

    // Constructor từ mảng 2 chiều có sẵn
    public Mang2Chieu(int[,] arr)
    {
        if (arr == null)
            throw new ArgumentNullException(nameof(arr));

        soDong = arr.GetLength(0);
        soCot = arr.GetLength(1);
        mang = new int[soDong, soCot];

        for (int i = 0; i < soDong; i++)
            for (int j = 0; j < soCot; j++)
                mang[i, j] = arr[i, j];
    }

    // Copy constructor
    public Mang2Chieu(Mang2Chieu other)
    {
        if (other == null)
            throw new ArgumentNullException(nameof(other));

        soDong = other.soDong;
        soCot = other.soCot;
        mang = new int[soDong, soCot];

        for (int i = 0; i < soDong; i++)
            for (int j = 0; j < soCot; j++)
                mang[i, j] = other.mang[i, j];
    }


    public int SoDong { get { return soDong; } }
    public int SoCot { get { return soCot; } }

    //Index
    public int this[int i, int j]
    {
        get
        {
            if (i < 0 || i >= soDong || j < 0 || j >= soCot)
                throw new IndexOutOfRangeException(
                    $"Chỉ số ({i}, {j}) nằm ngoài phạm vi [{soDong} x {soCot}].");
            return mang[i, j];
        }
        set
        {
            if (i < 0 || i >= soDong || j < 0 || j >= soCot)
                throw new IndexOutOfRangeException(
                    $"Chỉ số ({i}, {j}) nằm ngoài phạm vi [{soDong} x {soCot}].");
            mang[i, j] = value;
        }
    }

    //Nhap/Xuat
    public void Nhap()
    {
        Console.Write("Nhập số dòng n: ");
        soDong = int.Parse(Console.ReadLine());

        Console.Write("Nhập số cột m: ");
        soCot = int.Parse(Console.ReadLine());

        if (soDong < 0 || soCot < 0)
            throw new ArgumentException("Số dòng và số cột không được âm.");

        mang = new int[soDong, soCot];

        for (int i = 0; i < soDong; i++)
        {
            for (int j = 0; j < soCot; j++)
            {
                Console.Write($"Nhập phần tử [{i},{j}]: ");
                mang[i, j] = int.Parse(Console.ReadLine());
            }
        }
    }

    public void Xuat()
    {
        if (soDong == 0 || soCot == 0)
        {
            Console.WriteLine("Mảng rỗng.");
            return;
        }

        Console.WriteLine($"Mảng {soDong} x {soCot}:");
        for (int i = 0; i < soDong; i++)
        {
            for (int j = 0; j < soCot; j++)
            {
                Console.Write(mang[i, j].ToString().PadLeft(6));
            }
            Console.WriteLine();
        }
    }

    //tim SNT
    private static bool LaSoNguyenTo(int x)
    {
        if (x < 2) return false;
        if (x == 2) return true;
        if (x % 2 == 0) return false;

        for (int k = 3; k * k <= x; k += 2)
            if (x % k == 0)
                return false;

        return true;
    }

    // Trả về một Mang2Chieu mới cùng kích thước,
    // phần tử không phải số nguyên tố thì để 0.
    // Đồng thời in ra danh sách các số nguyên tố tìm được.
    public Mang2Chieu TimSoNguyenTo()
    {
        Mang2Chieu ketQua = new Mang2Chieu(soDong, soCot);
        bool coNguyenTo = false;

        for (int i = 0; i < soDong; i++)
        {
            for (int j = 0; j < soCot; j++)
            {
                if (LaSoNguyenTo(mang[i, j]))
                {
                    ketQua[i, j] = mang[i, j];
                    coNguyenTo = true;
                }
            }
        }

        if (!coNguyenTo)
            Console.WriteLine("Không có số nguyên tố trong mảng.");

        return ketQua;
    }

    // Phiên bản khác: trả về mảng 1 chiều chứa các số nguyên tố
    public int[] LayDanhSachSoNguyenTo()
    {
        // Đếm trước
        int dem = 0;
        for (int i = 0; i < soDong; i++)
            for (int j = 0; j < soCot; j++)
                if (LaSoNguyenTo(mang[i, j]))
                    dem++;

        int[] ketQua = new int[dem];
        int k = 0;
        for (int i = 0; i < soDong; i++)
            for (int j = 0; j < soCot; j++)
                if (LaSoNguyenTo(mang[i, j]))
                    ketQua[k++] = mang[i, j];

        return ketQua;
    }

    // ============ Override ToString ============

    public override string ToString()
    {
        if (soDong == 0 || soCot == 0)
            return "Mang2Chieu[ rỗng ]";

        string s = "Mang2Chieu[\n";
        for (int i = 0; i < soDong; i++)
        {
            s += "  [ ";
            for (int j = 0; j < soCot; j++)
            {
                s += mang[i, j];
                if (j < soCot - 1) s += ", ";
            }
            s += " ]\n";
        }
        s += "]";
        return s;
    }
}