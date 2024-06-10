## Push Swap

Neste projeto, os alunos são encarregados de classificar uma lista de números desordenados. Para fazer isso, os alunos devem usar exatamente duas pilhas e manipular os números entre as duas pilhas usando um conjunto de 11 operações predefinidas de pilha.

O projeto Push_Swap desafia os participantes a desenvolver um programa capaz de ordenar uma lista de números desordenados fornecida como argumentos de entrada. 
No entanto, há uma restrição interessante: os participantes só podem usar duas pilhas, denominadas A e B, e devem manipulá-las seguindo regras específicas.
As operações permitidas são limitadas: os participantes podem empurrar (push) um elemento de uma pilha para a outra, ou seja, mover o elemento do topo da pilha A para o topo da pilha B e vice-versa. Além disso, podem realizar uma troca (swap) nos dois primeiros elementos do topo de uma pilha, invertendo suas posições. Por fim, é permitido rotacionar (rotate) uma pilha, movendo seu elemento superior para a base da pilha ou vice-versa.
Essas restrições nas operações permitidas com as pilhas são o cerne do desafio e dão nome ao projeto.

### Rodando o código

- Faça o clone deste repositório: `git clone`
- Compile o programa usando o `make`
- Passe uma lista de números desordenados separados por 
espaços para o programa push_swap: `./bin/push_swap 42 -42 1 2 3 0 472834 2347 -66573567`

Ele irá fornecer como saída todas as operações de pilha que foram aplicadas sequencialmente para ordenar sua lista em ordem crescente.
