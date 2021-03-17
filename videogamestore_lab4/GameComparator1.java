import java.util.Comparator;

public class GameComparator1 implements Comparator<VideoGame>
{
    public int compare(VideoGame game1,VideoGame game2)
    {
        return game1.getPrice() - game2.getPrice();
    }
}
