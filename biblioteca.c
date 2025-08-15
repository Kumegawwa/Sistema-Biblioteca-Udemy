#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- Estruturas de Dados ---

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

// --- "Banco de Dados" em Memória ---

struct Livro livros[100];
int totalLivros = 0;

struct Usuario usuarios[100];
int totalUsuarios = 0;

struct Emprestimo emprestimos[100];
int totalEmprestimos = 0;

// --- Função Principal (main) ---




int main() {
    printf("Sistema de Gerenciamento de Biblioteca\n");
    return 0;
}
