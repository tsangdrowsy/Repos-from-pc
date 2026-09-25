using System;

namespace Bai12
{
    public class NhanVien
    {
        // Thay const bằng field thường 
        public double TruMoiNgayVang = 100000;

        public string HoTen;
        public double MucLuong;
        public int SoNgayVang;

        // Default constructor
        public NhanVien()
        {
            HoTen = "";
            MucLuong = 0;
            SoNgayVang = 0;
        }

        // Constructor đầy đủ
        public NhanVien(string hoTen, double mucLuong, int soNgayVang)
        {
            if (mucLuong < 0)
                throw new ArgumentException("Mức lương không được âm.");
            if (soNgayVang < 0)
                throw new ArgumentException("Số ngày vắng không được âm.");

            HoTen = hoTen;
            MucLuong = mucLuong;
            SoNgayVang = soNgayVang;
        }

        // Copy constructor
        public NhanVien(NhanVien other)
        {
            HoTen = other.HoTen;
            MucLuong = other.MucLuong;
            SoNgayVang = other.SoNgayVang;
        }

        // Tiền bị trừ do vắng
        public double TienBiTru()
        {
            return SoNgayVang * TruMoiNgayVang;
        }

        // Lương thực lĩnh
        public double LuongThucLinh()
        {
            double luong = MucLuong - TienBiTru();
            return luong < 0 ? 0 : luong;
        }

        public void Nhap()
        {
            Console.Write("  Họ tên: ");
            HoTen = Console.ReadLine();

            Console.Write("  Mức lương: ");
            MucLuong = double.Parse(Console.ReadLine());

            Console.Write("  Số ngày vắng: ");
            SoNgayVang = int.Parse(Console.ReadLine());

            if (MucLuong < 0 || SoNgayVang < 0)
                throw new ArgumentException("Lương và số ngày vắng không được âm.");
        }

        public void Xuat()
        {
            Console.WriteLine(
                $"  {HoTen,-20} Lương: {MucLuong,12:N0}  " +
                $"Vắng: {SoNgayVang,3} ngày  Trừ: {TienBiTru(),10:N0} " +
                $"Thực lĩnh: {LuongThucLinh(),12:N0}");
        }

        public override string ToString()
        {
            return $"{HoTen} (lương {MucLuong:N0}, vắng {SoNgayVang} ngày, thực lĩnh {LuongThucLinh():N0})";
        }
    }

    public class PhongBan
    {
        private NhanVien[] danhSach;
        private int n;

        // Default constructor
        public PhongBan()
        {
            n = 0;
            danhSach = new NhanVien[0];
        }

        // Constructor n nhân viên rỗng
        public PhongBan(int n)
        {
            if (n < 0)
                throw new ArgumentException("Số nhân viên không được âm.");

            this.n = n;
            danhSach = new NhanVien[n];
            for (int i = 0; i < n; i++)
                danhSach[i] = new NhanVien();
        }

        // Constructor từ mảng có sẵn
        public PhongBan(NhanVien[] arr)
        {
            if (arr == null)
                throw new ArgumentNullException(nameof(arr));

            n = arr.Length;
            danhSach = new NhanVien[n];
            for (int i = 0; i < n; i++)
                danhSach[i] = new NhanVien(arr[i]);
        }

        // Copy constructor
        public PhongBan(PhongBan other)
        {
            n = other.n;
            danhSach = new NhanVien[n];
            for (int i = 0; i < n; i++)
                danhSach[i] = new NhanVien(other.danhSach[i]);
        }

        public int N
        {
            get { return n; }
        }

        // Indexer
        public NhanVien this[int i]
        {
            get
            {
                if (i < 0 || i >= n)
                    throw new IndexOutOfRangeException($"Chỉ số {i} ngoài phạm vi [0, {n - 1}].");
                return danhSach[i];
            }
            set
            {
                if (i < 0 || i >= n)
                    throw new IndexOutOfRangeException($"Chỉ số {i} ngoài phạm vi [0, {n - 1}].");
                danhSach[i] = new NhanVien(value);
            }
        }

        public void Nhap()
        {
            Console.Write("Nhập số nhân viên n: ");
            n = int.Parse(Console.ReadLine());

            if (n < 0)
                throw new ArgumentException("Số nhân viên không được âm.");

            danhSach = new NhanVien[n];
            for (int i = 0; i < n; i++)
            {
                Console.WriteLine($"\nNhân viên thứ {i + 1}:");
                danhSach[i] = new NhanVien();
                danhSach[i].Nhap();
            }
        }

        public void Xuat()
        {
            if (n == 0)
            {
                Console.WriteLine("Phòng ban không có nhân viên.");
                return;
            }

            Console.WriteLine("Danh sách nhân viên:");
            for (int i = 0; i < n; i++)
            {
                Console.Write($"{i + 1}. ");
                danhSach[i].Xuat();
            }
        }

        // Tổng lương thực lĩnh của phòng ban
        public double TongLuongThucLinh()
        {
            double tong = 0;
            for (int i = 0; i < n; i++)
                tong += danhSach[i].LuongThucLinh();
            return tong;
        }
        //extras cause idk what kind of sum is being asked
        public double TongLuongCoBan()
        {
            double tong = 0;
            for (int i = 0; i < n; i++)
                tong += danhSach[i].MucLuong;
            return tong;
        }

        public double TongTienBiTru()
        {
            double tong = 0;
            for (int i = 0; i < n; i++)
                tong += danhSach[i].TienBiTru();
            return tong;
        }

        public override string ToString()
        {
            if (n == 0)
                return "PhongBan[ rỗng ]";

            string s = "PhongBan[\n";
            for (int i = 0; i < n; i++)
                s += "  " + danhSach[i] + "\n";
            s += "]";
            return s;
        }
    }
//     class Program
//     {
//         static void Main()
//         {
//             NhanVien[] arr =
//             {
//             new NhanVien("Nguyễn Văn A", 10000000, 2),
//             new NhanVien("Trần Thị B",   12000000, 0),
//             new NhanVien("Lê Văn C",      8000000, 5)
//         };
//             PhongBan pb = new PhongBan(arr);

//             pb.Xuat();
          
//             Console.WriteLine($"Tổng lương thực lĩnh: {pb.TongLuongThucLinh():N0} VNĐ");
//         }
//     }
}