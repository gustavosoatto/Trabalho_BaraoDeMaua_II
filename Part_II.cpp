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
using namespace std;

struct cliente
{
    string nome;
    string cpf;
    string endereco;
    string data_nascimento;
    string data_emprestimo;
    string total_emprestimo;
    string parcelas_mensais;
};

int main()
{
    int user_option = 0, user_cliente_quantidade = 0, user_option_2 = 0;

    cout << "Quantos cliente deseja cadastrar?\n";
    cin >> user_cliente_quantidade;
    cliente user_cliente[user_cliente_quantidade];

    do
    {
        cout << "1. Cadastrar cliente\n"
             << "2. Visualizar as informações de um cliente\n"
             << "3. Editar as informações de um cliente\n"
             << "4. Cadastrar parcela paga\n"
             << "5. Cadastrar empréstimo\n"
             << "6. Excluir cliente\n"
             << "7. SAIR\n";
        cin >> user_option;

        if (user_option == 1)
        {
            cout << "Para cadastrar um cliente digite: \n";
            for (int i = 0; i < user_cliente_quantidade; i++)
            {
                cout << "Nome do cliente\n";
                cin >> user_cliente[i].nome;
                cout << "CPF\n";
                cin >> user_cliente[i].cpf;
                cout << "Endereço\n";
                cin >> user_cliente[i].endereco;
                cout << "Data de nascimento\n";
                cin >> user_cliente[i].data_nascimento;
                cout << "Data do empréstimo\n";
                cin >> user_cliente[i].data_emprestimo;
                cout << "Valor total do empréstimo\n";
                cin >> user_cliente[i].total_emprestimo;
                cout << "Informações sobre parcelas mensais de empréstimo." << endl;
                cin >> user_cliente[i].parcelas_mensais;
            }
        }
        else if (user_option == 2)
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
                     << user_cliente[user_option - 1].parcelas_mensais << endl;
            }
            else
            {
                cout << "Opção inválida, você tem " << user_cliente_quantidade << " cliente(s).\n";
            }
        }
        else if (user_option == 3)
        {
            // string user_alteration = "";
            do
            {
                cout << "Qual cliente deseja fazer alterações? (número do cliente)\n";
                cin >> user_option;
                cout << "Qual dado deseja fazer a alteração?\n"
                     << "1. Nome do cliente\n"
                     << "2. CPF\n"
                     << "3. Endereço\n"
                     << "4. Data de nascimento\n"
                     << "5. Data do empréstimo\n"
                     << "6. Valor total do empréstimo\n"
                     << "7. Informações sobre parcelas mensais de empréstimo\n"
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
                    cin >> user_cliente[user_option - 1].data_emprestimo;
                }
                else if (user_option_2 == 6)
                {
                    cin >> user_cliente[user_option - 1].total_emprestimo;
                }
                else if (user_option_2 == 7)
                {
                    cin >> user_cliente[user_option - 1].parcelas_mensais;
                }
            } while (user_option_2 != 0);
        }
        else if (user_option == 4)
        {
        }
        else if (user_option == 5)
        {
        }
        else if (user_option == 6)
        {
        }
        else if (user_option == 7)
        {
            return true;
        }
        else
        {
            cout << "Opção inválida (use apenas números 1.2.3.4.5.6.7)\n";
        }
    } while (user_option != 7);
}

/*BUG CONHECIDOS:
Se o usuário entrar com um tipo que não seja int em "user_option" o código entra em um loop infinito
*/