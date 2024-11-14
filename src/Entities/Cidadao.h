typedef struct cidadao {
    int id;
    int avenida;
    int rua;
    // Lista de vertex
    
} Cidadao;

typedef Cidadao *pt_Cidadao;

pt_Cidadao cidadao_init(const int id, const int avenida, const int rua);