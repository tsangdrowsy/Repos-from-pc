using System;

namespace CSharp.Buoi2
{
    class BieuThuc
    {
        //main
        public static void Main(string []args)
        {
            // Báo biến
            int a,b;
            int kqCong, kqTru, kqNhan, kqChiaNguyen, kqDu;
            double kqChiaThuc;

            //Nhập dữ liệu
            Console.Write("Moi ban nhap so a: "); //Lệnh Console write bắt buộc truyền dữ liệu và không xuống dòng
            a = int.Parse(Console.ReadLine()); // gán a = dữ liệu parse được từ dòng được gõ trong console
            Console.Write("Moi ban nhap so b: ");
            b = int.Parse(Console.ReadLine());

            // Xử lý
            kqCong=a+b;
            kqTru=a-b;
            kqNhan=a*b;
            kqChiaNguyen=a/b;
            kqDu=a%b;
            kqChiaThuc=a/(double)b;

            //In ra console
            Console.WriteLine("{0} + {1} = {2}", a, b, kqCong);//test
            Console.WriteLine("{0, -5} + {1, 5} = {2, 5}", a, b, kqCong);
            Console.WriteLine("{0,-5} - {1,5} ={2,5}",a,b,kqTru);
            Console.WriteLine("{0,-5} x {1,5} = {2,5}", a,b,kqNhan);
            Console.WriteLine("{0,-5} / {1,5} = {2,5}", a,b,kqChiaNguyen);
            Console.WriteLine("{0,-5} % {1,5} = {2,5}", a,b,kqDu);
            Console.WriteLine("{0,-5} / {1,5}= {2,5}", a,b,kqChiaThuc);

            Console.Read(); //return 0 in cpp

        }
    }
}