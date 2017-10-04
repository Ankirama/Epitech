#ifndef IINGREDIENT_HH_
# define IINGREDIENT_HH_

class IIngredient {
public:
  virtual ~IIngredient() {}

  virtual int getQuantity() const = 0;
  virtual bool setQuantity(int quantity) = 0;
  virtual bool removeQuantity(int quantity) = 0;
  virtual void resetIngredient() = 0;
  virtual std::string const &getName() const = 0;
};

#endif /* !IINGREDIENT_HH_ */
