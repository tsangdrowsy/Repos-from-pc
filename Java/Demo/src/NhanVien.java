public class NhanVien {
    private String hoTen;
    private int soNgayCong;
    private char xepLoai;
    private static final int LUONG_NGAY = 200_000;

    public NhanVien(String hoTen, int soNgayCong) {
        this.hoTen = hoTen;
        this.soNgayCong = soNgayCong;
        this.xepLoai = tinhXepLoai();
    }

    public String getHoTen() {
        return hoTen;
    }

    public void setHoTen(String hoTen) {
        this.hoTen = hoTen;
    }

    public int getSoNgayCong() {
        return soNgayCong;
    }

    public void setSoNgayCong(int soNgayCong) {
        this.soNgayCong = soNgayCong;
        this.xepLoai = tinhXepLoai(); 
    }

    public char getXepLoai() {
        return xepLoai;
    }

    private char tinhXepLoai() {
        if (soNgayCong > 26) return 'A';
        else if (soNgayCong >= 22) return 'B';
        else return 'C';
    }

    public double tinhLuong() {
        double heSoThuong = switch (xepLoai) {
            case 'A' -> 1.05;
            case 'B' -> 1.02;
            default -> 1;
        };
        return soNgayCong * LUONG_NGAY * heSoThuong;
    }

    public void inThongTin() {
        System.out.println("Ho ten: " + hoTen);
        System.out.println("So ngay cong: " + soNgayCong);
        System.out.println("Xep loai: " + xepLoai);
        System.out.println("Luong: " + tinhLuong() + " dong");
    }
}