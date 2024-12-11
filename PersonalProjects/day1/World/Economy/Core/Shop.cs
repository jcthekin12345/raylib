using Economy.Interfaces;

namespace Economy.Core
{
    internal class Shop : IInteract
    {
        public int? Money { get; set; }
        public int? Sale { get; set; }
        public int? Brand { get; set; }


    }
}
