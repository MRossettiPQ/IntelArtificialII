#include <iostream>
#include "FuzzyRule.h"
#include "FuzzyComposition.h"
#include "Fuzzy.h"
#include "FuzzyRuleConsequent.h"
#include "FuzzyOutput.h"
#include "FuzzyInput.h"
#include "FuzzyIO.h"
#include "FuzzySet.h"
#include "FuzzyRuleAntecedent.h"
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(int argc, char *argv[]) 
{
    Fuzzy* fuzzy = new Fuzzy();
    // FuzzyInput
		//Variaveis Linguisticas Direita
		FuzzyInput* distanciaD = new FuzzyInput(1);																							//CRIA플O ENTRADAS DIREITA
		FuzzySet* PertoD	   = new FuzzySet(0, 20, 20, 40);																				//DEFINI플O DE VARIAVEL LINGUISTICA PARA DISTANCIA PERTO DO MOTOR DIREITA
			distanciaD->addFuzzySet(PertoD);																								//ADI플O VARIAVEL DIREITA PERTO
		FuzzySet* SeguroD      = new FuzzySet(30, 50, 50, 70);																				//DEFINI플O DE VARIAVEL LINGUISTICA PARA DISTANCIA SEGURO DO MOTOR DIREITA
			distanciaD->addFuzzySet(SeguroD);																								//ADI플O VARIAVEL DIREITA SEGURO
		FuzzySet* LongeD       = new FuzzySet(60, 80, 80, 120);																				//DEFINI플O DE VARIAVEL LINGUISTICA PARA DISTANCIA LONGE DO MOTOR DIREITA
			distanciaD->addFuzzySet(LongeD);																								//ADI플O VARIAVEL DIREITA LONGE
		fuzzy->addFuzzyInput(distanciaD);																									//ADI플O ENTRADAS DIREITA
	
		//Variaveis Linguisticas Esquerda
		FuzzyInput* distanciaE = new FuzzyInput(2);																							//CRIA플O ENTRADAS ESQUERDA
		FuzzySet* PertoE       = new FuzzySet(0, 20, 20, 40);																				//DEFINI플O DE VARIAVEL LINGUISTICA PARA DISTANCIA PERTO DO MOTOR ESQUERDA
			distanciaE->addFuzzySet(PertoE);																								//ADI플O VARIAVEL ESQUERDA PERTO
		FuzzySet* SeguroE      = new FuzzySet(30, 50, 50, 70);																				//DEFINI플O DE VARIAVEL LINGUISTICA PARA DISTANCIA SEGURO DO MOTOR ESQUERDA
			distanciaE->addFuzzySet(SeguroE);																								//ADI플O VARIAVEL ESQUERDA SEGURO
		FuzzySet* LongeE       = new FuzzySet(60, 80, 80, 120);																				//DEFINI플O DE VARIAVEL LINGUISTICA PARA DISTANCIA LONGE DO MOTOR ESQUERDA
			distanciaE->addFuzzySet(LongeE);																								//ADI플O VARIAVEL ESQUERDA LONGE
		fuzzy->addFuzzyInput(distanciaE);																									//ADI플O ENTRADAS ESQUERDA

    // FuzzyOutput
		//Variaveis Linguisticas Direita
		FuzzyOutput* motorD  = new FuzzyOutput(1);																							//CRIA플O SAIDAS DIREITA
		FuzzySet* InvertidoD = new FuzzySet(-70, -120, -120, -150);																			//DEFINI플O DE VARIAVEL LINGUISTICA PARA VELOCIDADE INVERTIDA DO MOTOR DIREITA
			motorD->addFuzzySet(InvertidoD);																								//ADI플O VARIAVEL INVERTIDA DIREITA
		FuzzySet* BaixaD     = new FuzzySet(0, 40, 40, 80);																					//DEFINI플O DE VARIAVEL LINGUISTICA PARA VELOCIDADE BAIXA DO MOTOR DIREITA
			motorD->addFuzzySet(BaixaD);																									//ADI플O VARIAVEL BAIXA DIREITA
		FuzzySet* MediaD     = new FuzzySet(70, 120, 120, 150);																				//DEFINI플O DE VARIAVEL LINGUISTICA PARA VELOCIDADE MEDIA DO MOTOR DIREITA
			motorD->addFuzzySet(MediaD);																									//ADI플O VARIAVEL MEDIA DIREITA
		FuzzySet* MaximaD    = new FuzzySet(140, 200, 200, 255);																			//DEFINI플O DE VARIAVEL LINGUISTICA PARA VELOCIDADE MAXIMA DO MOTOR DIREITA
			motorD->addFuzzySet(MaximaD);																									//ADI플O VARIAVEL MAXIMA DIREITA
		fuzzy->addFuzzyOutput(motorD);																										//ADI플O SAIDAS DIREITA

		//Variaveis Linguisticas Esquerda
		FuzzyOutput* motorE  = new FuzzyOutput(2);																							//CRIA플O SAIDAS ESQUERDA
		FuzzySet* InvertidoE = new FuzzySet(-70, -120, -120, -150);																			//DEFINI플O DE VARIAVEL LINGUISTICA PARA VELOCIDADE INVERTIDA DO MOTOR ESQUERDO
			motorE->addFuzzySet(InvertidoE);																								//ADI플O VARIAVEL INVERTIDA ESQUERDA
		FuzzySet* BaixaE     = new FuzzySet(0, 40, 40, 80);																					//DEFINI플O DE VARIAVEL LINGUISTICA PARA VELOCIDADE BAIXA DO MOTOR ESQUERDO
			motorE->addFuzzySet(BaixaE);																									//ADI플O VARIAVEL BAIXA ESQUERDA
		FuzzySet* MediaE     = new FuzzySet(70, 120, 120, 150);																				//DEFINI플O DE VARIAVEL LINGUISTICA PARA VELOCIDADE MEDIA DO MOTOR ESQUERDO
			motorE->addFuzzySet(MediaE);																									//ADI플O VARIAVEL MEDIA ESQUERDA
		FuzzySet* MaximaE    = new FuzzySet(140, 200, 200, 255);																			//DEFINI플O DE VARIAVEL LINGUISTICA PARA VELOCIDADE MAXIMA DO MOTOR ESQUERDO
			motorE->addFuzzySet(MaximaE);																									//ADI플O VARIAVEL MAXIMA ESQUERDA
		fuzzy->addFuzzyOutput(motorE);																										//ADI플O SAIDAS ESQUERDA
	
	// CONSTRU플O DAS REGRAS DE INFERENCIA
		//Regra 1
		FuzzyRuleAntecedent* distanciaPerto      = new FuzzyRuleAntecedent();																//Cria Antecedente
			distanciaPerto->joinWithAND(PertoD, PertoE);																					//Associa豫o sensor Esquerdo com o Direito
 		FuzzyRuleConsequent* velocidadeInvertida = new FuzzyRuleConsequent();																//Cria Consequencia
			velocidadeInvertida->addOutput(InvertidoD);																						//Define a Saida Direita
			velocidadeInvertida->addOutput(InvertidoE);																						//Define a Saida Esquerda
		FuzzyRule* Regra1 = new FuzzyRule(1, distanciaPerto, velocidadeInvertida);															//SE sensor Direito resulta "PERTO" e sensor Esquerdo resulta "PERTO", ENT홒 ele INVERTERA a rota豫o do motor
			fuzzy->addFuzzyRule(Regra1);																									//Adiciona a regra 1

		//Regra 2
		FuzzyRuleAntecedent* distanciaPertoEsquerda1 = new FuzzyRuleAntecedent();															//Cria Antecedente
			distanciaPertoEsquerda1->joinWithAND(SeguroD, PertoE);																			//Associa豫o sensor Esquerdo com o Direito
		FuzzyRuleConsequent* virarDireita1			 = new FuzzyRuleConsequent();															//Cria Consequencia
			velocidadeInvertida->addOutput(InvertidoD);																						//Define a Saida Direita
			velocidadeInvertida->addOutput(MediaE);																							//Define a Saida Esquerda
		FuzzyRule* Regra2 = new FuzzyRule(12, distanciaPertoEsquerda1, virarDireita1);														//SE sensor Direito resulta "SEGURO" e sensor Esquerdo resulta "PERTO", ENT홒 ele irar virar a DIREITA
			fuzzy->addFuzzyRule(Regra2);																									//Adiciona a regra 2

		//Regra 3	
		FuzzyRuleAntecedent* distanciaPertoEsquerda2 = new FuzzyRuleAntecedent();															//Cria Antecedente
			distanciaPertoEsquerda2->joinWithAND(LongeD, PertoE);																			//Associa豫o sensor Esquerdo com o Direito
		FuzzyRuleConsequent* virarDireita2			 = new FuzzyRuleConsequent();															//Cria Consequencia
			velocidadeInvertida->addOutput(BaixaD);																							//Define a Saida Direita
			velocidadeInvertida->addOutput(MediaE);																							//Define a Saida Esquerda
		FuzzyRule* Regra3 = new FuzzyRule(3, distanciaPertoEsquerda2, virarDireita2);														//SE sensor Direito resulta "LONGE" e sensor Esquerdo resulta "PERTO", ENT홒 ele irar virar a DIREITA
			fuzzy->addFuzzyRule(Regra3);																									//Adiciona a regra 3

		//Regra 4
		FuzzyRuleAntecedent* distanciaPertoDireita1 = new FuzzyRuleAntecedent();															//Cria Antecedente
			distanciaPertoDireita1->joinWithAND(PertoD, SeguroE);																			//Associa豫o sensor Esquerdo com o Direito
		FuzzyRuleConsequent* virarEsquerda1			= new FuzzyRuleConsequent();															//Cria Consequencia
			velocidadeInvertida->addOutput(MediaD);																							//Define a Saida Direita
			velocidadeInvertida->addOutput(InvertidoE);																						//Define a Saida Esquerda
		FuzzyRule* Regra4 = new FuzzyRule(4, distanciaPertoDireita1, virarEsquerda1);														//SE sensor Direito resulta "PERTO" e sensor Esquerdo resulta "SEGURO", ENT홒 ele irar virar a ESQUERDA
			fuzzy->addFuzzyRule(Regra4);																									//Adiciona a regra 4

		//Regra 5
		FuzzyRuleAntecedent* distanciaPertoDireita2 = new FuzzyRuleAntecedent();															//Cria Antecedente
			distanciaPertoDireita2->joinWithAND(PertoD, LongeE);																			//Associa豫o sensor Esquerdo com o Direito
		FuzzyRuleConsequent* virarEsquerda2			= new FuzzyRuleConsequent();															//Cria Consequencia
			velocidadeInvertida->addOutput(MediaD);																							//Define a Saida Direita
			velocidadeInvertida->addOutput(BaixaE);																							//Define a Saida Esquerda
		FuzzyRule* Regra5 = new FuzzyRule(5, distanciaPertoDireita2, virarEsquerda2);														//SE sensor Direito resulta "PERTO" e sensor Esquerdo resulta "LONGE", ENT홒 ele irar virar a ESQUERDA
			fuzzy->addFuzzyRule(Regra5);																									//Adiciona a regra 5
		
		//Regra 6
		FuzzyRuleAntecedent* distanciaSeguroEsquerda1 = new FuzzyRuleAntecedent();															//Cria Antecedente
			distanciaSeguroEsquerda1->joinWithAND(SeguroD, SeguroE);																		//Associa豫o sensor Esquerdo com o Direito
		FuzzyRuleConsequent* emFrente1				  = new FuzzyRuleConsequent();															//Cria Consequencia
			velocidadeInvertida->addOutput(MediaD);																							//Define a Saida Direita
			velocidadeInvertida->addOutput(MediaE);																							//Define a Saida Esquerda
		FuzzyRule* Regra6 = new FuzzyRule(6, distanciaSeguroEsquerda1, emFrente1);															//SE sensor Direito resulta "SEGURO" e sensor Esquerdo resulta "SEGURO", ENT홒 ele ira seguir em FRENTE
			fuzzy->addFuzzyRule(Regra6);																									//Adiciona a regra 6

		//Regra 7
		FuzzyRuleAntecedent* distanciaSeguroEsquerda2 = new FuzzyRuleAntecedent();															//Cria Antecedente
			distanciaSeguroEsquerda2->joinWithAND(LongeD, SeguroE);																			//Associa豫o sensor Esquerdo com o Direito
		FuzzyRuleConsequent* emFrente2				  = new FuzzyRuleConsequent();															//Cria Consequencia
			velocidadeInvertida->addOutput(MediaD);																							//Define a Saida Direita
			velocidadeInvertida->addOutput(MediaE);																							//Define a Saida Esquerda
		FuzzyRule* Regra7 = new FuzzyRule(7, distanciaSeguroEsquerda1, emFrente2);															//SE sensor Direito resulta "LONGE" e sensor Esquerdo resulta "SEGURO", ENT홒 ele ira seguir em FRENTE
			fuzzy->addFuzzyRule(Regra7);																									//Adiciona a regra 7

		//Regra 8
		FuzzyRuleAntecedent* distanciaSeguroDireita = new FuzzyRuleAntecedent();															//Cria Antecedente
			distanciaSeguroDireita->joinWithAND(SeguroD, LongeE);																			//Associa豫o sensor Esquerdo com o Direito
		FuzzyRuleConsequent* emFrente3				= new FuzzyRuleConsequent();															//Cria Consequencia
			velocidadeInvertida->addOutput(MediaD);																							//Define a Saida Direita
			velocidadeInvertida->addOutput(MediaE);																							//Define a Saida Esquerda
		FuzzyRule* Regra8 = new FuzzyRule(8, distanciaSeguroDireita, emFrente3);															//SE sensor Direito resulta "SEGURO" e sensor Esquerdo resulta "LONGE", ENT홒 ele ira seguir em FRENTE
			fuzzy->addFuzzyRule(Regra8);																									//Adiciona a regra 8

		//Regra 9
		FuzzyRuleAntecedent* distanciaLonge			= new FuzzyRuleAntecedent();															//Cria Antecedente
			distanciaLonge->joinWithAND(LongeD, LongeE);																					//Associa豫o sensor Esquerdo com o Direito
		FuzzyRuleConsequent* emFrente4				= new FuzzyRuleConsequent();															//Cria Consequencia
			velocidadeInvertida->addOutput(MaximaD);																						//Define a Saida Direita
			velocidadeInvertida->addOutput(MaximaE);																						//Define a Saida Esquerda
		FuzzyRule* Regra9 = new FuzzyRule(9, distanciaLonge, emFrente4);																	//SE sensor Direito resulta "LONGE" e sensor Esquerdo resulta "LONGE", ENT홒 ele ira seguir em FRENTE
			fuzzy->addFuzzyRule(Regra9);																									//Adiciona a regra 9


	int cont, randomico1, randomico2;																										//VARIAVEIS SIMULA플O
	for (cont = 0; cont <= 100; cont++)
	{
		randomico1 = rand() % 119;																											//CHAMADA E CRIA플O DE VALOR RANDOMICO PARA ENTRADA DO SENSOR
		randomico2 = rand() % 119;																											//CHAMADA E CRIA플O DE VALOR RANDOMICO PARA ENTRADA DO SENSOR
		cout << "VALOR SENSOR 1: " << randomico1 << ", VALOR SENSOR 2: " << randomico2 << endl;												//IMPRESS홒 DOS VALORES LIDOS PELO SENSOR

		fuzzy->setInput(1, randomico1);																										//CHAMADA DA FUN플O QUE FUZZIFICA OS VALORES DO SENSOR 1
		fuzzy->setInput(2, randomico2);																										//CHAMADA DA FUN플O QUE FUZZIFICA OS VALORES DO SENSOR 2

		fuzzy->fuzzify();																													//PROCESSAMENTO DAS REGRAS DE INFERENCIA

		cout << "Regra1: " << Regra1->isFired() << ", Regra2: " << Regra2->isFired() << ", Regra3: " << Regra3->isFired() << endl;			//IMPRESS홒 DA REGRA QUE FOI ATIVADA
		cout << "Regra4: " << Regra4->isFired() << ", Regra5: " << Regra5->isFired() << ", Regra6: " << Regra6->isFired() << endl;			//IMPRESS홒 DA REGRA QUE FOI ATIVADA
		cout << "Regra7: " << Regra7->isFired() << ", Regra8: " << Regra8->isFired() << ", Regra9: " << Regra9->isFired() << endl;			//IMPRESS홒 DA REGRA QUE FOI ATIVADA


		float output1 = fuzzy->defuzzify(1);																								//RECEP플O DO VALOR APLICADO NO MOTOR DIREITO
		float output2 = fuzzy->defuzzify(2);																								//RECEP플O DO VALOR APLICADO NO MOTOR ESQUERDO

		cout << "Motor Direita: " << output1 << ", Motor Esquerda: " << output2 << endl;													//IMPRESS홒 DA VELOCIDADE DOS MOTORES APLICADA
		cout << "\n" << endl;
	}
	system("pause");
    return 0;
}
