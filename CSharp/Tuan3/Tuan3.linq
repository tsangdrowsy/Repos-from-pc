<Query Kind="Program" />

﻿using System;
using System.Collections.Generic;
using System.Linq;

namespace BaiThucHanhLINQ
{

    // BÀI 4.1: KHAI BÁO CÁC LỚP ĐỐI TƯỢNG

    public class MonHoc
    {
        public string MaMon { get; set; } = "";
        public string TenMon { get; set; } = "";
        public string He { get; set; } = "";
        public byte SoTiet { get; set; }
    }

    public class He
    {
        public string MaHe { get; set; } = "";
        public string TenHe { get; set; } = "";
    }

    public class DuLieu
    {
        // Phương thức trả về List<MonHoc> 
        public static List<MonHoc> DS_Mon()
        {
            return new List<MonHoc>()
            {
                new MonHoc { MaMon = "HP2_1", TenMon = "Nền tảng C#", He = "KTV", SoTiet = 64 },
                new MonHoc { MaMon = "HP2_2", TenMon = "Công nghệ ADO.NET", He = "KTV", SoTiet = 64 },
                new MonHoc { MaMon = "HP3_1", TenMon = "Lập trình Windows Forms", He = "KTV", SoTiet = 64 },
                new MonHoc { MaMon = "HP3_2", TenMon = "Xây dựng ứng dụng Windows Forms", He = "KTV", SoTiet = 64 },
                new MonHoc { MaMon = "HP4_1", TenMon = "Lập trình Web với HTML, CSS và JavaScript", He = "KTV", SoTiet = 64 },
                new MonHoc { MaMon = "HP4_2", TenMon = "Xây dựng ứng dụng Web với ASP.NET", He = "KTV", SoTiet = 64 },
                new MonHoc { MaMon = "HP5_1", TenMon = "Lập trình CSDL SQL Server căn bản", He = "KTV", SoTiet = 64 },
                new MonHoc { MaMon = "HP5_2", TenMon = "Lập trình CSDL SQL Server nâng cao", He = "KTV", SoTiet = 64 },
                new MonHoc { MaMon = "JLCB", TenMon = "Joomla cơ bản", He = "CD", SoTiet = 72 },
                new MonHoc { MaMon = "LINQ", TenMon = "Language-Integrated Query", He = "CD", SoTiet = 64 },
                new MonHoc { MaMon = "DAWEB", TenMon = "Đồ án thực tế Web với ASP.NET", He = "CD", SoTiet = 40 },
                new MonHoc { MaMon = "DAWIN", TenMon = "Đồ án thực tế Windows Forms", He = "CD", SoTiet = 40 },
                new MonHoc { MaMon = "CC++", TenMon = "Lập trình hướng đối tượng với C/C++", He = "CD", SoTiet = 128 },
                new MonHoc { MaMon = "JQUE", TenMon = "JQuery", He = "CD", SoTiet = 22 },
                new MonHoc { MaMon = "XML", TenMon = "Công nghệ XML", He = "CD", SoTiet = 32 },
                new MonHoc { MaMon = "CRYS", TenMon = "Crystal Report trong Visual Studio", He = "CD", SoTiet = 32 },
                new MonHoc { MaMon = "BWEB", TenMon = "HTML, CSS và JavaScript", He = "CD", SoTiet = 32 },
               
            };
        }
    


    // CHƯƠNG TRÌNH CHÍNH

   

 
        // BÀI 2.1: TRUY VẤN MẢNG SỐ NGUYÊN
 
        static void Bai21()
        {
            int[] mangSo = { 50, 42, 16, 3, 9, 8, 12, 7, 24, 0 };

            // a. Liệt kê các phần tử chia hết cho 4 và 3
            var cauA = mangSo.Where(n => n % 4 == 0 && n % 3 == 0);
            Console.WriteLine("a. Các phần tử chia hết cho 4 và 3: " + string.Join(", ", cauA));

            // b. Liệt kê các phần tử nhỏ hơn hoặc bằng 3
            var cauB = from n in mangSo where n <= 3 select n;
            Console.WriteLine("b. Các phần tử <= 3: " + string.Join(", ", cauB));

            // c. Tạo dãy mới: số chẵn chia đôi, số lẻ giữ nguyên
            var cauC = mangSo.Select(n => n % 2 == 0 ? n / 2 : n);
            Console.WriteLine("c. Dãy mới (chẵn chia đôi, lẻ giữ nguyên): " + string.Join(", ", cauC));
        }


