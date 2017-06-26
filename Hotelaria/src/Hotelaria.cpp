#include "Hotelaria.h"
#include <string>
#include <iostream>
#include <stdio.h>

Hotelaria::Hotelaria()
{
	cod_cli=0;
	cod_func=0;
	nEstadia=0;
	nPessoa=0;
	num_quarto=0;
}

Hotelaria::~Hotelaria()
{
}

void Hotelaria::cadastro_cli(Cliente cliente){
	vCliente[cod_cli] = cliente;
	cod_cli++;
	nPessoa++;
}

void Hotelaria::cadastro_func(Funcionario funcionario){
	vFuncionario[cod_func] = funcionario;
	cod_func++;
	nPessoa++;
}

void Hotelaria::cadastro_quarto(Quarto quarto){
	vQuarto[num_quarto] = quarto;
	num_quarto++;
}

bool Hotelaria::check_in(int nEstadia,string nome,int cod_cli,int dia,int mes,int ano,int num_quarto,string telefone,int quant_pessoas){
	if(vCliente[cod_cli].getNome()==nome){
		if(vQuarto[num_quarto].getDisponibilidade()==1){
			vEstadia[nEstadia].setNome(nome);
			vEstadia[nEstadia].setCodCli(cod_cli);
			vEstadia[nEstadia].setDataEntrada(dia,mes,ano);
			vEstadia[nEstadia].setNumQuarto(num_quarto);
			vEstadia[nEstadia].setTelefone(telefone);
			vEstadia[nEstadia].setQuantPessoas(quant_pessoas);
			nEstadia++;
			return 1;
		}else{
			return 0;	//ERRO Quarto não disponível
		}
	}else{
		return 0;		//ERRO Cliente não cadastrado
	}
}

Cliente Hotelaria::consulta_cli(int cod_cli){
	return vCliente[cod_cli];
}

Estadia Hotelaria::consulta_estadia(int nEstadia){
	return vEstadia[nEstadia];
}

Funcionario Hotelaria::consulta_func(int cod_func){
	return vFuncionario[cod_func];
}

Quarto Hotelaria::consulta_quarto(int num_quarto){
	return vQuarto[num_quarto];
}

float Hotelaria::altera_quarto(int num_quarto,string tipo,string categoria){
	float preco;
	preco=vQuarto[num_quarto].defineValor(tipo,categoria);
	return preco;
}

void Hotelaria::disponibilidade(int num_quarto){
	vQuarto[num_quarto].setDisponibilidade();
}

float Hotelaria::check_out(int nEstadia,int cod_cli, string nome,int dia,int mes,int ano, int num_quarto,string observacao, string forma_pag){
	if(vCliente[cod_cli].getNome()==nome){	//Verificar se existe um cliente com esse nome
		if((vEstadia[nEstadia].getCodCli()==cod_cli)&&(vEstadia[nEstadia].getNumQuarto()==num_quarto)){	// Verificar se existe estadia com esse cliente e esse quarto
		vEstadia[nEstadia].setDataSaida(dia,mes,ano);
		vEstadia[nEstadia].setObservacao(observacao);
		vEstadia[nEstadia].setFormaPag(forma_pag);
		if(vQuarto[num_quarto].getDisponibilidade()==0){	//Verifica se o quarto foi usado, maneira de verificar se o quarto existe
			float valor;
			string tipo;
			string categoria;
			unsigned long dias;
			Data entrada;
			Data saida;
			tipo=vQuarto[num_quarto].getTipo();
			categoria=vQuarto[num_quarto].getCategoria();
			valor=vQuarto[num_quarto].defineValor(tipo,categoria);
			entrada=vEstadia[nEstadia].getDataEntrada();
			saida=vEstadia[nEstadia].getDataSaida();
			dias=dist_dias(entrada,saida);
			valor*=dias;
			vCliente[cod_cli].setConta(valor);
			vQuarto[num_quarto].setDisponibilidade();
			return valor;
		}else{
			return 2.0;	//ERRO Quarto estava em uso
		}
		}else{
			return 1.0;	//ERRO Estadia com esse nome não existe
		}
	}else{
		return 0.0;	//ERRO Cliente inexistente
	}
}
/*
void Hotelaria::acompanhante(int nEstadia,string nome,string telefone,int quantidade){
	vEstadia[nEstadia].acompanhante(nome,telefone,quantidade);
}*/

string Hotelaria::recupera_senha(int cod_func,string CPF,string cargo){
	string senha;
	senha=vFuncionario[cod_func].recupera_senha(CPF,cargo);
	return senha;
}

bool Hotelaria::login(int cod_func,string senha){
	string senha_d;
	if(vFuncionario[cod_func].getAtividade()==1){
		senha_d=vFuncionario[cod_func].getSenha();
		if(senha_d==senha){
			return 1;	//Autorizado
		}else{
			return 0;	//ERRO
		}
	}else{
		return 0;	//ERRO
	}
}

bool Hotelaria::altera_cargo(int cod_func,string cargo){
	vFuncionario[cod_func].setCargo(cargo);
	return 1;
}

bool Hotelaria::altera_data_admissao(int cod_func,string data_admissao){
	vFuncionario[cod_func].setDataAdmissao(data_admissao);
	return 1;
}

bool Hotelaria::altera_telefone(int cod_func,string telefone){
	vFuncionario[cod_func].setTelefone(telefone);
	return 1;
}

bool Hotelaria::altera_carga_horaria(int cod_func,int carga_horaria){
	vFuncionario[cod_func].setCargaHoraria(carga_horaria);
	return 1;
}

bool Hotelaria::altera_salario(int cod_func,float salario){
	vFuncionario[cod_func].setSalario(salario);
	return 1;
}

bool Hotelaria::desativa_func(int cod_func){
	if(vFuncionario[cod_func].getAtividade()==1){
		vFuncionario[cod_func].setAtividade();
		return 1;	//Sucesso
	}else{
		return 0;	//ERRO - Funcionário já desativado
	}
}
bool Hotelaria::altera_RG_func(int cod_func,string RG){
	vFuncionario[cod_func].setRG(RG);
	return 1;
}

bool Hotelaria::altera_CPF_func(int cod_func,string CPF){
	vFuncionario[cod_func].setCPF(CPF);
	return 1;
}

bool Hotelaria::altera_data_nasc_func(int cod_func,string data_nasc){
	vFuncionario[cod_func].setDataNasc(data_nasc);
	return 1;
}

bool Hotelaria::altera_endereco_func(int cod_func,string endereco){
	vFuncionario[cod_func].setEndereco(endereco);
	return 1;
}

bool Hotelaria::altera_nome_func(int cod_func,string nome){
	vFuncionario[cod_func].setNome(nome);
	return 1;
}

bool Hotelaria::altera_RG_cli(int cod_cli,string RG){
	vCliente[cod_cli].setRG(RG);
	return 1;
}

bool Hotelaria::altera_CPF_cli(int cod_cli,string CPF){
	vCliente[cod_cli].setCPF(CPF);
	return 1;
}

bool Hotelaria::altera_data_nasc_cli(int cod_cli,string data_nasc){
	vCliente[cod_cli].setDataNasc(data_nasc);
	return 1;
}

bool Hotelaria::altera_endereco_cli(int cod_cli,string endereco){
	vCliente[cod_cli].setEndereco(endereco);
	return 1;
}

bool Hotelaria::altera_nome_cli(int cod_cli,string nome){
	vCliente[cod_cli].setNome(nome);
	return 1;
}

