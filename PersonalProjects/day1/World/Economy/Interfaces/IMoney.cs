namespace Economy.Interfaces
{
    internal interface IMoney
    {
        char currency { get; }
        decimal value { get; }
        decimal price { get; }
        void Add(decimal amount);
        void Remove(decimal amount);

        void Convert(IMoney toCurrency, decimal amount);
        void Sell(IMoney toCurrency, decimal amount);

        void Buy(IMoney fromCurrency, decimal amount);
        void Exchange(IMoney fromCurrency, IMoney toCurrency, decimal amount);


        //TODO: IMoney connects the economy
        //TODO: 1. Currency checker
        //TODO: 2. value
        //TODO: 3. Add for adding money
        //TODO: 4. Remove for removing money
    }
}
