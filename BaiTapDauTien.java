import java.util.Scanner;

public class BaiTapDauTien{
    public static void main(String[] args)
{
    float  r, cv, dt;
    Scanner scan=new Scanner(System.in);
    System.out.print("nhap ban kinh: ");
    r=scan.nextFloat();

    cv=(float)Math.PI *2*r;
    dt=(float)Math.PI *r*r;

    System.out.println("chu vi la: "+cv);
    System.out.println("dien tich la: "+dt);
    scan.close();
}
}

