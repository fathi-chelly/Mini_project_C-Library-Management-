#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrays.h"
void
ViderBuffer ()
{
  int c = 0;
  while (c != '\n' && c != EOF)
    c = getchar ();
};


Element_livre *
cree_element (livre lv1)
{
  Element_livre *el;
  el = (Element_livre *) malloc (sizeof (Element_livre));
  el->lv = lv1;
  el->suivant = NULL;
  return el;
};

void
Inserer_Dans_Liste (liste_des_livres * L1, Element_livre * nouveau)
{
  nouveau->suivant = L1->debut;
  L1->debut = nouveau;
};

void
Ajouter_livre (liste_des_livres * L1)
{
  livre *lv1;
  Element_livre *lv = NULL;
  lv1 = (livre *) malloc (sizeof (livre));
  lv1->code_livre = (char *) malloc (20 * sizeof (char));
  system ("clear");
  printf ("Veuillez donner le code du livre : ");
  do
    {
      scanf ("%s", lv1->code_livre);
      if (existence_code (L1, lv1->code_livre) == 1)
	printf ("\nAttention! Le code existe!\n");
    }
  while (existence_code (L1, lv1->code_livre) == 1);

  lv1->titre = (char *) malloc (100 * sizeof (char));
  printf ("donner le titre du livre : ");
  ViderBuffer ();
  scanf ("%[^\n]", lv1->titre);
  printf ("donner le nombre de pages du livre : ");
  scanf ("%d", &lv1->nbr_pages);
  printf ("donner l'auteur du livre : ");
  lv1->auteur = (char *) malloc (80 * sizeof (char));
  ViderBuffer ();
  scanf ("%[^\n]", lv1->auteur);
  lv1->etat = (char *) malloc (11 * sizeof (char));
  do
    {
      printf ("donner l'ètat du livre :(emprunte / disponible) ");
      ViderBuffer ();
      scanf ("%s", lv1->etat);
    }
  while ((strcmp (lv1->etat, "emprunte") != 0)
	 && (strcmp (lv1->etat, "emprunté") != 0)
	 && (strcmp (lv1->etat, "disponible") != 0));
  lv = cree_element (*lv1);
  Inserer_Dans_Liste (L1, lv);

};

void
affiche_livre (liste_des_livres * l1, char *code)
{
  Element_livre *courant;
  courant = (Element_livre *) malloc (sizeof (Element_livre));
  if (l1->debut != NULL)
    {
      courant = l1->debut;
      while (courant != NULL)
	{
	  if (strcmp (courant->lv.code_livre, code) == 0)
	    {
	      printf ("le code du livre est : %s \n", courant->lv.code_livre);
	      printf ("le titre du livre est : %s \n", courant->lv.titre);
	      printf ("le nombre des pages du livre est : %d\n",
		      courant->lv.nbr_pages);
	      printf ("l'auteur du livre est : %s\n", courant->lv.auteur);
	      printf ("l'etat du livre est : %s\n", courant->lv.etat);
	      break;
	    }
	  courant = courant->suivant;

	};
      if (courant == NULL)
	printf ("\nLe code n'existe pas\n");
    }
  else
    printf ("\nLa liste est vide!");
};

Element_Adherent *
cree_element_adherent (Adherent Ad1)
{
  Element_Adherent *el;
  el = (Element_Adherent *) malloc (sizeof (Element_Adherent));
  el->Ad = Ad1;
  el->suivant = NULL;
  return el;

};

void
Inserer_Dans_Liste_Adherent (liste_des_adherents * L2, Element_Adherent * Ad1)
{
  Ad1->suivant = L2->debut;
  L2->debut = Ad1;
};

void
Ajouter_adherent (liste_des_adherents * L2)
{
  Adherent *Ad1 = NULL;
  Element_Adherent *ad = NULL;
  Ad1 = (Adherent *) malloc (sizeof (Adherent));
  Ad1->code_adr = (char *) malloc (20 * sizeof (char));
  system ("clear");
  printf ("donner le code d'un adherent : ");
  do
    {
      scanf ("%s", Ad1->code_adr);
      if (existence_code_adr (L2, Ad1->code_adr) == 1)
	printf ("Attention! Le code existe!\n");
    }
  while (existence_code_adr (L2, Ad1->code_adr) == 1);

  Ad1->nom_adr = (char *) malloc (100 * sizeof (char));
  printf ("donner le nom du l'adhérent : ");
  ViderBuffer ();
  scanf ("%[^\n]", Ad1->nom_adr);
  printf ("donner le nombre des emprunts de l'adhérent : ");
  scanf ("%d", &Ad1->nbrEmp_adr);
  ad = cree_element_adherent (*Ad1);
  Inserer_Dans_Liste_Adherent (L2, ad);

};

