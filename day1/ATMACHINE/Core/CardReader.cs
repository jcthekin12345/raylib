using ATMACHINE.Interfaces;
namespace ATMACHINE.Core
{
    public class BasicCardValidator : ICardValidator
    {
        public bool ValidateCard(Card card) =>
            !string.IsNullOrEmpty(card.HolderName);

    }
}
