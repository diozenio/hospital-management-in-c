# Sistema de Gerenciamento Hospitalar em C

Este é um sistema de gerenciamento hospitalar desenvolvido em C como parte de uma atividade acadêmica. O sistema permite o gerenciamento de pacientes, médicos e enfermeiros em um ambiente hospitalar.

## Funcionalidades

- **Sistema de Autenticação**: Diferentes níveis de acesso para administradores, médicos e enfermeiros.
- **Gerenciamento de Pacientes**: Cadastro, atualização e visualização de informações dos pacientes.
- **Fila de Atendimento**: Organização dos pacientes por gravidade.
- **Hospitalização**: Possibilidade de hospitalizar pacientes e atualizar seu estado.

## Estrutura do Projeto

O projeto está organizado em várias pastas:

- `src/`: Contém o código-fonte principal
  - `apps/`: Aplicações específicas para cada tipo de usuário
  - `include/`: Arquivos de cabeçalho e implementações de estruturas de dados
  - `utils/`: Funções utilitárias
- `bin/`: Arquivos binários e executáveis (gerados durante a compilação)

## Requisitos

- Compilador GCC
- Make (para usar o Makefile)

## Como Compilar e Executar

1. Clone o repositório:

   ```
   git clone https://github.com/diozenio/hospital-management-in-c.git
   cd hospital-management-in-c
   ```

2. Compile o projeto usando o Makefile:

   ```
   make
   ```

3. (Opcional) Crie dados de exemplo:

   ```
   make mock
   ```

4. Execute o programa:
   ```
   make run
   ```

## Uso

Após executar o programa, você será apresentado a uma tela de login. Use as credenciais fornecidas pelo comando `make mock` para acessar o sistema:

- Admin: email "admin", senha "123"
- Enfermeiro: email "enfermeiro", senha "123"
- Médico: email "medico", senha "123"

Cada tipo de usuário terá acesso a diferentes funcionalidades do sistema.

## Limpeza

Para limpar os arquivos compilados:

```
make clean
```

## Licença

Este projeto está licenciado sob a Licença MIT - veja o arquivo [LICENSE](LICENSE) para detalhes.

## Autores

[Dionísio Barbosa](https://github.com/diozenio/) e [Pedro Henrique](https://github.com/pedrohenriquee8)
