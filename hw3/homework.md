# 3. zadaća

## 1. zadatak (10 bodova)

Riješiti 1. laboratorijsku vježbu iz kolegija PPIUS. Obavezno obaviti testiranje na STM32F4 platformi i utvrditi je li ponašanje
očekivano. Upute se nalaze u repozitoriju (``PIES_lab1_upute.pdf``).

Upute su pisane za mikrokontroler STM32F407, a vi imate razvojni sustav temeljen na mikrokontroleru
STM32F429. Ti sustavi su slični, ali postoje neke razlike na koje morate paziti da bi stvar radila
na drugom sustavu (konfiguracija ulazno-izlaznih priključaka, memorijski raspored i slično). Ono što
je potrebno napraviti da bi stvar radila i na razvojnom sustavu STM32F429 je sljedeće:
- upute stranica 6. Kako biste testirali jeste li instalirali i ispravno konfigurirali sve potrebne alate za razvoj programske potpore, na mikrokontroleru ćete pokrenuti gotov primjer koji pali i gasi LE diode. U uputama su navedene naredbe za dohvaćanje repozitorija s programskom potporom za STM32F407, a vi trebate pokrenuti sljedeće naredbe:
```
$ git clone https://github.com/PIES-laboratory-exercises/STM32F429_test_example.git
$ cd STM32F429_test_example
$ make
$ st-flash write build/STM32F429_test_example.bin 0x8000000
```
- upute stranica 8. U izborniku za odabir mikrokontrolera, izaberite STM32F429ZITx.
- za ispravan rad ``blinky`` programa potrebno je uočiti da razvojni sustav ima samo dvije LE diode koje nisu
spojene na iste priključke kao na STM32F407 platformi. 
Konfiguracija LE dioda na STM32F429 platformi je sljedeća:
  - LD3: pin PG13
  - LD4: pin PG14

Inicijalizaciju GPIO pinova će alat STM32CubeMX učiniti za vas, no opisane korake vezane uz Blinky funkcionalnost (poglavlja 4.3. i 4.4.) trebate prilagoditi sukladno s tablicom.