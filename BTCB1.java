import java.util.Scanner;



public class BTCB1{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Bai 1");
        bai1a(sc);
        bai1b(sc);
        bai1c(sc);
        bai1d(sc);
        sc.close();
    }
    public static void bai1a(Scanner sc){
        System.out.print("NhapChieuDai: ");
        double dai = sc.nextDouble();
        System.out.print("NhapChieuRong: ");
        double rong = sc.nextDouble();
        double chuvi = 2*(dai+rong);
        double dientich = dai*rong;
        System.out.println("Chu vi: "+chuvi);
        System.out.println("Dien tich: "+dientich);
    }
     public static void bai1b(Scanner sc) {
        System.out.print("Nhap 3 so nguyen abc: ");
        int a = sc.nextInt(), b = sc.nextInt(),c = sc.nextInt();
        int max = Math.max(a, Math.max(b, c));
        int min = Math.min(a, Math.min(b, c));
        System.out.println("Max: "+max);
        System.out.println("Min: "+min);
     }
      public static void bai1c(Scanner sc) {
        System.out.print("Nhap so nguyen duong n: ");
        int n = sc.nextInt();
        System.out.print("Cac uoc cua " + n + ": ");
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) System.out.print(i + " ");
        }
        System.out.println();
    }
       public static void bai1d(Scanner sc) {
        System.out.print("Nhap so nguyen duong x: ");
        int x = sc.nextInt();
        int count = String.valueOf(x).length();
        System.out.println("So chu so cua x la: " + count);
    }





}