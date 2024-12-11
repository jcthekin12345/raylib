using System.ComponentModel;
using System.Runtime.CompilerServices;

namespace FileManager;
// Character.cs
public class Character : INotifyPropertyChanged
{
    private string _name;
    private int _age;
    private double _health;
    private double _happiness;
    private double _intelligence;

    public event PropertyChangedEventHandler? PropertyChanged;

    public string Name
    {
        get => _name;
        set
        {
            _name = value;
            OnPropertyChanged();
        }
    }

    public int Age
    {
        get => _age;
        set
        {
            _age = value;
            OnPropertyChanged();
        }
    }

    public double Health
    {
        get => _health;
        set
        {
            _health = Math.Clamp(value, 0, 100);
            OnPropertyChanged();
        }
    }

    public double Happiness
    {
        get => _happiness;
        set
        {
            _happiness = Math.Clamp(value, 0, 100);
            OnPropertyChanged();
        }
    }

    public double Intelligence
    {
        get => _intelligence;
        set
        {
            _intelligence = Math.Clamp(value, 0, 100);
            OnPropertyChanged();
        }
    }

    protected void OnPropertyChanged([CallerMemberName] string propertyName = null)
    {
        PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
    }

    public Character(string name)
    {
        Name = name;
        Age = 0;
        Health = 100;
        Happiness = 100;
        Intelligence = 50;
    }
}
