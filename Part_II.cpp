// GRUPO:
// GUSTAVO SOATTO SANTOS 2141790
//
//

// B)(70 pontos) Uma empresa financeira necessita de um programa que organize o seu cadastro de clientes. Desenvolva um programa em C++ que:
// 1. Permita cadastrar e gerenciar clientes com as seguintes informações: nome do cliente, CPF, endereço, data de nascimento, data do empréstimo, valor total do empréstimo e informações sobre parcelas mensais de empréstimo. Um cliente deve ser cadastrado por vez.
// 2. Permita gerenciar as parcelas. As parcelas de cada empréstimo (no máximo 12 parcelas, sendo que cada cliente pode ter apenas um empréstimo em vigência) devem ter as seguintes informações: valor, se já foi paga ou não, data do pagamento e data de vencimento. As parcelas devem ser todas iguais.
// 3. Tenha um menu que permita realizar as seguintes operações:
// i. Cadastrar cliente
// ii. Visualizar as informações de um cliente
// iii. Editar as informações de um cliente
// iv. Cadastrar parcela paga
// v. Cadastrar empréstimo.
// vi. Excluir cliente
// vii. Sair

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct parcela
{
    float valor;
    bool pagamento;
    string data_pagamento;
    string data_vencimento;
};

struct cliente
{
    string nome;
    string cpf;
    string endereco;
    string data_nascimento;
    string data_emprestimo;
    float total_emprestimo;
    float total_parcelas;
    parcela parcelas_mensais[12];
};

int meses(string mes_string)
{
    int mes_number = 0;

    if (mes_string == "jan" || mes_string == "janeiro")
    {
        mes_number = 1;
        return mes_number;
    }
    else if (mes_string == "fev" || mes_string == "fevereiro")
    {
        mes_number = 2;
        return mes_number;
    }
    else if (mes_string == "mar" || mes_string == "março" || mes_string == "marco")
    {
        mes_number = 3;
        return mes_number;
    }
    else if (mes_string == "abr" || mes_string == "abril")
    {
        mes_number = 4;
        return mes_number;
    }
    else if (mes_string == "mai" || mes_string == "maio")
    {
        mes_number = 5;
        return mes_number;
    }
    else if (mes_string == "jun" || mes_string == "junho")
    {
        mes_number = 6;
        return mes_number;
    }
    else if (mes_string == "jul" || mes_string == "julho")
    {
        mes_number = 7;
        return mes_number;
    }
    else if (mes_string == "ago" || mes_string == "agosto")
    {
        mes_number = 8;
        return mes_number;
    }
    else if (mes_string == "set" || mes_string == "setembro")
    {
        mes_number = 9;
        return mes_number;
    }
    else if (mes_string == "out" || mes_string == "outubro")
    {
        mes_number = 10;
        return mes_number;
    }
    else if (mes_string == "nov" || mes_string == "novembro")
    {
        mes_number = 11;
        return mes_number;
    }
    else if (mes_string == "dez" || mes_string == "dezembro")
    {
        mes_number = 12;
        return mes_number;
    }
    else
    {
        cout << "Mes invalido\n";
        return 0;
    }
}

string meses_for_string(int mes_number)
{
    string mes_string = "";

    switch (mes_number)
    {
    case 1:
        mes_string = "Janeiro";
        return mes_string;
    case 2:
        mes_string = "Fevereiro";
        return mes_string;
    case 3:
        mes_string = "Marco";
        return mes_string;
    case 4:
        mes_string = "Abril";
        return mes_string;
    case 5:
        mes_string = "Maio";
        return mes_string;
    case 6:
        mes_string = "Junho";
        return mes_string;
    case 7:
        mes_string = "Julho";
        return mes_string;
    case 8:
        mes_string = "Agosto";
        return mes_string;
    case 9:
        mes_string = "Setembro";
        return mes_string;
    case 10:
        mes_string = "Outubro";
        return mes_string;
    case 11:
        mes_string = "Novembro";
        return mes_string;
    case 12:
        mes_string = "Dezembro";
        return mes_string;
    default:
        cout << "Mes invalido, informe um número entre 1 - 12 de acordo com o mes desejado" << endl;
        return 0;
    }
}