        // BÀI 2.2: TRUY VẤN MẢNG CHUỖI

        static void Bai22()
        {
            string[] mangChuoi = { "đầu", "lòng", "hai", "ả", "tố", "nga", "Thúy", "Kiều", "là", "chị", "em", "là", "Thúy", "Vân" };

            // a. Liệt kê các phần tử có 4 ký tự và sắp xếp tăng dần theo ký tự đầu tiên
            var cauA = mangChuoi.Where(s => s.Length == 4).OrderBy(s => s[0]);
            Console.WriteLine("a. Từ có 4 ký tự (sắp xếp theo ký tự đầu): " + string.Join(", ", cauA));

            // b. Biến đổi phần tử thành: <chữ thường> - <CHỮ HOA>
            var cauB = mangChuoi.Select(s => $"{s.ToLower()} - {s.ToUpper()}");
            Console.WriteLine("b. Biến đổi thành <thường> - <HOA>:");
            foreach (var item in cauB) Console.WriteLine("   " + item);

            // c. Liệt kê các phần tử có chứa ký tự "u"
            var cauC = mangChuoi.Where(s => s.Contains("u"));
            Console.WriteLine("c. Các từ chứa ký tự 'u': " + string.Join(", ", cauC));

            // d. Liệt kê các từ "Thúy Kiều Thúy Vân" bằng cách chọn các phần tử bắt đầu bằng chữ in hoa
            var cauD = mangChuoi.Where(s => s.Length > 0 && char.IsUpper(s[0]));
            Console.WriteLine("d. Các từ bắt đầu bằng chữ in hoa: " + string.Join(" ", cauD));
        }


        // BÀI 3.1: THỐNG KÊ MẢNG SỐ

        static void Bai31()
        {
            int[] mangSo = { 50, 42, 12, 3, 9, 8, 1, 50, 3, 42, 85 };

            // a. Tổng số phần tử, số chẵn, số lẻ
            Console.WriteLine($"a. Tổng số phần tử: {mangSo.Length}");
            Console.WriteLine($"   Số phần tử chẵn: {mangSo.Count(n => n % 2 == 0)}");
            Console.WriteLine($"   Số phần tử lẻ: {mangSo.Count(n => n % 2 != 0)}");

            // b. Tổng giá trị, Min, Max
            Console.WriteLine($"b. Tổng giá trị: {mangSo.Sum()}");
            Console.WriteLine($"   Giá trị nhỏ nhất: {mangSo.Min()}");
            Console.WriteLine($"   Giá trị lớn nhất: {mangSo.Max()}");

            // c. Số lượng giá trị khác nhau
            Console.WriteLine($"c. Số lượng giá trị khác nhau: {mangSo.Distinct().Count()}");

            // d. Phân nhóm theo số dư khi chia cho 5
            var nhomDu = mangSo.GroupBy(n => n % 5).OrderBy(g => g.Key);
            Console.WriteLine("d. Phân nhóm theo số dư khi chia cho 5:");
            foreach (var nhom in nhomDu)
            {
                Console.WriteLine($"   Số dư {nhom.Key}: {string.Join(", ", nhom)}");
            }
        }

   
        // BÀI 3.2: THỐNG KÊ MẢNG CHUỖI

        static void Bai32()
        {
            string[] monAn = { "Bún bò Huế", "Hủ tiếu heo", "Bánh canh", "Bánh mì", "Nước Cà phê", "Mì quảng", "Cơm tấm", "Nước Chanh dây", "Mì xào", "Bún riêu", "Bánh cuốn", "Mì gói", "Bún chả", "Hủ tiếu Nam vang" };

            // a. Các phần tử có chiều dài ngắn nhất và dài nhất
            int minLen = monAn.Min(s => s.Length);
            int maxLen = monAn.Max(s => s.Length);
            Console.WriteLine($"a. Từ ngắn nhất ({minLen} ký tự): {string.Join(", ", monAn.Where(s => s.Length == minLen))}");
            Console.WriteLine($"   Từ dài nhất ({maxLen} ký tự): {string.Join(", ", monAn.Where(s => s.Length == maxLen))}");

            // b. Phân nhóm theo từ đầu tiên của mỗi món
            var nhomTuDau = monAn.GroupBy(s => s.Split(' ')[0]);
            Console.WriteLine("b. Phân nhóm theo từ đầu tiên:");
            foreach (var nhom in nhomTuDau)
            {
                Console.WriteLine($"   Nhóm '{nhom.Key}': {string.Join(", ", nhom)}");
            }

            // c. Đếm số phần tử có từ đầu tiên là "Bánh"
            int demBanh = monAn.Count(s => s.StartsWith("Bánh"));
            Console.WriteLine($"c. Số món có từ đầu tiên là 'Bánh': {demBanh}");
        }


