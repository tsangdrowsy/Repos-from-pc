
import java.util.Scanner;
public class HCN2 {

    private double dai, rong;

    public HCN2() {
        dai = rong = 1;
    }

    public HCN2(double dai, double rong) {
        this.dai = dai;
        this.rong = rong;
    }

    public HCN2(HCN2 a) {
        this.dai = a.dai;
        this.rong = a.rong;
    }

    public double tinhChuVi() {
        return 2 * (dai + rong);
    }

    public double tinhDienTich() {
        return dai * rong;
    }

    public double tinhDuongCheo() {
        return Math.sqrt(dai * dai + rong * rong);
    }

    public void nhap() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Nhap chieu dai: ");
        dai = sc.nextDouble();
        System.out.print("Nhap chieu rong: ");
        rong = sc.nextDouble();
        sc.close();
    }

    public void xuat() {
        System.out.println("Chieu dai: " + dai);
        System.out.println("Chieu rong: " + rong);
        System.out.println("Chu vi: " + tinhChuVi());
        System.out.println("Dien tich: " + tinhDienTich());
        System.out.println("Duong cheo: " + tinhDuongCheo());
    }

    public void changeSize(int tx, int ty, int kieu) {
        if (kieu == 1) {
            dai += tx;
            rong += ty;
        } else {
            dai = Math.max(1, dai - tx);
            rong = Math.max(1, rong - ty);
        }
    }

    public void changeSize(HCN2 a, int kieu) {
        if (kieu == 1) {
            dai += a.dai;
            rong += a.rong;
        } else {
            dai = Math.max(1, dai - a.dai);
            rong = Math.max(1, rong - a.rong);
        }
    }
     public static void main(String[] args) {
        HCN2 hcn = new HCN2();
        System.out.println("Nhap thong tin hinh chu nhat:");
        hcn.nhap();

        System.out.println("\nThong tin ban dau:");
        hcn.xuat();

        System.out.println("\nThay doi kich thuoc: tang 2 chieu len 3 va 4");
        hcn.changeSize(3, 4, 1);
        hcn.xuat();

        System.out.println("\nTao HCN moi de cong vao:");
        HCN2 hcnn = new HCN2(2, 2);
        hcn.changeSize(hcnn, 1);
        hcn.xuat();

        System.out.println("\nGiam kich thuoc bang HCN moi:");
        hcn.changeSize(hcnn, 0);
        hcn.xuat();
    }

}

