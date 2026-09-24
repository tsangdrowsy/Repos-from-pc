using System;


namespace Bai2
{
    public class Point
    {
        public double x;
        public double y;

        //get, set
        public double X
        {
            get { return x; }
            set { x = value; }
        }

        public double Y
        {
            get { return y; }
            set { y = value; }
        }

        //constructor
        public Point()
        {
            this.x = 0;
            this.y = 0;
        }

        //input, output
        public void Input()
        {
            Console.Write("Nhập hoành độ x: ");
            this.x = Convert.ToDouble(Console.ReadLine());
            Console.Write("Nhập tung độ y: ");
            this.y = Convert.ToDouble(Console.ReadLine());
        }

        public void Output()
        {
            Console.WriteLine($"({this.x}, {this.y})");
        }

        //override
        public override string ToString()
        {
            return $"({this.x}, {this.y})";
        }

        //preconfig hàm point for ease of use for overloading
        public Point(double x, double y)
        {
            this.x = x;
            this.y = y;
        }

        //nạp chồng
        public static Point operator +(Point p1, Point p2)
        {
            return new Point(p1.X + p2.X, p1.Y + p2.Y);
        }



        public static Point operator -(Point p1, Point p2)
        {
            return new Point(p1.X - p2.X, p1.Y - p2.Y);
        }


        public static Point operator -(Point p)
        {
            return new Point(-p.X, -p.Y);
        }

        // phương thức thành viên
        public double KhoangCachD(Point other)
        {
            if (other == null) return 0;
            return Math.Sqrt(Math.Pow(this.x - other.x, 2) + Math.Pow(this.y - other.y, 2));
        }

        // static method, phương thức tĩnh
        public static double Distance(Point p1, Point p2)
        {
            if (p1 == null || p2 == null) return 0;
            return Math.Sqrt(Math.Pow(p1.x - p2.x, 2) + Math.Pow(p1.y - p2.y, 2));
        }
        // thành viên
        public Point MidpointWith(Point other)
        {
            if (other == null) return new Point();
            double midX = (this.x + other.x) / 2;
            double midY = (this.y + other.y) / 2;
            return new Point(midX, midY);
        }
        //tĩnh
        public static Point Midpoint(Point p1, Point p2)
        {
            if (p1 == null || p2 == null) return new Point();
            double midX = (p1.x + p2.x) / 2;
            double midY = (p1.y + p2.y) / 2;
            return new Point(midX, midY);
        }

        public static void Main(string[] args) //AI slop main for testing @@ 
        {
            Console.OutputEncoding = System.Text.Encoding.UTF8;

            Console.WriteLine("--- Nhập tọa độ điểm A ---");
            Point A = new Point();
            A.Input();

            Console.WriteLine("\n--- Nhập tọa độ điểm B ---");
            Point B = new Point();
            B.Input();

            Console.WriteLine($"\nĐiểm A: {A}");
            Console.WriteLine($"Điểm B: {B}");

            Console.WriteLine("\n--- (a) Tính Khoảng Cách Giữa A và B ---");

            double d1 = A.KhoangCachD(B);
            Console.WriteLine($"Cách 1 (Phương thức thành viên): AB = {d1:F2}");

            double d2 = Point.Distance(A, B);
            Console.WriteLine($"Cách 2 (Phương thức tĩnh):      AB = {d2:F2}");

            Console.WriteLine("\n--- (b) Xác Định Trung Điểm I của AB ---");

            Point I1 = A.MidpointWith(B);
            Console.WriteLine($"Cách 1 (Phương thức thành viên): I = {I1}");

            Point I2 = Point.Midpoint(A, B);
            Console.WriteLine($"Cách 2 (Phương thức tĩnh):      I = {I2}");

            Console.ReadLine();
        }

    }
}