using System;
using System.Data.Common;


namespace Bai6
{
    class Bai6
    {
        public int TimGTLN(int x, int y, int z)
        {
            int GTLN=0;

            if (x>GTLN)
            {
                GTLN=x;
            }
            if (y>GTLN)
            {
                GTLN=y;
            }
            if(z>GTLN)
            {
                GTLN=z;
            }
            return GTLN;
        }
    }

    class Bai7
    {
        public bool laSNT(int x)
        {
            if (x<2) return false;
            if (x==2) return true;
            if (x%2==0)return false;

            for (int i=3; i> Math.Sqrt(x+1); i+=2) //ripped the loop from AI cause I ain't remembering the math :steamhappy:
            {
                if (x%i==0)
                return false;
            }
            return true;
        }
    }

    class Bai8
    {
        public void HoanVi(ref double x, ref double y)
        {
            double temp=x;
            x=y;
            y=temp;
        }
    }

    class Bai9
    {
        public void TimGiaTriMaxMin(double x, double y, double z, out double max, out double min)
        {
            max =x;
            min =x;

            if (y>max) max=y;
            if (y<min) min=y;

            if (z>max) max=z;
            if (z<min) min=z;

        }
    }

    class Program
    {
        public static void Main(String[] args)
        {
            Bai6 u= new Bai6();
            Console.WriteLine("e: {0}",u.TimGTLN(3,5,4));

            Bai7 d= new Bai7();

            int dd=27;
            
            if (d.laSNT(dd) ==true)
            {
                Console.Write("LaSNT");
            }
            else
            {
                Console.Write("nuh");
            }

            Bai8 r=new Bai8();
            double o=1, p=2;
            r.HoanVi(ref o,ref p);
            Console.WriteLine("o is {0}, p is {1}", o,p);

            Bai9 t=new Bai9();
            double man,min;
            t.TimGiaTriMaxMin(3,4,5, out man, out min);
            Console.WriteLine("yeah it's ... {0},{1}",man,min);
            
        }
    }

}
