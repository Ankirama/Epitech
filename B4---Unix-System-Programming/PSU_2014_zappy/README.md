TODO : Commencer le projet

Précisions sur l'incantation :
Il faut le nombre exact de pierres sur la même case, si c'est plus ou moins impossible de la lancer.
Le nombre de pierres peut être partagés entre les différentes IA, si une IA fait une expulsion l'incantation est annulée

                  SERVER                         /          CLIENT                           /          CLIENT_GRAPHIQUE
Langage :           C                                        C++                                      C++ et SFML
Répartition:  Fabien (réseau) / Charles (jeu)        Raphael (réseau & ia) / Alex (ia)

Server -> select (prévoir fd pour le client graphique)
Client -> normal + fork pour lancer autre client

Server -> paramètres par défauts


ENUM stones	0-5;
define MEAT	6;
define NB_OBJET 7;

SERVEUR (structures):
t_team:
	liste de joueur
	char * name team
	char nb_lvl_max

t_player:
	unsigned int inventaire[7]
	char lvl
	t_orientation orientation
	unsigned int pos;
	int fd;

t_case:
	unsigned int objets[7]
	list joueur_case

t_player_case:
	t_player
	next

t_server:
	int	fd[USER]
	fct	write[USER]
	fct	read[USER]
	t_case	tab[taille]
	unsigned int	length
	unsigned int	width;
	(USER => max player + 1)

JOUEUR :
t_joueur:
	int fd
	char lvl;
./zappy_server -p 4224 -x 100 -y 100 -n meow sao louise zero -c 4 -t 1 --debug