        // BÀI 4.1: KIỂM TRA LỚP VÀ DỮ LIỆU
 
        static void Bai41()
        {
            List<MonHoc> danhSachMonHoc = DuLieu.DS_Mon();

            Console.WriteLine($"Tổng số môn học đã tạo: {danhSachMonHoc.Count}");
            Console.WriteLine("\nDanh sách môn học:");
            foreach (var mon in danhSachMonHoc)
            {
                Console.WriteLine($"- Mã: {mon.MaMon,-6} | Tên: {mon.TenMon,-45} | Hệ: {mon.He,-4} | Số tiết: {mon.SoTiet}");
            }
        }

      
        // BÀI 5.1: TRUY VẤN TRÊN LIST<MonHoc>
   
        static void Bai51()
        {
            var dsMon = DuLieu.DS_Mon();

            // a. Liệt kê tên các môn học bắt đầu bằng "Lập trình"
            var cauA = dsMon.Where(m => m.TenMon.StartsWith("Lập trình")).Select(m => m.TenMon);
            Console.WriteLine("a. Môn bắt đầu bằng 'Lập trình':");
            foreach (var ten in cauA) Console.WriteLine("   - " + ten);

            // b. Liệt kê các môn thuộc hệ "CD", sắp xếp số tiết giảm dần rồi mã môn tăng dần
            var cauB = dsMon.Where(m => m.He == "CD")
                            .OrderByDescending(m => m.SoTiet)
                            .ThenBy(m => m.MaMon)
                            .Select(m => $"{m.MaMon} - {m.TenMon} ({m.SoTiet} tiết)");
            Console.WriteLine("\nb. Môn hệ CD (Số tiết giảm dần, Mã môn tăng dần):");
            foreach (var item in cauB) Console.WriteLine("   - " + item);

            // c. Liệt kê các môn có tên chứa từ "web", chỉ lấy Tên môn và Hệ
            var cauC = dsMon.Where(m => m.TenMon.ToLower().Contains("web"))
                            .Select(m => new { m.TenMon, m.He });
            Console.WriteLine("\nc. Môn có tên chứa 'web':");
            foreach (var item in cauC) Console.WriteLine($"   - {item.TenMon} (Hệ: {item.He})");

            // d. Liệt kê các môn thuộc hệ "KTV", sắp xếp tăng dần theo Mã môn
            var cauD = dsMon.Where(m => m.He == "KTV").OrderBy(m => m.MaMon).Select(m => m.MaMon);
            Console.WriteLine("\nd. Mã môn hệ KTV (tăng dần): " + string.Join(", ", cauD));
        }

      
        // BÀI 5.2: THỐNG KÊ TRÊN LIST<MonHoc>
  
