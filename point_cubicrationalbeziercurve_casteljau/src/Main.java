import java.awt.*;
import java.awt.geom.Point2D;
import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        //pentru testare am folosit punctele
        /*
        Point2D b0=new Point2D.Double(0,0);
        Point2D b1=new Point2D.Double(1,0);
        Point2D b2=new Point2D.Double(2,2);
        Point2D b3=new Point2D.Double(3,0);
        */
        Scanner in = new Scanner(System.in);
        System.out.println("Introduceti coordonatele punctelor: (4 puncte)");
        System.out.print("\nb0\n");
        double b0x = in.nextDouble();
        double b0y = in.nextDouble();
        Point2D b0=new Point2D.Double(0,0);
        b0.setLocation(b0x,b0y);

        System.out.print("\nb1\n");
        double b1x = in.nextDouble();
        double b1y = in.nextDouble();
        Point2D b1=new Point2D.Double(0,0);
        b1.setLocation(b1x,b1y);

        System.out.print("\nb2\n");
        double b2x = in.nextDouble();
        double b2y = in.nextDouble();
        Point2D b2=new Point2D.Double(0,0);
        b2.setLocation(b2x,b2y);

        System.out.print("\nb3\n");
        double b3x = in.nextDouble();
        double b3y = in.nextDouble();
        Point2D b3=new Point2D.Double(0,0);
        b3.setLocation(b3x,b3y);

        //si ponderile
        /*double w0=1,w1=3,w2=2,w3=1;*/
        System.out.println("Introduceti ponderile:");
        double w0= in.nextDouble();
        double w1= in.nextDouble();
        double w2= in.nextDouble();
        double w3= in.nextDouble();
        double[][] ponderi=new double[4][4];
        for(int i = 0; i < ponderi.length; i++)
        {
            for(int j =0; j< ponderi.length; j++)
            {
                ponderi[i][j]=0;
            }
        }
        //si t-ul
        /*double t = 0.5;  // 1/2*/
        System.out.println("Introduceti variabila t:");
        double t = in.nextDouble();

        //punem ponderile initiale
        ponderi[0][0]=w0;
        ponderi[1][0]=w1;
        ponderi[2][0]=w2;
        ponderi[3][0]=w3;
        //calculam restul ponderilor
            //w[i][j] = (1-t)*w[i][j-1] +t*w[i+1][j-1];   j=1..n   i=0...n-j   n=3
        ponderi[0][1] = (1-t)*ponderi[0][0] + t*ponderi[1][0]; //i=0  j=1
        ponderi[1][1] = (1-t)*ponderi[1][0] + t*ponderi[2][0]; //i=1  j=1
        ponderi[2][1] = (1-t)*ponderi[2][0] + t*ponderi[3][0]; //i=2  j=1
            //i devine 0 iar j-ul creste cu 1
        ponderi[0][2] = (1-t)*ponderi[0][1] + t*ponderi[1][1]; //i=0  j=2
        ponderi[1][2] = (1-t)*ponderi[1][1] + t*ponderi[2][1]; //i=1  j=2
            //i devine 0 iar j-ul creste cu 1
        ponderi[0][3] = (1-t)*ponderi[0][2] + t*ponderi[1][2]; //i=0  j=3

        //afisare ponderi
        System.out.println("Ponderile sunt:");
        for(int i = 0; i < ponderi.length; i++)
        {
            for(int j =0; j< ponderi.length-i; j++)
            {
                System.out.print("W"+"["+i+"]"+"["+j+"]"+"= "+ponderi[i][j]+" | ");
            }
            System.out.print("\n");
        }

        //punem punctele intiale
        Point2D[][] puncte = new Point2D.Double[4][4];
        for(int i = 0; i < puncte.length; i++)
        {
            for(int j =0; j< puncte.length; j++)
            {
                puncte[i][j]= new Point2D.Double(0,0);
            }
        }
        puncte[0][0]=b0;
        puncte[1][0]=b1;
        puncte[2][0]=b2;
        puncte[3][0]=b3;
        //calculam restul punctelor
            //b[i][j]=(1-t)*w[i][j-1]/w[i][j]*b[i][j-1] + t*w[i+1][j-1]/w[i][j]*b[i+1][j-1]
        double x01=(1-t)*ponderi[0][0]/ponderi[0][1]*puncte[0][0].getX() + t*ponderi[1][0]/ponderi[0][1]*puncte[1][0].getX();
        double y01=(1-t)*ponderi[0][0]/ponderi[0][1]*puncte[0][0].getY() + t*ponderi[1][0]/ponderi[0][1]*puncte[1][0].getY();
        puncte[0][1].setLocation(x01,y01);

        double x11=(1-t)*ponderi[1][0]/ponderi[1][1]*puncte[1][0].getX() + t*ponderi[2][0]/ponderi[1][1]*puncte[2][0].getX();
        double y11=(1-t)*ponderi[1][0]/ponderi[1][1]*puncte[1][0].getY() + t*ponderi[2][0]/ponderi[1][1]*puncte[2][0].getY();
        puncte[1][1].setLocation(x11,y11);

        double x21=(1-t)*ponderi[2][0]/ponderi[2][1]*puncte[2][0].getX() + t*ponderi[3][0]/ponderi[2][1]*puncte[3][0].getX();
        double y21=(1-t)*ponderi[2][0]/ponderi[2][1]*puncte[2][0].getY() + t*ponderi[3][0]/ponderi[2][1]*puncte[3][0].getY();
        puncte[2][1].setLocation(x21,y21);

        double x02=(1-t)*ponderi[0][1]/ponderi[0][2]*puncte[0][1].getX() + t*ponderi[1][1]/ponderi[0][2]*puncte[1][1].getX();
        double y02=(1-t)*ponderi[0][1]/ponderi[0][2]*puncte[0][1].getY() + t*ponderi[1][1]/ponderi[0][2]*puncte[1][1].getY();
        puncte[0][2].setLocation(x02,y02);

        double x12=(1-t)*ponderi[1][1]/ponderi[1][2]*puncte[1][1].getX() + t*ponderi[2][1]/ponderi[1][2]*puncte[2][1].getX();
        double y12=(1-t)*ponderi[1][1]/ponderi[1][2]*puncte[1][1].getY() + t*ponderi[2][1]/ponderi[1][2]*puncte[2][1].getY();
        puncte[1][2].setLocation(x12,y12);

        //r(t)
        double x03=(1-t)*ponderi[0][2]/ponderi[0][3]*puncte[0][2].getX() + t*ponderi[1][2]/ponderi[0][3]*puncte[1][2].getX();
        double y03=(1-t)*ponderi[0][2]/ponderi[0][3]*puncte[0][2].getY() + t*ponderi[1][2]/ponderi[0][3]*puncte[1][2].getY();
        puncte[0][3].setLocation(x03,y03);

        //afisare puncte
        System.out.println("\nPunctele sunt:");
        for(int i = 0; i < puncte.length; i++)
        {
            for(int j =0; j< puncte.length-i; j++)
            {
                System.out.print("b"+"["+i+"]"+"["+j+"]"+"= ("+puncte[i][j].getX()+","+puncte[i][j].getY()+") | ");
            }
            System.out.print("\n");
        }
        System.out.print("\nIar r("+t+") este: ("+puncte[0][3].getX()+","+puncte[0][3].getY()+")");

        System.out.println("\n*To exit the program read anything*");
        in.next();
    }
}
