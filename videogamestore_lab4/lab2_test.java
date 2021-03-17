import java.util.Iterator;

public class lab2_test {
    public static void main(String[] args)
    {
        VideoGameStore games=new VideoGameStore();

        VideoGame game1=new VideoGame(2000,60,"dev1","name1","publisher1");
        VideoGame game2=new VideoGame(2005,45,"dev1","name2","publisher2");
        VideoGame game3=new VideoGame(2010,60,"dev3","name3","publisher3");

        games.addGame(game1);
        games.addGame(game2);
        games.addGame(game3);

        Iterator<VideoGame> it= games.videoGameIterator();
        for(; it.hasNext();)
            System.out.println(it.next());

        System.out.println("\nGames by dev1:");
        games.GamesByDeveloper("dev1");

        System.out.println("\nOldest game:");
        System.out.println(games.OldestGame());

        System.out.println("\nMost expensive game:");
        System.out.println(games.MostExpensiveGame());


    }

}
