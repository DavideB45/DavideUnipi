#include <stdio.h>
#include <stdlib.h>

#include "ListaRevisioni.h"

#ifndef BOOLEAN
# define BOOLEAN int
# define FALSE 0
# define TRUE 1
#endif


// costruzione di una nuova struttura lista concatenata che implementa una coda
ListaRevisioni * lista_revisioni_new(MapVeicoli *veicoli, int data) {
    ListaRevisioni *res = (ListaRevisioni*)malloc(sizeof(ListaRevisioni));
    res->veicoli = veicoli;
    res->data = data;
    res->front = res->rear = NULL;
    return res;
}

// libera la memoria associata alla struttura dati
void lista_revisioni_free(ListaRevisioni *cnt) {    
    VeicoloItr *front = cnt->front;
    while(front) {
        lista_revisioni_dequeue(cnt, NULL);
        front = front->next;
    }
    free(cnt);
}

// ritorna TRUE se la lista e vuota
int isEmpty(ListaRevisioni *cnt) {
    return (cnt->front == NULL);
}

// rimuove un elemento dalla lista
int lista_revisioni_dequeue(ListaRevisioni *cnt, Veicolo **v) {
    if (isEmpty(cnt))
        return FALSE;
    else {
        VeicoloItr *front = cnt->front;
        if(v != NULL) (*v) = front->data;        
        cnt->front = front->next;
        free(front);
        return TRUE;
    }
}

// aggiunge un elemento Veicolo in coda cercando il veicolo corrispondente 
int lista_revisioni_enqeue_targa(ListaRevisioni *cnt, const char *targa) {    
    Veicolo *veicolo = map_veicoli_lookup_targa(cnt->veicoli, targa);
    if (veicolo == NULL) return FALSE;
    lista_revisioni_enqueue(cnt, veicolo);
    return TRUE;
}


//      ____ ___  __  __ ____  _     _____ _____  _    ____  _____    //
//     / ___/ _ \|  \/  |  _ \| |   | ____|_   _|/ \  |  _ \| ____|   //
//    | |  | | | | |\/| | |_) | |   |  _|   | | / _ \ | |_) |  _|     //
//    | |__| |_| | |  | |  __/| |___| |___  | |/ ___ \|  _ <| |___    //
//     \____\___/|_|  |_|_|   |_____|_____| |_/_/   \_\_| \_\_____|   //


// ritorna la referenza che e' associata al primo elemento della coda
Veicolo * lista_revisioni_front(ListaRevisioni *cnt) {
    // [ ... ]
    VeicoloItr *front = cnt->front;
    return cnt->front;
}

// aggiunge un elemento Veicolo in coda alla lista
int lista_revisioni_enqueue(ListaRevisioni *cnt, Veicolo *v) {
    // [ ... ]
    if (isEmpty(cnt)) {
        cnt->front = (ListaRevisioni) malloc(sizeof(struct _ListaRevisioni));
        cnt->rear = cnt->front;
    }   
    else {
        cnt->rear->next = (ListaRevisioni) malloc(sizeof(struct _ListaRevisioni));
        cnt->rear = cnt->rear->next;
    }
    cnt->rear->data = v;
    cnt->rear->next = NULL;
    return TRUE;
}
