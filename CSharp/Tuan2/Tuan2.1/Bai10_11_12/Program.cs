using System;
using System.Runtime.CompilerServices;
using Microsoft.VisualBasic;


namespace Bai10
{
    class KtraDoixung
    {
        public bool Ktra(string e)
        {
            for (int i = 0; i < e.Length; i++)
            {
                for (int j = e.Length - 1; j >= 0; j--)
                {
                    if (j == e.Length - 1 - i)
                    {
                        if (e[i] != e[j])
                        {
                            return false;  //2 loops is a pain
                        }
                    }
                }
            }
            return true;
        }


        //       public bool Ktra(string e)
        // {
        //     for (int i = 0; i < e.Length; i++)
        //     {
        //         for (int j = e.Length - 1; j >= 0; j--)
        //         {
        //             if (e[i] != e[j])
        //             {
        //                 return false;
        //             }
        //         }
        //     }
        //     return true;
        // } a better one with a way clearer logic
    }

    class DAOCHUOI
    { //bai11

        public string DC(string e)
        {
            char[] xd = e.ToCharArray();
            int i = 0;
            int j = xd.Length - 1;

            while (i < j)
            {
                char temp = e[i];
                xd[i] = xd[j];
                xd[j] =temp;

                i++;
                j--;
            }

            return new string(xd);

        }
    }



    class InHoaInThuong
    {
        public string IHIT(string e)
        {
            char[] xd = e.ToCharArray();

            bool temp;

            for (int i = 0; i < xd.Length; i++)
            {

                temp = char.IsLower(xd[i]);
                if (temp == true)
                {
                    xd[i] = char.ToUpper(xd[i]);
                }
                else
                {
                    xd[i] = char.ToLower(xd[i]);
                }
            }
            return new string(xd);
        }
    }
    class Program
    {
        public static void Main(String[] args)
        {
            Console.WriteLine("Nhap chuoi e: ");
            string e = Console.ReadLine();

            KtraDoixung r = new KtraDoixung();
            if (r.Ktra(e) == true)
            {
                Console.Write("LaChuoiDS");

            }
            else
            {
                Console.WriteLine("m gay");
            }

            DAOCHUOI q = new DAOCHUOI();

            Console.WriteLine("{0}", q.DC(e));

            InHoaInThuong t = new InHoaInThuong();
            Console.WriteLine("{0}", t.IHIT(e));
        }
    }
}


