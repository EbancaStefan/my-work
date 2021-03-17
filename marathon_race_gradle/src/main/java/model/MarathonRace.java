package model;


public class MarathonRace implements Identifiable<Integer> {
    private int distance,ID;
    private String name;
    private String type;
    private String date;
    //private ReservationStatus status;

    public MarathonRace()
    {
        this.ID=0;
        this.distance =0;
        this.name ="";
        this.type ="";
        this.date ="";
        //this.status = ReservationStatus.NotReserved;
    }

    public MarathonRace(int id1, String name, String type, String date, int a1)
    {
        this.ID=id1;
        this.distance =a1;
        this.date = date;
        this.type = type;
        this.name =name;
        //this.status=ReservationStatus.NotReserved;
    }
    public MarathonRace(String name, String type, String date, int a1)
    {
        this.distance =a1;
        this.date = date;
        this.type = type;
        this.name =name;
        //this.status=ReservationStatus.NotReserved;
    }
    public void setDate(String d1) {
        this.date = d1;
    }
    public String getDate() {
        return this.date;
    }

    public void setDistance(int a1) {
        this.distance = a1;
    }
    public int getDistance() {
        return this.distance;
    }

    public void setName(String name){this.name = name;}
    public String getName(){return this.name;}


    public void setType(String type) {this.type = type;}
    public String getType(){return this.type;}

   /* public ReservationStatus getStatus() {
        return status;
    }*/

    /*public void setStatus(ReservationStatus NewStatus) {
        this.status = NewStatus;
    }*/
    @Override
    public String toString()
    {
        String str =ID+"; "+name+", " +type+ " distance "+ distance +" "+date;
        return str;
    }
    @Override
    public boolean equals(Object obj)
    {
        if(!(obj instanceof MarathonRace))
        {
            return false;
        }
        else
        {
            MarathonRace c = (MarathonRace)obj;
            return this.ID==c.ID;
        }
    }

    @Override
    public Integer getID() {
        return ID;
    }

    @Override
    public void setID(Integer ID) {
        this.ID=ID;
    }
}
