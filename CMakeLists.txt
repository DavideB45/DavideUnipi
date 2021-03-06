cmake_minimum_required(VERSION 3.15)
project(DavideUnipi)

set(CMAKE_CXX_STANDARD 14)

add_executable(DavideUnipi
        algo/altro/ricerca_binaria.c
        algo/altro/ricerca_lineare.c
        algo/lez1/inversione/arr.c
        algo/lez1/is_first/n_primo.c
        algo/lez1/lab/stringhe.c
        algo/lez1/minmax/minmax.c
        algo/lez1/primi_disp/somma.c
        algo/lez1/somma/somma.c
        algo/lez1/swap/swap.c
        algo/lez1/tswap/swap.c
        algo/lez2/0_9/between.c
        algo/lez2/anagramma/anagramma.c
        algo/lez2/find/find_in_arr.c
        algo/lez2/moltiplicazione_stringhe/molt.c
        algo/lez2/my_strcat3.c/cat.c
        algo/lez2/my_strcmp/strcmp.c
        algo/lez2/my_strlen/mystrlen.c
        algo/lez2/mystrcat1/cat.c
        algo/lez3/fusione_arr/merge.c
        algo/lez3/inters_disordinata/non_ho_voglia_di_ottimizzare.c
        algo/lez3/intersezione_ordinata/inter.c
        algo/lez3/somma_sott/somm.c
        algo/lez4/ins_sort_int/ins_sort.c
        algo/lez4/ins_sort_str/alpha_order.c
        algo/lez4/my_quick/quick.c
        algo/lez4/sel_sort/sel_sort.c
        linux/assignments/automa/provarobocop2.c
        linux/assignments/automa/robocop.c
        linux/assignments/biblioteca/biblioteca.c
        linux/assignments/biblioteca/copiabiblio.c
        linux/assignments/morse/creazionealfabeto.c
        linux/assignments/morse/morse.c
        linux/assignments/morse/morse2.c
        linux/assignments/morse/morse3.c
        linux/assignments/morse/morse4.c
        linux/assignments/morse/morsesenzar.c
        linux/assignments/polonisman/lastpolonian.c
        linux/assignments/polonisman/polonianism.c
        linux/assignments/polonisman/polonianism2.c
        linux/codechef/calendar/calendar.c
        linux/codechef/coach/coach.c
        linux/codechef/coach/tosubmit.c
        linux/codechef/macchine/macchine.c
        linux/codechef/movingsegments/segmenti.c
        linux/codechef/particles/reactor.c
        linux/codechef/round/round.c
        linux/codechef/struct/amazon.c
        linux/esami/02_04_19/palindrome.c
        linux/esami/13_09_2019/array.c
        linux/esami/matrici/matrici_nelle_matrici.c
        linux/esami/regaloDiNatale/esame.c
        linux/lezioni/lez10/dinamatr/azzeradiag.c
        linux/lezioni/lez10/es1/es1.c
        linux/lezioni/lez10/fuardior/fusion.c
        linux/lezioni/lez10/matricole/matricol.c
        linux/lezioni/lez10/moltmatrdin/moltiplicazionematricidinamiche.c
        linux/lezioni/lez10/ordceck/ordered.c
        linux/lezioni/lez11/1/listmagg.c
        linux/lezioni/lez11/2/rimozione.c
        linux/lezioni/lez11/3/add4.c
        linux/lezioni/lez11/4/per.c
        linux/lezioni/lez11/5/insertionsortlist.c
        linux/lezioni/lez11/5/insOrd.c
        linux/lezioni/lez11/6/intersection.c
        linux/lezioni/lez11/7/aggiunta.c
        linux/lezioni/lez11/no/staticint.c
        linux/lezioni/lez12/esame.c
        linux/lezioni/lez7/duearray/arrays.c
        linux/lezioni/lez7/min_azzera/minazzera.c
        linux/lezioni/lez7/moltiplicamat/moltiplica.c
        linux/lezioni/lez7/multiplidi3/multipli.c
        linux/lezioni/lez7/seqinvertita.c/seqinvertita.c
        linux/lezioni/lez7/sequenza/seq.c
        linux/lezioni/lez7/sommamat/sommamatrici.c
        linux/lezioni/lez7/trasposta/trasposta.c
        linux/lezioni/lez7/verificacondizione/verificacondizione.c
        linux/lezioni/lez8/abs/abs.c
        linux/lezioni/lez8/filst/occorrenza.c
        linux/lezioni/lez8/pig/pig.c
        linux/lezioni/lez8/swap/swap.c
        linux/lezioni/lez8/ticta.c/ticta.c
        linux/lezioni/lez8/occorrenza.c
        linux/lezioni/lez9/automa/automa.c
        linux/lezioni/lez9/bioseq/bioseq.c
        linux/lezioni/lez9/dipendenti/dipendenti.c
        linux/lezioni/lez9/elezioni/backupel.c
        linux/lezioni/lez9/elezioni/elezioni.c
        linux/lezioni/lez9/insort/inssortlist.c
        linux/lezioni/lez9/ordone/intord.c
        linux/lezioni/lez9/pila/pila.c
        linux/lezioni/lez9/remove/rimozione.c
        linux/lezioni/lez9/students/students.c
        linux/provevarie/arraydipuntatori/piaztrelleincode.c
        linux/provevarie/arraydipuntatori/scanf.c
        linux/provevarie/esercizi/directory/somma_intervallo.c
        linux/provevarie/esercizi/esame/1/espressione.c
        linux/provevarie/esercizi/programmi/commutazionevalute/tramutazionesoldi.c
        linux/provevarie/esercizi/programmi/esercizi_sito/asterischi/asterischi.c
        linux/provevarie/esercizi/programmi/esercizi_sito/crescente/crescente.c
        linux/provevarie/esercizi/programmi/esercizi_sito/data/data.c
        linux/provevarie/esercizi/programmi/esercizi_sito/esponenti/esponenti.c
        linux/provevarie/esercizi/programmi/esercizi_sito/fibonaccinonricorsivo/fibonacci.c
        linux/provevarie/esercizi/programmi/esercizi_sito/mcdmcm/mcdMCM.c
        linux/provevarie/esercizi/programmi/esercizi_sito/media/media.c
        linux/provevarie/esercizi/programmi/esercizi_sito/numeri/numeri.c
        linux/provevarie/esercizi/programmi/esercizi_sito/palindrome/palindomia_portami_via.c
        linux/provevarie/esercizi/programmi/esercizi_sito/pi.c/pi.c
        linux/provevarie/esercizi/programmi/esercizi_sito/piastrelle/piastrelle.c
        linux/provevarie/esercizi/programmi/esercizi_sito/potenzedi2/pot.c
        linux/provevarie/esercizi/programmi/esercizi_sito/prezzo/prezzo.c
        linux/provevarie/esercizi/programmi/esercizi_sito/prezzo/prezzo2.c
        linux/provevarie/esercizi/programmi/esercizi_sito/rettangoli/rettangoli.c
        linux/provevarie/esercizi/programmi/esercizi_sito/tabelline/tabelline.c
        linux/provevarie/esercizi/programmi/esercizi_sito/esponenti.c
        linux/provevarie/esercizi/programmi/inversione_sequenza_di_caratteri/inversione.c
        linux/provevarie/esercizi/programmi/malattia/propagazione.c
        linux/provevarie/esercizi/programmi/malattia/propagazione2.c
        linux/provevarie/esercizi/programmi/ordinavettallinserimento/pr.c
        linux/provevarie/esercizi/programmi/prove_enum/frazione_da_programma.c
        linux/provevarie/esercizi/programmi/prove_enum/prova_enum.c
        linux/provevarie/esercizi/programmi/ricorsione/fibricoda.c
        linux/provevarie/esercizi/programmi/ricorsione/overflaw.c
        linux/provevarie/esercizi/programmi/somma_intervallo/somma_intervallo.c
        linux/provevarie/esercizi/programmi/rette.c
        linux/provevarie/esercizi/programmi/sizeof.c
        linux/provevarie/esercizi/programmi/tramutazionesoldi.c
        linux/provevarie/liste/lista.c
        linux/provevarie/matrici/condiscions/esame/esamevecchio.c
        linux/provevarie/matrici/condiscions/almenounariga.c
        linux/provevarie/matrici/condiscions/almenouno.c
        linux/provevarie/matrici/condiscions/ognicolonna.c
        linux/provevarie/matrici/condiscions/ogniel.c
        linux/provevarie/matrici/condiscions/ogniriga.c
        linux/provevarie/matrici/mergesort/minimamemoria.c
        linux/provevarie/matrici/mergesort/priamisort.c
        linux/provevarie/matrici/mergesort/try1.c
        linux/provevarie/matrici/mergesort/try2.c
        linux/provevarie/matrici/mergesort/try3.c
        linux/provevarie/matrici/mergesort/try4.c
        linux/provevarie/matrici/order/ordinaperrighe.c
        linux/provevarie/matrici/order/ordinarighe.c
        linux/provevarie/matrici/order/ordinatramitelista.c
        linux/provevarie/matrici/readandprint/maxcolonna.c
        linux/provevarie/matrici/readandprint/quadrata.c
        linux/provevarie/matrici/readandprint/rettangolare.c
        linux/provevarie/menupuntatori/menu.c
        linux/provevarie/parcheggi/parcheggio.c
        linux/provevarie/readinput/get/contemp.c
        linux/provevarie/readinput/get/trymain.c
        linux/provevarie/readinput/get/undefinesting.c
        linux/provevarie/readinput/get/variousend.c
        linux/provevarie/readinput/print/r.c
        linux/provevarie/readinput/print/trymain.c
        linux/provevarie/readinput/print/trymainvsc.c
        linux/provevarie/readinput/print/Y.c
        linux/provevarie/ripasso/lista.c
        linux/provevarie/ripasso/mergesort.c
        linux/provevarie/ripasso/ricercabinaria.c
        linux/provevarie/cpiupiu.cpp algo/lez4/my_quick/quick2.c)
