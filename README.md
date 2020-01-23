# MINISHELL

## Challenge


Créer un mini interprétateur de commande UNIX

*  Les lignes de commande doivent être simple (no pipes, no redirection ou autre fonction avancé)
*  Les exécutables sont ceux que vous pouvez trouver dans les chemins indiqués dans la variable `PATH`
*  La gestion des erreurs doivent être gérer sans utiliser `erno` et adapté à la sortie d'erreur
*  Gestion de l'environnement
*  Gestion propre du signal (Ctrl-c)
*  Prompt dynamique

Implémentation d'une série de Builtins:
*  `exit`
*  `echo`
*  `cd`
*  `env`
*  `setenv`
*  `unsetenv`

L'interprétateur ne doit en aucun cas avoir de leaks.

Chaque erreur doit être gérer avec soin. 

Le minishell ne doit pas quitter de manière inattendu (Segmentation fault, bus error, double free, etc).

Fonction autorisé pour la création:

`malloc`, `free`, `access`, `open`, `close`, `read`, `write`, `opendir`, `readdir`, `closedir`, `getcwd`, `chdir`, `stat`, `lstat`, `fstat`, `fork`, `execve`, `wait`, `waitpid`, `wait3`, `wait4`, `signal`, `kill`, `exit`

Tout autre fonction est interdite.

## Utilisation

Pour la compilation, lancer `make`.
Puis `./minishell`
Pour quitter `exit`


## Démonstration

![Démonstration minishell](https://gitlab.com/fchancel/minishell/raw/master/img/minishell1.gif)
![Démonstration minishell](https://gitlab.com/fchancel/minishell/raw/master/img/minishell2.gif)