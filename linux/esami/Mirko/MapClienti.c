#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h>
#include <string.h>

#include "MapClienti.h"

#define SCANF_QUOTED_STRING " %*[\"]%[^\"]%*[\"] "
#define SCANF_BRACED_STRING " %*[{]%[^}]%*[}] "
#define SCANF_RECTBRACED_STRING " %*[\[]%[^]]%*[]] "

#ifndef BOOLEAN
# define BOOLEAN int
# define FALSE 0
# define TRUE 1
#endif


////////////////////////////////////////
// IMPLEMENTAZIONE FUNZIONI CLIENTE   //
////////////////////////////////////////

// Stampa una stringa corrispondente al piano partendo dal codice

int read_cliente(FILE *file, Cliente *p) {
    char vehicles_tmp[150] = "";
    int res = fscanf(file, "%d" SCANF_QUOTED_STRING 
                        SCANF_QUOTED_STRING 
                        SCANF_QUOTED_STRING 
                        SCANF_RECTBRACED_STRING,
                    &p->id, p->name, p->address, p->phone, vehicles_tmp);
    int i=0;
    char *tok = strtok (vehicles_tmp, ", ");
    while (tok != NULL && i<10) {
        p->vehicles[i++] = atoi(tok);
        tok = strtok (NULL, ", ");
    }
    res += i;
    while(i<10) { p->vehicles[i++] = -1; }
    return res;
}

void write_cliente(FILE *file, const Cliente *p) {
    fprintf(file, "Cliente [%.4d] - nome: %s \n"
                  "               - indirizzo: %s, telefono: %s \n",
           p->id, p->name, p->address, p->phone );
    fprintf(file, "               - codici veicolo: [ ");
    for(int i=0; i<10; i++) {
        if(p->vehicles[i] == -1) break;
        fprintf(file, "%d ", p->vehicles[i] );
    }
    fprintf(file, " ]\n" );
}

void print_cliente(const Cliente *p) {
    write_cliente(stdout, p);
}




///////////////////////////////////////////
// IMPLEMENTAZIONE FUNZIONI MAPCLIENTI   //
///////////////////////////////////////////


// Crea una nuova struttura cliente 
MapClienti * map_clienti_new(int size) {
    MapClienti *ret = (MapClienti *)malloc(sizeof(MapClienti));
    *ret = (MapClienti){ (Cliente *)malloc(sizeof(Cliente)*size), 0, size };
    return ret;
}

// Cancella la struttura cliente in cnt 
void map_clienti_free(MapClienti *cnt) {
    assert(cnt);
    free(cnt->data);
    free(cnt);
}

static void map_clienti_grow(MapClienti *cnt) {
    if( cnt->len < cnt->size ) return;
    Cliente *tmp = (Cliente *)malloc(sizeof(Cliente)*cnt->size*2);
    memcpy(tmp, cnt->data, sizeof(Cliente)*cnt->size);
    free(cnt->data);
    cnt->data = tmp;
    cnt->size *= 2;
}


// Trova un cliente dato il suo id
Cliente * map_clienti_lookup(MapClienti *cnt, int id) {
    for(int i=0; i<cnt->len; i++) 
        if(cnt->data[i].id == id) return &cnt->data[i];
    return NULL;
}

// ritorna TRUE se esiste un cliente con id = n
int map_clienti_contains_id(MapClienti *cnt, int id) {
    return map_clienti_lookup(cnt, id) != NULL;
}

// aggiunge un cliente alla mappa mantenendo l'ordine di id
void map_clienti_add(MapClienti *cnt, Cliente p) {
    if(map_clienti_contains_id(cnt, p.id)) return;
    map_clienti_grow(cnt);
    cnt->data[cnt->len++] = p;
}

// stampa il database di clienti
void map_clienti_print(MapClienti *cnt) {
    assert(cnt);
    printf(" ----- [ REGISTRO CLIENTI ] ----- \n\n");
    for (int i=0; i<cnt->len; ++i)  {
        print_cliente(&cnt->data[i]); printf("\n");
    } 
    printf(" --------------------------------- \n");
}

// legge il database di clienti da file
int map_clienti_read(MapClienti *cnt, const char *file_name) {
    FILE *file = fopen(file_name, "r");
    if (file==NULL) {
        printf("Error opening file\n");
        return 0;
    }
    
    Cliente tmp;
    int count = 0;
    while( read_cliente(file, &tmp) != EOF ) {
        map_clienti_add(cnt, tmp);
        count ++;
    }
    fclose(file);
    return count;
}

// legge il database di clienti e cerca una stringa nel nome copiando il risultato su (dst)
int map_clienti_lookup_name(MapClienti *dst, MapClienti *cnt, const char *name) {
    for(int i=0; i<cnt->len; ++i) {
        if( strstr(cnt->data[i].name, name) != NULL )
            map_clienti_add(dst, cnt->data[i]);
    }
    return dst->len;
}

// cerca nel database a quale cliente e' associato un id veicolo
Cliente * map_clienti_lookup_veicolo(MapClienti *clienti, int veicolo_id) {
    for(int i=0; i<clienti->len; i++) {
        Cliente *cli = &clienti->data[i];
        for(int j=0; j<10 && cli->vehicles[j] > -1; j++ ) {
            if( cli->vehicles[j] == veicolo_id) return cli;
        }
    }
    return NULL;
}

// conta quanti veicoli sono restrati associati ad un particolare cliente
static int cliente_count_vehicles(Cliente c) {
    int count = 0;
    for(int j=0; j<10 && c.vehicles[j] > -1; j++) count++;
    return count;
}


//      ____ ___  __  __ ____  _     _____ _____  _    ____  _____    //
//     / ___/ _ \|  \/  |  _ \| |   | ____|_   _|/ \  |  _ \| ____|   //
//    | |  | | | | |\/| | |_) | |   |  _|   | | / _ \ | |_) |  _|     //
//    | |__| |_| | |  | |  __/| |___| |___  | |/ ___ \|  _ <| |___    //
//     \____\___/|_|  |_|_|   |_____|_____| |_/_/   \_\_| \_\_____|   //


// Restutuisce il numero di clienti presenti nella mappa (cnt)
int map_clienti_length(MapClienti *cnt) {
    // [ ... ]
    return cnt->len;
}

int map_clienti_count_no_vehicles(MapClienti *cnt) {
    // [ ... ]
    // SUGGERIMENTO: 
    // per vedere se il numero di veicoli e' zero si usi la funzione:
    // cliente_count_vehicles(cl)
    int numbers = 0;
    for (int i = 0; i < cnt->len; i++)
    {
        if (cliente_count_vehicles(cnt->data[i]) == 0)
        {
            numbers++;
        }
    }
    return numbers;
}



