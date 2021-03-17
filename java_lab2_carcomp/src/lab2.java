public class lab2 {
    public lab2() {
    }
        public static void main(String[] args)
        {
            Dealership d = new Dealership();
            Car c1 = new Car("Dacia","1300",50,1989,false);
            Car c2 = new Car("Dacia","Duster",150,2010,false);
            Car c3 = new Car("Dacia","MCV",125,2007,false);
            Car c4 = new Car("YeeYee","Car",1000,2020,false);
            d.addCar(c1);
            d.addCar(c2);
            d.addCar(c3);
            d.addCar(c4);
            for(int i=0;i<d.getSize();i++)
            {
                System.out.println(d.getCar(i));
            }
            d.createRez(c1);
            d.createRez(c2);
            System.out.print("\n");
            for(int i=0;i<d.getSize();i++)
            {
                System.out.println(d.getCar(i));
            }
            System.out.print("\n");
            d.cancelRez(c2);
            //d.removeCar(c1);
            for(int i=0;i<d.getSize();i++)
            {
                System.out.println(d.getCar(i));
            }
            System.out.println("\nCars from the brand YeeYee:");
            d.cars_by_brand("YeeYee");
            System.out.println("\nCars from the brand Dacia:");
            d.cars_by_brand("Dacia");
            System.out.println("\nThe oldest car is:");
            System.out.println(d.OldestCar().toString());
            System.out.println("\nThe most expensive car is:");
            System.out.println(d.Most_expensive().toString());
        }

}
