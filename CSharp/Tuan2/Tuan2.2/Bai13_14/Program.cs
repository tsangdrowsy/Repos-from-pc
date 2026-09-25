using System;


public class SinhVien : IComparable<SinhVien> //yes this is not the java way of calling out an interface I know but this is kinda lit
{
    public string MaSV { get; set; }
    public string HoTen { get; set; }
    public double DiemTB { get; set; }

    public SinhVien() : this("", "", 0) { }

    public SinhVien(string maSV, string hoTen, double diemTB)
    {
        MaSV = maSV;
        HoTen = hoTen;
        DiemTB = diemTB;
    }

    public SinhVien(SinhVien other) : this(other.MaSV, other.HoTen, other.DiemTB) { }

    // So sánh ĐTB theo interface lớp
    public int CompareTo(SinhVien other)
    {
        if (other == null) return 1;
        return DiemTB.CompareTo(other.DiemTB);
    }

    public override string ToString()
    {
        return $"{MaSV,-8} | {HoTen,-20} | ĐTB: {DiemTB:F2}";
    }
}

// IComparer để sắp xếp theo tên (alphabet)
public class SoSanhTheoTen : IComparer<SinhVien>
{
    public int Compare(SinhVien a, SinhVien b)
    {
        if (a == null && b == null) return 0;
        if (a == null) return -1;
        if (b == null) return 1;
        return string.Compare(a.HoTen, b.HoTen, StringComparison.OrdinalIgnoreCase);
    }
}

// IComparer để sắp xếp theo mã sinh viên
public class SoSanhTheoMaSV : IComparer<SinhVien>
{
    public int Compare(SinhVien a, SinhVien b)
    {
        if (a == null && b == null) return 0;
        if (a == null) return -1;
        if (b == null) return 1;
        return string.Compare(a.MaSV, b.MaSV, StringComparison.Ordinal);
    }
}


//Bai 3.2 only requires me to write a sorting interface without specifying how many so ... just bubble sort then?
public static class MySort
{
    //using bubble sort guh
    // Yêu cầu T phải cài đặt IComparable<T> để so sánh được
    public static void Sort<T>(T[] arr) where T : IComparable<T>
    {
        if (arr == null)
            throw new ArgumentNullException(nameof(arr));

        for (int i = 0; i < arr.Length - 1; i++)
        {
            for (int j = 0; j < arr.Length - 1 - i; j++)
            {
                if (arr[j].CompareTo(arr[j + 1]) > 0)
                {
                    Swap(ref arr[j], ref arr[j + 1]);
                }
            }
        }
    }

 private static void Swap<T>(ref T a, ref T b)
    {
        T tmp = a;
        a = b;
        b = tmp;
    }
}

class Program
{
    static void Main()
    {
        SinhVien[] ds =
        {
            new SinhVien("SV03", "Nguyễn Văn C", 7.5),
            new SinhVien("SV01", "Trần Thị B",   9.0),
            new SinhVien("SV04", "Lê Văn D",     6.5),
            new SinhVien("SV02", "Hoàng Thị A",  8.2),
        };

        Console.WriteLine("Danh sách ban đầu ");
        foreach (var sv in ds) Console.WriteLine(sv);

    
        // Cách 2: truyền IComparer — theo tên
        Array.Sort(ds, new SoSanhTheoTen());
        Console.WriteLine("\n 3.1 (Alphabetical) ");
        foreach (var sv in ds) Console.WriteLine(sv);


        // Cách 4: dùng Comparison<T> delegate (lambda)
        Array.Sort(ds, (a, b) => b.DiemTB.CompareTo(a.DiemTB));
        Console.WriteLine("\n 3.2 ");
        foreach (var sv in ds) Console.WriteLine(sv);
    }
}


