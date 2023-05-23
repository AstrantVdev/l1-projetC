
# l1-project C : Dessin vectoriel

Cette application permet de générer des formes géométriques à partir de coordonnées et de données entrées par l’utilisateur.
Ces formes doivent pouvoir être affichées à l’écran toutes ensembles sur un même plan et à des coordonnées précises. 
C’est un système de commande utilisateur qui permet la création de celles-ci ainsi que l’affichage du plan les représentant.
Ces commandes gèrent aussi entre autres : l’affichage du plan, la destruction des formes, l’aide utilisateur et la sortie du programme.

__***Guide d'utulisation :***__

__Affichage d’une forme :__

>> help   //pour voir les commande disponibles et leurs arguments  
>> polygon 5 5 20 5 15 15  
>> plot

__Effacement d'une forme :__

>> point 5 5  
>> point 10 10  
>> plot  
>> list  
>> delete 2 // delete le point nouvellement créé  
>> list  
>> plot  
>> clear //actualise la matrice  
>> plot  
>> erase //efface toutes les formes  
>> clear  
>> plot     
>> exit //sort du programme

