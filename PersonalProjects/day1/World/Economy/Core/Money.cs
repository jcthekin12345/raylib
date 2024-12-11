namespace Economy.Core
{
    internal class Money : IMoney
    {
        public decimal Value { get; private set; }
        public Money(decimal value)
        {
            Value = value;
        }
        // Money class for managing monetary transactions and operations
        // Implement methods for deposit, withdraw, conversion, and other financial operations
    }
}
