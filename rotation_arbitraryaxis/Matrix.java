public class Matrix {
    public int M;             // numarul de linii
    public  int N;             // numarul de coloane
    public double[][] data;



    // creare matrice de M pe N
    public Matrix(int M, int N) {
        this.M = M;
        this.N = N;
        data = new double[M][N];
    }
    // creare matrice dintr-un array bidimensional
    public Matrix(double[][] data) {
        M = data.length;
        N = data[0].length;
        this.data = new double[M][N];
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
                this.data[i][j] = data[i][j];
    }
    //metoda care afiseaza o matrice
    public void show() {
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++)
                System.out.print(data[i][j]+" ");
            System.out.print("\n");
        }
    }
    // copy constructor
    public Matrix(Matrix A) { this(A.data); }

    //C=A+B
    public Matrix add(Matrix A,Matrix B) {
        Matrix C = new Matrix(M, N);
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
                C.data[i][j] = A.data[i][j] + B.data[i][j];
        return C;
    }

    //C=A-B
    public Matrix minus(Matrix A,Matrix B) {
        Matrix C = new Matrix(M, N);
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
                C.data[i][j] = A.data[i][j] - B.data[i][j];
        return C;
    }

    // return C = A * B
    public Matrix times(Matrix B) {
        Matrix A = this;
        Matrix C = new Matrix(A.M, B.N);
        for (int i = 0; i < C.M; i++)
            for (int j = 0; j < C.N; j++)
                for (int k = 0; k < A.N; k++)
                    C.data[i][j] += (A.data[i][k] * B.data[k][j]);
        return C;
    }

    //Creare matrice translatie
    public boolean translatie(double[] numere)
    {
        //Translatia va avea loc doar in cazul in care numarul de valori este mai mic cu 1 decat numarul de linii
        if(numere.length==this.M-1)
        {
            //Vom pune in matrice pe diagonala principala valoarea 1 iar pe celelalte pozitii valoarea 0
            for (int i = 0; i < M; i++)
                for (int j = 0; j < N; j++)
                    if (i == j)
                        this.data[i][j]=1;
                    else
                        this.data[i][j]=0;
            for (int i = 0; i < numere.length; i++) {
                this.data[i][this.N-1] = numere[i];
            }
            return true;
        }
        return false;
    }

    //Creare matrice rotatie Ox
    public void rotatie_Ox(double cosx,double sinx)
    {
            //Vom pune in matrice pe diagonala principala valoarea 1 iar pe celelalte pozitii valoarea 0
            for (int i = 0; i < M; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    if (i == j)
                        this.data[i][j] = 1;
                    else
                        this.data[i][j] = 0;
                }
            }
            this.data[1][1]=cosx;
            this.data[1][2]=-sinx;
            this.data[2][1]=sinx;
            this.data[2][2]=cosx;
    }

    //Creare matrice rotatie Oy
    public void rotatie_Oy(double cosy,double siny)
    {
        //Vom pune in matrice pe diagonala principala valoarea 1 iar pe celelalte pozitii valoarea 0
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (i == j)
                    this.data[i][j] = 1;
                else
                    this.data[i][j] = 0;
            }
        }
        this.data[0][0]=cosy;
        this.data[0][2]=siny;
        this.data[2][0]=-siny;
        this.data[2][2]=cosy;
    }

    //Creare matrice rotatie Oz
    public void rotatie_Oz(double cosz,double sinz)
    {
        //Vom pune in matrice pe diagonala principala valoarea 1 iar pe celelalte pozitii valoarea 0
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (i == j)
                    this.data[i][j] = 1;
                else
                    this.data[i][j] = 0;
            }
        }
        this.data[0][0]=cosz;
        this.data[0][1]=-sinz;
        this.data[1][0]=sinz;
        this.data[1][1]=cosz;
    }

    //Creare matrice rotatie de unghi(angle)
    public void rotatie_unghi(double angle)
    {
        //Vom pune in matrice pe diagonala principala valoarea 1 iar pe celelalte pozitii valoarea 0
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (i == j)
                    this.data[i][j] = 1;
                else
                    this.data[i][j] = 0;
            }
        }
        double radians = Math.toRadians(angle);
        this.data[0][0]=Math.cos(radians);//cosz;
        this.data[0][1]=-Math.sin(radians);//-sinz;
        this.data[1][0]=Math.sin(radians);//sinz;
        this.data[1][1]=Math.cos(radians);//cosz;
    }
}
