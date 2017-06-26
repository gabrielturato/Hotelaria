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
	cout << "Sistema de hotelaria VemDeZap" << endl;
	do{
		cout << "1-Quartos" << endl;
		cout << "2-Check-in" << endl;
		cout << "3-Check-out" << endl;
		cout << "4-Relatorios" << endl; //Não disponível ainda
		cout << "5-Funcionários" << endl;
		cout << "6-Clientes" << endl;
		cin >> opcao;
		switch (opcao){
			case 1:
				do{
					cout << "1-Cadastrar" << endl;
					cout << "2-Verificar Disponibilidade" << endl;
					cout << "3-Alterar" << endl;
					cin >> opcao;
					switch(opcao){
						case 1:
							Quarto quarto;
							string tipo;
							string categoria;
							float valor;
							cout << "Digite o tipo: " << endl;
							cin >> tipo;
							quarto.setTipo(tipo);
							cout << "Digite a categoria: " << endl;
							cin >> categoria;
							quarto.setCategoria(categoria);
							valor=quarto.defineValor(tipo,categoria);
							quarto.setValor(valor);
							cout << "O valor do quarto e:" << valor << endl;
							hotel.cadastro_quarto(quarto);
					}
				}while(opcao!=0);
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				break;
		}
	}while(opcao!=0);
	return 0;
}
