using System;


namespace Bai5
{
    public class DonThuc
    {
        // Hệ số a
        public double HeSo { get; set; }

        // Số mũ n (n >= 0)
        public int SoMu { get; set; }

        // Constructor mặc nhiên: 0
        public DonThuc() : this(0, 0) { }

        // Constructor khởi tạo đơn thức bậc 0: a
        public DonThuc(double heSo) : this(heSo, 0) { }

        // Constructor đầy đủ
        public DonThuc(double heSo, int soMu)
        {
            if (soMu < 0)
                throw new ArgumentException("Số mũ phải là số nguyên không âm.", nameof(soMu));

            HeSo = heSo;
            SoMu = soMu;
        }

        // Constructor sao chép
        public DonThuc(DonThuc d) : this(d.HeSo, d.SoMu) { }

        // (a) Tính giá trị P(x) = a * x^n
        public double TinhGiaTri(double x)
        {
            return HeSo * Math.Pow(x, SoMu);
        }

        // (b) Đạo hàm P'(x) = a * n * x^(n-1)
        public DonThuc DaoHam()
        {
            if (SoMu == 0)
                return new DonThuc(0, 0);

            return new DonThuc(HeSo * SoMu, SoMu - 1);
        }

        // Xuất đơn thức dạng chuỗi
        public override string ToString()
        {
            if (HeSo == 0)
                return "0";

            if (SoMu == 0)
                return HeSo.ToString();

            if (SoMu == 1)
                return $"{HeSo}x";

            return $"{HeSo}x^{SoMu}";
        }
    }
}