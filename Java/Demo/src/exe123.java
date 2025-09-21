public class exe123 {
    public static void main(String[] args) {
        HCN hcn = new HCN(4, 6);
        System.out.println("HCN - Chu vi: " + hcn.tinhChuVi());
        System.out.println("HCN - Dien tich: " + hcn.tinhDienTich());

        TamGiac tg = new TamGiac(3, 4, 5);
        System.out.println("Tam giac - Chu vi: " + tg.tinhChuVi());
        System.out.println("Tam giac - Dien tich: " + tg.tinhDienTich());

        NhanVien nv = new NhanVien("Tran Van A", 25);
        nv.inThongTin();
    }

}
