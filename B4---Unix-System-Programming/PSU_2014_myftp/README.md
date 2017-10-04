Questions par rapport au projet :

--> tentative d'acceder a un dossier avec cd dont pas les droits -> no such file or directory

-----------<<>>----------

functions used : 

getcwd
access
chdir
strerror
perror
memset
realpath

-----------<<>>----------

problem read / write tempo ?
Problem read / write par rapport a fin de transmission -> sans \n boucle inf

-----------<<>>----------

probleme ls -> prend le path complet pas notre path

-----------<<>>----------

cas a gerer : 

echo | ./client (gere)
ligne vide
kill server ou kill client --> my_printf ne gere pas les msg d'erreur ?

gerer kill pendant envoie fichier etc...
gerer mauvais fd du server ou client pour put / get