#include <stdio.h>
#include <string.h>
#define TF 10

struct tpdata{
	int ano;
	int mes;
	int dia;
};

struct tphorario{
	int hora;
	int minuto;
	int segundo;
};

struct compromisso{
	char descricao[20];
	struct tpdata data;
	struct tphorario horario;
};

void insereagenda(struct compromisso agenda[TF], int &tl){
	int i;
	struct compromisso a;
	if (tl == TF){
		printf("\nAgenda lotada!");
	}
	else {
		printf("\nAdicione descricao: ");
		scanf("%s", &a.descricao);
		printf("Ano: ");
		scanf("%d", &a.data.ano);
		printf("Mes: ");
		scanf("%d", &a.data.mes);
		printf("Dia: ");
		scanf("%d", &a.data.dia);
		printf("Hora: ");
		scanf("%d", &a.horario.hora);
		printf("Minuto: ");
		scanf("%d", &a.horario.minuto);
		printf("Segundo: ");
		scanf("%d", &a.horario.segundo);
		
		agenda[tl] = a;
		tl++;
	}
}

void exibeagenda(struct compromisso agenda[TF], int &tl){
	int i;
	for (i=0; i<tl; i++){
		printf("\nDescricao: %s	Data: %2d/%2d/%4d	Horario: %2d:%2d:%2d", 
		agenda[i].descricao, agenda[i].data.dia, agenda[i].data.mes, agenda[i].data.ano,
		agenda[i].horario.hora, agenda[i].horario.minuto, agenda[i].horario.segundo);
	}
	printf("\n");
}

/*
void exibeagenda(struct compromisso agenda[TF], int &tl){
	int i;
	for (i=0; i<tl; i++){
		printf("\nDescricao: %s", agenda[i].descricao);
		printf("\nAno: %d", agenda[i].data.ano);
		printf("\nMes: %d", agenda[i].data.mes);
		printf("\nDia: %d", agenda[i].data.dia);
		printf("\nHora: %d", agenda[i].horario.hora);
		printf("\nMinuto: %d", agenda[i].horario.minuto);
		printf("\nSegundo: %d", agenda[i].horario.segundo);
		printf("\n");
	}
}
*/

int main(void){
	int tl = 0, opcao = 0;
	struct compromisso agenda[TF];
	
	while (opcao!=3){
		printf("\n1 - Exibir compromissos");
		printf("\n2 - Inserir compromissos");
		printf("\n3 - Sair");
		printf("\nOpcao: ");
		scanf("%d", &opcao);
		
		switch (opcao){
			case 1:
				exibeagenda(agenda, tl);
				break;
			case 2:
				insereagenda(agenda, tl);
				break;
		}
	}
	
	return 0;
}

