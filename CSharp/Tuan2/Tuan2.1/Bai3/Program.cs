using System;

namespace Bai2
{
    class TinhMu{
        public static void Main(String[] args)
        {
            Console.Write("Nhap so nguyen x: ");
            // int x=int.Parse(Console.ReadLine()); //task 3
            string x= Console.ReadLine();
            Console.Write("Nhap so nguyen y: ");
            // int y=int.Parse(Console.ReadLine()); //task 3
            string y=Console.ReadLine();

            if (!int.TryParse(x, out int xx)) //Bài 4
            {
                Console.Write("m gay");
            }
               if (!int.TryParse(y, out int yy)) //Bài4
            {
                Console.Write("m gay");
            }

            Console.WriteLine("Ket qua {0} mu {1} la: {2}",xx,yy,Math.Pow(xx,yy));
        }
    }
}