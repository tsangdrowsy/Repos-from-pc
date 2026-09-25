using System;

// Lớp cơ sở Thí sinh 
public abstract class ThiSinh
{
    public string Sbd { get; set; }
    public string HoTen { get; set; }
    public double Bai1 { get; set; }
    public double Bai2 { get; set; }
    public double Bai3 { get; set; }

    public ThiSinh() : this("", "", 0, 0, 0) { }

    public ThiSinh(string sbd, string hoTen, double b1, double b2, double b3)
    {
        Sbd = sbd; HoTen = hoTen;
        Bai1 = b1; Bai2 = b2; Bai3 = b3;
    }

    public ThiSinh(ThiSinh other)
        : this(other.Sbd, other.HoTen, other.Bai1, other.Bai2, other.Bai3) { }

    // Tổng điểm 3 bài lập trình
    public double Tong3Bai => Bai1 + Bai2 + Bai3;

    // abstract guh
    public abstract double TinhTongDiem();

    // Tên loại thí sinh (để in)
    public abstract string LoaiThiSinh { get; }

    public virtual void Nhap() //override-able method thanks to virtual
    {
        Console.Write("  SBD: ");
        Sbd = Console.ReadLine();
        Console.Write("  Họ tên: ");
        HoTen = Console.ReadLine();
        Console.Write("  Điểm bài 1: ");
        Bai1 = double.Parse(Console.ReadLine());
        Console.Write("  Điểm bài 2: ");
        Bai2 = double.Parse(Console.ReadLine());
        Console.Write("  Điểm bài 3: ");
        Bai3 = double.Parse(Console.ReadLine());
    }

    public virtual void Xuat()
    {
        Console.WriteLine(
            $"{Sbd,-8} | {HoTen,-20} | {LoaiThiSinh,-10} | " +
            $"B1={Bai1,4} B2={Bai2,4} B3={Bai3,4} | " +
            $"Tổng = {TinhTongDiem(),6:F2}");
    }
}

// Thí sinh Chuyên 
public class ThiSinhChuyen : ThiSinh
{
    public double TiengAnh { get; set; }

    public ThiSinhChuyen() : this("", "", 0, 0, 0, 0) { }

    public ThiSinhChuyen(string sbd, string ten, double b1, double b2, double b3, double ta)
        : base(sbd, ten, b1, b2, b3)
    {
        TiengAnh = ta;
    }

    public ThiSinhChuyen(ThiSinhChuyen other)
        : this(other.Sbd, other.HoTen, other.Bai1, other.Bai2, other.Bai3, other.TiengAnh) { }

    public override string LoaiThiSinh => "Chuyên";

    // Điểm thưởng 
    public double DiemThuongTiengAnh()
    {
        if (TiengAnh >= 9 && TiengAnh <= 10) return 2;
        if (TiengAnh >= 7 && TiengAnh < 9) return 1;
        return 0;
    }

    public override double TinhTongDiem()
        => Tong3Bai + DiemThuongTiengAnh();

    public override void Nhap()
    {
        base.Nhap();
        Console.Write("  Điểm tiếng Anh: ");
        TiengAnh = double.Parse(Console.ReadLine());
    }

    public override void Xuat()
    {
        Console.Write($"{Sbd,-8} | {HoTen,-20} | {LoaiThiSinh,-10} | ");
        Console.Write($"B1={Bai1,4} B2={Bai2,4} B3={Bai3,4} | TA={TiengAnh,4} | ");
        Console.WriteLine($"Thưởng TA={DiemThuongTiengAnh()} | Tổng = {TinhTongDiem(),6:F2}");
    }
}

// Thí sinh Siêu cúp extended from ThiSinh
public class ThiSinhSieuCup : ThiSinh
{
    public double Csdl { get; set; }

    public ThiSinhSieuCup() : this("", "", 0, 0, 0, 0) { }

    public ThiSinhSieuCup(string sbd, string ten, double b1, double b2, double b3, double csdl)
        : base(sbd, ten, b1, b2, b3)
    {
        Csdl = csdl;
    }

    public ThiSinhSieuCup(ThiSinhSieuCup other)
        : this(other.Sbd, other.HoTen, other.Bai1, other.Bai2, other.Bai3, other.Csdl) { }

    public override string LoaiThiSinh => "Siêu cúp";

    // Tổng điểm = 4 bài thi
    public override double TinhTongDiem()
        => Tong3Bai + Csdl;

    public override void Nhap()
    {
        base.Nhap();
        Console.Write("  Điểm CSDL: ");
        Csdl = double.Parse(Console.ReadLine());
    }

    public override void Xuat()
    {
        Console.Write($"{Sbd,-8} | {HoTen,-20} | {LoaiThiSinh,-10} | ");
        Console.Write($"B1={Bai1,4} B2={Bai2,4} B3={Bai3,4} | CSDL={Csdl,4} | ");
        Console.WriteLine($"Tổng = {TinhTongDiem(),6:F2}");
    }
}


class Program
{
    static void Main()
    {
        Console.Write("Nhập số thí sinh: ");
        int n = int.Parse(Console.ReadLine());

        ThiSinh[] ds = new ThiSinh[n];

        for (int i = 0; i < n; i++)
        {
            Console.WriteLine($"\nThí sinh thứ {i + 1}:");
            Console.WriteLine("  Loại (1 = Chuyên, 2 = Siêu cúp): ");
            int loai = int.Parse(Console.ReadLine());

            if (loai == 1)
                ds[i] = new ThiSinhChuyen();
            else
                ds[i] = new ThiSinhSieuCup();

            ds[i].Nhap();
        }

        Console.WriteLine("\n===== KẾT QUẢ THI =====");
        foreach (ThiSinh ts in ds)
            ts.Xuat();

        // Thống kê
        int soChuyen = 0, soSieuCup = 0;
        double tongChuyen = 0, tongSieuCup = 0;

        foreach (ThiSinh ts in ds)
        {
            if (ts is ThiSinhChuyen)
            {
                soChuyen++;
                tongChuyen += ts.TinhTongDiem();
            }
            else if (ts is ThiSinhSieuCup)
            {
                soSieuCup++;
                tongSieuCup += ts.TinhTongDiem();
            }
        }

        Console.WriteLine($"\nSố thí sinh Chuyên:   {soChuyen}, tổng điểm: {tongChuyen:F2}");
        Console.WriteLine($"Số thí sinh Siêu cúp: {soSieuCup}, tổng điểm: {tongSieuCup:F2}");
    }
}