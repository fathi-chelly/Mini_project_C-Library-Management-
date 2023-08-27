#include <stdio.h>
#include <stdlib.h>
#include "arrays.h"
int
main (void)
{
  FILE *pf = NULL, *pf1 = NULL;
  int r = 0;
  char r2 = 'r';
  char R = 'R';
  char *rep = NULL, *code = NULL;
  char ligne[500];
  liste_des_livres *l1;
  liste_des_adherents *l2;
  liste_des_Emprunts *l3;
  rep = (char *) malloc (sizeof (char));
  code = (char *) malloc (20 * sizeof (char));
  l1 = (liste_des_livres *) malloc (sizeof (liste_des_livres));
  l2 = (liste_des_adherents *) malloc (sizeof (liste_des_adherents));
  l3 = (liste_des_Emprunts *) malloc (sizeof (liste_des_Emprunts));
  l1->debut = NULL;
  l2->debut = NULL;
  l3->debut = NULL;
  //ouverture du fichier livre:  
  livre *liv = NULL;
  Element_livre *courant = NULL;
  liv = (livre *) malloc (sizeof (livre));
  liv->code_livre = (char *) malloc (20 * sizeof (char));
  liv->titre = (char *) malloc (100 * sizeof (char));
  liv->auteur = (char *) malloc (80 * sizeof (char));
  liv->etat = (char *) malloc (11 * sizeof (char));
  pf = fopen ("livre.txt", "r");
  if (pf == NULL)
    {
      printf ("Erreur dans l'ouverture du fichier livre.txt \n");
      return 1;
    };

  while ((fgets (ligne, 500, pf)) != NULL)
    {
      liv->code_livre = (char *) malloc (20 * sizeof (char));
      liv->titre = (char *) malloc (100 * sizeof (char));
      liv->auteur = (char *) malloc (80 * sizeof (char));
      liv->etat = (char *) malloc (11 * sizeof (char));
      sscanf (ligne, "%s	%[^	]	%d	%[^	]	%s\n",
	      liv->code_livre, liv->titre,
	      &liv->nbr_pages, liv->auteur, liv->etat);
      courant = cree_element (*liv);
      Inserer_Dans_Liste (l1, courant);
    };

  fclose (pf);

//ouverture du fichier adherent:
  Adherent *adh = NULL;
  Element_Adherent *courant2 = NULL;
  adh = (Adherent *) malloc (sizeof (Adherent));
  adh->code_adr = (char *) malloc (20 * sizeof (char));
  adh->nom_adr = (char *) malloc (100 * sizeof (char));
  pf1 = fopen ("adherent.txt", "r");
  if (pf1 == NULL)
    {
      printf ("Erreur dans l'ouverture du fichier adhérent.txt \n");
      return 1;
    };
  if (pf1)
    {
      while ((fgets (ligne, 500, pf1)) != NULL)
	{
	  adh->code_adr = (char *) malloc (20 * sizeof (char));
	  adh->nom_adr = (char *) malloc (100 * sizeof (char));
	  sscanf (ligne, "%s	%[^	]	%d\n", adh->code_adr,
		  adh->nom_adr, &adh->nbrEmp_adr);
	  courant2 = cree_element_adherent (*adh);
	  Inserer_Dans_Liste_Adherent (l2, courant2);
	}

    }
  else
    (printf ("\nErreur d'ouverture du fichier adherent\n"));
  fclose (pf1);


  //ouverture du fichier emprunt:
  Emprunt *empr = NULL;
  Element_Emprunt *courant3 = NULL;
  empr = (Emprunt *) malloc (sizeof (Emprunt));
  empr->id = (char *) malloc (20 * sizeof (char));
  empr->code_livre = (char *) malloc (20 * sizeof (char));
  empr->code_adhr = (char *) malloc (20 * sizeof (char));
  pf1 = fopen ("emprunt.txt", "r");
  if (pf1 == NULL)
    {
      printf ("Erreur dans l'ouverture du fichier emprunt.txt \n");
      return 1;
    };
  if (pf1)
    {
      while ((fgets (ligne, 500, pf1)) != NULL)
	{
	  empr->id = (char *) malloc (20 * sizeof (char));
	  empr->code_livre = (char *) malloc (20 * sizeof (char));
	  empr->code_adhr = (char *) malloc (20 * sizeof (char));
	  sscanf (ligne, "%s	%s	%s	%d/%d/%d	%d/%d/%d\n",
		  empr->id, empr->code_livre,
		  empr->code_adhr, &empr->date_emp.j,
		  &empr->date_emp.m, &empr->date_emp.a,
		  &empr->date_retour.j,
		  &empr->date_retour.m, &empr->date_retour.a);
	  courant3 = cree_element_emprunt (*empr);
	  Inserer_Dans_Liste_Emprunt (l3, courant3);
	}

    }
  else
    (printf ("\nErreur d'ouverture du fichier emprunt\n"));
  fclose (pf1);


  while (r != 15)
    {
      r = EcranPrincipal ();
      switch (r)
	{
	case 1:
	  {
	    Ajouter_livre (l1);
	    do
	      {
		printf
		  ("\nVeuillez taper sur 'R' pour revenir au menu principal: ");
		getchar ();
		scanf ("%c", &*rep);
	      }
	    while ((*rep != R) && (*rep != r2));
	    break;
	  }
	case 2:
	  {
	    modifier_livre (l1);
	    do
	      {
		printf
		  ("\nVeuillez taper sur 'R' pour revenir au menu principal: ");
		getchar ();
		scanf ("%c", &*rep);
	      }
	    while ((*rep != R) && (*rep != r2));
	    break;
	  }
	case 3:
	  {
	    if (l1->debut != NULL)
	      {
		printf ("Veuillez donner le code du livre: ");
		ViderBuffer ();
		scanf ("%s", code);
	      }
	    supprimer_livre (l1, code);
	    do
	      {
		printf
		  ("\nVeuillez taper sur 'R' pour revenir au menu principal: ");
		getchar ();
		scanf ("%c", &*rep);
	      }
	    while ((*rep != R) && (*rep != r2));
	    break;
	  }
	case 4:
	  {
	    if (l1->debut != NULL)
	      {
		printf ("Veuillez donner le code du livre: ");
		ViderBuffer ();
		scanf ("%s", code);
	      };
	    affiche_livre (l1, code);
	    do
	      {
		printf
		  ("\nVeuillez taper sur 'R' pour revenir au menu principal: ");
		getchar ();
		scanf ("%c", &*rep);
	      }
	    while ((*rep != R) && (*rep != r2));
	    break;
	  }
	case 5:
	  {
	    Recherche (l1);

	    do
	      {
		printf
		  ("\nVeuillez taper sur 'R' pour revenir au menu principal: ");
		getchar ();
		scanf ("%c", &*rep);
	      }
	    while ((*rep != R) && (*rep != r2));
	    break;
	  }
	case 6:
	  {
	    Ajouter_adherent (l2);
	    do
	      {
		printf
		  ("\nVeuillez taper sur 'R' pour revenir au menu principal: ");
		getchar ();
		scanf ("%c", &*rep);
	      }
	    while ((*rep != R) && (*rep != r2));
	    break;
	  }
	case 7:
	  {
	    modifier_adherent (l2);
	    do
	      {
		printf
		  ("\nVeuillez taper sur 'R' pour revenir au menu principal: ");
		getchar ();
		scanf ("%c", &*rep);
	      }
	    while ((*rep != R) && (*rep != r2));
	    break;
	  }
	case 8:
	  {
	    if (l2->debut != NULL)
	      {
		printf ("Veuillez donner le code de l'adhérent: ");
		ViderBuffer ();
		scanf ("%s", code);
	      }
	    supprimer_adherent (l2, code);
	    do
	      {
		printf
		  ("\nVeuillez taper sur 'R' pour revenir au menu principal: ");
		getchar ();
		scanf ("%c", &*rep);
	      }
	    while ((*rep != R) && (*rep != r2));
	    break;
	  }
	case 9:
	  {
	    if (l2->debut != NULL)
	      {
		printf ("Veuillez donner le code de l'adhérent: ");
		ViderBuffer ();
		scanf ("%s", code);
	      }
	    affiche_adherent (l2, code);
	    do
	      {
		printf
		  ("\nVeuillez taper sur 'R' pour revenir au menu principal: ");
		getchar ();
		scanf ("%c", &*rep);
	      }
	    while ((*rep != R) && (*rep != r2));
	    break;
	  }
	case 10:
	  {
	    Ajouter_Emprunt (l3, l1, l2);
	    do
	      {
		printf
		  ("\nVeuillez taper sur 'R' pour revenir au menu principal: ");
		getchar ();
		scanf ("%c", &*rep);
	      }
	    while ((*rep != R) && (*rep != r2));
	    break;
	  }
	case 11:
	  {
	    modifier_emprunt (l3, l1, l2);
	    do
	      {
		printf
		  ("\nVeuillez taper sur 'R' pour revenir au menu principal: ");
		getchar ();
		scanf ("%c", &*rep);
	      }
	    while ((*rep != R) && (*rep != r2));
	    break;
	  }
	case 12:
	  {
	    if (l3->debut != NULL)
	      {
		printf ("Veuillez donner l'ID de l'emprunt ");
		ViderBuffer ();
		scanf ("%s", code);
	      }
	    supprimer_emprunt (l3, code);
	    do
	      {
		printf
		  ("\nVeuillez taper sur 'R' pour revenir au menu principal: ");
		getchar ();
		scanf ("%c", &*rep);
	      }
	    while ((*rep != R) && (*rep != r2));
	    break;
	  }
	case 13:
	  {
	    if (l3->debut != NULL)
	      {
		printf ("Veuillez donner l'ID de l'emprunt: ");
		ViderBuffer ();
		scanf ("%s", code);
	      }
	    affiche_emprunt (l3, code);
	    do
	      {
		printf
		  ("\nVeuillez taper sur 'R' pour revenir au menu principal: ");
		getchar ();
		scanf ("%c", &*rep);
	      }
	    while ((*rep != R) && (*rep != r2));
	    break;
	  }
	case 14:
	  {
	  statistiques (  l3,l1);
	    do
	      {
		printf
		  ("\nVeuillez taper sur 'R' pour revenir au menu principal: ");
		getchar ();
		scanf ("%c", &*rep);
	      }
	    while ((*rep != R) && (*rep != r2));
	    break;
	  }
	case 15:
	  {
	    break;
	  }



	};
    };
  //Sauvegarde sur le fichier livre:
  pf = fopen ("livre.txt", "w");
  if (pf)
    {
      Element_livre *temp = l1->debut;
      while (temp != NULL)
	{
	  fprintf (pf, "%s	%s	%d	%s	%s\n",
		   temp->lv.code_livre, temp->lv.titre,
		   temp->lv.nbr_pages, temp->lv.auteur, temp->lv.etat);
	  temp = temp->suivant;
	}
    }
  else
    {
      printf ("\nErreur d'ouverture\n");
    }
  fclose (pf);

//Sauvegarde sur le fichier adherent:
  pf1 = fopen ("adherent.txt", "w");
  if (pf1)
    {
      courant2 = l2->debut;
      while (courant2 != NULL)
	{
	  fprintf (pf1, "%s	%s	%d\n", courant2->Ad.code_adr,
		   courant2->Ad.nom_adr, courant2->Ad.nbrEmp_adr);
	  courant2 = courant2->suivant;
	}
    }
  else
    (printf ("\nErreur d'ouverture\n"));
  fclose (pf1);
//Sauvegarde sur le fichier emprunt:
  pf1 = fopen ("emprunt.txt", "w");
  if (pf1)
    {
      courant3 = l3->debut;
      while (courant3 != NULL)
	{
	  fprintf (pf1, "%s	%s	%s	%d/%d/%d	%d/%d/%d\n",
		   courant3->Em.id,
		   courant3->Em.code_livre,
		   courant3->Em.code_adhr,
		   courant3->Em.date_emp.j,
		   courant3->Em.date_emp.m,
		   courant3->Em.date_emp.a,
		   courant3->Em.date_retour.j,
		   courant3->Em.date_retour.m, courant3->Em.date_retour.a);
	  courant3 = courant3->suivant;
	}
    }
  else
    (printf ("\nErreur d'ouverture\n"));
  fclose (pf1);

  return 0;

}