        static void Bai52()
        {
            var dsMon = DuLieu.DS_Mon();

            Console.WriteLine($"a. Tổng số môn hiện có: {dsMon.Count}");
            Console.WriteLine($"b. Số môn bắt đầu bằng 'Lập trình': {dsMon.Count(m => m.TenMon.StartsWith("Lập trình"))}");
            Console.WriteLine($"c. Tổng số tiết của hệ KTV: {dsMon.Where(m => m.He == "KTV").Sum(m => m.SoTiet)}");

            // d. Tổng số môn của mỗi Hệ
            var cauD = dsMon.GroupBy(m => m.He);
            Console.WriteLine("d. Tổng số môn của mỗi Hệ:");
            foreach (var nhom in cauD) Console.WriteLine($"   Hệ {nhom.Key}: {nhom.Count()} môn");

            // e. Nhóm theo Số tiết, sắp xếp giảm dần
            var cauE = dsMon.GroupBy(m => m.SoTiet).OrderByDescending(g => g.Key);
            Console.WriteLine("e. Nhóm theo Số tiết (giảm dần):");
            foreach (var nhom in cauE) Console.WriteLine($"   {nhom.Key} tiết: {nhom.Count()} môn");

            // f. Môn học có số tiết cao nhất
            byte maxTiet = dsMon.Max(m => m.SoTiet);
            var monMax = dsMon.Where(m => m.SoTiet == maxTiet);
            Console.WriteLine($"f. Môn có số tiết cao nhất ({maxTiet} tiết):");
            foreach (var m in monMax) Console.WriteLine($"   - {m.TenMon}");

            // g. Thống kê theo Hệ: Tổng số môn, tổng số tiết, max, min
            var cauG = dsMon.GroupBy(m => m.He).Select(g => new {
                He = g.Key,
                TongMon = g.Count(),
                TongTiet = g.Sum(m => m.SoTiet),
                MaxTiet = g.Max(m => m.SoTiet),
                MinTiet = g.Min(m => m.SoTiet)
            });
            Console.WriteLine("g. Thống kê theo Hệ:");
            foreach (var item in cauG)
                Console.WriteLine($"   Hệ {item.He}: {item.TongMon} môn, Tổng {item.TongTiet} tiết, Max {item.MaxTiet}, Min {item.MinTiet}");

            // h. Liệt kê các môn được phân nhóm theo Hệ
            Console.WriteLine("h. Danh sách môn phân nhóm theo Hệ:");
            foreach (var nhom in dsMon.GroupBy(m => m.He))
            {
                Console.WriteLine($"   [Hệ {nhom.Key}]");
                foreach (var m in nhom) Console.WriteLine($"      - {m.TenMon}");
            }

            // i. Nhóm theo Số tiết, tăng dần
            var cauI = dsMon.GroupBy(m => m.SoTiet).OrderBy(g => g.Key);
            Console.WriteLine("i. Nhóm theo Số tiết (tăng dần):");
            foreach (var nhom in cauI) Console.WriteLine($"   {nhom.Key} tiết: {string.Join(", ", nhom.Select(m => m.MaMon))}");

            // j. Nhóm theo Hệ, sau đó nhóm theo HP2, HP3, HP4, HP5, sắp xếp theo Mã môn
            var cauJ = dsMon.Where(m => m.MaMon.StartsWith("HP"))
                            .GroupBy(m => m.He)
                            .Select(g => new {
                                He = g.Key,
                                NhomHP = g.GroupBy(m => m.MaMon.Substring(0, 3)).OrderBy(x => x.Key)
                            });
            Console.WriteLine("j. Phân nhóm Hệ -> HP2/3/4/5 -> Mã môn:");
            foreach (var he in cauJ)
            {
                Console.WriteLine($"   Hệ {he.He}:");
                foreach (var hp in he.NhomHP)
                    Console.WriteLine($"      {hp.Key}: {string.Join(", ", hp.OrderBy(m => m.MaMon).Select(m => m.MaMon))}");
            }

            // k. Nhóm theo Hệ, chỉ lấy môn có Số tiết > 40, sắp xếp theo Mã môn
            var cauK = dsMon.Where(m => m.SoTiet > 40)
                            .GroupBy(m => m.He);
            Console.WriteLine("k. Nhóm theo Hệ (Môn > 40 tiết, sắp xếp theo Mã môn):");
            foreach (var nhom in cauK)
            {
                Console.WriteLine($"   Hệ {nhom.Key}: {string.Join(", ", nhom.OrderBy(m => m.MaMon).Select(m => m.MaMon))}");
            }
        }

       
        // BÀI 6.2: JOIN VÀ CÁC TOÁN TỬ TẬP HỢP
 
