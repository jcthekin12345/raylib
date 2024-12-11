public class Game
{
    public static int Move(int position, int roll)
    {
        for (int i = 0; i < position; ++i)
        {
            position += roll;
        }
        return position;
    }

    public static void Main()
    {
        Move(0, 4);
    }
}

public 



