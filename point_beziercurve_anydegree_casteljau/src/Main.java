import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
public class Main {
    public static void main(String[] args)
    {
        //introducere grad curba
        Scanner in = new Scanner(System.in);
        System.out.print("Introduceti gradul curbei: ");
        int n = in.nextInt();
        System.out.print("\n");

        //declaram o matrice care va contine toate punctele de forma a cu indicii k si l
        Point[][] a = new Point[n+1][n+1]; //o curba de gradul n are n+1 puncte de control
        for(int i = 0;i<=n;i++)
        {
            for(int j = 0; j<=n;j++)
            {
                Point P1 = new Point(0,0);
                a[i][j]=P1;
            }
        }
        //citim punctele de control
        List<Double> test = new ArrayList<Double>();
        for(int i = 0; i <= n; i++)
        {
            double x =in.nextDouble();
            test.add(x);
            double y =in.nextDouble();
            test.add(y);
        }
        int i =0;
        int k=0;
        //adaugam punctele de control in matrice pe prima coloana a_k^0
        while(i < test.size())
        {
            Point P = new Point (test.get(i),test.get(i+1));
            a[k][0]=P;
            k++;
            i=i+2;
        }
        for(i = 0;i<=n;i++)
        {
            for(int j = 0; j<=n;j++)
            {
                System.out.print(a[i][j].getX()+ " "+a[i][j].getY()+"  ");
            }
            System.out.print("\n\n");
        }
        //citim parametrul t
        System.out.print("Introduceti parametrul t: ");
        double t = in.nextDouble();
        System.out.print("\n");

        //acum aplicam algoritmul lui de Casteljau
        for(int l=1; l <= n; l++)
        {
            for(k = 0; k <= n - l; k++)
            {
                Point a1 = new Point(a[k][l-1].getX(),a[k][l-1].getY());
                a1.multpl1(1-t);
                Point a2 = new Point(a[k+1][l-1].getX(),a[k+1][l-1].getY());
                a2.multpl1(t);
                a1.add1(a2);
                a[k][l].setX(a1.getX());
                a[k][l].setY(a1.getY());
            }
        }

        //afisam matricea
        for(i = 0;i<=n;i++)
        {
            for(int j = 0; j<=n;j++)
            {
                System.out.print(a[i][j].getX()+ " "+a[i][j].getY()+"  ");
            }
            System.out.print("\n\n");
        }
        //afisam r(t)
        System.out.println("r("+t+") este: "+a[0][n].getX()+" "+a[0][n].getY());

        //Derivata de ordinul intai a unei curbe Bezier de ordinul n, cu punctele
        //de control date de vectorii de pozittie a0, . . . , an este data de
        //r'(t) = n(a_1^n-1 - a_0^n-1)

        Point a1 = new Point(a[1][n-1].getX(),a[1][n-1].getY());
        Point a2 = new Point(a[0][n-1].getX(),a[0][n-1].getY());
        a1.sub1(a2);
        a1.multpl1(n);

        //afisam r'(t)
        System.out.println("r'("+t+") este: "+a1.getX()+" "+a1.getY());

    }
}
