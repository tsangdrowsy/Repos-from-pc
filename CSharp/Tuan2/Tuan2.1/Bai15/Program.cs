using System;

namespace Bai15
{
    class Arrays
    {
        int n;
        int[] a;
        public void NhapMang()
        {
            Console.Write("Dai nhieu?");
            int n = int.Parse(Console.ReadLine());
            a = new int[n];
            for (int i = 0; i < n; i++)
            {
                Console.WriteLine("Nhap mang de");
                a[i] = int.Parse(Console.ReadLine());
            }

        }

        public void InMang()
        {
            Console.WriteLine("Mang ne ");
            for (int i = 0; i < n; i++)
            {
                Console.Write(a[i] + " ");
            }
            Console.WriteLine();
        }
        public void TimMaxMin(out int max, out int min)
        {
            max = a[0];
            min = a[0];
            for (int i = 1; i < n; i++)
            {
                if (a[i] > max) max = a[i];
                if (a[i] < min) min = a[i];
            }
        }
        public bool LaSoNguyenTo(int x)
        {
            if (x < 2) return false;
            for (int i = 2; i <= Math.Sqrt(x); i++)
            {
                if (x % i == 0) return false;
            }
            return true;
        }
        public int[] LayMangSoNguyenTo()
        {
            List<int> sntList = new List<int>();
            foreach (int x in a)
            {
                if (LaSoNguyenTo(x))
                {
                    sntList.Add(x);
                }
            }
            return sntList.ToArray();
        }
        public static void Main()
        {
            Console.OutputEncoding = System.Text.Encoding.UTF8;
            Arrays obj = new Arrays();

            obj.NhapMang();
            obj.InMang();

            obj.TimMaxMin(out int max, out int min);
            Console.WriteLine("Phần tử lớn nhất: {0}", max);
            Console.WriteLine("Phần tử nhỏ nhất: {0}", min);

            int[] sntA = obj.LayMangSoNguyenTo();
            Console.WriteLine("Các số nguyên tố trong mảng là: " + string.Join(" ", sntA));
        }
    }
}

