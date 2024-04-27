/*
File: telefonbuch.c
Date: 27.04.2024
Autor: Nicolas Höller
*/

#include <stdio.h>
#include <stdlib.h>

//Listenelement
struct knoten{
	int wert;
	struct knoten* next;
};

struct knoten* einfuegen(struct knoten* liste, int wert);
void leeren(struct knoten* liste);
void ausgeben(struct knoten* liste);

int main() {
	struct knoten* liste;
	liste=NULL;
	
	liste=einfuegen(liste, 9);
	liste=einfuegen(liste, 8);	
	liste=einfuegen(liste, 4);
	liste=einfuegen(liste, 10);
	liste=einfuegen(liste, 17);
		
	ausgeben(liste);
	
	leeren(liste);
	
	return 0;
}

//Am Ende der Liste einfügen
struct knoten* einfuegen(struct knoten* liste, int wert){
	struct knoten* neu=malloc(sizeof(struct knoten));
	neu->wert=wert;
	neu->next=NULL;
	
	//Wenn Liste leer ist, ist die neue Liste das neue Element
	if(liste==NULL){
		return neu;	
	}
	
	//ansonsten am Ende einfuegen
	struct knoten* temp;
	temp=liste;
	while(temp->next!=NULL){  //Ende aufsuchen
		temp=temp->next;
	}
	
	temp->next=neu;  //einfügen
	return liste;
}

//Speicher freigeben, Listenelement für Listenelement
void leeren(struct knoten* liste){
	if(liste==NULL){
		return;
	}
	
	struct knoten* temp;
	while(liste!=NULL){
		temp=liste->next;
		free(liste);
		liste=temp;
	}
	
}

//Liste ausgeben
void ausgeben(struct knoten* liste){
	struct knoten* temp;
	temp=liste;
	while(temp!=NULL){
		printf("Listenelement: %d\n", temp->wert);
		temp=temp->next;
	}	
}