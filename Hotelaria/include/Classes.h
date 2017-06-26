#include <iostream>
#include <string>
#include <stdio.h>


using namespace std;

#ifndef STRUCTS_H
#define STRUCTS_H
typedef struct acompanhante
{
	string nome;
	string telefone;
}dados_Acomp;

typedef struct {
	int dia;
	int mes;
	int ano;
} Data;

int bissexto (int ano);
unsigned long dist_dias (Data inicio, Data fim);

#endif

#ifndef PESSOA_H
#define PESSOA_H
class Pessoa
{
	public:
		Pessoa();
		~Pessoa();
		void setNome(string nome);
		string getNome();
		void setRG(string RG);
		string getRG();
		void setCPF(string CPF);
		string getCPF();
		void setDataNasc(string data_nasc);
		string getDataNasc();
		void setEndereco(string endereco);
		string getEndereco();
	private:
		string nome;
		string RG;
		string CPF;
		string data_nasc;
		string endereco;
};
#endif

#ifndef QUARTO_H
#define QUARTO_H
class Quarto
{
	public:
		Quarto();
		~Quarto();
		void setValor(float valor);
		float getValor();
		void setTipo(string tipo);
		string getTipo();
		void setCategoria(string categoria);
		string getCategoria();
		float defineValor(string tipo,string categoria);
		void setDisponibilidade();
		bool getDisponibilidade();
		//float dadosQuarto();
	private:
		float valor;
		string tipo;
		string categoria;
		bool disponivel;
};
#endif

#ifndef ESTADIA_H
#define ESTADIA_H
class Estadia
{
	public:
		Estadia();
		~Estadia();
		void setAcompanhante(string nome,string telefone);
		dados_Acomp getAcompanhante();
		void setDataEntrada(int dia,int mes,int ano);
		Data getDataEntrada();
		void setDataSaida(int dia,int mes,int ano);
		Data getDataSaida();
		void setValor(float valor);
		float getValor();
		void setFormaPag(string forma_pag);
		string getFormaPag();
		void setQualidade(string qualidade);
		string getQualidade();
		void setObservacao(string observacao);
		string getObservacao();
		void setTelefone(string telefone);
		string getTelefone();
		void setQuantQuartos(int quant_quartos);
		int getQuantQuartos();
		void setGanhos(float ganhos);
		float getGanhos();
		void setQuantPessoas(int quant_pessoas);
		int getQuantPessoas();
		void setNome(string nome);
		string getNome();
		void setCodCli(int cod_cli);
		int getCodCli();
		void setNumQuarto(int num_quarto);
		int getNumQuarto();
	protected:
		dados_Acomp pessoa;
		int cod_cli;
		int num_quarto;
		string nome;
		Data entrada;
		Data saida;
		float valor;
		string forma_pag;
		string qualidade;
		string observacao;
		string telefone;
		int quant_quartos;
		float ganhos;
		int quant_pessoas;
};
#endif

#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H
class Funcionario : public Pessoa
{
	public:
		Funcionario();
		~Funcionario();
		string	recupera_senha(string CPF,string cargo);
		bool	login(string senha);
		void	setAtividade();
		bool	getAtividade();
		void setCargo(string cargo);
		string getCargo();
		void setDataAdmissao(string data_admissao);
		string getDataAdmissao();
		void setTelefone(string telefone);
		string getTelefone();
		void setCargaHoraria(int carga_horaria);
		int getCargaHoraria();
		void setSalario(float salario);
		float getSalario();
		void setSenha(string senha);
		string getSenha();
	protected:
		bool ativo;
		string cargo;
		string data_admissao;
		string telefone;
		int carga_horaria;
		float salario;
		string senha;
};
#endif

#ifndef CLIENTE_H
#define CLIENTE_H
class Cliente : public Pessoa
{
	public:
		Cliente();
		~Cliente();
		void setConta(float valor);
		float getConta();
		void diminuiConta(float valor);
		void setCodCli(int cod_cli);
		int getCodCli();
	protected:
		float Conta;
		int cod_cli;
};
#endif

