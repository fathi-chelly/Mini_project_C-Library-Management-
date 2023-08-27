#ifndef ARRAYS_H
#define ARRAYS_H
#define max 75
typedef struct
{
  char *code_livre;
  char *titre;
  int nbr_pages;
  char *auteur;
  char *etat;
} livre;

typedef struct
{
  livre lv;
  struct Element_livre *suivant;
} Element_livre;

typedef struct
{
  Element_livre *debut;
} liste_des_livres;
typedef struct
{
  char *code_adr;
  char *nom_adr;
  int nbrEmp_adr;
} Adherent;

typedef struct
{
  Adherent Ad;
  struct Element_Adherent *suivant;
} Element_Adherent;

typedef struct
{
  Element_Adherent *debut;
} liste_des_adherents;

typedef struct
{
int j;
int m;
int a;
}date;

typedef struct
{
  char *id;
  char *code_livre;
  char *code_adhr;
  date date_emp;
  date date_retour;
} Emprunt;
typedef struct
{
  Emprunt Em;
  struct Element_Emprunt *suivant;
} Element_Emprunt;

typedef struct
{
  Element_Emprunt *debut;
} liste_des_Emprunts;
typedef struct
{
    char * nom ;
    int somme ;
}reccurence ;
typedef struct
{
    reccurence re;
    struct Element_reccurence *suivant;
}Element_reccurence;

typedef struct
{
    Element_reccurence * debut ;
}liste;
void
ViderBuffer ();
int
existence_code (liste_des_livres * , char *);
int
existence_titre (liste_des_livres * , char *);
int
existence_auteur (liste_des_livres * , char *);
int
existence_code_adr (liste_des_adherents * , char *);
int
existence_id (liste_des_Emprunts * , char *);
Element_livre *
cree_element (livre );
void
Inserer_Dans_Liste (liste_des_livres * , Element_livre * );
void
Ajouter_livre (liste_des_livres *);
void
affiche_livre (liste_des_livres * , char *);
Element_Adherent *
cree_element_adherent (Adherent );
void
Inserer_Dans_Liste_Adherent (liste_des_adherents * , Element_Adherent * );
void
Ajouter_adherent (liste_des_adherents * );
Element_Emprunt *
cree_element_emprunt (Emprunt );
void
Inserer_Dans_Liste_Emprunt (liste_des_Emprunts * , Element_Emprunt * );
int
periode (date , date );
void
Ajouter_Emprunt (liste_des_Emprunts * ,liste_des_livres * ,liste_des_adherents *);
void
affiche_adherent (liste_des_adherents * , char *);
void
affiche_emprunt (liste_des_Emprunts * , char *);
void
supprimer_livre (liste_des_livres * , char *);
void
supprimer_adherent (liste_des_adherents * , char *);
void
supprimer_emprunt (liste_des_Emprunts * , char *);
void Recherche(liste_des_livres *);
int
EcranPrincipal (void);
void
modifier_livre (liste_des_livres * );
void
modifier_adherent (liste_des_adherents * );
void
modifier_emprunt (liste_des_Emprunts * , liste_des_livres * ,liste_des_adherents * );
void
supprimer_reccurence (liste *, char *);
void statistiques ( liste_des_Emprunts * ,liste_des_livres* );
#endif
		  
