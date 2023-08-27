#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrays.h"
void
modifier_livre (liste_des_livres * l1)
{
  int answer = 1, existe = 0, choix;
  char *code, *code2, *texte, *titree;
  Element_livre *courant;
  courant = (Element_livre *) malloc (sizeof (Element_livre));
  code = (char *) malloc (20 * sizeof (char));
  code2 = (char *) malloc (20 * sizeof (char));
  texte = (char *) malloc (100 * sizeof (char));
  titree = (char *) malloc (100 * sizeof (char));
  if (l1->debut == NULL)
    printf ("Attention la liste des livres est vide!\n");
  else
    {
      courant = l1->debut;
      do
	{
	  system ("clear");
	  if ((answer != 1) && (answer != 2) && (answer != 3))
	    printf ("Attention!Veuillez taper 1 ou 2 ou 3 seulement!\n");
	  printf
	    ("Veuillez donner par quelle methode vous voulez trouvez le livre à modifier:\n1-Code du livre\n2-Titre\n3-Auteur\n");
	  scanf ("%d", &answer);
	}
      while ((answer != 1) && (answer != 2) && (answer != 3));
      system ("clear");
      switch (answer)

	{
	case 1:
	  do
	    {
	      printf ("Veuillez donner le code du livre: ");
	      ViderBuffer ();
	      scanf ("%s", code);
	      if (existence_code (l1, code) == 0)
		printf
		  ("\nAttention le code tapé précedemment n'existe pas!\n");
	    }
	  while (existence_code (l1, code) == 0);

	  printf
	    ("\nVeuillez spécifier ce que vous voulez changer:\n1-Code\n2-Titre\n3-nbr_pages\n4-Auteur\n5-etat\n");
	  ViderBuffer ();
	  do
	    {
	      scanf ("%d", &choix);
	    }
	  while ((choix < 1) || (choix > 5));
	  switch (choix)
	    {
	    case 1:
	      do
		{
		  printf ("Veuillez donner le code du livre: ");
		  ViderBuffer ();
		  scanf ("%s", code2);
		  if (existence_code (l1, code2) == 1)
		    printf
		      ("\nAttention le code tapé précedemment existe déja!\n");
		}
	      while (existence_code (l1, code2) == 1);
	      while (courant != NULL)
		{
		  if (strcmp (courant->lv.code_livre, code) == 0)
		    {
		      courant->lv.code_livre = code2;
		      break;
		    };
		  courant = courant->suivant;

		};
	      break;
	    case 2:
	      printf ("Veuillez donner le nouvel titre: ");
	      ViderBuffer ();
	      scanf ("%[^\n]", texte);
	      while (courant != NULL)
		{
		  if (strcmp (courant->lv.code_livre, code) == 0)
		    {
		      courant->lv.titre = texte;
		      break;
		    };
		  courant = courant->suivant;

		};
	      break;
	    case 3:
	      printf ("Veuillez donner le nouvel nombre de page: ");
	      scanf ("%d", &existe);
	      while (courant != NULL)
		{
		  if (strcmp (courant->lv.code_livre, code) == 0)
		    {
		      courant->lv.nbr_pages = existe;
		      break;
		    };
		  courant = courant->suivant;

		};
	      break;
	    case 4:
	      printf ("Veuillez donner le nouvel auteur: ");
	      ViderBuffer ();
	      scanf ("%[^\n]", texte);
	      while (courant != NULL)
		{
		  if (strcmp (courant->lv.code_livre, code) == 0)
		    {
		      courant->lv.auteur = texte;
		      break;
		    };
		  courant = courant->suivant;

		};
	      break;
	    case 5:
	      do
		{
		  printf
		    ("donner l'ètat du livre :(emprunte / disponible) ");
		  scanf ("%s", texte);
		}
	      while ((strcmp (texte, "emprunte") != 0)
		     && (strcmp (texte, "emprunté") != 0)
		     && (strcmp (texte, "disponible") != 0));
	      while (courant != NULL)
		{
		  if (strcmp (courant->lv.code_livre, code) == 0)
		    {
		      courant->lv.etat = texte;
		      break;
		    };
		  courant = courant->suivant;
		};
	      break;
	    };
	  break;
	case 2:
	  do
	    {
	      printf ("Veuillez donner le titre du livre: ");
	      ViderBuffer ();
	      scanf ("%s", titree);
	      if (existence_titre (l1, titree) == 0)
		printf
		  ("\nAttention le titre tapé précedemment n'existe pas!\n");
	    }
	  while (existence_titre (l1, titree) == 0);
	  if (l1->debut != NULL)
	    {
	      while (courant != NULL)
		{
		  if (strcmp (courant->lv.titre, titree) == 0)
		    {
		      affiche_livre (l1, courant->lv.code_livre);
		    };
		  courant = courant->suivant;
		};
	    };
	  do
	    {
	      printf ("\nVeuillez donner le code du livre: ");
	      ViderBuffer ();
	      scanf ("%s", code);
	      if (existence_code (l1, code) == 0)
		printf
		  ("\nAttention le code tapé précedemment n'existe pas!\n");
	    }
	  while (existence_code (l1, code) == 0);
	  printf
	    ("\nVeuillez spécifier ce que vous voulez changer:\n1-Code\n2-Titre\n3-nbr_pages\n4-Auteur\n5-etat\n");
	  ViderBuffer ();
	  do
	    {
	      scanf ("%d", &choix);
	    }
	  while ((choix < 1) || (choix > 5));
	  switch (choix)
	    {


	    case 1:
	      do
		{
		  printf ("Veuillez donner le code du livre: ");
		  ViderBuffer ();
		  scanf ("%s", code2);
		  if (existence_code (l1, code2) == 1)
		    printf
		      ("\nAttention le code tapé précedemment existe déja!\n");
		}
	      while (existence_code (l1, code2) == 1);
	      while (courant != NULL)
		{
		  if (strcmp (courant->lv.code_livre, code) == 0)
		    {
		      courant->lv.code_livre = code2;
		      break;
		    };
		  courant = courant->suivant;

		};
	      break;
	    case 2:
	      printf ("Veuillez donner le nouvel titre: ");
	      ViderBuffer ();
	      scanf ("%[^\n]", texte);
	      while (courant != NULL)
		{
		  if (strcmp (courant->lv.code_livre, code) == 0)
		    {
		      courant->lv.titre = texte;
		      break;
		    };
		  courant = courant->suivant;

		};
	      break;
	    case 3:
	      printf ("Veuillez donner le nouvel nombre de page: ");
	      scanf ("%d", &existe);
	      while (courant != NULL)
		{
		  if (strcmp (courant->lv.code_livre, code) == 0)
		    {
		      courant->lv.nbr_pages = existe;
		      break;
		    };
		  courant = courant->suivant;

		};
	      break;
	    case 4:
	      printf ("Veuillez donner le nouvel titre: ");
	      ViderBuffer ();
	      scanf ("%[^\n]", texte);
	      while (courant != NULL)
		{
		  if (strcmp (courant->lv.code_livre, code) == 0)
		    {
		      courant->lv.auteur = texte;
		      break;
		    };
		  courant = courant->suivant;

		};
	      break;
	    case 5:
	      do
		{
		  printf
		    ("donner l'ètat du livre :(emprunte / disponible) ");
		  scanf ("%s", texte);
		}
	      while ((strcmp (texte, "emprunte") != 0)
		     && (strcmp (texte, "emprunté") != 0)
		     && (strcmp (texte, "disponible") != 0));
	      while (courant != NULL)
		{
		  if (strcmp (courant->lv.code_livre, code) == 0)
		    {
		      courant->lv.etat = texte;
		      break;
		    };
		  courant = courant->suivant;
		};
	      break;
	    };
	  break;





	case 3:
	  do
	    {
	      printf ("Veuillez donner le nom de l'auteur du livre: ");
	      ViderBuffer ();
	      scanf ("%[^\n]", titree);
	      if (existence_auteur (l1, titree) == 0)
		printf
		  ("\nAttention le nom de l'auteur tapé précedemment n'existe pas!\n");
	    }
	  while (existence_auteur (l1, titree) == 0);
	  if (l1->debut != NULL)
	    {
	      while (courant != NULL)
		{
		  if (strcmp (courant->lv.auteur, titree) == 0)
		    {
		      affiche_livre (l1, courant->lv.code_livre);
		    };
		  courant = courant->suivant;
		};
	    };
	  do
	    {
	      printf ("\nVeuillez donner le code du livre: ");
	      ViderBuffer ();
	      scanf ("%s", code);
	      if (existence_code (l1, code) == 0)
		printf
		  ("\nAttention le code tapé précedemment n'existe pas!\n");
	    }
	  while (existence_code (l1, code) == 0);
	  printf
	    ("\nVeuillez spécifier ce que vous voulez changer:\n1-Code\n2-Titre\n3-nbr_pages\n4-Auteur\n5-etat\n");
	  ViderBuffer ();
	  do
	    {
	      scanf ("%d", &choix);
	    }
	  while ((choix < 1) || (choix > 5));
	  switch (choix)
	    {


	    case 1:
	      do
		{
		  printf ("Veuillez donner le nouvel code du livre: ");

		  ViderBuffer ();
		  scanf ("%s", code2);
		  if (existence_code (l1, code2) == 1)
		    printf
		      ("\nAttention le code tapé précedemment existe déja!\n");
		}
	      while (existence_code (l1, code2) == 1);
	      while (courant != NULL)
		{
		  if (strcmp (courant->lv.code_livre, code) == 0)
		    {
		      courant->lv.code_livre = code2;
		      break;
		    };
		  courant = courant->suivant;

		};
	      break;
	    case 2:
	      printf ("Veuillez donner le nouvel titre: ");
	      ViderBuffer ();
	      scanf ("%[^\n]", texte);
	      while (courant != NULL)
		{
		  if (strcmp (courant->lv.code_livre, code) == 0)
		    {
		      courant->lv.titre = texte;
		      break;
		    };
		  courant = courant->suivant;

		};
	      break;
	    case 3:
	      printf ("Veuillez donner le nouvel nombre de page: ");
	      scanf ("%d", &existe);
	      while (courant != NULL)
		{
		  if (strcmp (courant->lv.code_livre, code) == 0)
		    {
		      courant->lv.nbr_pages = existe;
		      break;
		    };
		  courant = courant->suivant;

		};
	      break;
	    case 4:
	      printf ("Veuillez donner le nouvel titre: ");
	      ViderBuffer ();
	      scanf ("%[^\n]", texte);
	      while (courant != NULL)
		{
		  if (strcmp (courant->lv.code_livre, code) == 0)
		    {
		      courant->lv.auteur = texte;
		      break;
		    };
		  courant = courant->suivant;

		};
	      break;
	    case 5:
	      do
		{
		  printf
		    ("donner l'ètat du livre :(emprunte / disponible) ");
		  scanf ("%s", texte);
		}
	      while ((strcmp (texte, "emprunte") != 0)
		     && (strcmp (texte, "emprunté") != 0)
		     && (strcmp (texte, "disponible") != 0));
	      while (courant != NULL)
		{
		  if (strcmp (courant->lv.code_livre, code) == 0)
		    {
		      courant->lv.etat = texte;
		      break;
		    };
		  courant = courant->suivant;
		};
	      break;
	    };
	  break;
	};
    };
};


