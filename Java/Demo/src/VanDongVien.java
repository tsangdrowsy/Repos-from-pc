import java.util.Scanner;

public class VanDongVien {
    private String maSo, hoTen;
    private int soAo;
    private Time batDau, ketThuc;
    private static final Time thanhTichChuan = new Time(1, 30, 0); // 1 giờ 30 phút

    public VanDongVien() {
        this.maSo = "";
        this.hoTen = "";
        this.soAo = 0;
        this.batDau = new Time();
        this.ketThuc = new Time();
    }

    public VanDongVien(String maSo, String hoTen, int soAo, Time batDau, Time ketThuc) {
        this.maSo = maSo;
        this.hoTen = hoTen;
        this.soAo = soAo;
        this.batDau = new Time(batDau);
        this.ketThuc = new Time(ketThuc);
    }

    public VanDongVien(VanDongVien v) {
        this.maSo = v.maSo;
        this.hoTen = v.hoTen;
        this.soAo = v.soAo;
        this.batDau = new Time(v.batDau);
        this.ketThuc = new Time(v.ketThuc);
    }

    public void nhap() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Nhap ma so: ");
        maSo = sc.nextLine();
        System.out.print("Nhap ho ten: ");
        hoTen = sc.nextLine();
        System.out.print("Nhap so ao: ");
        soAo = sc.nextInt();

        System.out.println("Nhap thoi gian bat dau : ");
        int h = sc.nextInt(), m = sc.nextInt(), s = sc.nextInt();
        batDau = new Time(h, m, s);

        System.out.println("Nhap thoi gian ket thuc: ");
        h = sc.nextInt();
        m = sc.nextInt();
        s = sc.nextInt();
        ketThuc = new Time(h, m, s);
        sc.close();
    }

    public void xuat() {
        System.out.println("MS: " + maSo);
        System.out.println("Ho ten: " + hoTen);
        System.out.println("So ao: " + soAo);
        System.out.print("Thoi gian bat dau: ");
        batDau.xuat24h();
        System.out.print("Thoi gian ket thuc: ");
        ketThuc.xuat24h();
        System.out.print("Thanh tich: ");
        tinhThanhTich().xuat24h();
        System.out.println("Dat chuan: " + (datChuan() ? "Dat" : "Khong dat"));
    }

    public Time tinhThanhTich() {
        int start = batDau.getGio() * 3600 + batDau.getPhut() * 60 + batDau.getGiay();
        int end = ketThuc.getGio() * 3600 + ketThuc.getPhut() * 60 + ketThuc.getGiay();
        int diff = end - start;
        if (diff < 0)
            diff += 86400; // nếu qua ngày

        int h = diff / 3600;
        int m = (diff % 3600) / 60;
        int s = diff % 60;
        return new Time(h, m, s);
    }

    public boolean datChuan() {
        Time t = tinhThanhTich();
        int thoiGianThi = t.getGio() * 3600 + t.getPhut() * 60 + t.getGiay();
        int chuan = thanhTichChuan.getGio() * 3600 + thanhTichChuan.getPhut() * 60 + thanhTichChuan.getGiay();
        return thoiGianThi <= chuan;
    }

    public boolean thoiGianHopLe() {
        return batDau.isValid() && ketThuc.isValid();
    }

    public static void main(String[] args) {
        VanDongVien vdv = new VanDongVien();
        System.out.println("Nhap thong tin VDV:");
        vdv.nhap();

        if (!vdv.thoiGianHopLe()) {
            System.out.println("❌ Thoi gian nhap khong hop le");
            return;
        }

        System.out.println("\nThong tin van đong vien:");
        vdv.xuat();
    }
}