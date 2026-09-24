using System;
using Bai3;


namespace Bai7
{
    public class PersonList
    {
        // Dùng List<Person> để lưu danh sách
        private List<Person> danhSach;

        // Default constructor
        public PersonList()
        {
            danhSach = new List<Person>();
        }

        // Copy constructor: sao chép sâu (deep copy)
        public PersonList(PersonList other)
        {
            danhSach = new List<Person>();
            foreach (Person p in other.danhSach)
            {
                danhSach.Add(new Person(p)); // dùng copy constructor của Person
            }
        }

        // Số lượng Person trong danh sách
        public int Count
        {
            get { return danhSach.Count; }
        }

        // Thêm một Person vào danh sách
        public void Add(Person x)
        {
            if (x == null)
                throw new ArgumentNullException(nameof(x));

            danhSach.Add(x);
        }

        // Nhập danh sách Person
        public void Input()
        {
            Console.Write("Nhập số lượng người: ");
            int n = int.Parse(Console.ReadLine());

            for (int i = 0; i < n; i++)
            {
                Console.WriteLine($"\nNhập thông tin người thứ {i + 1}:");
                Person p = new Person();
                p.Input();
                danhSach.Add(p);
            }
        }

        // Xuất danh sách Person
        public void Output()
        {
            Console.WriteLine("\nDanh sách người:");

            if (danhSach.Count == 0)
            {
                Console.WriteLine("(Danh sách trống)");
                return;
            }

            for (int i = 0; i < danhSach.Count; i++)
            {
                Console.Write($"{i + 1}. ");
                danhSach[i].Output();
            }
        }

        // Trả về một PersonList chỉ gồm những người còn sống
        public PersonList LivingPeople()
        {
            PersonList ketQua = new PersonList();

            foreach (Person p in danhSach)
            {
                if (p.IsLiving())
                {
                    ketQua.Add(new Person(p)); // copy sang danh sách mới
                }
            }

            return ketQua;
        }

        public override string ToString()
        {
            if (danhSach.Count == 0)
                return "PersonList[]";

            return "PersonList[\n  " + string.Join("\n  ", danhSach) + "\n]";
        }
    }
}