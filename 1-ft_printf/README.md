<img src="utils/FT_PRINTF.png" alt="logo_ft-printf" style="width: 100%">

# Sujet
Reproduire la (célèbre) fonction `printf()`, en prenant en compte les conversions suivantes :

`%c` : Imprimer un seul caractère. <br>
`%s` : Imprimer une chaîne de caractères. <br>
`%p` : Imprimer un pointeur void * en format hexadécimal. <br>
`%d` : Imprimer un nombre décimal (base 10). <br>
`%i` : Imprimer un entier en base 10. <br>
`%u` : Imprimer un nombre décimal non signé (base 10). <br>
`%x` : Imprimer un nombre en format hexadécimal en lettres minuscules (base 16). <br>
`%X` : Imprimer un nombre en format hexadécimal en lettres majuscules (base 16). <br>
`%%` : Imprimer un signe de pourcentage. <br>

## Protoype

**```int ft_printf(const char *format, ...)```**

Le programme ft_printf est une implémentation simplifiée de la fonction printf en langage C. Il permet d’afficher du texte formaté en utilisant divers spécificateurs de format, tels que %d, %s, %c, et d’autres. Cette documentation vous expliquera comment utiliser et comprendre le fonctionnement de ft_printf.

Fonctions principales

Le programme ft_printf est composé de plusieurs fonctions, dont voici les principales :

int ft_printf(const char *origin, ...)

Cette fonction principale est l’équivalent de la fonction printf. Elle prend une chaîne de format en premier argument (comme "Hello, %s!") et des arguments supplémentaires en fonction des spécificateurs de format dans la chaîne. Elle renvoie le nombre de caractères écrits.

int ft_check(char c, va_list args, int count)

Cette fonction est utilisée pour gérer les spécificateurs de format individuels. Elle prend en charge les spécificateurs de format tels que %c, %s, %d, %i, %u, %x, %X, et %p. Elle renvoie le nombre de caractères écrits pour ce spécificateur.

Fonctions auxiliaires

Le programme ft_printf utilise également plusieurs fonctions auxiliaires pour accomplir sa tâche, telles que print_c, print_s, print_nb, print_base, et print_base2. Elles sont utilisées pour l’affichage de caractères, de chaînes, de nombres et de bases différentes.

Comment ça fonctionne

	1.	Lorsque vous appelez ft_printf avec une chaîne de format, il parcourt la chaîne caractère par caractère.
	2.	Lorsqu’il rencontre un caractère %, il analyse le caractère suivant pour déterminer le spécificateur de format.
	3.	En fonction du spécificateur de format rencontré, ft_printf appelle la fonction appropriée (par exemple, print_c pour %c, print_s pour %s, etc.) avec les arguments correspondants.
	4.	Ces fonctions auxiliaires sont responsables de formater et d’afficher correctement les données en utilisant write pour l’affichage.
	5.	Une fois que chaque spécificateur de format a été géré, ft_printf continue de parcourir la chaîne de format jusqu’à ce qu’il ait traité tous les caractères.
	6.	En fin de compte, ft_printf renvoie le nombre total de caractères écrits.


## Résultat de Moulinette
|          Note          |          Tests          |
|:----------------------:|:-----------------------:|
| ![](./utils/grade.png) | ![](./utils/detail.png) |

