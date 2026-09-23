using System;
using System.Net.Http.Headers;

namespace Bai5
{
    class Menu
    {
        public static void Main(String[] args)
        {
            int e = 0;
            double x = 0, y = 0;

            while (e != 4)
            {
                Console.WriteLine("MENU");

                Console.WriteLine("1. Nhap hai gia tri bieu thuc x,y");
                Console.WriteLine("2. Tinh x^y");
                Console.WriteLine("3. Tinh can bac 2 cua x va y");
                Console.WriteLine("4. Thoat");




                e = int.Parse(Console.ReadLine());


                {

                    switch (e)
                    {
                        case 1:
                            {
                                Console.Write("Nhap so nguyen x: ");
                                x = double.Parse(Console.ReadLine()); //task 3

                                Console.Write("Nhap so nguyen y: ");
                                y = double.Parse(Console.ReadLine()); //task 3
                                break;
                                
                            }
                        case 2:
                            {
                                Console.WriteLine("Ket qua cua x^y la: {0}", Math.Pow(x, y));
                                break;

                            }
                        case 3:
                            {
                                Console.WriteLine("Ket qua can 2 cua x va y la: {0} , {1}", Math.Sqrt(x), Math.Sqrt(y));
                                break;
                            }
                        case 4:
                            {
                                break;
                            }
                        default:
                            {
                                Console.Write("M gay");
                                break;
                            }
                    }
                }
            }

        }
    }

}

