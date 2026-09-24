using System;

public static class SortByDelegate
{
    // Delegate so sánh: trả về <0 nếu a<b, 0 nếu a==b, >0 nếu a>b
    public delegate int Comparison<T>(T a, T b);

    // bubble sort with delegate
    public static void Sort<T>(T[] arr, Comparison<T> cmp)
    {
        if (arr == null)
            throw new ArgumentNullException(nameof(arr));
        if (cmp == null)
            throw new ArgumentNullException(nameof(cmp));

        for (int i = 0; i < arr.Length - 1; i++)
        {
            for (int j = 0; j < arr.Length - 1 - i; j++)
            {
                if (cmp(arr[j], arr[j + 1]) > 0)
                    Swap(ref arr[j], ref arr[j + 1]);
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