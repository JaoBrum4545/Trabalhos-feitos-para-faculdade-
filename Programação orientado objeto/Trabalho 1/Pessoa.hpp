
namespace faculdade
{
class Pessoa
{
    private:
    std::string nome;

    public:
    inline const std::string getNome() const;
    inline void setNome(const std::string nome);
};
}

// ainda no Pessoa.hpp
inline const std::string faculdade::Pessoa::getNome() const
{
    return (this->nome);
}

inline void faculdade::Pessoa::setNome(const std::string nome)
{
    this->nome = (nome);
}
