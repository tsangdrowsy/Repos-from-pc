import java.util.ArrayList;
import java.util.Random;

public class BaiTapThuBa {
        public static void main(String[] args)
        {
            ArrayList<Integer> ds = new ArrayList<>();
            for(int i=0;i<10;i++)
            {
                Random rd = new Random();
                Integer x = new Integer(rd.nextInt(100));
                ds.add(x);
                System.out.print(ds.get(i)+" ");
            }
            System.out.println("\nTrong ds co chua so 50 khong: "+ds.contains(50));
            int[]mlc=new int[10];
            for(int i=0;i<10;i++)
            {
                Random re= new Random();
                mlc[i]=re.nextInt(100);
                System.out.print(mlc[i]+" ");
        
            }       
            for(int i=0;i<mlc.length;i++)
            {
                if(mlc[i]==50)
                        System.out.println("\nTrong ds co chua so 50 : true");
                    System.out.println("\nTrong ds co chua so 50 : false");
            


            }
            
        }

} 
