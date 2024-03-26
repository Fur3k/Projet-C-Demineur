#include <stdio.h>
#include <stdlib.h>
/*-----Conditions-----*/
int pair_impair(int x) {
	if (x % 2 == 0){
		printf("%d est un nombre pair !\n", x);
	}
	else
	{
		printf("%d est un nombre impair !\n", x);
	}
}

void compare(int a, int b) {
	if (a == b) {
		printf("%d est egale a %d !\n", a, b);
	}
	else if (a < b)
	{
		printf("%d est inferieur a %d !\n", a, b);
	}
	else
	{
		printf("%d est superieur a %d !\n", a, b);
	}
}

void tri_number(int a, int b, int c) {
	if (b < a) {
		if (c <= b) {
			printf("%d %d %d\n", c, b, a);
		}
		else if (c > b && c <= a)
		{
			printf("%d %d %d\n", b, c, a);
		}
		else
		{
			printf("%d %d %d\n", b, a, c);
		}
	}
	else if (b > a)
	{
		if (c <= b && c > a) {
			printf("%d %d %d\n", a, c, b);
		}
		else if (c > b)
		{
			printf("%d %d %d\n", a, b, c);
		}
		else
		{
			printf("%d %d %d\n", c, a, b);
		}
	}
}

void int_float(float x) {
	if (x - (int)x == 0) {
		printf("%.0f est un entier !\n", x);
	}
	else
	{
		printf("%.3f n'est pas un entier !\n", x);
	}
}

void char_alphabet(char x) {
	if (x >= 65 && x <= 90) {
		printf("Ce int est la majuscule %c !\n", x);
	}
	else if (x >= 97 && x <= 122)
	{
		printf("Ce int est la minuscule %c !\n", x);
	}
	else
	{
		printf("%c ne fait pas partie de l'alphabet !\n", x);
	}
}

void conv_date(const char* x) {
	char* c_mois[12] = {"Janvier","Fevrier","Mars","Avril","Mai","Juin","Juillet","Aout","Septembre","Octobre","Novembre","Decembre"};
	int i_mois = ((int)x[3]-48)*10+(int)x[4]-49;
	printf("%c%c-%s-%c%c%c%c\n", x[0], x[1], c_mois[i_mois], x[6], x[7], x[8], x[9]);
}

/*-----Boucles-----*/

void int_premier(int x)
{
	int nb_div = 0;
	int i = 1;
	while(i <= x && nb_div <=2) {
		if (x % i == 0) {
			nb_div++;
		}
		i++;
	}
	if (nb_div == 2) {
		printf("%d est un nombre premier !\n", x);
	}
	else
	{
		printf("%d n'est pas un nombre premier !\n", x);
	}
}

void tri_dizaine() {
	int list[] = { 12,1,150,41,5,80,30,70,62,45 };
	int somme_diz = 0;
	int max_diz = 0;
	for (int i = 0; i < 10; i++) {
		if (list[i] % 10 == 0 && list[i] < 100) {
			somme_diz += list[i];
			if (max_diz < list[i]) {
				max_diz = list[i];
			}
		}

	}
	printf("La somme de toute les dizaines est de %d, et le plus grand nombre est %d !\n", somme_diz, max_diz);
}

/*-----Tableaux-----*/

void occur_int() 
{
	int tab[6] = { 1,3,5,3,1,3 };
	int nb_occur[6] = { 0 };
	for (int i = 0; i < 6; i++)
	{
		if (nb_occur[tab[i]] == 0){
			for (int j = 0; j < 6; j++) {
				if (tab[i] == tab[j]){
					nb_occur[tab[i]]++;
				}
			}
			printf("il y a %d fois %d dans le tableau !\n", nb_occur[tab[i]], tab[i]);
		}
	}
}

void tri_a_bulle() {
	int size = 10;
	int max = 0;
	int tab[10] = { 21,15,321,56,12,54,2,1,4,50 };
	while (size != 1) {
		for (int i = 0; i < size - 1; i++) 
		{
			if (tab[i] > tab[i+1]) {
				max = tab[i];
				tab[i] = tab[i+1];
				tab[i + 1] = max;
			}
		}
		size--;
	}
	for (int j = 0; j < 10; j++) {
		printf(" %d |", tab[j]);
	}
	printf("\n");
}

void tri_insertion() {
	int size = 10;
	int min;
	int tab[] = { 21,15,321,56,12,54,2,1,4,50 };
	for (int i = 1; i < size; i++)
	{
		if (tab[i] < tab[i - 1]) {
			min = tab[i];
			int j = i;
			while (min < tab[j - 1] && j > 0)
			{
				tab[j] = tab[j - 1];
				j--;
			}
			tab[j] = min;
		}
	}
	for (int k = 0; k < 10; k++) {
		printf(" %d |", tab[k]);
	}
	printf("\n");
}

int main() {
	/*-----Conditions-----*/
	pair_impair(4);
	compare(4, 5);
	tri_number(2, 13, 1);
	int_float(4.5545632);
	char_alphabet('A');
	conv_date("25/03/2024");
	/*-----Boucles-----*/
	int_premier(101);
	tri_dizaine();
	/*-----Tableaux-----*/
	occur_int();
	tri_a_bulle();
	tri_insertion();
}