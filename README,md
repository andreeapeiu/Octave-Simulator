# Octave-Simulator

    Programul foloseste un vector de structuri pentru a retine mai usor numarul
de linii, coloane si suma elementelor matricei, dar si matricea propriu zisa.
  Algoritmul foloseste o variabila start=1 pentru a verifica faptul ca nu a
primit litera 'Q' de la tastatura si in while() citeste cate un caracter 
de la tastatura. Atunci cand citeste caracterl 'L' de la tastatura, citeste si
2 numere intregi, m si n, care reprezinta numarul de linii si respectiv numarul
de coloane ale matricei pe care doresc sa o adaug in vectorul meu de structuri,
a. Dupa aceea verific daca in vectorul meu de structuri mai este loc pentru o 
noua matrice( daca numarul efectiv de matrici nu este egal cu dimensiunea 
vectorului meu de structuri(size!=capacity) ), iar daca nu este, dublez 
dimensiunea vectorului. Dupa aceea, citesc matricea de la tastatura
si o adaug la finalul vectorului. 
    Daca litera citita de la tastatura este D, citesc indexul matricii careia
doresc sa ii afisez numarul de linii si de coloane si verific daca indexul este
valid( indexul trebuie sa fie mai mare decat 0 si mai mic decat numarul de
matrici din vectorul meu de structuri ). Daca indexul este valid, afisez
rezultatul, altfel afisez mesajul de eroare.
    Daca litera citita de la tastatura este P, citesc indexul matricii pe care
doresc sa o afisez si verific daca indexul este valid. Daca da, afisez matricea
corespunzatoare indexului, altfel afisez mesajul de eroare.
    Daca litera citita de la tastatura este M, citesc doi intregi i1 si i2, 
corespunzatori matricilor pe care doresc sa le inmultesc. Matricea rezultata
trebuie adaugata la finalul vectorului de structuri. Astfel, verific daca
vectorul meu de structuri mai are loc pentru o noua matrice. Algoritmul de 
inmultire al matricelor este unul clasic, cu 3 for-uri imbricate, functia
multiply_matrix() returnand matricea rezultata.
    Daca litera citita de la tastatura este T, se va realiza transpusa 
matricei, transformarea fiind realizata in-place. Se verifica daca indexul
primit de la tastatura este valid, iar daca este, se va apela functia
transpunere_matrice() care va realiza transpusa matricei.
    Daca litera citita de la tastatura este F, se sterge matricea de la
indexul primit de la tastatura. Se verifica daca indexul este valid, iar daca
este, se va apela functia deallocate_matrix() care va sterge matricea de la
indexul respectiv. Apoi toate matricile de dupa cea stearsa vor fi mutate cu
o pozitie mai la stanga. Variabila size va fi decrementata cu 1, aceasta 
reprezentand numarul efectiv de structuri din vectorul a. Pentru ca stergerea
sa fie eficienta, verific iar numarul de matrici din vectorul a si daca acesta
este mai mic decat jumatate din capacitatea vectorului, fac operatia 
capacity=capacity/2.
    Daca litera citita de la tastatura este O, se va apela functia sum() care
are rolul de a calcula suma elementelor fiecarei matrici din vectorul a si de
a le stoca in campul sum din structura corespunzatoare fiecarei structuri. Apoi
este utilizata functia sort_matrix() care sorteaza matricile din vectorul a
crescator in functie de suma elementelor lor. Suma este realizata cu modulo
la fiecare pas pentru a evita overflow-ul.
    Daca litera citita de la tastatura este C, se va apela redim care are 
rolul de a crea un minor al matricei de la indexul primit de la tastatura.
Pentru asta folosesc o structura auxiliara new care are dimensiunile date
de la tastatura. Aceasta retine doar elementele care ne intereseaza. Dealoc
matricea de la indexul primit de la tastatura si ii dau ca noua valoare
matricea new.
    Daca litera citita de la tastatura este R, functia ridica matricea la
puterea primita de la tastatura in timp logaritmic. Daca puterea este 0, atunci
voi returna matricea identitate. Apoi, cat timp puterea este nenula, voi
verifica daca este para sau impara. Daca este para, voi inmulti matricea cu
ea insasi, iar daca este impara, voi inmulti matricea cu ea insasi si cu
matricea initiala. La fiecare pas injumatatesc puterea pentru a obtine
o complexitate logaritmica.
    Daca litera citita de la tastatura este S, se vor inmulti doua matrici 
utilizand algoritmul lui Strassen. Se verifica daca in coada vectorului mai
este loc pentru o matrice. Algoritmul Strassen este unul recursiv, care
utilizeaza, de asemenea, un vector de structuri in urmatoarea ordine:
A1, A2, A3, A4, B1, B2, B3, B4, C1, C2, C3, C4, M1, M2, M3, M4, M5, M6, M7 si
doua matrici auxiliare. La fiecare pas, se verifica daca matricele sunt de
dimensiune 1, caz in care se inmultesc direct. Daca nu, se calculeaza matricele
bloc si se realizeaza operatiile algoritmului recursiv. Valoarea variabilei dim
se injumatateste, pentru a nu declara o alta variabila pentru dimensiunea
matricilor bloc. La final, in matricea final.data se construieste matricea
rezultata prin concatenarea matricilor bloc C1 C2 C3 C4.
    Daca litera citita de la tastatura este Q, se va iesi din program, eliberand
toate resursele programului si variabila start se egaleaza cu 0 pentru siguranta.
    Daca litera citita de la tastatura nu este una dintre cele de mai sus,
se va afisa mesajul de eroare "Unrecognized command.".