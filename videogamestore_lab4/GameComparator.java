import java.util.Comparator;

public class GameComparator implements Comparator<VideoGame>
{
    public int compare(VideoGame game1,VideoGame game2)
    {
        return game1.getYear() - game2.getYear();
    }
}