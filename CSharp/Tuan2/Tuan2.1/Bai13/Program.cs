using System;
using System.Text.Unicode;


namespace Bai13
{
    class SinhVien
    {
        public string MaSV { get; set; }
        public string HoTen { get; set; }
        public string DiaChi { get; set; }
        public int NamThu { get; set; }

        public void Nhap()
        {


            Console.Write("Nhập mã sinh viên: ");
            MaSV = Console.ReadLine();

            Console.Write("Nhập họ tên: ");
            HoTen = Console.ReadLine();

            Console.Write("Nhập địa chỉ: ");
            DiaChi = Console.ReadLine();

            while (true)
            {
                Console.Write("Sinh viên năm thứ mấy? ");
                if (int.TryParse(Console.ReadLine(), out int nam) && nam > 0)
                {
                    NamThu = nam;
                    break;
                }
                Console.WriteLine("Vui lòng nhập một số nguyên hợp lệ!");
            }
        }

        public void Xuat()
        {
            Console.WriteLine($"Mã sinh viên      : {MaSV}");
            Console.WriteLine($"Họ và tên         : {HoTen}");
            Console.WriteLine($"Địa chỉ           : {DiaChi}");
            Console.WriteLine($"Sinh viên năm thứ : {NamThu}");
        }

        class Program
        {
            static void Main(string[] args)
            {
              

                SinhVien sv = new SinhVien();

                sv.Nhap();

                sv.Xuat();

                Console.ReadLine();
            }
        }
    }
}

