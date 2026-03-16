# MÈTODES NUMÈRICS
Aquest és el repositori de la primera pràctica de Mètodes Numèrics del Grau de Matemàtiques de la Universitat Autònoma de Barcelona.

En aquesta pràctica, implementarem un programa per fer càlculs amb polinomis de grau elevat de forma eficient. Calcularem el producte, combinació lineal i derivada de polinomis.

Aquesta pràctica està resolta tant en `C` com en `Rust`. En el repositori de GitHub hi ha les versions compilades de les dues versions.

## Pràctica 1: Utilitats per a Polinomis de Grau Elevat

### 1. Motivació del treball
L'objectiu és desenvolupar un conjunt d'utilitats de línia de comandes Unix i una biblioteca en C per treballar amb polinomis de grau elevat. S'ha de poder calcular:
* Combinacions lineals.
* Productes.
* Derivades.
* Avaluacions en punts concrets.

---

### 2. Requeriments Tècnics

#### 2.1 Definicions
* **Format de text (Unix):** Un polinomi $p(x)=a_{0}+a_{1}x+...+a_{n}x^{n}$ es representa com una seqüència ASCII que comença pel seu **grau** seguit dels seus **coeficients** en ordre creixent, separats per espais en blanc o salts de línia.
  * *Exemple:* El polinomi $2.3 - 1.4x + 3.5x^{2}$ es representa com: `2 2.3 -1.4 3.5`.
* **Format de biblioteca (C):** Els coeficients s'emmagatzemen en un vector de tipus `double` i el grau en una variable `int` independent.

#### 2.2 Utilitats de Línia de Comandes
Es requereixen els següents executables:
1. **`./pcl alf bet`**: Calcula la combinació lineal $\alpha p(x) + \beta q(x)$ a partir de dos polinomis llegits per `stdin`.
2. **`./pmul`**: Calcula el producte $p(x)q(x)$.
3. **`./pder`**: Calcula la derivada $p'(x)$.
4. **`./paval`**: Avalua un polinomi en una llista d'abscisses $x_0, \dots, x_m$ i en retorna les parelles $(x_i, p(x_i))$.

#### 2.3 Biblioteca (`pol.h` / `pol.c`)
La biblioteca ha d'incloure les següents funcions:
* `int plleg (FILE *fp, int *n, double **p)`: Llegeix un polinomi i reserva memòria dinàmica amb `malloc()`.
* `void pescr (int n, double *p, FILE *fp)`: Escriu el polinomi en un fitxer o `stdout`.
* `void pcl (int m, double *p, int n, double *q, double alf, double bet, double *r)`: Operació de combinació lineal.
* `void pmul (int m, double *p, int n, double *q, double *r)`: Operació de producte.
* `void pder (int n, double *p, double *dp)`: Operació de derivació.
* `double paval (int n, double *p, double x0)`: Avalua el polinomi usant l'**algorisme de Horner**.

---

### 3. Etapes de Desenvolupament i Validació
1. Escriptura i validació de la biblioteca.
2. Escriptura i validació de les utilitats.
3. **Proves de validació:**
  * **Combinació lineal:** `cat p.txt q.txt | ./pcl 2.37 -1.71 > r1.txt`.
  * **Producte:** `cat p.txt q.txt | ./pmul > r2.txt`.
  * **Derivada:** `./pder < p.txt > r3.txt`.
  * **Gràfica:** Avaluar $p(x)q(x)$ en l'interval $[-0.9, 0.9]$ i representar-ho amb `gnuplot`.

---

### 4. Lliurament
S'ha de lliurar un fitxer comprimit `NIA.zip` que contingui:
* La biblioteca: `pol.c`.
* Les utilitats: `pcl.c`, `pmul.c`, `pder.c`, `paval.c`.
* La memòria del treball en format `memoria.pdf`.