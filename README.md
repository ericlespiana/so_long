# So_Long

<h2 align=center>
  
  ![so_long Logo](https://github.com/ericlespiana/erpiana-utils/blob/master/so_longm.png)
</h2>

## Descrição:
So_Long é um projeto do curso da 42 que envolve a criação de um jogo simples em 2D usando a biblioteca gráfica MiniLibX (Nesse projeto eu utilizei a MLX da codam). O objetivo principal é entender os conceitos básicos de programação de jogos, manipulação de gráficos e interações de usuário.

## Funcionalidades:
- **Mapa Interativo**: O jogo permite que o jogador se mova em um mapa 2D.
- **Personagem e Objetos**: Há um personagem controlado pelo jogador e objetos com os quais ele interage.
- **Controles Simples**: Os controles do jogo são simples e intuitivos.

## Requisitos:
- Acesso a um sistema operacional compatível com a biblioteca MLX Codam.
- Make e cmake instalado, com a versão no mínimo 3.16.0 do cmake

## Instalação e Execução:
1. Clone este repositório: `git clone https://github.com/ericlespiana/so_long.git`
2. Navegue até o diretório do projeto: `cd so_long`
3. Baixe o repositório da MLX `git submodule update --init`
4. Compile o programa: `make` ou `make bonus` para jogar o jogo com animações`
5. Execute o jogo: `./so_long maps/map1.ber` ou `./so_long_bonus maps/map1.ber`

## Controles:
- `W`: Mover para cima
- `A`: Mover para a esquerda
- `S`: Mover para baixo
- `D`: Mover para a direita
- `ESC`: Sair do jogo
- O jogo também funciona com as setas pra cima, baixo, esquerda e direita
## Formato do Mapa:
- O mapa é fornecido como um arquivo `.ber`.
- O mapa consiste em caracteres que representam diferentes elementos do jogo:
  - `1`: Parede
  - `0`: Espaço vazio
  - `P`: Personagem
  - `E`: Saída
  - `C`: Coleção de itens
- Exemplo de arquivo de mapa:
  
11111111111111111111111111111111111
10000000000000000000000000000000001
10000000000000000000000000000000001
10000000000000000000000000000000001
1000111100001111001111111111110E001
10001111000011110011111111111100001
10001111000011110011110000111100001
10001111000011110011110000111100001
10001111111111110000000011110000001
1000111111111111000000111100000P001
10000000000011110000111100000000001
100C0000000011110011110000111100001
10000C00000011110011111111111100001
10000C00000011110011111111111100001
10000000000000000000000000000000001
10000000000000000000000000000000001
10000000000000000000000000000000001
11111111111111111111111111111111111


## Contribuição:
Contribuições são bem-vindas! Sinta-se à vontade para enviar pull requests com melhorias ou correções.





