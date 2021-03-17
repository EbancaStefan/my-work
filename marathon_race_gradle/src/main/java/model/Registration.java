package model;

public class Registration implements Identifiable<Integer>{
    private int ID,age;
    private String personName, phoneNumber,address;
    private MarathonRace marathonRace;

    public Registration() {
        age=0;
        ID = 0;
        personName = "";
        phoneNumber ="";
        marathonRace =null;

    }

    public String getAddress() {
        return address;
    }

    public void setAddress(String address) {
        this.address = address;
    }

    public Registration(int ID, String personName, String phoneNumber, String adress, MarathonRace marathonRace, int age) {
        this.ID = ID;
        this.personName = personName;
        this.phoneNumber = phoneNumber;
        this.address=adress;
        this.marathonRace = marathonRace;
        this.age = age;

    }

    public Registration(String personName, String phoneNumber,String adress, MarathonRace marathonRace, int age) {
        this.personName = personName;
        this.phoneNumber = phoneNumber;
        this.address=adress;
        this.marathonRace = marathonRace;
        this.age = age;

    }

    @Override
    public Integer getID() {
        return ID;
    }

    @Override
    public void setID(Integer Id) {
        this.ID = Id;
    }

    public String getPersonName() {
        return personName;
    }

    public String getPhoneNumber() {
        return phoneNumber;
    }

    public int getAge() {
        return age;
    }

    public MarathonRace getRace() {
        return marathonRace;
    }

    public void setPersonName(String personName) {
        this.personName = personName;
    }

    public void setPhoneNumber(String phoneNumber) {this.phoneNumber = phoneNumber;}

    public void setAge(int age) {
        this.age = age;
    }

    public void setRace(MarathonRace marathonRace) {
        this.marathonRace = marathonRace;
    }

    @Override
    public String toString()
    {
        String str = ID+" "+ personName +" "+phoneNumber+" "+address+" "+age+" "+marathonRace;
        return str;
    }
    @Override
    public boolean equals(Object obj)
    {
        if(obj instanceof Registration)
        {
            Registration c=(Registration)obj;
            return c.ID==this.ID;
        }
        return false;
    }
}
