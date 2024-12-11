namespace Score.Core;
internal class ScoreBoard
{
    public string name;
    public int points;
    public int level;
    public int fails;
    public int rank;
    private readonly string _AdminUser = "jc";

    public ScoreBoard(string n, int p, int l)
    {
        name = n;
        points = p;
        level = l;
    }
    public List<string> GetHackers(List<string> users)
    {
        var hackers = users.Where(users => users != _AdminUser).ToList();
        return hackers;
    }
    public void RemoveHackers(ref List<string> targets)
    {
        targets?.RemoveAll(target => target != _AdminUser);
    }
    public bool EarnedStar() => (points / level) > 1000;
}
