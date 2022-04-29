#ifndef BRASS_CARD_H_
#define BRASS_CARD_H_

#include "location.h"
#include "industry.h"
#include "player-network.h"

#include <string>

enum class CardType {
  kLocationCard,
  kIndustryCard,
  kWildLocationCard,
  kWildIndustryCard,
};

//// TODO: Add virtual specifiers for the member functions of the Card class
//// to make it an abstract one.

//// Hint 1: You need not make every function virtual.
//// Hint 2: Cards are dynamically created. At the end of the game,
////         players and the draw deck will delete the cards discarded / unused.
//// Hint 3: As this is an asssignment about inheritiance, you probably want to
////         add things that are related to defining the inheritance relationship
////         between classes, e.g. access specifiers, virtual specifiers, pure virtual
////         function specifiers. How do you know that? e.g. refer to the destructor of 
////         DrawDeck.

//// Do not create any dynamic objects are delete any objects within the card classes
//// because they don't have any ownership of pointers. Those pointers that you receive
//// are only shared to you but not meant to be transferred to you.

// The Card class. It sets additional constraints for the "Build" action,
// e.g. the location where the holder can build an industry on.
// To the other actions, cards are just used to meet the discard requirement
// for performing an action but nothing more.
// @see `Action` (especially `BuildAction`), `DrawDeck`, `PlayerHand` classes
class Card {
 public:
  Card(const std::string& name);
  ~Card();

  // Returns true if the card can be realized as a "Wild Card".
  virtual bool IsWildCard() const = 0;
  
  // Returns true if the card's specification allows us to overbuild
  // the industry `to_be_overbuilt`, i.e., assume we are going to build
  // a valid industry on it, does the card permit us to do so?
  // Hint: Not every card is going to make use of the `network` parameter.
  virtual bool CanIndustryBeOverbuilt(const PlayerNetwork* network,
                              const Industry* to_be_overbuilt) const = 0;

  // Returns the card type.
  virtual CardType card_type() const = 0;

  // Returns the name of the card.
  // For wild cards, it is just "Wild Location" or "Wild Industry".
  // For non-wild cards, it is just the name of the location,
  // Refer to the class definition of Location to check how we can obtain
  // a name from a Location object.
  // or the string representation of the industry type (check the util header file)
  // Refer to `util-common.h` to locate a function which helps you to convert
  // an IndustryType argument into a return value of std::string type.
  std::string name() const;

 protected:
  std::string name_;  // this is meant to be storing the name of the card
};

//// TODO ends


//// TODO: Define the subclasses of `Card` below.
//// They are not complete: it's more than adding the missing function declarations.

// A location card allows us to build on the location specified by the card,
// no matter it's part of the player's network or not.
class LocationCard : public Card{
 public:
  LocationCard(Location* location);
  ~LocationCard();

  virtual bool IsWildCard() const override;

  virtual bool CanIndustryBeOverbuilt(const PlayerNetwork* network,
                              const Industry* to_be_overbuilt) const override;

  virtual CardType card_type() const override;
 
 private:
  Location* const location_;  // this is the location specified by the LocationCard
};

// A wild location card allows us to build on any location on the map,
// no matter the location is within the player's network or not.
// That's why you may not need to use the `network` parameter.
class WildLocationCard : public Card{
 public:
  WildLocationCard();
  ~WildLocationCard();

  virtual bool IsWildCard() const override;

  virtual bool CanIndustryBeOverbuilt(const PlayerNetwork* network,
                              const Industry* to_be_overbuilt) const override;

  virtual CardType card_type() const override;
};

// An industry card only concerns about the finest classifcation of industry types,
// but not the main industry type. Before a player has built any link or industry,
// the card allows the player to build on any location. However, we must always make
// sure that the industry `to_be_overbuilt` has an industry type that is the same
// as the card's specification.
// When a player hasn't built any industry or link, we allow the player to build
// on any locations' industries that have the same industry type as specified by 
// this card.
class IndustryCard : public Card{
 public:
  IndustryCard(IndustryType industry_type);
  ~IndustryCard();

  virtual bool IsWildCard() const override;

  virtual bool CanIndustryBeOverbuilt(const PlayerNetwork* network,
                              const Industry* to_be_overbuilt) const override;

  virtual CardType card_type() const override;

 private:
  const IndustryType industry_type_;  // this is the industry type specified by the card
};

// A wild industry card allows a player to build on any location that is part of
// his network. Because this is a wild card, this doesn't constrain the industry type
// which the holder may build. When a player hasn't established any links or industries,
// it doesn't make an exception for the aforementioned condition.
class WildIndustryCard : public Card{
 public:
  WildIndustryCard();
  ~WildIndustryCard();

  virtual bool IsWildCard() const override;

  virtual bool CanIndustryBeOverbuilt(const PlayerNetwork* network,
                              const Industry* to_be_overbuilt) const override;

  virtual CardType card_type() const override;
};

//// TODO ends

#endif  // BRASS_CARD_H_
