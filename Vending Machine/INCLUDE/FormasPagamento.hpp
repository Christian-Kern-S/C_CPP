#include <iostream>

template <typename T>

class FormasDePagamento
{
private:
  std::string name;
  std::function<bool(const T &)> verifyPayment;
  std::function<void(T &)> getPayment;

public:
  FormasDePagamento(std::string namePayment,
                    std::function<bool(const T &)> verifyPayment,
                    std::function<void(T &)> getPayment)
      : name(name_payment), verifyPayment(verify_payment),
        getPayment(get_payment) {}

  std::string getname() const
  {
    return nome;
  }

  inline bool can_payment_process(const T &payment) const { return verify_payment(payment); }

  inline void payment_process(T &payment) const { get_payment(payment); }
};