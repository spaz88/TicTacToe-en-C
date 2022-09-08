#include <stdio.h>
#include <stdlib.h>

int tabJeu[3][3] = {0};

int conditionVictoire(){

    if((tabJeu[0][0] == 1 && tabJeu[0][1] == 1 && tabJeu[0][2] == 1)||
       (tabJeu[1][1] == 1 && tabJeu[1][1] == 1 && tabJeu[1][2] == 1)||
       (tabJeu[2][0] == 1 && tabJeu[2][1] == 1 && tabJeu[2][2] == 1)||
       (tabJeu[0][0] == 1 && tabJeu[1][0] == 1 && tabJeu[2][0] == 1)||
       (tabJeu[0][1] == 1 && tabJeu[1][1] == 1 && tabJeu[2][1] == 1)||
       (tabJeu[0][2] == 1 && tabJeu[1][2] == 1 && tabJeu[2][2] == 1)||
       (tabJeu[0][0] == 1 && tabJeu[1][1] == 1 && tabJeu[2][2] == 1)||
       (tabJeu[2][0] == 1 && tabJeu[1][1] == 1 && tabJeu[0][2] == 1)){
           return 1;
       }
    else if((tabJeu[0][0] == 2 && tabJeu[0][1] == 2 && tabJeu[0][2] == 2)||
       (tabJeu[1][1] == 2 && tabJeu[1][1] == 2 && tabJeu[1][2] == 2)||
       (tabJeu[2][0] == 2 && tabJeu[2][1] == 2 && tabJeu[2][2] == 2)||
       (tabJeu[0][0] == 2 && tabJeu[1][0] == 2 && tabJeu[2][0] == 2)||
       (tabJeu[0][1] == 2 && tabJeu[1][1] == 2 && tabJeu[2][1] == 2)||
       (tabJeu[0][2] == 2 && tabJeu[1][2] == 2 && tabJeu[2][2] == 2)||
       (tabJeu[0][0] == 2 && tabJeu[1][1] == 2 && tabJeu[2][2] == 2)||
       (tabJeu[2][0] == 2 && tabJeu[1][1] == 2 && tabJeu[0][2] == 2)){
           return 2;
       }
    else{
        return 0;
    }
}

void joueur1(){
    int ligne, colonne;
    printf("Joueur 1 : \n");
    printf("Entrez une ligne ");
    scanf("%d", &ligne);
    printf("Entrez une colonne ");
    scanf("%d", &colonne);

    if(tabJeu[ligne][colonne] == 0){
        tabJeu[ligne][colonne] = 1;
    }
    else{
        printf("Vous ne pouvez pas jouer cette case\n");
    }
}

void joueur2(){
    int ligne, colonne;
    printf("Joueur 2 : \n");
    printf("Entrez une ligne ");
    scanf("%d", &ligne);
    printf("Entrez une colonne ");
    scanf("%d", &colonne);

    if(tabJeu[ligne][colonne] == 0){
        tabJeu[ligne][colonne] = 2;
    }
    else{
        printf("Vous ne pouvez pas jouer cette case \n");
    }
}

void afficherTableJeu(){
    int i, j;
    for(i=0; i < 3; i++)
    {
      for(j = 0; j < 3; j++)
      {
        printf("%4d",tabJeu[i][j]);
      }

      printf("\n");
    }
}

int main() {

  int k;
  int nbJoueur = 1;
  for(k=0; k<9; k++){

    if(nbJoueur == 1){
        joueur1();
        afficherTableJeu();
        nbJoueur = 2;
    }

    if (nbJoueur == 2){
        joueur2();
        afficherTableJeu();
        nbJoueur = 1;
    }

    switch(conditionVictoire()){
    case 1:
        printf("Le joueur 1 a gagne");
        exit(EXIT_SUCCESS);
    case 2:
        printf("Le joueur 2 a gagne");
        exit(EXIT_SUCCESS);
    }
  }

  return 0;
};
