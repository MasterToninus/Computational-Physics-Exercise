c'è un problema:
I primi test del kernel danno un errore di compilazione perchè negli ultimi test ho modificato l'header in modo da allocare sulla shared array della dimensione del warp!. quindi c'è una costante in più....


la correzione è semplice. bisogna fare in modo che le chiamate delle funzioni di test che usano la shared non chiamino più trhead del consentito!ZZ
