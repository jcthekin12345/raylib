using Score.Core;
namespace Score;
internal class Program
{
    static void Main(string[] args)
    {
        List<string> usersInAdminSection = new List<string>();
        usersInAdminSection.Add("jc");
        usersInAdminSection.Add("john");
        usersInAdminSection.Add("Michael");

        ScoreBoard score = new ScoreBoard("John Doe", 100, 1);
        var hackers = score.GetHackers(usersInAdminSection);
        foreach (var hacker in hackers)
        {
            Console.WriteLine(hacker);
        }
        score.RemoveHackers(ref usersInAdminSection);
        foreach (var hacker in hackers)
        {
            Console.WriteLine(hacker);
        }
    }
}
