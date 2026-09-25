using System;
using System.Text.Unicode;
using Bai5;


public class DaThuc
{
    
    public DonThuc[] donThucs;
    public int n;


    // Default constructor
    public DaThuc()
    {
        n = 0;
        donThucs = new DonThuc[] { new DonThuc(0, 0) };
    }

    // Constructor tạo đa thức bậc n với tất cả hệ số = 0
    public DaThuc(int n)
    {
        if (n < 0)
            throw new ArgumentException("Bậc đa thức không được âm.", nameof(n));

        this.n = n;
        donThucs = new DonThuc[n + 1];
        for (int i = 0; i <= n; i++)
            donThucs[i] = new DonThuc(0, i);
    }

    // Constructor từ mảng hệ số
    public DaThuc(double[] heSo)
    {
        if (heSo == null || heSo.Length == 0)
            throw new ArgumentException("Mảng hệ số không được rỗng.", nameof(heSo));

        n = heSo.Length - 1;
        donThucs = new DonThuc[n + 1];
        for (int i = 0; i <= n; i++)
            donThucs[i] = new DonThuc(heSo[i], i);
    }

    // Constructor từ mảng các DonThuc 
    public DaThuc(DonThuc[] ds)
    {
        if (ds == null || ds.Length == 0)
            throw new ArgumentException("Mảng đơn thức không được rỗng.", nameof(ds));

        // Tìm bậc cao nhất
        int maxBac = 0;
        foreach (DonThuc d in ds)
            if (d.SoMu > maxBac)
                maxBac = d.SoMu;

        n = maxBac;
        donThucs = new DonThuc[n + 1];
        for (int i = 0; i <= n; i++)
            donThucs[i] = new DonThuc(0, i);

        foreach (DonThuc d in ds)
            donThucs[d.SoMu] = new DonThuc(d);
    }

    // Copy constructor: sao chép 
    public DaThuc(DaThuc other)
    {
        if (other == null)
            throw new ArgumentNullException(nameof(other));

        n = other.n;
        donThucs = new DonThuc[n + 1];
        for (int i = 0; i <= n; i++)
            donThucs[i] = new DonThuc(other.donThucs[i]);
    }


    public int Bac { get { return n; } }
    public int SoDonThuc { get { return n + 1; } }

    //indexer


    public DonThuc this[int i]
    {
        get
        {
            if (i < 0 || i > n)
                throw new IndexOutOfRangeException(
                    $"Chỉ số {i} nằm ngoài phạm vi [0, {n}].");
            return donThucs[i];
        }
        set
        {
            if (i < 0 || i > n)
                throw new IndexOutOfRangeException(
                    $"Chỉ số {i} nằm ngoài phạm vi [0, {n}].");

            if (value == null)
                throw new ArgumentNullException(nameof(value));

            // Đảm bảo bậc của đơn thức khớp với vị trí
            donThucs[i] = new DonThuc(value.HeSo, i);
        }
    }

    //NhapXuat

    public void Nhap()
    {
        Console.Write("Nhập bậc n của đa thức: ");
        n = int.Parse(Console.ReadLine());

        if (n < 0)
            throw new ArgumentException("Bậc không được âm.");

        donThucs = new DonThuc[n + 1];
        Console.WriteLine("Nhập hệ số cho từng đơn thức (a_i của x^i):");
        for (int i = 0; i <= n; i++)
        {
            Console.Write($"  a[{i}] = ");
            double a = double.Parse(Console.ReadLine());
            donThucs[i] = new DonThuc(a, i);
        }
    }

    public void Xuat()
    {

        bool daIn = false;
        for (int i = n; i >= 0; i--)
        {
            double a = donThucs[i].HeSo;
            if (a == 0) continue;

            if (daIn)
                Console.Write(a > 0 ? " + " : " - ");
            else if (a < 0)
                Console.Write("-");

            double absA = Math.Abs(a);
            if (i == 0)
                Console.Write(absA);
            else if (i == 1)
                Console.Write($"{absA}x");
            else
                Console.Write($"{absA}x^{i}");

            daIn = true;
        }

        if (!daIn)
            Console.Write("0");

        Console.WriteLine();
    }

    // tính đa thức

    public double TinhGiaTri(double x)
    {
        double tong = 0;
        for (int i = 0; i <= n; i++)
            tong += donThucs[i].TinhGiaTri(x);
        return tong;
    }
    // override

    public override string ToString()
    {
        string s = "P(x) = ";
        bool daIn = false;

        for (int i = n; i >= 0; i--)
        {
            double a = donThucs[i].HeSo;
            if (a == 0) continue;

            if (daIn)
                s += a > 0 ? " + " : " - ";
            else if (a < 0)
                s += "-";

            double absA = Math.Abs(a);
            if (i == 0) s += absA;
            else if (i == 1) s += $"{absA}x";
            else s += $"{absA}x^{i}";

            daIn = true;
        }

        if (!daIn) s += "0";
        return s;
    }
    class Program
{
    static void Main()
    {
        // Tạo đa thức từ mảng hệ số: P(x) = 3 - 2x + 0x^2 + 5x^3
        double[] heSo = { 3, -2, 0, 5 };
        DaThuc p = new DaThuc(heSo);


        Console.Write("Nhập x để tính giá trị: ");
        double x2 = double.Parse(Console.ReadLine());
        Console.WriteLine($"P({x2}) = {p.TinhGiaTri(x2)}");
    }
}
}