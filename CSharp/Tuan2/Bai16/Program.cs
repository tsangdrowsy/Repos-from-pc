using System;

namespace Bai16_17
{
    class Bai16
    {
        public void GiaiBai16()
        {
            Console.Write("Nhập số lượng người (n): ");
            if (!int.TryParse(Console.ReadLine(), out int n) || n <= 0)
            {
                Console.WriteLine("Số lượng không hợp lệ!");
                return;
            }

            string[] hoTen = new string[n];

            // Nhập mảng
            for (int i = 0; i < n; i++)
            {
                Console.Write($"Nhập họ tên người thứ {i + 1}: ");
                hoTen[i] = Console.ReadLine();
            }

            // Sắp xếp tăng dần theo bảng chữ cái (Alphabet)
            Array.Sort(hoTen);

            // In kết quả
            Console.WriteLine("\nMảng họ tên sau khi sắp xếp tăng dần:");
            foreach (string ten in hoTen)
            {
                Console.WriteLine($"- {ten}");
            }
        }
        class Bai17
        {
            public void GiaiBai17()
            {
                Console.Write("Nhập số dòng n: ");
                int n = int.Parse(Console.ReadLine());
                Console.Write("Nhập số cột m: ");
                int m = int.Parse(Console.ReadLine());

                int[,] maTran = SinhMangNgauNhien(n, m);

                Console.WriteLine("\nMảng 2 chiều vừa sinh ngẫu nhiên:");
                InMangHaiChieu(maTran);

                TachChanLe(maTran, out int[] mangChan, out int[] mangLe);

                // In kết quả mảng chẵn, lẻ
                Console.WriteLine("\nMảng các số chẵn:");
                Console.WriteLine(string.Join(", ", mangChan));

                Console.WriteLine("Mảng các số lẻ:");
                Console.WriteLine(string.Join(", ", mangLe));
            }
            public static int[,] SinhMangNgauNhien(int n, int m) //man this random library is stolen from AI I have no idea it existed :sob:
            {
                int[,] matrix = new int[n, m];
                Random rand = new Random();

                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < m; j++)
                    {
                        matrix[i, j] = rand.Next(10, 101); //Stolen from AI cause I HAVE NO CLUE HOW
                    }
                }
                return matrix;
            }

            public void InMangHaiChieu(int[,] matrix)
            {
                int dong = matrix.GetLength(0);
                int cot = matrix.GetLength(1);

                for (int i = 0; i < dong; i++)
                {
                    for (int j = 0; j < cot; j++)
                    {
                        Console.Write($"{matrix[i, j]}\t"); //the normal array printing
                    }
                    Console.WriteLine();
                }
            }

            public void TachChanLe(int[,] matrix, out int[] mangChan, out int[] mangLe) //also int [,] is legit a matrix but short holy
            {
                List<int> danhSachChan = new List<int>();
                List<int> danhSachLe = new List<int>();

                foreach (int phanTu in matrix)
                {
                    if (phanTu % 2 == 0)
                    {
                        danhSachChan.Add(phanTu);
                    }
                    else
                    {
                        danhSachLe.Add(phanTu); //not hard at all
                    }
                }

                mangChan = danhSachChan.ToArray();
                mangLe = danhSachLe.ToArray();
            }
        }
    }
}