int main()
{
    setlocale(LC_ALL, "pt_br.UTF-8");
    int user_option = 0, user_cliente_quantidade = 0, user_option_2 = 0;

    cout << "Quantos cliente deseja cadastrar?\n";
    cin >> user_cliente_quantidade;
    cliente user_cliente[user_cliente_quantidade];

    do
    {
        cout << "1. Cadastrar cliente\n"
             << "2. Visualizar as informacoes de um cliente\n"
             << "3. Editar as informacoes de um cliente\n"
             << "4. Cadastrar parcela paga\n"
             << "5. Cadastrar emprestimo\n"
             << "6. Excluir cliente\n"
             << "7. SAIR\n";
        cin >> user_option;

        if (user_option == 1) // i. Cadastrar cliente
        {
            cout << "Para cadastrar um cliente digite: \n";
            for (int i = 0; i < user_cliente_quantidade; i++)
            {
                cout << "Nome do cliente\n";
                cin >> user_cliente[i].nome;
                cout << "CPF\n";
                cin >> user_cliente[i].cpf;
                cout << "Endereco\n";
                cin >> user_cliente[i].endereco;
                cout << "Data de nascimento\n";
                cin >> user_cliente[i].data_nascimento;

                user_cliente[i].data_emprestimo = "00/00/00";
                user_cliente[i].total_emprestimo = 0.0;
                user_cliente[i].total_parcelas = 0.0;
                for (int j = 0; j < 12; j++)
                {
                    user_cliente[i].parcelas_mensais[j].valor = 0000;
                    user_cliente[i].parcelas_mensais[j].pagamento = false;
                    user_cliente[i].parcelas_mensais[j].data_pagamento = "00/00/00";
                    user_cliente[i].parcelas_mensais[j].data_vencimento = "00/00/00";
                }
            }
        }
        else if (user_option == 2) // ii. Visualizar as informações de um cliente
        {
            cout << "Qual cliente deseja ver?\n";
            cin >> user_option;
            if (user_option <= user_cliente_quantidade && user_option > 0)
            {
                cout << "Seu cliente " << user_option << endl;
                cout << user_cliente[user_option - 1].nome << endl
                     << user_cliente[user_option - 1].cpf << endl
                     << user_cliente[user_option - 1].endereco << endl
                     << user_cliente[user_option - 1].data_nascimento << endl
                     << user_cliente[user_option - 1].data_emprestimo << endl
                     << user_cliente[user_option - 1].total_emprestimo << endl
                     << user_cliente[user_option - 1].total_parcelas << endl;
                for (int k = 0; k < 12; k++)
                {
                    cout << "Informacoes das parcelas do mes de " << meses_for_string(k + 1) << endl;
                    cout << setprecision(2) << user_cliente[user_option - 1].parcelas_mensais[k].valor << endl;
                    cout << user_cliente[user_option - 1].parcelas_mensais[k].pagamento << endl;
                    cout << user_cliente[user_option - 1].parcelas_mensais[k].data_pagamento << endl;
                    cout << user_cliente[user_option - 1].parcelas_mensais[k].data_vencimento << endl;
                }
            }
            else
            {
                cout << "Opcao invalida, você tem " << user_cliente_quantidade << " cliente(s).\n";
            }
        }
        else if (user_option == 3) // iii. Editar as informações de um cliente
        {
            do
            {
                int user_option_3 = 0;
                string mes = "";
                char pagamento = '\n';

                cout << "Qual cliente deseja fazer alteracoes? (numero do cliente)\n";
                cin >> user_option;
                cout << "Qual dado deseja fazer a alteracao?\n"
                     << "1. Nome do cliente\n"
                     << "2. CPF\n"
                     << "3. Endereço\n"
                     << "4. Data de nascimento\n"
                     << "5. Informacoes das parcelas\n"
                     << "6. Informacoes dos emprestimos\n"
                     << "0. CANCELAR" << endl;
                cin >> user_option_2;
                if (user_option_2 == 1)
                {
                    cin >> user_cliente[user_option - 1].nome;
                }
                else if (user_option_2 == 2)
                {
                    cin >> user_cliente[user_option - 1].cpf;
                }
                else if (user_option_2 == 3)
                {
                    cin >> user_cliente[user_option - 1].endereco;
                }
                else if (user_option_2 == 4)
                {
                    cin >> user_cliente[user_option - 1].data_nascimento;
                }
                else if (user_option_2 == 5)
                {
                    do
                    {
                        cout << "Qual mês deseja fazer a alteracao? (jan,fev,mar,...)\n";
                        cin >> mes;
                        cout << "Qual dado da parcela deseja fazer a alteracao?\n"
                             << "1. Valor\n"
                             << "2. Pagamento(s/n)\n"
                             << "3. Data do pagamento\n"
                             << "4. Data do vencimento\n"
                             << "0. CANCELAR" << endl;
                        cin >> user_option_3;
                        switch (user_option_3)
                        {
                        case 1:
                            user_cliente[user_option - 1].parcelas_mensais[meses(mes)].valor = (user_cliente[user_option - 1].total_emprestimo / user_cliente[user_option - 1].total_parcelas);
                            break;
                        case 2:
                            cin >> pagamento;
                            if (pagamento == 's')
                            {
                                user_cliente[user_option - 1].parcelas_mensais[meses(mes)].pagamento = true;
                            }
                            else if (pagamento == 'n')
                            {
                                user_cliente[user_option - 1].parcelas_mensais[meses(mes)].pagamento = false;
                            }
                            else
                            {
                                cout << "Pagamento invalido\n";
                            }
                            break;
                        case 3:
                            cin >> user_cliente[user_option - 1].parcelas_mensais[meses(mes)].data_pagamento;
                            break;
                        case 4:
                            user_cliente[user_option - 1].parcelas_mensais[meses(mes)].data_vencimento;
                            break;
                        default:
                            break;
                        }
                    } while (user_option_3 != 0);
                }
                else if (user_option_2 == 6)
                {
                    do
                    {
                        cout << "Qual dado do emprestimo deseja fazer a alteracao?\n"
                             << "1. Data do emprestimo\n"
                             << "2. Valor do emprestimo\n"
                             << "3. Quantidade de parcelas que deseja pagar\n"
                             << "0. CANCELAR" << endl;
                        cin >> user_option_3;
                        switch (user_option_3)
                        {
                        case 1:
                            cin >> user_cliente[user_option - 1].data_emprestimo;
                            break;
                        case 2:
                            cin >> user_cliente[user_option - 1].total_emprestimo;
                            break;
                        case 3:
                            cin >> user_cliente[user_option - 1].total_parcelas;
                            break;
                        }
                    } while (user_option_3 != 0);

                    cin >> user_cliente[user_option - 1].data_emprestimo;
                }
                else if (user_option_2 == 6)
                {
                    cin >> user_cliente[user_option - 1].total_emprestimo;
                }
                else if (user_option_2 == 8)
                {
                    cin >> user_cliente[user_option - 1].total_parcelas;
                }
            } while (user_option_2 != 0);
        }
        else if (user_option == 4) // iv. Cadastrar parcela paga
        {
            int valor = 0;
            char pagamento = '\0';
            string mes = "";

            cout << "Qual cliente deseja cadastrar a parcela? (numero do cliente)\n";
            cin >> user_option;

            if (user_cliente[user_option - 1].total_emprestimo > 0)
            {
                cout << "Qual mes deseja cadastrar?(jan,fev,mar,...)\n";
                cin >> mes;
                user_cliente[user_option - 1].parcelas_mensais[meses(mes)].valor = user_cliente[user_option - 1].total_emprestimo / user_cliente[user_option - 1].total_parcelas;
                cout << "O valor e: \n"
                     << user_cliente[user_option - 1].parcelas_mensais[meses(mes)].valor << endl;
                cout << "A parcela ja foi paga?(s/n)\n";
                cin >> pagamento;
                if (pagamento == 's')
                {
                    user_cliente[user_option - 1].parcelas_mensais[meses(mes) - 1].pagamento = true;
                    cout << "Qual a data do pagamento?(00/00/00)\n";
                    cin >> user_cliente[user_option - 1].parcelas_mensais[meses(mes) - 1].data_pagamento;
                }
                else if (pagamento == 'n')
                {
                    user_cliente[user_option - 1].parcelas_mensais[meses(mes) - 1].pagamento = false;
                }
                else
                {
                    cout << "Pagamento invalido\n";
                }
                cout << "Qual a data do vencimento?(00/00/00)\n";
                cin >> user_cliente[user_option - 1].parcelas_mensais[meses(mes) - 1].data_vencimento;
            }
            else
            {
                cout << "O cliente deve ter um emprestimo ativo para poder pagar uma parcela.\n";
            }
        }
        else if (user_option == 5) // v. Cadastrar empréstimo.
        {
            cout << "Qual cliente deseja cadastrar um emprestimo?\n";
            cin >> user_option;

            cout << "Qual o valor do emprestimo?(Use casa decimais 0.00)\n";
            cin >> user_cliente[user_option - 1].total_emprestimo;
            cout << "Quantas parcelas deseja pagar? (máximo de 12 parcelas)\n";
            cin >> user_cliente[user_option - 1].total_parcelas;
            cout << "Qual a data do emprestimo?(00/00/00)\n";
            cin >> user_cliente[user_option - 1].data_emprestimo;
        }
        else if (user_option == 6) // vi. Excluir cliente
        {
            cout << "Qual cliente deseja excluir?\n";
            cin >> user_option;
            if (user_option <= user_cliente_quantidade && user_option > 0)
            {
                for (int i = user_option - 1; i < user_cliente_quantidade - 1; i++)
                {
                    user_cliente[i] = user_cliente[i + 1];
                }
                user_cliente[user_cliente_quantidade - 1] = {""};
            }
            else
            {
                cout << "Opcao invalida, você tem " << user_cliente_quantidade << " cliente(s).\n";
            }
        }
        else if (user_option == 7) // vii. Sair
        {
            return true;
        }
        else
        {
            cout << "Opcao invalida (use apenas numeros 1.2.3.4.5.6.7)\n";
        }
    } while (user_option != 7);
}

/*BUG CONHECIDOS:
Se o usuário entrar com um tipo que não seja int em "user_option" o código entra em um loop infinito
*/