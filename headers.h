typedef struct{
    char nombre[100];
    float precio;
    float stock;
    int id;
} Producto;

struct Pila{
    Producto item;
    struct Pila *siguiente;
};
typedef struct Pila Pila;

Pila* agregarItem(Pila* pila, Producto producto);
void leerProductos(Pila* pila);
Pila* removerItem(Pila* pila);
void insertar(Pila* inicio, Pila* ultimo);