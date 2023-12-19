#define DECK_SIZE       52              // total de cartas no baralho

// dimensões do tabuleiro em linhas e colunas de cartas

#define NLINES			4               // linhas do tabuleiro
#define NCOLS			6               // colunas do tabuleiro
#define BOARD_SIZE     (NLINES*NCOLS)   // total de cartas no tabuleiro
#define NPAIRS         (BOARD_SIZE/2)   // total de pares

// configurações do visual

#define CARD_WIDTH		100
#define CARD_HEIGHT 	130
#define CARD_BORDER_X	15
#define CARD_BORDER_Y	15

// zona de informações

#define INFO_X 10
#define INFO_Y 10
#define INFO_HEIGHT 40

// dimensões do tabuleiro em pixeis
#define BOARD_WIDTH    (CARD_BORDER_X + (CARD_BORDER_X + CARD_WIDTH)*NCOLS)
#define BOARD_HEIGHT   (CARD_BORDER_Y + (CARD_BORDER_Y + CARD_HEIGHT)*NLINES)

#define BOARD_X			10              // início da primeira coluna
#define BOARD_START_Y   (INFO_Y+INFO_HEIGHT+10)
#define BOARD_END_Y	    (BOARD_START_Y  + BOARD_HEIGHT)   // a referência é o fim da última linha

   

#define WINDOW_WIDTH    (BOARD_X*2+BOARD_WIDTH)
#define WINDOW_HEIGHT   (BOARD_END_Y + 10)

#define INFO_WIDTH      WINDOW_WIDTH - (2*INFO_X)

//  configuração de componentes
#define CLOCK_X (INFO_X + 10)
#define CLOCK_Y (INFO_Y + 10)

#define COUNT_X (WINDOW_WIDTH - 140)
#define COUNT_Y (INFO_Y+5)

#define VICTORY_MSG_HEIGHT 30
#define VICTORY_MSG_WIDTH 350

#define VICTORY_MSG_X  ((WINDOW_WIDTH - VICTORY_MSG_WIDTH)/2)
#define VICTORY_MSG_Y  ((WINDOW_HEIGHT - VICTORY_MSG_HEIGHT)/2)

// temporizações
#define BASE_TIME         50
#define HIDE_TIME       2000
#define TICKS_PER_SEC     20

// cores 
 
#define BACK_COLOR graph_rgb(60, 120, 35) 
#define INFO_BACK_COLOR graph_rgb(60, 60, 60) 
#define COLOR_VICTORY_MSG  graph_rgb(200,200,200)

// tipos

// estados da carta
typedef enum card_state { VISIBLE, HIDDEN, REMOVED } card_state_t;

// definir a posição em linhas colunas de tabuleiro
typedef struct location_t {
	int line;
	int col;
} location_t;
 

// representa a carta e o seu estado
typedef struct card_t {
    // aqui a carta é apenas o repositório do nome de uma imagem
    // podiam ser cartas ou outra coisa qualquer
	int value; // 0..51
	card_state_t state;
} card_t;

typedef card_t board_t[NLINES][NCOLS];

// estado do jogo
typedef struct pairs_game {
	board_t cards;                  // tabuleiro de cartas
	int remaining;                  // os pares que faltam identificar
	location_t first;               // localização da 1ª carta seleccionada
    
    location_t hide1, hide2;        // localização das 2 cartas a esconder
    int count_milis, ticks;         // gestão de temporizações
    bool end;                       // a true indica fim do jogo
    bool show_pair;                 // indica que está temporariamente a mostrar o par de cartas seleccionadas
} pairs_game_t;

// suporte à animação

typedef struct rem_anim {
	int width, height;
	int line, col;
	bool stopped;
} rem_anim_t;


// funções

void game_refresh();
void card_show_aux(int line, int col, int w, int h);
void card_show(int line, int col) ;
void card_init(card_t *card, int value);
rem_anim_t card_remove(location_t l);

void info_refresh();
void anim_init(rem_anim_t *ra, int line, int col);
