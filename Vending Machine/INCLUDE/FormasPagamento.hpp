#include <iostream>

template <typename T>

class FormasDePagamento {
  private:
    std::string nome;
    std::function<bool(const T&)> verifica_pagamento;
    std::function<void(T&)> receber_pagamento;

  public:
    FormasDePagamento(std::string nome_pagamento, 
                      std::function<bool(const T&)> verificar_pagamento,
                      std::function<void(T&)> receber_pagamento_pagamento)
        : nome(nome_pagamento), verifica_pagamento(verificar_pagamento),
          receber_pagamento(receber_pagamento_pagamento) {}

    std::string obter_nome() const {
        return nome;
    }
        
    inline bool pode_processar_pagamento(const T& pagamento) const {return verifica_pagamento(pagamento);}

    inline void processar_pagamento(T& pagamento) const {receber_pagamento(pagamento);}
};