#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
typedef struct cadastro
{
	int codigoCliente;
	char nome[30];
	int anoNasc;
	float totalGasto;
}cliente;

void cadastrarCliente(cliente* cad, int* contador) {

	getchar();
	printf("\nDigite o Nome do cliente:\n");
	scanf("%30[^\n]", &(cad + *contador)->nome);
	printf("\nDigite o ano de nascimente do cliente:\n");
	scanf("%d", &(cad + *contador)->anoNasc);
	printf("\nDigite o total gasto do cliente:\n");
	scanf("%f", &(cad + *contador)->totalGasto);
	(cad + *contador)->codigoCliente = *contador + 1;
	*contador = *contador + 1;

}

void editarCliente(cliente* cad, int contador) {
	int codigo, opcao;

	printf("\nDigite o id do cliente que deseja atualizar o montante de compras, ids disponíveis de 1 a %d\n", contador);
	scanf("%d", &codigo);

	for (int i = 0; i < contador; i++)
	{
		if (codigo == (cad + i)->codigoCliente)
		{
			printf("\nEsse cliente que deseja atualizar o montante de compras?\n");
			printf("\n%d.\t%s\t%d\t%.2f\n", (cad + i)->codigoCliente, (cad + i)->nome, (cad + i)->anoNasc, (cad + i)->totalGasto);
			printf("\n1-Sim\n2-Não\n");
			scanf("%d", &opcao);

			if (opcao == 1)
			{
				printf("\nDigite o novo montante de compraso\n");
				scanf("%f", &(cad + i)->totalGasto);
				printf("\n%d.\t%s\t%d\t%.2f\n", (cad + i)->codigoCliente, (cad + i)->nome, (cad + i)->anoNasc, (cad + i)->totalGasto);

			}
			break;
		}
		else
		{
			printf("id do cliente não encontrado");

		}
	}


}

int excluirCliente(cliente* cad, int contador, cliente* aux)
{
	int codigo, opcao, x = 0;

	printf("\nDigite o id do cliente que deseja excluir %d\n", contador);
	scanf("%d", &codigo);

	for (int i = 0; i < contador; i++)
	{
		if (codigo == (cad + i)->codigoCliente)
		{
			printf("\nEsse cliente que deseja excluir?\n");
			printf("\n%d.\t%s\t%d\t%.2f\n", (cad + i)->codigoCliente, (cad + i)->nome, (cad + i)->anoNasc, (cad + i)->totalGasto);
			printf("\n1-Sim\n2-Não\n");
			scanf("%d", &opcao);

			if (opcao == 1)
			{
				for (int j = 0; j < contador; j++)
				{
					if ((cad + j)->codigoCliente != codigo)
					{
						(aux + x)->codigoCliente = (cad + j)->codigoCliente;
						strcpy((aux + x)->nome, (cad + j)->nome);
						(aux + x)->anoNasc = (cad + j)->anoNasc;
						(aux + x)->totalGasto = (cad + j)->totalGasto;
						x++;
					}
				}
				for (int j = 0; j < x; j++)
				{
					(cad + j)->codigoCliente = j + 1;
					strcpy((cad + j)->nome, (aux + j)->nome);
					(cad + j)->anoNasc = (aux + j)->anoNasc;
					(cad + j)->totalGasto = (aux + j)->totalGasto;
				}
			}
			return -1;
		}
		else
		{
			printf("id do cliente não encontrado");
		}
	}
}

void zerarMontante(cliente* cad, int contador) {
	for (int i = 0; i < contador; i++)
	{
		(cad + i)->totalGasto = 0;
	}
}

void melhorComprador(cliente* cad, int contador) {
	int aux = cad->totalGasto, cod;
	for (int i = 0; i < contador; i++)
	{
		if (aux > (cad + i)->totalGasto)
		{
			cod = (cad + i)->codigoCliente;
		}
	}
	printf("\n\tMELHOR CLIENTE\n");
	printf("---------------------------------");
	for (int i = 0; i < contador; i++)
	{
		if (cod == (cad + i)->codigoCliente)
		{
			printf("\n%d.\t%s\t%d\t%.2f\n", (cad + i)->codigoCliente, (cad + i)->nome, (cad + i)->anoNasc, (cad + i)->totalGasto);
		}
	}
	printf("---------------------------------");

}
void buscaCliente(cliente* cad, int contador) {
	int cod;
	printf("\nDigite o id do cliente:\n");
	scanf("%d", &cod);
	printf("\n\t CLIENTE\n");
	printf("---------------------------------");
	for (int i = 0; i < contador; i++)
	{
		if (cod == (cad + i)->codigoCliente)
		{
			printf("\n%d.\t%s\t%d\t%.2f\n", (cad + i)->codigoCliente, (cad + i)->nome, (cad + i)->anoNasc, (cad + i)->totalGasto);
		}
	}
	printf("---------------------------------");

}

void imprimir(cliente* cad, int contador) {
	printf("\n\tLISTA DE CLIENTES\n");
	printf("---------------------------------");
	for (int i = 0; i < contador; i++)
	{
		printf("\n%d.\t%s\t%d\t%.2f\n", (cad + i)->codigoCliente, (cad + i)->nome, (cad + i)->anoNasc, (cad + i)->totalGasto);
	}
	printf("---------------------------------");
}

int main() {
	setlocale(LC_ALL, "portuguese");
	cliente* cad;
	cliente* aux;

	cad = (cliente*)calloc(10, sizeof(cliente));
	aux = (cliente*)calloc(10, sizeof(cliente));

	int opcao, contador = 0;
	do
	{
		printf("\n1-Cadastro cliente\n");
		printf("\n2-Atualizar o montante de compras\n");
		printf("\n3-Remover cliente\n");
		printf("\n4-Zerar todos os montantes de compras\n");
		printf("\n5-Listar o cliente melhor comprador\n");
		printf("\n6-Buscar cliente\n");
		printf("\n7-Listar clientes\n");
		printf("\n0-Sair\n");
		printf("\n\nDigite a opção desejada:\n");
		scanf("%d", &opcao);
		switch (opcao)
		{
		case 1:
			cadastrarCliente(cad, &contador);
			if (contador == 10 || contador % 10 == 0)
			{
				printf("\nLista de cliente cheia, deseja criar mais 10 espaços para clientes?\n");
				printf("\n1-Sim\n2-Não\n");
				scanf("%d", &opcao);

				if (opcao)
				{
					cad = (cliente*)realloc(cad, ((((contador + 1) / 10) * 10) * sizeof(cliente)));
					aux = (cliente*)realloc(cad, ((((contador + 1) / 10) * 10) * sizeof(cliente)));
				}
				else
				{
					break;
				}
			}
			break;
		case 2:
			editarCliente(cad, contador);
			break;
		case 3:
			contador = contador + excluirCliente(cad, contador, aux);
			break;
		case 4:
			zerarMontante(cad, contador);
			imprimir(cad, contador);
			break;
		case 5:
			melhorComprador(cad, contador);
			break;
		case 6:
			buscaCliente(cad, contador);
			break;
		case 7:
			imprimir(cad, contador);
			break;
		default:
			if (opcao != 0)
			{
				printf("\nOpção inválida\n");
			}
			break;
		}
	} while (opcao != 0);
}