using System;

namespace Bai3
{
    public class Person
    {
        // Các dữ liệu
        public string id;
        public string name;
        public int yob;
        public int yod;

        public Person()
        {
            id = "";
            name = "";
            yob = 0;
            yod = 0;
        }

        public Person(Person other) //copy
        {
            if (other != null)
            {
                this.id = other.id;
                this.name = other.name;
                this.yob = other.yob;
                this.yod = other.yod;
            }
        }

        public Person(string id, string name, int yob, int yod) //input yes
        {
            this.id = id;
            this.name = name;
            this.yob = yob;
            this.yod = yod;
        }

        public bool IsLiving()
        {
            return yod == 0;
        }

        public void Output()
        {
            string trangThai = IsLiving() ? "Còn sống" : $"Đã mất năm {yod}";
            Console.WriteLine($"Id: {id}, Tên: {name}, Năm sinh: {yob}, Trạng thái: {trangThai}");
        }


         public void Input()
    {
        Console.Write("Nhập id: ");
        id = Console.ReadLine();

        Console.Write("Nhập tên: ");
        name = Console.ReadLine();

        Console.Write("Nhập năm sinh: ");
        yob = int.Parse(Console.ReadLine());

        Console.Write("Nhập năm mất (0 nếu còn sống): ");
        yod = int.Parse(Console.ReadLine());
    }
        public override string ToString()
        {
            return $"Person[{id}, {name}, {yob}, {yod}]";
        }
    }
}