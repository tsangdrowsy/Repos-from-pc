using System;
using System.Text.Unicode;


// Lớp cơ sở NhanVien aka the founding father
public abstract class NhanVien
{
    public string MaNV { get; set; }
    public string HoTen { get; set; }

    public NhanVien() : this("", "") { }

    public NhanVien(string maNV, string hoTen)
    {
        MaNV = maNV;
        HoTen = hoTen;
    }

    public NhanVien(NhanVien other) : this(other.MaNV, other.HoTen) { }

    // abstraction method 
    public abstract double TinhLuong();

    public virtual void Nhap()//override-able method thanks to virtual
    {
        Console.Write("  Mã NV: ");
        MaNV = Console.ReadLine();
        Console.Write("  Họ tên: ");
        HoTen = Console.ReadLine();
    }

    public virtual void Xuat()
    {
        Console.Write($"{MaNV,-8} | {HoTen,-20} | Lương: {TinhLuong(),12:N0} VNĐ");
    }

    public override string ToString()
        => $"{MaNV} - {HoTen} - Lương: {TinhLuong():N0}";
}

// Nhân viên kinh doanh extended
public class NhanVienKinhDoanh : NhanVien
{
    public const double ThuongMoiHopDong = 500000;
    public double LuongCoBan { get; set; }
    public int SoHopDong { get; set; }

    public NhanVienKinhDoanh() : this("", "", 0, 0) { }

    public NhanVienKinhDoanh(string ma, string ten, double luongCB, int soHD)
        : base(ma, ten)
    {
        LuongCoBan = luongCB;
        SoHopDong = soHD;
    }

    public NhanVienKinhDoanh(NhanVienKinhDoanh other)
        : this(other.MaNV, other.HoTen, other.LuongCoBan, other.SoHopDong) { }

    public override double TinhLuong()
        => LuongCoBan + SoHopDong * ThuongMoiHopDong;

    public override void Nhap()
    {
        base.Nhap();
        Console.Write("  Lương cơ bản: ");
        LuongCoBan = double.Parse(Console.ReadLine());
        Console.Write("  Số hợp đồng đã ký: ");
        SoHopDong = int.Parse(Console.ReadLine());
    }

    public override void Xuat()
    {
        base.Xuat();
        Console.WriteLine($" | [KD] {SoHopDong} HĐ");
    }
}

// Nhân viên sản xuất extended from NhanVien
public class NhanVienSanXuat : NhanVien
{
    public const double DonGiaSanPham = 1000;
    public const int NguongThuong = 3000;
    public const double TyLeThuong = 0.05;

    public int SoSanPham { get; set; }

    public NhanVienSanXuat() : this("", "", 0) { }

    public NhanVienSanXuat(string ma, string ten, int soSP) : base(ma, ten)
    {
        SoSanPham = soSP;
    }

    public NhanVienSanXuat(NhanVienSanXuat other)
        : this(other.MaNV, other.HoTen, other.SoSanPham) { }

    public override double TinhLuong()
    {
        double luong = SoSanPham * DonGiaSanPham;
        if (SoSanPham > NguongThuong)
            luong *= (1 + TyLeThuong);   // +5%
        return luong;
    }

    public override void Nhap()
    {
        base.Nhap();
        Console.Write("  Số sản phẩm: ");
        SoSanPham = int.Parse(Console.ReadLine());
    }

    public override void Xuat()
    {
        base.Xuat();
        Console.WriteLine($" | [SX] {SoSanPham} SP");
    }
}


class Program
{
    static void Main()
    {
        // Danh sách đa hình
        NhanVien[] ds =
        {
            new NhanVienKinhDoanh("KD01", "Nguyễn Văn A", 5_000_000, 10),
            new NhanVienSanXuat  ("SX01", "Trần Thị B",   3500),
            new NhanVienKinhDoanh("KD02", "Lê Văn C",     6_000_000, 3),
            new NhanVienSanXuat  ("SX02", "Hoàng Thị D",  2000),
        };

        Console.WriteLine("===== BẢNG LƯƠNG NHÂN VIÊN =====");
        double tongLuong = 0;
        foreach (NhanVien nv in ds)
        {
            nv.Xuat();
            tongLuong += nv.TinhLuong();
        }

        Console.WriteLine($"\nTổng lương công ty: {tongLuong:N0} VNĐ");

        // Đếm theo bộ phận
        int soKD = 0, soSX = 0;
        foreach (NhanVien nv in ds)
        {
            if (nv is NhanVienKinhDoanh) soKD++;
            else if (nv is NhanVienSanXuat) soSX++;
        }
        Console.WriteLine($"Số NV kinh doanh: {soKD}, số NV sản xuất: {soSX}");
    }
}