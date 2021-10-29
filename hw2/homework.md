# HW02

Zadaća se sastoji od 3 zadatka. Za prva dva zadatka potrebno je implementirati
niz funkcija u datotekama cmplx.c i io.c. Neka se zadani prototipi nalaze 
u cmplx.h i io.h datotekama. U direktoriju projekta neka budu src, inc i exe
direktoriji. Potrebno je modificirati Makefile s predavanja tako da je moguće
imati više exe targeta. Za sve funkcije potrebno je napisati testove. Svaka
testna datoteka sadrži funkciju main. Nakon izgradnje projekta direktorij 
exe mora sadržavati testove (npr. test01.elf, test02.elf ...). U Makefile dodati
target run koji će pokrenuti sve testove. Makefile ne smije sadržavati ime ni
jedne datoteke izvornog koda u direktoriju projekta.

Napomena: olakšati si možete na način da datoteke koje sadrže funkciju ``main``
stavite u zaseban direktorij ``exesrc``. Isto tako napravite posebne varijable
za objekte iz ``exesrc`` direktorija. 

## Zadatak 1. (4 boda)

Implementirati skup funkcija za operacije nad kompleksnim brojevima i signalima. 
Potrebno je implementirati sljedeće funkcije:

```
// c = a / b;
void cmplx_div(cmplx_t a, cmplx_t b, cmplx_t c);
// c = a * b;
void cmplx_mul(cmplx_t a, cmplx_t b, cmplx_t c);
// returns |a|
double cmplx_mag(cmplx_t a);
// returns phase in radians of a 
double cmplx_phs(cmplx_t a);
// returns real part of mag/_phs
double cmplx_real(double mag, double phs);
// returns imaginary part of mag/_phs
double cmplx_imag(double mag, double phs);
// returns dft transformation of complex input signal
void cmplx_dft(cmplx_t *input, cmplx_t *output, int N);
// returns inverse dft transformation of complex input signal
void cmplx_idft(cmplx_t *input, cmplx_t *output, int N);
```
Neka je ``cmplx_t`` tip koji je definiran na sljedeći način:
``
typedef float cmplx_t[2];
``
Nemojte koristiti ugrađeno zaglavlje ``complex.h``. Za verificiranje 
ispravnog rada funkcija ``cmplx_dft`` i ``cmplx_idft`` koristiti 
GNU Octave ili Matlab i njihovu funkciju ``fft``. Usporediti ostavrenu
implementaciju sa ``fft`` implementacijom u okruženjima Matlab ili Octave.

## Zadatak 2. (4 boda)

Implementirati funkcije za učitavanje i spremanje riječi (32 bita), 
i poluriječi (16 bita) iz binarne datoteke. Potrebno je implementirati sljedeće 
funkcije:

```
int read_word(int fd);
short read_half(int fd);
void write_word(int fd, int word);
void write_half(int fd, short word);
```

Za pisanje i čitanje iz datoteke, koristiti funkcije read, write, open. 
Dokumentacija je dostupna na http://man7.org/linux/man-pages/man2/read.2.html.

Testiranje ``read`` i ``write`` funkcija i odnosno ``dft`` i ``idft`` 
funkcija obaviti na sljedeći način:
- napisati program ``test_dft.c`` koji mora generirati realni 
signal ``sin(2 * pi * 50 * t)`` uz frekvenciju otipkavanja 
``fs = 200 Hz`` i zatim napraviti ``dft`` transformaciju te 
rezultat slijedno zapisati u datoteku koristeći funkciju ``write_word``.
- napisati program ``test_idft.c`` koji mora učitati sadržaj 
prethodno generirane datoteke koristeći funkciju ``read_word``
napraviti inverznu `dft` transoformaciju i usporediti signal s
generiranim signalom

Napomena: pošto se u datoteku upisuje cjelobrojna riječ jer funkcija
``write_word`` prima cijeli broj od 32 bita (``int word``) potrebno 
je na neki način ``float`` vrijednost pretvoriti u ``int`` vrijednost
korištenjem jednog jednostavnog trika. Naime, u memoriji je neka 
``float`` vrijednost zapisana u obliku predznak|eksponent|mantisa prema 
IEEE 754 standardu. Pretvaranjem (cast) vrijednosti u ``int`` prevoditelj
uzeti cijeli broj te decimalne vrijednosti. Stoga da bi sačuvali ``float``
vrijednost u pravom formatu i zapisali je u datoteku, potrebno je učiniti
sljedeće:
```
float vrijednost = 3.84;
void *a = (void *) &vrijednost;
int vrijednost_ieee = *((int *) a);
int vrijednost_cijeli_broj = (int) vrijednost;
```
U varijabli ``vrijednost_ieee`` je zapisano išto što i u varijabli ``vrijednost``
ali je drugačiji kontekst odnosno tip. Varijablu ``vrijednost_ieee`` predati
kao argument funkciji ``write_word``.

Prilikom čitanja iz datoteke pretvorbu napraviti na sljedeći način:
```
int vrijednost_ieee = read_word(fd);
void *a = (void *) &vrijednost_ieee;
float vrijednost = *((float *) a);
```

Rješenje zadataka 1) i 2) predati u vlastiti GitHub repozitorij naziva 
project-hw02. Repozitorij ne smije sadržavati binarne datoteke.

## Zadatak 3. (2 boda)

Cilj ovog zadatka je ispraviti grešku u postojećem projektu koji se 
nalazi na GitHub-u. Greška se javlja prilikom pokušaja prevođenja. Upute
su u nastavku.

Klonirati repozitorij: 

```
git clone https://github.com/dumpram/odroid-xen-rtos -b hw02.
```
Za izgradnju projekta potreban je arm-none-eabi-gcc prevoditelj koji možete 
preuzeti na poveznici https://launchpad.net/gcc-arm-embedded ili instalirati
na sljedeći način:
```
sudo apt purge gcc-arm-none-eabi
sudo apt purge binutils-arm-none-eabi
sudo apt purge gdb-arm-none-eabi
sudo apt purge gdb-arm-none-eabi
sudo apt autoremove

sudo add-apt-repository ppa:team-gcc-arm-embedded/ppa

sudo apt install gcc-arm-embedded
```
Nakon što je ``toolchain`` dobro konfiguriran pokušajte izgraditi aplikaciju.
Identificirajte vrstu pogrešaka i otklonite ih. Nakon napravljenih izmjena 
rezultat naredbe git diff pohranite u datoteku hw02.patch. Datoteku 
hw02.patch dodati u GitHub repozitorij project-hw02.

## Napomena za bodovanje

Za 1. i 2. zadatak 2 boda nosi razvijena funkcionalnost, a 2 boda odgovarajuća struktura direktorija i ispravan
``Makefile``.
