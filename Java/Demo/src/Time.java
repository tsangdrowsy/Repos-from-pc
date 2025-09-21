public class Time {
    private int gio, phut, giay;

    public Time() {
        this.gio = 0;
        this.phut = 0;
        this.giay = 0;
    }

    public Time(int gio, int phut, int giay) {
        this.gio = (gio >= 0 && gio <= 23) ? gio : 0;
        this.phut = (phut >= 0 && phut <= 59) ? phut : 0;
        this.giay = (giay >= 0 && giay <= 59) ? giay : 0;
    }

    public Time(Time t) {
        this.gio = t.gio;
        this.phut = t.phut;
        this.giay = t.giay;
    }

    public boolean isValid() {
        return gio >= 0 && gio <= 23 && phut >= 0 && phut <= 59 && giay >= 0 && giay <= 59;
    }

    public void xuat24h() {
        System.out.printf("%02d:%02d:%02d\n", gio, phut, giay);
    }

    public void xuat12h() {
        String ampm = (gio < 12) ? "AM" : "PM";
        int h = gio % 12;
        if (h == 0) h = 12;
        System.out.printf("%02d:%02d:%02d %s\n", h, phut, giay, ampm);
    }

    public void tangGio(int soGiay) {
        int total = gio * 3600 + phut * 60 + giay + soGiay;
        total %= 86400;
        gio = total / 3600;
        phut = (total % 3600) / 60;
        giay = total % 60;
    }

    public void tangGio(int soGiay, String kieuGio) {
        tangGio(soGiay);
        if (kieuGio.equals("24")) xuat24h();
        else xuat12h();
    }

    public void giamGio(int soGiay) {
        int total = gio * 3600 + phut * 60 + giay - soGiay;
        while (total < 0) total += 86400;
        gio = total / 3600;
        phut = (total % 3600) / 60;
        giay = total % 60;
    }

    public void giamGio(int soGiay, String kieuGio) {
        giamGio(soGiay);
        if (kieuGio.equals("24")) xuat24h();
        else xuat12h();
    }

    public int getGio() { return gio; }
    public int getPhut() { return phut; }
    public int getGiay() { return giay; }
      public static void main(String[] args) {
        Time t1 = new Time(10, 30, 45);
        System.out.print("Thoi gian ban dau (24h): ");
        t1.xuat24h();

        System.out.print("Thoi gian ban dau (12h): ");
        t1.xuat12h();

        System.out.println("\nTang 5000 giay:");
        t1.tangGio(5000);
        t1.xuat24h();

        System.out.println("Giam 3000 giay:");
        t1.giamGio(3000);
        t1.xuat24h();

        System.out.println("\nTang 3600 giay theo 12h:");
        t1.tangGio(3600, "12");

        System.out.println("Giam 7200 giay theo 24h:");
        t1.giamGio(7200, "24");
    }

}