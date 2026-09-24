
using System;

namespace Bai4
{
    public class PhanSo
    {
        public int TuSo { get; set; }
        public int MauSo { get; set; }

        // Constructor mặc nhiên: 
        public PhanSo() : this(0, 1) { }

        // Constructor khởi tạo phân số với mẫu = 1
        public PhanSo(int tuSo) : this(tuSo, 1) { }

        // Constructor khởi tạo đầy đủ
        public PhanSo(int tuSo, int mauSo)
        {
            if (mauSo == 0)
                throw new ArgumentException("Mẫu số không được bằng 0.", nameof(mauSo));

            // Chuẩn hóa dấu: mẫu số luôn dương
            if (mauSo < 0)
            {
                tuSo = -tuSo;
                mauSo = -mauSo;
            }

            // Rút gọn phân số
            int ucln = UCLN(Math.Abs(tuSo), Math.Abs(mauSo));
            TuSo = tuSo / ucln;
            MauSo = mauSo / ucln;
        }

        // Constructor sao chép
        public PhanSo(PhanSo p) : this(p.TuSo, p.MauSo) { } // : is constructor initializer gọi constructor khác

        private static int UCLN(int a, int b)
        {
            a = Math.Abs(a);
            b = Math.Abs(b);

            while (b != 0)
            {
                int r = a % b;
                a = b;
                b = r;
            }

            return a == 0 ? 1 : a;
        }

        // Xuất phân số dạng "tử/mẫu"
        public override string ToString()
        {
            return $"{TuSo}/{MauSo}";
        }

        // Toán tử một ngôi
        public static PhanSo operator +(PhanSo a)
        {
            return new PhanSo(a);
        }

        public static PhanSo operator -(PhanSo a)
        {
            return new PhanSo(-a.TuSo, a.MauSo);
        }

        // Toán tử hai ngôi
        public static PhanSo operator +(PhanSo a, PhanSo b)
        {
            return new PhanSo(
                a.TuSo * b.MauSo + b.TuSo * a.MauSo,
                a.MauSo * b.MauSo
            );
        }

        public static PhanSo operator -(PhanSo a, PhanSo b)
        {
            return new PhanSo(
                a.TuSo * b.MauSo - b.TuSo * a.MauSo,
                a.MauSo * b.MauSo
            );
        }

        public static PhanSo operator *(PhanSo a, PhanSo b)
        {
            return new PhanSo(
                a.TuSo * b.TuSo,
                a.MauSo * b.MauSo
            );
        }

        public static PhanSo operator /(PhanSo a, PhanSo b)
        {
            if (b.TuSo == 0)
                throw new DivideByZeroException("Không thể chia cho phân số 0.");

            return new PhanSo(
                a.TuSo * b.MauSo,
                a.MauSo * b.TuSo
            );
        }

        // Toán tử so sánh
        public static bool operator >(PhanSo a, PhanSo b)
        {
            return (long)a.TuSo * b.MauSo > (long)b.TuSo * a.MauSo;
        }

        public static bool operator <(PhanSo a, PhanSo b)
        {
            return (long)a.TuSo * b.MauSo < (long)b.TuSo * a.MauSo;
        }

        public static bool operator >=(PhanSo a, PhanSo b)
        {
            return (long)a.TuSo * b.MauSo >= (long)b.TuSo * a.MauSo;
        }

        public static bool operator <=(PhanSo a, PhanSo b)
        {
            return (long)a.TuSo * b.MauSo <= (long)b.TuSo * a.MauSo;
        }

        public static bool operator ==(PhanSo a, PhanSo b)
        {
            return (long)a.TuSo * b.MauSo == (long)b.TuSo * a.MauSo;
        }

        public static bool operator !=(PhanSo a, PhanSo b)
        {
            return !(a == b);
        }
    }
}