#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrays.h"

int existence_code (liste_des_livres * L1, char *code)
//Cette fonction vérifie si le code existe dans la liste des livres ou non
{
  Element_livre *courant;
  courant = (Element_livre *) malloc (sizeof (Element_livre));
  if (courant == NULL)
    {
      printf ("Erreur d'allocation!\n");
      return;
    }
  int answer = 0;
  if (L1->debut != NULL)
    {
      courant = L1->debut;
      while (courant != NULL)
	{
	  if (strcmp (courant->lv.code_livre, code) == 0)
	    {
	      answer = 1;
	      break;
	    };
	  courant = courant->suivant;

	};
    };
  return answer;
};

//Si le code existe dans la liste la valeur retournée est 1 sinon 0
int existence_titre (liste_des_livres * L1, char *code)
{
  Element_livre *courant;
  courant = (Element_livre *) malloc (sizeof (Element_livre));
  int answer = 0;
  if (L1->debut != NULL)
    {
      Element_livre *courant = L1->debut;
      while (courant != NULL)
	{
	  if (strcmp (courant->lv.titre, code) == 0)
	    {
	      answer = 1;
	      break;
	    };
	  courant = courant->suivant;

	}
    }
  return answer;
}


int existence_auteur (liste_des_livres * L1, char *code)
{
  Element_livre *courant;
  courant = (Element_livre *) malloc (sizeof (Element_livre));
  int answer = 0;
  if (L1->debut != NULL)
    {
      Element_livre *courant = L1->debut;
      while (courant != NULL)
	{
	  if (strcmp (courant->lv.auteur, code) == 0)
	    {
	      answer = 1;
	      break;
	    };
	  courant = courant->suivant;

	}
    }
  return answer;
};

int existence_code_adr (liste_des_adherents * L1, char *code)
{
  Element_Adherent *courant;
  courant = (Element_Adherent *) malloc (sizeof (Element_Adherent));
  int answer = 0;
  if (L1->debut != NULL)
    {
      Element_Adherent *courant = L1->debut;
      while (courant != NULL)
	{
	  if (strcmp (courant->Ad.code_adr, code) == 0)
	    {
	      answer = 1;
	      break;
	    };
	  courant = courant->suivant;

	}
    }
  return answer;
};
int existence_id (liste_des_Emprunts * L1, char *code)
{
  Element_Emprunt *courant;
  courant = (Element_Emprunt*) malloc (sizeof (Element_Emprunt));
  int answer = 0;
  if (L1->debut != NULL)
    {
      Element_Emprunt *courant = L1->debut;
      while (courant != NULL)
	{
	  if (strcmp (courant->Em.id, code) == 0)
	    {
	      answer = 1;
	      break;
	    };
	  courant = courant->suivant;

	}
    }
  return answer;
};