Element_Emprunt *
cree_element_emprunt (Emprunt Em1)
{
  Element_Emprunt *el;
  el = (Element_Emprunt *) malloc (sizeof (Element_Emprunt));
  el->Em = Em1;
  el->suivant = NULL;
  return el;
};

void
Inserer_Dans_Liste_Emprunt (liste_des_Emprunts * L3, Element_Emprunt * el)
{
  el->suivant = L3->debut;
  L3->debut = el;
};

int
periode (date d1, date d2)
{
  int mois[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
  if (d1.a % 4 == 0)
    mois[1] = 29;
  if (d1.a == d2.a)
    {
      if (d1.m == d2.m)
	{
	  if (((d2.j - d1.j) <= 15) && ((d2.j - d1.j) >= 0))
	    return 0;
	  else
	    return 1;
	}
      else
	{
	  if (d2.m - d1.m != 1)
	    return 1;
	  else
	    {
	      if (((mois[d1.m - 1] - d1.j + d2.j) <= 15)
		  && ((mois[d1.m - 1] - d1.j + d2.j) >= 0))
		return 0;
	      else
		return 1;
	    }
	}
    }
  else
    {
      if (d2.a - d1.a != 1)
	return 1;
      else
	{
	  if (d2.m == 1 && d1.m == 12)
	    {
	      if ((((31 - d1.j) + d2.j) <= 15) && (((31 - d1.j) + d2.j) >= 0))
		return 0;
	      else
		return 1;
	    }
	  else
	    return 1;
	}
    }
};

void
Ajouter_Emprunt (liste_des_Emprunts * L3, liste_des_livres * l2,
		 liste_des_adherents * l1)
{
  Emprunt *Em1;
  Element_Emprunt *el = NULL;
  Em1 = (Emprunt *) malloc (sizeof (Emprunt));
  Em1->id = (char *) malloc (20 * sizeof (char));
  system ("clear");
  printf ("donner l'identifiant de l'emprunt : ");
  do
    {
      scanf ("%s", Em1->id);
      if (existence_id (L3, Em1->id) == 1)
	printf ("Attention! L'identifier existe!\n");
    }
  while (existence_id (L3, Em1->id) == 1);
  Em1->code_livre = (char *) malloc (20 * sizeof (char));
  do
    {
      printf ("Veuillez donner le code du livre: ");
      ViderBuffer ();
      scanf ("%s", Em1->code_livre);
      if (existence_code (l2, Em1->code_livre) == 0)
	printf
	  ("\nAttention le code tapé précedemment n'existe pas dans la liste des livres!\n");
    }
  while (existence_code (l2, Em1->code_livre) == 0);
  Em1->code_adhr = (char *) malloc (20 * sizeof (char));
  do
    {
      printf ("Veuillez donner le code de l'adhérent: ");

      ViderBuffer ();
      scanf ("%s", Em1->code_adhr);
      if (existence_code_adr (l1, Em1->code_adhr) == 0)
	printf
	  ("\nAttention le code tapé précedemment n'existe pas dans la liste des adherents!\n");
    }
  while (existence_code_adr (l1, Em1->code_adhr) == 0);



  printf
    ("Vous devez mainteneant donner la date de l'emprunt :\nVeuillez commencer par indiquer:\n-Le jour: ");
  do
    {
      scanf ("%d", &Em1->date_emp.j);
      if (((Em1->date_emp.j) < 1 || (Em1->date_emp.j) > 31))
	printf ("\nAttention Veuillez répéter:\n");
    }
  while ((Em1->date_emp.j) < 1 || (Em1->date_emp.j) > 31);
  printf ("\n-Le mois: ");
  do
    {
      scanf ("%d", &Em1->date_emp.m);
      if (((Em1->date_emp.m) < 1 || (Em1->date_emp.m) > 12))
	printf ("\nAttention Veuillez répéter:\n");
    }
  while ((Em1->date_emp.m) < 1 || (Em1->date_emp.m) > 12);
  printf ("\n-L'année: ");
  do
    {
      scanf ("%d", &Em1->date_emp.a);
      if (((Em1->date_emp.a) < 1500 || (Em1->date_emp.a) > 2050))
	printf ("\nAttention Veuillez répéter:\n");
    }
  while ((Em1->date_emp.a) < 1500 || (Em1->date_emp.a) > 2050);

  printf
    ("Vous devez mainteneant donner la date de retour de l'emprunt :\nVeuillez commencer par indiquer:\n-Le jour: ");
  do
    {
      do
	{
	  scanf ("%d", &Em1->date_retour.j);
	  if (((Em1->date_retour.j) < 1 || (Em1->date_retour.j) > 31))
	    printf ("\nAttention Veuillez répéter:\n");
	}
      while ((Em1->date_retour.j) < 1 || (Em1->date_retour.j) > 31);
      printf ("\n-Le mois: ");
      do
	{
	  scanf ("%d", &Em1->date_retour.m);
	  if (((Em1->date_retour.m) < 1 || (Em1->date_retour.m) > 12))
	    printf ("\nAttention Veuillez répéter:\n");
	}
      while ((Em1->date_retour.m) < 1 || (Em1->date_retour.m) > 12);
      printf ("\n-L'année: ");
      do
	{
	  scanf ("%d", &Em1->date_retour.a);
	  if (((Em1->date_retour.a) < 1500 || (Em1->date_retour.a) > 2050))
	    printf ("\nAttention Veuillez répéter:\n");
	}
      while ((Em1->date_retour.a) < 1500 || (Em1->date_retour.a) > 2050);
      if (periode (Em1->date_emp, Em1->date_retour) == 1)
	printf
	  ("\nAttention! La période de l'emprunt ne doit pas dépasser 15 jours!\nVeuillez répéter la saisie:\nVeuillez donner le jour:\n");
    }
  while (periode (Em1->date_emp, Em1->date_retour) == 1);
  el = cree_element_emprunt (*Em1);
  Inserer_Dans_Liste_Emprunt (L3, el);
};

void
affiche_adherent (liste_des_adherents * l2, char *code)
{
  int r = 0;
  Element_Adherent *courant;
  courant = (Element_Adherent *) malloc (sizeof (Element_Adherent));
  if (l2->debut != NULL)
    {
      Element_Adherent *courant = l2->debut;
      while (courant != NULL)
	{
	  if (strcmp (courant->Ad.code_adr, code) == 0)
	    {
	      r = 1;
	      break;
	    }
	  courant = courant->suivant;

	};
      if (r == 1)
	{
	  printf ("le code de l'adhèrent est : %s\n", courant->Ad.code_adr);
	  printf ("le nom de l'adhèrent est : %s\n", courant->Ad.nom_adr);
	  printf ("le nombre des emprunts de l'adhèrent est : %d\n",
		  courant->Ad.nbrEmp_adr);
	}
      else
	printf ("\nLe code n'existe pas!\n");
    }
  else
    printf ("\nLa liste est vide!");
};

void
affiche_emprunt (liste_des_Emprunts * l3, char *code_id)
{
  int r = 0;
  Element_Emprunt *courant;
  courant = (Element_Emprunt *) malloc (sizeof (Element_Emprunt));
  if (l3->debut != NULL)
    {
      Element_Emprunt *courant = l3->debut;
      while (courant != NULL)
	{
	  if (strcmp (courant->Em.id, code_id) == 0)
	    {
	      r = 1;
	      break;
	    }
	  courant = courant->suivant;

	};
      if (r == 1)
	{
	  printf ("l'identitè du l'emprunt est : %s\n", courant->Em.id);
	  printf ("le code du livre est : %s\n", courant->Em.code_livre);
	  printf ("le code d'un adhèrent est : %s\n", courant->Em.code_adhr);
	  printf ("la date de l'emprunt est  : %d/%d/%d\n",
		  courant->Em.date_emp.j, courant->Em.date_emp.m,
		  courant->Em.date_emp.a);
	  printf ("la date du retour est  : %d/%d/%d\n",
		  courant->Em.date_retour.j, courant->Em.date_retour.m,
		  courant->Em.date_retour.a);
	}
      else
	printf ("\nL'ID n'existe pas!\n");
    }
  else
    printf ("\nLa liste est vide!");
};

void
supprimer_livre (liste_des_livres * l1, char *code)
{
  Element_livre *courant = l1->debut;
  Element_livre *precedent = NULL;
  system ("clear");
  if (l1->debut == NULL)
    {
      printf ("\nLa liste est vide!");
      return;
    }

  while (courant != NULL)
    {
      if (strcmp (courant->lv.code_livre, code) == 0)
	{
	  if (courant == l1->debut)

	    l1->debut = courant->suivant;

	  else
	    precedent->suivant = courant->suivant;

	  free (courant);
	  break;
	}
      precedent = courant;
      courant = courant->suivant;
    }

  if (courant == NULL)
    {
      printf ("\nAttention! Le code n'existe pas!\n");
    }
}


void
supprimer_adherent (liste_des_adherents * l1, char *code)
{
  Element_Adherent *courant = l1->debut, *precedent = NULL;
  system ("clear");
  if (l1->debut == NULL)
    printf ("\nLa liste est vide!");
  else
    {
      while (courant != NULL)
	{
	  if (strcmp (courant->Ad.code_adr, code) == 0)
	    {
	      if (courant == l1->debut)

		l1->debut = courant->suivant;


	      else
		precedent->suivant = courant->suivant;

	      free (courant);
	      break;

	    };
	  precedent = courant;
	  courant = courant->suivant;

	};
      if (courant == NULL)
	{
	  printf ("\nAttention! Le code n'existe pas!\n");
	}
    };

};

void
supprimer_emprunt (liste_des_Emprunts * l1, char *code)
{
  Element_Emprunt *courant = l1->debut, *precedent = NULL;
  system ("clear");
  if (l1->debut == NULL)
    printf ("\nLa liste est vide!");
  else
    {
      while (courant != NULL)
	{
	  if (strcmp (courant->Em.id, code) == 0)
	    {
	      if (courant == l1->debut)
		l1->debut = courant->suivant;
	      else
		precedent->suivant = courant->suivant;
	      free (courant);
	      break;

	    };
	  precedent = courant;
	  courant = courant->suivant;

	};
      if (courant == NULL)
	{
	  printf ("\nAttention! L'ID n'existe pas!\n");
	}
    };

};

void
Recherche (liste_des_livres * l1)
{
  int nbr = 0, e1 = 0, e2 = 0, e3 = 0, e4 = 0, e5 = 0;
  char r, *code = NULL, *code2 = NULL, *code3 = NULL, *etat = NULL;
  Element_livre *courant = l1->debut;
  system ("clear");
  printf
    ("Veuillez déterminer les critères selon lesquels la recherche sera entamée:\n(y/n)\n-Le code: ");
  do
    {
      ViderBuffer ();
      scanf ("%c", &r);
      if ((r != 'y') && (r != 'Y') && (r != 'N') && (r != 'n'))
	printf ("\nAttention! Tapez 'n' ou 'y'\n");
    }
  while ((r != 'y') && (r != 'Y') && (r != 'N') && (r != 'n'));
  if ((r == 'y') || (r == 'Y'))
    {
      code = (char *) malloc (20 * sizeof (char));
      printf ("Veuillez donner le code: ");
      ViderBuffer ();
      scanf ("%s", code);
    };
  printf ("\n-Le titre: ");
  do
    {
      ViderBuffer ();
      scanf ("%c", &r);
      if ((r != 'y') && (r != 'Y') && (r != 'N') && (r != 'n'))
	printf ("\nAttention! Tapez 'n' ou 'y'\n");
    }
  while ((r != 'y') && (r != 'Y') && (r != 'N') && (r != 'n'));
  if ((r == 'y') || (r == 'Y'))
    {
      code2 = (char *) malloc (100 * sizeof (char));
      printf ("Veuillez donner le titre: ");
      ViderBuffer ();
      scanf ("%[^\n]", code2);
    };
  printf ("\n-Le nombre de pages: ");
  do
    {
      ViderBuffer ();
      scanf ("%c", &r);
      if ((r != 'y') && (r != 'Y') && (r != 'N') && (r != 'n'))
	printf ("\nAttention! Tapez 'n' ou 'y'\n");
    }
  while ((r != 'y') && (r != 'Y') && (r != 'N') && (r != 'n'));
  if ((r == 'y') || (r == 'Y'))
    {
      printf ("Veuillez donner le nombre de pages: ");
      ViderBuffer ();
      scanf ("%d", &nbr);
    };
  printf ("\n-L'auteur: ");
  do
    {
      ViderBuffer ();
      scanf ("%c", &r);
      if ((r != 'y') && (r != 'Y') && (r != 'N') && (r != 'n'))
	printf ("\nAttention! Tapez 'n' ou 'y'\n");
    }
  while ((r != 'y') && (r != 'Y') && (r != 'N') && (r != 'n'));
  if ((r == 'y') || (r == 'Y'))
    {
      code3 = (char *) malloc (100 * sizeof (char));
      printf ("Veuillez donner l'auteur: ");
      ViderBuffer ();
      scanf ("%[^\n]", code3);
    };
  printf ("\n-L'état: ");
  do
    {
      ViderBuffer ();
      scanf ("%c", &r);
      if ((r != 'y') && (r != 'Y') && (r != 'N') && (r != 'n'))
	printf ("\nAttention! Tapez 'n' ou 'y'\n");
    }
  while ((r != 'y') && (r != 'Y') && (r != 'N') && (r != 'n'));
  if ((r == 'y') || (r == 'Y'))
    do
      {
	etat = (char *) malloc (12 * sizeof (char));
	printf ("donner l'ètat du livre :(emprunte / disponible) ");
	scanf ("%s", etat);
      }
    while ((strcmp (etat, "emprunte") != 0)
	   && (strcmp (etat, "emprunté") != 0)
	   && (strcmp (etat, "disponible") != 0));
  if (l1->debut != NULL)
    {
      while (courant != NULL)
	{
	  e1 = 0;
	  e2 = 0;
	  e3 = 0;
	  e4 = 0;
	  e5 = 0;
	  if (code2 == NULL)
	    e2 = 1;
	  else if (strcmp (courant->lv.titre, code2) == 0)
	    e2 = 1;
	  if (code == NULL)
	    e1 = 1;
	  else if (strcmp (courant->lv.code_livre, code) == 0)
	    e1 = 1;
	  if ((nbr == 0) || ((nbr != 0) && (nbr == courant->lv.nbr_pages)))
	    {
	      e3 = 1;
	    };
	  if (code3 == NULL)
	    e4 = 1;
	  else if (strcmp (courant->lv.auteur, code3) == 0)
	    e4 = 1;
	  if (etat == NULL)
	    e5 = 1;
	  else if ((strcmp (courant->lv.etat, "emprunte")==0)||(strcmp (courant->lv.etat, "emprunté")==0))
	  {
	  if((strcmp (etat, "emprunte") == 0) || (strcmp (etat, "emprunté") == 0))
	  e5 = 1;
	  }
	  else if (strcmp (courant->lv.etat, etat) == 0)
	    e5 = 1;
	  if ((e1 == 1) && (e2 == 1) && (e3 == 1) && (e4 == 1) && (e5 == 1))
	    {
	      affiche_livre (l1, courant->lv.code_livre);
	      printf
		("\n********************************************************************************************\n");
	    }


	  courant = courant->suivant;
	};
    }
  else
    printf ("\nLa liste est vide!\n");




};

void
supprimer_reccurence (liste * l1, char *code)
{
  Element_reccurence *courant = l1->debut, *precedent = NULL;
  if (l1->debut == NULL)
    printf ("\nLa liste est vide!");
  else
    {
      while (courant != NULL)
	{
	  if (strcmp (courant->re.nom, code) == 0)
	    {
	      if (courant == l1->debut)
		l1->debut = courant->suivant;
	      else
		precedent->suivant = courant->suivant;
	      free (courant);
	      break;

	    };
	  precedent = courant;
	  courant = courant->suivant;

	};
      if (courant == NULL)
	{
	  printf ("\nAttention! L'titre n'existe pas!\n");
	}
    };

};

void
statistiques (liste_des_Emprunts * l3, liste_des_livres * l1)
{
system("clear");
  int s, maxi = 0, aff = 0;
  liste *l;
  l->debut = NULL;
  Element_Emprunt *courant1 = l3->debut;
  char *texte = NULL;
  if (courant1 != NULL)
    {
      while (courant1 != NULL)
	{
	  texte = (char *) malloc (100 * sizeof (char));
	  Element_livre *courant2 = l1->debut;
//rechercher le titre du code
	  while (courant2 != NULL)
	    {
	      if (strcmp (courant2->lv.code_livre, courant1->Em.code_livre) ==
		  0)
		{
		  texte = courant2->lv.titre;
		  break;
		}
	      courant2 = courant2->suivant;
	    };
	  //Verifier l'existence du titre dans la liste et incrementer la somme dans le cas de son existence
	  Element_reccurence *courant3 = l->debut;
	  while (courant3 != NULL)
	    {
	      if (strcmp (courant3->re.nom, texte) == 0)
		{
		  (courant3->re.somme)++;
		  break;
		}
	      courant3 = courant3->suivant;

	    };
	  //sinon(si le titre n'existe pas dans l) ajouter une cellule à l qui contient ce titre
	  if (courant3 == NULL)
	    {
	      Element_reccurence *el;
	      el =
		(Element_reccurence *) malloc (sizeof (Element_reccurence));
	      el->re.nom = texte;
	      el->re.somme = 1;
	      el->suivant = l->debut;
	      l->debut = el;
	    };

	  courant1 = courant1->suivant;
	};
      Element_reccurence *temp;

      /*maintenant la liste l est prete, elle contient les titres des livres ainsi que le nombre d'emprunts de ces livres , il nous reste seulement de
         parcourir l est afficher les livres les plus empruntés */
      printf ("Les livres les plus empruntés sont:\n");
      while ((l->debut!=NULL) && (aff < 3))
	{
	  Element_reccurence *temp=l->debut;	
	  //temp à chaque fois va recevoir le debut de la lsite elle va la parcourir en cherchant le titre le plus emprunté,l'affiche,puis on va supprimer sa cellule
	  maxi = 0;
	  char *plus_emprunte;
	  plus_emprunte = (char *) malloc (100 * sizeof (char));
	  while (temp != NULL)
	    {
	      if ((temp->re.somme) > maxi)
		{
		  plus_emprunte = temp->re.nom;
		  maxi = temp->re.somme;
		}

	      temp = temp->suivant;
	    }
	  printf ("%d- %s	%d fois\n", aff + 1, plus_emprunte,maxi);
	  aff++;
	  supprimer_reccurence(l,plus_emprunte);

	}

    }
  else
    printf ("\nAttention la liste est vide!\n");;
};


int
EcranPrincipal (void)
{
  char texte[21][70] =
    { "*Livre:", "1-Ajouter un livre", "2-Modifier un livre",
    "3-supprimer un livre", "4-Afficher un livre", "5-Rechercher un livre",
    "*Adhérent:", "6-Ajouter un adhérent", "7-Modifier un adhérent",
    "8-supprimer un adhérent", "9-Afficher un adhérent",
    "*Emprunt:", "10-Ajouter un emprunt", "11-Modifier un emprunt",
    "12-supprimer un emprunt", "13-Afficher un emprunt",
    "14-Donner les livres les plus empruntés", "15-Quitter", " ", " ",
    " Entrez votre choix:( 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 ):"
  };
  int i, j, r;
  system ("clear");
  for (i = 0; i < 25; i++)
    printf (" ");
  printf ("GESTION DE LA BIBLIOTHEQUE");
  for (i = 0; i < 25; i++)
    printf (" ");
  printf ("\n");
  for (i = 0; i < 75; i++)
    printf ("*");
  printf ("\n*");
  for (i = 0; i < 73; i++)
    printf (" ");
  printf ("*\n*");
  //debut menu livre
  for (i = 0; i < 21; i++)
    {
      for (j = 0; j < 5; j++)
	printf (" ");
      printf ("%s", texte[i]);
      for (j = 0; j < max - (7 + strlen (texte[i])); j++)
	printf (" ");
      printf ("*\n*");
    }
  //fin menu livre
  for (i = 0; i < 75; i++)
    printf ("*");
  printf ("\n");
  do
    {
      scanf ("%d", &r);
      if ((r > 15) || (r <= 0))
	printf (" Attention! Veuillez donner un numero de 1 à 15: ");

    }
  while ((r > 15) || (r <= 0));
  return r;
};
