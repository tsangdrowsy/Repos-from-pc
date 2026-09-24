using System;


namespace Bai14
{
    class Program
    {
        public static void Main(string[] args)
        {
            string hoTen;
            double Luong;
            int soNgayVang;
            double luongReal;
            double TIEN_TRU_MOT_NGAY_VANG = 100000;

            Console.Write("Nhập họ tên nhân viên: ");
            hoTen = Console.ReadLine();
            Console.Write("Nhập mức lương cơ bản: ");
            Luong = double.Parse(Console.ReadLine());
            Console.Write("Nhập số ngày vắng: ");
            soNgayVang = int.Parse(Console.ReadLine());

            luongReal = Luong - (soNgayVang * TIEN_TRU_MOT_NGAY_VANG);

            if (luongReal < 0)
            {
                luongReal = 0;
            }

            Console.WriteLine("\n THÔNG TIN LƯƠNG NHÂN VIÊN ");
            Console.WriteLine($"Họ và tên   : {hoTen}");
            Console.WriteLine($"Mức lương   : {Luong:N0} VNĐ");
            Console.WriteLine($"Số ngày vắng: {soNgayVang}");
            Console.WriteLine($"Lương thực nhận: {luongReal:N0} VNĐ");

            Console.Read();
        }
    }
}