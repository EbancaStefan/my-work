import java.util.Scanner;

public class test {
    public static void main(String args[])
    {
        Scanner scan = new Scanner(System.in);


        //Determinarea imaginii unui poliedru,dat prin coordonate omogene ale varfurilor
        //doua puncte P si Q ||  Q(4,7,2) P(2,1,5)   PQ=(4,7,2)-(2,1,5) = (2,6,-3)
        double[] P = {2,1,5};
        double[] Q = {4,7,2};
        double[] PQ = {0,0,0};

        //aici este pe caz general (introducere de coordonate pentru P si Q)
        System.out.println("\nGive the coordinates of the point P:");
        for(int i=0; i<3; i++)
        {
            double coord = scan.nextDouble();
            P[i]=coord;
        }
        System.out.println("\nGive the coordinates of the point Q:");
        for(int i=0; i<3; i++)
        {
            double coord = scan.nextDouble();
            Q[i]=coord;
        }
        System.out.print("\n");

        //determinarea lui PQ
        System.out.print("PQ=(");
        for (int i = 0; i<P.length; i++)
        {
            PQ[i]=Q[i]-P[i];
            System.out.print(PQ[i]+" ");
        }
        System.out.print(")\n");

        //Determinam versorul asociat acestei axe, R(r1,r2,r3) = (2,6,3) / ||(2,6,3)||
        double[] R={0,0,0};
        double norm=Math.sqrt(PQ[0]*PQ[0]+PQ[1]*PQ[1]+PQ[2]*PQ[2]);
        System.out.print("||PQ||=");
        System.out.print(norm+"\n");
        R[0]=PQ[0]/norm;//r1
        R[1]=PQ[1]/norm;//r2
        R[2]=PQ[2]/norm;//r3
        System.out.print("R=(");
        for (int i = 0; i<3; i++)
        {
            System.out.print(R[i]+" ");
        }
        System.out.print(")\n");

        //vom determina matricea rotatiei de unghi teta(x) in jurul axei Ox
        double sin_teta_x = R[1]/(Math.sqrt(R[1]*R[1]+R[2]*R[2])); //sin(tetax) = r2/(sqrt(r2^2+r3^2))
        double cos_teta_x = R[2]/(Math.sqrt(R[1]*R[1]+R[2]*R[2])); //cos(tetax) = r3/(sqrt(r2^2+r3^2))
        Matrix Rot_Ox = new Matrix(4,4);
        Rot_Ox.rotatie_Ox(cos_teta_x,sin_teta_x);

        //vom determina matricea rotatiei de unghi teta(y) in jurul axei Oy
        double sin_teta_y = R[0]; // sin(tetay) = r1
        double cos_teta_y = Math.sqrt(R[1]*R[1]+R[2]*R[2]); //cos(tetay) = sqrt(r2^2+r3^2)
        Matrix Rot_Oy = new Matrix(4,4);
        Rot_Oy.rotatie_Oy(cos_teta_y,sin_teta_y);

        //vom determina matricea rotatiei de unghi -teta(x) in jurul axei Ox
        Matrix Rot_minus_Ox = new Matrix(4,4);
        Rot_minus_Ox.rotatie_Ox(cos_teta_x,-sin_teta_x);

        //vom determina matricea rotatiei de unghi -teta(y) in jurul axei Oy
        Matrix Rot_minus_Oy = new Matrix(4,4);
        Rot_minus_Oy.rotatie_Oy(cos_teta_y,-sin_teta_y);

        //Calculam translatia T(-p1,-p2,-p3) care duce punctul P in origine
        //P(p1,p2,p3)
        Matrix translatie_origine = new Matrix(4,4);
        double[] puncte = {-P[0],-P[1],-P[2]};
        translatie_origine.translatie(puncte);

        //Determinam matricea de rotatie de X grade
        System.out.print("\nGive the angle of rotation:");
        double unghi = scan.nextDouble();
        //double unghi = 30;
        Matrix rotatie_unghi = new Matrix(4,4);
        rotatie_unghi.rotatie_unghi(unghi);

        //Determinam translatia T1(p1,p2,p3)
        //P(p1,p2,p3)
        Matrix translatie_inapoi = new Matrix(4,4);
        double[] puncte1 = {P[0],P[1],P[2]};
        translatie_inapoi.translatie(puncte1);

        Matrix C = new Matrix(4,4);

        //Printam toate matricele
        System.out.println("\nT(x0,y0,z0) is");
        translatie_inapoi.show();
        System.out.println("\nRotx(-TetaX) is");
        Rot_minus_Ox.show();
        System.out.println("\nRoty(TetaY) is");
        Rot_Oy.show();
        System.out.println("\nRot(unghi) is");
        rotatie_unghi.show();
        System.out.println("\nRoty(-TetaY) is");
        Rot_minus_Oy.show();
        System.out.println("\nRotx(TetaX) is");
        Rot_Ox.show();
        System.out.println("\nT(-x0,-y0,-z0) is");
        translatie_origine.show();

        System.out.println("\nR = T(x0,y0,z0) * Rotx(-TetaX) * Roty(TetaY) * Rot(unghi) * Roty(-TetaY) * Rotx(TetaX) * T(-x0,-y0,-z0)");
        //Facem inmultirea dintre (x0,y0,z0) * Rotx(-TetaX)
        System.out.println("\nT(x0,y0,z0) * Rotx(-TetaX)=");
        Matrix rot_delta = new Matrix(4,4);
        rot_delta = translatie_inapoi.times(Rot_minus_Ox);
        rot_delta.show();
        //Facem inmultirea dintre T(x0,y0,z0) * Rotx(-TetaX) * Roty(TetaY)
        System.out.println("\nT(x0,y0,z0) * Rotx(-TetaX) * Roty(TetaY)=");
        rot_delta = rot_delta.times(Rot_Oy);
        rot_delta.show();
        //Facem inmultirea dintre T(x0,y0,z0) * Rotx(-TetaX) * Roty(TetaY) * Rot(unghi)
        System.out.println("\nT(x0,y0,z0) * Rotx(-TetaX) * Roty(TetaY) * Rot(unghi)=");
        rot_delta = rot_delta.times(rotatie_unghi);
        rot_delta.show();
        //Facem inmultirea dintre T(x0,y0,z0) * Rotx(-TetaX) * Roty(TetaY) * Rot(unghi) * Roty(-TetaY)
        System.out.println("\nT(x0,y0,z0) * Rotx(-TetaX) * Roty(TetaY) * Rot(unghi) * Roty(-TetaY)=");
        rot_delta = rot_delta.times(Rot_minus_Oy);
        rot_delta.show();
        //Facem inmultirea dintre T(x0,y0,z0) * Rotx(-TetaX) * Roty(TetaY) * Rot(unghi) * Roty(-TetaY) * Rotx(TetaX)
        System.out.println("\nT(x0,y0,z0) * Rotx(-TetaX) * Roty(TetaY) * Rot(unghi) * Roty(-TetaY) * Rotx(TetaX)=");
        rot_delta = rot_delta.times(Rot_Ox);
        rot_delta.show();
        //Facem inmultirea dintre T(x0,y0,z0) * Rotx(-TetaX) * Roty(TetaY) * Rot(unghi) * Roty(-TetaY) * Rotx(TetaX) * T(-x0,-y0,-z0)
        System.out.println("\nT(x0,y0,z0) * Rotx(-TetaX) * Roty(TetaY) * Rot(unghi) * Roty(-TetaY) * Rotx(TetaX) * T(-x0,-y0,-z0)=");
        rot_delta = rot_delta.times(translatie_origine);
        rot_delta.show();

        //introducem numar de coordonate ale poliedrului si coordonatele acestuia
        System.out.println("\nIntroduceti numarul de varfuri ale poliedrului:");
        int nr = scan.nextInt();
        Matrix poly = new Matrix(4,nr);
        System.out.println("\nIntroduceti coordonatele poliedrului:");
        char b ='A';
        for(int j=0;j<nr;j++) {
            System.out.println(b);
            for (int i = 0; i < 3; i++) {
                poly.data[i][j] = scan.nextDouble();
                poly.data[3][j]=1;
            }
            b+=1;
            System.out.println("");
        }
        System.out.println("The resulting matrix is");
        poly.show();
        System.out.println("");

        //Determinam imaginea poliedrului
        Matrix imagine = rot_delta.times(poly);
        System.out.println("The matrix of the image is");
        imagine.show();
        System.out.println("");

        //Afisam coordonatele imaginii
        char a ='A';
        for(int j=0;j<nr;j++) {
            System.out.println(a+"'");
            for (int i = 0; i < 3; i++) {
                System.out.println(imagine.data[i][j]);
            }
            a+=1;
            System.out.println("");
        }
    }
}
