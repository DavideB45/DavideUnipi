#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h>
#include <string.h>

#include "MapVeicoli.h"
#include "MapClienti.h"

#define SCANF_QUOTED_STRING " %*[\"]%[^\"]%*[\"] "
#define SCANF_BRACED_STRING " %*[{]%[^}]%*[}] "
#define SCANF_RECTBRACED_STRING " %*[\[]%[^\]]%*[\]] "

#ifndef BOOLEAN
# define BOOLEAN int
# define FALSE 0
# define TRUE 1
#endif


////////////////////////////////////////
// IMPLEMENTAZIONE FUNZIONI VEICOLO   //
////////////////////////////////////////

// Stampa una stringa corrispondente al piano partendo dal codice

int read_veicolo(FILE *file, Veicolo *p) {
    char vehicles_tmp[150] = "";
    int res = fscanf(file, "%d" SCANF_QUOTED_STRING 
                        SCANF_QUOTED_STRING "%d" 
                        SCANF_QUOTED_STRING "%d",
                    &p->id, p->marca, p->modello, &p->anno, p->targa, &p->revisione);
    return res;
}

void write_veicolo(FILE *file, const Veicolo *p) {
    fprintf(file,   "Veicolo [%.4d] - marca: %s  modello: %s  immatricolazione: (%d)\n"
                    "               - targa: [%s], ultima revisione: %d \n",
           p->id, p->marca, p->modello, p->anno,
           p->targa, p->revisione);
}

void print_veicolo(const Veicolo *p) {
    write_veicolo(stdout, p);
}




///////////////////////////////////////////
// IMPLEMENTAZIONE FUNZIONI MAPVEICOLI   //
///////////////////////////////////////////


// Crea una nuova struttura veicolo 
MapVeicoli * map_veicoli_new(int size) {
    MapVeicoli *ret = (MapVeicoli *)malloc(sizeof(MapVeicoli));
    *ret = (MapVeicoli){ (Veicolo *)malloc(sizeof(Veicolo)*size), 0, size };
    return ret;
}

// Cancella la struttura veicolo in cnt 
void map_veicoli_free(MapVeicoli *cnt) {
    assert(cnt);
    free(cnt->data);
    free(cnt);
}

void map_veicoli_grow(MapVeicoli *cnt) {
    if( cnt->len < cnt->size ) return;
    Veicolo *tmp = (Veicolo *)malloc(sizeof(Veicolo)*cnt->size*2);
    memcpy(tmp, cnt->data, sizeof(Veicolo)*cnt->size);
    free(cnt->data);
    cnt->data = tmp;
    cnt->size *= 2;
}



// ritorna TRUE se esiste un veicolo con id = n
int map_veicoli_contains_id(MapVeicoli *cnt, int n) {
    assert(cnt);
    return map_veicoli_lookup(cnt, n) != NULL;
}




// aggiunge un veicolo alla mappa
void map_veicoli_add(MapVeicoli *cnt, Veicolo p) {
    assert(cnt);
    if(map_veicoli_contains_id(cnt, p.id)) return;
    map_veicoli_grow(cnt);
    int i = cnt->len;
    while (i>0 && cnt->data[i-1].id > p.id )  {
      cnt->data[i] = cnt->data[i-1]; i--;
    }
    cnt->data[i] = p;
    cnt->len++;
}



// legge il database di veicoli e cerca una stringa nel nome copiando il risultato su (dst)
Veicolo * map_veicoli_lookup_targa(MapVeicoli *cnt, const char *targa) {
    for(int i=0; i<cnt->len; ++i) {
        if( strcmp(cnt->data[i].targa, targa) == 0 )
            return &cnt->data[i];
    }
    return NULL;
}

// legge il database di veicoli da file
int map_veicoli_read(MapVeicoli *cnt, const char *file_name) {
    FILE *file = fopen(file_name, "r");
    if (file==NULL) {
        printf("Error opening file\n");
        return 0;
    }
    
    Veicolo tmp;
    int count = 0;
    while( read_veicolo(file, &tmp) != EOF ) {
        map_veicoli_add(cnt, tmp);
        count ++;
    }
    fclose(file);
    return count;
}

// stampa il database di veicoli
void map_veicoli_print(MapVeicoli *cnt) {
    assert(cnt);
    printf(" ----- [ REGISTRO VEICOLI ] ----- \n\n");
    for (int i=0; i<cnt->len; ++i)  {
        print_veicolo(&cnt->data[i]); printf("\n");
    } 
    printf(" --------------------------------- \n");
}

// [funzione di utilita'] stampa la lista di veicoli e relativi proprietari con revisione scaduta
int map_veicoli_lista_revisione(MapVeicoli *cnt, MapClienti *cli, const char *file_name, int date) {

    FILE *file = fopen(file_name, "w");
    if (file==NULL) {
        printf("Error opening file\n");
        return FALSE;
    }
    
    for(int i=0; i<cnt->len; i++) {
        Veicolo v = cnt->data[i];
        if(v.revisione < date) {
            write_veicolo(file, &v);
            Cliente *c = map_clienti_lookup_veicolo(cli, v.id);
            if(c) write_cliente(file, c);
        }
    }

    fclose(file);
    return TRUE;
}

//      ____ ___  __  __ ____  _     _____ _____  _    ____  _____    //
//     / ___/ _ \|  \/  |  _ \| |   | ____|_   _|/ \  |  _ \| ____|   //
//    | |  | | | | |\/| | |_) | |   |  _|   | | / _ \ | |_) |  _|     //
//    | |__| |_| | |  | |  __/| |___| |___  | |/ ___ \|  _ <| |___    //
//     \____\___/|_|  |_|_|   |_____|_____| |_/_/   \_\_| \_\_____|   //



// Funzione di supporto che realizza la ricerca binaria tramite chiamate ricorsive
static Veicolo * binarySearch_veicolo(Veicolo arr[], int l, int r, int x) { 
    // [ ... ]
    // completare la funzione ricorsiva per la ricerca binaria
    if (r >= l) { 
        int mid = l + (r - l) / 2; 
  
        // If the element is present at the middle 
        // itself 
        if (arr[mid].id == x) 
            return arr[mid]; 
  
        // If element is smaller than mid, then 
        // it can only be present in left subarray 
        if (arr[mid].id > x) 
            return binarySearch_veicolo(arr, l, mid - 1, x); 
  
        // Else the element can only be present 
        // in right subarray 
        return binarySearch_veicolo(arr, mid + 1, r, x); 
    } 
    return NULL; 
} 

// Trova un veicolo dato il suo id
Veicolo * map_veicoli_lookup(MapVeicoli *cnt, int k) {    
    // [ ... ]
    // completare chiamando la funzione ricorsiva per la ricerca binaria definita sopra
    Veicolo Vehicle;
    Vehicle = binarySearch_veicolo(cnt->data, 0, cnt->len, k);
    return Vehicle; 
}

