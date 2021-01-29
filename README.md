# Automat na teplé nápoje v C++

![title](https://www.mistik.space/images/portfolio/5.jpg)

Mojim cieľom v tomto projekte bolo vytvoriť model automatu na teplé
nápoje, ktorý by jeho prevádzkovateľovi umožňoval rozmanitejšie voľby
kombinácií surovín pre vytvorenie nápojov. Pre tento cieľ som sa
inšpiroval skutočným nápojovým automatom, avšak niektoré technické
záležitosti (presné množstvo surovín, ich počet) som musel len odhadnúť.

Tento automat má 7 priehradiek na suroviny (konkrétne sú to: cukor,
káva, esencia whisky, bujón, čokoláda, sušené mlieko, čaj). Štandardne
má každá priehradka kapacitu 1kg, ale táto hodnota sa dá navýšiť,
prípadne znížiť - všetko z závislosti od dopytu po konkrétnych
produktoch.

Čo sa týka hotovosti, platba je možná len mincami v niekoľkých
nominálnych hodnotách, až na dve výnimky - jedno a dvoj centové mince
bežný automat neakceptuje, všetky ostatné mince automat (od 5 centov do
2 eur/€) akceptuje. Štandardne automat obsahuje z každej mince 9 kusov,
avšak aj toto množstvo sa dá meniť podľa potreby.

Automat dokáže vyrobiť presne 10 rôznych nápojov. Nebude fungovať ani
s menším ani s väčším počtom možností prípravy nápojov. Toto je spravené
takto zámerne, keby reálne niekde fungoval tak nech využíva celý svoj
potenciál.

Nápoje vo svojej podstate môžu mať rôzne názvy či ceny. V tomto prípade
majú určené, koľko gramov si z každej suroviny čerpajú. Štandardne som
v prípade tvorby nového automatu podľa vzoru už existujúcich automatov
predefinoval 10 základných nápojov a odhadom im nastavil odber surovín.
Nápoje sa však dajú vytvárať aj vlastné.

*Bežný automat štandardne vydáva týchto 10 druhov nápojov:*

-   Káva

-   Veľká káva

-   Kapučíno

-   Kapučíno s čokoládou

-   Mliečna káva

-   Káva s čokoládou

-   Citrónový čaj

-   Čokoláda

-   Irish cream

-   Polievka

Pre konkrétne typy nápojov je možné vybrať si aj predvoľbu, a teda
nastaviť možnosť pridania cukru alebo zvoliť nápoj bez cukru. Prípadne
je možné zvoliť aj možnosť bez predvoľby, a teda v tomto prípade bude
množstvo cukru nastavené na optimálnu hodnotu pre každý z konkrétnych
typov nápojov.

Zmeny ceny nápojov je možné regulovať prostredníctvom zamestnaneckých
kľúčov. Bez kľúča majú nápoje rôzne ceny, ale po vložení kľúča majú
všetky nápoje rovnakú sumu, a to 25 centov.

Vydávanie mincí je asi najzložitejšia funkcia. Na začiatok sa určí,
koľko kombinácii pre určenú sumu v centoch (to bude kredit mínus cena
nápoja) existuje - na to je pripravený algoritmus s lineárnou
zložitosťou (O(n)), a teda algoritmus, ktorého zložitosť rastie lineárne
s veľkosťou vstupu. Ak bude výsledné číslo väčšie ako nula, potom si
automat všetky tieto kombinácie po jednom prejde. Rozpis všetkých
kombinácií do 2€ (vrátane) má už automat pripravený, o čom sa domnievam,
že takto tento proces reálne v automatoch funguje.

Zaujímavé je, že napríklad na sumu 2€ pri eurominciach od 5 centov, po
2€ (vrátane) existuje 293 rôznych možností.

Pri zakúpení nápoja v prípade, že zákazník vhodí presnú sumu, je pre nás
vyššie zmienený krok nepodstatný - presná suma za daný nápoj sa zaráta a
nápoj sa následne vyrobí.

Ak do automatu vložíme sumu väčšiu ako je cena nápoja, ale bude to stále
2€ alebo menej, tak sa automat "pokúsi" vydať príslušnú sumu a nápoj
vyrobí. Ak automat nebude mať dostatok mincí nutných pre vydanie do sumy
zákazníka, tak stanovenú sumu nevydá.

Posledná možnosť je tá, že ak vložíme sumu vyššiu ako 2€, čo reálny
automat neumožňuje (bežný automat by mince okamžite vrátil), mnou
naprogramovaný automat umožňuje využiť aj takúto možnosť platby. V tomto
prípade si automat z celkovej sumy zarezervuje iba sumu 2€ a snaží sa
vydať príslušnú sumu a nápoj vyrobí. Ak automat nemá dostatok vhodných
mincí, nechá si celé 2€.
