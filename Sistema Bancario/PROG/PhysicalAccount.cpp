#include "../INCLUDE/PhysicalAccount.hpp"

std::string PhysicalAccount::inputPhysicalName()
{
    std::string nome{""};
    std::cout << "Olá, bem vindo ao bank Kern Corp." << std::endl;
    std::cout << "Insira seu nome: ";
    std::cin >> nome;
    return nome;
}