void
modifier_adherent (liste_des_adherents * l1)
{
  int choix, existe = 0;
  char *code, *code2, *texte;
  Element_Adherent *courant;
  courant = (Element_Adherent *) malloc (sizeof (Element_Adherent));
  code = (char *) malloc (20 * sizeof (char));
  code2 = (char *) malloc (20 * sizeof (char));
  texte = (char *) malloc (100 * sizeof (char));
  if (l1->debut == NULL)
    printf ("Attention la liste des livres est vide!\n");
  else
    {
      system ("clear");
      courant = l1->debut;
      do
	{
	  printf ("Veuillez donner le code de l'adhérent: ");
	  ViderBuffer ();
	  scanf ("%s", code);
	  if (existence_code_adr (l1, code) == 0)
	    printf
	      ("\nAttention le code tapé précedemment n'existe pas!\n");
	}
      while (existence_code_adr (l1, code) == 0);

      printf
	("\nVeuillez spécifier ce que vous voulez changer:\n1-Code de l'adhérent\n2-Nom de l'adhérent\n3-Nombre d'emprunts de l'adhérent\n");
      ViderBuffer ();
      do
	{
	  scanf ("%d", &choix);
	}
      while ((choix < 1) || (choix > 3));
      switch (choix)
	{


	case 1:
	  do
	    {
	      printf ("Veuillez donner le nouvel code de l'adhérent: ");

	      ViderBuffer ();
	      scanf ("%s", code2);
	      if (existence_code_adr (l1, code2) == 1)
		printf
		  ("\nAttention le code tapé précedemment existe déja!\n");
	    }
	  while (existence_code_adr (l1, code2) == 1);
	  while (courant != NULL)
	    {
	      if (strcmp (courant->Ad.code_adr, code) == 0)
		{
		  courant->Ad.code_adr = code2;
		  break;
		};
	      courant = courant->suivant;

	    };
	  break;
	case 2:
	  printf ("Veuillez donner le nom de l'adhérent: ");
	  ViderBuffer ();
	  scanf ("%[^\n]", texte);
	  while (courant != NULL)
	    {
	      if (strcmp (courant->Ad.code_adr, code) == 0)
		{
		  courant->Ad.nom_adr = texte;
		  break;
		};
	      courant = courant->suivant;

	    };
	  break;
	case 3:
	  printf ("Veuillez donner le nouvel nombre d'emprunts: ");
	  scanf ("%d", &existe);
	  while (courant != NULL)
	    {
	      if (strcmp (courant->Ad.code_adr, code) == 0)
		{
		  courant->Ad.nbrEmp_adr = existe;
		  break;
		};
	      courant = courant->suivant;

	    };
	  break;
	};
    };
};

