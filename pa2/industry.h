#ifndef BRASS_INDUSTRY_H_
#define BRASS_INDUSTRY_H_

#include "location.h"
#include "infrastructure.h"

#include "game-common.h"
#include "game-observer.h"

#include <set>

class Player;
class Location;
class Infrastructure;
class IndustryObserver;
class ResourceObserver;

class Industry : public Infrastructure {
 public:
  // When an industry is not located on the game map yet, location may be
  // a nullptr. However, we always ensure that an industry has an industry type.
  // For the resource type, it is meant to be used by a PrimaryIndustry only.
  // The reason why we include resource_type here is to open the flexibity of
  // extending the game. For secondary industry, it's by default 
  // ResourceType::kUndefined.
  Industry(IndustryType industry_type,
           Location* location,
           ResourceType resource_type);
  virtual ~Industry();

  // Returns true if the industry is built.
  virtual bool IsBuilt() const = 0;

  // Build `this` industry on the parameter `industry`.
  // You may asssume that `industry` is always a slot on the game map.
  // It may be an open slot, or a slot that has an industry tile
  // (aka. IndustryImpl) on it.
  // Inform the industry observer.
  virtual bool Build(Industry* industry) = 0;

  // Returns true if this industry can overbuild `other`.
  virtual bool CanOverbuild(Industry* other) const = 0;

  // Reacts to being overbuilt. See the functions declartion
  // in the class definition of the realizations of this class
  // for the implementation detail, i.e. IndustryImpl::BeOverbuilt(),
  // IndustryProxy::BeOverbuilt().
  // Inform the industry observer.
  virtual void BeOverbuilt(Industry* other) = 0;

  // Returns true if the industry is demolished.
  virtual bool IsDemolished() const = 0;

  // Removes the industry from the location, may be because
  // `this` object is being overbuilt by another industry, see
  // `IndustryImpl::BeOverbuilt()`.
  // Update the industry observer, and the resource observe, if there's any.
  virtual void Demolish() = 0;

  // Returns true if the industry is eligible for VP calculation;
  virtual bool IsEligibleForVp() const = 0;

  // Returns true if the industry is sold in the sell action, 
  // which concerns secondary industries only. For primary industry
  // just do nothing.
  // As it's not the industry which is selling itself, just
  // change its state of `sold_` as sold.
  // This fails only if the industry was sold before.
  // This should update the industry observer.
  virtual bool Sell();

  // Provides a specified number of resource units for free.
  virtual bool ProvideResources(int units);

  // This is not going to be used by you.
  bool operator<(const Industry& other) const;

  // This returns the VP worth of the industry if is eligible for VP calculation,
  // otherwise, returns 0.
  virtual int vp() const = 0;

  // This returns the VP awarded for adjacent links if the industry is eligible for VP calculation,
  // otherwise, returns 0.
  virtual int vp_for_adjacent_link() const = 0;

  // Returns the available resource units of the industry.
  virtual int available_units() const = 0;

  virtual Industry* impl() = 0;
  virtual Player* player() const = 0;
  virtual std::string player_name() const = 0;
  Location* location() const;
  virtual IndustryProperties properties() const = 0;
  MainIndustryType main_industry_type() const;
  IndustryType industry_type() const;
  ResourceType resource_type() const;

  virtual void set_player(Player* player) = 0;
  void set_location(Location* location);
  virtual void set_industry_observer(IndustryObserver* observer) = 0;
  virtual void set_resource_observer(ResourceObserver* rsrc_observer) = 0;

 protected:
  // Produces consumable resources.
  virtual void ProduceResources();

  // Removes the consumable resources produced.
  virtual void RemoveResources();

  IndustryType industry_type_;
  ResourceType resource_type_;

  Location* location_;
  IndustryObserver* industry_observer_ = nullptr;
  ResourceObserver* resource_observer_ = nullptr;

 private:
  static int counter;
  const int creation_id_;
};


class IndustrySubscriber {
  friend IndustryObserver;
 
 public:
  virtual ~IndustrySubscriber();

 protected:
  virtual void UpdateIndustryInfo(std::map<IndustryType, std::vector<IndustryInfo> > industry_info) = 0;
};

class IndustryObserver : public Observer {
 public:
  IndustryObserver();
  ~IndustryObserver();

  // This function accepts an `industry` pointer which has its underlying object
  // recently changed. This updates the information that this object previously knows
  // about the `industry`. If the `industry` has not been seen by this observer before,
  // just insert an entry about it to cache the `industry`'s information.
  void UpdateIndustry(Industry* industry);

  // Removes the industry entry stored inside this object. This means let
  // the industry observer forgets about the `industry`, and not provide the information
  // of the `industry` to its subscribers anymore.
  void RemoveIndustry(Industry* industry);

