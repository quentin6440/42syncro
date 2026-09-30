FICHE 42 — NETPRACTICE (IPv4, Subnets, Routage)
1. Une adresse IPv4 = 32 bits

Exemple :

192.168.1.10

Chaque nombre = 8 bits :

192        168        1          10
11000000 . 10101000 . 00000001 . 00001010

Total :

4 × 8 = 32 bits
2. Masque de sous-réseau

Le masque indique :

bits à 1 → partie réseau
bits à 0 → partie machine (host)

Exemple :

255.255.255.0

en binaire :

11111111.11111111.11111111.00000000

Donc :

192.168.1.10/24

signifie :

24 bits réseau
8 bits machines
3. CIDR à connaître
CIDR	Masque	Hosts disponibles
/32	255.255.255.255	1 adresse
/30	255.255.255.252	2 hosts
/29	255.255.255.248	6 hosts
/28	255.255.255.240	14 hosts
/24	255.255.255.0	254 hosts
/16	255.255.0.0	65534 hosts

Formule :

nombre d'adresses = 2^(bits host)

Puis :

hosts utilisables = 2^(bits host) - 2

(on enlève réseau + broadcast)

4. Trouver l'adresse réseau

Opération :

IP AND MASK

Exemple :

IP :

192.168.1.10

Masque :

255.255.255.0

Résultat :

192.168.1.0

C'est le réseau.

5. Trouver le broadcast

Le broadcast est :

tous les bits host à 1

Exemple :

Réseau :

192.168.1.0/24

Host bits :

00000000

Broadcast :

11111111

Donc :

192.168.1.255
6. Vérifier si deux machines sont dans le même réseau

Faire :

IP1 & MASK

et

IP2 & MASK

Si résultat identique :

→ même réseau

Sinon :

→ réseaux différents

7. Routeur : règle principale

Un routeur relie des réseaux différents.

Exemple :

PC A
192.168.1.10
     |
     |
192.168.1.1
ROUTER
192.168.2.1
     |
     |
PC B
192.168.2.10

Le routeur doit avoir :

une interface dans chaque réseau
une IP appartenant à chaque subnet
8. Default Gateway

La gateway est :

l'adresse du routeur que la machine utilise pour sortir de son réseau.

Exemple :

PC :

IP:
192.168.1.10

MASK:
255.255.255.0

Gateway:
192.168.1.1

La gateway doit être :

dans le même réseau que le PC
une adresse utilisée par le routeur
9. Table de routage

Un routeur regarde :

Destination       Gateway        Interface

192.168.1.0/24    direct         eth0
192.168.2.0/24    direct         eth1
0.0.0.0/0         10.0.0.1       eth2

Lecture :

"Pour aller vers ce réseau, envoie par cette interface."

10. Le piège classique NetPractice
Mauvais subnet

Exemple :

PC:
192.168.1.10/24

Gateway:
192.168.2.1

Erreur.

Pourquoi ?

PC réseau :

192.168.1.0/24

Gateway réseau :

192.168.2.0/24

Ils ne sont pas dans le même réseau.

11. Ports et connexions

Une machine identifie une connexion avec :

IP + PORT

Exemple :

192.168.1.10:80

IP = machine

Port = service

Quelques ports :

22  SSH
80  HTTP
443 HTTPS
53  DNS
12. Réflexe NetPractice en 5 étapes

Quand un exercice ne marche pas :

1) Vérifier les IP

Les machines ont-elles une IP correcte ?

2) Vérifier les masques

Sont-elles dans le bon réseau ?

Calcul :

IP & MASK
3) Vérifier les gateways

La gateway appartient-elle au même réseau ?

4) Vérifier les interfaces routeur

Chaque interface doit avoir une IP dans son réseau.

5) Vérifier les routes

Le routeur connaît-il le chemin vers la destination ?

Mentalité à garder

Une IP = un nombre de 32 bits.

Un masque = un filtre de bits.

IP & MASK

sépare :

[ partie réseau ][ partie machine ]

Le routeur ne comprend pas "192.168.1.10".

Il manipule seulement :

01000000 10101000 ...

NetPractice = apprendre à lire ces groupes de bits.
