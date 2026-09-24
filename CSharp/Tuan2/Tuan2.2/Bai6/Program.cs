using System;
using System.Collections;

// Lớp Point đơn giản (nếu chưa có)
public class Point
{
    public int X { get; set; }
    public int Y { get; set; }

    public Point() : this(0, 0) { }

    public Point(int x, int y)
    {
        X = x;
        Y = y;
    }

    public override string ToString()
    {
        return $"({X}, {Y})";
    }
}

// Lớp ArrayPoint quản lý danh sách các Point
public class ArrayPoint
{
    // Field: ArrayList chứa các Point
    private ArrayList danhSachPoint;

    // Constructor mặc nhiên
    public ArrayPoint()
    {
        danhSachPoint = new ArrayList();
    }

    // Constructor khởi tạo với sức chứa ban đầu
    public ArrayPoint(int capacity)
    {
        danhSachPoint = new ArrayList(capacity);
    }

    // Constructor sao chép
    public ArrayPoint(ArrayPoint other)
    {
        danhSachPoint = new ArrayList(other.danhSachPoint);
    }

    // Thuộc tính cho biết số lượng Point
    public int Count => danhSachPoint.Count;

    // Indexer: cho phép truy cập Point thứ i
    public Point this[int i]
    {
        get
        {
            if (i < 0 || i >= danhSachPoint.Count)
                throw new IndexOutOfRangeException(
                    $"Chỉ số {i} nằm ngoài phạm vi [0, {danhSachPoint.Count - 1}].");

            return (Point)danhSachPoint[i];
        }
        set
        {
            if (i < 0 || i >= danhSachPoint.Count)
                throw new IndexOutOfRangeException(
                    $"Chỉ số {i} nằm ngoài phạm vi [0, {danhSachPoint.Count - 1}].");

            danhSachPoint[i] = value;
        }
    }

    // Thêm một Point vào cuối danh sách
    public void Them(Point p)
    {
        if (p == null)
            throw new ArgumentNullException(nameof(p));

        danhSachPoint.Add(p);
    }

    // Xóa Point tại vị trí i
    public void Xoa(int i)
    {
        if (i < 0 || i >= danhSachPoint.Count)
            throw new IndexOutOfRangeException(
                $"Chỉ số {i} nằm ngoài phạm vi [0, {danhSachPoint.Count - 1}].");

        danhSachPoint.RemoveAt(i);
    }

    // Xuất danh sách các Point
    public override string ToString()
    {
        if (danhSachPoint.Count == 0)
            return "[]";

        string s = "[";
        for (int i = 0; i < danhSachPoint.Count; i++)
        {
            s += danhSachPoint[i].ToString();
            if (i < danhSachPoint.Count - 1)
                s += ", ";
        }
        s += "]";
        return s;
    }
}