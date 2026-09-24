using System;

namespace Bai1
{
    class Bai16
    {
        public static void Main(string[] args)
        {
            Console.Write("Nhập họ tên sinh viên: ");
            string hoTen = Console.ReadLine();

            Console.Write("Nhập năm sinh: ");
            int namSinh = int.Parse(Console.ReadLine());

            int tuoi = DateTime.Now.Year - namSinh;
            Console.WriteLine($"Họ tên: {hoTen}");
            Console.WriteLine($"Năm sinh: {namSinh}");
            Console.WriteLine($"Tuổi: {tuoi}");
        }
    }
}