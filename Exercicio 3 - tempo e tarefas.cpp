	#include <stdio.h>
	#include <string.h>
	#include <stdbool.h>
	#include <locale.h>
	#include <stdlib.h>
	#include <math.h>
	
	
	/*Crie um programa em C para registrar o tempo gasto em tarefas diferentes. O
	programa deve permitir ao usuário especificar o número de tarefas, inserir nomes
	de tarefas e o tempo gasto em cada uma. Use alocação dinâmica para armazenar as
	informações das tarefas e, no final, calcule o tempo total gasto e exiba as tarefas e
	o tempo gasto em cada uma.*/
	
	typedef struct{
		
		char nome[50];
		int tempo[3] = {0,0,0};	
	
	}tarefas;
	
void converteHora(tarefas *tarefa, int qntd) {
    for (int i = 0; i < qntd; i++) {
        // Converter segundos em minutos
        if (tarefa[i].tempo[2] >= 60) {
            tarefa[i].tempo[1] += tarefa[i].tempo[2] / 60;
            tarefa[i].tempo[2] = tarefa[i].tempo[2] % 60;
        }

        // Converter minutos em horas
        if (tarefa[i].tempo[1] >= 60) {
            tarefa[i].tempo[0] += tarefa[i].tempo[1] / 60;
            tarefa[i].tempo[1] = tarefa[i].tempo[1] % 60;
        }
    }
}

void converteHorasTotais(int *tempo) {
    int qntd;
	 
	 for (int i = 0; i < qntd; i++) {
        // Converter segundos em minutos
        if (tempo[2] >= 60) {
          	tempo[1] += tempo[2] / 60;
            tempo[2] = tempo[2] % 60;
        }

        // Converter minutos em horas
        if (tempo[1] >= 60) {
            tempo[0] += tempo[1] / 60;
            tempo[1] = tempo[1] % 60;
        }
    }
}
		
	
	
int main(){
setlocale (LC_ALL, "");
	
		int qntd;
		printf("Quantas tarefas você tem? ");
		scanf("%i", &qntd);
		
		int i;
		int somaTempo[3] = {0,0,0};
		
		tarefas *tarefa;
		
		tarefa = (tarefas *) calloc(qntd, sizeof(tarefas));
		
		for(i = 0; i < qntd; i++){
			printf("Digite o nome da %iº tarefa: ", i+1);
			fflush(stdin);
			gets(tarefa[i].nome);
			fflush;
			printf("Digite quanto tempo foi gasto na %iº tarefa (hora,minuto,segundo): ", i+1);
			scanf("%i:%i:%i", &tarefa[i].tempo[0],&tarefa[i].tempo[1],&tarefa[i].tempo[2]);
				converteHora(tarefa, qntd);
		}
		
	
		
		for(i = 0; i < qntd; i++){
			printf("A %iº tarefa se chama %s\n", i+1, tarefa[i].nome);
			printf("E você gastou %02i:%02i:%02i\n", tarefa[i].tempo[0], tarefa[i].tempo[1], tarefa[i].tempo[2]);
		
		}
		
		//soma horas
		for(i = 0; i < qntd; i++){
			somaTempo[0] = somaTempo[0] + tarefa[i].tempo[0];	
		}
		//soma minutos
		for(i = 0; i < qntd; i++){
			somaTempo[1] = somaTempo[1] + tarefa[i].tempo[1];	
		}
		//soma segundos
		for(i = 0; i < qntd; i++){
			somaTempo[2] = somaTempo[2] + tarefa[i].tempo[2];	
		}
		
		converteHorasTotais(somaTempo);
		printf("E você gastou %02i:%02i:%02i no total", somaTempo[0],somaTempo[1],somaTempo[2]);
		
		free(tarefa);
		
	
	
	
	}

