namespace ATMACHINE.Core
{
    public enum CardType
    {
        Credit,
        Debit,
        Prepaid,
        Unknown
    }

    internal class Card
    {
        /* 1. Created the type field
         * 2. Created Number field
         * 3. Created name Holder  field
         * 4. Created activate checker field
         */
        public CardType Type { get; init; }
        public int Number { get; init; }
        public string? HolderName { get; set; }
        public bool IsActive { get; set; }

        public void Deactivate() => IsActive = false;
        public void Activate() => IsActive = true;
    }
}
