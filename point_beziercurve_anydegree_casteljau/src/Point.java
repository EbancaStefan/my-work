public class Point {
    private double x;
    private double y;
    public Point()
    {
        this.x=0;
        this.y=0;
    }

    public Point(double x,double y)
    {
        this.x=x;
        this.y=y;
    }
    public void setX(double x){this.x=x;}
    public double getX(){return this.x;}

    public void setY(double y){this.y=y;}
    public double getY(){return this.y;}

    public void multpl(double t)
    {
        this.setX(this.getX()*t);
        this.setY(this.getY()*t);
    }
    public Point multpl1(double t)
    {
        this.setX(this.getX()*t);
        this.setY(this.getY()*t);
        return this;
    }
    public void add(Point P)
    {
        this.setX(this.getX()+P.getX());
        this.setY(this.getY()+P.getY());
    }
    public Point add1(Point P)
    {
        this.setX(this.getX()+P.getX());
        this.setY(this.getY()+P.getY());
        return this;
    }
    public Point sub1(Point P)
    {
        this.setX(this.getX()-P.getX());
        this.setY(this.getY()-P.getY());
        return this;
    }


}
