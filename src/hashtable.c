// see: https://stackoverflow.com/questions/4384359/quick-way-to-implement-dictionary-in-c
// Refer to 6.6 in the C Programming Language book

struct nlist { /* table entry: */
    struct nlist *next; /* next entry in chain */
    char *name; /* defined name */
    char *defn; /* replacement text */
};

#define HASHSIZE 101
static struct nlist *hashtab[HASHSIZE]; /* pointer table */

/* hash: form hash value for string s */
/* The hashing function adds each character value in the string to a scrambled combination of the previous ones and returns the remainder modulo the array size*/
unsigned hash(char *s)
{
    unsigned hashval;
    for (hashval = 0; *s != '\0'; s++)
      hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
}

/* The hashing process produces a starting index in the array hashtab.
   If the string is found anywhere, it will be in the list of blocks beginning there. 
   If lookup finds the entry already present, it returns a pointer to it; if not, it returns NULL
*/

/* lookup: look for s in hashtab */
struct nlist *lookup(char *s)
{
    struct nlist *np;
  //for (ptr = head; ptr != NULL; ptr = ptr->next) <-- this for loop is the standard idiom for walking a linked list
    for (np = hashtab[hash(s)]; np != NULL; np = np->next) 
        if (strcmp(s, np->name) == 0)
          return np; /* found */
    return NULL; /* not found */

}

char *strdup(char *);

/*
    Install uses lookup to determine whether the name being installed is already present; if so, the new definition will supersede the old one
    Otherwise, a new entry is created.
    If there is no room for a new entry, install returns NULL
*/

/* install: put (name, defn) in hashtab */
struct nlist *install(char *name, char *defn)
{
    struct nlist *np;
    unsigned hashval;
    if ((np = lookup(name)) == NULL) { /* not found */
        np = (struct nlist *) malloc(sizeof(*np));
        if (np == NULL || (np->name = strdup(name)) == NULL)
          return NULL;
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    } else /* already there */
        free((void *) np->defn); /*free previous defn */
    if ((np->defn = strdup(defn)) == NULL)
       return NULL;
    return np;
}

char *strdup(char *s) /* make a duplicate of s */
{
    char *p;
    p = (char *) malloc(strlen(s)+1); /* +1 for ’\0’ */
    if (p != NULL)
       strcpy(p, s);
    return p;
}

/*
    Exercise write a function undef that will remove a name and defintion from the table mainted by lookup and install
*/

/*
    Implement a simple version of the #define processor (i.e. no arguments) suitable for use with C programs
    You may find getch and ungetch helpful.
*/