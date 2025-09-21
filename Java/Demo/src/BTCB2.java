import java.util.*;

public class BTCB2{
public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
     
        System.out.println("\nBai 2");
        ArrayList<Integer> a = new ArrayList<>();
        bai2a(a, sc);
        bai2b(a);
        bai2c(a, sc);
        bai2d(a);
        bai2e(a, sc);
        bai2f(a);
}
     public static void bai2a(ArrayList<Integer> a, Scanner sc) {
        extracted();
        for (int i = 0; i < 5; i++) {
            System.out.print("a["+i+"] = ");
            a.add(sc.nextInt());
        }
        System.out.println("Mang a: "+a);
    }
     private static void extracted() {
        System.out.println("Nhap 5 so nguyen cho ArrayList: ");
     }

    public static void bai2b(ArrayList<Integer> a) {
        Random rand = new Random();
        while (a.size() < 15) {
            a.add(rand.nextInt(100));
        }
        System.out.println("Mang sau khi them so ngau nhien <100 (>=15 phan tu): " + a);
    }

    public static void bai2c(ArrayList<Integer> a, Scanner sc) {
        System.out.println("Nhap them 3 phan tu:");
        for (int i = 0; i < 3; i++) {
            System.out.print("Phần tử " + (i + 1) + ": ");
            a.add(sc.nextInt());
        }
        System.out.println("Mang sau khi them: " + a);
    }

    public static void bai2d(ArrayList<Integer> a) {
        a.removeIf(x -> x % 5 == 0);
        System.out.println("Mang sau khi xoa boi cua 5: " + a);
    }

    public static void bai2e(ArrayList<Integer> a, Scanner sc) {
        System.out.print("Nhap so x can tim: ");
        int x = sc.nextInt();
        if (a.contains(x)) {
            System.out.println("Mang co chua so " + x);
        } else {
            System.out.println("Mang khong chua so " + x);
        }
    }
     public static void bai2f(ArrayList<Integer> a) {
        System.out.print("Cac phan tu co chu so hang chuc la 1: ");
        for (int num : a) {
            if (num >= 10 && (num / 10) % 10 == 1) {
                System.out.print(num + " ");
            }
        }
        System.out.println();
    }
}