#include "Classes.h"
#include <string>
#include <iostream>
#include <stdio.h>
#ifndef HOTELARIA_H
#define HOTELARIA_H

using namespace std;

class Hotelaria{
	private:
		Estadia vEstadia[100];
		Funcionario vFuncionario[100];
		Cliente vCliente[100];
		Quarto vQuarto[100];
		int nEstadia;
		int nPessoa;
		int num_quarto;
		int cod_cli;
		int cod_func;
	public:
		Hotelaria();
		~Hotelaria();
		void cadastro_quarto(Quarto quarto);
		void cadastro_func(Funcionario funcionario);
		void cadastro_cli(Cliente cliente);
		bool check_in(int nEstadia,string nome,int cod_cli,int dia,int mes,int ano,int num_quarto,string telefone);
		Funcionario	consulta_func(int cod_func);
		Quarto	consulta_quarto(int num_quarto);
		Cliente consulta_cli(int cod_cli);
		Estadia	consulta_estadia(int nEstadia);
		float altera_quarto(int num_quarto,string tipo,string categoria);
		void disponibilidade(int num_quarto);
		float	check_out(int nEstadia,int cod_cli,string nome,int dia,int mes,int ano,int num_quarto,string observacao,string forma_pag);
		void	acompanhante(int nEstadia,string nome,string telefone);
		string	recupera_senha(int cod_func,string CPF,string cargo);
		bool	login(int cod_func, string senha);
		bool	altera_cargo(int cod_func,string cargo);
		bool	altera_data_admissao(int cod_func,string data_admissao);
		bool	altera_telefone(int cod_func,string telefone);
		bool	altera_carga_horaria(int cod_func,int carga_horaria);
		bool	altera_salario(int cod_func,float salario);
		bool	desativa_func(int cod_func);
		bool	altera_RG_func(int cod_func,string RG);
		bool	altera_CPF_func(int cod_func,string CPF);
		bool	altera_data_nasc_func(int cod_func,string data_nasc);
		bool	altera_endereco_func(int cod_func,string endereco);
		bool	altera_nome_func(int cod_func,string nome);
		bool	altera_RG_cli(int cod_cli,string RG);
		bool	altera_CPF_cli(int cod_cli,string CPF);
		bool	altera_data_nasc_cli(int cod_cli,string data_nasc);
		bool	altera_endereco_cli(int cod_cli,string endereco);
		bool	altera_nome_cli(int cod_cli,string nome);
};

#endif