        static void Bai62()
        {
            var dsMon = DuLieu.DS_Mon();
            var dsHe = new List<He>()
            {
                new He { MaHe = "KTV", TenHe = "Kỹ thuật viên" },
                new He { MaHe = "CD", TenHe = "Chuyên đề" },
                new He { MaHe = "QT", TenHe = "Chứng chỉ quốc tế" }
            };

            // a. Dùng join để liệt kê: Tên hệ, Mã môn, Tên môn
            var cauA = from m in dsMon
                       join h in dsHe on m.He equals h.MaHe
                       select new { h.TenHe, m.MaMon, m.TenMon };
            Console.WriteLine("a. Join Tên hệ - Mã môn - Tên môn:");
            foreach (var item in cauA) Console.WriteLine($"   {item.TenHe} | {item.MaMon} | {item.TenMon}");

            // b. Liệt kê các hệ chưa có môn học (Left outer join với GroupJoin + DefaultIfEmpty)
            var cauB = from h in dsHe
                       join m in dsMon on h.MaHe equals m.He into nhomMon
                       from m in nhomMon.DefaultIfEmpty()
                       where m == null
                       select h.TenHe;
            Console.WriteLine("\nb. Các hệ chưa có môn học: " + string.Join(", ", cauB));

            // c. Liệt kê cả hệ chưa có môn học và môn chưa khai báo hệ
            var cauC_HeChuaCoMon = from h in dsHe
                                   join m in dsMon on h.MaHe equals m.He into nhomMon
                                   from m in nhomMon.DefaultIfEmpty()
                                   where m == null
                                   select $"Hệ chưa có môn: {h.TenHe}";
            
            var cauC_MonChuaCoHe = from m in dsMon
                                   join h in dsHe on m.He equals h.MaHe into nhomHe
                                   from h in nhomHe.DefaultIfEmpty()
                                   where h == null
                                   select $"Môn chưa khai báo hệ: {m.TenMon}";

            Console.WriteLine("c. Kết quả:");
            foreach (var item in cauC_HeChuaCoMon) Console.WriteLine("   " + item);
            foreach (var item in cauC_MonChuaCoHe) Console.WriteLine("   " + item);

            // d. Chi liệt kê những hệ chưa có môn học VÀ những môn học chưa khai báo hệ
            // (Đã thực hiện ở câu c, gộp chung kết quả)

            // e. Lấy 5 môn học đầu tiên có số tiết giảm dần
            var cauE = dsMon.OrderByDescending(m => m.SoTiet).Take(5);
            Console.WriteLine("\ne. 5 môn học đầu tiên có số tiết giảm dần:");
            foreach (var m in cauE) Console.WriteLine($"   {m.TenMon} ({m.SoTiet} tiết)");

            // f. Cho biết tổng số môn học của mỗi hệ (Dùng GroupJoin)
            var cauF = from h in dsHe
                       join m in dsMon on h.MaHe equals m.He into nhomMon
                       select new { h.TenHe, TongSoMon = nhomMon.Count() };
            Console.WriteLine("f. Tổng số môn học của mỗi hệ:");
            foreach (var item in cauF) Console.WriteLine($"   {item.TenHe}: {item.TongSoMon} môn");

            // g. Cho biết có bao nhiêu loại Số tiết khác nhau
            Console.WriteLine($"\ng. Có {dsMon.Select(m => m.SoTiet).Distinct().Count()} loại số tiết khác nhau.");

            // h. Tìm môn học đầu tiên có tên bắt đầu bằng "Lập trình"
            var cauH = dsMon.FirstOrDefault(m => m.TenMon.StartsWith("Lập trình"));
            Console.WriteLine($"h. Môn đầu tiên bắt đầu bằng 'Lập trình': {(cauH != null ? cauH.TenMon : "Không có")}");

            // i. Liệt kê các môn theo từng hệ, đánh số thứ tự trong mỗi nhóm
            var cauI = dsMon.GroupBy(m => m.He);
            Console.WriteLine("i. Liệt kê môn theo hệ (có đánh số thứ tự):");
            foreach (var nhom in cauI)
            {
                Console.WriteLine($"   [Hệ {nhom.Key}]");
                int stt = 1;
                foreach (var m in nhom)
                {
                    Console.WriteLine($"      {stt++}. {m.TenMon}");
                }
            }
			
			}
			 class Program
    {
        static void Main(string[] args)
        {
            Console.OutputEncoding = System.Text.Encoding.UTF8;

            Console.WriteLine("================ BÀI 2.1 ================");
            Bai21();

            Console.WriteLine("\n================ BÀI 2.2 ================");
            Bai22();

            Console.WriteLine("\n================ BÀI 3.1 ================");
            Bai31();

            Console.WriteLine("\n================ BÀI 3.2 ================");
            Bai32();

            Console.WriteLine("\n================ BÀI 4.1 ================");
            Bai41();

            Console.WriteLine("\n================ BÀI 5.1 ================");
            Bai51();

            Console.WriteLine("\n================ BÀI 5.2 ================");
            Bai52();

            Console.WriteLine("\n================ BÀI 6.2 ================");
            Bai62();

            Console.ReadLine();
        }
        }
    }
}