typedef struct lista Lista;
int retornaTamanho(Lista *L);
Lista* retira_prefixo(Lista* L, int *v);
Lista* retirarTodos(Lista* L, int *v, int qnt);
void imprimir(Lista *L);
Lista* insereInicio(Lista *L, int num);
