[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/dWp6iS_E)

# ATUDOSIEI ANDREI CRISTIAN 322AB

# WINDOWS 11

# Am folosit in prima faza Visual Studio 2022(am construit clasele, metodele si toate fisierele, dar se formatau fisierele de afisare diferit), dar apoi am folosit Visual Studio Code(am vazut de ce nu mergeau fisierele de afisare si nu luam punctaj maxim)

## Produs

Aici am creat constructorii necesari, destructorii, am supradefinit operatorii << si = (m-au ajutat la copierea datelor si la debugging) si get-eri pentru fiecare atribut si un seter de care am avut nevoie pentru a schimba cantitatea din stoc.
Am creat toate aceste metode ca la laboratoare.
Am avut putine probleme in zona asta, deoarece aveam un sir de caractere static, iar la laboratoare eram obisnuit sa il declaram pointer. Totusi, nu am vrut sa modific structura data.

## Comanda

Aici am creat constructorii necesari, destructorii, am supradefinit operatorii << si = (m-au ajutat la copierea datelor si la debugging) si get-eri pentru fiecare atribut.

## Client

Aici am facut asemenea ca la celelalte clase.

## Pentru crearea agregarii intre clase, am respectat pasii de la laborator

## Functions

Aici am introdus toate functiile necesare rezolvarii cerintei, adica verificarea ca un fisier e gol citirea stocului, citirea clientilor, o functie de afisare care sa afiseze doar stocul si una pentru clienti si stoc, apoi functia care procesa toate comenzile si facea schimbarile in stoc.

Functia de verificare marimii fisierului functioneaza astfel:

- Este de tip bool deoarece vrem sa returnam true daca e gol fisierul, false daca nu
- Prima linie din functie, deschide fisierul in mod binar si duce cursorul pe ultima pozitie, nu pe prima cum se intampla de obicei
- ftellg ne spune pozitia unde se afla cursorul si daca este 0, inseamna ca fisierul e gol

La functiile de citire am avut grija sa nu am probleme cu newline-ul si cu citirea caracterelor si sirurilor de caractere.

Pe linia 43 si 44 a fost problema care a aparut din cauza IDE-ului. In Visual Studio 2022, daca puneam doar un fisier.ignore() imi crea fisierele de output exact ca in cele de pe Git, dar nu primeam punctaj maxim. Atunci cand intram pe Visual Studio Code si rulam programul, fisierele imi erau create gresit, asa ca am mai adaugat un fisier.ignore(), deoarece am observat ca in loc sa imi citeasca un nume, citeste un newline.

Functia de procesare a stocului, doar parcurge toate comenzile clientilor si scade din produsele din stoc tot ce a fost cumparat

# Main

Am initializat fisierele de citire si afisare, apoi am luat pe cazuri ceea ce se poate intampla

- Daca ambele fisiere de citire erau goale, atunci afisam un mesaj corespunzator in ambele fisiere de afisare
- Daca fisierul cu clientii era gol, lucram doar cu produsele si afisam stocul in fisierul corespunzator
- Daca ambele fisiere de citire au elemente, atunci rezolvam toate cerinta. Produsele le aveam deja citite incepand cu al doilea caz, deci imi mai ramasese sa citesc comenzile. Dupa ce am citit tot, am apelat functia procesareStoc, care imi rezolva practic cerinta si apoi functia de afisare. Am eliberat memoria de la vectorii principali si apoi am inchis fisierele
