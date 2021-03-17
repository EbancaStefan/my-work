public class VideoGame implements Comparable<VideoGame>{
    private int year,price;
    private String developer,title,publisher;
    public VideoGame ()
    {
        this.year=0;
        this.price=0;
        this.developer="";
        this.title="";
        this.publisher="";
    }
    public VideoGame(int year,int price,String developer,String title,String publisher)
    {
        this.year=year;
        this.price=price;
        this.developer=developer;
        this.title=title;
        this.publisher=publisher;
    }
    //setters / getters
    public void setYear(int year1)
    {
        this.year=year1;
    }
    public int getYear()
    {
        return this.year;
    }
    public void setPrice(int price1)
    {
        this.price=price1;
    }
    public int getPrice()
    {
        return this.price;
    }
    public void setDeveloper(String dev)
    {
        this.developer=dev;
    }
    public String getDeveloper()
    {
        return this.developer;
    }
    public void setTitle(String title1)
    {
        this.title=title1;
    }
    public String getTitle()
    {
        return this.title;
    }
    public void setPublisher(String pub)
    {
        this.publisher=pub;
    }
    public String getPublisher()
    {
        return this.publisher;
    }

    public String toString()
    {
        StringBuffer str= new StringBuffer();
        str.append(title);
        str.append(" by ");
        str.append(developer);
        str.append(" published by ");
        str.append(publisher);
        str.append(" released in ");
        str.append(year);
        str.append(" costs $");
        str.append(price);
        str.append(".");
        return str.toString();
    }
    @Override
    public boolean equals(Object obj)
    {
        if(obj instanceof VideoGame)
        {
            VideoGame vg=(VideoGame) obj;
            return this.year==vg.year && this.title.equals(vg.title) && this.developer.equals(vg.developer);
        }
        return false;
    }
    public int compareTo(VideoGame vg)
    {
        if(vg.year>this.year)
            return -1;
        if(vg.year==this.year)
            return 0;
        return 1;
    }
}
