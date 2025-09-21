
 import java.util.Scanner;

public class NuocGiaiKhat {
    private String tenHang;
    private String donViTinh;
    private int soLuong;
    private float donGia;
    private static float thueVAT = 1.1f; 


    public NuocGiaiKhat(String tenHang, String donViTinh, int soLuong, float donGia) {
        this.tenHang = tenHang;
        this.donViTinh = kiemTraDVT(donViTinh);
        this.soLuong = (soLuong > 0) ? soLuong : 1;
        this.donGia = (donGia > 0) ? donGia : 1;
    }


    private String kiemTraDVT(String dvt) {
        return switch (dvt.toLowerCase()) {
            case "thùng", "chai", "lon" -> dvt.toLowerCase();
            default -> "kết";
        };
    }

    public String getTenHang() { return tenHang; }
    public void setTenHang(String tenHang) { this.tenHang = tenHang; }

    public String getDonViTinh() { return donViTinh; }
    public void setDonViTinh(String donViTinh) { this.donViTinh = kiemTraDVT(donViTinh); }

    public int getSoLuong() { return soLuong; }
    public void setSoLuong(int soLuong) { this.soLuong = (soLuong > 0) ? soLuong : 1; }

    public float getDonGia() { return donGia; }
    public void setDonGia(float donGia) { this.donGia = (donGia > 0) ? donGia : 1; }

    public static float getThueVAT() { return thueVAT; }
    public static void setThueVAT(float vat) { thueVAT = (vat > 0) ? vat : 1.1f; }

    public float tinhThanhTien() {
        return switch (donViTinh) {
            case "thùng" -> soLuong * donGia * thueVAT;
            case "chai" -> soLuong * (donGia / 20) * thueVAT;
            case "lon" -> soLuong * (donGia / 24) * thueVAT;
            default -> 0;
        };
    }

    public void nhapThongTin() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Nhap ten hang: ");
        tenHang = sc.nextLine();

        System.out.print("Nhap DVT (thung/chai/lon): ");
        donViTinh = kiemTraDVT(sc.nextLine());

        System.out.print("Nhap SL (>0): ");
        int sl = sc.nextInt();
        soLuong = (sl > 0) ? sl : 1;

        System.out.print("Nhap don gia (>0): ");
        float dg = sc.nextFloat();
        donGia = (dg > 0) ? dg : 1;
        sc.close();
    }

    public void xuatThongTin() {
        System.out.println("Ten hang: " + tenHang);
        System.out.println("DVT: " + donViTinh);
        System.out.println("SL: " + soLuong);
        System.out.println("DG: " + donGia);
        System.out.println("Thue VAT: " + thueVAT);
        System.out.println("Thanh tien: " + tinhThanhTien());
    }

    @Override
    protected void finalize() throws Throwable {
        System.out.println("da huy: " + tenHang);
        super.finalize();
    }
     public static void main(String[] args) {
        NuocGiaiKhat.setThueVAT(1.08f); 

        NuocGiaiKhat ngk = new NuocGiaiKhat("Pepsi", "chai", 100, 8000);
        ngk.xuatThongTin();

        System.out.println("\nNhap mat hang moi");
        NuocGiaiKhat ngk2 = new NuocGiaiKhat("", "", 0, 0);
        ngk2.nhapThongTin();
        ngk2.xuatThongTin();
    }

}

