## Ideia:

Um Jogo 2D de **movimentação lateral** onde o personagem está dentro de um navio no mar e é a representação do capitão de uma tripulação pirata. O objetivo do jogo é **conquistar uma tripulação** inteira de piratas que desempenhem **todas as funções** dentro do navio, cada membro da tripulação representa uma vida.

**Como funciona:** os personagens irão *cair sobre a tela*, e com a movimentação lateral, o jogador irá escolher quais tokens irá pegar, a cada personagem pego, aumenta um **ponto de vida** e chega mais perto da vitória, mas, além dos personagens, também **cairão monstros marinhos** como *Krakens* e *Leviatãs*. 

Ao encostar em um monstro marinho, a sua **tripulação** perderá o membro mais antigo, aquele que foi selecionado primeiro.

Quando estiver com **apenas o capitão** e relar em um monstro marinho, o jogo acaba e **você perde**, mas, quando **coletar um membro de cada função** do navio para sua tripulação, o jogo acaba e **você ganha.**

Além disso, coletar **membros repetidos** vai ser permitido, entretanto, seu navio **afunda com 12 tripulantes**, portanto, é necessário saber administrar o uso das *“vidas”* e ter **estratégia** para montar sua tripulação completa utilizando as percas de tripulantes para monstros marinhos.

## TRIPULAÇÃO:

Cozinheiro: Prepara a comida para os tripulantes

Navegador: Cuida dos mapas e rotas de navegação

Caçador: Luta com os monstros marinhos com uma espada

Capitão: já inicia o jogo com ele, cuida da organização e controle do navio

Médico: Responsável pela vida dos tripulantes

Musico: Entretenimento do navio

Arqueiro: Cuida dos monstros voadores que se aproximam

Papagaio: PET da tripulação

### *Ideias adicionais:*

Médico tem **duas vidas** (se for o próximo a morrer, não morre na primeira chamada)

Se você tem um caçador na tripulação, ele **morre primeiro** antes de verificar a Fila

# Estruturas de dados utilizadas:

Como base, utilizamos as **Filas** que utilizam o modelo FIFO, onde registramos a entrada de novos tripulantes no navio e retiramos por **ordem de chegada**, entretanto, existem *exceções,* como quando o navio tem um caçador ou o médico é o primeiro da fila.

Como nossa fila tem um **limite de tripulantes** antes do navio afundar, ela precisa **necessariamente** ter um **limite e ficar cheia**, além disso, precisamos que o capitão nunca saia da fila e ela já inicie com ele, portanto, vamos criar uma fila de lista duplamente encadeada para facilitar a procura de elementos dentro da estrutura de dados, com header e vetor circular para melhorar a realocação de elementos.

![fila tripulantes.png](https://prod-files-secure.s3.us-west-2.amazonaws.com/6428a912-891f-4d40-9a9f-1beee71eb364/6abc573b-ed87-45d4-b70a-5f13b03c8cfb/fila_tripulantes.png)

## Construção do projeto:

Nosso projeto será desenvolvido **utilizando C++**, com a aplicação de *tipos abstratos de dados* e manipulação das operações que alteram os elementos da fila a partir de **métodos das classes** implementadas

1. **Tipo Abstrato de Dados (TAD) em C++:** Implementar uma classe para **representar** a estrutura da tripulação, com métodos para adicionar, remover membros e lidar com as *condições especiais* de cada tipo de tripulante.
2. **Interface Gráfica (GUI) em C++:** Criar a **interface do usuário** para exibir informações sobre a tripulação, pontuação, condições especiais e outros
3. **Gestão da Fila da Tripulação em C++:** Implementar a *lógica por trás da fila* principal da tripulação, considerando as condições especiais para o médico e o caçador.
4. **Animações em C++:** Implementar **animações** para personagens, movimentos de captura e efeitos visuais para monstros e interações

Sobre as ferramentas gráficas para o desenvolvimento do projeto, ainda nao estudamos muito para decidir qual será utilizada, mas com uma breve pesquisa temos algumas opções:

1. **SFML (Simple and Fast Multimedia Library):** Uma biblioteca C++ que fornece uma interface simples para renderização gráfica, entrada de usuário, áudio, etc.
2. **SDL (Simple DirectMedia Layer):** Oferece funcionalidades semelhantes à SFML, permitindo acesso a hardware de áudio, teclado, mouse e controladores.
3. **Allegro:** Outra biblioteca em C++ para desenvolvimento de jogos, oferecendo suporte a gráficos, som, entrada de usuário e muito mais.

Avançar estrutura com operações e deizar apenas a parte gráfica pra fase 2