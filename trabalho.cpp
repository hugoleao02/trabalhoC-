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
    double price;
    Date changeDatePrice;

    void print(){
        cout<<"Codigo: " << code << ",\n" << " Nome: " << name << "," << " Preco: " << price << ",\n"<<
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
    Date date;

    void print(){
        cout << "Data: " << date.day <<"/"<< date.month <<"/" << date.year<< ", Codigo do cliente: "
        << cliente.code << ", Codigo do combustivel: "<< combustivel.code<< ", Quantidade: " << theAmount
        << ", Valor do litro: " << literValue << ", Total: "<< total <<", Pago: " << (paidOut ? "Sim" : "Nao") << ";"<< endl;
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
    cout<<"Cliente ativo(0= nao, 1= sim)?\n";
    cin>> ativo;

    int id = 8;

    novo.code = id++;
    novo.name = nome;
    novo.active = ativo;
    client[novo.code] = novo;
}

void cadastrarVenda(map<int,Sales>&sales);

int main() {

    map<int,Client>client;
    map<int,Fuel>fuel;
    map<int,Sales>sales;
    init(client,fuel);
    int opcao;
    bool sair = 1;

    while(sair = 1){
    system("clear||cls");
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

};

}

void listClient(map<int,Client>&client){
    system("clear||cls");
    cout << "\n  Clientes \n\n";
    for(auto i: client){
        if(i.second.active){
        i.second.print();
        }
    }
    char voltar;
    cout<<"Deseja voltar para o menu? (s ou n)\n";
    cin>> voltar;
        if(voltar == 's'){
            main();
        }
}

void cadastrarVenda(map<int,Sales>&sales){
    system("clear||cls");
    int idCliente;
    int combustivel;
    double litros;
    bool pago;
    Sales venda;
    int dia,mes,ano;
    Fuel fuel;


    cout<<"-------------Cadastrar venda---------------\n";
    cout << "Digite o id do Cliente:\n";
    cin >> idCliente;
    cout << "Digite o id do combustivel:\n";
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
    venda.theAmount = litros;
    venda.paidOut = pago;
    venda.literValue = fuel.price;
    venda.total = fuel.price *litros;
    venda.date.day = dia;
    venda.date.month = mes;
    venda.date.year = ano;

    sales[idCliente] = venda;
}



void listFuel(map<int,Fuel>&fuel){
    system("clear||cls");
    cout << "\n  Combustiveis \n\n";
    for(auto i: fuel){
        i.second.print();
    }
    char voltar;
    cout<<"Deseja voltar para o menu? (s ou n)\n";
    cin>> voltar;
         if(voltar == 's'){
            main();
        }
}

void listSales(map<int,Sales>&sales){
    system("clear||cls");
    cout << "\n  Vendas \n\n";
    for(auto i: sales){
        i.second.print();
    }
    char voltar;
    cout<<"Deseja voltar para o menu? (s ou n)\n";
    cin>> voltar;
         if(voltar == 's'){
            main();
        }
}

void init(map<int,Client>& c,map<int,Fuel>& f){
    Client client;
    Fuel fuel;
    client.code = 1;
    c[client.code].code = 1;
    c[client.code].name = "Hugo Ferreira";
    c[client.code].active = true;

    client.code = 2;
    c[client.code].code = 2;
    c[client.code].name = "Vitor alexandre";
    c[client.code].active = false;

    client.code = 4;
    c[client.code].code = 4;
    c[client.code].name = "Fulano Ciclano";
    c[client.code].active = true;

    client.code = 5;
    c[client.code].code = 5;
    c[client.code].name = "Beutrano Tetrano";
    c[client.code].active = true;

    client.code = 6;
    c[client.code].code = 6;
    c[client.code].name = "Caio Ciclano";
    c[client.code].active = true;

    client.code = 7;
    c[client.code].code = 7;
    c[client.code].name = "Arthur Ciclano";
    c[client.code].active = true;

    fuel.code = 1;
    fuel.name = "Diesel s10";
    fuel.price = 5.00;
    fuel.changeDatePrice.day = 30;
    fuel.changeDatePrice.month = 11;
    fuel.changeDatePrice.year = 2022;

    f[fuel.code] = fuel;

    fuel.code = 2;
    fuel.name = "Gasolina comum";
    fuel.price = 6.40;
    fuel.changeDatePrice.day = 23;
    fuel.changeDatePrice.month = 6;
    fuel.changeDatePrice.year = 2021;

    f[fuel.code] = fuel;

    fuel.code = 3;
    fuel.name = "Etanol comum";
    fuel.price = 7.20;
    fuel.changeDatePrice.day = 02;
    fuel.changeDatePrice.year = 2022;

     f[fuel.code] = fuel;
}

