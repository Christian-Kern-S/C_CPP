#include <iostream>
#include <map>
#include <string>

class AccountBancaria {
public:
    AccountBancaria(std::string nome, double saldo) : nome(nome), saldo(saldo) {}

    std::string getNome() const { return nome; }
    double getSaldo() const { return saldo; }

private:
    std::string nome;
    double saldo;
};

int main() {
    std::map<int, AccountBancaria> contas;

    // Criando algumas contas
    contas[1] = AccountBancaria("João", 1000.0);
    contas[2] = AccountBancaria("Maria", 2000.0);

    // Acessando informações da conta pelo número da conta
    int numeroDaAccount = 1;
    if (contas.find(numeroDaAccount) != contas.end()) {
        std::cout << "Nome: " << contas[numeroDaAccount].getNome() << std::endl;
        std::cout << "Saldo: " << contas[numeroDaAccount].getSaldo() << std::endl;
    } else {
        std::cout << "Account não encontrada." << std::endl;
    }

    return 0;
}