  // Store the pointer pointing to the subscriber so that when there is any changes
  // to this observe's state, e.g. has the information of an industry updated or removed.
  void RegisterSubscriber(IndustrySubscriber* subscriber);

  // Removes the entry of the subscriber so that when there is any change to this observer's
  // state, we no longer informs this specific `subscriber`.
  void Unsubscribe(IndustrySubscriber* subscriber);

  // Inform the subscribers of the changes to the industries that are known by this observer.
  virtual void Notify() override;

 private:
  using IndustryInfoMap = std::map<Industry*, IndustryInfo, ptr_less<Industry> >;

  IndustryInfoMap industry_info_;  // the cache which stores the information about the previously seen industries
  std::set<IndustrySubscriber*> subscribers_;
};

class IndustryImpl : public Industry {
 public:
  IndustryImpl(IndustryType industry_type, IndustryProperties properties,
               ResourceType resource_type = ResourceType::kUndefined);
  virtual ~IndustryImpl();

  // For an industry tile, if it's built, it's associated to 
  // a certain location.
  virtual bool IsBuilt() const override;

  virtual bool Build(Industry* industry) override;
  
  virtual bool CanOverbuild(Industry* industry) const override = 0;
  
  // When an industry tile is being overbuilt by another industry,
  // we demolishes the industry by removing the pointers to all the
  // observers which observe this object.
  virtual void BeOverbuilt(Industry* industry) override;

  virtual bool IsDemolished() const override;
  virtual void Demolish() override;
  virtual bool IsEligibleForVp() const override = 0;

  virtual Industry* impl() override;
  virtual Player* player() const override;
  virtual std::string player_name() const override;

  // Returns 0 if the industry is not eligible for VP. Otherwise, returns `properties_.vp`.
  virtual int vp() const override;

  // Returns 0 if the industry is not eligible for VP. Otherwise, returns `properties_.vp_for_adj_link`.
  virtual int vp_for_adjacent_link() const override;

  virtual int available_units() const override;
  virtual IndustryProperties properties() const override;

  virtual void set_player(Player* player) override;

  virtual void set_industry_observer(IndustryObserver* observer) override;
  virtual void set_resource_observer(ResourceObserver* rsrc_observer) override = 0;

 protected:
  const IndustryProperties properties_;
  bool demolished_ = false;
  Player* player_ = nullptr;
};

class PrimaryIndustry : public IndustryImpl {
 public:
  // A converting constructor. A primary industry always comes with an industry_type,
  // and resource_type, and industry properties because this is the only constructor
  // that this class has.
  PrimaryIndustry(IndustryType industry_type, IndustryProperties properties,
                  ResourceType resource_type);
  ~PrimaryIndustry() = default;

  // This can overbuild the `other` industry if this is more technologically advanced,
  // and they are of the same industry type. If the other industry represents an null object,
  // i.e. it is an open slot, the checking stops here, returns true.
  // However, when the `other` industry is built (equivalently, has a player), we have to consider
  // who the owners of the two objects are.
  // If the owners refer to the same player, the checking stops here, returns true.
  // The player of this industry can be different from the `other`'s only if the resources
  // of the resource type specified by this object is exhausted on the entire game board.
  // i.e. both the market and all industries which sells / produces the resource have no more
  // available units.
  // Hint: As we alway overbuild through an industry proxy, and an industry proxy always
  //       has a resource observer attached, we can assume `other` is assoicated
  //       to a valid resource observer. Do not check this object's resource observer
  //       because it is a nullptr when this is not yet built. We only assign a resource
  //       observer to this object after it's built and produce resources.
  virtual bool CanOverbuild(Industry* other) const override;

  // Returns true if all of its `available_units_` becomes zero and it's built.
  virtual bool IsEligibleForVp() const override;

  // Provides the given nubmer of resource units if possible.
  // If the units requested is larger than the current available units 
  // that the industry currently has. We reject the request by returning false.
  // Otherwise we just decrease the number of available units
  // that is currently held by the industry.
  // When the available units becomes zero, we increae the owner's
  // EXP specified by `properties_.exp_increase`.
  // updates the resource and industry observes of the change.
  virtual bool ProvideResources(int units) override;

  // Returns the inventory of the industry.
  virtual int available_units() const override;

  // Sets the resource observer of the industry.
  virtual void set_resource_observer(ResourceObserver* rsrc_observer) override;

 private:
  // Industry production happens during the building of an industry,
  // see IndustryImpl::Build().
  // Produces the number of output units specified by `properties_.output_units`.
  // This means we just increase the availble resource units that the industry
  // currently holds. It's just a simple assignment because an industry initially
  // has no production before it is built.
  // updates the resource and industry observers of the change.
  virtual void ProduceResources() override;

