using System;
using System.Collections.Generic;
using System.Text.Unicode; //added this to support Unicode






// Lớp ConsoleMenu tổng quát 
public class ConsoleMenu
{
    // Một mục menu
    protected class MenuItem
    {
        public int So { get; set; }
        public string MoTa { get; set; }
        public Action HanhDong { get; set; }
    }

    private readonly List<MenuItem> items = new List<MenuItem>();
    private bool daThoat = false;

    // Sự kiện được phát khi người dùng chọn một mục
    // Tham số: số của mục được chọn
    public event Action<int> Choose;

    public string TieuDe { get; set; } = "MENU";

    // Thêm một mục menu
    protected void ThemMuc(int so, string moTa, Action hanhDong)
    {
        items.Add(new MenuItem { So = so, MoTa = moTa, HanhDong = hanhDong });
        items.Sort((a, b) => a.So.CompareTo(b.So));   // sắp theo số
    }

    // In menu ra màn hình
    protected virtual void HienThiMenu()
    {
        Console.WriteLine("\n========== " + TieuDe + " ==========");
        foreach (var it in items)
            Console.WriteLine($"{it.So}. {it.MoTa}");
        Console.WriteLine("0. Thoát chương trình");
        Console.WriteLine("==================================");
    }

    // Vòng lặp chính
    public void Run()
    {
        while (!daThoat)
        {
            HienThiMenu();
            Console.Write("Thực hiện: ");
            int chon;
            if (!int.TryParse(Console.ReadLine(), out chon))
            {
                Console.WriteLine("nuh gng");
                continue;
            }

            // Phát sự kiện Choose cho bên ngoài
            Choose?.Invoke(chon);

            if (chon == 0)
            {
                daThoat = true;
                Console.WriteLine("adios!");
                break;
            }

            // Tìm mục có số tương ứng
            MenuItem chon_item = items.Find(x => x.So == chon);
            if (chon_item == null)
            {
                Console.WriteLine("nuh gng rechoose");
            }
            else
            {
                Console.WriteLine($"Bạn thực hiện chức năng {chon}: {chon_item.MoTa}");
                try
                {
                    chon_item.HanhDong?.Invoke();
                }
                catch (Exception ex)
                {
                    Console.WriteLine("Lỗi: " + ex.Message);
                }
            }
        }
    }
}

// Lớp con áp dụng cho PT bậc 2
public class PTBac2Console : ConsoleMenu
{
    public PTBac2Console()
    {
        TieuDe = "GIẢI PHƯƠNG TRÌNH BẬC 2";

        ThemMuc(1, "Nhập hệ số a, b, c", NhapHeSo);
        ThemMuc(2, "Giải phương trình", GiaiPT);
        ThemMuc(3, "Xem lại hệ số đã nhập", XemHeSo);
    }

    private double a, b, c;
    private bool daNhap = false;

    private void NhapHeSo()
    {
        Console.Write("Nhập a: ");
        a = double.Parse(Console.ReadLine());
        Console.Write("Nhập b: ");
        b = double.Parse(Console.ReadLine());
        Console.Write("Nhập c: ");
        c = double.Parse(Console.ReadLine());
        daNhap = true;
        Console.WriteLine("Đã lưu hệ số.");
    }

    private void XemHeSo()
    {
        if (!daNhap)
        {
            Console.WriteLine("Chưa nhập hệ số.");
            return;
        }
        Console.WriteLine($"Phương trình: {a}x^2 + {b}x + {c} = 0");
    }

    private void GiaiPT()
    {
        if (!daNhap)
        {
            Console.WriteLine("Vui lòng nhập hệ số trước (chức năng 1).");
            return;
        }

        Console.WriteLine($"Phương trình: {a}x^2 + {b}x + {c} = 0");

        if (a == 0)
        {
            if (b == 0)
                Console.WriteLine(c == 0 ? "Vô số nghiệm." : "Vô nghiệm.");
            else
                Console.WriteLine($"PT bậc 1, nghiệm x = {-c / b}");
            return;
        }

        double delta = b * b - 4 * a * c;
        Console.WriteLine($"Delta = {delta}");

        if (delta < 0)
            Console.WriteLine("Phương trình vô nghiệm.");
        else if (delta == 0)
            Console.WriteLine($"Nghiệm kép x1 = x2 = {-b / (2 * a)}");
        else
        {
            double x1 = (-b + Math.Sqrt(delta)) / (2 * a);
            double x2 = (-b - Math.Sqrt(delta)) / (2 * a);
            Console.WriteLine($"x1 = {x1}");
            Console.WriteLine($"x2 = {x2}");
        }
    }
}

// Chương trình chính 
class Program
{
    static void Main()
    {
        PTBac2Console app = new PTBac2Console();

        // Bắt sự kiện để log hoặc xử lý thêm
        app.Choose += (so) =>
        {
           
        };

        app.Run();
    }
}