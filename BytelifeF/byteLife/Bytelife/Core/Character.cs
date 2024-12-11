public class Character : ObservableObject
{
    // Basic stats
    private string name;
    private int age;
    private int happiness;
    private decimal money;
    
    // Observable properties that will automatically update the UI later
    public string Name 
    { 
        get => name; 
        set => SetProperty(ref name, value); 
    }
    
    public int Age 
    { 
        get => age;
        set => SetProperty(ref age, value);
    }

    public int Happiness
    {
        get => happiness;
        set => SetProperty(ref happiness, Math.Clamp(value, 0, 100));
    }

    public decimal Money
    {
        get => money;
        set => SetProperty(ref money, value);
    }

    public Character(string name)
    {
        Name = name;
        Age = 0;
        Happiness = 100;
        Money = 1000;
    }

    public void AgeUp()
    {
        Age++;
        // Random life event could happen here
    }
}