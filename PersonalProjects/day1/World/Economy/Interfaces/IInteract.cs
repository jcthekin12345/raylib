namespace Economy.Interfaces
{
    internal interface IInteract : IMoney
    {
        int? Money { get; set; }
        void Sell(decimal amount);
        void Buy(decimal amount);
        void Unsell(decimal amount);
        void Unbuy(decimal amount);
        //TODO: IInteract connects the economy

    }
}
