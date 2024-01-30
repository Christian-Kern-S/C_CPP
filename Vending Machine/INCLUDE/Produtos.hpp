#include <iostream>
#include <string>

class Produto
{

public:
    Produto(std::string nome_produto, float preco_produto, int qtdMax_produto) : nome(nome_produto), preco(preco_produto), estoque{0, qtdMax_produto} {}
    int Add();
    int Remove(int qtd);
    inline int get_qtdAtual() { return estoque.qtdAtual; }
    inline int get_qtdMax() { return estoque.qtdMax; }
    inline int get_precoProduto() { return preco; };
    void set_qtdMax(int qtdMax);

private:
    std::string nome;
    float preco;
    struct
    {
        int qtdAtual;
        int qtdMax;
    } estoque;
};
