#include <string>
#include <iostream>
#include <stdio.h>
#include "Classes.h"
#include "Hotelaria.h"
#include <windows.h>

using namespace std;

int main(int argc,char** argv)
{
	Hotelaria hotel;
	Funcionario funcionario;
	Cliente cliente;
	int opcao=0;
	int opcao2=0;
	int opcao3 = 0;
	//cout << "Sistema de hotelaria VemDeZap" << endl;



cout << "          __  __                           " << endl;
cout << "         /\\ \\/\\ \\                          " << endl;
cout << "         \\ \\ \\ \\ \\     __     ___ ___      " << endl;
cout << "          \\ \\ \\ \\ \\  /'__`\\ /' __` __`\\    " << endl;
cout << "           \\ \\ \\_/ \\/\\  __/ /\\ \\/\\ \\/\\ \\   " << endl;
cout << "            \\ `\\___/\\ \\____\\\\ \\_\\ \\_\\ \\_\\  " << endl;
cout << "             `\\/__/  \\/____/ \\/_/\\/_/\\/_/  " << endl;
cout << "                                           " << endl;
cout << "                                           " << endl;
cout << "                ____                       " << endl;
cout << "               /\\  _`\\                     " << endl;
cout << "               \\ \\ \\/\\ \\     __            " << endl;
cout << "                \\ \\ \\ \\ \\  /'__`\\          " << endl;
cout << "                 \\ \\ \\_\\ \\/\\  __/          " << endl;
cout << "                  \\ \\____/\\ \\____\\         " << endl;
cout << "                   \\/___/  \\/____/         " << endl;
cout << "                                           " << endl;
cout << "                                           " << endl;
cout << "          ________                         " << endl;
cout << "         /\\_____  \\                        " << endl;
cout << "         \\/____//'/'      __     _____     " << endl;
cout << "              //'/'     /'__`\\  /\\ '__`\\   " << endl;
cout << "             //'/'___  /\\ \\L\\.\\_\\ \\ \\L\\ \\  " << endl;
cout << "             /\\_______\\\\ \\__/.\\_\\\\ \\ ,__/  " << endl;
cout << "             \\/_______/ \\/__/\\/_/ \\ \\ \\/   " << endl;
cout << "                                   \\ \\_\\   " << endl;
cout << "                                    \\/_/   " << endl;
cout << "                                           " << endl;
	system("pause");
	do{
        system("cls");
        cout << "   MENU PRINCIPAL" << endl << endl;
		cout << "   1-Quartos" << endl;
		cout << "   2-Check-in" << endl;
		cout << "   3-Check-out" << endl;
		cout << "   4-Funcionarios" << endl;
		cout << "   5-Clientes" << endl;
		cout << "   0-Sair" << endl;
		cout << "   Escolha uma opcao: ";
		cin >> opcao3;
        cout << endl;

		string nome_pessoa = "";
		string rg = "";
		string cpf = "";
		string data_nasc = "";
		string endereco = "";

		string cargo = "";
		string data_adm = "";
		string telefone = "";
		int carga_h = 0;
		float salario = 0;
		string senha = "";
		int cod_func = 0;

		string tipo = "";
		string categoria = "";
		string nome_cliente = "";
		string observacao = "";
		string forma_pagamento = "";

		string nome_acompanhante = "";
		string tel_acompanhante = "";
		bool acompanhante;
		int cod_cliente = 0;
		int dia_saida = 0;
		int mes_saida = 0;
        int ano_saida = 0;
        int dia_entrada = 0;
        int mes_entrada = 0;
        int ano_entrada = 0;
        int nEstadia = 0;

        Quarto quarto;
        float valor;
        int num_quarto = 0;




		switch (opcao3){
			case 1: // Quartos
				do{
                    system("cls");
                    cout << "   QUARTOS" << endl << endl;
					cout << "   1-Cadastrar" << endl;
					cout << "   2-Verificar Disponibilidade" << endl;
					cout << "   3-Alterar" << endl;
					cout << "   0-Retornar" << endl;
					cout << "   Escolha uma opcao: ";
					cin >> opcao2;
					switch(opcao2){
						case 1:
						    system("cls");
                            cout << "   QUARTOS -> CADASTRAR" << endl << endl;
							cout << "   Digite o tipo: ";
							cin >> tipo;
							quarto.setTipo(tipo);
							cout << "   Digite a categoria: ";
							cin >> categoria;
							quarto.setCategoria(categoria);
							valor=quarto.defineValor(tipo,categoria);
							quarto.setValor(valor);
							cout << "   O valor do quarto e: " << valor << endl;
							hotel.cadastro_quarto(quarto);
							system("pause");
							break;
                        case 2:
                            system("cls");
                            cout << "   QUARTOS -> VERIFICAR DISPONIBILIDADE" << endl << endl;
                            cout << "   Digite o numero do quarto: ";
                            cin >> num_quarto;
                            quarto = hotel.consulta_quarto(num_quarto);
                            if(quarto.getDisponibilidade() == 1){
                                cout << "   O quarto de tipo " << quarto.getTipo() << " e de categoria " << quarto.getCategoria() << " esta disponivel" << endl;
                                system("pause");
                            }else{
                                cout << "   O quarto de tipo " << quarto.getTipo() << " e de categoria " << quarto.getCategoria() << " esta ocupado" << endl;
                                system("pause");
                            }
                            break;
                        case 3:
                            system("cls");
                            cout << "   QUARTOS -> ALTERAR DADOS" << endl << endl;
                            cout << "   Digite o numero do quarto a ser alterado: ";
                            cin >> num_quarto;
                            cout << "   Digite o novo tipo: ";
                            cin >> tipo;
                            cout << "   Digite a nova categoria: ";
                            cin >> categoria;
                            valor = hotel.altera_quarto(num_quarto, tipo, categoria);
                            cout << "   O novo valor e: " << valor << endl;
                            system("    pause");
                            break;

                    }
				}while(opcao2!=0);
                break;
			case 2:
                system("cls");
                cout << "   CHECK IN" << endl << endl;
                cout << "   Digite o numero da estadia: ";
                cin >> nEstadia;
                cout << "   Digite o codigo do cliente: ";
                cin >> cod_cliente;
                cout << "   Digite o nome do cliente: ";
                cin >> nome_cliente;
                cout << "   Digite o dia de entrada: ";
                cin >> dia_entrada;
                cout << "   Digite o mes de entrada: ";
                cin >> mes_entrada;
                cout << "   Digite o ano de entrada: ";
                cin >> ano_entrada;
                cout << "   Digite o numero do quarto: " ;
                cin >> num_quarto;
                cout << "   Digite o telefone: " ;
                cin >> telefone;
                hotel.check_in(nEstadia, nome_cliente, cod_cliente, dia_entrada, mes_entrada, ano_entrada, num_quarto, telefone);
                cout << "   Tem acompanhante?(1-Sim, 0-Nao)";
                cin >> acompanhante;
                if(acompanhante==1){
                    cout << "   Digite o nome do acompanhante: ";
                    cin >> nome_acompanhante;
                    cout << "   Digite o telefone do acompanhante: ";
                    cin >> tel_acompanhante;
                    hotel.acompanhante(nEstadia, nome_acompanhante, tel_acompanhante);
                    cout << "   Check in realizado com sucesso." << endl;
                    system("pause");
                	break;
                }
                else{
                    cout << "   Check in realizado com sucesso." << endl;
                    system("pause");
                	break;
                }
			case 3: //Check out
                    system("cls");
                    cout << "   CHECK OUT" << endl << endl;
                    cout << "   Digite o numero da estadia: ";
                    cin >> nEstadia;
                    cout << "   Digite o codigo do cliente: ";
                    cin >> cod_cliente;
                    cout << "   Digite o nome do cliente: ";
                    cin >> nome_cliente;
                    cout << "   Digite o dia de saida: ";
                    cin >> dia_saida;
                    cout << "   Digite o mes de saida: ";
                    cin >> mes_saida;
                    cout << "   Digite o ano de saida: ";
                    cin >> ano_saida;
                    cout << "   Digite o numero do quarto: " ;
                    cin >> num_quarto;
                    cout << "   Digite a observacao: " ;
                    cin >> observacao;
                    cout << "   Digite a forma de pagamento: " ;
                    cin >> forma_pagamento;

                    valor = hotel.check_out(nEstadia, cod_cliente, nome_cliente, dia_saida, mes_saida, ano_saida, num_quarto, observacao, forma_pagamento);

                    if(valor == 0.0){
                        cout << "   O cliente informado nao existe." << endl;
                        system("pause");
                    }
                    else if(valor == 1.0){
                        cout << "   O check in nao foi realizado." << endl;
                        system("pause");
                    }
                    else if(valor == 2.0){
                        cout << "   O quarto informado nao confere com o cliente." << endl;
                        system("pause");
                    }
                    else{
                        cout << "   O valor a ser pago apos o check out e: " << valor << endl;
                        system("pause");
                        break;
                    }
			case 4:
			    do{
                    system("cls");
                    cout << "FUNCIONARIOS" << endl << endl;
					cout << "1-Cadastrar" << endl;
					cout << "2-Alterar" << endl;
					cout << "3-Consultar" << endl;
					cout << "4-Desativar" << endl;
					cout << "0-Retornar" << endl;
					cout << "Escolha uma opcao: ";
					cin >> opcao2;
					switch(opcao2){
						case 1:
						    system("cls");
						    cout << "FUNCIONARIOS -> CADASTRO DE FUNCIONARIO" << endl << endl;
							cout << "Digite o nome: " ;
							cin >> nome_pessoa;
							funcionario.setNome(nome_pessoa);
							cout << "Digite o RG: " ;
							cin >> rg;
							funcionario.setRG(rg);
							cout << "Digite o CPF: " ;
							cin >> cpf;
							funcionario.setCPF(cpf);
							cout << "Digite a data de nascimento: " ;
							cin >> data_nasc;
							funcionario.setDataNasc(data_nasc);
							cout << "Digite o endereço: " ;
							cin >> endereco;
							funcionario.setEndereco(endereco);
							cout << "Digite o cargo: " ;
							cin >> cargo;
							funcionario.setCargo(cargo);
							cout << "Digite a data de admissao: " ;
							cin >> data_adm;
							funcionario.setDataAdmissao(data_adm);
							cout << "Digite o telefone: " ;
							cin >> telefone;
							funcionario.setTelefone(telefone);
							cout << "Digite o carga horaria: " ;
							cin >> carga_h;
							funcionario.setCargaHoraria(carga_h);
							cout << "Digite o salario: " ;
							cin >> salario;
							funcionario.setSalario(salario);
							hotel.cadastro_func(funcionario);
							system("pause");
							break;
                        case 2:
                            do{
                                    system("cls");
                                    cout << "FUNCIONARIOS -> ALTERAR INFORMACOES" << endl << endl;
                                    cout << "1-Cargo" << endl;
                                    cout << "2-Salario" << endl;
                                    cout << "3-Carga horaria" << endl;
                                    cout << "4-Data Admissao" << endl;
                                    cout << "5-Telefone" << endl;
                                    cout << "0-Retornar" << endl;
                                    cout << "Escolha uma opcao: ";
                                    cin >> opcao;
                                        switch (opcao){
                                            case 1:
                                                cout << "Digite o codigo do funcionario: ";
                                                cin >> cod_func;
                                                funcionario = hotel.consulta_func(cod_func);
                                                cout << "Digite o novo cargo: ";
                                                cin >> cargo;
                                                funcionario.setCargo(cargo);
                                                system("pause");
                                                break;
                                            case 2:
                                                cout << "Digite o codigo do funcionario: ";
                                                cin >> cod_func;
                                                funcionario = hotel.consulta_func(cod_func);
                                                cout << "Digite o novo salario: " ;
                                                cin >> salario;
                                                funcionario.setSalario(salario);
                                                system("pause");
                                                break;
                                            case 3:
                                                cout << "Digite o codigo do funcionario: ";
                                                cin >> cod_func;
                                                funcionario = hotel.consulta_func(cod_func);
                                                cout << "Digite a nova carga horaria: " ;
                                                cin >> carga_h;
                                                funcionario.setCargaHoraria(carga_h);
                                                system("pause");
                                                break;
                                            case 4:
                                                cout << "Digite o codigo do funcionario: ";
                                                cin >> cod_func;
                                                funcionario = hotel.consulta_func(cod_func);
                                                cout << "Digite a nova data de admissao: " ;
                                                cin >> data_adm;
                                                funcionario.setDataAdmissao(data_adm);
                                                system("pause");
                                                break;
                                            case 5:
                                                cout << "Digite o codigo do funcionario: ";
                                                cin >> cod_func;
                                                funcionario = hotel.consulta_func(cod_func);
                                                cout << "Digite o novo telefone: " ;
                                                cin >> telefone;
                                                funcionario.setTelefone(telefone);
                                                system("pause");
                                                break;
                                       }
                                }while(opcao != 0);
                                break;
                         case 3:
                            system("cls");
                            cout << "   FUNCIONARIOS -> CONSULTAR INFORMACOES" << endl << endl;
                            cout << "   Digite o codigo do funcionario: ";
                            cin >> cod_func;
                            funcionario = hotel.consulta_func(cod_func);
                                cout << "   Nome: " << funcionario.getNome() << endl;
                                cout << "   RG: " << funcionario.getRG() << endl;
                                cout << "   CPF: " << funcionario.getCPF() << endl;
                                cout << "   Data de nascimento: " << funcionario.getDataNasc() << endl;
                                cout << "   Endereco: " << funcionario.getEndereco() << endl;
                                cout << "   Cargo: " << funcionario.getCargo() << endl;
                                cout << "   Carga horaria: " << funcionario.getCargaHoraria() << endl;
                                cout << "   Salario: " << funcionario.getSalario() << endl;
                                cout << "   Data de admissao: " << funcionario.getDataAdmissao() << endl;
                                cout << "   Telefone: " << funcionario.getTelefone() << endl;
                                system("pause");
                                break;
                         case 4:
                            system("cls");
                            cout << "   FUNCIONARIOS -> DESATIVAR FUNCIONARIO" << endl << endl;
                            cout << "   Digite o codigo do funcionario: ";
                            cin >> cod_func;
                            funcionario = hotel.consulta_func(cod_func);
                            funcionario.setAtividade();
                            cout << "   Funcionario desativado." << endl;
                            system("pause");
                            break;
                        }

				}while(opcao2!=0);


			case 5:
				do{
                    system("cls");
                    cout << "   CLIENTE" << endl << endl;
					cout << "   1-Cadastrar" << endl;
					cout << "   2-Alterar" << endl;
					cout << "   3-Consultar" << endl;
					cout << "   0-Retornar" << endl;
					cout << "   Escolha uma opcao: ";
					cin >> opcao2;
					switch(opcao2){
                        case 1:
                            system("cls");
						    cout << "   CLIENTES -> CADASTRO DE CLIENTES" << endl << endl;
							cout << "   Digite o nome: " ;
							cin >> nome_pessoa;
							cliente.setNome(nome_pessoa);
							cout << "   Digite o RG: " ;
							cin >> rg;
							cliente.setRG(rg);
							cout << "   Digite o CPF: " ;
							cin >> cpf;
							cliente.setCPF(cpf);
							cout << "   Digite a data de nascimento: " ;
							cin >> data_nasc;
							cliente.setDataNasc(data_nasc);
							cout << "   Digite o endereco: " ;
							cin >> endereco;
							cliente.setEndereco(endereco);
							cliente.setConta(0);
							hotel.cadastro_cli(cliente);
							system("pause");
							break;
                        case 2:
                            do{
                                    system("cls");
                                    cout << "   CLIENTES -> ALTERAR INFORMACOES" << endl << endl;
                                    cout << "   1-Nome" << endl;
                                    cout << "   2-RG" << endl;
                                    cout << "   3-CPF" << endl;
                                    cout << "   4-Data de nascimento" << endl;
                                    cout << "   5-Endereco" << endl;
                                    cout << "   0-Retornar" << endl;
                                    cout << "   Escolha uma opcao: ";
                                    cin >> opcao;
                                    switch (opcao){
                                        case 1:
                                            cout << "   Digite o codigo do cliente: ";
                                            cin >> cod_cliente;
                                            cliente = hotel.consulta_cli(cod_cliente);
                                            cout << "   Digite o novo nome: ";
                                            cin >> nome_pessoa;
                                            cliente.setNome(nome_pessoa);
                                            system("pause");
                                            break;
                                        case 2:
                                            cout << "   Digite o codigo do cliente: ";
                                            cin >> cod_cliente;
                                            cliente = hotel.consulta_cli(cod_cliente);
                                            cout << "   Digite o novo RG: " ;
                                            cin >> rg;
                                            cliente.setRG(rg);
                                            system("pause");
                                            break;
                                        case 3:
                                            cout << "   Digite o codigo do cliente: ";
                                            cin >> cod_cliente;
                                            cliente = hotel.consulta_cli(cod_cliente);
                                            cout << "   Digite o novo CPF: " ;
                                            cin >> cpf;
                                            cliente.setCPF(cpf);
                                            system("pause");
                                            break;
                                        case 4:
                                            cout << "   Digite o codigo do cliente: ";
                                            cin >> cod_cliente;
                                            cliente = hotel.consulta_cli(cod_cliente);
                                            cout << "   Digite a nova data de nascimento: " ;
                                            cin >> data_nasc;
                                            cliente.setDataNasc(data_nasc);
                                            system("pause");
                                            break;
                                        case 5:
                                            cout << "   Digite o codigo do cliente: ";
                                            cin >> cod_cliente;
                                            cliente = hotel.consulta_cli(cod_cliente);
                                            cout << "   Digite o novo endereco: " ;
                                            cin >> endereco;
                                            cliente.setEndereco(endereco);
                                            system("pause");
                                            break;
                                    }
                            }while(opcao != 0);
                                break;
                         case 3:
                            system("cls");
                            cout << "   CLIENTES -> CONSULTAR INFORMACOES" << endl << endl;
                            cout << "   Digite o codigo do funcionario: ";
                            cin >> cod_func;
                            cliente = hotel.consulta_cli(cod_cliente);
                                cout << "   Nome: " << cliente.getNome() << endl;
                                cout << "   RG: " << cliente.getRG() << endl;
                                cout << "   CPF: " << cliente.getCPF() << endl;
                                cout << "   Data de nascimento: " << cliente.getDataNasc() << endl;
                                cout << "   Endereco: " << cliente.getEndereco() << endl;
                                system("pause");
                                break;

	}

	}while(opcao2 != 0);


	}
}while(opcao3!=0);
    return 0;
}
