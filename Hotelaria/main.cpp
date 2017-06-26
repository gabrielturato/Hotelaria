#include <string>
#include <iostream>
#include <stdio.h>
#include "Classes.h"
#include "Hotelaria.h"

using namespace std;

int main(int argc,char** argv)
{
	Hotelaria hotel;
	int opcao=0;
	int opcao2=0;
	cout << "Sistema de hotelaria VemDeZap" << endl;
	do{
		cout << "1-Quartos" << endl;
		cout << "2-Check-in" << endl;
		cout << "3-Check-out" << endl;
		cout << "4-Relatorios" << endl; //Não disponível ainda
		cout << "5-Funcionários" << endl;
		cout << "6-Clientes" << endl;
		cout << "0-Sair" << endl;
		cin >> opcao;

		string tipo = "";
		string categoria = "";
		string nome_cliente = "";
		string observacao = "";
		string forma_pagamento = "";
		int cod_cliente = 0;
		int dia_saida = 0;
		int mes_saida = 0;
        int ano_saida = 0;
        int nEstadia = 0;

        Quarto quarto;
        float valor;
        int num_quarto = 0;


		switch (opcao){
			case 1: // Quartos
				do{
					cout << "1-Cadastrar" << endl;
					cout << "2-Verificar Disponibilidade" << endl;
					cout << "3-Alterar" << endl;
					cout << "0-Retornar" << endl;
					cin >> opcao2;
					switch(opcao2){
						case 1:
							cout << "Digite o tipo: " << endl;
							cin >> tipo;
							quarto.setTipo(tipo);
							cout << "Digite a categoria: " << endl;
							cin >> categoria;
							quarto.setCategoria(categoria);
							valor=quarto.defineValor(tipo,categoria);
							quarto.setValor(valor);
							cout << "O valor do quarto e: " << valor << endl;
							hotel.cadastro_quarto(quarto);
							break;
                        case 2:
                            cout << "Digite o numero do quarto: " << endl;
                            cin >> num_quarto;
                            quarto = hotel.consulta_quarto(num_quarto);
                            if(quarto.getDisponibilidade() == 1)
                                cout << "O quarto esta disponivel." << endl;
                            else
                                cout << "O quarto esta ocupado." << endl;
                            break;
                        case 3:
                            cout << "Digite o numero do quarto a ser alterado: " << endl;
                            cin >> num_quarto;
                            cout << "Digite o novo tipo: " << endl;
                            cin >> tipo;
                            cout << "Digite a nova categoria: " << endl;
                            cin >> categoria;
                            valor = hotel.altera_quarto(num_quarto, tipo, categoria);
                            cout << "O novo valor e: " << valor << endl;
                            break;

                    }
				}while(opcao2!=0);
                break;
			case 2:

				break;
			case 3: //Check out
                    cout << "Digite o numero da estadia: " << endl;
                    cin >> nEstadia;
                    cout << "Digite o codigo do cliente: " << endl;
                    cin >> cod_cliente;
                    cout << "Digite o nome do cliente: " << endl;
                    cin >> nome_cliente;
                    cout << "Digite o dia de saida: " << endl;
                    cin >> dia_saida;
                    cout << "Digite o mes de saida: " << endl;
                    cin >> mes_saida;
                    cout << "Digite o ano de saida: " << endl;
                    cin >> ano_saida;
                    cout << "Digite o numero do quarto: " << endl;
                    cin >> num_quarto;
                    cout << "Digite a observacao: " << endl;
                    cin >> observacao;
                    cout << "Digite a forma de pagamento: " << endl;
                    cin >> forma_pagamento;

                    valor = hotel.check_out(nEstadia, cod_cliente, nome_cliente, dia_saida, mes_saida, ano_saida, num_quarto, observacao, forma_pagamento);

                    if(valor == 0.0)
                        cout << "O cliente informado nao existe." << endl;
                    else if(valor == 1.0)
                        cout << "O check in nao foi realizado." << endl;
                    else if(valor == 2.0)
                        cout << "O quarto informado nao confere com o cliente." << endl;
                    else
                        cout << "O valor a ser pago apos o check out e: " << valor;
                    break;
			case 4:	break; //Relatorios
			case 5:
			    do{
					cout << "1-Cadastrar" << endl;
					cout << "2-Alterar" << endl;
					cout << "3-Consultar" << endl;
					cout << "4-Desativar" << endl;
					cout << "0-Retornar" << endl;
					cin >> opcao2;
					switch(opcao2){
						case 1:
							cout << "Digite o tipo: " << endl;
							cin >> tipo;
							quarto.setTipo(tipo);
							cout << "Digite a categoria: " << endl;
							cin >> categoria;
							quarto.setCategoria(categoria);
							valor=quarto.defineValor(tipo,categoria);
							quarto.setValor(valor);
							cout << "O valor do quarto e: " << valor << endl;
							hotel.cadastro_quarto(quarto);
							break;
                        case 2:
                            cout << "Digite o numero do quarto: " << endl;
                            cin >> num_quarto;
                            quarto = hotel.consulta_quarto(num_quarto);
                            if(quarto.getDisponibilidade() == 1)
                                cout << "O quarto esta disponivel." << endl;
                            else
                                cout << "O quarto esta ocupado." << endl;
                            break;
                        case 3:
                            cout << "Digite o numero do quarto a ser alterado: " << endl;
                            cin >> num_quarto;
                            cout << "Digite o novo tipo: " << endl;
                            cin >> tipo;
                            cout << "Digite a nova categoria: " << endl;
                            cin >> categoria;
                            valor = hotel.altera_quarto(num_quarto, tipo, categoria);
                            cout << "O novo valor e: " << valor << endl;
                            break;

                    }
				}while(opcao2!=0);
                break; // Funcionarios
				break;
			case 6:
				break;
		}
	}while(opcao!=0);
	return 0;
}