void
modifier_emprunt (liste_des_Emprunts * l1, liste_des_livres * l2,
		  liste_des_adherents * l3)
{
  int choix, existe = 0;
  date d1;
  char *code, *code2, *texte;
  Element_Emprunt *courant;
  courant = (Element_Emprunt *) malloc (sizeof (Element_Emprunt));
  code = (char *) malloc (20 * sizeof (char));
  code2 = (char *) malloc (20 * sizeof (char));
  texte = (char *) malloc (100 * sizeof (char));
  if (l1->debut == NULL)
    printf ("Attention la liste des livres est vide!\n");
  else
    {
      system ("clear");
      courant = l1->debut;
      do
	{
	  printf ("Veuillez donner l'id de l'emprunt: ");
	  ViderBuffer ();
	  scanf ("%s", code);
	  if (existence_id (l1, code) == 0)
	    printf
	      ("\nAttention le code tapé précedemment n'existe pas!\n");
	}
      while (existence_id (l1, code) == 0);

      printf
	("\nVeuillez spécifier ce que vous voulez changer:\n1-Id\n2-Code livre\n3-Code de l'adhérent\n4-Date de l'emprunt\n5-Date du retour\n");
      ViderBuffer ();
      do
	{
	  scanf ("%d", &choix);
	}
      while ((choix < 1) || (choix > 5));
      switch (choix)
	{


	case 1:
	  do
	    {
	      printf ("Veuillez donner le nouvel Id : ");

	      ViderBuffer ();
	      scanf ("%s", code2);
	      if (existence_id (l1, code2) == 1)
		printf
		  ("\nAttention le code tapé précedemment existe déja!\n");
	    }
	  while (existence_id (l1, code2) == 1);
	  while (courant != NULL)
	    {
	      if (strcmp (courant->Em.id, code) == 0)
		{
		  courant->Em.id = code2;
		  break;
		};
	      courant = courant->suivant;

	    };
	  break;
	case 2:
	  do
	    {
	      printf ("Veuillez donner le code du livre: ");
	      ViderBuffer ();
	      scanf ("%s", code);
	      if (existence_code (l2, code) == 0)
		printf
		  ("\nAttention le code tapé précedemment n'existe pas dans la liste des livres!\n");
	    }
	  while (existence_code (l2, code) == 0);
	  while (courant != NULL)
	    {
	      if (strcmp (courant->Em.id, code) == 0)
		{
		  courant->Em.code_livre = texte;
		  break;
		};
	      courant = courant->suivant;

	    };
	  break;
	case 3:
	  do
	    {
	      printf ("Veuillez donner le nouvel code de l'adhérent: ");

	      ViderBuffer ();
	      scanf ("%s", code2);
	      if (existence_code_adr (l3, code) == 0)
		printf
		  ("\nAttention le code tapé précedemment n'existe pas dans la liste des adherents!\n");
	    }
	  while (existence_code_adr (l3, code2) == 0);
	  while (courant != NULL)
	    {
	      if (strcmp (courant->Em.id, code) == 0)
		{
		  courant->Em.code_adhr = code2;
		  break;
		};
	      courant = courant->suivant;

	    };
	  break;
	case 4:
	  while (courant != NULL)
	    {
	      if (strcmp (courant->Em.id, code) == 0)
		break;
	      courant = courant->suivant;

	    };
	  do
	    {
	      printf ("Veuillez donner le jour: ");
	      ViderBuffer ();
	      do
		{
		  scanf ("%d", &d1.j);
		  if (((d1.j) < 1) || ((d1.j) > 31))
		    printf ("\nAttention Veuillez répéter:\n");
		}
	      while ((d1.j) < 1 || ((d1.j) > 31));
	      printf ("\n-Le mois: ");
	      do
		{
		  scanf ("%d", &d1.m);
		  if (((d1.m) < 1) || ((d1.m) > 12))
		    printf ("\nAttention Veuillez répéter:\n");
		}
	      while (((d1.m) < 1) || ((d1.m) > 12));
	      printf ("\n-L'année: ");
	      do
		{
		  scanf ("%d", &d1.a);
		  if (((d1.a) < 1500) || ((d1.a) > 2050))
		    printf ("\nAttention Veuillez répéter:\n");
		}
	      while (((d1.a) < 1500) || ((d1.a) > 2050));
	      if (periode (d1, courant->Em.date_emp) == 1)
		printf
		  ("\nAttention! La période ne doit pas dépasser 15 jours\n");

	    }
	  while (periode (d1, courant->Em.date_retour) == 1);
	  courant->Em.date_emp = d1;
	  break;
	case 5:
	  while (courant != NULL)
	    {
	      if (strcmp (courant->Em.id, code) == 0)
		break;
	      courant = courant->suivant;

	    };
	  do
	    {
	      printf ("Veuillez donner le jour: ");
	      ViderBuffer ();
	      do
		{
		  scanf ("%d", &d1.j);
		  if (((d1.j) < 1) || ((d1.j) > 31))
		    printf ("\nAttention Veuillez répéter:\n");
		}
	      while ((d1.j) < 1 || ((d1.j) > 31));
	      printf ("\n-Le mois: ");
	      do
		{
		  scanf ("%d", &d1.m);
		  if (((d1.m) < 1) || ((d1.m) > 12))
		    printf ("\nAttention Veuillez répéter:\n");
		}
	      while (((d1.m) < 1) || ((d1.m) > 12));
	      printf ("\n-L'année: ");
	      do
		{
		  scanf ("%d", &d1.a);
		  if (((d1.a) < 1500) || ((d1.a) > 2050))
		    printf ("\nAttention Veuillez répéter:\n");
		}
	      while (((d1.a) < 1500) || ((d1.a) > 2050));
	      if (periode (d1, courant->Em.date_emp) == 1)
		printf
		  ("\nAttention! La période ne doit pas dépasser 15 jours\n");

	    }
	  while (periode (courant->Em.date_emp, d1) == 1);
	  courant->Em.date_retour = d1;
	  break;

	};
    };
};
