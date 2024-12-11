using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Runtime.CompilerServices;
using System.Windows.Input;

namespace FileManager;
/// <summary>
/// Interaction logic for MainWindow.xaml
/// </summary>
public class MainViewModel : INotifyPropertyChanged
{
    public event PropertyChangedEventHandler PropertyChanged;

    public Character Character
    {
        get; private set;
    }

    private ObservableCollection<LifeEvent> _lifeEvents;
    public ObservableCollection<LifeEvent> LifeEvents
    {
        get => _lifeEvents;
        set
        {
            _lifeEvents = value;
            OnPropertyChanged();
        }
    }

    private ObservableCollection<GameAction> _availableActions;
    public ObservableCollection<GameAction> AvailableActions
    {
        get => _availableActions;
        set
        {
            _availableActions = value;
            OnPropertyChanged();
        }
    }

    public MainViewModel()
    {
        Character = new Character("John Doe");
        LifeEvents = new ObservableCollection<LifeEvent>();
        AvailableActions = new ObservableCollection<GameAction>();

        InitializeActions();
        AddLifeEvent("You were born!");
    }

    private void InitializeActions()
    {
        AvailableActions.Add(new GameAction
        {
            Name = "Study",
            Command = new RelayCommand(() => Study())
        });

        AvailableActions.Add(new GameAction
        {
            Name = "Exercise",
            Command = new RelayCommand(() => Exercise())
        });

        AvailableActions.Add(new GameAction
        {
            Name = "Have Fun",
            Command = new RelayCommand(() => HaveFun())
        });
    }

    private void Study()
    {
        Character.Intelligence += 5;
        Character.Happiness -= 2;
        AddLifeEvent("You studied hard and got smarter!");
    }

    private void Exercise()
    {
        Character.Health += 5;
        Character.Happiness += 3;
        AddLifeEvent("You exercised and feel healthier!");
    }

    private void HaveFun()
    {
        Character.Happiness += 10;
        Character.Health -= 2;
        AddLifeEvent("You had a great time!");
    }

    private void AddLifeEvent(string message)
    {
        LifeEvents.Insert(0, new LifeEvent { Message = message });
    }

    protected void OnPropertyChanged([CallerMemberName] string propertyName = null)
    {
        PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
    }
}
public class LifeEvent
{
    public string Message
    {
        get; set;
    }
}

public class GameAction
{
    public string Name
    {
        get; set;
    }
    public ICommand Command
    {
        get; set;
    }
}

public class RelayCommand : ICommand
{
    private readonly Action _execute;
    private readonly Func<bool> _canExecute;

    public RelayCommand(Action execute, Func<bool> canExecute = null)
    {
        _execute = execute ?? throw new ArgumentNullException(nameof(execute));
        _canExecute = canExecute;
    }

    public event EventHandler CanExecuteChanged
    {
        add => CommandManager.RequerySuggested += value;
        remove => CommandManager.RequerySuggested -= value;
    }

    public bool CanExecute(object parameter) => _canExecute?.Invoke() ?? true;

    public void Execute(object parameter) => _execute();
}