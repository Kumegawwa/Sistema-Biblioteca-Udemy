#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//estruturas de dados

struct Livro {
    int codigo;
    char titulo[50];
    char autor[50];
    int quantidade_total;
    int quantidade_disponivel;
};

struct Usuario {
    int codigo;
    char nome[50];
    int idade;
};

struct Emprestimo {
    int codUsuario;
    int codLivro;
};

//bd em memória

struct Livro livros[100];
int totalLivros = 0;

struct Usuario usuarios[100];
int totalUsuarios = 0;

struct Emprestimo emprestimos[100];
int totalEmprestimos = 0;

//arquivos

void salvarDados() {
    FILE *f;

    f = fopen("livros.txt", "w");
    for (int i = 0; i < totalLivros; i++) {
        fprintf(f, "%d;%s;%s;%d;%d\n",
                livros[i].codigo,
                livros[i].titulo,
                livros[i].autor,
                livros[i].quantidade_total,
                livros[i].quantidade_disponivel);
    }
    fclose(f);

    f = fopen("usuarios.txt", "w");
    for (int i = 0; i < totalUsuarios; i++) {
        fprintf(f, "%d;%s;%d\n",
                usuarios[i].codigo,
                usuarios[i].nome,
                usuarios[i].idade);
    }
    fclose(f);

    f = fopen("emprestimos.txt", "w");
    for (int i = 0; i < totalEmprestimos; i++) {
        fprintf(f, "%d;%d\n",
                emprestimos[i].codUsuario,
                emprestimos[i].codLivro);
    }
    fclose(f);
}

void carregarDados() {
    FILE *f;

    f = fopen("livros.txt", "r");
    if (f != NULL) {
        while (fscanf(f, "%d;%49[^;];%49[^;];%d;%d\n",
                      &livros[totalLivros].codigo,
                      livros[totalLivros].titulo,
                      livros[totalLivros].autor,
                      &livros[totalLivros].quantidade_total,
                      &livros[totalLivros].quantidade_disponivel) != EOF) {
            totalLivros++;
        }
        fclose(f);
    }

    f = fopen("usuarios.txt", "r");
    if (f != NULL) {
        while (fscanf(f, "%d;%49[^;];%d\n",
                      &usuarios[totalUsuarios].codigo,
                      &usuarios[totalUsuarios].nome,
                      &usuarios[totalUsuarios].idade) != EOF) {
            totalUsuarios++;
        }
        fclose(f);
    }

    f = fopen("emprestimos.txt", "r");
    if (f != NULL) {
        while (fscanf(f, "%d;%d\n",
                      &emprestimos[totalEmprestimos].codUsuario,
                      &emprestimos[totalEmprestimos].codLivro) != EOF) {
            totalEmprestimos++;
        }
        fclose(f);
    }
}

//sistema 

void cadastrarLivro() {
    struct Livro l;
    printf("Codigo do livro: ");
    scanf("%d", &l.codigo);
    getchar();

    printf("Titulo: ");
    scanf(" %[^\n]", l.titulo);

    printf("Autor: ");
    scanf(" %[^\n]", l.autor);

    printf("Quantidade total: ");
    scanf("%d", &l.quantidade_total);

    l.quantidade_disponivel = l.quantidade_total;
    livros[totalLivros++] = l;

    salvarDados();
    printf("Livro cadastrado com sucesso!\n");
}

void cadastrarUsuario() {
    struct Usuario u;
    printf("Codigo do usuario: ");
    scanf("%d", &u.codigo);
    getchar();

    printf("Nome: ");
    scanf(" %[^\n]", u.nome);

    printf("Idade: ");
    scanf("%d", &u.idade);

    usuarios[totalUsuarios++] = u;
    salvarDados();
    printf("Usuario cadastrado com sucesso!\n");
}

void listarLivros() {
    printf("\n-*- Lista de Livros -*-\n");
    for (int i = 0; i < totalLivros; i++) {
        printf("%d - %s (%s) | Total: %d | Disponiveis: %d\n",
               livros[i].codigo,
               livros[i].titulo,
               livros[i].autor,
               livros[i].quantidade_total,
               livros[i].quantidade_disponivel);
    }
}

void listarUsuarios() {
    printf("\n-*- Lista de Usuarios -*-\n");
    for (int i = 0; i < totalUsuarios; i++) {
        printf("%d - %s | Idade: %d\n",
               usuarios[i].codigo,
               usuarios[i].nome,
               usuarios[i].idade);
    }
}






// MAIN

int main() {
    printf("Sistema de Gerenciamento de Biblioteca\n");
    return 0;
}
