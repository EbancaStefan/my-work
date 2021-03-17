import java.util.*;

public class VideoGameStore {
    private ArrayList<VideoGame> games;
    public VideoGameStore()
    {
        games = new ArrayList<VideoGame>();
    }
    public boolean addGame(VideoGame game1)
    {
        games.add(game1);
        return true;
    }
    public Iterator<VideoGame> videoGameIterator()
    {
        return games.iterator();
    }
    public VideoGame OldestGame()
    {
        return Collections.min(games, new GameComparator());
    }
    public void GamesByDeveloper(String dev)
    {
        for (int i=0 ;i < games.size();i++)
        {
            if(games.get(i).getDeveloper().equals(dev))
                System.out.println(games.get(i));
        }
    }
    public VideoGame MostExpensiveGame()
    {
        return Collections.max(games, new GameComparator1());
    }

}

