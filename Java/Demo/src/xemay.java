

public class xemay{
    private String NhanHieu;
    private String MauSac;

    public void XuatThongTin(){
        System.out.println("Nhan hieu xe la: "+NhanHieu);
        System.out.println("Mau sac la: "+MauSac);
    }
    public String getNhanHieu(){
        return NhanHieu;
    }
    public void setNhanHieu(String NhanHieu){
         this.NhanHieu=NhanHieu;
    }
    public String getMauSau(){
        return MauSac;
    }
    public void setMauSac(String MauSac){
        this.MauSac=MauSac;
    }

    

    public void xuatTT(){
        System.out.println("Nhan hieu la: "+this.NhanHieu);
        System.out.println("Mau Sac la: "+this.MauSac);
    }
    public static void Main(String args[])
    {
        xemay Xemay=new xemay();
        Xemay.setNhanHieu("Exciter");
        Xemay.setMauSac("Mau do");
        Xemay.xuatTT();

    }
}


