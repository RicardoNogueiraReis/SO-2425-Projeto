# SO-2425-Projeto

## **Índice**

1. [Regras principais para uma melhor organização do trabalho e código](#1)
1. [Estruturação e Organização do Projeto](#2)
1. [Práticas de Codificação e Estilo](#3)
1. [Trabalho em Equipa e Documentação](#4)
1. [Inteligência Artificial](#5)
1. [Validação](#6)

### 1. Regras principais para uma melhor organização do trabalho e código <a name="1"></a>

- **Indentar devidamente o código para que seja legível.**
- **Comentar o código apenas se ele não for auto-explicativo ou se for necessário explicar o porquê da sua implementação.**
- **Sempre que é feita uma funcionalidade ou é feito algum progresso de uma tarefa, mandem para o repositório para ficar guardado desde que respeite as seguintes regras:**
	- Código enviado não interfere com o funcionamento do resto do projeto;
	- Código funciona parcialmente e o;
	- Código é legível.

> [!NOTE]
> Lembrem-se que não vão ser os únicos a ler o que escreveram e mais tarde poderão vir a necessitar de rever o que escreveram


### 2. Estruturação e Organização do Projeto <a name="2"></a>

- **Seguir uma estrutura de pastas clara e organizada**: 
	- Separem o código em funções auto descritivas para melhorar o processo de *debug* e o código ser mais legível:
	
```c
int funcao1(int parametros) {
	// Código omitido
	
	funcao2(outroParameteros);
	
	// Código omitido
	
}

int funcao2(int outroParameteros) {
	// Código omitido
	
}
```


- **Nomes de ficheiros e funções descritivos**: 
	- Usem nomes que descrevam o que as funções fazem e evitem ambiguidades. Assim, é mais fácil perceber o que o código faz.


### 3. Práticas de Codificação e Estilo <a name="3"></a>

- **Seguir um estilo de código consistente**: 
	- Sigam a nomenclatura de variáveis/Estruturas/funções do C e sejam consistentes.
	
- **Evitar variáveis globais**:
	- Usem variáveis locais ou passem-nas como parâmetros sempre que possível.

- **Limpeza de memória**: 
	- Sempre que alocarem memória (ex: `malloc`), verifiquem foi libertada (`free`) para evitar *memory leaks*. 

### 4. Trabalho em Equipa e Documentação <a name="4"></a>

- **Em casos em que é necessário efetuar *merges* de código:
	- Tenham cuidado em não substituir código dos outros membros que podem ser cruciais para o funcionamento do projeto ou que ainda esteja em progresso de estar acabado;
	- Definam o VS Code para fazer os *Git merges*, é mais fácil e é mais visual;
	- Se não souberem, peçam a alguém que saiba, é necessário explicar o contexto do código ao colega para que fique bem feito e nenhum código seja eliminado desnecessariamente (evitem fazer isto, tentem aprender como se faz para não se perder muito tempo).

- **Documentação mínima para cada função**:
	- Mesmo que o código seja auto explicativo, recomenda-se que incluam uma breve descrição antes de cada função (vejam como se faz no ficheiro ``/pdfs/Doxygen.pdf``);
	- Indicar o que a função faz, os seus parâmetros e o valor de retorno (se aplicável).

```c
/**
 * Descrição da função.
 * 
 * @param parametro Tipo e descrição do parâmetro.
 * @return Descrição do valor de retorno.
 */
int minhaFuncao(int parametro) {
    // Código da função
    
}

```

### 5. Inteligência Artificial <a name="5"></a>

- **Não usem ChatGPT para fazer o código todo por vocês**:

	- Algo que **não** pode ser levado a brincar, código gerado pelo ChatGPT, quando não se domina de código leva a incompatibilidade com o resto do projeto;

> [!caution]
>Código gerado por I.A. em geral que não seja compatível com o resto do projeto, que é demasiado complexo desnecessariamente e que não funcione:
> - **Não** é da responsabilidade dos outros membros de corrigir e;
>- **Não conta como contribuição.**
### 6. Gestão de Versões e Alterações <a name="6"></a>

- **Escrever mensagens de *commit* claras**: 
	- A mensagem deve indicar de forma simples e direta o que foi alterado.
	- Façam pequenos progressos e mandem para que a mensagem do *commit* seja pequena, concisa e para não se esquecerem de incluir detalhes do que foi feito.


### 7. Validação<a name="7"></a>

- **Verificação de erros**:
	- Sempre que lidarem com *input/output* de dados ou alocação de memória, implementem verificações para garantir que o código funcione bem em caso de falha.
