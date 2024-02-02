#include "Produtos.hpp"


int Produto::Add() {
  int qtd;
  std::cout << "infome a quantidade de produtos a ser adicionada: " << std::endl;
  std::cin >> qtd;
  if (qtd + estoque.qtdAtual > estoque.qtdMax) {
    std::cout << "Não é possivel adicionar mais produtos, o estoque está cheio";
    return 0;
  }
  std::cout << "Quantidade adicionada com sucesso" << std::endl;
  return estoque.qtdAtual += qtd;
}

int Produto::Remove(int qtd) {
  std::cout << "infome a quantidade de produtos a ser removida: " << std::endl;
  std::cin >> qtd;
  return estoque.qtdAtual -= qtd;
}

void Produto::set_qtdMax(int qtdMax) {
  std::cout << "infome a nova quantidade maxima de produtos no estoque: "<< std::endl;
  std::cin >> qtdMax;
  estoque.qtdMax = qtdMax;
}
