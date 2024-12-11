#pragma once
#include <string>

enum CardType {
	CREDIT,
	DEBIT,
	PREPAID, UNKNOWN 
};

enum class CardBrand {
	VISA,
	MASTERCARD,
	ANEX,
	DISCOVER,
	UNKNOWN 
};

struct CardNumber {
  std::string number;
  bool isValid;

  CardNumber(const std::string& num) : number(num), isValid(validateNumber()) {}

  private:
	  //A BOOL EXPRESSION
	  bool validateNumber() {
     return number.length() >= 13 && number.length() <= 19; //Check if the number is is valid 
                                                            //and returns it to isValid which is a bool
  }
};

class Card {
 private:
  CardType type;
  CardBrand brand;
  std::string holderName;
  std::string expiryDate;
  bool isActive
 public:
    Card(CardType t, const std::string& num, const std::string& name, const std::string& name, const std::string& expiry) 
      : type(t)
      , brand(detemineBrand(num))
      , number(num)
      , holderName(name)
      , epiryDate(expiry)
      , isActive(true) {}

    CardType getType() const { return type; }
    CardBrand getBrand() const { return brand; }
    std::string getHolderName() const { return holderName; }
    std::string getEpiryDate() const { return expiryDate; }
    bool isCardActive() const { return isActive;}

    void deactivate()
};
