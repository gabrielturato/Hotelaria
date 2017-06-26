#include "Classes.h"
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int bissexto (int ano) {
	return (ano % 4 == 0) && ((ano % 100 != 0) || (ano % 400 == 0));
}

int dias_mes[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                       {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

//Função para achar a distancia entre a data de fim e data de início
unsigned long dist_dias (Data inicio, Data fim) {
	unsigned long idias, fdias;	/* guarda qtos dias tem da data */
					/* ate o comeco do ano */
	unsigned long def_anos = 0;	/* guarda diferenca entre anos das */
					/* datas inicio e fim medida em dias */
	register int i;
	int dbissexto;

	idias = inicio.dia;
	dbissexto = bissexto (inicio.ano);
	for (i = inicio.mes - 1; i > 0; --i)
		idias += dias_mes[dbissexto][i];

	fdias = fim.dia;
	dbissexto = bissexto (fim.ano);
	for (i = fim.mes - 1; i > 0; --i)
		fdias += dias_mes[dbissexto][i];

	while (inicio.ano < fim.ano)
		def_anos += 365 + bissexto(inicio.ano++);

	return def_anos - idias + fdias;
}


Pessoa::Pessoa()
{
}

Pessoa::~Pessoa()
{
}

void Pessoa::setCPF(string CPF)
{
	this->CPF=CPF;
}

string Pessoa::getCPF()
{
	return this->CPF;
}

void Pessoa::setRG(string RG)
{
	this->RG=RG;
}

string Pessoa::getRG()
{
	return this->RG;
}

void Pessoa::setNome(string nome)
{
	this->nome=nome;
}

string Pessoa::getNome()
{
	return this->nome;
}

void Pessoa::setDataNasc(string data_nasc)
{
	this->data_nasc=data_nasc;
}

string Pessoa::getDataNasc()
{
	return this->CPF;
}

void Pessoa::setEndereco(string endereco)
{
	this->endereco=endereco;
}

string Pessoa::getEndereco()
{
	return this->endereco;
}

Funcionario::Funcionario()
{
	ativo=1;
}

Funcionario::~Funcionario()
{
}

string Funcionario::recupera_senha(string CPF,string cargo)
{
	string CPFPessoa;
	CPFPessoa=getCPF();
	if(CPFPessoa==CPF){
		if(this->cargo==cargo){
			return this->senha;
		}else{
			return "Cargo inválido";
		}
	}else{
		return "CPF inválido";
	}
}

void Funcionario::setCargo(string cargo)
{
	this->cargo=cargo;
}

string Funcionario::getCargo()
{
	return this->cargo;
}
void Funcionario::setDataAdmissao(string data_admissao)
{
	this->data_admissao=data_admissao;
}

string Funcionario::getDataAdmissao()
{
	return this->data_admissao;
}
void Funcionario::setTelefone(string telefone)
{
	this->telefone=telefone;
}

string Funcionario::getTelefone()
{
	return this->telefone;
}
void Funcionario::setCargaHoraria(int carga_horaria)
{
	this->carga_horaria=carga_horaria;
}

int Funcionario::getCargaHoraria()
{
	return this->carga_horaria;
}
void Funcionario::setSalario(float salario)
{
	this->salario=salario;
}

float Funcionario::getSalario()
{
	return this->salario;
}

void Funcionario::setSenha(string senha)
{
	this->senha=senha;
}

string Funcionario::getSenha()
{
	return this->senha;
}

void Funcionario::setAtividade()
{
	if(ativo==1){
		ativo=0;
	}else{
		ativo=1;
	}
}

bool Funcionario::getAtividade()
{
	if(ativo==1){
		return 1;
	}else{
		return 0;
	}
}

Cliente::Cliente()
{
}

Cliente::~Cliente()
{
}

void Cliente::setConta(float valor)
{
	this->Conta+=valor;
}

float Cliente::getConta()
{
	return this->Conta;
}

void Cliente::diminuiConta(float valor)
{
	this->Conta-=valor;
}

Quarto::~Quarto()
{
}

Quarto::Quarto()
{
	disponivel=1;
}

void Quarto::setValor(float valor)
{
	this->valor=valor;
}

float Quarto::getValor()
{
	return this->valor;
}

void Quarto::setTipo(string tipo)
{
	this->tipo=tipo;
}

string Quarto::getTipo()
{
	return this->tipo;
}

void Quarto::setCategoria(string categoria)
{
	this->categoria=categoria;
}

string Quarto::getCategoria()
{
	return this->categoria;
}

float Quarto::defineValor(string tipo, string categoria)
{
	float valor;
	this->tipo=tipo;
	this->categoria=categoria;
	if(tipo=="solteiro"){
		valor+=70.00;
	}else{
		if(tipo=="duplo_solteiro"){
			valor+=120.00;
		}else{
			if(tipo=="casal"){
				valor+=150.00;
			}
		}
	}
	if(categoria=="basico"){
		valor+=0.00;
	}else{
		if(categoria=="luxo"){
			valor+=150.00;
		}else{
			if(categoria=="sweet_dreams"){
				valor+=300.00;
			}
		}
	}
	return valor;
}

void Quarto::setDisponibilidade()
{
	if(disponivel==0)
		disponivel=1;
	else
		disponivel=0;
}

bool Quarto::getDisponibilidade(){
	return this->disponivel;
}

Estadia::Estadia()
{
}

Estadia::~Estadia()
{
}

void Estadia::setAcompanhante(string nome,string telefone)
{
    pessoa.nome=nome;
    pessoa.telefone=telefone;
}

dados_Acomp Estadia::getAcompanhante()
{
    return this->pessoa;
}

void Estadia::setDataEntrada(int dia,int mes,int ano)
{
	this->entrada.dia=dia;
	this->entrada.mes=mes;
	this->entrada.ano=ano;
}

Data Estadia::getDataEntrada()
{
	return this->entrada;
}

void Estadia::setDataSaida(int dia,int mes,int ano)
{
	this->saida.dia=dia;
	this->saida.mes=mes;
	this->saida.ano=ano;
}

Data Estadia::getDataSaida()
{
	return this->saida;
}

void Estadia::setValor(float valor)
{
	this->valor=valor;
}

float Estadia::getValor()
{
	return this->valor;
}

void Estadia::setFormaPag(string forma_pag)
{
	this->forma_pag=forma_pag;
}

string Estadia::getFormaPag()
{
	return this->forma_pag;
}

void Estadia::setQualidade(string qualidade)
{
	this->qualidade=qualidade;
}

string Estadia::getQualidade()
{
	return this->qualidade;
}

void Estadia::setObservacao(string observacao)
{
	this->observacao=observacao;
}

string Estadia::getObservacao()
{
	return this->observacao;
}

void Estadia::setTelefone(string telefone)
{
	this->telefone=telefone;
}

string Estadia::getTelefone()
{
	return this->telefone;
}

void Estadia::setQuantQuartos(int quant_quartos)
{
	this->quant_quartos=quant_quartos;
}

int Estadia::getQuantQuartos()
{
	return this->quant_quartos;
}

void Estadia::setGanhos(float ganhos)
{
	this->ganhos=ganhos;
}

float Estadia::getGanhos()
{
	return this->ganhos;
}

void Estadia::setQuantPessoas(int quant_pessoas)
{
	this->quant_pessoas=quant_pessoas;
}

int Estadia::getQuantPessoas()
{
	return this->quant_pessoas;
}

void Estadia::setNome(string nome)
{
	this->nome=nome;
}

string Estadia::getNome()
{
	return this->nome;
}

void Estadia::setCodCli(int cod_cli)
{
	this->cod_cli=cod_cli;
}

int Estadia::getCodCli()
{
	return this->cod_cli;
}

void Estadia::setNumQuarto(int num_quarto)
{
	this->num_quarto=num_quarto;
}

int Estadia::getNumQuarto()
{
	return this->num_quarto;
}

