# Proiect POO - Anul I Semestrul II

# Sistem de Rezervari Zboruri

Acest proiect C++ simuleaza un sistem complet de rezervari pentru zboruri comerciale. A fost realizat ca tema pentru disciplina Programare Orientata pe Obiecte si implementeaza concepte avansate de OOP, precum mostenire, polimorfism, abstractizare, si gestiunea memoriei.

## Functionalitati principale

- Gestionare companii aeriene (Etihad Airways, Air France, TAROM, WizzAir)
- Generare automata de zboruri pe baza unei retele de rute
- Pilotii au CNP valid si sunt alocati corect in functie de anul de incepere a carierei
- Sistem de rezervari:
  - Alegerea unei companii si a unui zbor
  - Selectarea clasei (economic/business)
  - Atribuirea echipajului
  - Introducerea datelor pasagerului si generarea biletului
- Afisarea tuturor zborurilor disponibile (optiunea 1 din meniu)
- Afisarea tuturor rezervarilor realizate in sesiunea curenta (optiunea 3)
- Salvarea rezervarilor intr-un fisier text sub forma de e-mail (optiunea 4)
- Istoric de zboruri pentru fiecare pasager (afisat in optiunea 3)

## Concepte OOP implementate

- Peste 10 clase organizate modular
- Mostenire: clasa de baza `Companie` are patru derivari
- Polimorfism: metode virtuale suprascrise pentru fiecare companie
- Encapsulare si acces controlat prin getter/setteri
- Supraincarcare de functii si operatori
- Utilizarea structurilor pentru tipuri simple (ex: `Date`, `Ora`)
- Membri statici pentru generare ID unic de zbor
- Utilizare de obiecte alocate atat pe stack, cat si pe heap
- Singleton pentru `Retea_Rute` (gestioneaza distantele dintre orase)

## Cum se foloseste

1. Se compileaza proiectul cu suport pentru standardul C++11 sau mai recent
2. Se ruleaza executabilul rezultat
3. Meniul aplicatiei permite:
   - Afisarea tuturor zborurilor (optiunea 1)
   - Crearea unei rezervari (optiunea 2)
   - Afisarea tuturor rezervarilor din sesiune (optiunea 3)
   - Exportul rezervarilor in fisier text (optiunea 4)
   - Iesirea din aplicatie (optiunea 0)

## Structura fisierelor

- `src/` – fisierele .cpp cu implementari
- `include/` – fisierele .h corespunzatoare fiecarei clase
- `main.cpp` – logica meniului principal si legatura intre module
- `rezervari_email.txt` – fisier generat cu rezervarile in format text

## Exemplu rezervare exportata

=== REZERVARI SALVATE ===

--------------------------------------------
To: Mitrea Ioana <6050712000000@client.OOP>
Subject: Confirmare Rezervare Zbor - ID WZ011

Stimate pasager,

Ati efectuat o rezervare cu urmatoarele detalii:

Pasager: Mitrea Ioana (CNP: 6050712000000)
Zbor: WZ011 | Ruta: Baia Mare -> Barcelona
Data: 14/6/2025, Ora: 08:57
Clasa: business
Pret: 429 EUR
Echipaj: Horvath David, Toth Adam
Companie: WizzAir

Va multumim pentru alegerea serviciului nostru!
--------------------------------------------
To: Mitrea Ioana <6050712000000@client.OOP>
Subject: Confirmare Rezervare Zbor - ID WZ009

Stimate pasager,

Ati efectuat o rezervare cu urmatoarele detalii:

Pasager: Mitrea Ioana (CNP: 6050712000000)
Zbor: WZ009 | Ruta: Arad -> Roma
Data: 26/6/2025, Ora: 19:17
Clasa: economic
Pret: 143 EUR
Echipaj: Nagy Luca, Kovacs Istvan
Companie: WizzAir

Va multumim pentru alegerea serviciului nostru!



## Autor

Proiect realizat de Mitrea Anastasia-Ioana pentru cursul de Programare Orientata pe Obiecte, Anul I, Semestrul II, Facultatea de Matematica si Informatica Bucuresti.
