#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <cstdlib>
#include <ctime>


using namespace std;

typedef struct date{
    int day;
    int month;
    int year;
}Date;

typedef struct client {
    int code;
    string name;
    bool active;

    void print(){
     cout<<"Codigo: "<< code << ","<< " Nome: " << name << "," << " Ativo: "
    << (active  ? "Sim" : "Nao" ) << ";"<<endl;
    }
}Client;

typedef struct fuel{
    int code;
    string name;
    float price;
    Date changeDatePrice;

    void print(){
        cout<<"Codigo: " << code << "," << " Nome: " << name << "," << " Preco: " << price << ","<<
        " Data de alteracao: "<< changeDatePrice.day <<"/"<< changeDatePrice.month <<"/" <<
         changeDatePrice.year << ";"<<endl;
    }
}Fuel;

typedef struct sales{
    Client cliente;
    Fuel combustivel;
    bool paidOut;
    double theAmount;
    double literValue;
    double total;
    string responsible;
    Date date;

    void print(){
        cout << "Data: " << date.day <<"/"<< date.month <<"/" << date.year<< ", Codigo do cliente: "
        << cliente.code << ", Codigo do combustivel: "<< combustivel.code<< ", Quantidade: " << theAmount
        << ", Valor do litro: " << literValue << ", Total: "<< total << ", Reponsavel: "<< responsible
        << ", Pago: " << (paidOut ? "Sim" : "Nao") << ";"<< endl;
        }
}Sales;

void init(map<int,Client>& c, map<int,Fuel>& f);
void listFuel(map<int,Fuel>&fuel);
void listClient(map<int,Client>&Client);
void listSales(map<int,Sales>&sales);

int randomId()
{
    srand(time(0));
    int randomNumber = 100 + rand() % 899;
    return randomNumber;
}

void cadastrarUsuario(map<int, Client>&client)
{
    system("clear||cls");
    string nome;
    bool ativo;
    Client novo;



    cout<<"-------------Cadastrar usuário---------------\n";
    cout<<"Digite o nome do cliente\n";
    cin>> nome;
    cout<<"Cliente ativo(true or false)?\n";
    cin>> ativo;

    int id = 1;

    novo.code = id++;
    novo.name = nome;
    novo.active = ativo;
    client[novo.code] = novo;
}

void cadastrarVenda(map<int,Sales>&sales)
{
    system("clear||cls");
    int idCliente;
    int combustivel;
    float litros;
    bool pago;
    Sales venda;
    int dia,mes,ano;



    cout<<"-------------Cadastrar venda---------------\n";
    cout << "Digite o id do Cliente:\n";
    cin >> idCliente;
    cout << "Digite o Codigo do Produto:\n";
    cin >> combustivel;
    cout << "Digite quantidade de litros abastecidos:\n";
    cin >> litros;
    cout << "Data da compra(dia,mes,ano):\n";
    cin >> dia;
    cin >> mes;
    cin >> ano;
    cout << "Foi pago?: (0= nao, 1= sim)\n";
    cin >> pago;

    venda.cliente.code = idCliente;
    venda.combustivel.code = combustivel;
    venda.paidOut = pago;
    venda.date.day = dia;
    venda.date.month = mes;
    venda.date.year = ano;


    sales[idCliente] = venda;
}


int main() {
    map<int,Client>client;
    map<int,Fuel>fuel;
    map<int,Sales>sales;
    init(client,fuel);
    int opcao;
    bool sair = 1;

    do{

    int opcao;
    cout <<"-------------------MENU----------------------\n";
    cout <<"1.Cadastrar usuario\n";
    cout <<"2.Cadastrar venda\n";
    cout <<"3.Verificar vendas\n";
    cout <<"4.Verificar clientes\n";
    cout <<"5.Verificar combustivel \n";
    cout <<"---------------------------------------------\n";
    cin >> opcao;

    switch(opcao){
        case 1:
               cadastrarUsuario(client);
            break;

        case 2:
                cadastrarVenda(sales);
            break;

        case 3:
             listSales(sales);
            break;
        case 4:
            listClient(client);
            break;

        case 5:
            listFuel(fuel);
            break;
    }
    }while(sair = 1);


}

void listClient(map<int,Client>&client){
    cout << "\n  Clientes \n\n";
    for(auto i: client){
        if(i.second.active){
        i.second.print();
        }
    }
}



void listFuel(map<int,Fuel>&fuel){
    cout << "\n  Combustiveis \n\n";
    for(auto i: fuel){
        i.second.print();
    }
}

void listSales(map<int,Sales>&sales){
    cout << "\n  Vendas \n\n";
    for(auto i: sales){
        i.second.print();
    }
}

void init(map<int,Client>& c,map<int,Fuel>& f){
    Client client;
    Fuel fuel;
    client.code = 2235;
    c[client.code].code = 45265;
    c[client.code].name = "Hugo Ferreira";
    c[client.code].active = true;

    client.code = 4444;
    c[client.code].code = 48964;
    c[client.code].name = "Vitor alexandre";
    c[client.code].active = false;

    client.code = 2877;
    c[client.code].code = 66958;
    c[client.code].name = "Fulano Ciclano";
    c[client.code].active = true;

    fuel.code = 3654;
    f[fuel.code].code = 568916;
    f[fuel.code].name = "Diesel s10";
    f[fuel.code].price = 5.30;
    f[fuel.code].changeDatePrice.day = 30;
    f[fuel.code].changeDatePrice.month = 11;
    f[fuel.code].changeDatePrice.year = 2022;

    fuel.code = 5584;
    f[fuel.code].code = 56562;
    f[fuel.code].name = "Gasolina comum";
    f[fuel.code].price = 6.49;
    f[fuel.code].changeDatePrice.day = 23;
    f[fuel.code].changeDatePrice.month = 6;
    f[fuel.code].changeDatePrice.year = 2021;

    fuel.code = 2987;
    f[fuel.code].code = 65631;
    f[fuel.code].name = "Etanol comum";
    f[fuel.code].price = 7.49;
    f[fuel.code].changeDatePrice.day = 02;
    f[fuel.code].changeDatePrice.year = 2022;
}

