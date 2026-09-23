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
    }
    
}