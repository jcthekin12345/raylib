namespace WorldMap.Core;

public class Coords<TY, TX>(TY y, TX x)
{
    public TY Y
    {
        get;
    } = y;

    public TX X
    {
        get;
    } = x;
}

public class Map
{
    private () grid = ();

    public Map()
    {
        Grid = new int[10, 10];
    }
    static void DisplayCoords((int x, int y) coords) 
    {
        
    }
}