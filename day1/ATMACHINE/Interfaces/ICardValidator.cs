using ATMACHINE.Core;
namespace ATMACHINE.Interfaces
{
    internal interface ICardValidator
    {
        bool ValidateCard(Card card);
        bool ValidateCardNumber(Card card);
        bool ValidateCardType(Card card);
        bool ValidateCardIsActive(Card card);

    }
}