  // This is used during the demolishing of an industry.
  // Removes all the resource units available, which means it just assign zero to
  // the available units currently held by the player, without increase the player's EXP
  // because the resources are not being used. They are just dumped away as our TUI.
  // This updates the resource and industry observers of the change.
  virtual void RemoveResources() override;

  int available_units_ = 0;
};

class SecondaryIndustry : public IndustryImpl {
 public:
  SecondaryIndustry(IndustryType industry_type, IndustryProperties properties);
  ~SecondaryIndustry() = default;

  // This can overbuild the `other` industry if this is more technologically advanced,
  // and they are of the same industry type. If the other industry represents an null object,
  // i.e. it is an open slot, the checking stops here, returns true.
  // However, when the `other` industry is built (equivalently, has a player), we have to consider
  // who the owners of the two objects are.
  // If the owners refer to the same player, the checking stops here, returns true.
  // Otherwise just return false.
  virtual bool CanOverbuild(Industry* other) const override;

  // Returns true if the industry is sold and is built.
  virtual bool IsEligibleForVp() const override;

  // Sells the industry, and increases the player's EXP spcefied by
  // `properties_.exp_increase`. Also refer to the comment in Industry::Sell().
  virtual bool Sell() override;

  // Returns true if the industry is already sold.
  bool sold() const;

  // Do not do anything about the `rsrc_obsever` becauase a secondary industry
  // doesn't produce any resources and is not relevant to the observer.
  // We have nothing to tell the resource observer about. That's why
  // this class doesn't have an resource observer data member.
  virtual void set_resource_observer(ResourceObserver* rsrc_observer) override;

 private:
  bool sold_ = false;
};

class IndustryProxy : public Industry, IndustrySubscriber {
 public:
  IndustryProxy(IndustryType industry_type, Location* location,
                ResourceType resource_type = ResourceType::kUndefined);
  ~IndustryProxy();

  virtual bool IsBuilt() const override final;
  virtual bool Build(Industry* industry) override;
  virtual bool CanOverbuild(Industry* industry) const override final;

  // Let the underlying industry be overbuilt by the `other` industry.
  virtual void BeOverbuilt(Industry* other) override final;

  // We caanot demolish an industry proxy because it's not a real industry tile.
  // Just returns false.
  virtual bool IsDemolished() const override;

  // We cannot demolish an industry proxy because it's not a real industry tile.
  // Just do nothing.
  virtual void Demolish() override;

  // Just calls the function of the same name of the underljying object. 
  virtual bool IsEligibleForVp() const override;

  // Ditto.
  virtual bool ProvideResources(int units) override;

  // This is used by an IndustryImpl to inform its proxy of any change to it.
  // So that the IndustryProxy can update the industry observes owned by the game
  // to reflect changes to the IndustryImpl.
  void UpdateIndustryInfo(std::map<IndustryType, std::vector<IndustryInfo> > industry_info) override;

  // Some accessor-like and setter functions.
  virtual Industry* impl() override;

  // Returns 0 if the underlying object is not available. Otherwise, just returns the "VP"
  // of the underlying object.
  virtual int vp() const override final;

  // Returns 0 if the underlying object is not available. Otherwise, just returns the "VP for adjacent link"
  // of the underlying object.
  virtual int vp_for_adjacent_link() const override final;

  virtual int available_units() const override;

  virtual Player* player() const override;
  virtual std::string player_name() const override;
  virtual IndustryProperties properties() const override;

  virtual void set_player(Player* player) override;
  virtual void set_industry_observer(IndustryObserver* industry_observer) override;
  virtual void set_resource_observer(ResourceObserver* resource_observer) override;
  
 private:
  IndustryImpl* impl_ = nullptr;
  IndustryObserver* impl_observer_;  // the observer that this proxy owns to observe the underlying industry
};

inline IndustryType Industry::industry_type() const {
  return industry_type_;
}

inline ResourceType Industry::resource_type() const {
  return resource_type_;
}

inline bool IndustryImpl::IsDemolished() const {
  return demolished_;
}

inline bool IndustryProxy::IsDemolished() const {
  return false;
}

inline 
bool Industry::operator<(const Industry& other) const {
  if (main_industry_type() < other.main_industry_type()) {
    return true;
  }
  if (main_industry_type() > other.main_industry_type()) {
    return false;
  }
  if (industry_type_ < other.industry_type_) {
    return true;
  }
  if (industry_type_ > other.industry_type_) {
    return false;
  }
  if (*location_ < *other.location_) {
    return true;
  }
  if (*other.location_ < *location_) {
    return false;
  }
  if (creation_id_ < other.creation_id_) {
    return true;
  }
  if (creation_id_ > other.creation_id_) {
    return false;
  }
  return false;
}

#endif  // BRASS_INDUSTRY_H_
