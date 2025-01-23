typedef enum { drama, comedy, thriller, adventure, biography } janr_t;

typedef struct _dat1 {
    int id;
    char name[16];
    char otch[16];
    char family[16];
    char email[16];
} authors;

typedef struct _dat2 {
    int id;
    char name[32];
    int aut_id;
    int publish_id;
    janr_t janr;
} books;

typedef struct _dat3 {
    int id;
    char name[16];
    long long inn;
    char email[16];
} publishers;